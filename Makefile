all:	evolution	gui
	g++	-o	release/Main.o	bin/base.o	bin/gui.o	src/main/main.cpp	-lfltk	-lfltk_images	-lpthread	-Ofast

evolution:
	g++	-c	src/evolution/base.cpp
	mv	base.o	bin/base.o

gui:
	g++	-c	src/gui/gui.cxx
	mv	gui.o	bin/gui.o

clean:
	rm bin/*



run:
	./release/Main.o
