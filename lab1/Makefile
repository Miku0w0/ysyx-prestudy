# basic setting
TOPNAME = top
NXDC_FILES = constr/top.nxdc
INC_PATH ?=

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		-top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all: default

run: $(BIN)
	@$^

clean:
	rm -rf $(BUILD_DIR)

.PHONY: default all clean run

# verilator simulate
SIM_OBJ_DIR = $(BUILD_DIR)/sim_obj
SIM_BIN = $(BUILD_DIR)/sim_top
SIM_CSRCS = $(shell find ./csrc -name "*.c" -or -name "*.cc" -or -name "*.cpp")
SIM_CSRCS += csrc/sim_main.cpp  # 仿真入口

sim: $(VSRCS) $(SIM_CSRCS)
	@mkdir -p $(SIM_OBJ_DIR)
	$(VERILATOR) -cc --trace -O3 --x-assign fast --x-initial fast --noassert \
		-top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) \
		--Mdir $(SIM_OBJ_DIR) --exe csrc/sim_main.cpp -o $(SIM_BIN)
	$(MAKE) -C $(SIM_OBJ_DIR) -f V$(TOPNAME).mk
	$(SIM_BIN)


# waveform
wave:
	gtkwave $(BUILD_DIR)/waveform.vcd