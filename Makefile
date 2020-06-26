all_linux:	evolution
	g++	-o	release/Main.o	bin/base.o	src/main/main.cpp	-lpthread	-lglut	-lGLU	-lGL	-w

all_mac:	evolution
	g++	-o	release/Main.o	bin/base.o	src/main/main.cpp	-I/usr/local/include	-lpthread	-framework	OpenGL	-framework	GLUT	-w

evolution:
	g++	-c	src/evolution/base.cpp
	mv	base.o	bin/base.o

clean:
	rm bin/*

install_lib:
	sudo apt install mesa-common-dev freeglut3-dev

run:
	./release/Main.o
