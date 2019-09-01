# TewiBook MakeFile for g++ 6.1.0
#

# Build Target
target=TewiBook

# Objects
obj=main.o \
        method.o \
        ItemModel.o \
	MenuController.o \
	DbController.o \
	OptionController.o \
	ExportController.o \
	AppController.o 

# Compliler
CC:=g++

# Main recipe
$(target): $(obj)
	$(CC) -o $@ $^

# For every objects
%.o: %.cpp
	$(CC) -o $@ -c $<

# Clean methods
.PHONY:clean cleanall cleanw
clean:
	-rm -rf $(obj) $(target)

cleanall:
	-rm -rf *.o

cleanw:
	-del $(obj) $(target) $(target).exe
