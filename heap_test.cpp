#include <iostream>
using namespace std;
#include "heap.h"

int main(){
    Heap<int> x;
    x.push(5);
    x.push(9);
    x.push(2);
    x.pop();
    x.pop();
    cout << x.top();
}