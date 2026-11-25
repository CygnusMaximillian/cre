# Agent-Aware Tiered Storage Engine

## One-line description

A C++ storage-engine prototype that persists database and agent-context pages across memory, local disk, and MinIO/S3, with WAL recovery and measurable predictive prefetching.

## Why this project exists

The project is designed to practice the systems that appear underneath modern disaggregated databases and AI infrastructure: buffer management, durable pages, indexing, recovery, remote object storage, cache policy, and tail-latency measurement.

## Repository documents

- [Project ticket](.ticket.md)
- [Product requirements](PRD.md)
- [Learning and resources](RESOURCES.md)
- [Task checklist](TASKS.md)

## Core hypothesis

Can lightweight workload prediction and explicit agent-context hints reduce p99 latency when cold pages must be fetched from object storage, without causing unacceptable cache pollution or extra S3 traffic?

## Month-one milestone

Deliver a tested single-process prototype with a buffer pool, B+ tree insert/lookup, redo-only WAL recovery, MinIO-backed cold-page reads, a deterministic agent-context workload, and benchmark comparisons.

## Planned benchmark policies

- No prefetch
- LRU-only
- Sequential/stride prefetch
- Agent-hint prefetch

## Expected evidence

- Unit-test results
- Crash-recovery output
- Cold-cache and warm-cache measurements
- Cache hit-rate chart
- p50/p99 latency chart
- S3 request/byte comparison
- Known limitations and future roadmap

## Resume-oriented description

Built and benchmarked a C++ agent-aware tiered storage engine that persists database and tool-use context across memory, local disk, and MinIO/S3, with B+ tree indexing, redo-only WAL recovery, and workload-aware prefetching evaluated using cache-hit rate and p99 latency.

## Important honesty boundary

This is a focused prototype, not a production database, a replacement for Neon/Snowflake, or novel ML research. The strength of the project is the complete implementation, failure testing, reproducible benchmark design, and clear analysis of tradeoffs.
