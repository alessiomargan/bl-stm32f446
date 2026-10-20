# Convenience targets for building and flashing the STM32F446 bootloader project

# Configuration
BUILD_DIR := build/Debug
ELF := $(BUILD_DIR)/bl-stm32f446.elf
BIN := $(BUILD_DIR)/bl-stm32f446.bin
# Default target
.PHONY: all
all: build

# Configure + Build (Debug preset)
.PHONY: configure build
configure:
	cmake --preset Debug

build: configure
	cmake --build $(BUILD_DIR) --clean-first -- -v

# CMake's post-build step generates the .bin from the ELF.
.PHONY: bin
bin: build
	@test -f "$(BIN)"

# Flash via stlink-tools (st-flash)
.PHONY: flash
flash: bin
	st-flash write $(BIN) 0x08000000

# Flash via OpenOCD (uses ELF; requires openocd in PATH)
.PHONY: flash-openocd
flash-openocd: build
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg \
		-c "program $(ELF) verify reset exit"

# Clean build artifacts
.PHONY: clean
clean:
	rm -rf build

# Size report
.PHONY: size
size: build
	arm-none-eabi-size $(ELF)
