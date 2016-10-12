   /* FILE: RomanNumeralCalculator.h
      AUTHOR: Jackson Ward

      DESCRIPTION: Header file for RomanNumeralCalculator.

      CREATED ON: 10/3/2016
   */

   #ifndef ROM_NUM_CALC_H
   #define ROM_NUM_CALC_H
   
   #include <stdbool.h> // import for use of type <bool>

   #define STRING_SIZE sizeof(char)*31

   // Function Declarations

   #ifdef RUN_TESTS     
   char *addNumerals(char *, char *);      /////  Functions Used In TDD  /////
   char *subtractNumerals(char *, char *); ///////////////////////////////////

   #else
   char addNumerals(char *, char *, char *);      /////  Functions Used In Production  /////
   char subtractNumerals(char *, char *, char *); //////////////////////////////////////////
   #endif

   bool checkForProperInputChar(char *);
   bool detectOverflow(char *);
   bool detectLargerSubtrahend(char *, char *);
   int  compare_NumeralA_to_NumeralB(char *, char *);
   char *extractPositiveElements(char *);
   char *extractNegativeElements(char *);
   char *combine(char *, char *);
   void concatNumeral(char *, char *);
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
   void detectAndCorrectDoubleNegatives(char *, char *);
   void insertNegatives(char *, char *);
   void borrowCancel(char *, char *);
   void breakup (char *, char *);
   #endif // ROM_NUM_CALC_H
