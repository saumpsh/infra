load("@python_deps//:requirements.bzl", "requirement")

py_binary(
    name = "dbc_code_generator",
    srcs = [
        "__init__.py",
        "code_writer.py",
        "dbc_code_generator.py",
    ],
    visibility = ["//visibility:public"],
    deps = [
        requirement("cantools"),
    ],
)
