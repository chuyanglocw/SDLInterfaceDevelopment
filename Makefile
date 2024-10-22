
srcs = $(wildcard src/*.cpp)
objs = $(patsubst src/%.cpp,objs/%.o,$(srcs))

include_dir = ./include
lib_dir = ./bin
libs = SDL2 SDL2_image SDL2_ttf SDL2_mixer SDL2_net

I_options = $(include_dir:%=-I%)
l_options = $(libs:%=-l%)
L_options = $(lib_dir:%=-L%)

L_options += -mwindows

include_linking = $(I_options) -fPIC
lib_linking = $(l_options) $(L_options)

objs/%.o: src/%.cpp
	g++ -c $< -o $@ $(include_linking)

bin/game: $(objs)
	g++ $^ -o $@ $(l_options) $(L_options)

run: bin/game
	$<

clean:
	del /p objs\*
	del /p bin\game.exe

debug:
	@echo $(srcs)
	@echo $(objs)

.PHONY: debug run
