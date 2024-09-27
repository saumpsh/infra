#!/bin/bash

# Demonstrate basic use of stamping

echo BUILD_SCM_STATUS funky
echo BUILD_SCM_REVISION $(git describe --long --dirty --tags)
