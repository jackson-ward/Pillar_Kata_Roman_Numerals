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
      bool result = false; // initialize return variable to false

      switch ( *inputChar ) 
      {
         case 'I' : 
         case 'V' : 
         case 'X' :
         case 'L' :
         case 'C' :
         case 'D' :
         case 'M' :
	    	     result = true; // if the input char matches one of these cases then set return variable to true
         	     break;

         default  :  break; 
      }
      
      return result; 
   }

   /*********** Function: compare_NumeralA_to_NumeralB ***************

       Input: char *A, char *B -> pointers to characters to compare

      Output: int result -> signifies result of operation

     Purpose: Returns a 0 if A and B are equal, a 1 if A is bigger
              than B, a 2 if A is smaller than B, or a -1 if
              either input was invalid.
   ***************************************************************/
   int compare_NumeralA_to_NumeralB(char *A, char *B)
   {
      if (!checkForProperInputChar(A) || !checkForProperInputChar(B)) return -1;   // return -1 if either input was invalid
    
      char hierarchy[8] = {'I', 'V', 'X', 'L', 'C', 'D', 'M', '\0'}; // stores Numerals in increasing order

      char *ptr = hierarchy; // pointer to head of hierarchy

      while (*ptr != '\0') // execute loop until pointer reaches null terminator
      {
         if (*A == *ptr && *B == *ptr) // if *A and *B match the same character in hierarchy then return 0
         {
            return 0;
         }

         else if (*A == *ptr) // if *A matches *ptr then A is smaller than B, return 2
         {
            return 2;
         }

         else if (*B == *ptr) // if *B matches *ptr then A is bigger than B, return 1
         {
            return 1;
         }

         ptr = ptr + sizeof(char); // step ptr up in hierarchy
      }

      return -1; // input was invalid
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
      char *result = malloc(STRING_SIZE); // allocate memory for the string pointed to by the return pointer
      char *insertPos = result;           // set a pointer to the beginning of the newly allocated section
      char *ptr = input;                  // set a pointer to the beginning of the input string

      if (*ptr == '\0')    // if the input points to a null terminator then set result to point  
      {                    // to a null terminator and return result
          *result = '\0'; 
          return result;
      }

      char *nextPtr = input + sizeof(char); // set a pointer to the char after the char pointed to by ptr

      while (*nextPtr != '\0') // execute loop until nextPtr points to a null terminator
      {
         int compareResult = compare_NumeralA_to_NumeralB(ptr, nextPtr); // compare the size of the numerals pointed to by ptr and ptr2
        
         if (compareResult == 0 || compareResult == 1) // if *ptr is equal to or bigger than *nextPtr then insert *ptr into
         {                                             // the result string and step up the insert position
            *insertPos = *ptr;

            insertPos = insertPos + sizeof(char);
	 }
           
         ptr = ptr + sizeof(char);          // step up ptr
         nextPtr = nextPtr + sizeof(char);  // step up nextPtr
         
      }

      *insertPos = *ptr;                  // insert the last numeral
      *(insertPos + sizeof(char)) = '\0'; // insert the null terminator

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
      char *result = malloc(STRING_SIZE);   // allocate memory for the string pointed to by the return pointer
      char *insertPos = result;             // set a pointer to the beginning of the newly allocated section
      char *ptr = input;                    // set a pointer to the beginning of the input string

      if (*ptr == '\0')   // if the input points to a null terminator then set result to point
      {                   // to a null terminator and return result
         *result = '\0';
         return result;
      }

      char *nextPtr = input + sizeof(char);   // set a pointer to the char after the char pointed to by ptr

      while (*nextPtr != '\0')   // execute loop until nextPtr points to a null terminator
      {
         int compareResult = compare_NumeralA_to_NumeralB(ptr, nextPtr);   // compare the size of the numerals pointed to by ptr and ptr2

         if (compareResult == 2)   // if *ptr is smaller than *nextPtr then insert *ptr into
         {                         // the result string and step up the insert position and both pointers
            *insertPos = *ptr;

            insertPos = insertPos + sizeof(char);
            ptr = ptr + sizeof(char);
            nextPtr = nextPtr + sizeof(char);
         }

         ptr = ptr + sizeof(char);   // step up ptr

         if (*nextPtr != '\0')   // step up nextPtr if it is NOT already pointing to null terminator
         {
            nextPtr = nextPtr + sizeof(char);
         }
      }

      *insertPos = '\0';   // insert the null terminator

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
      char *ptr = target;   // set a pointer to the character to be removed
        
      while (*ptr != '\0')   // execute loop until ptr points to a null terminator
      {
         *ptr = *(ptr + sizeof(char));  // set *ptr equal to the next char in the string

         ptr = ptr + sizeof(char);   // step up ptr 
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
      char *posPtr = pos;   // set a pointer to the beginning of the positive elements string
      char *negPtr = neg;   // set a pointer to the beginning of the negative elements string

      while (*posPtr != '\0')   // execute outer loop until posPt points to a null terminator
      {
         while (*negPtr != '\0')   // execute inner loop until negPtr points to a null terminator
         {
            if (*posPtr == *negPtr)              // if a char in the pos string matches a char in the neg string
            {                                    // then remove both chars from their strings and set negPtr to
               removeNumeralFromString(posPtr);  // point to the beginning of the neg string
               removeNumeralFromString(negPtr); 
               negPtr = neg;
            }

            else
            {
               negPtr = negPtr + sizeof(char);   // else if the chars do not match then step up the negPtr
            }
         }
         
         negPtr = neg;          // if the inner loop is exited then set negPtr to point to the beginning of the neg string
   
	 if (*posPtr != '\0')   // if there are still more chars in the pos string step up the posPtr
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
      char *insertPos = target;   // set a pointer to the beginning of the target string 

      while (*insertPos != '\0')  // walk the pointer down the string until it points to a null terminator
      {
         insertPos = insertPos + sizeof(char);
 
      }

      *insertPos = *source;                 // insert the new char where the null terminator was
      *(insertPos + sizeof(char)) = '\0';   // insert a new null terminator after the new char
   }

   //////////////////////////////////////////////////////////////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////             

                      // Use the -DRUN_TESTS compiler flag 
   #ifdef RUN_TESTS   // if you want to compile the program
                      // with the tests used during TDD


   /*************** Function: addNumerals *************************

       Input: char *a, char*b -> point to the heads of the strings
                                 to be added

      Output: char *result   ->    pointer to "sum" string

     Purpose: Produces string by adding two input strings
   ***************************************************************/
   char *addNumerals(char *a, char *b)
   {
      char *posa = extractPositiveElements(a);   // Extract the positive and negative elements of both inputs
      char *posb = extractPositiveElements(b);   //
      char *nega = extractNegativeElements(a);   //
      char *negb = extractNegativeElements(b);   //

      char *pos = combine(posa, posb);   // combine positive elements of both inputs into one string
      char *neg = combine(nega, negb);   // combine negative elements of both inputs into one string
      
      cancelNumerals(pos, neg);   // remove matching pairs of numerals from the positive and negative strings

      char *intm = malloc(STRING_SIZE);   // allocate memory for the intermediate result string

      char *ptr = pos;   // set a pointer to the beginning of the pos string
    
      while (*ptr != '\0')          // execute loop until ptr points to a null terminator
      {                             //
         concatNumeral(ptr, intm);  // loop fills the intermediate result string with the contents of pos  
         ptr = ptr + sizeof(char);  //
      }

      char *pos2 = extractPositiveElements(intm);   // extract the positive and negative elements of the intermediate result
      char *neg2 = extractNegativeElements(intm);   //
      neg = combine(neg, neg2);                     // combine the new negatives with the old negatives

      cancelNumerals(pos2, neg);   // cancel matching pairs of numerals

      ptr = pos2;   // set ptr to point to the beginning of pos2

      *intm = '\0';   // clear the intermediate result
      
      while (*ptr != '\0')          // execute loop until ptr points to a null terminator
      {                             //
         concatNumeral(ptr, intm);  // loop fills intermediate result with the new positives
         ptr = ptr + sizeof(char);  //
      }

      detectAndCorrectDoubleNegatives(intm, neg);  // if any numerals are duplicated in the negative string they need to be replaced
      insertNegatives(intm, neg);                  // insert negatives into the intermediate string

      countAndCorrectForOnesRule(intm);   //
      countAndCorrectForVsRule(intm);     //
      countAndCorrectForXsRule(intm);     // These functions handle the detection and correction of rules concerning
      countAndCorrectForLsRule(intm);     // consecutively repeating numerals
      countAndCorrectForCsRule(intm);     //
      countAndCorrectForDsRule(intm);     //  

      pos2 = extractPositiveElements(intm);   //  extract positive and negative elements of the intermediate result
      neg2 = extractNegativeElements(intm);   //

      cancelNumerals(pos2, neg2);   // cancel matching pairs of positive and negative numerals

      ptr = pos2;   // set ptr to point to the new positive elements string

      *intm = '\0';   // clear the intermediate results string

      while (*ptr != '\0')          //   execute loop until ptr points to a null terminator
      {                             //
         concatNumeral(ptr, intm);  //   loop fills intermediate result string with the 
         ptr = ptr + sizeof(char);  //   contents of the positives string
      }

      detectAndCorrectDoubleNegatives(intm, neg2);   // if any numerals are duplicated in the negative string they need to be replaced
      insertNegatives(intm, neg2);                   // insert negatives into the intermediate string

      resultFix(intm);   // fix the intermediate results if a negative numeral apears before a numera more than ten times its size

      free(posa);   //
      free(posb);   //  
      free(pos);    //   Free Allocated Memory
      free(nega);   //
      free(negb);   //
      free(neg);    //
      
      return intm;  // return the intermediate result string as the final result (to be assessed by the tests)
   }

   #else   // If RUN_TESTS is not defined this version of addNumerals is compiled instead of the above
   

   /*************** Function: addNumerals *************************

       Input: char *a, char*b -> point to the heads of the strings
                                 to be added

      Output: char *result   ->    pointer to "sum" string

     Purpose: Produces string by adding two input strings
   ***************************************************************/
   char addNumerals(char *a, char *b, char *result)
   {
      char *ptr = a;                                    //
      while (*ptr != '\0')                              //
      {                                                 //
         if(!checkForProperInputChar(ptr)) return 'I';  //
         ptr = ptr + sizeof(char);                      //  If an input is invalid then return 'I' immediately
      }                                                 //
                                                        //
      ptr = b;                                          //
      while (*ptr != '\0')                              //
      {                                                 //
         if(!checkForProperInputChar(ptr)) return 'I';  //
         ptr = ptr + sizeof(char);                      //
      }                                                 //


      char *posa = extractPositiveElements(a);   //  extract positive and negative elements of both inputs
      char *posb = extractPositiveElements(b);   //
      char *nega = extractNegativeElements(a);   //
      char *negb = extractNegativeElements(b);   //

      char *pos = combine(posa, posb);   // combine positive and negative elements into two strings
      char *neg = combine(nega, negb);   //

      cancelNumerals(pos, neg);   // cancel matching pairs of positives and negatives

      char *intm = malloc(STRING_SIZE);   // allocate memory for the intermediate result

      ptr = pos;   // set ptr to point to the beginning of the positive string

      while (*ptr != '\0')          // loop executes until ptr points a null terminator
      {                             //
         concatNumeral(ptr, intm);  // loop fills intermediate result with positive elements
         ptr = ptr + sizeof(char);  //
      }

      char *pos2 = extractPositiveElements(intm);  //
      char *neg2 = extractNegativeElements(intm);  //
      neg = combine(neg, neg2);                    //

      cancelNumerals(pos2, neg);

      ptr = pos2;                                  //  ABOVE STEPS REPEATED

      *intm = '\0';

      while (*ptr != '\0')                         //
      {                                            //
         concatNumeral(ptr, intm);                 //
         ptr = ptr + sizeof(char);                 //
      }                                            //

      detectAndCorrectDoubleNegatives(intm, neg);   // replace double negatives
      insertNegatives(intm, neg);                   // put negatives into intermediate result

      countAndCorrectForOnesRule(intm);   //
      countAndCorrectForVsRule(intm);     //
      countAndCorrectForXsRule(intm);     //   The functions handle rules concerning consecutively
      countAndCorrectForLsRule(intm);     //   repeating numerals
      countAndCorrectForCsRule(intm);     //
      countAndCorrectForDsRule(intm);     //

      pos2 = extractPositiveElements(intm);   //
      neg2 = extractNegativeElements(intm);   //
                                              //
      cancelNumerals(pos2, neg2);        

      ptr = pos2;
                                              // ANOTHER ROUND OF POS/NEG CANCELLING
      *intm = '\0';

      while (*ptr != '\0')               
      {                                       //
         concatNumeral(ptr, intm);            //
         ptr = ptr + sizeof(char);            //
      }

      detectAndCorrectDoubleNegatives(intm, neg2);  // replace double negatives
      insertNegatives(intm, neg2);                  // put negatives into intermediate result

      resultFix(intm);   // fix result if a negative numeral directly precedes a numeral more than ten times its size

      ptr = intm;                        //
      *result = '\0';                    //

      while (*ptr != '\0')               // REFILL INTM
      {
         concatNumeral(ptr, result);
         ptr = ptr + sizeof(char);       //
      }

      free(posa);   //
      free(posb);   //
      free(pos);
      free(nega);   // FREE ALLOCATED MEMORY
      free(negb);
      free(neg);    //
      free(intm);   //

      if (detectOverflow(result))        // 
      {                                  //
         char *max = "MMMCMXCIX";        //
         *result = '\0';
         
         ptr = &max[0];

         while (*ptr != '\0')            // If the result is too large then make the result the maximum value and return 'X'
         {
            concatNumeral(ptr, result);
            ptr = ptr + sizeof(char);
         }
                                        //
         return 'X';                    //
      }                                 //

      return 'C'; // return 'C' if result has no special flag
   }

   #endif  // RUN_TESTS

   //////////////////////////////////////////////////////////////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////
   


 
  
   //////////////////////////////////////////////////////////////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////             

                      // Use the -DRUN_TESTS compiler flag 
   #ifdef RUN_TESTS   // if you want to compile the program
                      // with the tests used during TDD  
   

   /*************** Function: subtractNumerals ********************

       Input: char *a, char*b -> point to the heads of the strings
                                 to be added

      Output: char *result   ->    pointer to "difference" string

     Purpose: Produces string by subtracting an input string from
              another.
   ***************************************************************/   
   char *subtractNumerals(char *a, char *b)
   {
      char *pos = combine(extractPositiveElements(a), extractNegativeElements(b));  // extract positive and negative elements
      char *neg = combine(extractNegativeElements(a), extractPositiveElements(b));  //

      cancelNumerals(pos, neg);  // cancel positive and negative matching pairs
     
      borrowCancel(pos, neg);    // borrow from larger numerals if necessary

      char *empty = "";   // empty string
       
      return addNumerals(pos, empty);   // use addNumerals to recreate a proper roman numeral
   }

   #else // If RUN_TESTS is not defined this version of addNumerals is compiled instead of the above

   char subtractNumerals(char *a, char *b, char *result)
   {
      char returnChar = 'C';  // default return character is 'C'

      char *ptr = a;                                        //
      while (*ptr != '\0')                                  //
      {                                                     //
         if(!checkForProperInputChar(ptr)) return 'I';
         ptr = ptr + sizeof(char);
      }
                                                            // RETURN 'I' IMMEDIATELY IF INVALID INPUT
      ptr = b;
      while (*ptr != '\0')
      {
         if(!checkForProperInputChar(ptr)) return 'I';      //
         ptr = ptr + sizeof(char);                          //
      }                                                     //

      if (detectLargerSubtrahend(a, b))   //
      {                                   //
         char *swp = a;           
         a = b;
         b = swp;                         // If the subtrahend is larger than swap A and B and set the return char to V

         returnChar = 'V';
      }                                   //

      char *pos = combine(extractPositiveElements(a), extractNegativeElements(b)); // extract the positive and negative elements
      char *neg = combine(extractNegativeElements(a), extractPositiveElements(b)); //

      cancelNumerals(pos, neg);  // cancel matching pairs of positive and negative elements

      borrowCancel(pos, neg);  // borrow from larger numerals if necessary

      char *empty = "";   // empty string
      
      addNumerals(pos, empty, result);  // use addNumerals to recreate a proper numeral

      return returnChar;
   }

   #endif   // RUN_TESTS

   //////////////////////////////////////////////////////////////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////
   
   /*************** Function: borrowCancel ********************

       Input: char *pos, char *neg -> pos points to the positive
              elements of the numerals and neg points to the 
              negative.

      Output: none

     Purpose: Recursive function which borrows from larger
              numerals to allow for cancellation of smaller pos
              and neg numerals. Calls itself recursively until
              neg is an empty string.
   ***************************************************************/
   void borrowCancel(char *pos, char *neg)
   {
     
      if (*neg == '\0') return;   // return immediately if there is no negative element

      char *ptr = pos;            // set a pointer to the beginning of the positive elements
      if (*ptr == '\0') return;   // return immediately if there is no positive element

      while (*(ptr + sizeof(char)) != '\0') // walk ptr to the end of the positive elements
      {
         ptr = ptr + sizeof(char);
      }

      while (ptr != (pos - sizeof(char)))                  // loop executes until ptr has travelled past the front of pos
      {
         if (compare_NumeralA_to_NumeralB(ptr, neg) == 1)  //
         {
            breakup(ptr, neg);                             // if the current positive element is bigger than the negative element
                                                           // then breakup the larger positive element and exit the while loop
            ptr = pos - sizeof(char);                      //
         }

         else
         {
            ptr = ptr - sizeof(char);
         }
      }

      cancelNumerals(pos, neg);  // cancel pos and neg

      borrowCancel(pos, neg);    // calls itself recursively
   }

   /*************** Function: breakup ****************************

       Input: char *big, char *small -> big points to character to
               breakup, small points to character that is the 
              smallest size *big needs to be broken up into.

      Output: none

     Purpose: Breaks up *big into smaller numerals including the
              numeral *small.
   ***************************************************************/
   void breakup(char *big, char *small)
   {
      static char *vi = "IIIII";                     //
      static char *xi = "IIIIIV";
      static char *xv = "VV";
      static char *li = "IIIIIVXXXX";
      static char *lv = "VVXXXX";
      static char *lx = "XXXXX";
      static char *ci = "IIIIIVXXXXL";
      static char *cv = "VVXXXXL";
      static char *cx = "XXXXXL";                    // REPLACEMENT STRINGS (xy - x=pos, y=neg)
      static char *cl = "LL";
      static char *di = "IIIIIVXXXXLCCCC";
      static char *dv = "VVXXXXLCCCC";
      static char *dx = "XXXXXLCCCC";
      static char *dl = "LLCCCC";
      static char *dc = "CCCCC";
      static char *mi = "IIIIIXXXXLCCCCD";
      static char *mv = "VVXXXXLCCCCD";
      static char *mx = "XXXXXLCCCCD";
      static char *ml = "LLCCCCD";
      static char *mc = "CCCCCD";
      static char *md = "DD";
      static char *empty = "";                      //

      char *replacement;

      switch (*big)   // switch on the larger positive char to set the proper replacement string
      {
         case 'V':
                   replacement = &vi[0];
                   break;

         case 'X':
                        if (*small == 'I') replacement = &xi[0];
                   else if (*small == 'V') replacement = &xv[0];
                   break;

         case 'L':
                        if (*small == 'I') replacement = &li[0];
                   else if (*small == 'V') replacement = &lv[0];
                   else if (*small == 'X') replacement = &lx[0];
                   break;

         case 'C':
                        if (*small == 'I') replacement = &ci[0];
                   else if (*small == 'V') replacement = &cv[0];
                   else if (*small == 'X') replacement = &cx[0];
                   else if (*small == 'L') replacement = &cl[0];
                   break;

         case 'D':
                        if (*small == 'I') replacement = &di[0];
                   else if (*small == 'V') replacement = &dv[0];
                   else if (*small == 'X') replacement = &dx[0];
                   else if (*small == 'L') replacement = &dl[0];
                   else if (*small == 'C') replacement = &dc[0];
                   break;
  
         case 'M':
                        if (*small == 'I') replacement = &mi[0];
                   else if (*small == 'V') replacement = &mv[0];
                   else if (*small == 'X') replacement = &mx[0];
                   else if (*small == 'L') replacement = &ml[0];
                   else if (*small == 'C') replacement = &mc[0];
                   else if (*small == 'D') replacement = &md[0];
                   break;

          default:
                   replacement = &empty[0];  
                   break;
       }

       removeNumeralFromString(big);   // remove the larger positive numeral

       while (*replacement != '\0')    // make the replacement
       {
          insertNumeral(replacement, big);
          replacement = replacement + sizeof(char);
       }
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

      while(*ptr != '\0')   // loop executes until ptr points to a null terminator
      {
         if (*ptr == 'I')   // if *ptr is an I then set armed
         {
            armed = true;
            ptr2 = ptr;
            i = 0;
            while (i < 3)   // loop checks if the next three chars are also I's
            {
               ptr2 = ptr2 + sizeof(char);

               if (*ptr2 != 'I')
               {
                  armed = false;  // if a char is not an I then unset armed 
                  ptr = ptr2;
                  i = 3;          // exit the loop
               }

               i++;
            }

            if (armed)   // if armed is set then make the replacment
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
      // same as ones above
     
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
      // like ones above but searches for just more than one in a row
 
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
      // like Vs above      

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
      // like ones above
    
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
      // like Vs above   
  
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
      char *ptr = target; // set a pointer to the target location

      while (*ptr != '\0')          // walk ptr to the end of the target string 
      {
         ptr = ptr + sizeof(char);
      }

      while (ptr != (target - sizeof(char)))  // loop executes until ptr has traveled back through the target location
      {
         *(ptr + sizeof(char)) = *ptr;        // push everything right to make room for the source char
         
         ptr = ptr - sizeof(char);
      }

      *target = *source;   // insert the source char
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
      
      while (*ptr != '\0')  // iterate through result string
      {
         if (*ptr == 'I')   // if *ptr is I check to see if the next char breaks the rule
         {                  // if it does then create a replacement string depending on
                            // the characters involved (reapeated for other chars below)
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

         if (armed)  // enter this loop if a rule was broken
         {
            armed = false;

            removeNumeralFromString(ptr);  // remove both the offending chars
            removeNumeralFromString(ptr);

            char *ptr2 = replacement;
            while (*ptr2 != '\0')          // make the replacment
            {
               insertNumeral(ptr2, ptr);   //
               
               ptr = ptr + sizeof(char);
               ptr2 = ptr2 + sizeof(char); //
            }
         }

         else
         {
            ptr = ptr + sizeof(char);
         }
  
         nxt = ptr + sizeof(char);

         *replacement = '\0';
      }

      free(replacement);  // free allocated memory
   }

   /*************** Function: combine *******************************

       Input: char *a, char *b -> pointers to strings to combine 

      Output: char *result -> the new combined string

     Purpose: combines two numeral strings in descending order
   *****************************************************************/
   char *combine(char *a, char *b)
   {
      char *ptra = a;   // set pointers to the input strings
      char *ptrb = b;   //
      char *result = malloc(STRING_SIZE);  // allocate memory for the result
            *result = '\0';

      while (*ptra != '\0' || *ptrb != '\0') // loop executes while either input still has new chars
      {
         int compare = compare_NumeralA_to_NumeralB(ptra, ptrb); // compare sizes

         if (compare == 1 || *ptrb == '\0') // if a is bigger or the only one left insert a
         {
            concatNumeral(ptra, result);
            ptra = ptra + sizeof(char);
         }

         else if (compare == 2 || *ptra == '\0') // if a is smaller or there is only b left insert b 
         {
            concatNumeral(ptrb, result);
            ptrb = ptrb + sizeof(char);
         }

         else  // if they are equal then insert them both
         {
            concatNumeral(ptra, result);
            concatNumeral(ptrb, result);
            ptra = ptra + sizeof(char);
            ptrb = ptrb + sizeof(char);
         }
      }

      return result;
   }

   /********** Function: detectAndCorrectDoubleNegatives ***********

       Input: char *result, char *neg -> result points to the result
                                         string and neg points to 
                                         the negative elements 

      Output: none

     Purpose: fixes the case where a numeral appears as a negative 
              more than once
   *****************************************************************/
   void detectAndCorrectDoubleNegatives(char *result, char *neg)
   {
      bool armed = false; // default do nothing

      char *ptr = neg;          //  set a pointer to neg and immediately return if null terminator
      if (*ptr == '\0') return; //

      char *ptr2 = ptr + sizeof(char); // set a pointer to the char after *ptr
      char *ptr3 = result;  // set a pointer to the result string
      char *head = ptr3;    // set a pointer to the head of the result string

      while (*ptr2 != '\0') // loop executes until ptr2 points to a null terminator
      {  
         ptr3 = result; // reset pt3 to head

         while (*ptr3 != '\0')          // walk ptr3 to the end
         {
            ptr3 = ptr3 + sizeof(char);
         }

            if (*ptr == *ptr2)                // if two numerals match then remove them ans set armed
            {
               char offender = *ptr;  // record which numeral broke the rule
               removeNumeralFromString(ptr);
               removeNumeralFromString(ptr);
               armed = true;

               while (ptr3 != (head - sizeof(char)) && armed) // this loop executes if armed is set and until ptr3 has traveled the whole string
               {
                  if (*ptr3 == 'V' && offender == 'I')        // The function of this loop is to detect what replacemnt needs to be made and to
                  {                                           // make the replacement
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

   /********************** Function: insertNegatives ****************

       Input: char *result, char *neg -> result points to the result
                                         string and neg points to 
                                         the negative elements 

      Output: none

     Purpose: inserts negative elements into result at the proper
              locations
   *****************************************************************/
   void insertNegatives(char *result, char *neg)
   {
      char *ptr = neg;           // set a pointer to neg and return immediately if null terminator
      if (*ptr == '\0') return;  //

      char *head = ptr;     // set a pointer to the head of neg
      char *ptr2 = result;  // set a pointer to the result string

      while (*ptr2 != '\0')   // walk ptr2 to the end of result
      {
         ptr2 = ptr2 + sizeof(char);
      }

      while (*ptr != '\0')  // walk ptr to the end of neg
      {
         ptr = ptr + sizeof(char);
      }

      ptr = ptr - sizeof(char); // step back ptr

      while (ptr != (head - sizeof(char)))  // this loop executes until ptr has traversed all of neg
      {
         if (compare_NumeralA_to_NumeralB(ptr, ptr2) == 2)  // if the negative cahr is smaller than the result char then insert the neg into result
         {
            insertNumeral(ptr, ptr2);
            ptr = ptr - sizeof(char);
            ptr2 = ptr2 + sizeof(char);
         }

         if (compare_NumeralA_to_NumeralB(ptr, ptr2) == 0) // if it is equal then move the neg ptr (this should not occur)
         {
            ptr = ptr - sizeof(char);
         }
        
         ptr2 = ptr2 - sizeof(char);
      }
   }

   /**************** Function: detectOverflow ***********************

       Input: char *input -> points to the result string to be 
                             tested for over flow 

      Output: bool: true = overflow, false = no overflow

     Purpose: detects if result > MMMCMXCIX
   *****************************************************************/
   bool detectOverflow(char *input)
   {
      int trigger = 4;  // countdown trigger
      char *ptr = input; // points to the input string

      while (*ptr == 'M')  // loop executes while *ptr == M
      {
         trigger--;
         ptr = ptr + sizeof(char);
      }
      
      if (trigger <= 0) return true;   // signifies overflow, return true

      return false;   // else return false
   }

   /********* Function: detectLargerSubtrahend **********************

       Input: char *a, char *b -> a points to the minuend and b 
                                  points to the subtrahend

      Output: bool: true = larger subtrahend, false = lesser or equal

     Purpose: detects if subtrahend > minuend
   *****************************************************************/
   bool detectLargerSubtrahend(char *a, char *b)
   {
      char *ptr = a;  // set pointers to input strings
      char *ptr2 = b;

      while (*ptr != '\0' && *ptr2 != '\0')  // loop iterates while both pointers have not reached null terminator
      {
         if (compare_NumeralA_to_NumeralB(ptr, ptr2) == 2)   // if a < b
         {
            if (*(ptr + sizeof(char)) == '\0') return true;   // if a+1 == '\0' return true
            else if (compare_NumeralA_to_NumeralB(ptr + sizeof(char), ptr2) == 1) return false; // if a+1 > b return false
            else return true; 
         }

         else if (compare_NumeralA_to_NumeralB(ptr, ptr2) == 1)   // if a > b
         {
            if (*(ptr2 + sizeof(char)) == '\0') return false;   // if b+1 == '\0' return false
            else if (compare_NumeralA_to_NumeralB(ptr, ptr2 + sizeof(char)) == 2) return true;   // if a < b+1 return true
            else return false;
         }

         ptr = ptr + sizeof(char);
         ptr2 = ptr2 + sizeof(char);
      }

      if (*ptr == '\0' && *ptr2 != '\0') return true; // if they were equal up until exiting then return true if b is longer

      return false;
   }

   
