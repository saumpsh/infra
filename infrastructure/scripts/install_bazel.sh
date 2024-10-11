#!/bin/bash

BAZEL_VERSION=7.0.2

wget https://github.com/bazelbuild/bazel/releases/download/${BAZEL_VERSION}/bazel-${BAZEL_VERSION}-installer-linux-x86_64.sh \
  && chmod +x bazel-${BAZEL_VERSION}-installer-linux-x86_64.sh \
  && sudo ./bazel-${BAZEL_VERSION}-installer-linux-x86_64.sh
