#include <iostream>
#include <string>
#include "itw.h"

int main(int argc,char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <integer>\n";
        return 1; 
    }

    std::cout <<numberToWords(std::atoi(argv[1])) << "\n";
    
    return 0;
} 
