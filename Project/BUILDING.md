# Building the project

From `~/cre/Project`:

```bash
cmake -S . -B build -DAGENT_STORAGE_BUILD_TESTS=ON
cmake --build build
ctest --test-dir build --output-on-failure
```

The initial structure contains:

- `agent_storage`: the library target for storage-engine code
- `agent_storage_smoke_test`: the first test executable
- `CTest`: test discovery and execution
- `include/`: public headers
- `src/`: implementation files
- `tests/`: test files
