# Ticket 008: Crash Recovery

## Status

Blocked until Ticket 007 is complete

## Depends on

Ticket 007

## Objective

Recover durable page state by replaying the redo-only WAL after an abnormal termination.

## Tasks

- Add startup recovery.
- Add a subprocess crash test.
- Terminate the writer during a controlled write using `kill -9`.
- Reopen the database and verify recovered records.
- Document the durability boundary.

## Acceptance criteria

- The crash test is reproducible.
- Committed records are recovered.
- Incomplete records are ignored or safely rejected.
- Recovery reports useful diagnostics.

## Outcome

Pending implementation.

