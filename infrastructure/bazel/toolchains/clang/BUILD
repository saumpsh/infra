load(":cc_toolchain_config.bzl", "clang_cc_toolchain_config")

filegroup(name = "empty")

clang_cc_toolchain_config(name = "clang_toolchain_config")

cc_toolchain(
    name = "clang_k8_toolchain",
    all_files = ":empty",
    compiler_files = ":empty",
    dwp_files = ":empty",
    linker_files = ":empty",
    objcopy_files = ":empty",
    strip_files = ":empty",
    supports_param_files = 0,
    toolchain_config = ":clang_toolchain_config",
    toolchain_identifier = "clang-toolchain",
)
