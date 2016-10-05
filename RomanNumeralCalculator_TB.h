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
   #endif // TB_H
