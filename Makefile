
SRCS := $(wildcard */*.c)
EXES := $(patsubst %.c, %.out, $(SRCS))

.PHONY: all setup clean run
all: $(EXES)

$(EXES): $(SRCS)
	@for src in $(SRCS); do \
		gcc -g -Wall $$src -o $${src%.c}.out; \
	done

setup: 
	@for day in {1..24}; do \
		if [ -d day$$day ]; then \
			echo "day$$day already exists";\
			continue;\
		fi;\
		mkdir day$$day;\
		cat template.c > day$$day/day$$day.c;\
		touch day$$day/input.txt;\
	done

run:
	@echo "Which day?"
	@read -i "day" day;\
	day="day$$day";\
	valgrind ./$$day/$$day.out $$day/input.txt

clean:
	@rm -rf $(EXES)