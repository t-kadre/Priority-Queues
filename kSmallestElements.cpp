#include <bits/stdc++.h>
using namespace std;
//finding k smallest elements from a given array of n integers
//time complexity should be O(nlogk) NOT O(nlogn) so sorting is out of options
//if k=1, finding out the smallest element would take O(n) and we assume first element to be smallest then keep on comparing & updating it 
//similarly we assume first k elements to be smallest, then we keep on comparing & updating the list if the next element<max of those k elements
void kSmallest(int a[],int n,int k){
    priority_queue<int> p;
    for(int i=0;i<k;i++){
        p.push(a[i]);
    }
    for(int i=k;i<n;i++){
        if(a[i]<p.top()){
            p.pop();
            p.push(a[i]);
        }
    }
    while(!p.empty()){
        cout<<p.top()<<endl;
        p.pop();
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    kSmallest(a,n,k);
    return 0;
}