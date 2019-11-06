CC=gcc -I include_files
objects = codegenerator.o infixtopostfix.o \
		tokenizer.o virtualmachine.o stack.o

calculator:  $(objects) main.o
			$(CC) -o calculator $(objects) main.o

test: $(objects) test_main.o
			$(CC) -o test_calculator.t $(objects) test_main.o
			./test_calculator.t
	

.PHONY: clean
clean:
	-rm calculator $(objects) main.o test_main.o test_calculator.t