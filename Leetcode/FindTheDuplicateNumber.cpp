#include<iostream>
using namespace std;

int findDuplicateNumber(int arr[]) {
    int slow = arr[0];
    int fast = arr[0];
    cout<< "slow: "<<slow<< " fast "<<fast<<endl;
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
        cout<< "slow: "<<slow<< " fast "<<fast<<endl;
    } while( slow != fast);

    fast = arr[0];
    while(fast != slow) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main() {
    int arr[] = {1,2,4,2,3};
    cout<<"Duplicate number: "<<findDuplicateNumber(arr)<<endl;
    return 0;
}