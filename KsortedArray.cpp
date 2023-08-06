#include <bits/stdc++.h>
using namespace std;
//O(nlogn) min time achievable by any sorting algorithm
//O(nlogn) -> heap sort, quick sort, merge sort
//but given a k sorted array, it can be sorted faster than nlogn
void kSortedArray(int a[],int n,int k){
    priority_queue<int> p;
    for(int i=0;i<k;i++){
        p.push(a[i]);//O(klogk) as inserting k elements in priority queue so k size heap forms
    }
    int j=0;
    for(int i=k;i<n;i++){//O((n-k)logk) as logk for popping one element from size k heap & doing this n-k times
        a[j]=p.top();
        p.pop();
        j++;
        p.push(a[i]);//heap size remains k
    }
    //after this loop only last k elements remain in priority queue
    while(!p.empty()){//O(klogk) 
        a[j]=p.top();
        p.pop();
        j++;
    }
}
//O((n+k)logk) total time complexity, if n>>k -> O(n) which is better than O(nlogn)
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    kSortedArray(a,n,k);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}