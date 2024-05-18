release:
	cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
	cmake --build build

debug:
	cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug
	cmake --build build
