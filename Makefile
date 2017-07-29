all: init_build
	make --directory=build all

test: init_build
	make --directory=build test

test_verbose: init_build
	make --directory=build test_verbose

build_test: init_build
	make --directory=build build_test

build_test_verbose: init_build
	make --directory=build build_test_verbose

init_build:
	cmake -E make_directory build
	cmake -E chdir build cmake $(CURDIR)

clean:
	cmake -E chdir build make clean
	cmake -E remove_directory build
