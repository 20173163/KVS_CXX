# specify compiler, compile flags
CXX = g++
OPTS = -Wall -O -c
# specify target here (name of executable)
TARG = static
TARG2 = dll
# specify all source files here
SRCS = put.cpp get.cpp open.cpp close.cpp
STATIC = test_static.cpp $(SRCS)
DLL = test_dll.cpp $(SRCS)
HEADER = kvs.h
LIB = libstatic.a
SO = libdll.so
# this translates .c files in src list to .o’s
OBJS = $(STATIC:.cpp=.o)
OBJS2 = $(DLL:.cpp=.o)


# generate "static" and "dll" executable
all: $(TARG) $(TARG2)
# generate "static" executable
$(TARG): $(OBJS) $(LIB)
	$(CXX) -static -o test_$(TARG) $(OBJS) ./$(LIB)
# generate "dll" executable
$(TARG2): $(OBJS2) $(SO)
	$(CXX) -o test_$(TARG2) test_$(TARG2).cpp -ldl
# libstatic.a
$(LIB): $(OBJS)
	ar rcs $@ $<
# libdll.so
$(SO): $(SRCS)
	$(CXX) -shared -fPIC -o $(SO) $(SRCS) $(HEADER)
# this is a generic rule for .o files
%.o: %.cpp $(HEADER)
	$(CXX) $(OPTS) $< -o $@
# clean line
clean:
	rm -f test_$(TARG) test_$(TARG2) $(OBJS) $(OBJS2) $(LIB) $(SO) test_$(TARG).txt test_$(TARG2).txt
