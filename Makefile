

# !make -f

CXX=g++
CXXFLAGS=-std=c++11 -Werror -Wsign-conversion
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all --error-exitcode=99

SOURCES=Graph.cpp Algorithms.cpp
MAIN_SOURCES=Demo.cpp $(SOURCES)
TEST_SOURCES=TestCounter.cpp Test.cpp $(SOURCES)

MAIN_OBJECTS=$(subst .cpp,.o,$(MAIN_SOURCES))
TEST_OBJECTS=$(subst .cpp,.o,$(TEST_SOURCES))

all: Demo test

Demo: $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o Demo

test: $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: Demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./main 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o Demo test
