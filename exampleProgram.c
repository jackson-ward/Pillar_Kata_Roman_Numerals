   // FILE: exampleProgram.c
   // AUTHOR: Jackson Ward
   // 
   // DESCRIPTION: Short program to demonstrate use of
   //              the RomanNumeralCalculator Library.
   //              Add or Subtract Numerals from
   //              Command Line
   //
   // CREATED ON: 10/12/16

   #include <stdio.h>
   #include "RomanNumeralCalculator.h"

   int main(int i, char *v[])
   {
      if (i != 4  ||  (*v[1] != 'a' && *v[1] != 's')) // check for proper usage, print message
      {
         printf("Usage: PROGRAM <function> <operand_1> <operand_2>\n\nFunction = a for add or s for subtract. Example: 'exampleProgram a XIV CCI'\n\n");
         return 0;
      }
  
      char returnChar;           // stores return character
      char result[STRING_SIZE];  // stores result string

      if (*v[1] == 'a')   // add function
      {
         returnChar = addNumerals(v[2], v[3], &result[0]);
      }

      else if (*v[1] == 's')  // subtract function
      {
         returnChar = subtractNumerals(v[2], v[3], &result[0]);
      }

      if (returnChar == 'I') printf("Invalid Input!\n");  // alert invalid input
    
      else if (returnChar == 'X') printf("Result = %s | Overflow Occured!\n", result);  // print result and alert overflow

      else if (returnChar == 'V') printf("Result = Negative %s\n", result);   // print result and alert negative

      else printf("Result = %s\n", result);  // print result

      
      return 0;
   }
