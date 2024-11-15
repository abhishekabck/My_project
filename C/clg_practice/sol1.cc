#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> minHeap(A.begin(), A.end());
    int operation = 0;
    while (minHeap.size()>1 && minHeap.top() < k){
        // pop the two least sweat cookies
        int leastSweat = minHeap.top()
        minHeap.pop();
        int secondLeastSweat = minHeap.top();
        minHeap.pop();


        int newCookie = leastSweat + 2*secondLeastSweat;
        minHeap.push(newCookie);
        operations++
    }

    if (minHeap.top() >= k){
        return operations; // Check if the smallest element in the heap meets or exceeds k
    } else {
        return -1; // It's impossible to reach the desired sweetness
    }
}