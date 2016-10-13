#
# FILE: Makefile
# AUTHOR: Jackson Ward
# DESCRIPTION: Makefile for RomanNumeralCalculator
# CREATED ON: 10/3/2016

CC = gcc
CFLAGS = -Wall -g -DRUN_TESTS

default: clean
default: romanNumeralCalculatorTest

example: clean
example: CFLAGS = -Wall 
example: exampleProgram

romanNumeralCalculatorTest: RomanNumeralCalculator.o RomanNumeralCalculator_TB.o
	$(CC) $(CFLAGS) -o runTests RomanNumeralCalculator.o RomanNumeralCalculator_TB.o

RomanNumeralCalculator.o: RomanNumeralCalculator.c RomanNumeralCalculator.h
	$(CC) $(CFLAGS) -c RomanNumeralCalculator.c

RomanNUmeralCalculator_TB.o: RomanNumeralCalculator.c RomanNumeralCalculator.h RomanNumeralCalculator_TB.c RomanNumeralCalculator_TB.h
	$(CC) $(CFLAGS) -c RomanNumeralCalculator_TB.c

exampleProgram: RomanNumeralCalculator.o exampleProgram.o
	$(CC) $(CFLAGS) -o exampleProgram exampleProgram.o RomanNumeralCalculator.o

exampleProgram.o: exampleProgram.c
	$(CC) $(CFLAGS) -c exampleProgram.c

clean:
	$(RM) runTest exampleProgram *.o *~
