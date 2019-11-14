CC=gcc -I include_files
deps = stack.o common.o
LIST = stack common virtualmachine codegenerator infixtopostfix tokenizer
objects = $(addsuffix .o, $(LIST))
test_targets = $(addprefix test_, $(LIST))


calculator:  $(objects) main.o
			@echo "Building calculator"
			$(CC) -o calculator $(objects) main.o

all: $(test_targets) $(LIST)

$(LIST): %: $(deps)
	@echo $^
	$(CC) -D NOMAIN -o $@ $@.c $^

$(test_targets): test_%: %.o $(deps)
	$(CC) -o $@.t Test_Suite/unit$@.c $^

unittest: $(test_targets)
	$(CC) -o unittest_calculator Test_Suite/unittest_main.c


.PHONY: clean
clean:
	@rm -f unittest_calculator calculator *.o *.t $(LIST)
