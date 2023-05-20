.PHONY: default
default: build
	cmake --build build --target run

build:
	cmake -S ./examples/simple -B build

clean:
	rm -rf *build*
