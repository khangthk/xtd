# assume_is_less

Shows how to use [xtd::tunit::assume::is_less](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assume.html#aa3f97beea3faa946b5731fcc89addb1c) method.

## Sources

[src/assume_is_less.cpp](src/assume_is_less.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
Start 2 tests from 1 test case
Run tests:
  SUCCEED test.test_case_succeed (0 ms total)
  ABORTED test.test_case_failed (0 ms total)
    Expected: less than 12
    But was:  24
    Stack Trace: in |---OMITTED---|/assume_is_less.cpp:13

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```