#!/bin/bash

# Script to automatically set up a Makefile-based C compilation system
# Just copy this script to your project folder and run it

# Create Makefile
cat > Makefile << 'EOF'
# Auto-generated Makefile for C compilation
# This Makefile automatically finds all .c files and creates targets for each

# Find all .c files in the current directory
C_FILES := $(wildcard *.c)
# Create target names (filename without extension)
TARGETS := $(basename $(C_FILES))

# Compiler flags
CFLAGS := -Wall -Werror -Wshadow -Wnull-dereference -O0 -g3

# Default target - show available targets
.PHONY: all
all:
	@echo "Available targets:"
	@for target in $(TARGETS); do echo "  make $$target"; done

# Create dynamic targets for each .c file
define make_target
.PHONY: $(1)
$(1): $(1).c
	gcc $(CFLAGS) $(1).c -o $(1).out
	./$(1).out
endef

$(foreach target,$(TARGETS),$(eval $(call make_target,$(target))))

# Clean up generated .out files
.PHONY: clean
clean:
	rm -f *.out

.PHONY: help
help:
	@echo "Usage: make <filename>"
	@echo ""
	@echo "Examples:"
	@for target in $(TARGETS); do echo "  make $$target"; done
	@echo ""
	@echo "Other targets:"
	@echo "  make clean  - Remove all .out files"
	@echo "  make help   - Show this help message"
EOF

echo "✓ Makefile created"

# Create .gitignore
cat > .gitignore << 'EOF'
# Setup script (only needed for initial setup)
setup.sh

# Object files (if using object file compilation)
*.o
*.obj

# Build artifacts
*.a
*.so

# Editor and IDE files
.vscode/
.idea/
*.swp
*.swo
*~
.DS_Store
EOF

echo "✓ .gitignore created"
echo ""
echo "✓ Setup complete!"
echo ""
echo "Usage:"
echo "  make <filename>  # Compile and run filename.c"
echo ""
echo "Examples:"
echo "  make hello       # Compiles hello.c and runs hello.out"
echo "  make test        # Compiles test.c and runs test.out"
echo ""
echo "Run 'make help' to see all available targets"
