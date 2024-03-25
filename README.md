# DCT-II algorithm tailored for RISC-V satellites 🛰️

The goal of this project is to explore a hardware-software co-design approach to the DCT-II algorithm on a RISC-V processor. 
There is currently a rise of RISC-V processors in the industry, especially in the space domain. 
I thought it would be interesting to explore the DCT-II algorithm due to its applications in satellites, and its potential to be accelerated.
Therefore, this project places emphasis on energy efficient configurations in contrast to maximizing throughput.

## To build:
```bash
riscv64-unknown-elf-gcc -march=rv64imadcv -mabi=lp64d main.c -lm -o dct2d_riscv.out  
```
