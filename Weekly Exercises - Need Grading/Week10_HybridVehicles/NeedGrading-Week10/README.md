# WEEK 10 EXERCISE - NEED GRADING  


## **Compiling Instruction** 
0. Ensure that Doctest is installed before running tests

1. Type the following command to compile specific files (**Main Function**, **Unit Tests**)
```bash
        g++ main.cpp Vehicle.cpp Electric.cpp Gasoline.cpp Hybrid.cpp
        g++ unittests.cpp Vehicle.cpp Electric.cpp Gasoline.cpp Hybrid.cpp
 
```
2. Run complied files
```bash
        ./a.out
```

## **Problem Clarification**
- The exercise involving the Vehicle, Electric, Gasoline, and Hybrid classes in C++ serves to illustrate key object-oriented programming concepts, offering practical insights into:

**Multiple and Virtual Inheritance:**
Showcases handling of multiple inheritance where the Hybrid class inherits from both Electric and Gasoline. It uses virtual inheritance to prevent multiple instances of the Vehicle base class in the Hybrid class, solving the diamond problem and ensuring consistency in the class hierarchy.

**Polymorphism:**
Implements virtual functions (Start, Stop, CostOfFuel) in the Vehicle class that are overridden in derived classes. This enables dynamic dispatch where the method that gets executed depends on the object's runtime type, demonstrating runtime polymorphism essential for flexible software architectures.

**Encapsulation and Abstraction:**
Encapsulates vehicle attributes (like name and weight) and behaviors (methods to start and stop vehicles) within classes. Abstraction is achieved by exposing a uniform interface (virtual methods in Vehicle), allowing interaction with all vehicle types through the same interface while hiding the implementation details.

**Design and Architecture:**
Illustrates effective software design by organizing a system where components (Electric, Gasoline, Hybrid) share common functionalities yet each maintains distinct characteristics. This design promotes reusability and modularity, essential for building scalable and maintainable applications.

**Practical Application:**
The application of these OOP principles to model real-world entities like vehicles not only helps in understanding the theoretical concepts but also demonstrates their practical utility in designing systems that reflect real-world complexities and requirements.