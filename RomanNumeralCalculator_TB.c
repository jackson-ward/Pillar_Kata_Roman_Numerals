   /* FILE: RomanNumeralCalculator_TB.c
      AUTHOR: Jackson Ward

      DESCRIPTION: Source code file containing definitions and execution of
                   RomanNumeralCalculator tests.

      CREATED ON: 10/3/2016
   */

   #include <assert.h> // import for use of assert();
   #include <stdio.h>  // import for use of printf();
   #include <stdlib.h>
   #include "RomanNumeralCalculator_TB.h"
   #include "RomanNumeralCalculator.h"

   int main()
   {
      assertDetectionOfProperNumeralInput(); // run Test 1
      assertCorrectResultWhenComparingTheSizeOf2CharacterNumerals(); // run Test 2
      assertStringNumeralPositveElementsAreCategorizedCorrectly(); // run test 3
      assertStringNumeralPositiveElementsAreCategorizedCorrectlySpecialCases(); // run test 4
      assertStringNumeralPositiveElementsAreCategorizedCorrectlyGeneralSize(); // run test 5
      assertStringNumeralNegativeElementsAreCategorizedCorrectly(); // run test 6
      assertStringNumeralNegativeElementsAreCategorizedCorrectlySpecialCases(); // run test 7
      assertStringNumeralNegativeElementsAreCategorizedCorrectlyGeneralSize(); // run test 8
      assertCharacterRemovedFromStringProperly(); // run test 9
      assertPositivesAndNegativesCancelForAddition(); // run test 10
      assertProperConcatenationOfNumeralToEmptyString(); // run test 11
      assertProperConcatenationIntoNonEmptyString(); // run test 12
      assert_IplusI_Equals_II(); // run Add Test 1 (test 13)
      assert_IplusII_Equals_III(); // run Add Test 2 (test 14)
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
   
   /******** Function: assertStringNumeralPositveElementsAreCategorizedCorrectly **********
       Input: none
       Output: none
       Description: Assert that function 'extractPositiveElements' returns "CLV" when 
                    "CXLIV" is given as input.
                      
   ******************************************************************************************/
   void assertStringNumeralPositveElementsAreCategorizedCorrectly()
   {
      char input[6] = {'C', 'X', 'L', 'I', 'V', '\0'};

      char *ptr;

      ptr = extractPositiveElements(input);

      assert(*ptr     == 'C');
      assert(*(ptr + sizeof(char)) == 'L');
      assert(*(ptr + sizeof(char) * 2) == 'V');

      free(ptr);  
   }
   
   /******** Function: assertStringNumeralPositveElementsAreCategorizedCorrectlySpecialCases **********
       Input: none
       Output: none
       Description: Assert that function 'extractPositiveElements' returns "\0" when input is "\0"
                    and "X" when input is "X\0"
                      
   ******************************************************************************************/
   void assertStringNumeralPositiveElementsAreCategorizedCorrectlySpecialCases()
   {
      char input1[1] = {'\0'};
      char input2[2] = {'X', '\0'};

      char *ptr;

      ptr = extractPositiveElements(input1);
      assert(*ptr == '\0');
      free(ptr);

      ptr = extractPositiveElements(input2);
      assert(*ptr == 'X');
      assert(*(ptr + sizeof(char)) == '\0');
      free(ptr);
   }
   
   /******** Function: assertStringNumeralPositiveElementsAreCategorizedCorrectlyGeneralSize **********
       Input: none
       Output: none
       Description: Assert that function 'extractPositiveElements' returns correct results for 
                    arbitraily sized input. 

                    Testing Inputs: "XX\0" and "MMMCMXCIX\0"
                      
   ****************************************************************************************************/
   void assertStringNumeralPositiveElementsAreCategorizedCorrectlyGeneralSize()
   {
      char input1[3] = {'X', 'X', '\0'};
      char input2[10] = {'M', 'M', 'M', 'C', 'M', 'X', 'C', 'I', 'X', '\0'};
      
      char *ptr;

      ptr = extractPositiveElements(input1);
      assert(*ptr == 'X');
      assert(*(ptr + sizeof(char)) == 'X');
      assert(*(ptr + sizeof(char) * 2) == '\0');
      free(ptr);

      ptr = extractPositiveElements(input2);
      assert(*ptr == 'M');
      assert(*(ptr + sizeof(char)) == 'M');
      assert(*(ptr + sizeof(char) * 2) == 'M');
      assert(*(ptr + sizeof(char) * 3) == 'M');
      assert(*(ptr + sizeof(char) * 4) == 'C');
      assert(*(ptr + sizeof(char) * 5) == 'X');
      assert(*(ptr + sizeof(char) * 6) == '\0');
      free(ptr);
   }

   /******** Function: assertStringNumeralNegativeElementsAreCategorizedCorrectly **********
       Input: none
       Output: none
       Description: Assert that function 'extractNegativeElements' returns "XI\0" when 
                    "CXLIV\0" is given as input.
                      
   ******************************************************************************************/
   void assertStringNumeralNegativeElementsAreCategorizedCorrectly()
   {
      char input[6] = {'C', 'X', 'L', 'I', 'V', '\0'};

      char *ptr;

      ptr = extractNegativeElements(input);

      assert(*ptr     == 'X');
      assert(*(ptr + sizeof(char)) == 'I');
      assert(*(ptr + sizeof(char) * 2) == '\0');

      free(ptr);
   }

    /******** Function: assertStringNumeralNegativeElementsAreCategorizedCorrectlySpecialCases **********
       Input: none
       Output: none
       Description: Assert that function 'extractNegativeElements' returns "\0" when input is "\0",
                    "\0" when input is "X\0", and "I\0" when input is "IX\0"
                      
   ******************************************************************************************/
   void assertStringNumeralNegativeElementsAreCategorizedCorrectlySpecialCases()
   {
      char input1[1] = {'\0'};
      char input2[2] = {'X', '\0'};
      char input3[3] = {'I', 'X', '\0'};

      char *ptr;

      ptr = extractNegativeElements(input1);
      assert(*ptr == '\0');
      free(ptr);

      ptr = extractNegativeElements(input2);
      assert(*ptr == '\0');
      free(ptr);

      ptr = extractNegativeElements(input3);
      assert(*ptr == 'I');
      assert(*(ptr + sizeof(char)) == '\0');
      free(ptr);
   }
    
   /******** Function: assertStringNumeralNegativeElementsAreCategorizedCorrectlyGeneralSize **********
       Input: none
       Output: none
       Description: Assert that function 'extractNegativeElements' returns correct results for 
                    arbitraily sized input. 

                    Testing Inputs: "IX\0" and "MMMCMXCIX\0"
                      
   ****************************************************************************************************/
   void assertStringNumeralNegativeElementsAreCategorizedCorrectlyGeneralSize()
   {
      char input1[3] = {'I', 'X', '\0'};
      char input2[10] = {'M', 'M', 'M', 'C', 'M', 'X', 'C', 'I', 'X', '\0'};

      char *ptr;

      ptr = extractNegativeElements(input1);
      assert(*ptr == 'I');
      assert(*(ptr + sizeof(char)) == '\0');
      free(ptr);

      ptr = extractNegativeElements(input2);
      assert(*ptr == 'C');
      assert(*(ptr + sizeof(char)) == 'X');
      assert(*(ptr + sizeof(char) * 2) == 'I');
      assert(*(ptr + sizeof(char) * 3) == '\0');
      free(ptr);
   }

   /******** Function: assertCharacterRemovedFromStringProperly **********
       Input: none
       Output: none
       Description: Assert that function 'removeNumeralFromString'
                    transforms 'XIX\0' into 'XX\0' when given a
                    pointer to 'I' as input. 
              
   ***********************************************************************/
   void assertCharacterRemovedFromStringProperly()
   {
      char input[4] = {'X', 'I', 'X', '\0'};
      
      char *ptr = &input[1];

      removeNumeralFromString(ptr);

      ptr = input;

      assert(*ptr == 'X');
      assert(*(ptr + sizeof(char)) == 'X');
      assert(*(ptr + sizeof(char) * 2) == '\0');  
   }

   /******** Function: assertPositivesAndNegativesCancelForAddition **********
       Input: none
       Output: none
       Description: Assert that function cancelNumerals removes
                    numerals that appear in both the positive and negative
                    strings. 
              
   ***************************************************************************/
   void assertPositivesAndNegativesCancelForAddition()
   {
      char input1[3] = {'I', 'X', '\0'};
      char input2[2] = {'I', '\0'};

      char *posPtr = input1;
      char *negPtr = input2;

      cancelNumerals(posPtr, negPtr);

      assert(*posPtr == 'X');
      assert(*(posPtr + sizeof(char)) == '\0');
      assert(*negPtr == '\0');
   }  

   /******** Function: assertProperConcatenationOfNumeralToEmptyString **********
       Input: none
       Output: none
       Description: Assert that function concatNumeral adds a numeral to the
                    end of an empty string properly 
              
   ***************************************************************************/
   void assertProperConcatenationOfNumeralToEmptyString()
   {
      char input1[1] = {'\0'};
      char input2[1] = {'I'};

      char *target = malloc(STRING_SIZE);
      char *source = input2;

      target = input1;

      target = concatNumeral(source, target);

      assert(*target == 'I');
      assert(*(target + sizeof(char)) == '\0');

      free(target);
   }
   
   /******** Function: assertProperConcatenationIntoNonEmptyString **********
       Input: none
       Output: none
       Description: Assert that function concatNumeral adds a numeral to the
                    end of a string properly 
              
   **********************************************************************************/
   void assertProperConcatenationIntoNonEmptyString()
   {
      char input1[2] = {'X', '\0'};
      char input2[1] = {'I'};

      char *target = malloc(STRING_SIZE);
      char *source = input2;

      target = input1;

      target = concatNumeral(source, target);

      assert(*target == 'X');
      assert(*(target + sizeof(char)) == 'I');
      assert(*(target + sizeof(char) * 2) == '\0');

      free(target);
   }

   /*************** Function: assert_I+I_Equals_II *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('I', 'I') returns
                    II.
   **************************************************************/
   void assert_IplusI_Equals_II()
   {
      char input1[2] = {'I', '\0'};
      char input2[2] = {'I', '\0'};

      char *a = input1;
      char *b = input2;

      char *result = addNumerals(a, b);

      assert(*result == 'I');
      assert(*(result + sizeof(char)) == 'I');
      assert(*(result + sizeof(char) * 2) == '\0');

      free(result);
   }
   
   /*************** Function: assert_I+II_Equals_III *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('I', 'II') returns
                    III.
   **************************************************************/
   void assert_IplusII_Equals_III()
   {
      char input1[2] = {'I', '\0'};
      char input2[3] = {'I', 'I', '\0'};

      char *a = input1;
      char *b = input2;

      char *result = addNumerals(a, b);

      assert(*result == 'I');
      assert(*(result + sizeof(char)) == 'I');
      assert(*(result + sizeof(char) * 2) == 'I');
      assert(*(result + sizeof(char) * 3) == '\0');

      free(result);
   } 

