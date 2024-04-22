package(default_visibility = ["//visibility:public"])

cc_library(
    name = "can_i",
    hdrs = ["hal_can_i.h"],
    includes = ["."],
)

cc_library(
  name = "can",
  srcs = ["hal_can.cpp"],
  hdrs = ["hal_can.h"],
  includes = ["."],
    deps = [
        ":can_i",
        "//src/hal/timer",
        "@com_google_absl//absl/log"
    ],
)
