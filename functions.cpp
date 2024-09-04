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

if (num < 10000 && num >=1000)
{
    int thousands = num / 1000;
    int remainder = num % 1000;
    int hundreds = remainder / 100;
    int tens = remainder / 10;
    int ones = remainder % 10;

    if (remainder == 0)
    {
        return numbersBelow20[thousands] + " " + "thousand";
    }
    else if (remainder < 10)
    {
        return numbersBelow20[thousands] + " " + "thousand" + " and " + numbersBelow20[remainder];
    }
    else if (remainder < 100 && remainder >= 10)
    {
        return numbersBelow20[thousands] + " " + "thousand" + " and " + numbersInTens[tens - 2] + " " + numbersBelow20[ones];
    }
}
    return "Couldn't handle such number";
}