
CXXFLAGS += -I./include

LDFLAGS += -L./lib

LDLIBS += -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_net -lSDL2_ttf

main.exe: main.o implements.o
	g++ $^ -o $(basename $@) $(LDLIBS) $(LDFLAGS)
.PHONY: run clean

run: main.exe
	$<

clean:
	del *.o *.exe