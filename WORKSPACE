load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_google_googletest",
    urls = ["https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip"],
    strip_prefix = "googletest-1.14.0",
    sha256 = "1f357c27ca988c3f7c6b4bf68a9395005ac6761f034046e9dde0896e3aba00e4",
)

# Fake Function Framework (fff)
http_archive(
    name = "fff",
    urls = ["https://github.com/meekrosoft/fff/archive/refs/tags/v1.1.zip"],
    strip_prefix = "fff-1.1",
    sha256 = "5a8329878f59bd1ea19b734573d63c228f742384b8c78d00e4d005909b90ee83",
    build_file = "//infrastructure/bazel/testing:fff.BUILD",
)


# Armv8 Architecture GCC cross compiler targeting Linux Apps for Linux x86 host machine
http_archive(
    name = "arm64_gcc_9_2_linux_x86_64",
    urls = ["https://developer.arm.com/-/media/Files/downloads/gnu-a/9.2-2019.12/binrel/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu.tar.xz"],
    strip_prefix = "gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu",
    sha256 = "8dfe681531f0bd04fb9c53cf3c0a3368c616aa85d48938eebe2b516376e06a66",
    build_file = "//infrastructure/bazel/toolchains/gcc/arm64_gcc_9_2:arm64_gcc_9_2.BUILD",
)

# Armv8 Architecture GCC 4.7 cross compiler targeting Linux Apps for Linux x86 host machine
http_archive(
    name = "arm64_gcc_4_7_linux_x86_64",
    urls = ["https://releases.linaro.org/archive/13.04/components/toolchain/binaries/gcc-linaro-aarch64-linux-gnu-4.7-2013.04-20130415_linux.tar.xz"],
    strip_prefix = "gcc-linaro-aarch64-linux-gnu-4.7-2013.04-20130415_linux",
    # sha256 = "8dfe681531f0bd04fb9c53cf3c0a3368c616aa85d48938eebe2b516376e06a66",
    build_file = "//infrastructure/bazel/toolchains/gcc/arm64_gcc_4_7:arm64_gcc_4_7.BUILD",
)

# Register Armv8 cross compiler
register_toolchains(
    "//infrastructure/bazel/toolchains:arm64_gcc_9_2_linux_x86_64",
)

register_toolchains(
    "//infrastructure/bazel/toolchains:arm64_gcc_4_7_linux_x86_64",
)
