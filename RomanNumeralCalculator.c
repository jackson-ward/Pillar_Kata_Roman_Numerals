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
         
         negPtr = neg;   
   
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

      char *pos = combine(posa, posb);
      char *neg = combine(nega, negb);
      
      cancelNumerals(pos, neg);

      char *result = malloc(STRING_SIZE);
      char *ptr = pos;
    
      while (*ptr != '\0')
      {
         concatNumeral(ptr, result);
         ptr = ptr + sizeof(char);
      }

      ptr = result;

      char *pos2 = extractPositiveElements(result);
      char *neg2 = extractNegativeElements(result);
      neg = combine(neg, neg2);

      cancelNumerals(pos2, neg);

      ptr = pos2;

      *result = '\0';
      
      while (*ptr != '\0')
      {
         concatNumeral(ptr, result);
         ptr = ptr + sizeof(char);
      }
      
      detectAndCorrectDoubleNegatives(result, neg);
      insertNegatives(result, neg);

      countAndCorrectForOnesRule(result);
      countAndCorrectForVsRule(result);
      countAndCorrectForXsRule(result);
      countAndCorrectForLsRule(result);
      countAndCorrectForCsRule(result);
      countAndCorrectForDsRule(result);      

      pos2 = extractPositiveElements(result);
      neg2 = extractNegativeElements(result);

      cancelNumerals(pos2, neg2);

      ptr = pos2;

      *result = '\0';

      while (*ptr != '\0')
      {
         concatNumeral(ptr, result);
         ptr = ptr + sizeof(char);
      }

      detectAndCorrectDoubleNegatives(result, neg2);
      insertNegatives(result, neg2);

      free(posa);
      free(posb);
      free(pos);
      free(nega);
      free(negb);
      free(neg);

      //resultFix(result); 

      ptr = result; while (*ptr != '\0') { printf("%c", *ptr); ptr = ptr + sizeof(char);} printf("\n");
      
      return result;
   }

   char *subtractNumerals(char *a, char *b)
   {
      char *posa = extractPositiveElements(a);
      char *negb = extractPositiveElements(b);
      char *nega = extractNegativeElements(a);
      char *posb = extractNegativeElements(b);
   
      char *pos = combine(posa, posb);
      char *neg = combine(nega, negb);

      cancelNumerals(pos, neg);

      char *ptr = neg;
      while(*ptr != '\0')
      {
         if(*ptr == 'V')
         {
            removeNumeralFromString(ptr);
            int j;
            for (j = 0; j < 5; j++)
            {
               char I = 'I';
               char *i = &I;
               insertNumeral(i, ptr);
            }
         }

         ptr = ptr + sizeof(char);
      }

      char *result = malloc(STRING_SIZE);
      ptr = pos;

      while (*ptr != '\0')
      {
         concatNumeral(ptr, result);
         ptr = ptr + sizeof(char);
      }

      detectAndCorrectDoubleNegatives(result, neg);
      //insertNegatives(result, neg); 
      countAndCorrectForOnesRule(result);
      countAndCorrectForVsRule(result);
      countAndCorrectForXsRule(result);
      countAndCorrectForLsRule(result);
      countAndCorrectForCsRule(result);
      countAndCorrectForDsRule(result);

      char *pos2 = extractPositiveElements(result);
      char *neg2 = extractNegativeElements(result);
      neg2 = combine(neg, neg2);

      cancelNumerals(pos2, neg2);

      ptr = pos2;

      *result = '\0';

      while (*ptr != '\0')
      {
         concatNumeral(ptr, result);
         ptr = ptr + sizeof(char);
      }

      detectAndCorrectDoubleNegatives(result, neg2);
      insertNegatives(result, neg2);

      free(posa);
      free(posb);
      free(pos);
      free(nega);
      free(negb);
      free(neg);

      resultFix(result);
      
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
      char *ptr = input;
      char *ptr2;
      bool armed = false;
      int i = 0;

      while(*ptr != '\0')
      {
         if (*ptr == 'I')
         {
            armed = true;
            ptr2 = ptr;
            i = 0;
            while (i < 3)
            {
               ptr2 = ptr2 + sizeof(char);

               if (*ptr2 != 'I')
               {
                  armed = false;
                  ptr = ptr2;
                  i = 3;
               }

               i++;
            }

            if (armed)
            {
               armed = false;
               char I = 'I';
               char V = 'V';
               char *i = &I;
               char *v = &V;

               int j;
               for (j = 0; j < 4; j++)
               {
                  removeNumeralFromString(ptr);
               }

               insertNumeral(v, ptr);
               insertNumeral(i, ptr);

               ptr = ptr + sizeof(char);
            }
         }

         ptr = ptr + sizeof(char);
      }
   }

   /*************** Function: countAndCorrectForXsRule *************************

       Input: char *input -> point to the head of string to modify

      Output: none

     Purpose: Produces string that doesn't violate Xs rule
   ******************************************************************************/
   void countAndCorrectForXsRule(char *input)
   {
      char *ptr = input;
      char *ptr2;
      bool armed = false;
      int i = 0;

      while(*ptr != '\0')
      {
         if (*ptr == 'X')
         {
            armed = true;
            ptr2 = ptr;
            i = 0;
            while (i < 3)
            {
               ptr2 = ptr2 + sizeof(char);

               if (*ptr2 != 'X')
               {
                  armed = false;
                  ptr = ptr2;
                  i = 3;
               }

               i++;
            }

            if (armed)
            {
               armed = false;
               char X = 'X';
               char L = 'L';
               char *x = &X;
               char *l = &L;

               int j;
               for (j = 0; j < 4; j++)
               {
                  removeNumeralFromString(ptr);
               }

               insertNumeral(l, ptr);
               insertNumeral(x, ptr);

               ptr = ptr + sizeof(char);
            }
         }

         ptr = ptr + sizeof(char);
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

      while (*ptr != '\0')
      {
         while (*nxt != '\0')
         {
            if (*ptr == 'V' && *nxt == 'V')
            {
               removeNumeralFromString(nxt);
               removeNumeralFromString(ptr);

               char X = 'X';
               char *x = &X;

               insertNumeral(x, nxt - sizeof(char));
            }

            nxt = nxt + sizeof(char);
         }
  
         ptr = ptr + sizeof(char);
         nxt = ptr + sizeof(char);
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
      while (*ptr != '\0')
      {
         while (*nxt != '\0')
         {
            if (*ptr == 'L' && *nxt == 'L')
            {
               removeNumeralFromString(nxt);
               removeNumeralFromString(ptr);

               char C = 'C';
               char *c = &C;

               insertNumeral(c, nxt - sizeof(char));           
            }

            nxt = nxt + sizeof(char);
         } 
      
         ptr = ptr + sizeof(char);
         nxt = ptr + sizeof(char);
      }
   }

   /*************** Function: countAndCorrectForCsRule *************************

       Input: char *input -> point to the head of string to modify

      Output: none

     Purpose: Produces string that doesn't violate Cs rule
   ******************************************************************************/
   void countAndCorrectForCsRule(char *input)
   {
      char *ptr = input;
      char *ptr2;
      bool armed = false;
      int i = 0;

      while(*ptr != '\0')
      {
         if (*ptr == 'C')
         {
            armed = true;
            ptr2 = ptr;
            i = 0;
            while (i < 3)
            {
               ptr2 = ptr2 + sizeof(char);

               if (*ptr2 != 'C')
               {
                  armed = false;
                  ptr = ptr2;
                  i = 3;
               }

               i++;
            }

            if (armed)
            {
               armed = false;
               char C = 'C';
               char D = 'D';
               char *c = &C;
               char *d = &D;

               int j;
               for (j = 0; j < 4; j++)
               {
                  removeNumeralFromString(ptr);
               }

               insertNumeral(d, ptr);
               insertNumeral(c, ptr);

               ptr = ptr + sizeof(char);
            }
         }
    
         ptr = ptr + sizeof(char);
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

      while (*ptr != '\0')
      {
         while (*nxt != '\0')
         {
            if (*ptr == 'D' && *nxt == 'D')
            {
               removeNumeralFromString(nxt);
               removeNumeralFromString(ptr);

               char M = 'M';
               char *m = &M;

               insertNumeral(m, nxt - sizeof(char));
            }

            nxt = nxt + sizeof(char);
         }

         ptr = ptr + sizeof(char);
         nxt = ptr + sizeof(char);
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

   /*************** Function: resultFix ****************************

       Input: char *input -> pointer to string to be fixed for 
                             proper rules 

      Output: none

     Purpose: Detects and repairs improper subtrahend - minuend pair
   *****************************************************************/
   void resultFix(char *input)
   {
      char *ptr = input;
      char *nxt = ptr + sizeof(char);
      char *replacement = malloc(STRING_SIZE);
      bool armed = false;
      static char I, X, L, C, D, M;
     
      I = 'I';
      X = 'X';
      L = 'L';
      C = 'C';
      D = 'D';
      M = 'M';

      *replacement = '\0';
      
      while (*ptr != '\0')
      {
         if (*ptr == 'I')
         {
            switch (*nxt)
            {
               case 'L':
                          concatNumeral(&X, replacement);
                          concatNumeral(&L, replacement);
                          concatNumeral(&I, replacement);
                          concatNumeral(&X, replacement);
                        
			  armed = true;
                          break;

               case 'C':
                          concatNumeral(&X, replacement);
                          concatNumeral(&C, replacement);
                          concatNumeral(&I, replacement);
                          concatNumeral(&X, replacement);

                          armed = true;   
                          break;

               case 'D':
                          concatNumeral(&C, replacement);
                          concatNumeral(&D, replacement);
                          concatNumeral(&X, replacement);
                          concatNumeral(&C, replacement);
                          concatNumeral(&I, replacement);
                          concatNumeral(&X, replacement);
 
                          armed = true;
                          break; 

               case 'M':
                          concatNumeral(&C, replacement);
                          concatNumeral(&M, replacement);
                          concatNumeral(&X, replacement);
                          concatNumeral(&C, replacement);
                          concatNumeral(&I, replacement);
                          concatNumeral(&X, replacement);

                          armed = true;
                          break;

                default:  break;
            } 
         }

         else if (*ptr == 'X')
         {
            switch(*nxt)
            {
               case 'D':
                          concatNumeral(&C, replacement);
                          concatNumeral(&D, replacement);
                          concatNumeral(&X, replacement);
                          concatNumeral(&C, replacement);

                          armed = true;
                          break;

               case 'M':
                          concatNumeral(&C, replacement);
                          concatNumeral(&M, replacement);
                          concatNumeral(&X, replacement);
                          concatNumeral(&C, replacement);

                          armed = true;
                          break;

                default:  break;
            }
         }

         if (armed)
         {
            armed = false;

            removeNumeralFromString(ptr);
            removeNumeralFromString(ptr);

            char *ptr2 = replacement;
            while (*ptr2 != '\0')
            {
               insertNumeral(ptr2, ptr);
               
               ptr = ptr + sizeof(char);
               ptr2 = ptr2 + sizeof(char);
            }
         }

         else
         {
            ptr = ptr + sizeof(char);
         }
  
         nxt = ptr + sizeof(char);

         *replacement = '\0';
      }

      free(replacement);
   }

   char *combine(char *a, char *b)
   {
      char *ptra = a;
      char *ptrb = b;
      char *result = malloc(STRING_SIZE);
            *result = '\0';

      while (*ptra != '\0' || *ptrb != '\0')
      {
         int compare = compare_NumeralA_to_NumeralB(ptra, ptrb);

         if (compare == 1 || *ptrb == '\0')
         {
            concatNumeral(ptra, result);
            ptra = ptra + sizeof(char);
         }

         else if (compare == 2 || *ptra == '\0')
         {
            concatNumeral(ptrb, result);
            ptrb = ptrb + sizeof(char);
         }

         else
         {
            concatNumeral(ptra, result);
            concatNumeral(ptrb, result);
            ptra = ptra + sizeof(char);
            ptrb = ptrb + sizeof(char);
         }
      }

      return result;
   }

   void detectAndCorrectDoubleNegatives(char *result, char *neg)
   {
      bool armed = false;

      char *ptr = neg;      
      if (*ptr == '\0') return;

      char *ptr2 = ptr + sizeof(char);
      char *ptr3 = result;
      char *head = ptr3;

      while (*ptr2 != '\0')
      {  
         ptr3 = result;

         while (*ptr3 != '\0')
         {
            ptr3 = ptr3 + sizeof(char);
         }

            if (*ptr == *ptr2)
            {
               char offender = *ptr;
               removeNumeralFromString(ptr);
               removeNumeralFromString(ptr);
               armed = true;

               while (ptr3 != (head - sizeof(char)) && armed)
               {
                  if (*ptr3 == 'V' && offender == 'I')
                  {
                     armed = false;

                     char I = 'I';
                     char *i = &I;

                     removeNumeralFromString(ptr3);
                     insertNumeral(i, ptr3);
                     insertNumeral(i, ptr3);
                     insertNumeral(i, ptr3);
                  }

                  if (*ptr3 == 'X' && offender == 'I')
                  {
                     armed = false;

                     char I = 'I';
                     char *i = &I;
                     char V = 'V';
                     char *v = &V;
                     removeNumeralFromString(ptr3);
                     insertNumeral(i, ptr3);
                     insertNumeral(i, ptr3);
                     insertNumeral(i, ptr3);
                     insertNumeral(v, ptr3);
                  }

                  if (*ptr3 == 'L' && offender == 'I')
                  {
                     armed = false;

                     char I = 'I';
                     char *i = &I;
                     char L = 'L';
                     char *l = &L;
                     char X = 'X';
                     char *x = &X;
                     char V = 'V';
                     char *v = &V;
                     removeNumeralFromString(ptr3);
                     insertNumeral(i, ptr3);
                     insertNumeral(i, ptr3);
                     insertNumeral(i, ptr3);
                     insertNumeral(v, ptr3);
                     insertNumeral(l, ptr3);
                     insertNumeral(x, ptr3);
                  }

                  if (*ptr3 == 'L' && offender == 'X')
                  {
                     armed = false;

                     char X = 'X';
                     char *x = &X;
                     removeNumeralFromString(ptr3);
                     insertNumeral(x, ptr3);
                     insertNumeral(x, ptr3);
                     insertNumeral(x, ptr3);
                  }

                  if (*ptr3 == 'C' && offender == 'X')
                  {
                     armed = false;

                     char L = 'L';
                     char *l = &L;
                     char X = 'X';
                     char *x = &X;
                     removeNumeralFromString(ptr3);
                     insertNumeral(x, ptr3);
                     insertNumeral(x, ptr3);
                     insertNumeral(x, ptr3);
                     insertNumeral(l, ptr3);
                  }

                  if (*ptr3 == 'D' && offender == 'C')
                  {
                     armed = false;

                     char C = 'C';
                     char *c = &C;
                     removeNumeralFromString(ptr3);
                     insertNumeral(c, ptr3);
                     insertNumeral(c, ptr3);
                     insertNumeral(c, ptr3);
                  }

                  if (*ptr3 == 'M' && offender == 'C')
                  {
                     armed = false;

                     char D = 'D';
                     char *d = &D;
                     char C = 'C';
                     char *c = &C;
                     removeNumeralFromString(ptr3);
                     insertNumeral(c, ptr3);
                     insertNumeral(c, ptr3);
                     insertNumeral(c, ptr3);
                     insertNumeral(d, ptr3);
                  }

                  ptr3 = ptr3 - sizeof(char);
               }
            }
            
            else
            {
               ptr2 = ptr2 + sizeof(char);
               ptr = ptr + sizeof(char);
            }
      } 
   }

   void insertNegatives(char *result, char *neg)
   {
      char *ptr = neg;
      if (*ptr == '\0') return;

      char *head = ptr;
      char *ptr2 = result;

      while (*ptr2 != '\0')
      {
         ptr2 = ptr2 + sizeof(char);
      }

      while (*ptr != '\0')
      {
         ptr = ptr + sizeof(char);
      }

      ptr = ptr - sizeof(char);

      while (ptr != (head - sizeof(char)))
      {
         if (compare_NumeralA_to_NumeralB(ptr, ptr2) == 2)
         {
            insertNumeral(ptr, ptr2);
            ptr = ptr - sizeof(char);
            ptr2 = ptr2 + sizeof(char);
         }

         if (compare_NumeralA_to_NumeralB(ptr, ptr2) == 0)
         {
            ptr = ptr - sizeof(char);
         }
        
         ptr2 = ptr2 - sizeof(char);
      }
   }
