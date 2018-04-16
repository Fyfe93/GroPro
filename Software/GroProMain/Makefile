
CXXFLAGS = -pedantic -Wall
SRCS = GroProMain.cpp GroProServer.cpp GroProThread.cpp Max7221DriverClass.cpp OPT.cpp pid.cpp PwmClass.cpp
OBJECTS = $(SRCS:.cpp=.o)
LIBS =  -lpthread -lwiringPi


all: GroProMain

GroProMain: $(OBJECTS)
	$(LD) -o $@ $^ $(LIBS)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $^


appname: $(OBJECTS)
	$(CXX) $(OBJECTS) -o GroProMain

clean:
	rm -f *.o GroProMain

# Scott McPeak's autodepend rule
#   http://scottmcpeak.com/autodepend/autodepend.html
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $*.cpp -o $*.o
	$(CXX) -MM $(CXXFLAGS) $*.cpp > $*.d
	@mv -f $*.d $*.d.tmp
	@sed -e 's|.*:|$*.o:|' < $*.d.tmp > $*.d
	@cp -f $*.d $*.d.tmp
	@sed -e 's/.*://' -e 's/\\$$//' < $*.d.tmp | fmt -1 | \
	  sed -e 's/^ *//' -e 's/$$/:/' >> $*.d
	@rm -f $*.d.tmp
