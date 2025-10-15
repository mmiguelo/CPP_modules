# CPP_modules

Reading material:

```https://cplusplus.com/doc/tutorial/```


# 📘 42 C++ Modules

This repository contains my solutions to the 42 C++ modules (00 to 04). Each file demonstrates a specific concept or set of concepts from modern C++ (C++98 to C++ canonical form), following the school's progression.

---
## Insert text here<br>
<details>
<summary> 📦 Module 00 — Basics & Syntax</summary><br>

| File              | Concept                                                                         |
|-------------------|---------------------------------------------------------------------------------|
| ex00              | Command-line arguments, basic output                                            |
| ex01              | Classes, private attributes, basic I/O, std::setw, string truncation            |
| ex01              | Basic class design, encapsulation, member functions, scope, object lifetime     |

</details>

<details>
<summary> 🧱 Module 01 — Memory, References, and File I/O</summary><br>

| File              | Concept                                          |
|-------------------|--------------------------------------------------|
| ex00              | Stack vs heap allocation, constructors           |
| ex01              | Heap allocation, delete                          |
| ex02              | References vs pointers                           |
| ex03              | Using references, initializer lists              |
| ex04              | File reading/writing, string manipulation        |
| ex05              | Pointers to member functions                     |
| ex06              | Switch statments                                 |

</details>

<details>
<summary> 🧠 Module 02 — OOP and Ad-hoc Polymorphism</summary><br>
  
| File                  | Concept                                                           |
|-----------------------|-------------------------------------------------------------------|
| ex00                  | Orthodox Canonical Form, fixed-point arithmetic                   |
| ex01                  | Copy constructor, assignment operator                             |
| ex02                  | Roundf, operator overloading, static polymorphism                 |
| ex03                  | Inheritance, polymorphism, virtual destructors, dynamic dispatch  |

</details>

<details>
<summary> 📦 Module 03 — Inheritance & Polymorphism</summary><br>
  
| File                    | Concept                                       |
|-------------------------|-----------------------------------------------|
| ex00                    | Orthodox Canonical Form                       |
| ex01                    | Basic inheritance                             |
| ex02                    | Derived classes and method specialization     |
| ex03                    | Multiple inheritance, virtual inheritance     |
  
</details>

<details>
<summary> 🎯 Module 04 — Abstract Classes & Interfaces</summary><br>

| File                  | Concept                                                   |
|-----------------------|-----------------------------------------------------------|
| ex00                  | Abstract classes, virtual methods, dynamic polymorphism   |
| ex01                  | Deep copies, dynamic memory in class members              |
| ex02                  | Abstract classes, pure virtual functions                  |
| ex03                  | Interfaces, pure abstract classes                         |

</details>

<details>
<summary> Next Modules Coming Soon (here is a preview)</summary><br>

## 🛠 Module 05 — Exceptions
| File               | Concept                                                       |
|--------------------|---------------------------------------------------------------|
| ex00               | Bureaucrat class, exceptions, range validation with try/catch |
| ex01               | Form class, nested exceptions, interaction between classes
| ex02               | Polymorphic forms, exception hierarchy, execution permissions
| ex03               | Intern class, factory method pattern, dynamic form creation

---

## ⚙️ Module 06 — Casting
| File                  | Concept                                |
|-----------------------|----------------------------------------|
| ex00                | Static casting, type conversion between base and derived             |
| ex01                | Dynamic casting, runtime type identification (RTTI)                |
| ex02                | Base class pointer identification using dynamic_cast

---

## 🎲 Module 07 — Templates
| File                | Concept                        |
|---------------------|--------------------------------|
| ex00                | Function templates, generic programming basics             |
| ex01                | Class templates, template parameters |
| ex02                | Template specialization, iterators, and generic containers

---

## 🧰 Module 08 — Containers & STL
| File                | Concept                                  |
|---------------------|------------------------------------------|
| ex00                | Templates with custom classes, STL algorithms      |
| ex01                | Templated container with iterators, add/shortest/longest span |
| ex02                | Extend STL containers and make a stack iterable

---

## 📈 Module 09 — MutantStack & Inheritance from STL
| File                | Concept                                   |
|---------------------|-------------------------------------------|
| ex00                | Parse files, handle errors, and use std::map for date-based lookups.       |
| ex01                | Stack operations, expression parsing, and error handling.        |
| ex02                | Advanced sorting algorithms and performance comparison using STL containers.

</details>

---

## 🧪 Tests
Where applicable, I’ve included test files or sample usage to demonstrate and validate each concept.

---

## 🔧 Build & Run

All files can be compiled with a simple `Makefile` or using:
```bash
make
```
Or to include memory leak verification use (only in exercises where applicable):
```bash
make val
```
