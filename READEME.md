# Genetic Algorithm: Sudoku Solver

## Description

This project implements a sudoku solver powered by a genetic algorithm (GA). It
models the puzzle-solving process by simulating evolution, improving potential
solutions over successive generations. With a population of candidate sudoku
grids, each generation undergoes selection, culling, and mutation steps to guide
the population toward a solution. The program stops when it finds a valid sudoku
solution or reaches the set maximum number of generations.

## Getting Started

### Compiling The Program

Follow these steps to compile the program:

* Clone repository:

    ```bash
    git clone https://github.com/michael-re/genetic-algorithm.git
    ```

* Navigate to project directory:

    ```bash
    cd genetic-algorithm/
    ```

* Build the program using the provided **[`makefile`](makefile)**:

    ```bash
    # Debug build
    make debug

    # Release build
    make release

    # Clean up compiled binaries and build artifacts
    make clean
    ```

> [!NOTE]
> The compiled binary is placed in the **`bin/`** directory of the project root.

## Usage

To run the program, use the following command:

```bash
# example: running the program
./bin/ga <population-size> <max-generation>
```

|   arg                 |  type       |  description                                             |
| --------------------- | ----------- | -------------------------------------------------------- |
|  `population-size`    |  required   |  the number of individuals in the puzzle population      |
|  `max-generation`     |  required   |  the maximum number of generations to run the simulation |

> [!NOTE]
> When the program starts, you will be prompted to enter a puzzle. The program
> will keep reading from `std::cin` until 81 digits are entered. If you prefer
> not to manually enter a puzzle, you can simply pipe a file that contains a
> puzzle to `std::cin`:
>
> ```bash
> # example: piping a file to program
> ./bin/ga 4000 4000 < puzzles/sudoku_e1.txt
> ```

### Test Puzzles

The **[`puzzles`](puzzles/)** directory contains a selection of pre-defined
sudoku puzzles for testing purposes. You can use these puzzles by either piping
them directly into the program or manually entering them when prompted.

Each puzzle file name includes a difficulty level indicator:

  1. **`e`**: for easy
  2. **`m`**: for medium
  3. **`h`**: for hard
  4. **`x`**: for example

> ### **[`puzzles`](puzzles/)**
>
> * **[`sudoku_e1`](puzzles/sudoku_e1.txt):** `037000150005710030010350700000507301351000070700031005570103000100075003003000517`
> * **[`sudoku_e1`](puzzles/sudoku_e2.txt):** `007605831508713600136800057813007506060581073705036180670150308381070065050368710`
> * **[`sudoku_e1`](puzzles/sudoku_e3.txt):** `900020604060940200420060900002004069609200040004096020040602090290000406006409002`
> * **[`sudoku_h1`](puzzles/sudoku_h1.txt):** `070004000030000000000000090000680001308045760007010900903000670050300400160000000`
> * **[`sudoku_h1`](puzzles/sudoku_h2.txt):** `020600400807100000060003020000000080002400500000708301000000000040007062050000800`
> * **[`sudoku_m1`](puzzles/sudoku_m1.txt):** `003040000200300049040209300030020904020490030409003200002000493304900000900034000`
> * **[`sudoku_m1`](puzzles/sudoku_m2.txt):** `007020009509000270002597000200000905790250000050009720900702050075900002020005000`
> * **[`sudoku_x1`](puzzles/sudoku_x1.txt):** `409806701001307200030009004500030680090000050026080007300100020004603900908402503`
> * **[`sudoku_x1`](puzzles/sudoku_x2.txt):** `100090005040050090800302004208000603003206400504000709700605001050080030400030002`
