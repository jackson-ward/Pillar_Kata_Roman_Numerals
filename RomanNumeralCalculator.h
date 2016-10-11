   /* FILE: RomanNumeralCalculator.h
      AUTHOR: Jackson Ward

      DESCRIPTION: Header file for RomanNumeralCalculator.

      CREATED ON: 10/3/2016
   */

   #ifndef ROM_NUM_CALC_H
   #define ROM_NUMCALC_H
   
   #include <stdbool.h> // import for use of type <bool>

   #define STRING_SIZE sizeof(char)*31
   // Function Declarations

   bool checkForProperInputChar(char *);
   int  compare_NumeralA_to_NumeralB(char *, char *);
   char *extractPositiveElements(char *);
   char *extractNegativeElements(char *);
   void concatNumeral(char *, char *);
   char *addNumerals(char *, char *);
   void removeNumeralFromString(char *);
   void cancelNumerals(char *, char *);
   void countAndCorrectForOnesRule(char *);
   void insertNumeral(char *, char *);
   void countAndCorrectForVsRule(char *);
   void countAndCorrectForXsRule(char *);
   void countAndCorrectForLsRule(char *);
   void countAndCorrectForCsRule(char *);
   void countAndCorrectForDsRule(char *);
   void resultFix(char *);
   char *combine(char *, char *);
   void detectAndCorrectDoubleNegatives(char *, char *);
   void insertNegatives(char *, char *);
   char *subtractNumerals(char *, char *);
   char *subtractNumerals_BorrowMethod(char *a, char *b);
   #endif // ROM_NUM_CALC_H
