RM = /bin/rm -f

C++ = g++
CCFLAGS = -g -I. -I/usr/X11R6/include -L/usr/X11R6/lib

LDFLAGS2 = -lpthread -lglut -lGLU -lGL -lm -lXi -lX11 -lXmu -lXext
LDFLAGS = -lpthread -lglut -lGLU -lGL

.PHONY: clean
clean:
	@echo --- $@ ---
	-$(RM) *.o core

terrain: terrain.cpp
	@echo --- $@ ---
	$(C++) $(CCFLAGS) io.cpp terrain.cpp -o terrain.o $(LDFLAGS)

