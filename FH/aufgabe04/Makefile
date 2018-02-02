# ---------------------------------------------	#
# Fachhochschule Wedel, Wintersemester 2017     #
# C-Uebung 03 - Bitoperationen                  #
# Helga Karafiat                                #
#                                               #
# Makefile                                      #
# ---------------------------------------------	#

# Der Dateiname des zu erstellenden Programmes
BINARY = ueb04
# Die Quelldateien des zu erstellenden Programmes
SOURCES = word.c occlist.c wordlist.c indexer.c errors.c ueb04.c
# Die Objektdateien des zu erstellenden Programmes
OBJECTS = $(SOURCES:.c=.o)

# Compiler
CC		= gcc
# Linker
LD    = gcc
# Doc generator
DOC		= doxygen

# Include directories
INCLUDES	=

# Compiler flags
CFLAGS  = -c -g -mfpmath=sse -msse2 -ansi -pedantic -Wall -Wextra -Werror
# Linker flags
LDFLAGS = 

# Optionen fuer den Pre-Compiler
#     CPPFLAGS = -DDEBUG


.PHONY: all help clean doc

all: $(BINARY)

# zeigt Informationen zur Benutzung des Makefiles an
help:
	@echo "Optionen:"
	@echo "make all      - Bibliotheken und Programm erzeugen"
	@echo "make clean    - Kompilierungsergebnisse loeschen"

# Erzeugen der Objektdateien
%.o: %.c
	@echo
	@echo "  - Building $@"
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<
	@echo "  -  ... Done"

# Linken des Programms
$(BINARY): $(OBJECTS)
	@echo
	@echo "  - linking $@"
	$(LD) -o $@ $^ $(LDFLAGS)
	@echo "  -  ... done"

doc:
	@echo "  - creating documentation"
	$(DOC)
	@echo "  ... done"

# Aufraeumen
clean:
	@echo
	@echo "  - delete object all files"
	rm -rf doc
	rm -f $(BINARY) $(OBJECTS) *~ doxygen.log
	@echo "  -  ... Done"

