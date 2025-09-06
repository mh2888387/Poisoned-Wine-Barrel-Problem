# 🍷 Poisoned Wine Barrel Solver

[![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.cppreference.com/w/cpp/17)
[![Algorithm](https://img.shields.io/badge/Algorithm-Divide%20%26%20Conquer-green.svg)](https://github.com/mohamedhamdi/poisoned-wine-barrel-solver)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

## 🧩 Problem Overview

An ancient algorithmic puzzle: **How do you identify one poisoned wine barrel among 1000 barrels using the minimum number of testers within 5 weeks?**

The challenge involves a lethal poison that kills exactly 30 days after ingestion. This project implements an elegant **divide-and-conquer** solution that can solve the puzzle with either:
- **10 testers** using binary encoding (classical approach)
- **8 testers** using time-staggered multi-day testing (optimized approach)

## 🚀 Features

- **Dual Strategy Implementation**: Both binary encoding and time-staggered approaches
- **Interactive Testing Schedule Generator**: Creates detailed tasting schedules
- **Outcome Decoder**: Identifies the poisoned barrel from death patterns
- **Flexible Configuration**: Supports different numbers of barrels, testers, and observation days
- **Mathematical Optimization**: Uses base-n encoding for maximum efficiency

## 🔬 How It Works

### Binary Encoding Strategy (10 Testers)
```
Barrels: 1000 → Binary representation (10 bits)
Testers: 10 → Each represents one bit position
Result: 2^10 = 1024 possible outcomes > 1000 barrels ✓
```

### Time-Staggered Strategy (8 Testers)
```
Barrels: 1000 → Base-6 representation (8 digits)  
Testers: 8 → Each can have 6 outcomes (death days 0-4 + survival)
Result: 6^8 = 1,679,616 possible outcomes >> 1000 barrels ✓
```

## 🛠️ Installation & Usage

### Prerequisites
- C++17 compatible compiler
- Standard library support

### Compilation
```bash
g++ -std=c++17 -O2 task4.cpp -o wine_barrel_solver
```

### Running the Program
```bash
./wine_barrel_solver
```

### Input Format
```
N S D
```
- **N**: Number of barrels (e.g., 1000)
- **S**: Number of testers/slaves (e.g., 8 or 10)  
- **D**: Extra observation days beyond 30 (e.g., 4 for 5-week strategy, 0 for binary)

### Example Usage

#### Binary Strategy (10 testers, 0 extra days)
```bash
Input: 1000 10 0
Output: [Testing schedule for all 1000 barrels]
After 30 days, input death results: 0 1 0 1 0 1 0 1 0 1
Result: Poisoned barrel label = 341
```

#### Time-Staggered Strategy (8 testers, 4 extra days)
```bash
Input: 1000 8 4  
Output: [Testing schedule for all 1000 barrels]
After 34 days, input death results: 0 2 5 4 2 2 2 0
Result: Poisoned barrel label = 512
```

## 📊 Sample Output

### Testing Schedule Generation
```
+----------------------+--------------------------------------+
| SETUP PARAMETERS     | (enter as: N S D)                   |
+----------------------+--------------------------------------+
| N (barrels >= 1)     | total wine barrels                   |
| S (slaves >= 1)      | number of testers                    |
| D (days >= 0)        | extra days beyond 30                 |
+----------------------+--------------------------------------+

>> Input N S D: 1000 8 4

Barrel 1 -> Slave #1 on day 0
Barrel 2 -> Slave #2 on day 0  
Barrel 3 -> Slave #1 on day 1
...
```

### Outcome Input Interface
```
+--------------------------------+----------------------------------------------+
| OUTCOME NOTATION               | (enter o[j] for j = 1..S)                   |
+--------------------------------+----------------------------------------------+
| o[j] = t (0 <= t <= D)         | Slave #(j+1) DIED on day 30 + t            |
| o[j] = 5                       | Slave #(j+1) SURVIVED (no taste)           |
+--------------------------------+----------------------------------------------+
```

## 🎯 Algorithm Complexity

- **Time Complexity**: O(N×S) for schedule generation + O(S) for decoding
- **Space Complexity**: O(S) for streaming implementation, O(N×S) for full schedule storage
- **Optimality**: Mathematically optimal in terms of information theory

## 🧮 Mathematical Foundation

The solution leverages **information theory** principles:

- **10 testers binary**: log₂(1000) ≈ 9.97 → need 10 bits
- **8 testers multi-day**: log₆(1000) ≈ 3.86 → need 4 base-6 digits, but use 8 for redundancy

Each tester provides multiple bits of information through timing, dramatically reducing the required number of testers.

## 📈 Comparison with Other Approaches

| Strategy | Testers Needed | Time Required | Feasibility |
|----------|----------------|---------------|-------------|
| Brute Force | 1000 | 1000 × 30 days | ❌ Impossible |
| Sequential Binary Search | 1 | 10 × 30 days | ❌ Too slow |
| Parallel Binary Encoding | 10 | 30 days | ✅ Classical solution |
| **Time-Staggered D&C** | **8** | **35 days** | ✅ **Optimal** |

## 📁 Project Structure

```
poisoned-wine-barrel-solver/
├── task4.cpp                 # Main implementation
├── algo_project_final1.pdf   # Detailed mathematical analysis
├── README.md                 # This file
└── examples/                 # Sample inputs and outputs
```

## 🔬 Research Paper

This implementation is based on the comprehensive research paper included in `algo_project_final1.pdf` which covers:

- Detailed mathematical proofs
- Complexity analysis  
- Comparison with alternative approaches
- Extensive examples and case studies
- Theoretical foundations in information theory

## 🎓 Educational Value

This project demonstrates key computer science concepts:

- **Divide & Conquer Algorithms**
- **Information Theory Applications**
- **Encoding Theory**
- **Optimization Techniques**  
- **Parallel vs Sequential Processing**

Perfect for algorithm design courses, competitive programming practice, and interview preparation.

## 🤝 Contributing

Contributions are welcome! Areas for improvement:

- GUI implementation
- Web-based visualization
- Extended test cases
- Performance optimizations
- Multi-language implementations


## 👨‍💻 Author

**Mohamed Hani Hamdi** (Student ID: 2100915)

*Algorithms & Data Structures Project*

---

### 🏷️ Tags
`algorithm` `divide-and-conquer` `information-theory` `optimization` `cpp` `puzzle` `encoding` `computer-science` `competitive-programming`
