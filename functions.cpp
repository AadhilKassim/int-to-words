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
    

    return "Couldn't handle such number";
}