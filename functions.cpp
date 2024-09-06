#include <iostream>
#include <string>

std::string numberToWords(long long int num)
{
    if (num == 0)
    {
        return "zero";
    }

    std::string numbersBelow20[] = {"", "one", "two", "three", "four",
                                    "five", "six", "seven", "eight", "nine",
                                    "ten", "eleven", "twelve", "thirteen", "fourteen",
                                    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    std::string numbersInTens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    // for numbers under 20
    if (num < 20)
    {
        return numbersBelow20[num];
    }

    // for numbers under 100
    if (num < 100 && num >= 20)
    {
        int tens{};
        int ones{};

        tens = (num / 10);
        ones = num % 10;

        return numbersInTens[tens - 2] + " " + numbersBelow20[ones];
    }
    
    if (num >= 100 && num < 1000)
    {
        int hundreds = num/100;
        int remainder = num%100;
        int tens = (remainder)/10;
        int ones = (remainder)%10;

        if ((num%100) == 0 && tens == 0)
        {
            return numbersBelow20[hundreds] + " hundred";
        }
        else if ((num%100) < 20 )
        {
            return numbersBelow20[hundreds] + " hundred and " + numbersBelow20[remainder];
        }
        else
        {
            return numbersBelow20[hundreds] + " hundred and " + numbersInTens[tens - 2] + " " + numbersBelow20[ones];
        }
         
    }
    

    // for numbers from 1000 to 9999
    if (num < 10000 && num >= 1000)
    {
        int thousands = num / 1000;
        int remainder = num % 1000;
        int hundreds = remainder / 100;
        remainder = remainder % 100;

        if (remainder == 0 && hundreds == 0) //when the number is of type x000 eg:1000
        {
            return numbersBelow20[thousands] + " thousand"; 
        }
        else if (remainder == 0) //when the number is of type xx00 eg:3200
        {
            return numbersBelow20[thousands] + " thousand " + numbersBelow20[hundreds] + " hundred";
        }
        else if (hundreds == 0 && remainder < 20) //when the number is of type x0xx with last two digits less than 20 eg:7519
        {
            return numbersBelow20[thousands] + " thousand and " + numbersBelow20[remainder];
        }
        else if (hundreds == 0) //when the number is of type x0xx eg:1256
        {
            int tens = remainder / 10;
            int ones = remainder % 10;
            return numbersBelow20[thousands] + " thousand and " + numbersInTens[tens - 2] + (ones ? " " + numbersBelow20[ones] : "");
        }
        else if (remainder < 20) //when the number is of type xxxx with last two digits less than 20 eg:4611
        {
            return numbersBelow20[thousands] + " thousand " + numbersBelow20[hundreds] + " hundred and " + numbersBelow20[remainder];
        }
        else //when number is of type xxxx eg:8987
        {
            int tens = remainder / 10;
            int ones = remainder % 10;
            return numbersBelow20[thousands] + " thousand " + numbersBelow20[hundreds] + " hundred and " + numbersInTens[tens - 2] + (ones ? " " + numbersBelow20[ones] : "");
        }
    }

    //for numbers from 10000-99999
    if (num<100000 && num >= 1000) //12345
    {
        int thousands = num / 1000;
        int remainder = num % 1000;
        int hundreds = remainder / 100;
        remainder = remainder % 100;

        if (thousands < 20 && remainder == 0 && hundreds == 0)
        {
            return numbersBelow20[thousands] + " thousand"; 
        }
        else if (thousands >= 20 && remainder == 0 && hundreds == 0)
        {
            return numbersInTens[(thousands/10)-2] + " " + numbersBelow20[thousands%10] + " thousand";
        }
        else if (thousands < 20 && remainder == 0)
        {
            return numbersBelow20[thousands] + " thousand " + numbersBelow20[hundreds] + " hundred";
        }
        else if (thousands >= 20 && remainder == 0)
        {
            return numbersInTens[(thousands/10)-2] + " " + numbersBelow20[thousands%10] + " thousand " + numbersBelow20[hundreds] + " hundred";
        }
        else if (thousands < 20 && hundreds == 0 && remainder < 20)
        {
            return numbersBelow20[thousands] + " thousand and " + numbersBelow20[remainder];
        }
        else if (thousands >= 20 && hundreds == 0 && remainder < 20)
        {
            return numbersInTens[(thousands/10)-2] + " " + numbersBelow20[thousands%10] + " thousand and " + numbersBelow20[remainder];
        }
        else if (thousands < 20 && hundreds == 0)
        {
            int tens = remainder / 10;
            int ones = remainder % 10;
            return numbersBelow20[thousands] + " thousand and " + numbersInTens[tens - 2] + (ones ? " " + numbersBelow20[ones] : "");
        }
        else if (thousands >= 20 && hundreds == 0)
        {
            int tens = remainder / 10;
            int ones = remainder % 10;
            return numbersInTens[(thousands/10)-2] + " " + numbersBelow20[thousands%10] + " thousand and " + numbersInTens[tens - 2] + (ones ? " " + numbersBelow20[ones] : "");
        }
        else if (thousands < 20 && remainder < 20)
        {
            return numbersBelow20[thousands] + " thousand " + numbersBelow20[hundreds] + " hundred and " + numbersBelow20[remainder];
        }
        else if (thousands >= 20 && remainder < 20)
        {
            return numbersInTens[(thousands/10)-2] + " " + numbersBelow20[thousands%10] + " thousand " + numbersBelow20[hundreds] + " hundred and " + numbersBelow20[remainder];
        }
        else if (thousands >= 20)
        {
            int tens = remainder / 10;
            int ones = remainder % 10;
            return numbersInTens[(thousands/10)-2] + " " + numbersBelow20[thousands%10] + " thousand " + numbersBelow20[hundreds] + " hundred and " + numbersInTens[tens - 2] + (ones ? " " + numbersBelow20[ones] : "");
        }
        else
        {
            int tens = remainder / 10;
            int ones = remainder % 10;
            return numbersBelow20[thousands] + " thousand " + numbersBelow20[hundreds] + " hundred and " + numbersInTens[tens - 2] + (ones ? " " + numbersBelow20[ones] : "");
        }
    }
    
    // for numbers from 100000-999999
    if (num < 1000000 && num >= 100000)
    {
        int lakhs = num / 100000;                    // Extract lakhs
        int remainder = num % 100000;                 // Remainder after lakhs
        int thousands = remainder / 1000;             // Extract thousands
        int belowThousand = remainder % 1000;         // Remainder after thousands
        int hundreds = belowThousand / 100;           // Extract hundreds
        int tensAndOnes = belowThousand % 100;        // Extract tens and ones

        std::string result = "";

        // Handling lakhs
        if (lakhs > 0)
        {
            result += numbersBelow20[lakhs] + " lakh";
        }

        // Handling thousands
        if (thousands > 0)
        {
            if (!result.empty()) result += " "; // Add space if lakhs exist
            if (thousands < 20)
            {
                result += numbersBelow20[thousands] + " thousand";
            }
            else
            {
                result += numbersInTens[(thousands / 10) - 2] + (thousands % 10 ? " " + numbersBelow20[thousands % 10] : "") + " thousand";
            }
        }

        // Handling hundreds
        if (hundreds > 0)
        {
            if (!result.empty()) result += " "; // Add space if lakhs or thousands exist
            result += numbersBelow20[hundreds] + " hundred";
        }

        // Handling tens and ones (below 100)
        if (tensAndOnes > 0)
        {
            if (!result.empty()) result += " and "; // Add "and" if lakhs, thousands, or hundreds exist
            if (tensAndOnes < 20)
            {
                result += numbersBelow20[tensAndOnes];
            }
            else
            {
                result += numbersInTens[(tensAndOnes / 10) - 2] + (tensAndOnes % 10 ? " " + numbersBelow20[tensAndOnes % 10] : "");
            }
        }

        return result;
    }

    // for numbers from 1000000-99999999 (10 lakhs to 99,99,999)
    if (num >= 1000000 && num < 10000000)
    {
        int lakhs = num / 100000;                    // Extract the lakhs part (two digits)
        int remainder = num % 100000;                // Remainder after lakhs
        int thousands = remainder / 1000;            // Extract thousands
        int belowThousand = remainder % 1000;        // Remainder after thousands
        int hundreds = belowThousand / 100;          // Extract hundreds
        int tensAndOnes = belowThousand % 100;       // Extract tens and ones

        std::string result = "";

        // Handling lakhs (both one and two-digit lakhs)
        if (lakhs < 20) 
        {
            result += numbersBelow20[lakhs] + " lakh";
        }
        else
        {
            result += numbersInTens[(lakhs / 10) - 2] + (lakhs % 10 ? " " + numbersBelow20[lakhs % 10] : "") + " lakh";
        }

        // Handling thousands
        if (thousands > 0)
        {
            result += " "; // Add space after lakhs
            if (thousands < 20)
            {
                result += numbersBelow20[thousands] + " thousand";
            }
            else
            {
                result += numbersInTens[(thousands / 10) - 2] + (thousands % 10 ? " " + numbersBelow20[thousands % 10] : "") + " thousand";
            }
        }

        // Handling hundreds
        if (hundreds > 0)
        {
            result += " " + numbersBelow20[hundreds] + " hundred";
        }

        // Handling tens and ones (below 100)
        if (tensAndOnes > 0)
        {
            result += " and "; // Add "and" if there are lakhs, thousands, or hundreds
            if (tensAndOnes < 20)
            {
                result += numbersBelow20[tensAndOnes];
            }
            else
            {
                result += numbersInTens[(tensAndOnes / 10) - 2] + (tensAndOnes % 10 ? " " + numbersBelow20[tensAndOnes % 10] : "");
            }
        }

        return result;
    }

    // for numbers from 10000000 to 999999999 (1 crore to 99,99,99,999)
    if (num >= 10000000 && num < 1000000000)
    {
        int crores = num / 10000000;                 // Extract the crore part (two digits)
        int remainder = num % 10000000;              // Remainder after crores
        int lakhs = remainder / 100000;              // Extract the lakhs part
        remainder = remainder % 100000;              // Remainder after lakhs
        int thousands = remainder / 1000;            // Extract thousands
        int belowThousand = remainder % 1000;        // Remainder after thousands
        int hundreds = belowThousand / 100;          // Extract hundreds
        int tensAndOnes = belowThousand % 100;       // Extract tens and ones

        std::string result = "";

        // Handling crores (both one and two-digit crores)
        if (crores < 20)
        {
            result += numbersBelow20[crores] + " crore";
        }
        else
        {
            result += numbersInTens[(crores / 10) - 2] + (crores % 10 ? " " + numbersBelow20[crores % 10] : "") + " crore";
        }

        // Handling lakhs
        if (lakhs > 0)
        {
            result += " "; // Add space after crores
            if (lakhs < 20)
            {
                result += numbersBelow20[lakhs] + " lakh";
            }
            else
            {
                result += numbersInTens[(lakhs / 10) - 2] + (lakhs % 10 ? " " + numbersBelow20[lakhs % 10] : "") + " lakh";
            }
        }

        // Handling thousands
        if (thousands > 0)
        {
            result += " "; // Add space after lakhs
            if (thousands < 20)
            {
                result += numbersBelow20[thousands] + " thousand";
            }
            else
            {
                result += numbersInTens[(thousands / 10) - 2] + (thousands % 10 ? " " + numbersBelow20[thousands % 10] : "") + " thousand";
            }
        }

        // Handling hundreds
        if (hundreds > 0)
        {
            result += " " + numbersBelow20[hundreds] + " hundred";
        }

        // Handling tens and ones (below 100)
        if (tensAndOnes > 0)
        {
            result += " and "; // Add "and" if there are crores, lakhs, thousands, or hundreds
            if (tensAndOnes < 20)
            {
                result += numbersBelow20[tensAndOnes];
            }
            else
            {
                result += numbersInTens[(tensAndOnes / 10) - 2] + (tensAndOnes % 10 ? " " + numbersBelow20[tensAndOnes % 10] : "");
            }
        }

        return result;
    }

    // for numbers from 100000000 to 99999999999 (10 crores to 99,99,99,99,999)
    if (num >= 100000000 && num < 100000000000)
    {
        int crores = num / 10000000;                // Extract the crore part (two digits)
        int remainder = num % 10000000;             // Remainder after crores
        int lakhs = remainder / 100000;             // Extract the lakhs part
        remainder = remainder % 100000;             // Remainder after lakhs
        int thousands = remainder / 1000;           // Extract thousands
        int belowThousand = remainder % 1000;       // Remainder after thousands
        int hundreds = belowThousand / 100;         // Extract hundreds
        int tensAndOnes = belowThousand % 100;      // Extract tens and ones

        std::string result = "";

        // Handling crores (both one and two-digit crores)
        if (crores < 20)
        {
            result += numbersBelow20[crores] + " crore";
        }
        else
        {
            result += numbersInTens[(crores / 10) - 2] + (crores % 10 ? " " + numbersBelow20[crores % 10] : "") + " crore";
        }

        // Handling lakhs
        if (lakhs > 0)
        {
            result += " "; // Add space after crores
            if (lakhs < 20)
            {
                result += numbersBelow20[lakhs] + " lakh";
            }
            else
            {
                result += numbersInTens[(lakhs / 10) - 2] + (lakhs % 10 ? " " + numbersBelow20[lakhs % 10] : "") + " lakh";
            }
        }

        // Handling thousands
        if (thousands > 0)
        {
            result += " "; // Add space after lakhs
            if (thousands < 20)
            {
                result += numbersBelow20[thousands] + " thousand";
            }
            else
            {
                result += numbersInTens[(thousands / 10) - 2] + (thousands % 10 ? " " + numbersBelow20[thousands % 10] : "") + " thousand";
            }
        }

        // Handling hundreds
        if (hundreds > 0)
        {
            result += " " + numbersBelow20[hundreds] + " hundred";
        }

        // Handling tens and ones (below 100)
        if (tensAndOnes > 0)
        {
            result += " and "; // Add "and" if there are crores, lakhs, thousands, or hundreds
            if (tensAndOnes < 20)
            {
                result += numbersBelow20[tensAndOnes];
            }
            else
            {
                result += numbersInTens[(tensAndOnes / 10) - 2] + (tensAndOnes % 10 ? " " + numbersBelow20[tensAndOnes % 10] : "");
            }
        }

        return result;
    }



    return "Couldn't handle such number";
}