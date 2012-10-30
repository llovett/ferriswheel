FLAGS = -I/usr/include/GL -g
LIBS = -L/usr/include -lglut -lglui -lGLU -lGL -lm

APPS = ferriswheel

all: $(APPS)

2dcube: 2dcube.cpp matrix.cpp
	g++ $(FLAGS) $(LIBS) ferriswheel.cpp -o $(APPS)

clean:
	@rm -rf $(APPS)

