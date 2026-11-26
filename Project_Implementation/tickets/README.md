# Sequential Project Tickets

This directory contains the implementation tickets for the agent-aware tiered storage engine. Work through them in order. Do not start a ticket until its dependencies are complete.

## Workflow

1. Choose the first open ticket whose dependencies are satisfied.
2. Read its objective, implementation notes, and acceptance criteria.
3. Implement only the ticket's scope.
4. Run the required verification.
5. Record the outcome, evidence, and follow-up work in the ticket.
6. Mark the ticket complete before starting the next one.

## Ticket order

1. Repository and build foundation
2. Page format and serialization
3. Disk manager
4. Buffer pool and pinning
5. LRU eviction
6. B+ tree leaf index
7. Write-ahead log
8. Crash recovery
9. MinIO remote page tier
10. Agent context cache
11. Predictive prefetching
12. Benchmark harness and analysis
13. Documentation and public release

## Definition of done

A ticket is done only when its acceptance criteria pass, tests or other evidence are recorded, and the outcome section is filled in. A ticket may be marked blocked with a concrete reason and next action; blocked work does not count as complete.

