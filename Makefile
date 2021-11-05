CFLAGS := -Wall -Werror -Wextra -std=c++17
CPPFLAGS := -MMD
CXX := g++

TARGET := bin/gameOfLife

SOURCES := $(wildcard src/gameOfLife/*.cpp)
LIBSOURCES := $(wildcard src/lib/*.cpp)
LIBMSOURCES := $(wildcard src/mlib/*.cpp)

LIBOBJ := $(patsubst src/lib/%.cpp, obj/src/%.o, $(LIBSOURCES))
LIB := obj/lib/functionLib.a

MLIBOBJ := $(patsubst src/mlib/%.cpp, obj/src/%.o, $(LIBMSOURCES))
MLIB := obj/mlib/methodsLib.a

OBJ := $(patsubst src/gameOfLife/%.cpp, obj/src/%.o, $(SOURCES))

LIBS= -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

all:$(TARGET)

$(TARGET): $(LIB) $(MLIB) $(OBJ)
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o $(TARGET) $(OBJ)  -L. $(MLIB) -L. $(LIB)  $(LIBS)

$(LIB): $(LIBOBJ)
	ar rcs $@ $^

$(MLIB): $(MLIBOBJ)
	ar rcs $@ $^

obj/src/%.o: src/lib/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ $(LIBS) -I src/lib -I src/mlib

obj/src/%.o: src/mlib/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ $(LIBS) -I src/lib -I src/mlib

obj/src/%.o: src/gameOfLife/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ $(LIBS) -Isrc/lib -I src/mlib  

run: $(TARGET)
	./bin/gameOfLife

clean:
	find . -name "*.o" -exec rm '{}' \;
	find . -name "*.d" -exec rm '{}' \;
	find . -name "*.a" -exec rm '{}' \;
	find ./bin -type f -name "gameOfLife" -exec rm -f '{}' \;
	find ./src/mlib -type f -name "logic" -exec rm -f '{}' \;

format:
	cd src; find . -name "*.cpp" -exec clang-format -i {} \;
	cd src; find . -name "*.h" -exec clang-format -i {} \;

.PHONY: clean test run all format