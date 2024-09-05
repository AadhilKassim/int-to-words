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

    // for numbers from 1000 to 9999
    if (num < 10000)
    {
        int thousands = num / 1000; //2564
        int remainder = num % 1000; //564
        int hundreds = remainder / 100; //5
        remainder = remainder % 100; //64

        if (remainder == 0 && hundreds == 0)
        {
            return numbersBelow20[thousands] + " thousand"; 
        }
        else if (remainder == 0)
        {
            return numbersBelow20[thousands] + " thousand " + numbersBelow20[hundreds] + " hundred";
        }
        else if (hundreds == 0 && remainder < 20)
        {
            return numbersBelow20[thousands] + " thousand and " + numbersBelow20[remainder];
        }
        else if (hundreds == 0)
        {
            int tens = remainder / 10;
            int ones = remainder % 10;
            return numbersBelow20[thousands] + " thousand and " + numbersInTens[tens - 2] + (ones ? " " + numbersBelow20[ones] : "");
        }
        else if (remainder < 20)
        {
            return numbersBelow20[thousands] + " thousand " + numbersBelow20[hundreds] + " hundred and " + numbersBelow20[remainder];
        }
        else
        {
            int tens = remainder / 10;
            int ones = remainder % 10;
            return numbersBelow20[thousands] + " thousand " + numbersBelow20[hundreds] + " hundred and " + numbersInTens[tens - 2] + (ones ? " " + numbersBelow20[ones] : "");
        }
    }

    return "Couldn't handle such number";
}