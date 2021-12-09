EXE	= a.out

all: a.out

a.out: main.cpp
	g++ -std=c++11 -g $^  $@

clean:
	rm -rf ${EXE}