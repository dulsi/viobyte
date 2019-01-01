CXX = g++
CXXFLAGS = -g
LIBS = -lexpat -lphysfs

TILEDCONVERT_OBJ = tiledconvert.o expatcpp.o
TILEDCONVERT_EXE = tiledconvert

all: $(TILEDCONVERT_EXE)

$(TILEDCONVERT_EXE): $(TILEDCONVERT_OBJ)
	$(CXX) -o $(TILEDCONVERT_EXE) $(TILEDCONVERT_OBJ) $(LIBS)

%.o: %.C
	$(CXX) $(CXXFLAGS) -c -o $@ $<
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(TILEDCONVERT_EXE)

# dependencies
