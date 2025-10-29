# My Experience

## Why This project

I started working on this project as a challenge to complete a select few such pre defined challenges from Codeing Challenges right before college. I am a amature C++ developer and learned C++ from high school, and wanting to improve my skills completed this challenge.

## First iteration

For the first ever almost satisfactory level of completion on this program used the well dreaded and hated nested if and if-else-if ladder. Though it worked the whole file where the conversion function lived was around **500** lines. Then I found that ChatGPT can role play as a guide by providing prompt to let it know to not just spew out the answers. Here are som of the prompts I used.

```text
I've taken up a challenge to create a integer to words c++ application with the word output in indian number system. Guide me though the project.
```
Another one:
```text
My plan here is to divide the code into different files. main will be in itw.cpp (itw is an abbreviation of int to word), different functions in function.cpp and all the prototypes in itw.h. my program will be a CLI file which will hake integers as arguments and display corresponding numbers.
```
These are primitive prompt engineering from my side. You can come up with better propmts for your specific usage

## Fine tuning

The program was finetuned using the modern C++ syntax and usage of the string library in C++. I have used Lambda functions after I got to learn about them in a freecodecamp video on C++.
Here is an example:

```C++
auto getBelow100 = [&](int n) {
    if (n < 20) return numbersBelow20[n];
    return numbersInTens[n / 10 - 2] + (n % 10 ? " " + numbersBelow20[n % 10] : "");
};
```
Where it follows this foloowing format to return a value.
```text
[captures](parameters) -> return_type {
    // function body
};

```
Where
**[&]** means: *“capture all variables from the surrounding scope by reference.”*

### Command-line Interface (CLI)

The program accepts integers as arguments and displays the corresponding number in words. Run the executable as follows:

```bash
./itw <integer>
```

### Example Commands:

```bash
./itw 4586
```

**Output**: `Four Thousand Five Hundred Eighty-Six`

```bash
./itw 123456
```

**Output**: `One Lakh Twenty-Three Thousand Four Hundred Fifty-Six`

---

## How It Works

### Logic for Number Conversion:

1. **Numbers 0-19**: These are hardcoded in an array for quick access (e.g., `0 = ""`, `1 = "One"`, ... `19 = "Nineteen"`).
2. **Tens (20-99)**: Numbers like "Twenty", "Thirty" are stored, and digits are appended (e.g., `34 = "Thirty-Four"`).
3. **Thousands and Lakhs**: The application breaks the number into thousands, lakhs, crores, and converts each part into words.
4. **Optimized Handling**: For numbers between 10,000 and 99,999, two digits are passed into the `thousands` variable, simplifying the conversion logic.

### Modularity:

- **Main Logic** (`itw.cpp`): Controls the flow and handles input/output.
- **Functions** (`functions.cpp`): Contains specific functions for each number range, making the code more readable and reusable.
- **Header** (`itw.h`): Includes all function prototypes and constants for easy reference across the project.

---

## Build Instructions

### Prerequisites

- C++ compiler (g++ recommended)
- Command-line environment (Linux, MacOS, or Windows)

### Compiling the Project

To compile the program, use the following command:

```bash
g++ itw.cpp functions.cpp -o itw
```

### Running the Program

Once compiled, run the program as follows:

```bash
./itw <integer>
```

Example:

```bash
./itw 98304
```
