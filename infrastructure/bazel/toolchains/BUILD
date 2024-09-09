toolchain(
    name = "arm64_gcc_9_2_linux_x86_64",
    exec_compatible_with = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
    ],
    target_compatible_with = [
        "@platforms//cpu:arm64",
        "//infrastructure/bazel/constraints/compiler:gcc-9.2",
    ],
    toolchain_type = "@rules_cc//cc:toolchain_type",
    toolchain = "@arm64_gcc_9_2_linux_x86_64//:cc_toolchain",
)

toolchain(
    name = "arm64_gcc_4_7_linux_x86_64",
    exec_compatible_with = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
    ],
    target_compatible_with = [
        "@platforms//cpu:arm64",
        "//infrastructure/bazel/constraints/compiler:gcc-4.7",
    ],
    toolchain_type = "@rules_cc//cc:toolchain_type",
    toolchain = "@arm64_gcc_4_7_linux_x86_64//:cc_toolchain",
)

toolchain(
    name = "clang_linux",
    exec_compatible_with = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
    ],
    target_compatible_with = [
        "@platforms//cpu:x86_64",
        "//infrastructure/bazel/constraints/compiler:clang-14",
    ],
    toolchain_type = "@rules_cc//cc:toolchain_type",
    toolchain = "//infrastructure/bazel/toolchains/clang:clang_k8_toolchain",
)
