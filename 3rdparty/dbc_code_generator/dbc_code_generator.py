# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
# documentation files (the "Software"), to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
# and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all copies or substantial portions of
# the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
# THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#
# This code is copied from external repository and might not strictly adhere to internal guidelines.

from argparse import ArgumentParser
import os
import sys

from code_writer import CodeWriter, GENERATE_ALL_NODE_NAME, InvalidDBCNodeError

# from colour import ColorString


def get_args():
    arg_parser = ArgumentParser()
    arg_parser.add_argument("--dbc", required=True)
    arg_parser.add_argument("-o", "--output", default=None)
    arg_parser.add_argument("--print-only", action="store_true")
    arg_parser.add_argument("--dbc-node-name", default=GENERATE_ALL_NODE_NAME)
    return arg_parser.parse_args()


def main():
    args = get_args()
    dbc_filepath = args.dbc
    output = args.output
    print_only = args.print_only
    dbc_node_name = args.dbc_node_name

    if not os.path.isfile(dbc_filepath):
        print("Unable to find DBC file: [{}]".format(dbc_filepath))
        return 1  # Return early

    try:
        code_writer = CodeWriter(dbc_filepath, dbc_node_name)
    except InvalidDBCNodeError as err:
        print(str(err))
        return 1  # Return early

    if not print_only:
        basename, ext = os.path.splitext(os.path.basename(dbc_filepath))
        output_filename = "{}.h".format(basename)

        if output is None:
            output_filepath = output_filename
        elif os.path.isdir(output) or "." not in os.path.basename(output):
            output_filepath = os.path.join(output, output_filename)
        else:
            output_filepath = output

        if not os.path.isdir(os.path.dirname(output_filepath)):
            os.makedirs(os.path.dirname(output_filepath))
        with open(output_filepath, "w") as file:
            file.write(str(code_writer))
    else:
        print(code_writer)

    return 0


if __name__ == "__main__":
    sys.exit(main())