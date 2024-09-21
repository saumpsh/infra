#!/usr/bin/env bash
set -euo pipefail
source 'infrastructure/ci/commands/ci_common.sh'

##################################################################
# Bazel Build
print_banner 'Running Bazel Build All'
bazel build //src/... "$@"
