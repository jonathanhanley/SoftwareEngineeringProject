CC=gcc -I include_files
objects = main.o codegenerator.o infixtopostfix.o \
		tokenizer.o virtualmachine.o stack.o

calculator:  $(objects)
			$(CC) -o calculator $(objects)



.PHONY: clean
clean:
	-rm calculator ${objects}