   /* FILE: RomanNumeralCalculator.c
      AUTHOR: Jackson Ward

      DESCRIPTION: Source code file for RomanNumeralCalculator.

      CREATED ON: 10/3/2016
   */

   #include "RomanNumeralCalculator.h"

   /*********** Function: checkForProperInputChar ***************

       Input: char *inputChar -> pointer to character to test

      Output: bool result -> boolean signifying test result

     Purpose: Checks if a type <char> variable is equal to one of
              the valid numerals (I, V, X, L, C, D, M) and returns
              true if so, and false if not.
   ***************************************************************/
   bool checkForProperInputChar(char *inputChar)
   {
      bool result = false;

      switch ( *inputChar )
      {
         case 'I' : 
         case 'V' : 
         case 'X' :
         case 'L' :
         case 'C' :
         case 'D' :
         case 'M' :
	    result = true;
         break;
         default : break; 
      }
      
      return result;
   }

   /*********** Function: compare_NumeralA_to_NumeralB ***************

       Input: char *A, char *B -> pointers to characters to compare

      Output: int result -> signifies result of operation

     Purpose: Returns a 0 if A and B are equal, a 1 if A is bigger
              than B, a 2 if A is smaller than B, and -1 if the
              given inputs were invalid
   ***************************************************************/
   int compare_NumeralA_to_NumeralB(char *A, char *B)
   {
      if (!checkForProperInputChar(A) || !checkForProperInputChar(B))
      {
           return -1;
      }

      char hierarchy[8] = {'I', 'V', 'X', 'L', 'C', 'D', 'M', '\0'};

      char *ptr = hierarchy;

      while (*ptr != '\0')
      {
         if (*A == *ptr && *B == *ptr)
         {
            return 0;
         }

         else if (*A == *ptr)
         {
            return 2;
         }

         else if (*B == *ptr)
         {
            return 1;
         }

         ptr = ptr + sizeof(char);
      }

      return -1;
   }
