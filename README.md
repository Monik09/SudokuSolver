# Cpp-Project_SudokuSolver
>This is my *cpp project* which is based on solving sudoku puzzle by **_backtracking algorithm_**
## Rules of Sudoku
* There is always a ***unique solution*** to a sudoku puzzle.
* Each column must contain all of the numbers 1 through 9 and *no two numbers in the same column of a Sudoku puzzle can be the same*.
* Each row must contain all of the numbers 1 through 9 and *no two numbers in the same row of a Sudoku puzzle can be the same*.
* Each block must contain all of the numbers 1 through 9 and *no two numbers in the same block of a Sudoku puzzle can be the same*.

## What is backtracking?
In backtracking algorithm, which uses **recursive function** to solve a puzzle.In backtracking, we first assign a value and then check whether this value is not violating the rule of the game,if it violates we increment the value and then check it again,otherwise, we assign that value and go to next empty place to be filled.
>***Everytime we find a dead-end,we either back-trace the path and try another path until we find exit or we have explored all the possible paths.***

## Explanation to My Code
I have written my code in C++ language.As the normal size of a Sudoku puzzle is 9, so I have taken MAX as 9.
### createsudoku() function 
The aim of the function is to input the sudoku to be solved.In this void-type function ,to represent an empty cell ,the user has to input 0.
### findemptycell() function
This function will find the empty cell present in the sudoku by just checking whether the element with value 0 is present(as the user will input empty cell by 0) and will return 1 if not present.
### valid() function
This function is an important function which just checks that the whether the value assigned to empty cell is not violating the rules of sudoku.It will first check in the row,then column, then the sub-box(3x3 box).
### solution() function
This is the most important function of this code as it will be using backtracking algorithm's main concept.
First of all, this function will find empty cell using one of the above defined function.
Then we check the value to be assigned to empty cell from 1 to 9 and if it is valid then we solve the whole puzzle ahead but if there is some point when we are not able to assign value to any empty cell,we come back to this value (back-traced the path) and will make this cell again unassigned and will assign the incremented value and follow the same procedure.
> If non of the value to a empty cell then the given the sudoku is wrong and thus we will return 0 resulting to show "No solution exists" in new line.
### display() function
This is a normal function to just display the sudoku.I have displayed empty cell by '.' character. I tried to give the output the feeling of real sudoku box by using'|_' and '_|' characters to represent  small boxes.
