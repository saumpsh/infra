cc_library(
    name = "json_c_headers",
    hdrs = glob(["include/json-c/*.h"]),
    includes = ["include"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "json_c_lib_arm",
    srcs = ["lib/aarch64/libjson-c.a"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "json_c_lib_x86_64",
    srcs = ["lib/x86_64/libjson-c.a"],
    visibility = ["//visibility:public"],
)
