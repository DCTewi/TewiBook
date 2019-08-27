target=TewiBook

obj=main.o MenuController.o method.o

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
