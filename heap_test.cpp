#include <iostream>
using namespace std;
#include "heap.h"

int main(){
    Heap<int> x;
    x.push(0);
    x.push(5);
    x.push(10);
    cout << x.top() << endl;
    x.pop();
    cout << x.top() << endl;
    x.pop();
    cout << x.top() << endl;
    x.pop();

}