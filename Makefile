compiler = g++

flags = -c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal 			\
		-Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs 				\
		-Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe 					\
		-fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body 					\
		-Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op 							\
		-Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith \
		-Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits 	\
		-Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

includes = ./inc/main.h ./inc/FileRunner.h ./inc/Compare.h ./inc/Errors.h ./inc/Utils.h

sources = ./src/main.cpp ./src/FileRunner.cpp ./src/Compare.cpp ./src/Utils.cpp

objects = $(sources:.cpp=.o)

execute = Onejka.exe

all: $(sources) $(execute)
	
$(execute): $(objects) 
	$(compiler) $(objects) -o $@

.cpp.o: $(includes)
	@$(compiler) $(flags) $< -o $@

clean:
	rm -rf ./src/*.o
	rm -rf *.exe