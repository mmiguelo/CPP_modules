<a id="readme-top"></a>

<div align="center">

# 📘 C++ Modules

Solutions to the **42 School C++ Modules** (00 – 09) — a progressive journey from basic syntax to advanced templates, STL containers, and design patterns

<br>

![42 School](https://img.shields.io/badge/42-School-blue?style=for-the-badge&logo=42&logoColor=white)
![C++](https://img.shields.io/badge/C++98-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Norminette](https://img.shields.io/badge/Norminette-passing-brightgreen?style=for-the-badge)

</div>

---

### 📑 Table of Contents

- [📌 About](#-about)
- [📘 Module 00 — Basics & Syntax](#-module-00--basics--syntax)
- [💾 Module 01 — Memory, References & File I/O](#-module-01--memory-references--file-io)
- [🧩 Module 02 — Fixed-Point & Operator Overloading](#-module-02--fixed-point--operator-overloading)
- [🌿 Module 03 — Inheritance](#-module-03--inheritance)
- [🔌 Module 04 — Abstract Classes & Interfaces](#-module-04--abstract-classes--interfaces)
- [🛡️ Module 05 — Exceptions](#%EF%B8%8F-module-05--exceptions)
- [🎭 Module 06 — Casting](#-module-06--casting)
- [🧬 Module 07 — Templates](#-module-07--templates)
- [📦 Module 08 — Containers & STL](#-module-08--containers--stl)
- [📈 Module 09 — STL Applications](#-module-09--stl-applications)
- [🔧 Build & Run](#-build--run)

---

### 📌 About

This repository contains all **10 C++ modules** from the 42 curriculum. Each module introduces a specific set of C++ concepts, building progressively from basic I/O and memory management to templates, STL containers, and advanced design patterns — all constrained to the **C++98 standard**.

```
  Module 00 ─── 01 ────── 02 ────── 03 ───────── 04 ──────── 05 ────── 06 ─────── 07 ──── 08 ──── 09
  Basics      Memory  Operators   Inherit     Abstract     Except    Cast   Templates    STL    Applied
```

> 📖 Reference: [cplusplus.com/doc/tutorial](https://cplusplus.com/doc/tutorial/)

---

### 📘 Module 00 — Basics & Syntax

<details>
<summary><b>Exercises</b></summary><br>

| Exercise | Concept |
|:---:|:---|
| `ex00` | Command-line arguments, basic output (`std::cout`, `std::toupper`) |
| `ex01` | Classes, private attributes, `std::setw`, string truncation, basic I/O |
| `ex02` | Object lifetime, scope, member functions, encapsulation |

</details>

---

### 💾 Module 01 — Memory, References & File I/O

<details>
<summary><b>Exercises</b></summary><br>

| Exercise | Concept |
|:---:|:---|
| `ex00` | Stack vs. heap allocation, constructors / destructors |
| `ex01` | Heap allocation, `new[]` / `delete[]` |
| `ex02` | References vs. pointers |
| `ex03` | References in composition, initializer lists |
| `ex04` | File reading / writing, string replacement |
| `ex05` | Pointers to member functions |
| `ex06` | Switch statements, filtering levels |

</details>

---

### 🧩 Module 02 — Fixed-Point & Operator Overloading

<details>
<summary><b>Exercises</b></summary><br>

| Exercise | Concept |
|:---:|:---|
| `ex00` | Orthodox Canonical Form, fixed-point number representation |
| `ex01` | Copy constructor, assignment operator overload |
| `ex02` | Arithmetic / comparison / increment operator overloading |
| `ex03` | Binary Space Partitioning (BSP), point-in-triangle test |

</details>

---

### 🌿 Module 03 — Inheritance

<details>
<summary><b>Exercises</b></summary><br>

| Exercise | Concept |
|:---:|:---|
| `ex00` | Orthodox Canonical Form — `ClapTrap` base class |
| `ex01` | Single inheritance — `ScavTrap` extends `ClapTrap` |
| `ex02` | Multi-level inheritance — `FragTrap` |
| `ex03` | Diamond inheritance, virtual base classes — `DiamondTrap` |

</details>

---

### 🔌 Module 04 — Abstract Classes & Interfaces

<details>
<summary><b>Exercises</b></summary><br>

| Exercise | Concept |
|:---:|:---|
| `ex00` | Virtual methods, dynamic polymorphism (`Animal` → `Dog` / `Cat`) |
| `ex01` | Deep copy with dynamically allocated members (`Brain`) |
| `ex02` | Pure virtual functions, abstract base class (`AAnimal`) |
| `ex03` | Interfaces (`ICharacter`, `IMateriaSource`), pure abstract classes |

</details>

---

### 🛡️ Module 05 — Exceptions

<details>
<summary><b>Exercises</b></summary><br>

| Exercise | Concept |
|:---:|:---|
| `ex00` | Custom exceptions, grade range validation, `try` / `catch` |
| `ex01` | Nested exceptions, `Form` signing with grade checks |
| `ex02` | Abstract `AForm`, concrete forms (`ShrubberyCreation`, `RobotomyRequest`, `PresidentialPardon`) |
| `ex03` | Factory pattern — `Intern` dynamically creates forms |

</details>

---

### 🎭 Module 06 — Casting

<details>
<summary><b>Exercises</b></summary><br>

| Exercise | Concept |
|:---:|:---|
| `ex00` | `static_cast` — scalar type conversion (`char`, `int`, `float`, `double`) |
| `ex01` | `reinterpret_cast` — serialization / deserialization of pointers |
| `ex02` | `dynamic_cast` — runtime type identification (RTTI) |

</details>

---

### 🧬 Module 07 — Templates

<details>
<summary><b>Exercises</b></summary><br>

| Exercise | Concept |
|:---:|:---|
| `ex00` | Function templates (`swap`, `min`, `max`) |
| `ex01` | `iter` — function template applied to arrays |
| `ex02` | Class template — generic `Array<T>` with bounds checking |

</details>

---

### 📦 Module 08 — Containers & STL

<details>
<summary><b>Exercises</b></summary><br>

| Exercise | Concept |
|:---:|:---|
| `ex00` | `easyfind` — templated search in STL containers |
| `ex01` | `Span` — container with shortest / longest span algorithms |
| `ex02` | `MutantStack` — extend `std::stack` to be iterable |

</details>

---

### 📈 Module 09 — STL Applications

<details>
<summary><b>Exercises</b></summary><br>

| Exercise | Concept |
|:---:|:---|
| `ex00` | Bitcoin exchange — date-based CSV parsing with `std::map` |
| `ex01` | Reverse Polish Notation — stack-based expression evaluation |
| `ex02` | `PmergeMe` — Ford-Johnson merge-insert sort, performance comparison across containers |

</details>

---

### 🔧 Build & Run

Each exercise has its own `Makefile`. From any exercise directory:

```bash
make                # Compile
./executable_name   # Run
make val            # Run with Valgrind (where applicable)
make re             # Full recompile
make fclean         # Clean all
```

---

<div align="center">

### 👤 Author

[![mmiguelo](https://img.shields.io/badge/mmiguelo-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/mmiguelo)

</div>

<p align="right">(<a href="#readme-top">back to top</a>)</p>
