# Custom Programming Language Compiler

A custom programming language compiler built in C++ featuring Bengali-inspired keywords and comprehensive language constructs including variables, control flow, logical operators, and I/O operations.

## 📋 Table of Contents
- [Features](#features)
- [Language Syntax](#language-syntax)
- [Installation](#installation)
- [Usage](#usage)
- [Code Examples](#code-examples)
- [Project Structure](#project-structure)
- [Technical Implementation](#technical-implementation)
- [Contributing](#contributing)

## ✨ Features

### Core Language Features
- **Multiple Data Types**: Integers (`purno`), Floats (`vogno`), Strings (`shobdo`)
- **Variable Declaration & Assignment**: Support for multiple variable declaration and initialization
- **Arithmetic Operations**: `+`, `-`, `*`, `/`, `+=`, `-=`, `*=`, `/=`, `++`, `--`
- **Comparison Operators**: `<`, `>`, `<=`, `>=`, `==`, `!=`
- **Logical Operators**: `&&` (AND), `||` (OR)
- **Control Flow**: If-else statements with else-if chaining, while loops
- **Input/Output**: Console input and output with string formatting
- **Comments**: Single-line (`//`) and multi-line (`/* */`) comment support
- **Error Handling**: Comprehensive error reporting with type checking

### Advanced Features
- **Expression Parser**: Unified expression parsing with proper operator precedence
- **Nested Control Structures**: Support for nested if-else and while loops
- **Complex Conditions**: Multi-condition expressions with logical operators
- **String Concatenation**: String manipulation and concatenation
- **Type Safety**: Runtime type checking and error reporting

## 🔤 Language Syntax

### Keywords
- `shuru` - Program start (equivalent to `main()`)
- `shesh` - Program end
- `purno` - Integer variable declaration
- `vogno` - Float variable declaration  
- `shobdo` - String variable declaration
- `jodi` - If statement
- `nahole` - Else statement
- `nahole jodi` - Else if statement
- `jotokkhon` - While loop
- `dekhao` - Output statement (like `cout`)
- `nao` - Input statement (like `cin`)

### Basic Syntax Structure
```cpp
shuru
    // Variable declarations
    purno x = 10, y = 20;
    vogno pi = 3.14159;
    shobdo name = "Hello World";
    
    // Conditional statements
    jodi (x < y && x != 0) {
        dekhao << "x is less than y and not zero\n";
    } nahole jodi (x == y) {
        dekhao << "x equals y\n";
    } nahole {
        dekhao << "x is greater than y\n";
    }
    
    // While loops
    jotokkhon (x <= y) {
        dekhao << "x = " << x << "\n";
        x++;
    }
    
    // Input/Output
    nao >> x;
    dekhao << "You entered: " << x << "\n";
shesh
```

## 🚀 Installation

### Prerequisites
- GCC compiler (g++)
- Linux/Unix environment (tested on Ubuntu)
- Make (optional)

### Compilation
```bash
# Clone the repository
git clone https://github.com/Hamza-28/Compiler-Design-Project.git
cd Compiler-Design-Project

# Compile the compiler
g++ -o compiler compiler.cpp tokenizer.cpp parser.cpp

# Make it executable (if needed)
chmod +x compiler
```

## 📖 Usage

### Running Programs
1. Write your program in a text file (e.g., `code.txt`)
2. Execute the compiler:
```bash
./compiler
```

The compiler reads from `code.txt` by default. You can modify the source file in `compiler.cpp` to specify different input files.

### Example Workflow
```bash
# Edit your program
nano code.txt

# Compile and run
g++ -o compiler compiler.cpp tokenizer.cpp parser.cpp && ./compiler
```

## 💡 Code Examples

### 1. Variable Operations
```cpp
shuru
    purno a = 5, b = 10;
    vogno result = 0.0;
    
    result = (a + b) * 2.5;
    dekhao << "Result: " << result << "\n";
    
    a += 5;
    b *= 2;
    dekhao << "a = " << a << ", b = " << b << "\n";
shesh
```

### 2. Complex Conditionals
```cpp
shuru
    purno score = 85;
    purno attendance = 90;
    
    jodi (score >= 80 && attendance >= 85) {
        dekhao << "Grade: A\n";
    } nahole jodi (score >= 70 || attendance >= 90) {
        dekhao << "Grade: B\n";
    } nahole {
        dekhao << "Grade: C\n";
    }
shesh
```

### 3. Nested Loops
```cpp
shuru
    purno i = 1, j = 1;
    
    jotokkhon (i <= 3) {
        j = 1;
        jotokkhon (j <= 3) {
            dekhao << i << "x" << j << "=" << (i*j) << " ";
            j++;
        }
        dekhao << "\n";
        i++;
    }
shesh
```

### 4. String Manipulation
```cpp
shuru
    shobdo firstName = "John";
    shobdo lastName = "Doe";
    shobdo fullName = firstName + " " + lastName;
    
    dekhao << "Full name: " << fullName << "\n";
shesh
```

### 5. Interactive Input
```cpp
shuru
    purno age;
    shobdo name;
    
    dekhao << "Enter your name: ";
    nao >> name;
    dekhao << "Enter your age: ";
    nao >> age;
    
    jodi (age >= 18) {
        dekhao << "Hello " << name << ", you are an adult!\n";
    } nahole {
        dekhao << "Hello " << name << ", you are a minor!\n";
    }
shesh
```

## 📁 Project Structure

```
Compiler-Design-Project/
├── README.md              # Project documentation
├── compiler.cpp           # Main compiler driver
├── tokenizer.h            # Tokenizer header file
├── tokenizer.cpp          # Lexical analyzer implementation
├── parser.h               # Parser header file  
├── parser.cpp             # Parser and interpreter implementation
├── code.txt               # Sample program file
├── compiler               # Compiled executable
└── .gitignore            # Git ignore file
```

### File Descriptions

- **`compiler.cpp`**: Main driver that reads source code and orchestrates compilation
- **`tokenizer.cpp/.h`**: Lexical analyzer that converts source code into tokens
- **`parser.cpp/.h`**: Parser that builds AST and interprets/executes the program
- **`code.txt`**: Sample source code file in the custom language

## 🔧 Technical Implementation

### Architecture
The compiler follows a traditional 3-phase design:

1. **Lexical Analysis (Tokenizer)**
   - Converts source code into tokens
   - Handles keywords, operators, literals, identifiers
   - Supports comments and string literals
   - Error reporting for invalid tokens

2. **Syntax Analysis (Parser)**
   - Recursive descent parser
   - Builds and evaluates Abstract Syntax Tree (AST)
   - Implements operator precedence
   - Type checking and error handling

3. **Interpretation/Execution**
   - Direct interpretation without intermediate code generation
   - Symbol table management for variables
   - Runtime error detection

### Key Components

#### Expression Parser
- **Unified Expression Parsing**: Single function handles all expressions
- **Operator Precedence**: Proper mathematical and logical operator precedence
- **Postfix Evaluation**: Uses Shunting Yard algorithm for expression evaluation

#### Control Flow
- **Conditional Statements**: Support for if-else-if chains
- **Loop Structures**: While loops with complex conditions
- **Nested Structures**: Proper handling of nested control blocks

#### Symbol Table Management
- **Type-specific Tables**: Separate tables for integers, floats, and strings
- **Scope Management**: Variable declaration and redeclaration checking
- **Type Safety**: Runtime type checking and conversion

### Expression Precedence
1. **Comparison Operators** (`<`, `>`, `<=`, `>=`, `==`, `!=`) - Level 4
2. **Logical AND** (`&&`) - Level 3  
3. **Logical OR** (`||`) - Level 2
4. **Arithmetic Operators** (`+`, `-`, `*`, `/`) - Level 1

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Development Guidelines
- Follow existing code style and conventions
- Add comprehensive test cases for new features
- Update documentation for any syntax changes
- Ensure backward compatibility when possible

## 📝 License

This project is open source and available under the [MIT License](LICENSE).

## 🚧 Future Enhancements

- [ ] Functions and procedures
- [ ] Arrays and data structures  
- [ ] File I/O operations
- [ ] Error recovery in parser
- [ ] Optimization passes
- [ ] IDE integration
- [ ] Debugging support
- [ ] Standard library functions

## 📞 Contact

**Hamza** - [GitHub](https://github.com/Hamza-28)

**Project Link**: [https://github.com/Hamza-28/Compiler-Design-Project](https://github.com/Hamza-28/Compiler-Design-Project)

---

*Built with ❤️ as a Compiler Design project*
