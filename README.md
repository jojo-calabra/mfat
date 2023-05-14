# MFAT 🪷

MFAT — My Friend and Teacher is a free & open-source (FOSS) application, designed to make learning more entertaining and effective.

It was created out of a struggle to prepare for our final exams properly while getting feedback on our performance and hints about where we could improve, without totally hoging all of the schools/teachers resources.

In simple terms this program lets you take training drills and generates detailed statistics about your performance.

<p align="center">
<!--   <a href="https://badgen.net/github/merged-prs/jojo-calabra/mfat"><img src="https://github.com/jojo-calabra/mfat/pulls?q=is%3Amerged"></a> -->
  <a href="https://GitHub.com/jojo-calabra/mfat/graphs/contributors/"><img src="https://img.shields.io/github/contributors/jojo-calabra/mfat.svg"></a>
  <a href="https://github.com/jojo-calabra/mfat/issues"><img src="https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat"></a>
  <a href="https://hits.dwyl.com/jojo-calabra/mfat"><img src="https://hits.dwyl.com/jojo-calabra/mfat.svg"></a>
  <a href="https://github.com/jojo-calabra/mfat"><img src="https://img.shields.io/github/stars/jojo-calabra/mfat?label=github%20stars"></a>
  <a href="https://github.com/airbytehq/airbyte/releases" target="_blank"><img src="https://img.shields.io/github/v/release/jojo-calabra/mfat?color=white" alt="Release"></a>
  <a href="https://www.gnu.org/licenses/gpl-3.0"><img src="https://img.shields.io/badge/License-GPLv3-blue.svg"></a>
</p>

