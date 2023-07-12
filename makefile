.PHONY: default
default: build
	cmake --build build --target run -v

build:
	cmake -S ./examples/simple -B build

clean:
	rm -rf build
