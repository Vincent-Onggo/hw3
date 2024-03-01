#include "stack.h"
#include <stdexcept>

template<typename T>
Stack<T>::Stack() {
    num_elements = 0;
}

template<typename T>
size_t Stack<T>::size() const {
    return(num_elements);
}

template<typename T>
bool Stack<T>::empty() const {
    if(num_elements == 0){
        return true;
    }else{
        return false;
    }
}

template<typename T>
void Stack<T>::push(const T &item) {
    stack.push_back(item);
    num_elements++;
}

template<typename T>
void Stack<T>::pop() {
    stack.pop_back();
    num_elements--;
}

template<typename T>
T const& Stack<T>::top() const{
    return stack.back();
}