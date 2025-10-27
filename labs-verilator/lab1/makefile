TOP = mux241
SRCS = $(TOP).v
CXX_SRCS = main.cpp
EXEC = sim

all: $(EXEC)

$(EXEC):
	verilator -Wall --cc --trace $(SRCS) --exe $(CXX_SRCS) -o $(EXEC)
	make -C obj_dir -f V$(TOP).mk
	cp obj_dir/$(EXEC) .

run: all
	./$(EXEC)

clean:
	rm -rf obj_dir $(EXEC) wave.vcd
