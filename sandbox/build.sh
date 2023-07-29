#!/bin/bash

# Set the directories
BIN_DIR="bin"
ENGINE_DIR="engine"

# Create the bin directory if it doesn't exist
mkdir -p "../$BIN_DIR"

# Build the engine as a shared library
echo "Building the sandbox..."
defines="-D_DEBUG -DKIMPORT"
compilerFlags=" -Wall"
linkerFlags=" -L../$BIN_DIR -lengine -Wl,-rpath,."
includeFlags="-I../"$ENGINE_DIR"/src"
g++ $compilerFlags -o "../$BIN_DIR/sandbox" $includeFlags src/*.cpp $linkerFlags


echo "Engine build complete!"
 
