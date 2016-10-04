   /* FILE: RomanNumeralCalculator_TB.c
      AUTHOR: Jackson Ward

      DESCRIPTION: Source code file containing definitions and execution of
                   RomanNumeralCalculator tests.

      CREATED ON: 10/3/2016
   */

   #include <assert.h> // import for use of assert();
   #include <stdio.h>  // import for use of printf();
   #include "RomanNumeralCalculator_TB.h"
   #include "RomanNumeralCalculator.h"

   int main()
   {
      assertDetectionOfProperNumeralInput(); // run Test 1
      assertCorrectResultWhenComparingTheSizeOf2CharacterNumerals(); // run Test 2

      printf("All tests passed succesfully!\n"); // All tests succesful - message

      return 0; // exit success
   }
   
   /******** Function: assertDetectionOfProperInputChar **********
       Input: none
       Output: none
       Description: For chars I, V, X, L, C, D, and M :
                    asserts that function 'checkForProperInputChar'
                    returns true.

                    For char Z (an example of invalid input) :
                    asserts that function 'checkForProperInputChar'
                    returns false.
   ****************************************************************/
   void assertDetectionOfProperNumeralInput()
   {
      char input = 'I';
      char *ptr  = &input;

      assert( checkForProperInputChar(ptr) == true );

      *ptr = 'V';
      assert( checkForProperInputChar(ptr) == true );

      *ptr = 'X';
      assert( checkForProperInputChar(ptr) == true );

      *ptr = 'L';
      assert( checkForProperInputChar(ptr) == true );

      *ptr = 'C';
      assert( checkForProperInputChar(ptr) == true );

      *ptr = 'D';
      assert( checkForProperInputChar(ptr) == true );

      *ptr = 'M';
      assert( checkForProperInputChar(ptr) == true );

      *ptr = 'Z';
      assert( checkForProperInputChar(ptr) == false );
   }
   
   /******** Function: assertCorrectResultWhenComparingTheSizeOf2CharacterNumerals **********
       Input: none
       Output: none
       Description: Assert that function 'compare_NumeralA_to_NumeralB(char *A, char *B)' 
                    returns 0 if the characters pointed to by A and B are equal, a 1 if *A
                    is bigger than *B, a 2 if *A is smaller than *B, and -1 if invalid input.

                    All possible test cases included for valid inputs, one for non-valid.
                      
   ******************************************************************************************/
   void assertCorrectResultWhenComparingTheSizeOf2CharacterNumerals()
   {

      char i = 'I';
      char v = 'V';
      char x = 'X';
      char l = 'L';
      char c = 'C';
      char d = 'D';
      char m = 'M';
      char z = 'Z';

      char *I = &i;
      char *V = &v;
      char *X = &x;
      char *L = &l;
      char *C = &c;
      char *D = &d;
      char *M = &m;
      char *Z = &z;

      assert(compare_NumeralA_to_NumeralB(I, I) ==  0);
      assert(compare_NumeralA_to_NumeralB(I, V) ==  2);
      assert(compare_NumeralA_to_NumeralB(I, X) ==  2);
      assert(compare_NumeralA_to_NumeralB(I, L) ==  2);
      assert(compare_NumeralA_to_NumeralB(I, C) ==  2);
      assert(compare_NumeralA_to_NumeralB(I, D) ==  2);
      assert(compare_NumeralA_to_NumeralB(I, M) ==  2);

      assert(compare_NumeralA_to_NumeralB(V, I) ==  1);
      assert(compare_NumeralA_to_NumeralB(V, V) ==  0);
      assert(compare_NumeralA_to_NumeralB(V, X) ==  2);
      assert(compare_NumeralA_to_NumeralB(V, L) ==  2);
      assert(compare_NumeralA_to_NumeralB(V, C) ==  2);
      assert(compare_NumeralA_to_NumeralB(V, D) ==  2);
      assert(compare_NumeralA_to_NumeralB(V, M) ==  2);

      assert(compare_NumeralA_to_NumeralB(X, I) ==  1);
      assert(compare_NumeralA_to_NumeralB(X, V) ==  1);
      assert(compare_NumeralA_to_NumeralB(X, X) ==  0);
      assert(compare_NumeralA_to_NumeralB(X, L) ==  2);
      assert(compare_NumeralA_to_NumeralB(X, C) ==  2);
      assert(compare_NumeralA_to_NumeralB(X, D) ==  2);
      assert(compare_NumeralA_to_NumeralB(X, M) ==  2);

      assert(compare_NumeralA_to_NumeralB(L, I) ==  1);
      assert(compare_NumeralA_to_NumeralB(L, V) ==  1);
      assert(compare_NumeralA_to_NumeralB(L, X) ==  1);
      assert(compare_NumeralA_to_NumeralB(L, L) ==  0);
      assert(compare_NumeralA_to_NumeralB(L, C) ==  2);
      assert(compare_NumeralA_to_NumeralB(L, D) ==  2);
      assert(compare_NumeralA_to_NumeralB(L, M) ==  2);

      assert(compare_NumeralA_to_NumeralB(C, I) ==  1);
      assert(compare_NumeralA_to_NumeralB(C, V) ==  1);
      assert(compare_NumeralA_to_NumeralB(C, X) ==  1);
      assert(compare_NumeralA_to_NumeralB(C, L) ==  1);
      assert(compare_NumeralA_to_NumeralB(C, C) ==  0);
      assert(compare_NumeralA_to_NumeralB(C, D) ==  2);
      assert(compare_NumeralA_to_NumeralB(C, M) ==  2);

      assert(compare_NumeralA_to_NumeralB(D, I) ==  1);
      assert(compare_NumeralA_to_NumeralB(D, V) ==  1);
      assert(compare_NumeralA_to_NumeralB(D, X) ==  1);
      assert(compare_NumeralA_to_NumeralB(D, L) ==  1);
      assert(compare_NumeralA_to_NumeralB(D, C) ==  1);
      assert(compare_NumeralA_to_NumeralB(D, D) ==  0);
      assert(compare_NumeralA_to_NumeralB(D, M) ==  2);

      assert(compare_NumeralA_to_NumeralB(M, I) ==  1);
      assert(compare_NumeralA_to_NumeralB(M, V) ==  1);
      assert(compare_NumeralA_to_NumeralB(M, X) ==  1);
      assert(compare_NumeralA_to_NumeralB(M, L) ==  1);
      assert(compare_NumeralA_to_NumeralB(M, C) ==  1);
      assert(compare_NumeralA_to_NumeralB(M, D) ==  1);
      assert(compare_NumeralA_to_NumeralB(M, M) ==  0);

      assert(compare_NumeralA_to_NumeralB(I, Z) == -1);
   }