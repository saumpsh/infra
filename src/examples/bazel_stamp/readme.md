
# Bazel Stamp example


```
bazel build --stamp //src/examples/bazel_stamp:verify_scm_status --workspace_status_command=src/examples/bazel_stamp/ws_status_cmd_ver.sh
```

## More context 

The stamp information is generated as header files by templates located in : `bazel-infra/external/bazel_tools/tools/build_defs/build_info`

Looking at the template, we can only use the following macros for stamping

```h
// non_volatile_file.h

#define BUILD_EMBED_LABEL "{BUILD_EMBED_LABEL}"
#define BUILD_HOST "{BUILD_HOST}"
#define BUILD_USER "{BUILD_USER}"
```


```h
// volatile_file.h

#define BUILD_SCM_REVISION "{BUILD_SCM_REVISION}"
#define BUILD_SCM_STATUS "{BUILD_SCM_STATUS}"
#define BUILD_TIMESTAMP {BUILD_TIMESTAMP}
```

An instance of generated 'header` file can be found in sandbox as follows

```
$ ~/.cache/bazel/_bazel_ubuntu/2c110d840f21fa831f585259362fde39/sandbox/linux-sandbox/7/execroot/_main/bazel-out/aarch64-fastbuild/bin/external/bazel_tools/tools/build_defs/build_info [8:13:01] 
$ ls
non_volatile_file.h  volatile_file.h
``

### Ref: 

1. https://groups.google.com/g/bazel-discuss/c/M9Krw-6RrYs
2. https://github.com/bazelbuild/bazel/blob/master/src/test/shell/bazel/bazel_workspace_status_test.sh#L73-L115
3. https://stackoverflow.com/questions/58980342/with-bazel-how-can-you-retrieve-stamped-information-from-a-binary
4. https://groups.google.com/g/bazel-discuss/c/9kqLmOq_m_U

General versioning guidelines:

1. https://interrupt.memfault.com/blog/release-versioning
2. https://embeddedartistry.com/blog/2016/12/21/giving-your-firmware-build-a-version/
3. https://gitlab.com/wolframroesler/version/-/tree/master?ref_type=heads
