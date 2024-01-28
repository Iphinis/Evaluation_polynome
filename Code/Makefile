#--------------------------------
# VARIABLES
#--------------------------------
# compilation
CC = gcc
FLAGS = -Wall -Werror -Wextra

EXEC = a.out

# directories
SRCDIR = src
OBJDIR = obj

# source and object files
SOURCES = $(wildcard $(SRCDIR)/**/*.c) $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

$(info SOURCES: $(SOURCES))

#--------------------------------
# EXECUTABLE
#--------------------------------
$(EXEC): $(OBJECTS)
	$(CC) $^ $(FLAGS) -o $@


#--------------------------------
# OBJECT RULES
#--------------------------------
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $< -c $(FLAGS) -o $@


#--------------------------------
# PHONY TARGETS
#--------------------------------
.PHONY: clean run

clean:
	rm -r obj $(EXEC)

run: $(EXEC)
	./$(EXEC)
