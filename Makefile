FLAGS = -I/usr/include/GL -g
LIBS = -L/usr/include -lglut -lglui -lGLU -lGL -lm

APPS = ferriswheel

all: $(APPS)

ferriswheel: ferriswheel.cpp ferriswheel.h
	g++ ferriswheel.cpp -o $(APPS) $(FLAGS) $(LIBS)

clean:
	@rm -rf $(APPS)

