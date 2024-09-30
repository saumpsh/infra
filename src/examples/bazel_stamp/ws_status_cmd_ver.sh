#!/bin/bash
#
# Demonstrate how version infomration can be stamped similar to a real project
#

# We can also use `git tags` instead, to automate with CI.
MAJOR=0
MINOR=1
PATCH=0

# Get the build time stamp
WHEN=$(date +"%Y-%m-%d %H:%M:%S")
# Get the user name
WHO="$USER"
# Get the machine name
WHERE=$(hostname)
# Get the OS version
WHAT=$(uname -sr)
# Only Git hash
BUILD_GIT_HASH=$(git describe --match='' --always)

# Build info
echo BUILD_SCM_STATUS "Git-Hash: $BUILD_GIT_HASH (built $WHEN by $WHO on $WHERE with $WHAT)"
echo BUILD_SCM_REVISION "$MAJOR.$MINOR.$PATCH"

# Examples on different ways to add version info
echo ""; echo "More examples"
echo "Git hash + num of commits ahead of the last versioned build: " # Eg: 0.1.64-2-gb27efef-dirty
echo BUILD_GIT_HASH_LAST_VERSION_BUILD $(git describe --long --dirty --tags)
