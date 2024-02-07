# LAB 2 - NEED GRADING  

## **Compiling Instruction** 
0. Ensure that Doctest is installed before running tests

1. Type the following command to compile specific files
    - Checking out the output of 20 000 trials
    -  Running tests

```bash
        g++ fisher_yates.cpp main_parents.cpp 
``` 
```bash
        g++ unitTest_fisherYates.cpp fisher_yates.cpp 
```
2. Run complied files/ Run tests
```bash
        ./a.out
```

## **Problem Clarification**
- Total sequences generated in my case: **20 000 attempts**
- Ratio of well-balanced lists to the total number of lists generated vary everytime. 
- Ratio is calculted by **validSequence divided by trials** in a case of checking for well-balanced lists
- 

## **Problem Explaination**

This lab exercise involves creating a simulation to understand the properties of well-balanced lists, specifically using symbols like parentheses as the basis for the experiment. A well-balanced list, in this context, means that for any prefix of the list, the number of opening symbols (e.g., '(') is never less than the number of closing symbols (e.g., ')'). This concept can be abstractly represented using integers, with +1 representing an opening symbol and -1 a closing symbol. The goal is to generate random sequences of these integers, apply certain constraints, and then analyze the proportion of sequences that are considered well-balanced. Here's a breakdown of the process as outlined in the steps:

**_Step 1_: Initialize the List**
You start by creating a list of 2𝑛 integers where the first 𝑛 elements are +1 (representing opening symbols) and the next 𝑛 elements are -1 (representing closing symbols). This ensures that you have an equal number of opening and closing symbols, a prerequisite for a list to be potentially well-balanced.

**_Step 2_: Randomize the List**
The Fisher-Yates shuffle algorithm is then used to randomly permute the list. This step is crucial because it simulates the randomness of creating well-balanced lists. The Fisher-Yates algorithm is an efficient way to shuffle a list, ensuring that each possible permutation is equally likely.

**_Step 3_: Filter Non-valid Lists**
After shuffling, the list is checked for validity based on prefix sums. A prefix sum here means the running total of the elements from the start of the list up to a certain point. For a list to be considered as a candidate for being well-balanced, its prefix sum must never be negative (which would imply more closing symbols than opening ones at some point in the sequence) and must end with a sum of 0 (equal number of opening and closing symbols). Lists that don't meet this criterion are discarded.