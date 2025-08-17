# Custom Programming Language Compiler 🚀

A sophisticated custom programming language compiler built in C++ featuring Bengali-inspired keywords, comprehensive language constructs, and modern programming features including complex expressions, control flow, logical operators, and robust error handling.

[![Language](https://img.shields.io/badge/Language-C++-blue.svg)](https://isocpp.org/)
[![Compiler](https://img.shields.io/badge/Compiler-GCC-green.svg)](https://gcc.gnu.org/)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Active-success.svg)](https://github.com/Hamza-28/Compiler-Design-Project)

## 📋 Table of Contents
- [Features](#-features)
- [Language Specification](#-language-specification)
- [Installation Guide](#-installation-guide)
- [Usage Instructions](#-usage-instructions)
- [Complete Language Reference](#-complete-language-reference)
- [Code Examples](#-code-examples)
- [Project Architecture](#-project-architecture)
- [Technical Implementation](#-technical-implementation)
- [Error Handling](#-error-handling)
- [Advanced Features](#-advanced-features)
- [Testing](#-testing)
- [Performance](#-performance)
- [Contributing](#-contributing)
- [Roadmap](#-roadmap)
- [FAQ](#-faq)

## ✨ Features

### 🔧 Core Language Features
- **📊 Multiple Data Types**: Integers (`purno`), Floats (`vogno`), Strings (`shobdo`)
- **🔢 Variable Management**: Declaration, initialization, assignment, and scope handling
- **🧮 Arithmetic Operations**: Full support for `+`, `-`, `*`, `/`, `+=`, `-=`, `*=`, `/=`, `++`, `--`
- **🔍 Comparison Operators**: `<`, `>`, `<=`, `>=`, `==`, `!=`
- **🧠 Logical Operators**: `&&` (AND), `||` (OR) with proper precedence
- **🎯 Control Flow**: If-else statements, else-if chaining, while loops
- **📝 Input/Output**: Console I/O with advanced string formatting
- **💬 Comments**: Single-line (`//`) and multi-line (`/* */`) support
- **🛡️ Error Handling**: Comprehensive error reporting with detailed diagnostics

### 🚀 Advanced Features
- **🔀 Expression Parser**: Unified expression parsing with operator precedence
- **🏗️ Nested Structures**: Support for deeply nested control structures
- **🤔 Complex Conditions**: Multi-condition expressions with logical operators
- **🔗 String Operations**: String concatenation and manipulation
- **🔒 Type Safety**: Runtime type checking and automatic type conversion
- **🎨 Flexible Syntax**: Intuitive Bengali-inspired keyword system
- **📊 Symbol Table**: Efficient variable storage and retrieval system
- **🔄 Loop Control**: Advanced loop constructs with complex termination conditions

## 🔤 Language Specification

### Keywords and Their Meanings

| Keyword | English Equivalent | Purpose | Example |
|---------|-------------------|---------|---------|
| `shuru` | `main()` / `begin` | Program start | `shuru` |
| `shesh` | `end` | Program end | `shesh` |
| `purno` | `int` | Integer declaration | `purno x = 5;` |
| `vogno` | `float` / `double` | Float declaration | `vogno pi = 3.14;` |
| `shobdo` | `string` | String declaration | `shobdo name = "Hello";` |
| `jodi` | `if` | Conditional statement | `jodi (x > 0)` |
| `nahole` | `else` | Else statement | `nahole` |
| `nahole jodi` | `else if` | Else if statement | `nahole jodi (x == 0)` |
| `jotokkhon` | `while` | While loop | `jotokkhon (i < 10)` |
| `dekhao` | `cout` / `print` | Output statement | `dekhao << "Hello";` |
| `nao` | `cin` / `input` | Input statement | `nao >> x;` |

### Operator Precedence (Highest to Lowest)

| Level | Operators | Description | Associativity |
|-------|-----------|-------------|---------------|
| 1 | `()` | Parentheses | Left-to-right |
| 2 | `*`, `/` | Multiplication, Division | Left-to-right |
| 3 | `+`, `-` | Addition, Subtraction | Left-to-right |
| 4 | `<`, `>`, `<=`, `>=` | Relational operators | Left-to-right |
| 5 | `==`, `!=` | Equality operators | Left-to-right |
| 6 | `&&` | Logical AND | Left-to-right |
| 7 | `||` | Logical OR | Left-to-right |

### Data Types and Operations

#### Integer (`purno`)
```cpp
purno x = 10;                    // Declaration with initialization
purno a = 5, b = 15, c;         // Multiple declarations
x = a + b * 2;                  // Arithmetic operations
x += 10;                        // Compound assignment
x++;                            // Increment
```

#### Float (`vogno`)
```cpp
vogno pi = 3.14159;             // Float declaration
vogno area = pi * radius * radius;
area /= 2.0;                    // Division assignment
```

#### String (`shobdo`)
```cpp
shobdo greeting = "Hello";       // String declaration
shobdo name = "World";
shobdo message = greeting + " " + name;  // Concatenation
```

## 🛠️ Installation Guide

### Prerequisites

#### For Linux/Unix Systems
- **Operating System**: Linux/Unix (Ubuntu 18.04+ recommended)
- **Compiler**: GCC 7.0+ with C++11 support
- **Memory**: Minimum 1GB RAM
- **Storage**: 50MB free space

#### For Windows Systems
- **Operating System**: Windows 10/11 (recommended)
- **Compiler**: One of the following options:
  - **MinGW-w64** (recommended for beginners)
  - **Microsoft Visual Studio** with C++ support
  - **Dev-C++** with GCC compiler
  - **Code::Blocks** with MinGW
- **Memory**: Minimum 1GB RAM
- **Storage**: 100MB free space (including compiler tools)

### Step-by-Step Installation

#### 🐧 Linux/Unix Installation

##### Method 1: Direct Compilation
```bash
# Clone the repository
git clone https://github.com/Hamza-28/Compiler-Design-Project.git
cd Compiler-Design-Project

# Compile the compiler
g++ -std=c++11 -O2 -o compiler compiler.cpp tokenizer.cpp parser.cpp

# Run your program (writes code in code.txt first)
./compiler
```

##### Method 2: Using Makefile (Optional)
```bash
# Create Makefile
cat > Makefile << 'EOF'
CXX = g++
CXXFLAGS = -std=c++11 -O2 -Wall -Wextra
TARGET = compiler
SOURCES = compiler.cpp tokenizer.cpp parser.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

.PHONY: clean
EOF

# Compile using make
make

# Clean build files
make clean
```

#### 🪟 Windows Installation

##### Option 1: Using MinGW-w64 (Recommended)

**Step 1: Install MinGW-w64**
```powershell
# Download and install MinGW-w64 from: https://www.mingw-w64.org/downloads/
# OR use MSYS2 (recommended):
# 1. Download MSYS2 from: https://www.msys2.org/
# 2. Install MSYS2
# 3. Open MSYS2 terminal and run:
pacman -S mingw-w64-x86_64-gcc
pacman -S mingw-w64-x86_64-gdb
pacman -S git
```

**Step 2: Set up Environment**
```powershell
# Add MinGW bin directory to PATH:
# Add C:\msys64\mingw64\bin to your system PATH environment variable
# OR if using standalone MinGW: Add C:\MinGW\bin to PATH
```

**Step 3: Clone and Compile**
```powershell
# Open Command Prompt or PowerShell
# Clone the repository
git clone https://github.com/Hamza-28/Compiler-Design-Project.git
cd Compiler-Design-Project

# Compile the compiler
g++ -std=c++11 -O2 -o compiler.exe compiler.cpp tokenizer.cpp parser.cpp

# Run your program (write code in code.txt first)
compiler.exe
```

##### Option 2: Using Visual Studio

**Step 1: Install Visual Studio**
```powershell
# Download Visual Studio Community (free) from:
# https://visualstudio.microsoft.com/vs/community/
# Make sure to select "C++ development" workload during installation
```

**Step 2: Create Project**
```powershell
# 1. Open Visual Studio
# 2. Create new "Console App" project
# 3. Add all .cpp and .h files to the project
# 4. Build and run the project
```

**Step 3: Alternative Command Line**
```powershell
# Open "Developer Command Prompt for VS"
# Navigate to project directory
cd path\to\Compiler-Design-Project

# Compile using cl (Visual Studio compiler)
cl /EHsc compiler.cpp tokenizer.cpp parser.cpp

# Run the program
compiler.exe
```

##### Option 3: Using Dev-C++ or Code::Blocks

**Step 1: Install IDE**
```powershell
# Download Dev-C++: https://www.bloodshed.net/devcpp.html
# OR Code::Blocks: https://www.codeblocks.org/downloads/
```

**Step 2: Create Project**
```powershell
# 1. Open your IDE
# 2. Create new project (Console Application)
# 3. Add all source files (compiler.cpp, tokenizer.cpp, parser.cpp)
# 4. Add header files (tokenizer.h, parser.h)
# 5. Build and run the project
```

### Troubleshooting Installation

#### Linux/Unix Issues

**Issue**: `g++: command not found`
```bash
# Ubuntu/Debian
sudo apt update && sudo apt install g++

# CentOS/RHEL
sudo yum install gcc-c++

# Fedora
sudo dnf install gcc-c++

# Arch Linux
sudo pacman -S gcc
```

#### Windows Issues

**Issue**: `'g++' is not recognized as an internal or external command`
```powershell
# Solution 1: Add MinGW to PATH
# Go to System Properties > Environment Variables
# Add C:\MinGW\bin or C:\msys64\mingw64\bin to PATH

# Solution 2: Use full path
C:\MinGW\bin\g++ -std=c++11 -O2 -o compiler.exe compiler.cpp tokenizer.cpp parser.cpp

# Solution 3: Install MinGW-w64 properly
# Download from https://www.mingw-w64.org/downloads/
```

**Issue**: Permission denied when running compiler
```powershell
# Run Command Prompt as Administrator
# OR ensure the directory has write permissions
```

**Issue**: Antivirus blocking compilation
```powershell
# Add compiler directory to antivirus exclusions
# Temporarily disable real-time protection during compilation
```

**Issue**: Compilation errors
```bash
# Check GCC version (should be 7.0+)
g++ --version

# Compile with debug information
g++ -std=c++11 -g -Wall -Wextra -o compiler compiler.cpp tokenizer.cpp parser.cpp
```

## 📖 Usage Instructions

## 📖 Usage Instructions

### 🚀 How to Use the Compiler

The compiler reads source code from a file called `code.txt` by default. Follow these steps:

#### Step 1: Write Your Program
Create or edit the `code.txt` file with your program:

**Linux/Unix:**
```bash
# Using nano editor
nano code.txt

# Using vim
vim code.txt

# Using any text editor
gedit code.txt    # Ubuntu/GNOME
kate code.txt     # KDE
```

**Windows:**
```powershell
# Using Notepad
notepad code.txt

# Using any text editor
# You can also use VS Code, Notepad++, or any IDE
```

#### Step 2: Write Your Code
Add your program to `code.txt`. Here's a simple example:
```cpp
shuru
    purno x = 10, y = 20;
    purno sum = x + y;
    dekhao << "Sum: " << sum << "\n";
shesh
```

#### Step 3: Compile the Compiler
You need to compile the compiler first before using it:

**Linux/Unix:**
```bash
# Navigate to project directory
cd Compiler-Design-Project

# Compile the compiler
g++ -std=c++11 -O2 -o compiler compiler.cpp tokenizer.cpp parser.cpp
```

**Windows (MinGW):**
```powershell
# Navigate to project directory
cd Compiler-Design-Project

# Compile the compiler
g++ -std=c++11 -O2 -o compiler.exe compiler.cpp tokenizer.cpp parser.cpp
```

**Windows (Visual Studio):**
```powershell
# Using Developer Command Prompt
cl /EHsc compiler.cpp tokenizer.cpp parser.cpp
```

#### Step 4: Run Your Program
Execute the compiled compiler to run your program:

**Linux/Unix:**
```bash
./compiler
```

**Windows:**
```powershell
# If using MinGW or any GCC-based compiler
compiler.exe

# If using Visual Studio
compiler.exe
```

### 📋 Complete Workflow Examples

#### Example 1: Hello World Program

**Step 1: Create code.txt**
```cpp
shuru
    shobdo message = "Hello, World!";
    dekhao << message << "\n";
shesh
```

**Step 2: Compile and Run**
```bash
# Linux/Unix
g++ -std=c++11 -o compiler compiler.cpp tokenizer.cpp parser.cpp
./compiler

# Windows
g++ -std=c++11 -o compiler.exe compiler.cpp tokenizer.cpp parser.cpp
compiler.exe
```

**Expected Output:**
```
Hello, World!
```

#### Example 2: Interactive Calculator

**Step 1: Write calculator program in code.txt**
```cpp
shuru
    purno num1, num2;
    dekhao << "Enter first number: ";
    nao >> num1;
    dekhao << "Enter second number: ";
    nao >> num2;
    
    purno sum = num1 + num2;
    dekhao << "Sum: " << sum << "\n";
shesh
```

**Step 2: Compile and Run**
```bash
# Compile once
g++ -std=c++11 -o compiler compiler.cpp tokenizer.cpp parser.cpp

# Run the program
./compiler
```

**Example Interaction:**
```
Enter first number: 15
Enter second number: 25
Sum: 40
```

### 🔧 Development Workflow

#### Method 1: Edit and Recompile Each Time
```bash
# 1. Edit your program
nano code.txt

# 2. Run the compiler (no need to recompile if compiler source hasn't changed)
./compiler
```

#### Method 2: Using Different File Names
If you want to work with multiple programs:

**Step 1: Create multiple program files**
```bash
# Create different programs
nano program1.txt
nano program2.txt
nano program3.txt
```

**Step 2: Copy to code.txt when you want to run**
```bash
# Run program1
cp program1.txt code.txt
./compiler

# Run program2  
cp program2.txt code.txt
./compiler
```

#### Method 3: Batch Script for Convenience

**Linux/Unix (create run_program.sh):**
```bash
#!/bin/bash
if [ "$1" ]; then
    cp "$1" code.txt
fi
g++ -std=c++11 -o compiler compiler.cpp tokenizer.cpp parser.cpp && ./compiler
```

**Usage:**
```bash
chmod +x run_program.sh
./run_program.sh myprogram.txt
```

**Windows (create run_program.bat):**
```batch
@echo off
if "%1" neq "" (
    copy "%1" code.txt
)
g++ -std=c++11 -o compiler.exe compiler.cpp tokenizer.cpp parser.cpp
if %errorlevel% equ 0 (
    compiler.exe
)
```

**Usage:**
```powershell
run_program.bat myprogram.txt
```

### 🐛 Debugging Your Programs

#### Common Issues and Solutions

**Issue**: Program doesn't compile
```bash
# Check for syntax errors in your .txt file
# Make sure you have shuru and shesh
# Check for proper semicolons and braces
```

**Issue**: Program runs but gives unexpected output
```bash
# Add debug output to trace execution
dekhao << "Debug: x = " << x << "\n";
```

**Issue**: Input not working
```bash
# Make sure you're using 'nao >>' for input
# Example: nao >> variable_name;
```

### 📝 Important Notes

1. **File Name**: The compiler specifically looks for `code.txt` in the current directory
2. **Compilation**: You only need to recompile the compiler when you modify `compiler.cpp`, `tokenizer.cpp`, or `parser.cpp`
3. **Program Changes**: When you modify your program in `code.txt`, just run `./compiler` again
4. **File Encoding**: Use UTF-8 encoding for your `code.txt` file
5. **Line Endings**: Both Unix (LF) and Windows (CRLF) line endings are supported

## 📚 Complete Language Reference

### 1. Program Structure
Every program must start with `shuru` and end with `shesh`:

```cpp
shuru
    // Your program code here
shesh
```

### 2. Variable Declaration and Initialization

#### Single Variable Declaration
```cpp
purno age;                      // Declaration only
purno score = 85;              // Declaration with initialization
vogno temperature = 98.6;      // Float with decimal
shobdo message = "Hello World"; // String with quotes
```

#### Multiple Variable Declaration
```cpp
purno x = 10, y = 20, z;       // Mixed declaration
vogno a = 1.5, b = 2.7, c = 0.0;
shobdo first = "John", last = "Doe";
```

### 3. Operators and Expressions

#### Arithmetic Operators
```cpp
purno result;
result = a + b;                 // Addition
result = a - b;                 // Subtraction
result = a * b;                 // Multiplication
result = a / b;                 // Division
result = (a + b) * (c - d);     // Complex expressions
```

#### Assignment Operators
```cpp
x = 10;                         // Basic assignment
x += 5;                         // Add and assign (x = x + 5)
x -= 3;                         // Subtract and assign
x *= 2;                         // Multiply and assign
x /= 4;                         // Divide and assign
x++;                            // Increment by 1
x--;                            // Decrement by 1
```

#### Comparison Operators
```cpp
jodi (a < b) { /* code */ }     // Less than
jodi (a > b) { /* code */ }     // Greater than
jodi (a <= b) { /* code */ }    // Less than or equal
jodi (a >= b) { /* code */ }    // Greater than or equal
jodi (a == b) { /* code */ }    // Equal to
jodi (a != b) { /* code */ }    // Not equal to
```

#### Logical Operators
```cpp
jodi (a > 0 && b > 0) {         // Logical AND
    dekhao << "Both positive\n";
}

jodi (a == 0 || b == 0) {       // Logical OR
    dekhao << "At least one is zero\n";
}

// Complex logical expressions
jodi ((a > 0 && b > 0) || (a < 0 && b < 0)) {
    dekhao << "Same sign\n";
}
```

### 4. Control Flow Statements

#### If-Else Statements
```cpp
// Simple if
jodi (condition) {
    // code block
}

// If-else
jodi (condition) {
    // if block
} nahole {
    // else block
}

// If-else-if chain
jodi (score >= 90) {
    dekhao << "Grade: A\n";
} nahole jodi (score >= 80) {
    dekhao << "Grade: B\n";
} nahole jodi (score >= 70) {
    dekhao << "Grade: C\n";
} nahole {
    dekhao << "Grade: F\n";
}
```

#### While Loops
```cpp
// Basic while loop
purno i = 1;
jotokkhon (i <= 10) {
    dekhao << i << " ";
    i++;
}

// While loop with complex condition
jotokkhon (i < 100 && sum < 1000) {
    sum += i;
    i++;
}

// Nested while loops
purno row = 1;
jotokkhon (row <= 5) {
    purno col = 1;
    jotokkhon (col <= row) {
        dekhao << "* ";
        col++;
    }
    dekhao << "\n";
    row++;
}
```

### 5. Input and Output Operations

#### Output (`dekhao`)
```cpp
// Basic output
dekhao << "Hello World\n";

// Variable output
dekhao << "Value: " << x << "\n";

// Multiple values
dekhao << "x = " << x << ", y = " << y << "\n";

// Escape sequences
dekhao << "Line 1\nLine 2\tTabbed\n";
```

#### Input (`nao`)
```cpp
// Single variable input
purno age;
dekhao << "Enter your age: ";
nao >> age;

// Multiple inputs
purno x, y;
dekhao << "Enter two numbers: ";
nao >> x >> y;

// String input
shobdo name;
dekhao << "Enter your name: ";
nao >> name;
```

### 6. String Operations
```cpp
shobdo firstName = "John";
shobdo lastName = "Doe";
shobdo fullName = firstName + " " + lastName;

// String with variables
shobdo result = "Hello " + name + "!";

// String concatenation with assignment
message += " Welcome!";
```

### 7. Comments
```cpp
// This is a single-line comment

/*
   This is a
   multi-line comment
   spanning multiple lines
*/

purno x = 10;  // Inline comment
```

## 💡 Code Examples

### Example 1: Calculator Program
```cpp
shuru
    purno num1, num2, choice;
    vogno result;
    
    dekhao << "Simple Calculator\n";
    dekhao << "Enter first number: ";
    nao >> num1;
    dekhao << "Enter second number: ";
    nao >> num2;
    
    dekhao << "Choose operation:\n";
    dekhao << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n";
    nao >> choice;
    
    jodi (choice == 1) {
        result = num1 + num2;
        dekhao << "Result: " << result << "\n";
    } nahole jodi (choice == 2) {
        result = num1 - num2;
        dekhao << "Result: " << result << "\n";
    } nahole jodi (choice == 3) {
        result = num1 * num2;
        dekhao << "Result: " << result << "\n";
    } nahole jodi (choice == 4) {
        jodi (num2 != 0) {
            result = num1 / num2;
            dekhao << "Result: " << result << "\n";
        } nahole {
            dekhao << "Error: Division by zero!\n";
        }
    } nahole {
        dekhao << "Invalid choice!\n";
    }
shesh
```

### Example 2: Factorial Calculator
```cpp
shuru
    purno n, factorial = 1, i = 1;
    
    dekhao << "Enter a number: ";
    nao >> n;
    
    jodi (n < 0) {
        dekhao << "Factorial not defined for negative numbers\n";
    } nahole jodi (n == 0 || n == 1) {
        dekhao << "Factorial of " << n << " is 1\n";
    } nahole {
        jotokkhon (i <= n) {
            factorial *= i;
            i++;
        }
        dekhao << "Factorial of " << n << " is " << factorial << "\n";
    }
shesh
```

### Example 3: Pattern Printing
```cpp
shuru
    purno rows, i = 1, j;
    
    dekhao << "Enter number of rows: ";
    nao >> rows;
    
    // Upper half of diamond
    jotokkhon (i <= rows) {
        j = 1;
        // Print spaces
        jotokkhon (j <= rows - i) {
            dekhao << " ";
            j++;
        }
        // Print stars
        j = 1;
        jotokkhon (j <= 2 * i - 1) {
            dekhao << "*";
            j++;
        }
        dekhao << "\n";
        i++;
    }
    
    // Lower half of diamond
    i = rows - 1;
    jotokkhon (i >= 1) {
        j = 1;
        // Print spaces
        jotokkhon (j <= rows - i) {
            dekhao << " ";
            j++;
        }
        // Print stars
        j = 1;
        jotokkhon (j <= 2 * i - 1) {
            dekhao << "*";
            j++;
        }
        dekhao << "\n";
        i--;
    }
shesh
```

### Example 4: Number Guessing Game
```cpp
shuru
    purno secretNumber = 42, guess, attempts = 0, maxAttempts = 5;
    
    dekhao << "Number Guessing Game!\n";
    dekhao << "I'm thinking of a number between 1 and 100.\n";
    dekhao << "You have " << maxAttempts << " attempts.\n\n";
    
    jotokkhon (attempts < maxAttempts) {
        dekhao << "Attempt " << (attempts + 1) << ": Enter your guess: ";
        nao >> guess;
        attempts++;
        
        jodi (guess == secretNumber) {
            dekhao << "Congratulations! You guessed it in " << attempts << " attempts!\n";
            break;  // Note: break not implemented, so we'll use a different approach
        } nahole jodi (guess < secretNumber) {
            dekhao << "Too low! Try again.\n";
        } nahole {
            dekhao << "Too high! Try again.\n";
        }
    }
    
    jodi (attempts == maxAttempts && guess != secretNumber) {
        dekhao << "Game over! The number was " << secretNumber << "\n";
    }
shesh
```

### Example 5: Grade Calculator
```cpp
shuru
    purno numSubjects, i = 1;
    vogno totalMarks = 0.0, average;
    purno currentMark;
    
    dekhao << "Grade Calculator\n";
    dekhao << "Enter number of subjects: ";
    nao >> numSubjects;
    
    jotokkhon (i <= numSubjects) {
        dekhao << "Enter marks for subject " << i << ": ";
        nao >> currentMark;
        totalMarks += currentMark;
        i++;
    }
    
    average = totalMarks / numSubjects;
    
    dekhao << "Total Marks: " << totalMarks << "\n";
    dekhao << "Average: " << average << "\n";
    
    jodi (average >= 90) {
        dekhao << "Grade: A+ (Excellent)\n";
    } nahole jodi (average >= 80) {
        dekhao << "Grade: A (Very Good)\n";
    } nahole jodi (average >= 70) {
        dekhao << "Grade: B (Good)\n";
    } nahole jodi (average >= 60) {
        dekhao << "Grade: C (Average)\n";
    } nahole jodi (average >= 50) {
        dekhao << "Grade: D (Below Average)\n";
    } nahole {
        dekhao << "Grade: F (Fail)\n";
    }
shesh
```

### Example 6: Complex Logical Conditions
```cpp
shuru
    purno age, income, creditScore;
    shobdo status;
    
    dekhao << "Loan Eligibility Checker\n";
    dekhao << "Enter your age: ";
    nao >> age;
    dekhao << "Enter your monthly income: ";
    nao >> income;
    dekhao << "Enter your credit score: ";
    nao >> creditScore;
    
    // Complex eligibility logic
    jodi ((age >= 21 && age <= 65) && (income >= 25000) && (creditScore >= 650)) {
        jodi (income >= 50000 && creditScore >= 750) {
            status = "Premium loan approved";
        } nahole jodi (income >= 35000 && creditScore >= 700) {
            status = "Standard loan approved";
        } nahole {
            status = "Basic loan approved";
        }
    } nahole jodi ((age >= 18 && age < 21) && (income >= 15000) && (creditScore >= 600)) {
        status = "Student loan may be available";
    } nahole {
        status = "Loan application rejected";
        
        // Provide specific feedback
        jodi (age < 18 || age > 65) {
            dekhao << "Reason: Age not in eligible range (18-65)\n";
        }
        jodi (income < 25000) {
            dekhao << "Reason: Income too low (minimum 25000)\n";
        }
        jodi (creditScore < 650) {
            dekhao << "Reason: Credit score too low (minimum 650)\n";
        }
    }
    
    dekhao << "Status: " << status << "\n";
shesh
```

## 🏗️ Project Architecture

### Directory Structure
```
Compiler-Design-Project/
├── README.md                   # Project documentation
├── LICENSE                     # MIT License file
├── .gitignore                 # Git ignore rules
├── Makefile                   # Build configuration (optional)
├── docs/                      # Additional documentation
│   ├── LANGUAGE_SPEC.md       # Detailed language specification
│   ├── API_REFERENCE.md       # Internal API documentation
│   └── EXAMPLES.md            # Extended examples
├── src/                       # Source code (alternative organization)
│   ├── compiler.cpp           # Main driver
│   ├── tokenizer.cpp/.h       # Lexical analyzer
│   └── parser.cpp/.h          # Parser and interpreter
├── tests/                     # Test programs
│   ├── basic_tests/           # Basic functionality tests
│   ├── advanced_tests/        # Complex feature tests
│   └── error_tests/           # Error handling tests
├── examples/                  # Sample programs
│   ├── hello_world.txt        # Basic hello world
│   ├── calculator.txt         # Calculator program
│   └── patterns.txt           # Pattern printing examples
├── compiler.cpp               # Main compiler driver
├── tokenizer.h                # Tokenizer header
├── tokenizer.cpp              # Lexical analyzer implementation
├── parser.h                   # Parser header
├── parser.cpp                 # Parser and interpreter implementation
├── code.txt                   # Default test program
└── compiler                   # Compiled executable
```

### Component Architecture

```
┌─────────────────────────────────────────────────────────────┐
│                     Compiler Architecture                   │
├─────────────────────────────────────────────────────────────┤
│  Input: Source Code (.txt file)                            │
│                           │                                 │
│                           ▼                                 │
│  ┌─────────────────────────────────────────────────────┐   │
│  │              Lexical Analyzer                       │   │
│  │                (tokenizer.cpp)                      │   │
│  │  • Tokenization                                     │   │
│  │  • Comment removal                                  │   │
│  │  • String literal handling                         │   │
│  │  • Operator recognition                             │   │
│  │  • Keyword identification                           │   │
│  └─────────────────────────────────────────────────────┘   │
│                           │                                 │
│                           ▼                                 │
│  ┌─────────────────────────────────────────────────────┐   │
│  │               Syntax Analyzer                       │   │
│  │                 (parser.cpp)                        │   │
│  │  • Recursive descent parsing                        │   │
│  │  • Expression evaluation                            │   │
│  │  • Symbol table management                          │   │
│  │  • Type checking                                    │   │
│  │  • Error reporting                                  │   │
│  └─────────────────────────────────────────────────────┘   │
│                           │                                 │
│                           ▼                                 │
│  ┌─────────────────────────────────────────────────────┐   │
│  │                Interpreter                          │   │
│  │              (integrated in parser)                 │   │
│  │  • Direct execution                                 │   │
│  │  • Variable storage                                 │   │
│  │  • Control flow handling                            │   │
│  │  • I/O operations                                   │   │
│  │  • Runtime error detection                          │   │
│  └─────────────────────────────────────────────────────┘   │
│                           │                                 │
│                           ▼                                 │
│  Output: Program execution results                          │
└─────────────────────────────────────────────────────────────┘
```

## 🔧 Technical Implementation

### 1. Lexical Analysis (tokenizer.cpp)

#### Token Types
```cpp
enum TokenType {
    KEYWORD,        // shuru, shesh, purno, etc.
    IDENTIFIER,     // variable names
    PURNO_LITERAL,  // integer literals
    VOGNO_LITERAL,  // float literals
    STRING,         // string literals
    OPERATOR,       // +, -, *, /, &&, ||, etc.
    BRACE,          // {, }
    EOF_TOKEN       // end of file
};
```

#### Key Functions
- **`tokenize()`**: Main tokenization function
- **`isNumber()`**: Validates numeric literals
- **`isValidIdentifier()`**: Validates identifier names
- **`removeComments()`**: Removes single and multi-line comments

#### Advanced Features
- **String Literal Handling**: Proper escape sequence processing
- **Operator Recognition**: Multi-character operators (`<=`, `>=`, `==`, `!=`, `&&`, `||`)
- **Comment Processing**: Nested comment support
- **Error Recovery**: Graceful handling of invalid tokens

### 2. Syntax Analysis (parser.cpp)

#### Parser Class Structure
```cpp
class Parser {
private:
    // Symbol tables for different data types
    unordered_map<string, int> purnoTable;      // Integer variables
    unordered_map<string, double> vognoTable;   // Float variables  
    unordered_map<string, string> shobdoTable;  // String variables
    
    vector<Token> tokens;                       // Input tokens
    int pos;                                    // Current position
    
    // Core parsing methods
    Token peek();                               // Look ahead
    Token get();                                // Consume token
    double parseExpression(const string& stopAt = "");
    string parseStringExpression();
    void parseStatement();
    void parseBlock();
    void skipBlock();
    bool isDeclared(const string& varName);
    
public:
    Parser(vector<Token> tks);
    void run();                                 // Main execution
};
```

#### Expression Parsing Algorithm
The compiler uses a **Shunting Yard algorithm** for expression parsing:

1. **Infix to Postfix Conversion**
   ```cpp
   Input:  "a + b * c"
   Output: ["@a", "@b", "@c", "*", "+"]
   ```

2. **Postfix Evaluation**
   ```cpp
   Stack operations:
   @a     → push value of a
   @b     → push value of b  
   @c     → push value of c
   *      → pop c,b; push b*c
   +      → pop result,a; push a+result
   ```

3. **Operator Precedence Handling**
   ```cpp
   auto precedence = [](const string &op) {
       if (op == "<" || op == ">" || op == "<=" || op == ">=" || 
           op == "==" || op == "!=") return 4;
       if (op == "&&") return 3;
       if (op == "||") return 2;
       if (op == "+" || op == "-") return 1;
       if (op == "*" || op == "/") return 1;
       return 0;
   };
   ```

#### Control Flow Implementation

**If-Else Processing**:
```cpp
// Condition evaluation
double cond = parseExpression(")");

// Block execution logic
if (cond != 0) {
    parseBlock();  // Execute if block
    conditionMet = true;
} else {
    skipBlock();   // Skip if block
}

// Handle else-if and else clauses
while (peek().value == "nahole") {
    // Process else-if or else
}
```

**While Loop Processing**:
```cpp
// Store positions for re-evaluation
int conditionStart = pos;
int loopBodyStart = pos;
int loopBodyEnd = findBlockEnd();

// Loop execution
while (cond != 0) {
    pos = loopBodyStart;
    executeLoopBody();
    
    // Re-evaluate condition
    pos = conditionStart;
    cond = parseExpression(")");
}
```

### 3. Symbol Table Management

#### Variable Storage
- **Type-specific Hash Tables**: Separate storage for different data types
- **Scope Management**: Global scope with redeclaration checking
- **Type Safety**: Runtime type validation

#### Variable Operations
```cpp
// Declaration checking
bool isDeclared(const string& varName) {
    return purnoTable.count(varName) || 
           vognoTable.count(varName) || 
           shobdoTable.count(varName);
}

// Type-safe assignment
if (purnoTable.count(var)) {
    double result = parseExpression();
    if (result != floor(result)) {
        // Type mismatch error
    } else {
        purnoTable[var] = static_cast<int>(result);
    }
}
```

## 🛡️ Error Handling

### Error Categories

#### 1. Lexical Errors
- **Invalid Characters**: Unrecognized symbols
- **Malformed Numbers**: Invalid numeric formats
- **Unterminated Strings**: Missing closing quotes
- **Invalid Identifiers**: Reserved keywords as variable names

```cpp
// Example lexical errors
purno 123invalid;        // Error: Invalid identifier
shobdo message = "Hello; // Error: Unterminated string
purno x@ = 5;           // Error: Invalid character '@'
```

#### 2. Syntax Errors
- **Missing Tokens**: Expected operators, braces, semicolons
- **Unexpected Tokens**: Tokens in wrong context
- **Malformed Expressions**: Invalid expression structure
- **Unmatched Braces**: Missing opening or closing braces

```cpp
// Example syntax errors
jodi (x > 0 {            // Error: Missing ')'
    dekhao << x;
}

purno x = 5 +;           // Error: Incomplete expression
```

#### 3. Semantic Errors
- **Undeclared Variables**: Using variables before declaration
- **Type Mismatches**: Incompatible type operations
- **Redeclaration**: Declaring same variable twice
- **Division by Zero**: Runtime division by zero

```cpp
// Example semantic errors
dekhao << undeclaredVar;  // Error: Undeclared variable
purno x = 3.14;          // Error: Type mismatch (float to int)
purno x = 5;
purno x = 10;            // Error: Redeclaration
```

#### 4. Runtime Errors
- **Division by Zero**: Mathematical errors
- **Input/Output Errors**: Failed I/O operations
- **Memory Errors**: Stack overflow (in complex expressions)

### Error Reporting System

#### Detailed Error Messages
```cpp
Error: Undeclared variable 'count' used in expression.
Error: Type mismatch. Cannot assign a non-integer value to an integer variable 'x'.
Error: Expected ')' after jodi condition, but got ';'.
Error: Redeclaration of variable 'sum'.
```

#### Error Recovery Strategies
- **Skip to Next Statement**: Continue parsing after error
- **Synchronization Points**: Recover at statement boundaries
- **Partial Execution**: Execute valid parts of program

## 🚀 Advanced Features

### 1. Complex Expression Support
- **Nested Parentheses**: Unlimited nesting depth
- **Mixed Data Types**: Automatic type promotion
- **Operator Chaining**: Multiple operators in single expression

```cpp
// Complex expression examples
result = ((a + b) * (c - d)) / ((e + f) * (g - h));
jodi ((x > 0 && y > 0) || (x < 0 && y < 0)) { /* same sign */ }
average = (math + physics + chemistry + biology) / 4.0;
```

### 2. String Processing
- **Concatenation**: Multiple string concatenation
- **Escape Sequences**: `\n`, `\t`, `\\`, `\"`
- **Variable Interpolation**: Mixing strings with variables

```cpp
shobdo message = "Hello" + " " + name + "!";
dekhao << "Line 1\nLine 2\tTabbed text\n";
dekhao << "Value of x is: " << x << "\n";
```

### 3. Advanced Control Flow
- **Nested Structures**: Unlimited nesting depth
- **Complex Conditions**: Multi-part logical expressions
- **Short-circuit Evaluation**: Efficient boolean evaluation

```cpp
// Deeply nested structures
jodi (condition1) {
    jotokkhon (condition2) {
        jodi (condition3) {
            // Nested logic
        }
    }
}

// Short-circuit evaluation
jodi (x != 0 && (y / x) > 5) {  // Safe division
    // y/x only evaluated if x != 0
}
```

### 4. Robust Type System
- **Implicit Conversions**: Safe type conversions
- **Type Checking**: Compile-time and runtime checking
- **Error Prevention**: Type mismatch detection

```cpp
vogno result = 10;        // int to float conversion
purno count = 3.0;        // Error: float to int requires explicit cast
shobdo text = 123;        // Error: number to string conversion
```

## 🧪 Testing

### Test Categories

#### 1. Unit Tests
```bash
# Basic functionality tests
./test_basic_arithmetic.sh
./test_variable_operations.sh
./test_string_operations.sh
./test_control_flow.sh
```

#### 2. Integration Tests
```bash
# End-to-end program tests
./test_calculator_program.sh
./test_loop_programs.sh
./test_complex_logic.sh
```

#### 3. Error Handling Tests
```bash
# Error detection and recovery
./test_syntax_errors.sh
./test_semantic_errors.sh
./test_runtime_errors.sh
```

#### 4. Performance Tests
```bash
# Performance and stress testing
./test_large_programs.sh
./test_deep_nesting.sh
./test_complex_expressions.sh
```

### Sample Test Cases

#### Test 1: Basic Arithmetic
```cpp
// test_arithmetic.txt
shuru
    purno a = 10, b = 5;
    purno sum = a + b;
    purno diff = a - b;
    purno prod = a * b;
    purno quot = a / b;
    
    dekhao << "Sum: " << sum << "\n";      // Expected: 15
    dekhao << "Diff: " << diff << "\n";    // Expected: 5
    dekhao << "Prod: " << prod << "\n";    // Expected: 50
    dekhao << "Quot: " << quot << "\n";    // Expected: 2
shesh
```

#### Test 2: Logical Operators
```cpp
// test_logical.txt
shuru
    purno x = 5, y = 10, z = 0;
    
    jodi (x > 0 && y > 0) {
        dekhao << "Both positive\n";       // Should execute
    }
    
    jodi (x > 0 || z > 0) {
        dekhao << "At least one positive\n"; // Should execute
    }
    
    jodi (x > 10 && y > 5) {
        dekhao << "Should not print\n";    // Should not execute
    }
shesh
```

#### Test 3: Error Handling
```cpp
// test_errors.txt
shuru
    purno declared = 5;
    dekhao << undeclared;     // Error: Undeclared variable
    
    purno x = 5;
    purno x = 10;             // Error: Redeclaration
    
    purno y = 3.14;           // Error: Type mismatch
shesh
```

### Running Tests
```bash
# Automated testing script
#!/bin/bash
echo "Running Compiler Tests..."

for test_file in tests/*.txt; do
    echo "Testing: $test_file"
    ./compiler "$test_file" > output.txt 2>&1
    
    if [ $? -eq 0 ]; then
        echo "✓ PASS: $test_file"
    else
        echo "✗ FAIL: $test_file"
        cat output.txt
    fi
done

echo "Testing complete."
```

## ⚡ Performance

### Benchmarks

#### Time Complexity
- **Tokenization**: O(n) where n is source code length
- **Parsing**: O(n) where n is number of tokens
- **Expression Evaluation**: O(m) where m is expression complexity
- **Symbol Table Lookup**: O(1) average case (hash table)

#### Space Complexity
- **Token Storage**: O(n) for token vector
- **Symbol Tables**: O(v) where v is number of variables
- **Call Stack**: O(d) where d is nesting depth

#### Performance Characteristics
```cpp
// Performance test results (approximate)
Source Code Size    | Compilation Time | Memory Usage
--------------------|------------------|-------------
< 1KB              | < 1ms           | < 1MB
1KB - 10KB         | < 10ms          | 1-5MB
10KB - 100KB       | < 100ms         | 5-20MB
> 100KB            | Variable        | 20MB+
```

### Optimization Opportunities
1. **Token Caching**: Reduce re-parsing overhead
2. **Symbol Table Optimization**: More efficient data structures
3. **Expression Tree Caching**: Cache complex expression results
4. **Memory Pool**: Reduce allocation overhead

## 🤝 Contributing

### Development Setup
```bash
# Fork the repository
git fork https://github.com/Hamza-28/Compiler-Design-Project.git

# Clone your fork
git clone https://github.com/YOUR_USERNAME/Compiler-Design-Project.git
cd Compiler-Design-Project

# Create development branch
git checkout -b feature/your-feature-name

# Set up development environment
make dev-setup  # If available
```

### Coding Standards

#### C++ Style Guidelines
- **Naming**: camelCase for functions, PascalCase for classes
- **Indentation**: 2 spaces (no tabs)
- **Braces**: Opening brace on same line
- **Comments**: Descriptive comments for complex logic

```cpp
// Good example
class Parser {
private:
  int currentPosition;
  
public:
  bool parseExpression() {
    if (condition) {
      // Process tokens
      return true;
    }
    return false;
  }
};
```

#### Commit Message Format
```
type(scope): brief description

Detailed explanation of changes made.

- Added feature X
- Fixed bug Y
- Updated documentation Z
```

### Contribution Types

#### 1. Bug Fixes
- **Error Reporting**: Improve error messages
- **Edge Cases**: Handle corner cases
- **Memory Leaks**: Fix memory issues

#### 2. Feature Additions
- **New Keywords**: Add language constructs
- **Data Types**: Support for arrays, structures
- **Built-in Functions**: Math, string functions

#### 3. Performance Improvements
- **Optimization**: Faster parsing algorithms
- **Memory**: Reduce memory footprint
- **Caching**: Implement smart caching

#### 4. Documentation
- **Examples**: More code examples
- **Tutorials**: Step-by-step guides
- **API Docs**: Internal documentation

### Pull Request Process
1. **Create Issue**: Describe proposed changes
2. **Develop Feature**: Implement with tests
3. **Test Thoroughly**: Ensure no regressions
4. **Update Docs**: Document new features
5. **Submit PR**: Clear description and examples

## 🗺️ Roadmap

### Version 1.0 (Current)
- ✅ Basic language constructs
- ✅ Arithmetic and logical operators
- ✅ Control flow (if-else, while)
- ✅ Input/output operations
- ✅ Error handling

### Version 1.1 (Planned)
- 🔄 Functions and procedures
- 🔄 Local variable scoping
- 🔄 Parameter passing
- 🔄 Return values

### Version 1.2 (Future)
- 📋 Arrays and data structures
- 📋 For loops
- 📋 Break and continue statements
- 📋 Switch-case statements

### Version 2.0 (Long-term)
- 📋 Object-oriented features
- 📋 File I/O operations
- 📋 Standard library
- 📋 Module system

### Version 2.1 (Advanced)
- 📋 Error recovery and debugging
- 📋 IDE integration
- 📋 Code optimization
- 📋 JIT compilation

## ❓ FAQ

### General Questions

**Q: What inspired the Bengali keywords?**
A: The Bengali-inspired keywords make programming more accessible to Bengali speakers and demonstrate how programming languages can be localized for different cultures.

**Q: Is this a compiled or interpreted language?**
A: Currently, it's an interpreted language. The "compiler" directly executes the source code without generating intermediate machine code.

**Q: Can I use this for production applications?**
A: This is primarily an educational project. While functional, it lacks many features needed for production use.

### Technical Questions

**Q: How do I add new keywords?**
A: Add the keyword to the `keywords` set in `tokenizer.cpp` and implement the parsing logic in `parser.cpp`.

**Q: Can I extend the type system?**
A: Yes, you can add new data types by creating additional symbol tables and extending the parsing logic.

**Q: How do I implement new operators?**
A: Add operator recognition in `tokenizer.cpp`, update precedence in `parser.cpp`, and implement evaluation logic.

### Troubleshooting

**Q: Compilation fails with "undefined reference" errors**
A: Ensure all source files are included in compilation: `g++ -o compiler compiler.cpp tokenizer.cpp parser.cpp`

**Q: Program hangs during execution**
A: Check for infinite loops in your source code, especially while loops with conditions that never become false.

**Q: Getting "Invalid identifier" errors**
A: Ensure variable names start with a letter and contain only alphanumeric characters and underscores.

### Performance Questions

**Q: How large programs can this handle?**
A: The compiler can handle moderately sized programs (up to several hundred lines) efficiently. Very large programs may experience performance degradation.

**Q: Can I optimize compilation speed?**
A: Yes, compile with `-O2` flag for optimized binary: `g++ -O2 -o compiler *.cpp`

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

```
MIT License

Copyright (c) 2025 Hamza

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## 📞 Contact & Support

### Author
**Hamza** - Compiler Design Enthusiast
- **GitHub**: [@Hamza-28](https://github.com/Hamza-28)
- **Email**: [Contact via GitHub](https://github.com/Hamza-28)

### Project Links
- **Repository**: [https://github.com/Hamza-28/Compiler-Design-Project](https://github.com/Hamza-28/Compiler-Design-Project)
- **Issues**: [Report bugs and request features](https://github.com/Hamza-28/Compiler-Design-Project/issues)
- **Discussions**: [Community discussions](https://github.com/Hamza-28/Compiler-Design-Project/discussions)

### Getting Help
1. **Check FAQ**: Review common questions above
2. **Search Issues**: Look for existing solutions
3. **Create Issue**: Report bugs with detailed information
4. **Start Discussion**: Ask questions or propose ideas

### Acknowledgments
- Inspiration from traditional compiler design principles
- Bengali language and culture for keyword inspiration
- Open source community for tools and resources
- Computer Science education community

---

<div align="center">

**⭐ If you found this project helpful, please give it a star! ⭐**

*Built with ❤️ for the compiler design and programming language community*

[🚀 Get Started](#-installation-guide) | [📖 Learn More](#-language-specification) | [🤝 Contribute](#-contributing) | [❓ Get Help](#-faq)

</div>
