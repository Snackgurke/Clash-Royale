WARNFLAGS = -W -Wall
OPTFLAGS = -O3
CFLAGS += $(WARNFLAGS) $(OPTFLAGS)
programme = main


all: $(programme)


main: func.c


clean:
	$(RM) *.o $(programme)
