CC=gcc -I include_files
objects = main.o codegenerator.o infixtopostfix.o \
		tokenizer.o virtualmachine.o stack.o common.o

calculator:  $(objects)
			@echo "Building calculator"
			$(CC) -o calculator $(objects)

LIST = stack common virtualmachine codegenerator infix2postfix tokenizer
targets = $(addprefix test_, $(LIST))

all: $(targets)

$(targets): test_%: %.o stack.o common.o
	$(CC) -o $@.t $< Test_Suite/unit$@.c

.PHONY: clean
clean:
	-rm calculator *.o test_calculator.t
