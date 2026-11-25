# Ticket 004: Buffer Pool and Pinning

## Status

Blocked until Ticket 003 is complete

## Depends on

Ticket 003

## Objective

Add an in-memory buffer pool that manages page frames, dirty state, and pin counts.

## Tasks

- Implement frame storage and page-table mappings.
- Implement fetch, create, unpin, and flush operations.
- Track dirty pages and pin counts.
- Prevent eviction of pinned pages.
- Add tests for repeated fetches and dirty-page flushes.

## Acceptance criteria

- The same page maps to one frame while resident.
- A pinned page cannot be evicted.
- Dirty pages are written back when flushed.
- Missing pages are loaded through the disk manager.

## Outcome

Pending implementation.

