#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    set<int> s = {876, '6', 909, 'g'};
    for (auto it:s){
        cout<<it<<endl;
    }
    return 0;
}