# News 
![Courses page wireframe draft](https://github.com/jojo-calabra/mfat/blob/main/doc/UI/MFAT%20Wireframe%20%E2%80%94%20Courses.jpg)

![MFAT DB ERD draft](https://github.com/jojo-calabra/mfat/blob/main/doc/UML/ERDDiagram1.jpg)

# Environment

<p align="center">
  <a href=""><img src="https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white"></a>
<!--   <a href=""><img src="https://img.shields.io/badge/kubernetes-%23326ce5.svg?style=for-the-badge&logo=kubernetes&logoColor=white"></a> -->
  <a href=""><img src="https://img.shields.io/badge/docker-%230db7ed.svg?style=for-the-badge&logo=docker&logoColor=white"></a>
  <a href=""><img src="https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white"></a>
  <a href=""><img src="https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white"></a>
  <a href=""><img src="https://img.shields.io/badge/go-%2300ADD8.svg?style=for-the-badge&logo=go&logoColor=white"></a>
  <a href=""><img src="https://img.shields.io/badge/NPM-%23CB3837.svg?style=for-the-badge&logo=npm&logoColor=white"></a>
  <a href=""><img src="https://img.shields.io/badge/vite-%23646CFF.svg?style=for-the-badge&logo=vite&logoColor=white"></a>
  <a href=""><img src="https://img.shields.io/badge/vuejs-%2335495e.svg?style=for-the-badge&logo=vuedotjs&logoColor=%234FC08D"></a>
  <a href=""><img src="https://img.shields.io/badge/typescript-%23007ACC.svg?style=for-the-badge&logo=typescript&logoColor=white"></a>
<!--   <a href=""><img src="https://img.shields.io/badge/threejs-black?style=for-the-badge&logo=three.js&logoColor=white"></a> -->
</p>
  
  
# Development Schedule (Estimates)

IMPORTANT — THIS PROGRAM IS STILL IN A VERY EARLY STAGE OF DEVELOPMENT. PLEASE LET US KNOW ABOUT ANY BUGS OR MISSING FEATURES THAT YOU WOULD LIKE TO BE ADDED, IN OUR [ISSUES](https://github.com/jojo-calabra/mfat/issues) PAGE.

![Gantt Chart with Work Breakdown Structure](https://github.com/jojo-calabra/mfat/blob/main/Images/MFAT%20Gantt%20Chart%20with%20work%20breakdown%20structure.pdf.png)


# Core Principles

The core principles for the applied learning methods are:
- Learning by doing
- Problem Solving / Pattern Recognition
- Collaborative and cooperative learning
- Selection of subject content based on individual performance history
- Digital Learning (or ICT Enabled Learning) / Multimedia Approach & Visual clues
- Spaced Repetition Learning
- Reward discovery / Reinforcement Learning
- Memory Learning / Memorizing

We want to help our classmates learn better and give them the feeling of being rewarded and appreciated for investing time to learn.
We noticed that our classes grades strongly depend on student motivation and wether or not we were given opportunities to apply the lessons learned to a problem.

# Further resources

If you're asking yourself "What were those guys thinking about when creating this cool application?" here's a list of sources:

- [Wikipedia — Progressive Education](https://en.wikipedia.org/wiki/Progressive_education)
- [Wikipedia — Learning-by-doing](https://en.wikipedia.org/wiki/Learning-by-doing)
- [Wikipedia — Spaced Repetition](https://en.wikipedia.org/wiki/Spaced_repetition)
- [Wikipedia — E Learning (Digital Learning)](https://en.wikipedia.org/wiki/E-learning_(theory))
- [Wikipedia — Reinforcement Learning](https://en.wikipedia.org/wiki/Reinforcement_learning)
- [Wikipedia — Reward System](https://en.wikipedia.org/wiki/Reward_system)
- [Wikipedia — Motivation](https://en.wikipedia.org/wiki/Motivation)

[Let us know ](https://github.com/jojo-calabra/mfat/issues) if any of these links stopped working!


# Libraries used and special thanks

We support and use these projects. 
You know what to do: Check them out and give their repositories a star, the y deserve it

First of all we use a large set of crow http functions, so thanks to the crow team for developing an amazing library!
https://github.com/CrowCpp/Crow


# Security Policy for Production-Ready code 🛡️

🚀 Stay safe and report any incidents or recommendations to the core team. If you should feel that these measures are unwarranted, open a new issue and let us know about it. 🚀

## Encryption Policy 🔒

To maintain the confidentiality and integrity of our data, it is critical that we adhere to a strict encryption policy. Here are the guidelines that we should follow:

- Choice of Algorithms
- Use of Libraries
- Key Management
- Secure Random Numbers
- Encryption Modes
- Authentication
- Password Handling
- Code Review
- Stay Updated
- Exception Handling

### Choice of Algorithms

Use only modern, secure, and vetted cryptographic algorithms. For symmetric encryption, we recommend AES-256. For asymmetric encryption, use RSA with at least 2048-bit keys, or preferably ECC (Elliptic Curve Cryptography) with at least 256-bit keys. For hashing, use SHA-256 or higher.

FUTURE RULES FOR POST QUANTUM ENCRYPTION ALGORITHMS WILL APPLY ONCE A ROBUST STRATEGY HAS BEEN PROPOSED

### Use of Libraries

Always use well-established cryptographic libraries instead of implementing your own cryptography. Libraries such as OpenSSL, Crypto++, or libsodium have been thoroughly tested and vetted for security.

### Key Management

All encryption keys must be securely generated, stored, and managed. Keys should never be hard-coded into the application. Consider using a secure vault or a dedicated key management service. If keys are stored locally, they should be encrypted themselves.

### Secure Random Numbers

Always use cryptographically secure random number generators when creating keys, initialization vectors, nonces, or any other random values in cryptography.

### Encryption Modes

If using AES, use a secure mode like GCM (Galois/Counter Mode), which also provides authentication, or CBC (Cipher Block Chaining) with a secure padding method like PKCS#7.

### Authentication

Always authenticate your data in addition to encrypting it. This can prevent a range of attacks and ensure the integrity of the data. This could mean using HMACs with your encryption, or using an authenticated encryption mode like AES-GCM.

### Password Handling

If using passwords in any capacity, always hash and salt them using a secure password hashing function like bcrypt, scrypt or Argon2.

### Code Review

All code that uses cryptography should be thoroughly reviewed for potential security flaws.

### Stay Updated

Cryptography is a rapidly changing field. Always stay updated with the latest advancements and recommendations. Update your libraries regularly to get the latest security patches.

### Exception Handling

Ensure that cryptographic operations are performed in a way that does not leak sensitive information through error messages or exceptions.

Remember, the goal of encryption is to protect data, and following these guidelines will help ensure that our implementation is secure. Encryption is only one part of a comprehensive security strategy, but it's a very important part.

# Memory safety policy 🛡️

Strictly adhere to these rules to avoid memory leaks and dangling pointers.

- Use Smart Pointers & Avoid Raw Pointers
- RAII
- Use Containers
- Use new and delete & Avoid memory functions (malloc(), calloc(), realloc(), free())
- Check for Allocation Failures
- Initialization
- Exception Safety
- Use Memory Management Tools (Valgrind, AddressSanitizer, LeakSanitizer, etc.)
- Code Review and Testing

### Use Smart Pointers 🧠, Avoid Raw Pointers 👾

Smart pointers are a safe alternative to raw pointers. They are RAII (see below) and will automatically clean up memory when they go out of scope. They are also type safe and will not allow you to do unsafe things like pointer arithmetic.

```cpp
// use smart pointers
std::unique_ptr<int> ptr = std::make_unique<int>(0); // do this 🧠

// and not raw pointers
int* ptr = new int(0); // instead of this 👾

// also use std::shared_ptr & std::weak_ptr accordingly
```

### RAII

RAII (Resource Acquisition Is Initialization) is a programming idiom where resources are tied to an objects lifetime. That is, resource acquisition (such as allocating memory) is done during the objects creation, by the CONSTRUCTOR, while resource deallocation (like memory deallocation) is done during object destruction, by the DESTRUCTOR. This guarantees that resources are correctly cleaned up, preventing resource leaks.

```cpp
// RAII example
class MyClass {
public:
    MyClass() : ptr(new int(0)) {} // constructor
    ~MyClass() { delete ptr; } // destructor
private:
    int* ptr;
};
```

### Use Containers

Containers are a safe alternative to raw arrays.

```cpp
// use containers
std::vector<int> vec(10); // do this

int arr[10]; // instead of this
```

### Avoid memory functions (malloc(), calloc(), realloc(), free()), use new and delete

```cpp
// use new
int* ptr = new int(0);
int* ptr = new int[10];

// instead of malloc()
int* ptr = (int*)malloc(sizeof(int));
int* ptr = (int*)malloc(sizeof(int) * 10);

// use delete
delete ptr;
delete[] ptr;

// instead of free()
free(ptr);

// or use smart pointers
std::unique_ptr<int> ptr = std::make_unique<int>(0);
std::unique_ptr<int[]> ptr = std::make_unique<int[]>(10);

// avoid other memory functions such as calloc(), realloc(), etc.
```

### Check for Allocation Failure

Check for allocation failures after allocation to avoid memory issues.

```cpp
int* ptr = new int(0); // allocation
if (ptr == nullptr) {
    // handle allocation failure
}

// instead of simply allocating and hoping for the best
int* ptr = new int(0);
```

### Initialization

Initialization is a common way to mess up memory safety & introduce memory safety bugs. For that reason, always initialize variables.

```cpp
// always initialize variables
int x = 0;

// always initialize pointers
int* ptr = nullptr;

// always initialize arrays
int arr[10] = {0};

// always initialize structs
struct MyStruct {
    int x;
    int y;
};

MyStruct my_struct = {0};

// always initialize classes
class MyClass {
public:
    MyClass() : x(0), y(0) {} // if possible, always initialize in constructor
    ~MyClass() {} // destructor (no pointers, no need to delete)
private:
    int x; // alternatively, initialize here
    int y;
};

MyClass my_class;

// the same goes for any other datatype
```

### Exception Safety

Ensure your code is exception safe. This means that your program continues to behave correctly (without leaks, corruption or other errors) even when exceptions are thrown.

- Never allow exceptions to propagate out of destructors. This is a key rule in C++, as violating it can lead to resource leaks, and in some cases, to program termination.

- Make use of RAII and smart pointers to handle cleanup automatically in the face of exceptions.

- Be aware of the potential for exceptions when calling functions, and write your code in a way that is resilient to exceptions.

- Use exception specifications ('noexcept') where appropriate.

- Make sure to catch exceptions at a level where you can actually do something about them.

This also ties into the rule 'Check for Allocation Failure'.

```cpp
// RAII guarantees resource cleanup even in the face of exceptions
try {
    std::unique_ptr<int> ptr = std::make_unique<int>(0);
    // other code that might throw an exception
} catch (...) {
    // ptr will be cleaned up automatically in case of exception
}
```

The main goal is to prevent resource leaks and to ensure that your code is robust and reliable, even in the face of unexpected errors or exceptions.

### Use Memory Management Tools (Valgrind, AddressSanitizer, LeakSanitizer, etc.)

- [Valgrind](https://valgrind.org/)
- [AddressSanitizer](https://clang.llvm.org/docs/AddressSanitizer.html)
- [LeakSanitizer](https://clang.llvm.org/docs/LeakSanitizer.html)
- [ThreadSanitizer](https://clang.llvm.org/docs/ThreadSanitizer.html)
- [UndefinedBehaviorSanitizer](https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html)
- [MemorySanitizer](https://clang.llvm.org/docs/MemorySanitizer.html)

These tools will help to catch memory safety issues early and quickly.

### Code Review and Testing

Your submitted code will be reviewed by members of the core team for memory safety.

- Code that does not pass the memory safety tests will be rejected.
- Code that does pass the memory safety tests will be reviewed for other errors.
- If all checks out, your code will be merged in one of the upcoming releases.

You can review code yourself using the tools mentioned above, prior to submitting, to avoid rejection.
If possible, the reason for rejection will be communicated.
If you need help with solving the issues, ask the core team or other developers for help.

# Input Validation Policy 🛡️

### Whitelisting Acceptable Input

Whitelisting is a technique where you define a set of acceptable input and reject everything else. This is a safe approach to input validation, which aims at preventing malicious input from being processed.

```cpp
#include <regex>

// Whitelist filter, returns true if input is valid
bool isValidInput(const std::string& input) {
    std::regex validInputPattern("^[a-zA-Z0-9]*$"); // Only alphanumeric characters
    return std::regex_match(input, validInputPattern);
}

// Usage
std::string userInput = "abcd1234";
if (isValidInput(userInput)) { // Apply whitelist filter
    // Process input
} else {
    // Reject input
}
```

# Authentication and Authorization Policy 🔑

### Secure Password Hashing

Passwords must be hashed using a secure hashing algorithm, such as Argon2, bcrypt, scrypt, or PBKDF2.

```cpp
#include <cryptopp/pwdbased.h>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>

std::string hashPassword(const std::string& password, const std::string& salt) {
    CryptoPP::PKCS5_PBKDF2_HMAC<CryptoPP::SHA256> pbkdf2;
    byte derivedKey[32];

    pbkdf2.DeriveKey(derivedKey, sizeof(derivedKey),
                     0, // purpose byte (no specific meaning)
                     (const byte *)password.data(), password.size(),
                     (const byte *)salt.data(), salt.size(),
                     10000 // iteration count
    );

    CryptoPP::HexEncoder encoder;
    std::string hashedPassword;
    encoder.Attach(new CryptoPP::StringSink(hashedPassword));
    encoder.Put(derivedKey, sizeof(derivedKey));
    encoder.MessageEnd();

    return hashedPassword;
}
```

# Error Handling and Logging Policy 📝

### Error Messages

Error messages must not contain any sensitive information, such as the actual error message, stack traces, or other information that could be used to exploit the system.

```cpp
#include <iostream>

void processInput(const std::string& input) {
    try {
        // Process input here
        throw std::runtime_error("Something went wrong!");
    } catch (const std::exception& e) {
        // Log the actual error message, but do not expose it to the user
        std::cerr << "Error: " << e.what() << std::endl;

        // Display a generic error message to the user
        std::cout << "An error occurred while processing your input. Please try again." << std::endl;
    }
}
```

# Security Headers and Configuration Policy ⚙️

### Security-Related HTTP Headers

Crow provides a simple way to set security-related HTTP headers.
If using [Crow](https://github.com/ipkn/crow), you can set security headers like this:

```cpp
#include <crow.h>

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([]{
        crow::response res("Hello World!");
        res.set_header("Content-Security-Policy", "default-src 'self'");
        res.set_header("X-Content-Type-Options", "nosniff");
        res.set_header("X-Frame-Options", "SAMEORIGIN");
        res.set_header("X-XSS-Protection", "1; mode=block");
        return res;
    });

    app.run();
}
```

🚀 Stay safe and report any incidents or recommendations to the core team. If you should feel that these measures are unwarranted, open a new issue and let us know about it. 🚀
