#include <iostream>
#include <set>

using namespace std;

int main(){
    set<int> a;
    a.insert(10);
    a.insert(20);
    a.insert(10);

    for(int x: a)
        cout << x << ' ';

    return 0;
}