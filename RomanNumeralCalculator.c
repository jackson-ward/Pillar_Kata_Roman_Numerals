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
      char *nega = extractNegativeElements(a);
      char *negb = extractNegativeElements(b);

      cancelNumerals(posa, negb);
      cancelNumerals(posb, nega);

      char *ptr = posb;

      while (*ptr != '\0')
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
      
      ptr = negb;
      char *ptr2 = nega;
      bool armed = false;

      while (*ptr != '\0')
      {
         while (*ptr2 != '\0')
         {
            if (*ptr == 'I' && *ptr2 == 'I')
            {
               removeNumeralFromString(ptr);
               removeNumeralFromString(ptr2);
               armed = true;

               char *ptr3 = result;
               while (*ptr3 != '\0' && armed)
               {
                  if (*ptr3 == 'V')
                  {
                     armed = false;

                     char I = 'I';
                     char *i = &I;

                     removeNumeralFromString(ptr3);
                     concatNumeral(i, ptr3);
                     concatNumeral(i, ptr3);
                     concatNumeral(i, ptr3);
                  }

                  if (*ptr3 == 'X')
                  {
                     armed = false;

                     char I = 'I';
                     char *i = &I;
                     char V = 'V';
                     char *v = &V;
                     removeNumeralFromString(ptr3);
                     concatNumeral(v, ptr3);
                     concatNumeral(i, ptr3);
                     concatNumeral(i, ptr3);
                     concatNumeral(i, ptr3);
                  }

                  ptr3 = ptr3 + sizeof(char);
               }
            }

            ptr2 = ptr2 + sizeof(char);
         }

         ptr = ptr + sizeof(char);
      }      

      countAndCorrectForOnesRule(result);
      countAndCorrectForVsRule(result);
      countAndCorrectForXsRule(result);
      countAndCorrectForLsRule(result);      
      countAndCorrectForCsRule(result);
      countAndCorrectForDsRule(result);

      ptr = negb;
      while (*ptr != '\0')
      {
         concatNumeral(ptr, nega);
         ptr = ptr + sizeof(char);
      }

      ptr = nega;
      ptr2 = result;

      while (*ptr2 != '\0')
      {
         ptr2 = ptr2 + sizeof(char);
      }

      while (*ptr != '\0')
      {
         if (compare_NumeralA_to_NumeralB(ptr, ptr2) == 2)
         {
            insertNumeral(ptr, ptr2);
            ptr = ptr + sizeof(char);
         }
         
         ptr2 = ptr2 - sizeof(char);
      }

      free(posa);
      free(posb);
      free(nega);
      free(negb);

      ptr = result; while (*ptr != '\0') { printf("%c", *ptr); ptr = ptr + sizeof(char);} printf("\n");
      
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

   /*************** Function: countAndCorrectForXsRule *************************

       Input: char *input -> point to the head of string to modify

      Output: none

     Purpose: Produces string that doesn't violate Xs rule
   ******************************************************************************/
   void countAndCorrectForXsRule(char *input)
   {
      unsigned short cnt = 0;
      char *X_a[4];

      char *ptr = input;

      while (*ptr != '\0')
      {
         if (*ptr == 'X')
         {
            X_a[cnt] = ptr;
            cnt++;
         }

         ptr = ptr + sizeof(char);
      }

      if (cnt == 4)
      {
         char X = 'X';
         char L = 'L';
         char *x = &X;
         char *l = &L;

         int j;
         for (j = 3; j >= 0; j--)
         {
            removeNumeralFromString(X_a[j]);
         }

         concatNumeral(x, input);
         concatNumeral(l, input);
      }
   }

   /*************** Function: countAndCorrectForVsRule *************************

       Input: char *input -> point to the head of string to modify

      Output: none

     Purpose: Produces string that doesn't violate v rule
   ******************************************************************************/
   void countAndCorrectForVsRule(char *input)
   {
      char *ptr = input;
      
      if (*ptr == '\0')
      {
         return;
      }

      char *nxt = ptr + sizeof(char);

      while (*nxt != '\0')
      {
         if (*ptr == 'V' && *nxt == 'V')
         {
            removeNumeralFromString(nxt);
            removeNumeralFromString(ptr);

            char X = 'X';
            char *x = &X;

            insertNumeral(x, ptr);
         }

         ptr = nxt;
         nxt = nxt + sizeof(char);
      }
      
   }
  
   /*************** Function: countAndCorrectForLsRule *************************

       Input: char *input -> point to the head of string to modify

      Output: none

     Purpose: Produces string that doesn't violate Ls rule
   ******************************************************************************/
   void countAndCorrectForLsRule(char *input)
   {
      char *ptr = input;

      if (*ptr == '\0')
      {
         return;
      }

      char *nxt = ptr + sizeof(char);

      while (*nxt != '\0')
      {
         if (*ptr == 'L' && *nxt == 'L')
         {
            removeNumeralFromString(nxt);
            removeNumeralFromString(ptr);

            char C = 'C';
            char *c = &C;

            insertNumeral(c, ptr);
         }

         ptr = nxt;
         nxt = nxt + sizeof(char);
      }

   }

   /*************** Function: countAndCorrectForCsRule *************************

       Input: char *input -> point to the head of string to modify

      Output: none

     Purpose: Produces string that doesn't violate Cs rule
   ******************************************************************************/
   void countAndCorrectForCsRule(char *input)
   {
      unsigned short cnt = 0;
      char *C_a[4];

      char *ptr = input;

      while (*ptr != '\0')
      {
         if (*ptr == 'C')
         {
            C_a[cnt] = ptr;
            cnt++;
         }

         ptr = ptr + sizeof(char);
      }

      if (cnt == 4)
      {
         char C = 'C';
         char D = 'D';
         char *c = &C;
         char *d = &D;

         int j;
         for (j = 3; j >= 0; j--)
         {
            removeNumeralFromString(C_a[j]);
         }

         concatNumeral(c, input);
         concatNumeral(d, input);
      }
   }   

   /*************** Function: countAndCorrectForDsRule *************************

       Input: char *input -> point to the head of string to modify

      Output: none

     Purpose: Produces string that doesn't violate Ds rule
   ******************************************************************************/
   void countAndCorrectForDsRule(char *input)
   {
      char *ptr = input;

      if (*ptr == '\0')
      {
         return;
      }

      char *nxt = ptr + sizeof(char);

      while (*nxt != '\0')
      {
         if (*ptr == 'D' && *nxt == 'D')
         {
            removeNumeralFromString(nxt);
            removeNumeralFromString(ptr);

            char M = 'M';
            char *m = &M;

            insertNumeral(m, ptr);
         }

         ptr = nxt;
         nxt = nxt + sizeof(char);
      }

   }
    
   /*************** Function: insertNumeral *************************

       Input: char *source -> pointer to numeral to insert

              char *target -> pointer to insertion location

      Output: none

     Purpose: Inserts a character into a string shifting left
              all characters stored to the left of or in the
              target location.
   ******************************************************************/
   void insertNumeral(char *source, char *target)
   {
      char *ptr = target;

      while (*ptr != '\0')
      {
         ptr = ptr + sizeof(char);
      }

      while (ptr != (target - sizeof(char)))
      {
         *(ptr + sizeof(char)) = *ptr;
         
         ptr = ptr - sizeof(char);
      }

      *target = *source;
   }
