target=TewiBook

obj=main.o \
	method.o \
	MenuController.o \
	AppController.o

CC:=g++

$(target): $(obj)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) -o $@ -c $<

.PHONY:clean cleanall
clean:
	-rm -rf $(obj) $(target)

cleanall:
	-rm -rf *.o
