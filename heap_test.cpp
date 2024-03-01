#include <iostream>
using namespace std;
#include "heap.h"


int main(){
    Heap<int, std::greater<int>> x;
    x.push(10);
    x.push(1000);
    x.push(100);
    cout << x.top() << endl;
    x.pop();
    cout << x.top() << endl;
    x.pop();
    cout << x.top() << endl;
    x.pop();

}