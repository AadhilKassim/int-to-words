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

    auto getBelow100 = [&](int n) {
        if (n < 20) return numbersBelow20[n];
        return numbersInTens[n / 10 - 2] + (n % 10 ? " " + numbersBelow20[n % 10] : "");
    };

    auto getBelow1000 = [&](int n) {
        if (n < 100) return getBelow100(n);
        return numbersBelow20[n / 100] + " hundred" + (n % 100 ? " and " + getBelow100(n % 100) : "");
    };

    std::string result = "";

    if (num >= 10000000) {
        result += getBelow100(num / 10000000) + " crore";
        num %= 10000000;
    }
    if (num >= 100000) {
        if (!result.empty()) result += " ";
        result += getBelow100(num / 100000) + " lakh";
        num %= 100000;
    }
    if (num >= 1000) {
        if (!result.empty()) result += " ";
        result += getBelow100(num / 1000) + " thousand";
        num %= 1000;
    }
    if (num >= 100) {
        if (!result.empty()) result += " ";
        result += getBelow1000(num);
    } else if (num > 0) {
        if (!result.empty()) result += " and ";
        result += getBelow100(num);
    }

    return result;
}