#
# FILE: Makefile
# AUTHOR: Jackson Ward
# DESCRIPTION: Makefile for RomanNumeralCalculator
# CREATED ON: 10/3/2016

CC = gcc
CFLAGS = -Wall -g -DRUN_TESTS

default: romanNumeralCalculatorTest

romanNumeralCalculatorTest: RomanNumeralCalculator.o RomanNumeralCalculator_TB.o
	$(CC) $(CFLAGS) -o runTests RomanNumeralCalculator.o RomanNumeralCalculator_TB.o

RomanNumeralCalculator.o: RomanNumeralCalculator.c RomanNumeralCalculator.h
	$(CC) $(CFLAGS) -c RomanNumeralCalculator.c

RomanNUmeralCalculator_TB.o: RomanNumeralCalculator.c RomanNumeralCalculator.h RomanNumeralCalculator_TB.c RomanNumeralCalculator_TB.h
	$(CC) $(CFLAGS) -c RomanNumeralCalculator_TB.c

clean:
	$(RM) runTests *.o *~
