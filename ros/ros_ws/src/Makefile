# Makefile
.PHONY: clean
clean:
	rm -rf ./build/ ./install/ ./log/
.PHONY: build
build:
	find ./pi_drive/ -type f -iname "*.cpp" -o -iname "*.h" | xargs clang-format -i -style=file
	colcon build --cmake-args -G Ninja --event-handlers console_direct+
.PHONY: rebuild
rebuild: clean build

.PHONY: test
test: build
	colcon test --executor parallel --event-handlers console_cohesion+

.PHONY: all
all: rebuild test

