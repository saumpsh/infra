#!/bin/bash

# Get the build time stamp
WHEN=$(date +"%Y-%m-%d %H:%M:%S")

# Get the user name
WHO="$USER"

# Get the machine name
WHERE=$(hostname)

# Get the OS version
WHAT=$(uname -sr)

echo BUILD_SCM_STATUS "built $WHEN by $WHO on $WHERE with $WHAT"
echo BUILD_SCM_REVISION $(git describe --long --dirty --tags)
