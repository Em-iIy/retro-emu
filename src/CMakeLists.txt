# Created by: Emily (Em_iIy) Winnink
# Created on: 27/03/2026

add_executable(gb-EM-u
	main.cpp
	CPU/CPU.cpp
	CPU/Register.cpp
	CPU/Instruction.cpp
	CPU/InstructionTable.cpp
	CPU/ExtendedInstructionTable.cpp

	CPU/Implementations/ADD.cpp
	CPU/Implementations/ADDC.cpp
	CPU/Implementations/AND.cpp
	CPU/Implementations/CALL.cpp
	CPU/Implementations/COMPARE.cpp
	CPU/Implementations/DEC.cpp
	CPU/Implementations/INC.cpp
	CPU/Implementations/JUMP.cpp
	CPU/Implementations/LOAD.cpp
	CPU/Implementations/OR.cpp
	CPU/Implementations/POP.cpp
	CPU/Implementations/PUSH.cpp
	CPU/Implementations/RET.cpp
	CPU/Implementations/ROTATE.cpp
	CPU/Implementations/RST.cpp
	CPU/Implementations/SHIFT.cpp
	CPU/Implementations/SUB.cpp
	CPU/Implementations/SUBC.cpp
	CPU/Implementations/XOR.cpp

	Cartridge/Cartridge.cpp
	Cartridge/CartridgeHeader.cpp
	Cartridge/ROM.cpp
	utils/readFile.cpp
	AMemoryAccessor.cpp
	MemoryBus.cpp
	WRAM.cpp
	GameBoy.cpp
)

target_include_directories(gb-EM-u
	PUBLIC ${PROJECT_SOURCE_DIR}/inc
)

target_compile_features(gb-EM-u
	PRIVATE cxx_std_20
)

target_compile_options(gb-EM-u
	PRIVATE
	-g
)