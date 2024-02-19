load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Armv8 Architecture GCC cross compiler targeting Linux Apps for Linux x86 host machine
http_archive(
    name = "arm64_gcc_9_2_linux_x86_64",
    urls = ["https://developer.arm.com/-/media/Files/downloads/gnu-a/9.2-2019.12/binrel/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu.tar.xz"],
    strip_prefix = "gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu",
    sha256 = "8dfe681531f0bd04fb9c53cf3c0a3368c616aa85d48938eebe2b516376e06a66",
    build_file = "//infrastructure/bazel/toolchains/gcc/arm64_gcc_9_2:arm64_gcc_9_2.BUILD",
)

# Register Armv8 cross compiler
register_toolchains(
    "//infrastructure/bazel/toolchains:arm64_gcc_9_2_linux_x86_64",
)
