   /* FILE: RomanNumeralCalculator.h
      AUTHOR: Jackson Ward
 
      DESCRIPTION: Header file for RomanNumeralCalculator's Test Bench
      CREATEDON: 10/3/2016
   */

   #ifndef TB_H
   #define TB_H

   void assertDetectionOfProperNumeralInput();
   void assertCorrectResultWhenComparingTheSizeOf2CharacterNumerals();
   void assertStringNumeralPositveElementsAreCategorizedCorrectly();
   void assertStringNumeralPositiveElementsAreCategorizedCorrectlySpecialCases();
   void assertStringNumeralPositiveElementsAreCategorizedCorrectlyGeneralSize();
   void assertStringNumeralNegativeElementsAreCategorizedCorrectly();
   void assertStringNumeralNegativeElementsAreCategorizedCorrectlySpecialCases();
   void assertStringNumeralNegativeElementsAreCategorizedCorrectlyGeneralSize();
   void assertCharacterRemovedFromStringProperly();
   void assertPositivesAndNegativesCancelForAddition();
   void assertProperConcatenationOfNumeralToEmptyString();
   void assertProperConcatenationIntoNonEmptyString();

   void assert_IplusI_Equals_II();
   void assert_IplusII_Equals_III();
   void assert_IplusIII_Equals_IV();
   void assert_IplusV_Equals_VI();
   void assert_IplusIV_Equals_V();
   void assert_IVplusI_Equals_V();
   void assert_XplusIV_Equals_XIV();
   void assert_VplusV_Equals_X();
   void assert_XXplusXX_Equals_XL();
   void assert_LplusL_Equals_C();
   void assert_CCplusL_CC_Equals_CD();
   #endif // TB_H
