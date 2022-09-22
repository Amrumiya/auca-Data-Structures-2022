
src = $(wildcard *.cpp)
hdr = $(wildcard *.cpp)

CXXFLAGS = -g -std=c++11 -Wall -Wextra -Wshadow -padantic -D_GlIBCXX_DEBUG -fsanitize=address -fsanitize=undefined
CXXRLSFLAGS = -O2 -std=c++11 -Wall -Wextra -Wshadow -pedantic

main: $(src) $(hdr)
	$(CXX) -o main $(CXXFLAGS) $(src)

.PHONY: release
release:
	$(CXX) -o main $(CXXRLSFLAGS) $(src)

.PHONY: clean
clean: 
	rm -f main