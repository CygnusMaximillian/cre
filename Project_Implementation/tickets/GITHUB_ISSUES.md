# GitHub Implementation Tickets

Parent roadmap: [Agent-aware tiered storage engine #2](https://github.com/CygnusMaximillian/cre/issues/2).

Created from the local planning tickets using the structure of the supplied [example issue](https://github.com/DarkPhoenix645/flowstate/issues/32). Work in order and record verification evidence before closing each issue.

| Ticket | GitHub issue | Blocked by |
|---|---|---|
| T01 Repository and Build Foundation | [#3](https://github.com/CygnusMaximillian/cre/issues/3) | None |
| T02 Page Format and Serialization | [#4](https://github.com/CygnusMaximillian/cre/issues/4) | [#3](https://github.com/CygnusMaximillian/cre/issues/3) |
| T03 Disk Manager | [#5](https://github.com/CygnusMaximillian/cre/issues/5) | [#4](https://github.com/CygnusMaximillian/cre/issues/4) |
| T04 Buffer Pool and Pinning | [#6](https://github.com/CygnusMaximillian/cre/issues/6) | [#5](https://github.com/CygnusMaximillian/cre/issues/5) |
| T05 LRU Eviction | [#7](https://github.com/CygnusMaximillian/cre/issues/7) | [#6](https://github.com/CygnusMaximillian/cre/issues/6) |
| T06 B+ Tree Leaf Index | [#8](https://github.com/CygnusMaximillian/cre/issues/8) | [#7](https://github.com/CygnusMaximillian/cre/issues/7) |
| T07 Write-Ahead Log | [#9](https://github.com/CygnusMaximillian/cre/issues/9) | [#8](https://github.com/CygnusMaximillian/cre/issues/8) |
| T08 Crash Recovery | [#10](https://github.com/CygnusMaximillian/cre/issues/10) | [#9](https://github.com/CygnusMaximillian/cre/issues/9) |
| T09 MinIO Remote Page Tier | [#11](https://github.com/CygnusMaximillian/cre/issues/11) | [#10](https://github.com/CygnusMaximillian/cre/issues/10) |
| T10 Agent Context Cache | [#12](https://github.com/CygnusMaximillian/cre/issues/12) | [#11](https://github.com/CygnusMaximillian/cre/issues/11) |
| T11 Predictive Prefetching | [#13](https://github.com/CygnusMaximillian/cre/issues/13) | [#12](https://github.com/CygnusMaximillian/cre/issues/12) |
| T12 Benchmark Harness and Analysis | [#14](https://github.com/CygnusMaximillian/cre/issues/14) | [#13](https://github.com/CygnusMaximillian/cre/issues/13) |
| T13 Documentation and Public Release | [#15](https://github.com/CygnusMaximillian/cre/issues/15) | [#14](https://github.com/CygnusMaximillian/cre/issues/14) |

The setup and release issues reflect the existing repository and local CMake/CTest skeleton. Issue creation does not mean the implementation or acceptance criteria are complete.
