all:	evolution	gui
	g++	-o	release/Main.o	bin/base.o	bin/gui.o	src/main/main.cpp	-lpthread	-lSDL	-Ofast

evolution:
	g++	-c	src/evolution/base.cpp
	mv	base.o	bin/base.o

gui:
	g++	-c	src/gui/gui.cxx
	mv	gui.o	bin/gui.o

clean:
	rm bin/*

install_lib:
	sudo apt install libsdl1.2-dev 

run:
	./release/Main.o
