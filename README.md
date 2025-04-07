# Password Strength Meter

This project was created for COP 3515 to build a password strength checker using the C programming language.

---

## 🔍 Overview

The program evaluates passwords or passphrases based on configurable criteria, including:

- Minimum and maximum length
- Repeated character sequences
- Presence of letters, numbers, and symbols
- Optional tests for:
  - Uppercase letters
  - Lowercase letters
  - At least two digits
  - At least two special characters

It processes multiple test cases to demonstrate how the settings impact password strength evaluation.

---

## 📂 Files

- `password_strength.c` – Main C source file containing all logic and test cases.

---

## ⚙️ How to Compile & Run

You can compile the program using GCC:
gcc -o password_strength password_strength.c ./password_strength


No input is required from the user — all test cases are preloaded and printed to the terminal.

---

## 🧠 What I Learned

Through this project, I learned how to:

- Apply C language fundamentals (strings, arrays, conditionals, loops, functions)
- Use standard libraries like `ctype.h` for character processing
- Write modular code with reusable functions
- Implement test case-based logic
- Understand how password validation rules are structured and enforced

This project strengthened both my C programming skills and my ability to design logical, real-world rule sets.

---

## 🌐 Real-World Applications

Password strength checkers are essential in:

- User sign-up and login systems (web, mobile, and desktop apps)
- IT security tools and system administration panels
- Embedded systems requiring local password validation
- Encryption tools and secure communication protocols

The validation logic built in this program mirrors how many real systems enforce password security standards to help protect users and data.

---

## 👨‍💻 Author

Varun Gupta
