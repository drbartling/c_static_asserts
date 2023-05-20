# Simple makefile to make some common tasks a little easier
# Simplifies github action and pre-commit definitions
.PHONY: test
test: build
	cmake --build build
	cd build && ctest --rerun-failed --output-on-failure


build:
	cmake -S . -B build

clean:
	rm -rf build
	rm -rf *-build-*
