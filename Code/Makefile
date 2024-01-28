#--------------------------------
# VARIABLES
#--------------------------------
# compilation
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBS = -lm -lSDL2 -lSDL2_ttf

EXEC = a.out

# directories
SRCDIR = src
OBJDIR = obj

# source and object files
SOURCES = $(wildcard $(SRCDIR)/**/*.c) $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

#--------------------------------
# EXECUTABLE
#--------------------------------
$(EXEC): $(OBJECTS) | data
	$(CC) $^ $(CFLAGS) -o $@ $(LIBS)


#--------------------------------
# OBJECT RULES
#--------------------------------
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $< -c $(CFLAGS) -o $@ $(LIBS)


#--------------------------------
# PHONY TARGETS
#--------------------------------
.PHONY: clean run $(DATADIR)

clean:
	rm -r obj $(EXEC)

run: $(EXEC)
	./$(EXEC)

data:
	mkdir -p input
	mkdir -p output
