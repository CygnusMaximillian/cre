# Ticket 006: B+ Tree Leaf Index

## Status

Blocked until Ticket 005 is complete

## Depends on

Ticket 005

## Objective

Build a minimal persistent B+ tree supporting insert and lookup.

## Scope

Start with leaf-page behavior and a single-level tree if necessary. Internal-node splits and range scans are follow-up work unless the core is stable early.

## Acceptance criteria

- Unique keys can be inserted and retrieved.
- Missing keys return a defined result.
- Data survives close and reopen.
- Duplicate-key behavior is documented and tested.

## Outcome

Pending implementation.

