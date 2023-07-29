#!/bin/bash

# Set the directories
BIN_DIR="bin"
ENGINE_DIR="engine"

# Create the bin directory if it doesn't exist
mkdir -p "../$BIN_DIR"

# Build the engine as a shared library
echo "Building the engine..."
defines="-D_DEBUG -DKEXPORT"
compilerFlags=" -Wall -shared -fPIC"
linkerFlags=" -ldl -lglfw"
g++ $compilerFlags -o "../$BIN_DIR/lib$ENGINE_DIR.so" src/*.cpp $defines $linkerFlags

echo "Engine build complete!"
