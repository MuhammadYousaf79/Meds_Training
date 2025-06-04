SV_FILE = sqrt
TB_FILE = tb_sqrt

all:
	verilator -Wall --trace -cc $(SV_FILE).sv --exe $(TB_FILE).cpp
	make -C obj_dir -f V$(SV_FILE).mk V$(SV_FILE)
	./obj_dir/V$(SV_FILE)

# Clean up generated files
clean:
	rm -rf obj_dir

