objects = main.o LinkedList.o
CCFLAGS = -Wall -Wextra
LDFLAGS = -lobject

main : $(objects)
	cc $(CCFLAGS) -o main $(objects) $(LDFLAGS)
.PHONY : clean
clean:
	rm -f main $(objects)
