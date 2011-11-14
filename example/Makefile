RM = /bin/rm -f

C++ = g++
CCFLAGS = -g -I. -I/usr/X11R6/include -L/usr/X11R6/lib

LDFLAGS = -lpthread -lglut -lGLU -lGL
# -lm -lXi -lX11 -lXmu -lXext

.PHONY: clean
clean:
	@echo --- $@ ---
	-$(RM) *.o core

# Compile and link
terrain: terrain.cpp
	@echo --- $@ ---
	$(C++) $(CCFLAGS) terrain.cpp -o terrain $(LDFLAGS)

# Compile
iri_vec.o: iri_vec.c iri_vec.h
	@echo --- $@ ---
	$(C++) -c iri_vec.c

# Compile
terrain-answer.o: terrain-answer.cpp iri_vec.h
	@echo --- $@ ---
	$(C++) $(CCFLAGS) -c terrain-answer.cpp

# Link
terrain-answer: terrain-answer.o iri_vec.o
	@echo --- $@ ---
	$(C++) $(CCFLAGS) terrain-answer.o iri_vec.o -o terrain-answer $(LDFLAGS)


