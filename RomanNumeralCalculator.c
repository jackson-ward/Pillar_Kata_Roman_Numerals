   /* FILE: RomanNumeralCalculator.c
      AUTHOR: Jackson Ward

      DESCRIPTION: Source code file for RomanNumeralCalculator.

      CREATED ON: 10/3/2016
   */

   #include "RomanNumeralCalculator.h"
   #include <stdlib.h>
   #include <stdio.h>  

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
   
   /*********** Function: extractPositiveElements ***************

       Input: char *input -> pointer to input string

      Output: char *result -> pointer to resultant string

     Purpose: Allocates memory for a return string, populates
              the return string with the positive elements of
              the string pointed to by input.
   ***************************************************************/
   char *extractPositiveElements(char *input)
   {
      char *result = malloc(STRING_SIZE);
      char *insertPos = result;
      char *ptr = input;

      if (*ptr == '\0')
      {
          *result = '\0';
          return result;
      }

      char *nextPtr = input + sizeof(char);

      while (*nextPtr != '\0')
      {
         int compareResult = compare_NumeralA_to_NumeralB(ptr, nextPtr);
        
         if (compareResult == 0 || compareResult == 1)
         {
            *insertPos = *ptr;

            insertPos = insertPos + sizeof(char);
	 }
           
         ptr = ptr + sizeof(char);
         nextPtr = nextPtr + sizeof(char);
         
      }

      *insertPos = *ptr;
      *(insertPos + sizeof(char)) = '\0';

      return result;
   }

   /*********** Function: extractNegativeElements ***************

       Input: char *input -> pointer to input string

      Output: char *result -> pointer to resultant string

     Purpose: Allocates memory for a return string, populates
              the return string with the negative elements of
              the string pointed to by input.
   ***************************************************************/
   char *extractNegativeElements(char *input)
   {
      char *result = malloc(STRING_SIZE);
      char *insertPos = result;
      char *ptr = input;

      if (*ptr == '\0')
      {
         *result = '\0';
         return result;
      }

      char *nextPtr = input + sizeof(char);

      while (*nextPtr != '\0')
      {
         int compareResult = compare_NumeralA_to_NumeralB(ptr, nextPtr);

         if (compareResult == 2)
         {
            *insertPos = *ptr;

            insertPos = insertPos + sizeof(char);
            ptr = ptr + sizeof(char);
            nextPtr = nextPtr + sizeof(char);
         }

         ptr = ptr + sizeof(char);

         if (*nextPtr != '\0')
         {
            nextPtr = nextPtr + sizeof(char);
         }
      }

      *insertPos = '\0';

      return result;
   }

   /*********** Function: removeNumeralFromString ***************

       Input: char *target -> pointer to character to remove

      Output: none

     Purpose: Removes a character from a string by moving
              everything past the character to the right. 
   ***************************************************************/ 
   void removeNumeralFromString(char *target)
   {
      char *ptr = target;
        
      while (*ptr != '\0')
      {
         *ptr = *(ptr + 1);

         ptr = ptr + sizeof(char); 
      }         
   }

   /*************** Function: cancelNumerals ********************

       Input: char *pos, char *neg -> pointers to positive
                                      and negative strings

      Output: none

     Purpose: Removes Numerals from the positive and negative
              strings if they appear in both 
   ***************************************************************/
   void cancelNumerals(char *pos, char *neg)
   {
      char *posPtr = pos;
      char *negPtr = neg;

      while (*posPtr != '\0')
      {
         while (*negPtr != '\0')
         {
            if (*posPtr == *negPtr)
            {
               removeNumeralFromString(posPtr);
               removeNumeralFromString(negPtr);
               
               negPtr = neg;
            }

            else
            {
               negPtr = negPtr + sizeof(char);
            }
         }
         
	 if (*posPtr != '\0')
         {
            posPtr = posPtr + sizeof(char);
         }
      }
   }

   /*************** Function: concatNumeral ********************

       Input: char *source, char *target -> target is pointer
                         to original string, source is the char
                         to concatenate

      Output: char *result   ->    pointer to concatenated string

     Purpose: Produces string by concatenating character to an
              existing string
   ***************************************************************/
   void concatNumeral(char *source, char *target)
   {
      //char *result = malloc(STRING_SIZE);
      char *insertPos = target;

      while (*insertPos != '\0')
      {
         insertPos = insertPos + sizeof(char);
 
      }

      *insertPos = *source;
      *(insertPos + sizeof(char)) = '\0';
   }

   /*************** Function: addNumerals *************************

       Input: char *a, char*b -> point to the heads of the strings
                                 to be added

      Output: char *result   ->    pointer to "sum" string

     Purpose: Produces string by adding two input strings
   ***************************************************************/
   char *addNumerals(char *a, char *b)
   {
      char *posa = extractPositiveElements(a);
      char *posb = extractPositiveElements(b);
      char *negb = extractNegativeElements(b);

      cancelNumerals(posa, negb);

      char *ptr = posb;

      while(*ptr != '\0')
      {
         concatNumeral(ptr, posa);
         ptr = ptr + sizeof(char);
      } 

      ptr = posa;

      while (*ptr != '\0')
      {
         if (compare_NumeralA_to_NumeralB(ptr, ptr + sizeof(char)) == 2)
         {
            char tmp = *ptr;
            *ptr = *(ptr + sizeof(char));
            *(ptr + sizeof(char)) = tmp;
         }
         
         ptr = ptr + sizeof(char);
      }

      ptr = posa;
      
      char *result = malloc(STRING_SIZE);

      while (*ptr != '\0')
      {
         concatNumeral(ptr, result);
         ptr = ptr + sizeof(char);
      }
      
      countAndCorrectForOnesRule(result);

      free(posa);
      free(posb);
      free(negb);
      
      return result;
   }

   /*************** Function: countAndCorrectForOnesRule *************************

       Input: char *input -> point to the head of string to modify

      Output: none

     Purpose: Produces string that doesn't violate ones rule
   ******************************************************************************/
   void countAndCorrectForOnesRule(char *input)
   {
      unsigned short cnt = 0;
      char *ones[4];

     char *ptr = input;

      while (*ptr != '\0')
      {
         if (*ptr == 'I')
         {
            ones[cnt] = ptr;
            cnt++;
         }

         ptr = ptr + sizeof(char);
      }

      if (cnt == 4)
      {
         char I = 'I';
         char V = 'V';
         char *i = &I;
         char *v = &V;

         int j;
         for (j = 3; j >= 0; j--)
         {
            removeNumeralFromString(ones[j]);
         }

         concatNumeral(i, input);
         concatNumeral(v, input);
      }
   }
