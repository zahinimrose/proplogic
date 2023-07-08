# Foobar

Proplogic is a project involving propositional logic. It will implement useful functionality involving propositional logic.

It is a learning exercise for me. I aim to be familiar with project management, version control (Git), remote repository (GitHub), and practice C language and logic.  

## Installation

Download and extract this repository from GitHub. Compile test.c with a compiler like gcc

```bash
gcc test.c -o test.exe
```

## Usage
### Truth table Printer:
Edit test.c
```c
P_Q_print_truth_table("P^Q"); //Edit here
```
True -  'T'

False - 'F'

Negate - '~'

Conjunction - '^'

Disjunction - 'v'

First Variable 'P'

Second Variable 'Q'

(Parentheses supported)

Example: "~(P^~Q)"

Compile test.c with a C compiler like gcc

```bash
gcc test.c -o test.exe
```
Run
```bash
./test.exe
```

## Contributing

Pull requests and feedback are welcome. 

## License

[MIT](https://choosealicense.com/licenses/mit/)