package(default_visibility = ["//visibility:public"])

cc_library(
    name = "timer_i",
    hdrs = ["timer_i.h"],
    includes = ["."],
)

cc_library(
  name = "timer",
  srcs = ["timer.cpp"],
  hdrs = ["timer.h"],
  includes = ["."],
  deps = [":timer_i"],
)
