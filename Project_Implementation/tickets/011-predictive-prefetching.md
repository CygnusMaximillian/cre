# Ticket 011: Predictive Prefetching

## Status

Blocked until Ticket 010 is complete

## Depends on

Ticket 010

## Objective

Reduce cold-page latency using transparent access-pattern detection and explicit agent-context hints.

## Tasks

- Implement no-prefetch and LRU-only baselines.
- Implement sequential/stride detection.
- Add an agent prefetch-hint API.
- Track useful and unused prefetches.
- Bound hints to avoid arbitrary cache pollution.
- Test incorrect, duplicate, and stale hints.

## Acceptance criteria

- Prefetch never changes logical correctness.
- Useful prefetches are counted separately from unused prefetches.
- The fake-agent workload can run with each policy.
- The implementation can show both improvement and regression cases.

## Outcome

Pending implementation.

