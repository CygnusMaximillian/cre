# Product Requirements Document

## 1. Product definition

This project is a learning and portfolio prototype of a tiered storage engine. It is not intended to replace Neon, Snowflake, ClickHouse, or a general-purpose database. Its purpose is to demonstrate database internals, reliability, cloud storage integration, performance analysis, and an AI-infrastructure workload.

## 2. Problem statement

Agent workloads repeatedly access conversation context, tool results, and task state. Keeping all state in memory is expensive, while fetching cold state from object storage adds latency. The prototype explores whether a small, transparent access predictor can improve resumed-session latency without causing excessive cache pollution.

## 3. Goals

1. Provide durable fixed-size page storage.
2. Cache pages in memory with pin counts and LRU eviction.
3. Index records with a minimal B+ tree.
4. Recover data using redo-only WAL replay.
5. Support memory → local disk → MinIO/S3 page movement.
6. Persist and resume deterministic agent-context sessions.
7. Compare no prefetch, LRU-only, sequential/stride, and agent-hint policies.
8. Produce reproducible measurements and technical documentation.

## 4. Non-goals

- SQL parser or query planner
- Full ACID transaction manager
- Multi-node replication
- Real LLM quality evaluation
- Kubernetes or cloud deployment
- Novel machine-learning research

## 5. Proposed architecture

```text
Fake Agent Workload
        |
Agent Context Cache API
        |
B+ Tree / Record Layer
        |
Buffer Pool + LRU + Pin Counts
        |
Prefetch Policy ----> Page Fetch Scheduler
        |                         |
Local Disk Manager         MinIO/S3 Object Store
        |
WAL + Redo Recovery
```

## 6. Core components

### Page manager

Use a fixed page size, page IDs, a page header, checksums if feasible, and a stable serialization format. Begin with one process and one database file.

### Disk manager

Provide page allocation, read, write, flush, and file-size validation. All I/O errors must be surfaced rather than silently ignored.

### Buffer pool

Maintain frames, page-table mappings, pin counts, dirty flags, and an LRU replacement structure. A pinned page must never be selected as a victim.

### B+ tree

Start with leaf-page insert and lookup. Add internal nodes only after leaf behavior is tested. Range scans are optional for month one.

### WAL

Use append-only records with a record identifier, page ID, operation type, payload, and checksum if feasible. Flush WAL before reporting durable page updates. Recovery replays valid redo records and ignores an incomplete tail record.

### Remote page tier

Use MinIO locally. Keep object keys deterministic, for example `pages/<page-id>`. Implement a remote fetch interface so tests can use a fake object store. Add S3 range reads only where the chosen page/object layout makes them meaningful.

### Agent-context cache

Expose operations such as `start_session`, `put_context`, `get_context`, `put_tool_result`, `resume_session`, and `prefetch_hint`. Store session metadata and context records through the normal page/index path; do not create a second persistence system.

### Predictor

Implement sequential/stride detection and an explicit agent-hint policy. Track predictions, useful prefetches, unused prefetches, misses, and bytes fetched.

## 7. Testing requirements

### Unit tests

- Page serialization and bounds
- Disk read/write
- Buffer-pool pin/unpin and eviction
- B+ tree insert/lookup
- WAL record parsing and replay
- Predictor decisions and metrics

### Integration tests

- Store → close → reopen → read
- Fill cache → evict → read from disk
- Store session → evict context → resume session
- Missing page → MinIO fetch → cache hit

### Fault tests

- Terminate during a write and recover with WAL
- Corrupt or truncate the WAL tail
- Simulate MinIO timeout and missing object
- Repeat a remote fetch to verify idempotent behavior

### Benchmark matrix

Run the same deterministic workload with:

1. No prefetch
2. LRU-only
3. Sequential/stride prefetch
4. Agent-hint prefetch

Record cache hit rate, p50 latency, p99 latency, S3 request count, bytes transferred, recovery time, and unused prefetched pages.

## 8. Four-week delivery plan

### Week 1: Foundation

CMake, tests, page layout, disk manager, buffer pool, LRU, pin counts.

### Week 2: Index and durability

B+ tree insert/lookup, WAL format, redo replay, restart and `kill -9` tests.

### Week 3: Remote tier

MinIO, remote page interface, cold-cache reads, local cache measurements, failure tests.

### Week 4: Agent workload and evaluation

Agent-context API, deterministic fake agent, predictor, comparison benchmarks, charts, README.

## 9. Risks and mitigations

| Risk | Mitigation |
|---|---|
| Reading replaces implementation | One-hour reading cap and artifact-per-reading rule |
| Scope expands into a full database | Keep SQL, transactions, replication, and ML deferred |
| C++ gaps slow progress | Use small isolated exercises and compile/test frequently |
| S3 integration blocks core work | Use a fake object-store interface and MinIO only after local storage works |
| Prefetch results are weak | Report negative results and measure unused prefetches |
| Too many parallel projects | Protect the first four-hour storage block |

## 10. Success narrative

The final story is: “I built a small durable tiered storage engine, then used it to test whether transparent access prediction and explicit agent-workload hints can reduce the tail latency of resuming cold agent context.”

