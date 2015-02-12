EXEC= startC99  startCilk  startCpp  startCppAsync startD  startForOmp  startGo  startOmp  startPy startPerl startJava.class startJavaGcj startAda

all: $(EXEC)
CFLAGS+= -Wall -Werror -O3
CXXFLAGS+= -Wall -Werror -O3

startC99: startC99.c
startC99: CFLAGS+= -std=gnu11
startC99: LDLIBS+= -lpthread

startCilk: startCilk.c
startCilk: CFLAGS+=  -std=gnu11 -fcilkplus


startCpp: startCpp.cpp
startCpp: CXXFLAGS+= -std=gnu++11
startCpp: LDLIBS+= -lpthread

startCppAsync: startCppAsync.cpp
startCppAsync: CXXFLAGS+= -std=gnu++11
startCppAsync: LDLIBS+= -lpthread

startD: startD.d
	gdc -o $@ $(CFLAGS) $^


# Not yet in gcc-4.9
startForCilk: startForCilk.c
startForCilk: CFLAGS+=  -std=gnu11 -fcilkplus


startForOmp: startForOmp.c
startForOmp: CFLAGS+=  -std=gnu11 -fopenmp

startGo: startGo.go
	gccgo -g -o $@ $(CFLAGS) $^

startOmp: startOmp.c
startOmp: CFLAGS+=  -std=gnu11 -fopenmp


startJava.class: startJava.java
	javac startJava.java

startJavaGcj: startJava.java
	gcj-4.9 -o $@ --main=startJava $^


startPy:

startPerl:

startAda: startada.adb
	gnatmake -o startAda startada.adb

clean:
	rm -f $(EXEC) *.o *.ali

