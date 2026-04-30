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
