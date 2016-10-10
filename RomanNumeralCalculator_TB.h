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
   void assert_CCplusCC_Equals_CD();
   void assert_DplusD_Equals_M();
   void assert_IVplusIV_Equals_VIII();
   void assert_IXplusIX_Equals_XVIII();
   void assert_XLplusXL_Equals_LXXX();
   void assert_XCplusXC_Equals_CLXXX();
   void assert_CDplusCD_Equals_DCCC();
   void assert_CMplusCM_Equals_MDCCC();
   void assert_MCIplusMCDXXXVI_Equals_MMDXXXVII();
   void assert_CDXplusCD_Equals_DCCCX();
   void assert_CVIplusX_Equals_CXVI();
   void assert_XCVIplusIV_Equals_C();
   void assert_LXplusXXX_Equals_XC();
   void assert_IIIplusIII_Equals_VI();
   void assert_XXplusXXV_Equals_XLV();
   void assert_XXXVIIIplusI_Equals_XXXIX();

   void assert_IIminusI_Equals_I();

   void assert_IL_goes_to_XLIX();
   void assert_IC_goes_to_XCIX();
   void assert_ID_goes_to_CDXCIX();
   void assert_IM_goes_to_CMXCIX();
   void assert_XD_goes_to_CDXC();
   void assert_XM_goes_to_CMXC();
   #endif // TB_H
