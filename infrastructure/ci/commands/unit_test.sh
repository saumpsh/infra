#!/usr/bin/env bash

# set options automatically checks return code for each command.
# -e option let script immediately exits on command failure.
# -u option detects incorrect assignments to variable and exits script with error. e.g. when assigning a
#    character string to a variable that was declared explicitly as one holding only integer value.
# -o pipefail option sets the exit code of a pipeline to that of the rightmost command to exit
#    with a non-zero status, or to zero if all commands of the pipeline exit successfully.
# for more details: https://www.tldp.org/LDP/abs/html/options.html
set -euo pipefail
source 'infrastructure/ci/commands/ci_common.sh'

print_banner 'Running C and C++ Tests'

bazel test //src/... "$@"
