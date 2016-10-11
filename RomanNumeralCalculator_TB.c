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
      assert_IplusIII_Equals_IV(); // run Add Test 3 (test 15)
      assert_IplusV_Equals_VI(); // run Add Test 4 (test 16)
      assert_IplusIV_Equals_V(); // run Add Test 5 (test 17)
      assert_IVplusI_Equals_V(); // run Add Test 6 (test 18)
      assert_XplusIV_Equals_XIV(); // run Add Test 7 (test 19)
      assert_VplusV_Equals_X(); // run Add Test 8 (test 20)
      assert_XXplusXX_Equals_XL(); // run Add Test 9 (test 21)
      assert_LplusL_Equals_C(); // run Add Test 10 (test 22)
      assert_CCplusCC_Equals_CD(); // run Add Test 11 (test 23)
      assert_DplusD_Equals_M(); // run Add Test 12 (test 24)
      assert_IVplusIV_Equals_VIII(); // run Add Test 13 (test 25)
      assert_IXplusIX_Equals_XVIII(); // run Add Test 14 (test 26)
      assert_XLplusXL_Equals_LXXX(); // run Add Test 15 (test 27)
      assert_XCplusXC_Equals_CLXXX(); // run Add Test 16 (test 28)
      assert_CDplusCD_Equals_DCCC(); // run Add Test 17 (test 29)
      assert_CMplusCM_Equals_MDCCC(); // run Add Test 18 (test 30)
      assert_IL_goes_to_XLIX(); // run Result_Fix Test 1 (test 31)
      assert_IC_goes_to_XCIX(); // run Result_Fix Test 2 (test 32)
      assert_ID_goes_to_CDXCIX(); // run Result_Fix Test 3 (test 32)
      assert_IM_goes_to_CMXCIX(); // run Result_Fix Test 4 (test 33)
      assert_XD_goes_to_CDXC(); // run Result_Fix Test 5 (test 34)
      assert_XM_goes_to_CMXC(); // run Result_Fix Test 6 (test 35)      
      assert_MCIplusMCDXXXVI_Equals_MMDXXXVII(); // run Add Test 19 (test 36)   
      assert_CDXplusCD_Equals_DCCCX(); // run Add Test 20 (test 37)
      assert_CVIplusX_Equals_CXVI(); // run Add Test 21 (test 38)
      assert_XCVIplusIV_Equals_C(); // run Add Test 22 (test 39)
      assert_LXplusXXX_Equals_XC(); // run Add Test 23 (test 40)
      assert_IIIplusIII_Equals_VI(); // run Add Test 24 (test 41)
      assert_XXXVIIIplusI_Equals_XXXIX(); // run Add Test 25 (test 42)
      assert_IIminusI_Equals_I(); // Sub Test 1 (test 43)
      assert_LminusI_Equals_XLIX(); // Sub Test 2 (test 44)
      assert_XLIXminusI_Equals_XLVIII(); // Sub Test 3 (test 45)
      assert_VminusIII_Equals_II(); // Sub Test 4 (test 46)
      assert_LminusXLV_Equals_V(); // Sub Test 5 (test 47)
      assert_CminusL_Equals_L(); // Sub Test 6 (test 48)
      assert_MminusD_Equals_D(); // Sub Test 7 (test 49)
      assert_LminusXI_Equals_XXXIX(); // Sub Test 8 (test 50)
      assert_detectOverflow_MMMM_Returns_True(); // Overflow Test 1 (test 51)

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

      *target = input1[0];

      concatNumeral(source, target);

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

      *target = input1[0];
      *(target + sizeof(char)) = input1[1];

      concatNumeral(source, target);

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
  
   /*************** Function: assert_I+III_Equals_IV *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('I', 'III') returns
                    IV.
   **************************************************************/
   void assert_IplusIII_Equals_IV()
   {
      char input1[2] = {'I', '\0'};
      char input2[4] = {'I', 'I', 'I', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'I');
      assert(*(result + sizeof(char)) == 'V');
      assert(*(result + sizeof(char) * 2) == '\0');

      free(result);
   }
   
   /*************** Function: assert_I+V_Equals_VI *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('I', 'V') returns
                    VI.
   **************************************************************/
   void assert_IplusV_Equals_VI()
   {
      char input1[2] = {'I', '\0'};
      char input2[2] = {'V', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'V');
      assert(*(result + sizeof(char)) == 'I');
      assert(*(result + sizeof(char) * 2) == '\0');

      free(result);
   }

   /*************** Function: assert_I+IV_Equals_V *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('I', 'IV') returns
                    V.
   **************************************************************/
   void assert_IplusIV_Equals_V()
   {
      char input1[2] = {'I', '\0'};
      char input2[3] = {'I', 'V', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'V');
      assert(*(result + sizeof(char)) == '\0');

      free(result);  
   }

   /*************** Function: assert_IV+I_Equals_V *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('IV', 'I') returns
                    V.
   **************************************************************/
   void assert_IVplusI_Equals_V()
   {
      char input1[3] = {'I', 'V', '\0'};
      char input2[2] = {'I', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'V');
      assert(*(result + sizeof(char)) == '\0');

      free(result);
   }

   /*************** Function: assert_XplusIV__Equals_XIV *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('IV', 'I') returns
                    V.
   **************************************************************/
   void assert_XplusIV_Equals_XIV()
   {
      char input1[2] = {'X', '\0'};
      char input2[3] = {'I', 'V', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'X');
      assert(*(result + sizeof(char)) == 'I');
      assert(*(result + sizeof(char) * 2) == 'V');
      assert(*(result + sizeof(char) * 3) == '\0');

      free(result);
   }

   /*************** Function: assert_VplusV__Equals_X *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('V', 'V') returns
                    X.
   ***************************************************************/
   void assert_VplusV_Equals_X()
   {
      char input1[2] = {'V', '\0'};
      char input2[2] = {'V', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'X');
      assert(*(result + sizeof(char)) == '\0');

      free(result);
   }
 
   /*************** Function: assert_XXplusXX_Equals_XL *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('XX', 'XX') returns
                    XL.
   ***************************************************************/
   void assert_XXplusXX_Equals_XL()
   {
      char input1[3] = {'X', 'X', '\0'};
      char input2[3] = {'X', 'X', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'X');
      assert(*(result + sizeof(char)) == 'L');
      assert(*(result + sizeof(char) * 2) == '\0');

      free(result);
   } 

   /*************** Function: assert_LplusL_Equals_C *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('L', 'L') returns
                    C.
   ***************************************************************/
   void assert_LplusL_Equals_C()
   {
      char input1[2] = {'L', '\0'};
      char input2[2] = {'L', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'C');
      assert(*(result + sizeof(char)) == '\0');

      free(result);
   }

   /*************** Function: assert_CCplusCC_Equals_CD *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('CC', 'CC') returns
                    CD.
   ***************************************************************/
   void assert_CCplusCC_Equals_CD()
   {
      char input1[3] = {'C', 'C', '\0'};
      char input2[3] = {'C', 'C', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'C');
      assert(*(result + sizeof(char)) == 'D');
      assert(*(result + sizeof(char) * 2) == '\0');

      free(result);
   }

   /*************** Function: assert_DplusD_Equals_M *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('D', 'D') returns
                    M.
   ***************************************************************/
   void assert_DplusD_Equals_M()
   {
      char input1[2] = {'D', '\0'};
      char input2[2] = {'D', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'M');
      assert(*(result + sizeof(char)) == '\0');

      free(result);
   }

   /*************** Function: assert_IVplusIV_Equals_VIII *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('IV', 'IV') returns
                    VIII.
   ***************************************************************/
   void assert_IVplusIV_Equals_VIII()
   {
      char input1[3] = {'I', 'V', '\0'};
      char input2[3] = {'I', 'V', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'V');
      assert(*(result + sizeof(char)) == 'I');
      assert(*(result + sizeof(char) * 2) == 'I');
      assert(*(result + sizeof(char) * 3) == 'I');
      assert(*(result + sizeof(char) * 4) == '\0');

      free(result);
   }

   /*************** Function: assert_IXplusIX_Equals_XVIII *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('IX', 'IX') returns
                    XVIII.
   ***************************************************************/
   void assert_IXplusIX_Equals_XVIII()
   {
      char input1[3] = {'I', 'X', '\0'};
      char input2[3] = {'I', 'X', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'X');
      assert(*(result + sizeof(char)) == 'V');
      assert(*(result + sizeof(char) * 2) == 'I');
      assert(*(result + sizeof(char) * 3) == 'I');
      assert(*(result + sizeof(char) * 4) == 'I');
      assert(*(result + sizeof(char) * 5) == '\0');

      free(result);
   }

   /*************** Function: assert_XLplusXL_Equals_LXXX *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('XL', 'XL') returns
                    LXXX.
   ***************************************************************/
   void assert_XLplusXL_Equals_LXXX()
   {
      char input1[3] = {'X', 'L', '\0'};
      char input2[3] = {'X', 'L', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'L');
      assert(*(result + sizeof(char)) == 'X');
      assert(*(result + sizeof(char) * 2) == 'X');
      assert(*(result + sizeof(char) * 3) == 'X');
      assert(*(result + sizeof(char) * 4) == '\0');

      free(result);
   }

   /*************** Function: assert_XCplusXC_Equals_CLXXX *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('XC', 'XC') returns
                    CLXXX.
   ***************************************************************/
   void assert_XCplusXC_Equals_CLXXX()
   {
      char input1[3] = {'X', 'C', '\0'};
      char input2[3] = {'X', 'C', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'C');
      assert(*(result + sizeof(char)) == 'L');
      assert(*(result + sizeof(char) * 2) == 'X');
      assert(*(result + sizeof(char) * 3) == 'X');
      assert(*(result + sizeof(char) * 4) == 'X');
      assert(*(result + sizeof(char) * 5) == '\0');

      free(result);
   }

   /*************** Function: assert_CDplusCD_Equals_DCCC *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('CD', 'CD') returns
                    DCCC.
   ***************************************************************/
   void assert_CDplusCD_Equals_DCCC()
   {
      char input1[3] = {'C', 'D', '\0'};
      char input2[3] = {'C', 'D', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'D');
      assert(*(result + sizeof(char)) == 'C');
      assert(*(result + sizeof(char) * 2) == 'C');
      assert(*(result + sizeof(char) * 3) == 'C'); 
      assert(*(result + sizeof(char) * 4) == '\0');

      free(result);
   }

   /*************** Function: assert_CMplusCM_Equals_MDCCC *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('CM', 'CM') returns
                    MDCCC.
   ***************************************************************/
   void assert_CMplusCM_Equals_MDCCC()
   {
      char input1[3] = {'C', 'M', '\0'};
      char input2[3] = {'C', 'M', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'M');
      assert(*(result + sizeof(char)) == 'D');
      assert(*(result + sizeof(char) * 2) == 'C');
      assert(*(result + sizeof(char) * 3) == 'C');
      assert(*(result + sizeof(char) * 4) == 'C');
      assert(*(result + sizeof(char) * 5) == '\0');

      free(result);
   }

   /*************** Function: assert_IL_goes_to_XLIX *************\
       Input: none
       Output: none
       Description: Assert that call resultFix('IL') returns
                    XLIX.
   ***************************************************************/
   void assert_IL_goes_to_XLIX()
   {
      char input[5] = {'I', 'L', '\0', '\0', '\0'};

      resultFix(input);

      assert(*input == 'X');
      assert(*(input + sizeof(char)) == 'L');
      assert(*(input + sizeof(char) * 2) == 'I');
      assert(*(input + sizeof(char) * 3) == 'X');   
      assert(*(input + sizeof(char) * 4) == '\0'); 
   }

   /*************** Function: assert_IC_goes_to_XCIX *************\
       Input: none
       Output: none
       Description: Assert that call resultFix('IC') returns
                    XCIX.
   ***************************************************************/
   void assert_IC_goes_to_XCIX()
   {
      char input[5] = {'I', 'C', '\0', '\0', '\0'};

      resultFix(input);

      assert(*input == 'X');
      assert(*(input + sizeof(char)) == 'C');
      assert(*(input + sizeof(char) * 2) == 'I');
      assert(*(input + sizeof(char) * 3) == 'X');
      assert(*(input + sizeof(char) * 4) == '\0');
   }

   /*************** Function: assert_ID_goes_to_CDXCIX *************\
       Input: none
       Output: none
       Description: Assert that call resultFix('ID') returns
                    CDXCIX.
   ***************************************************************/
   void assert_ID_goes_to_CDXCIX()
   {
      char input[7] = {'I', 'D', '\0', '\0', '\0', '\0', '\0'};

      resultFix(input);

      assert(*input == 'C');
      assert(*(input + sizeof(char)) == 'D');
      assert(*(input + sizeof(char) * 2) == 'X');
      assert(*(input + sizeof(char) * 3) == 'C');
      assert(*(input + sizeof(char) * 4) == 'I');
      assert(*(input + sizeof(char) * 5) == 'X');
      assert(*(input + sizeof(char) * 6) == '\0');
   }

   /*************** Function: assert_IM_goes_to_CMXCIX *************\
       Input: none
       Output: none
       Description: Assert that call resultFix('IM') returns
                    CMXCIX.
   ***************************************************************/
   void assert_IM_goes_to_CMXCIX()
   {
      char input[7] = {'I', 'M', '\0', '\0', '\0', '\0', '\0'};

      resultFix(input);

      assert(*input == 'C');
      assert(*(input + sizeof(char)) == 'M');
      assert(*(input + sizeof(char) * 2) == 'X');
      assert(*(input + sizeof(char) * 3) == 'C');
      assert(*(input + sizeof(char) * 4) == 'I');
      assert(*(input + sizeof(char) * 5) == 'X');
      assert(*(input + sizeof(char) * 6) == '\0');
   }

   /*************** Function: assert_XD_goes_to_CDXC *************\
       Input: none
       Output: none
       Description: Assert that call resultFix('XD') returns
                    CDXC.
   ***************************************************************/
   void assert_XD_goes_to_CDXC()
   {
      char input[5] = {'X', 'D', '\0', '\0', '\0'};

      resultFix(input);

      assert(*input == 'C');
      assert(*(input + sizeof(char)) == 'D');
      assert(*(input + sizeof(char) * 2) == 'X');
      assert(*(input + sizeof(char) * 3) == 'C');  
      assert(*(input + sizeof(char) * 4) == '\0');
   }

   /*************** Function: assert_XM_goes_to_CMXC *************\
       Input: none
       Output: none
       Description: Assert that call resultFix('XM') returns
                    CMXC.
   ***************************************************************/
   void assert_XM_goes_to_CMXC()
   {
      char input[5] = {'X', 'M', '\0', '\0', '\0'};

      resultFix(input);

      assert(*input == 'C');
      assert(*(input + sizeof(char)) == 'M');
      assert(*(input + sizeof(char) * 2) == 'X');
      assert(*(input + sizeof(char) * 3) == 'C');
      assert(*(input + sizeof(char) * 4) == '\0');
   }

   /*************** Function: assert_MCIplusMCDXXXVI_Equals_MMDXXXVII *************\
       Input: none
       Output: none
       Description: Assert that call addNumerals('CM', 'CM') returns
                    MDCCC.
   ***************************************************************/
   void assert_MCIplusMCDXXXVI_Equals_MMDXXXVII()
   {
      char input1[4] = {'M', 'C', 'I', '\0'};
      char input2[10] = {'M', 'C', 'D', 'X', 'X', 'X', 'V', 'I', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'M');
      assert(*(result + sizeof(char)) == 'M');
      assert(*(result + sizeof(char) * 2) == 'D');
      assert(*(result + sizeof(char) * 3) == 'X');
      assert(*(result + sizeof(char) * 4) == 'X');
      assert(*(result + sizeof(char) * 5) == 'X');
      assert(*(result + sizeof(char) * 6) == 'V');
      assert(*(result + sizeof(char) * 7) == 'I');
      assert(*(result + sizeof(char) * 8) == 'I');
      assert(*(result + sizeof(char) * 9) == '\0');

      free(result);
   }

   /*************** Function: assert_CDXplusCD_Equals_DCCCX *******
       Input: none
       Output: none
       Description: Assert that call addNumerals('CDX', 'DCCCX') returns
                    DCCCX.
   ***************************************************************/
   void assert_CDXplusCD_Equals_DCCCX()
   {
      char input1[4] = {'C', 'D', 'X', '\0'};
      char input2[10] = {'C', 'D', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'D');
      assert(*(result + sizeof(char)) == 'C');
      assert(*(result + sizeof(char) * 2) == 'C');
      assert(*(result + sizeof(char) * 3) == 'C');
      assert(*(result + sizeof(char) * 4) == 'X'); 
      assert(*(result + sizeof(char) * 5) == '\0');

      free(result);
   }

   /*************** Function: assert_CVIplusX_Equals_CXVI *******
       Input: none
       Output: none
       Description: Assert that call addNumerals('CVI', 'X') returns
                    CXVI.
   ***************************************************************/
   void assert_CVIplusX_Equals_CXVI()
   {
      char input1[4] = {'C', 'V', 'I', '\0'};
      char input2[2] = {'X', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'C');
      assert(*(result + sizeof(char)) == 'X');
      assert(*(result + sizeof(char) * 2) == 'V');
      assert(*(result + sizeof(char) * 3) == 'I');
      assert(*(result + sizeof(char) * 4) == '\0');

      free(result);
   }

   /*************** Function: assert_XCVIplusIV_Equals_C *******
       Input: none
       Output: none
       Description: Assert that call addNumerals('XCVI', 'IV') returns
                    C.
   ***************************************************************/
   void assert_XCVIplusIV_Equals_C()
   {
      char input1[5] = {'X', 'C', 'V', 'I', '\0'};
      char input2[3] = {'I', 'V', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'C');
      assert(*(result + sizeof(char)) == '\0');

      free(result);
   }

   /*************** Function: assert_LXplusXXX_Equals_XC *******
       Input: none
       Output: none
       Description: Assert that call addNumerals('LX', 'XXX') returns
                    XC.
   ***************************************************************/
   void assert_LXplusXXX_Equals_XC()
   {
      char input1[3] = {'L', 'X', '\0'};
      char input2[4] = {'X', 'X', 'X', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'X');
      assert(*(result + sizeof(char)) == 'C');
      assert(*(result + sizeof(char) * 2) == '\0');

      free(result);
   }

   /*************** Function: assert_IIIplusIII_Equals_VI *******
       Input: none
       Output: none
       Description: Assert that call addNumerals('III', 'III') returns
                    VI.
   ***************************************************************/
   void assert_IIIplusIII_Equals_VI()
   {
      char input1[4] = {'I', 'I', 'I', '\0'};
      char input2[4] = {'I', 'I', 'I', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'V');
      assert(*(result + sizeof(char)) == 'I');
      assert(*(result + sizeof(char) * 2) == '\0');

      free(result);
   }
   
   /*************** Function: assert_XXXVIIIplusI_Equals_XXXIX *******
       Input: none
       Output: none
       Description: Assert that call addNumerals('XXXVIII', 'I') returns
                    XXXIX.
   ***************************************************************/
   void assert_XXXVIIIplusI_Equals_XXXIX()
   {
      char input1[8] = {'X', 'X', 'X', 'V', 'I', 'I', 'I', '\0'};
      char input2[2] = {'I', '\0'};

      char *result = addNumerals(input1, input2);

      assert(*result == 'X');
      assert(*(result + sizeof(char)) == 'X');
      assert(*(result + sizeof(char) * 2) == 'X');
      assert(*(result + sizeof(char) * 3) == 'I');
      assert(*(result + sizeof(char) * 4) == 'X');
      assert(*(result + sizeof(char) * 5) == '\0');

      free(result);
   }

   /*************** Function: assert_IIminusI_Equals_I *******
       Input: none
       Output: none
       Description: Assert that call subtractNumerals('II', 'I') returns
                    I.
   ***************************************************************/
   void assert_IIminusI_Equals_I()
   {
      char input1[STRING_SIZE] = {'I', 'I', '\0'};
      char input2[STRING_SIZE] = {'I', '\0'};

      char *result = subtractNumerals(input1, input2);

      assert(*result == 'I');
      assert(*(result + sizeof(char)) == '\0');

      free(result);
   }

   /*************** Function: assert_LminusI_Equals_XLIX *******
       Input: none
       Output: none
       Description: Assert that call subtractNumerals('L', 'I') returns
                    XLIX.
   ***************************************************************/
   void assert_LminusI_Equals_XLIX()
   {
      char input1[STRING_SIZE] = {'L', '\0'};
      char input2[STRING_SIZE] = {'I', '\0'};

      char *result = subtractNumerals(input1, input2);

      assert(*result == 'X');
      assert(*(result + sizeof(char)) == 'L');
      assert(*(result + sizeof(char) * 2) == 'I');
      assert(*(result + sizeof(char) * 3) == 'X');
      assert(*(result + sizeof(char) * 4) == '\0');

      free(result);
   }
  
   /*************** Function: assert_XLIXminusI_Equals_XLVIII *******
       Input: none
       Output: none
       Description: Assert that call subtractNumerals('XLIX', 'I') returns
                    XLVIII.
   ***************************************************************/
   void assert_XLIXminusI_Equals_XLVIII()
   {
      char input1[STRING_SIZE] = {'X', 'L', 'I', 'X', '\0'};
      char input2[STRING_SIZE] = {'I', '\0'};

      char *result = subtractNumerals(input1, input2);

      assert(*result == 'X');
      assert(*(result + sizeof(char)) == 'L');
      assert(*(result + sizeof(char) * 2) == 'V');
      assert(*(result + sizeof(char) * 3) == 'I');
      assert(*(result + sizeof(char) * 4) == 'I');
      assert(*(result + sizeof(char) * 5) == 'I');
      assert(*(result + sizeof(char) * 6) == '\0');

      free(result);
   }

   /*************** Function: assert_VminusIII_Equals_II *******
       Input: none
       Output: none
       Description: Assert that call subtractNumerals('V', 'III') returns
                    II.
   ***************************************************************/
   void assert_VminusIII_Equals_II()
   {
      char input1[STRING_SIZE] = {'V', '\0'};
      char input2[STRING_SIZE] = {'I', 'I', 'I', '\0'};

      char *result = subtractNumerals(input1, input2);

      assert(*(result) == 'I');
      assert(*(result + sizeof(char)) == 'I');
      assert(*(result + sizeof(char) * 2) == '\0');

      free(result);
   }

   /*************** Function: assert_LminusXLV_Equals_V *******
       Input: none
       Output: none
       Description: Assert that call subtractNumerals('L', 'XLV') returns
                    V.
   ***************************************************************/
   void assert_LminusXLV_Equals_V()
   {
      char input1[STRING_SIZE] = {'L', '\0'};
      char input2[STRING_SIZE] = {'X', 'L', 'V', '\0'};

      char *result = subtractNumerals(input1, input2);

      assert(*(result) == 'V');
      assert(*(result + sizeof(char)) == '\0');

      free(result);
   }

   /*************** Function: assert_CminusL_Equals_L *******
       Input: none
       Output: none
       Description: Assert that call subtractNumerals('C', 'L') returns
                    L.
   ***************************************************************/
   void assert_CminusL_Equals_L()
   {
      char input1[STRING_SIZE] = {'C', '\0'};
      char input2[STRING_SIZE] = {'L', '\0'};

      char *result = subtractNumerals(input1, input2);

      assert(*(result) == 'L');
      assert(*(result + sizeof(char)) == '\0');

      free(result);
   }

   /*************** Function: assert_MminusD_Equals_D *******
       Input: none
       Output: none
       Description: Assert that call subtractNumerals('M', 'D') returns
                    D.
   ***************************************************************/
   void assert_MminusD_Equals_D()
   {
      char input1[STRING_SIZE] = {'M', '\0'};
      char input2[STRING_SIZE] = {'D', '\0'};

      char *result = subtractNumerals(input1, input2);

      assert(*(result) == 'D');
      assert(*(result + sizeof(char)) == '\0');

      free(result);
   }

   /*************** Function: assert_LminusXI_Equals_XXXIX *******
       Input: none
       Output: none
       Description: Assert that call subtractNumerals('L', 'XI') returns
                    XXXIX.
   ***************************************************************/
   void assert_LminusXI_Equals_XXXIX()
   {
      char input1[STRING_SIZE] = {'L', '\0'};
      char input2[STRING_SIZE] = {'X', 'I', '\0'};

      char *result = subtractNumerals(input1, input2);

      assert(*(result) == 'X');
      assert(*(result + sizeof(char)) == 'X');
      assert(*(result + sizeof(char) * 2) == 'X');
      assert(*(result + sizeof(char) * 3) == 'I');
      assert(*(result + sizeof(char) * 4) == 'X');
      assert(*(result + sizeof(char) * 5) == '\0');

      free(result);
   }

   /*************** Function: assert_detectOverflow_MMMM_Returns_True *******
       Input: none
       Output: none
       Description: Assert that call detectOverflow('MMMM') returns
                    true.
   ***************************************************************/
   void assert_detectOverflow_MMMM_Returns_True()
   {
      char *input = "MMMM";

      assert(detectOverflow(input) == true);
   }
