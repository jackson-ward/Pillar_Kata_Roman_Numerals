   /* FILE: RomanNumeralCalculator.h
      AUTHOR: Jackson Ward

      DESCRIPTION: Header file for RomanNumeralCalculator.

      CREATED ON: 10/3/2016
   */

   #ifndef ROM_NUM_CALC_H
   #define ROM_NUMCALC_H
   
   #include <stdbool.h> // import for use of type <bool>


   // Function Declarations

   bool checkForProperInputChar(char *);
   int  compare_NumeralA_to_NumeralB(char *, char *);
   char *extractPositiveElements(char *);
   #endif // ROM_NUM_CALC_H
