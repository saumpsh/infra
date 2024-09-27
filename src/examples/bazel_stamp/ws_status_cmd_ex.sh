#!/bin/bash

echo BUILD_SCM_STATUS funky
echo BUILD_SCM_REVISION $(git describe --long --dirty --tags)
