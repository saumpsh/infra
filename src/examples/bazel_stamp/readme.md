
# Bazel Stamp example


```
bazel build --stamp //src/examples/bazel_stamp:verify_scm_status --workspace_status_command=src/examples/bazel_stamp/ws_status_cmd.sh
```

### Ref: 

1. https://groups.google.com/g/bazel-discuss/c/M9Krw-6RrYs
2. https://github.com/bazelbuild/bazel/blob/master/src/test/shell/bazel/bazel_workspace_status_test.sh#L73-L115
3. https://stackoverflow.com/questions/58980342/with-bazel-how-can-you-retrieve-stamped-information-from-a-binary
4. https://groups.google.com/g/bazel-discuss/c/9kqLmOq_m_U
