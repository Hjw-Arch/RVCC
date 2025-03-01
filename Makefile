BUILD_DIR = ./build

$(shell mkdir -p $(BUILD_DIR))

CC = gcc
CROSS_COMPILER = riscv64-unknown-linux-gnu-gcc
CROSS_CFLAGS = -static

SRC ?= main.c
EXE_FILE ?= $(abspath $(BUILD_DIR)/$(basename $(SRC)))
ASM_FILE ?= $(abspath $(BUILD_DIR)/rvcc.s)
TARGET_FILE ?= $(abspath $(BUILD_DIR)/$(notdir $(basename $(ASM_FILE))))

NUM ?= 42

.PHONY: build clean

build: $(SRC)
	@$(CC) $(SRC) -o $(EXE_FILE)
	@$(EXE_FILE) $(NUM) > $(ASM_FILE)
	@$(CROSS_COMPILER) $(CROSS_CFLAGS) $(ASM_FILE) -o $(TARGET_FILE)
	-@qemu-riscv64 $(TARGET_FILE) > /dev/null 2>&1; echo "$$?"


clean:
	rm -rf $(BUILD_DIR)
