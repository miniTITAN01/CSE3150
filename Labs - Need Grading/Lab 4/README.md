# LAB 3 - NEED GRADING  

## **Compiling Instruction** 
0. Ensure that Doctest is installed before running tests

1. Type the following command to compile(if necessary) & run the main program
    -  Checking out the output of **Well-Formed Symbols Sequences**
    -  Running tests
    
```bash
        make run
``` 
```bash
        make check 
```
2. Remove all compiled files and executables.
```bash
        make clean
```

## **Problem Clarification**
**Step 1: Initialize the List**
- First, we create a list of 2n + 1 integers where the first n elements are 1, and the next n + 1 elements are -1.

**Step 2: Scramble the List**
- Next, we use the Fisher-Yates shuffle algorithm to randomly scramble the list. This step ensures that every permutation of the list is equally likely.

**Step 3: Find the Lowest Depth of Any Valley**
- To find the lowest depth (the most negative prefix sum) in this list, we can use the get_lowest_prefix_sum_value function from gen_permutation.cpp.

**Step 4 & 5: Define P1 and P2**
- P1 is defined as the path down to the first occurrence of the lowest valley. This means we take the sequence from the start up to and including the point where the lowest valley occurs.
- P2 is the rest of the sequence, starting right after the lowest valley point up to the end of the list.
**Step 6: Create P1'**
- P1' is obtained by dropping the last -1 from P1. This operation effectively removes the last "closing parenthesis" from P1, adjusting it to ensure the sequence can be well-balanced.

**Step 7: Combine P2 and P1' to Form a Well-Balanced List**
- Finally, we attach P2 to the start of P1'. This rearrangement ensures the sequence is well-balanced, as it starts with the part of the sequence that moves out of the lowest valley and then follows the path that led to the valley, minus the final step that would deepen the valley.