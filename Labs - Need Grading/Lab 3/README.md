# LAB 3 - NEED GRADING  

## **Compiling Instruction** 
0. Ensure that Doctest is installed before running tests

1. Type the following command to compile specific files
    -  Checking out the output of linked list with pointer jumping to the last node
    -  Running tests
    
```bash
        g++ linked_list.cpp linked_list_main.cpp
``` 
```bash
        g++ linked_list.cpp unittest_pointer_jumping.cpp
```
2. Run complied files/ Run tests
```bash
        ./a.out
```
3. Run tests with Valgrind to check for memory leaks
```bash 
        valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./a.out

```

## **Problem Clarification**
1. Initialize the linked list normally.
2. After the list is created, iterate through the list once to find the last element.
3. Iterate through the list again to set all jumper pointers to point to this last element.