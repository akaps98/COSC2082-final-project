CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		Schiesser.o Admin.o Function.o House.o Member.o System.o

LIBS =

TARGET =	Schiesser.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
