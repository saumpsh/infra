"""Rules for autogenerating C/C++ code from DBC files.
"""

def cc_dbc_library(name, dbc, outfile = None, **kwargs):
    """A macro that generates a C header from DBC file using the SJ2 DBC code generator, and packs it into a `cc_library` target.

    The top level target instantiated by this macro is the native `cc_library` rule. All attributes relevant to this rule may be used here.

    Building this target by default will appear to do nothing. To view the generated DBC file, build this target and append `_genrule` to the target name. For example:
    ```
    rules.cc_dbc_library(
        name = "motohawk_dbc",
        dbc = "motohawk.dbc",
    )
    ```
    Building the implicit target `:motohawk_dbc_genrule` will then print the path to the generated DBC header so that you can review it.

    Args:
        name: name of the target
        dbc: DBC file to generate a C library from
        outfile: Optional name of the emitted C header file. If omitted, the header is named after the rule name
        **kwargs: all other arguments pass through to the underlying `cc_library` target
    """
    outfile = outfile if outfile else name + ".h"  # Use name as outfile if outfile is not provided.

    native.genrule(
        name = name + "_genrule",
        srcs = [dbc],
        outs = [outfile],
        cmd = """\
            $(location //3rdparty/dbc_code_generator) \
            --dbc $(location {dbc}) \
            --out $(location {outfile})
            """.format(dbc = dbc, outfile = outfile),
        tools = ["//3rdparty/dbc_code_generator"],
    )

    native.cc_library(
        name = name,
        hdrs = [outfile],
        includes = ["."],
        **kwargs
    )
