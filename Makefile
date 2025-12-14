#------------------------------------------------------------------------------
# Makefile for Enigma Project
# Structure:
#   include/  -> Header files (.h)
#   source/   -> Implementation files (.c)
#   app/      -> Entry point (main.c)
#------------------------------------------------------------------------------

# Define compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -pedantic -std=c99 -g -Iinclude

# Application name
TARGET = enigma

# Define source files to compile
SRCS = app/main.c $(wildcard source/*.c)

# Build rule
all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Housekeeping
clean:
	rm -f $(TARGET)
