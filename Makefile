CC=gcc -I include_files
objects = main.o codegenerator.o infixtopostfix.o \
		tokenizer.o virtualmachine.o stack.o common.o

calculator:  $(objects) 
			@echo "Building calculator"
			$(CC) -o calculator $(objects) 

# codegenerator.o: include_files/common.h
# virtualmachine.o: include_files/stack.h
# main.o: include_files/stack.h include_files/common.h
# dummy.o:	

test: $(objects) test_main.o
			$(CC) -o test_calculator.t $(objects) test_main.o
			./test_calculator.t

.PHONY: clean
clean:
	-rm calculator *.o test_calculator.t