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
