EXEC= fiboOmp fiboCpp fiboCilk fiboC99 fiboRust
CFLAGS += -Wall -Werror -O3
CXXFLAGS += $(CFLAGS)

all: $(EXEC)

fiboOmp: fiboOmp.o
fiboOmp: CFLAGS += -std=gnu11 -fopenmp
fiboOmp: LDLIBS += -fopenmp

fiboCpp: fiboCpp.o
fiboCpp: CXXFLAGS += -std=gnu++11
fiboCpp: LDLIBS += -lpthread
fiboCpp: CC = g++

fiboCilk: fiboCilk.o
fiboCilk: CFLAGS += -fcilkplus
fiboCilk: LDFLAGS += -fcilkplus

fiboC99: fiboC99.o
fiboC99: CFLAGS += -std=gnu11

fiboRust: fiboRust.rs
	rustc -O $^

clean:
	rm -f *.o $(EXEC)
