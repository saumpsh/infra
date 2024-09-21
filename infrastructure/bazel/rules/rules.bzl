""" This file contains a structure of custom rules we have written

This makes development easier since all rules intended for BUILD file use will be given shortcuts here.

"""

load("//infrastructure/bazel/rules/cc/dbc:cc_dbc_library.bzl", "cc_dbc_library")

rules = struct(
    cc_dbc_library = cc_dbc_library,
)