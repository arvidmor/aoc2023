
SRCS := $(wildcard */*.c)
EXES := $(patsubst %.c, %.out, $(SRCS))

.PHONY: all setup clean run
all: $(EXES)

$(EXES): $(SRCS)
	@for src in $(SRCS); do \
		gcc -g -Wall $$src -o $${src%.c}.out; \
	done

setup: 
	@echo "Which day?"
	@read -i "day" day;\
	day="day$$day";\
	if [ -d day$$day ]; then \
		echo "$$day already exists";\
		continue;\
	fi;\
	mkdir $$day;\
	cat template.c > $$day/$$day.c;\
	touch $$day/input.txt;\


run:
	@echo "Which day?"
	@read -i "day" day;\
	day="day$$day";\
	valgrind ./$$day/$$day.out $$day/input.txt

clean:
	@rm -rf $(EXES)