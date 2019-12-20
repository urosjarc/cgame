BUILD = cmake-build-debug
PROJECT = cgame

build:
	@rm ${BUILD} -rf && mkdir ${BUILD} && cd ${BUILD} && cmake .. && make

test:: build
	cd ${BUILD} && ctest

doc::
	@doxygen ./Doxyfile

run: build
	cd ${BUILD} && ./src/${PROJECT}


