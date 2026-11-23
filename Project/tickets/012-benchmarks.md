# Ticket 012: Benchmark Harness and Analysis

## Status

Blocked until Ticket 011 is complete

## Depends on

Ticket 011

## Objective

Produce reproducible measurements comparing storage and prefetch policies.

## Tasks

- Define deterministic workloads and seeds.
- Compare no prefetch, LRU-only, sequential/stride, and agent-hint policies.
- Measure cache hit rate, p50, p99, S3 requests, bytes transferred, unused prefetches, and recovery time.
- Export machine-readable results.
- Generate charts and explain tradeoffs.

## Acceptance criteria

- Anyone can rerun the benchmark from documented commands.
- Results include warm-cache and cold-cache cases.
- The report does not hide regressions or negative results.
- Charts include enough context to interpret the comparison.

## Outcome

Pending implementation.

