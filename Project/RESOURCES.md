# Learning and Resource Guide

Use these resources just before the related implementation. Do not attempt to read everything before coding.

## Week 1: pages, disk, and buffer pools

1. CMU 15-445/645 Buffer Pool Manager and storage topics: https://15445.courses.cs.cmu.edu/
2. CMU Database Group notes and project material: https://15445.courses.cs.cmu.edu/fall2024/
3. C++ reference for file streams and filesystem: https://en.cppreference.com/
4. CMake tutorial: https://cmake.org/cmake/help/latest/guide/tutorial/
5. GoogleTest primer: https://google.github.io/googletest/primer.html

Read for: page ownership, fixed-size I/O, RAII, test fixtures, pin counts, and eviction invariants.

## Week 2: B+ trees and durability

1. CMU B+ tree and index lectures: https://15445.courses.cs.cmu.edu/
2. Database Systems Concepts, Silberschatz, Korth, and Sudarshan — indexing and recovery chapters.
3. ARIES paper: https://dl.acm.org/doi/10.1145/128765.128770
4. PostgreSQL WAL documentation for terminology: https://www.postgresql.org/docs/current/wal-intro.html

Read for: page splits, redo logging, log-before-data, recovery order, and incomplete log tails.

## Week 3: tiered and remote storage

1. MinIO documentation: https://min.io/docs/minio/linux/index.html
2. AWS S3 byte-range fetch documentation: https://docs.aws.amazon.com/AmazonS3/latest/userguide/range-get-olap.html
3. Neon pageserver architecture: https://github.com/neondatabase/neon/blob/main/docs/pageserver-services.md
4. Snowflake micro-partitions: https://docs.snowflake.com/en/en/user-guide/tables-clustering-micropartitions

Read for: remote-storage failure modes, object layouts, range requests, disaggregated storage, and the distinction between local cache and durable remote state.

## Week 4: prefetching and AI infrastructure

1. Sequentiality and Prefetching in Database Systems: https://www-inst.eecs.berkeley.edu/~cs266/sp10/readings/smith78.pdf
2. NVIDIA Dynamo discussion of prefetching for agentic inference: https://developer.nvidia.com/blog/full-stack-optimizations-for-agentic-inference-with-nvidia-dynamo/
3. IMPRESS multi-tier prefix KV storage: https://www.usenix.org/system/files/fast25-chen-weijian-impress.pdf
4. LMCache research and documentation: https://github.com/LMCache/LMCache

Read for: prefetch cost, cache pollution, hints, context reuse, tiered AI state, and why an AI workload does not require an LLM inside the storage engine.

## C++ topics to learn only when needed

- RAII and move semantics
- `std::mutex` and condition variables, if concurrency is added
- `std::filesystem`
- `std::span` and serialization boundaries
- `std::variant` or tagged records for WAL operations
- Sanitizers: https://clang.llvm.org/docs/AddressSanitizer.html
- UndefinedBehaviorSanitizer: https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html

Avoid advanced template metaprogramming unless the implementation genuinely requires it.

## Engineering tools

- Git and GitHub pull requests
- CMake
- GoogleTest or Catch2
- AddressSanitizer and UndefinedBehaviorSanitizer
- `perf` or another profiler
- MinIO client and Docker/Podman if available
- Python or a small script for benchmark aggregation and charts

## Open-source contribution path

Begin with one small ClickHouse contribution: documentation, a focused test, an error-message improvement, or a narrowly scoped bug fix. Treat MariaDB/GSoC exploration as a separate track. Do not let issue browsing displace the storage-engine milestone.

## Daily learning loop

1. Read for up to one hour.
2. Write down three implementation rules.
3. Implement one small behavior.
4. Add a test proving it.
5. Record what worked and what remains uncertain.

