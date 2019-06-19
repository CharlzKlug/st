CFLAGS = -Wall -Wshadow -O3 -g -march=native
LDLIBS = -lm

all: fl gh

fl: fl.o genann.o

gh: gh.o genann.o

clean:
	$(RM) *.o
	$(RM) test example1 example2 example3 example4 *.exe
	$(RM) persist.txt


