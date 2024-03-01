#include "stack.h"
#include <stdexcept>

template<typename T>
Stack<T>::Stack() {

}

template<typename T>
size_t Stack<T>::size() const {
    return stack.size();
}

template<typename T>
bool Stack<T>::empty() const {
    if(stack.size() == 0){
        return true;
    }else{
        return false;
    }
}

template<typename T>
void Stack<T>::push(const T &item) {
    stack.push_back(item);
}

template<typename T>
void Stack<T>::pop() {
    if(empty()){
        throw std::underflow_error("Stack is empty - can't perform pop()");
    }else{
        stack.pop_back();
    }

}

template<typename T>
T const& Stack<T>::top() const{
    if(empty()){
        throw std::underflow_error("Stack is empty - can't perform top() function");
    }else{
        return stack.back(); // may be wrong??
    }
}