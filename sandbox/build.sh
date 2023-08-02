#!/bin/bash

# Set the directories
BIN_DIR="bin"
ENGINE_DIR="engine"

# Create the bin directory if it doesn't exist
mkdir -p "../$BIN_DIR"

# Build the sandbox
echo "Building the sandbox..."
defines="-D_DEBUG -DKIMPORT"
compilerFlags=" -Wall"
linkerFlags=" -L../$BIN_DIR -lengine -Wl,-rpath,."
includeFlags="-I../"$ENGINE_DIR"/src"
cppFiles=$(find src -type f -name "*.cpp")
g++ $compilerFlags -o "../$BIN_DIR/sandbox" $includeFlags $cppFiles $linkerFlags


echo "SandBox build complete!"
 
