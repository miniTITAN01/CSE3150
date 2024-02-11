#include <iostream>

int fact(int n) {
  if (n <= 1)
    return 1;
  else {
    int rc = fact(n-1); 
    if (rc < 0) throw std::string("Overflow");
    return rc* n;

  }
}

int main() {

  try{
    int ten_fact = fact(10);
    std::cout << "Result is: " << ten_fact << std::endl;
    int x = fact(20);
    std::cout << "Result is: " << x << std::endl;
  } catch (std::string s) {
    std::cout << "Something went wrong! " << s << std::endl;
    return 1;
  }

  return 0;
}
/*#include <iostream>
#include <stdexcept> // Include for std::overflow_error

long long fact(int n) {
    if (n < 0) {
        throw std::invalid_argument("Negative input"); // Handle negative inputs explicitly
    }
    if (n <= 1) {
        return 1;
    } else {
        long long rc = fact(n - 1);
        if (n > 20) { // Simple check to avoid overflow for demonstration purposes
            throw std::overflow_error("Overflow"); // Use standard exception type
        }
        return rc * n;
    }
}

int main() {
    try {
        long long ten_fact = fact(10);
        std::cout << "10! is: " << ten_fact << std::endl;
        long long twenty_fact = fact(20); // Note: This will likely cause overflow for 32-bit int
        std::cout << "20! is: " << twenty_fact << std::endl;
    } catch (const std::overflow_error& e) { // Catch more specific exception type
        std::cout << "Overflow error: " << e.what() << std::endl;
        return 1;
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid argument: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
*/