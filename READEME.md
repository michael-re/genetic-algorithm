# Genetic Algorithm: Sudoku Solver

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

### Usage

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
