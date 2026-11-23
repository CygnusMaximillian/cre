# Ticket 005: LRU Eviction

## Status

Blocked until Ticket 004 is complete

## Depends on

Ticket 004

## Objective

Evict the least recently used unpinned page when the buffer pool is full.

## Acceptance criteria

- The least recently used eligible page is selected.
- Pinned pages are skipped.
- Dirty victims are flushed before reuse.
- The no-evictable-frame case returns a clear error.
- Eviction behavior is covered by deterministic tests.

## Outcome

Pending implementation.

