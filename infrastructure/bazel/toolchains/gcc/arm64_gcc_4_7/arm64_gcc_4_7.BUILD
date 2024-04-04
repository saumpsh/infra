load("@bazel_tools//tools/cpp:unix_cc_toolchain_config.bzl", "cc_toolchain_config")

filegroup(
    name = "all",
    srcs = glob(["**/*",]),
)

cc_toolchain(
    name = "cc_toolchain",
    all_files = ":all",
    ar_files = ":all",
    as_files = ":all",
    compiler_files = ":all",
    dwp_files = ":all",
    linker_files = ":all",
    objcopy_files = ":all",
    strip_files = ":all",
    static_runtime_lib = ":all",
    toolchain_config = ":my_cc_toolchain_config",
)

cc_toolchain_config(
    name = "my_cc_toolchain_config",
    cpu = "arm64",
    compiler = "gcc",
    toolchain_identifier = "arm64_gcc_4_7",
    host_system_name = "local",
    target_system_name = "local",
    target_libc = "unknown",
    abi_version = "unknown",
    abi_libc_version = "unknown",
    tool_paths = {
        "gcc": "bin/aarch64-linux-gnu-g++",
        "cpp": "bin/aarch64-linux-gnu-cpp",
        "ar": "bin/aarch64-linux-gnu-ar",
        "nm": "bin/aarch64-linux-gnu-nm",
        "ld": "bin/aarch64-linux-gnu-ld",
        "as": "bin/aarch64-linux-gnu-as",
        "objcopy": "bin/aarch64-linux-gnu-objcopy",
        "objdump": "bin/aarch64-linux-gnu-objdump",
        "gcov": "bin/aarch64-linux-gnu-gcov",
        "strip": "bin/aarch64-linux-gnu-strip",
        "llvm-cov": "/bin/false",
    },
    compile_flags = [
        "-I", "external/arm64_gcc_4_7_linux_x86_64/aarch64-linux-gnu/include/c++/4.7.3/aarch64-linux-gnu",
        "-I", "external/arm64_gcc_4_7_linux_x86_64/aarch64-linux-gnu/include/c++/4.7.3",
        "-I", "external/arm64_gcc_4_7_linux_x86_64/aarch64-linux-gnu/include",
        "-I", "external/arm64_gcc_4_7_linux_x86_64/aarch64-linux-gnu/libc/usr/include",
        "-I", "external/arm64_gcc_4_7_linux_x86_64/lib/gcc/aarch64-linux-gnu/4.7.3/include",
    ],
    link_flags = [],
)