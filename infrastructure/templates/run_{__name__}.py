from argparse import ArgumentParser, RawTextHelpFormatter
import errno
from pathlib import Path
import sys

DESCRIPTION = """\
This file is a sample Python program with an example command line interface (CLI)

Example usage:

python3 {}
""".format(
    Path(__file__).name
)


def get_args():
    argument_parser = ArgumentParser(description=DESCRIPTION, formatter_class=RawTextHelpFormatter)
    argument_parser.add_argument("--version", action="version", version="%(prog)s")
    return argument_parser.parse_args()


def main():
    args = get_args()
    return 0


if __name__ == "__main__":
    sys.exit(main())
