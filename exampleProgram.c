   #include <stdio.h>
   #include "RomanNumeralCalculator.h"

   int main(int i, char *v[])
   {
      char returnChar;
      char result[STRING_SIZE];

      if (*v[1] == 'a')
      {
         returnChar = addNumerals(v[2], v[3], &result[0]);
      }

      else if (*v[1] == 's')
      {
         returnChar = subtractNumerals(v[2], v[3], &result[0]);
      }

      if (returnChar == 'I') printf("Invalid Input!\n");
    
      else if (returnChar == 'X') printf("Result = %s | Overflow Occured!\n", result);

      else if (returnChar == 'V') printf("Result = Negative %s\n", result);

      else printf("Result = %s\n", result);

      
      return 0;
   }
