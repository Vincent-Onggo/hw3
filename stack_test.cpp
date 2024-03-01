#include "stack.h"
#include <iostream>

int main() {
    Stack<int> s;
    s.push(9);
    s.push(3);
    s.push(2);
    s.pop();
    s.push(5);
    std::cout << "Size of stack: " << s.size() << std::endl;
    std::cout << "Top element of stack: " << s.top() << std::endl;
    return 0;
}
