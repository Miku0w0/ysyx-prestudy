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
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp"| grep -v sim_main.cpp)
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

.PHONY: default all clean run help lint

# verilator simulate
SIM_OBJ_DIR = $(BUILD_DIR)/sim_obj_dir
SIM_BIN = $(abspath $(BUILD_DIR)/sim_top)  # 使用绝对路径
SIM_CSRCS = $(shell find ./csrc -name "*.c" -or -name "*.cc" -or -name "*.cpp"| grep -v main.cpp)
SIM_CSRCS += csrc/sim_main.cpp  # 仿真入口

sim: $(VSRCS) $(SIM_CSRCS)
	@rm -rf $(SIM_OBJ_DIR)
	$(shell mkdir -p $(BUILD_DIR))  # 添加这一行确保 build 目录存在
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

lint: $(VSRCS)
	verilator --lint-only -Wall --top-module $(TOPNAME) $^
	@echo "✓ 代码检查通过"

help:
	@echo "可用目标:"
	@echo "  all        - 构建 NVBoard 版本 (默认)"
	@echo "  run        - 运行 NVBoard 版本"
	@echo "  sim        - 构建并运行 Verilator 仿真"
	@echo "  wave       - 使用 gtkwave 查看波形"
	@echo "  lint       - 代码语法检查"
	@echo "  clean      - 清理构建文件"
	@echo "  help       - 显示此帮助信息"
