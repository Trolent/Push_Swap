# Push_swap - Sorting Algorithm Project

Welcome to my Push_swap repositery! This project aims to implement a sorting algorithm for stacks of integers using various limitating operations to manipulate the stacks.

## Objectives

The main objectives of this project are:

- To implement a sorting algorithm for stacks efficiently.
- To gain a deep understanding of sorting algorithms and their complexities.
- To write clean and efficient code in C.
- To handle basic algorithms and their complexities effectively.

## Usage

### Compilation

To compile the project, use the following commands:

```bash
make        # Compiles the project and generates the ./push_swap executable.
make bonus  # Compiles the project and generates the ./checker executable.
make clean  # Deletes the compiled object files.
make fclean # Deletes the compiled object files and the executables.
make re     # Fully recompiles the project.
```

### Executing Push_swap

At execution time, provide a list of integers as arguments to the push_swap executable:

```bash
./push_swap 2 1 3 6 5 8
```

The program will display the smallest list of instructions possible to sort the stack.

### Executing Checker

To verify the correctness of the sorting instructions generated by push_swap, use the checker program:

```bash
./push_swap <ARG_LIST> | ./checker <ARG_LIST>
```

If the sorting is correct, checker will display "OK"; otherwise, it will display "KO".
Controls and Output

### Step-by-Step Algorithm

1. **Initialization:**
    - The program begins by parsing the input integers and initializing stack `a` with these values. Stack `b` starts empty.

2. **Dividing into Thirds:**
    - The algorithm divides the elements of stack `a` into three sorted segments according to the nodes values:
        - Smallest third
        - Middle third
        - Largest third

3. **Moving Elements to Stack `b`:**
    - The smallest and middle thirds are moved to stack `b` in such a way that the smallest third is on top of the middle third.
    - The largest third remains in stack `a`.

4. **Pushing Remaining Elements:**
    - The remaining elements in stack `a` (the largest third) are also pushed on top of stack `b`, leaving only 3 elements into `a`.

5. **Sorting `a`:**
    - Sort the 3 elements in stack `a`.

6. **Reordering Elements:**
    - Elements are then pushed back from stack `b` to stack `a` in their correct positions. This is done by finding the "cheapest" node in terms of operations needed to push it to the right position in stack `a`.

7. **Final Adjustment:**
    - Once all elements are back in stack `a`, the algorithm ensures the smallest element is on top and the stack is in ascending order.

### Demonstration

![Push_swap Demonstration](https://github.com/Trolent/Push_Swap/blob/main/git_resource/Push_Swap_Visu.gif)

## Educational Value

This project is valuable for learning:

- **Sorting Algorithms:** Understanding various sorting algorithms and their efficiencies.
- **Complexity Analysis:** Analyzing the time and space complexities of algorithms.
- **Error Handling:** Implementing robust error handling for user input and program execution.
- **Linked lists:** Using linked list and managing them.

  
## Documentation

- With thanks to o-reo for his push_swap_visualiser. You can find the repository [here](https://github.com/o-reo/push_swap_visualizer).
- Special thanks to Ayogun for inspirationnal "Turk sort" algorithm. You can read about it in this [Medium article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).
- And to [@akdovlet](https://github.com/akdovlet) for the median sort idea that I tansformed into thirds.
