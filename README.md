# BigInt Engine

Arbitrary-precision integer arithmetic engine written in C from first principles — no external libraries, no built-in bignum types.

Standard C integers overflow past ~18-19 digits (`long long` maxes out around 9.2 × 10^18). This engine represents numbers as digit arrays instead, so operands can be as large as your memory allows.

## Features

- **Addition** — digit-by-digit summation with carry propagation
- **Subtraction** — handles operand magnitude comparison and produces correctly signed results
- **Multiplication** — schoolbook digit-by-digit multiplication with carry handling across all cross-digit positions
- **Division** — long division, computing one quotient digit at a time, with remainder support

All four operations have been verified against known-correct results (including Python's arbitrary-precision arithmetic) across small inputs, large inputs (50+ digits), and edge cases: division by zero, equal operands, zero dividend, and results requiring sign changes.

## Project Structure

```
bigint-engine/
├── src/
│   ├── bigint_add.c            # addition
│   ├── bigint_subtract.c       # subtraction
│   ├── bigint_multiplication.c # multiplication
│   └── bigint_division.c       # division (long division)
├── tests/
│   └── test.c                  # test harness
├── notes/
│   └── multiplication.txt      # algorithm notes
├── main.c                      # interactive entry point
└── Makefile
```

## Build & Run

```bash
gcc -Wall -Wextra src/*.c main.c -o build_main
./build_main
```

You'll be prompted for two numbers and an operator (`+`, `-`, `*`, `/`):

```
Enter first number  : 999999999999
Enter operator (+,-,*,/): *
Enter second number : 999999999999
Result = 999999999998000000000001
```

For division, both quotient and remainder are printed:

```
Enter first number  : 1234
Enter operator (+,-,*,/): /
Enter second number : 12
Quotient  = 102
Remainder = 10
```

## How It Works

Numbers are stored as C strings of ASCII digits, most-significant digit first. Each operation implements the same manual arithmetic you'd do on paper:

- **Add/Subtract** — operands are zero-padded to equal length, then processed right-to-left with a running carry (or borrow).
- **Multiply** — every digit of the first operand is multiplied against every digit of the second; each partial product is placed at the correct positional index (`i + j` / `i + j + 1`) in a result buffer, accumulating carries naturally as it goes.
- **Divide** — classic long division: bring down one digit at a time from the dividend, find the largest quotient digit whose multiple fits, subtract, and repeat.

## Roadmap

- Struct-based redesign (wrap digit array + sign + length into a `BigInt` type)
- Header file (`bigint.h`) for shared function declarations across `src/`
- Karatsuba multiplication for improved performance on very large inputs
