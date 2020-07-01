OS := $(shell uname -s)

FLAGS := -lpthread	-lfltk	-lfltk_images	-w

ifeq ($(OS),Linux)
	LIBS := sudo apt install mesa-common-dev	libfltk1.3-dev	libfltk-images1.3
endif
ifeq ($(OS),Darwin)
		LIBS := brew install fltk
endif

all:	evolution
	g++	-o	release/Main.o	bin/base.o	src/main/main.cpp	$(FLAGS)

evolution:
	g++	-c	src/evolution/base.cpp
	mv	base.o	bin/base.o

clean:
	rm bin/* release/*

install_libs:
	$(LIBS)

run:
	./release/Main.o
