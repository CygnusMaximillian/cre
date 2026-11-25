# Ticket 003: Disk Manager

## Status

Blocked until Ticket 002 is complete

## Depends on

Ticket 002

## Objective

Persist and retrieve fixed-size pages from a local database file.

## Tasks

- Implement page allocation.
- Implement page read and write.
- Implement flush and close behavior.
- Validate file size and page boundaries.
- Add tests for restart persistence and I/O errors.

## Acceptance criteria

- A written page can be read after closing and reopening the file.
- Invalid page IDs produce a controlled error.
- Partial or failed I/O is surfaced to the caller.
- Tests do not depend on a pre-existing local database file.

## Outcome

Pending implementation.

