CC=gcc -I include_files
deps = stack.o common.o
LIST = stack common virtualmachine codegenerator infixtopostfix tokenizer
objects = $(addsuffix .o, $(LIST))
test_targets = $(addprefix test_, $(LIST))

calculator:  $(objects) main.o
			@echo "Building calculator"
			$(CC) -o calculator $^

all: $(test_targets) $(LIST)

$(LIST): %: $(deps)
	@echo $^
	$(CC) -D NOMAIN -o $@ $@.c $^

$(test_targets): test_%: %.o $(deps)
	$(CC) -o $@.t Test_Suite/unit$@.c $^

unittest: $(test_targets)
	$(CC) -o unittest_calculator Test_Suite/unittest_main.c

integration_test: infixtopostfix.o tokenizer.o codegenerator.o $(deps)
	$(CC) -o test_tokenizer_infixtopostfix.t Test_Suite/integrationtest_tokenizer_infixtopostfix.c $^
	$(CC) -o test_infixtopostfix_codegenerator.t Test_Suite/integrationtest_infixtopostfix_codegenerator.c $^


test_system: $(objects)
	$(CC) -o test_system.t $(objects) Test_Suite/test_system.c

test: $(test_targets) integration_test test_system
		$(CC) -o test_calculator test_main.c

.PHONY: clean check
clean:
	@rm -f unittest_calculator calculator *.o *.t $(LIST)

check: test
	./test_calculator
