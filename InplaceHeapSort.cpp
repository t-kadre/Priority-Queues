#include <bits/stdc++.h>
using namespace std;
int main(){
    //STORING DATA INPLACE IN INPUT ARRAY IN DESCENDING ORDER 
    //in order to do this, we need min heap so that when we swap root & last element the last element becomes lowest
    //we dont need to delete the last element
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //now firstly storing the data in min heap fashion in the given input array itself
    int childIndex=1;
    while(childIndex<n){//O(nlogn) 
        int ci=childIndex;
        while(a[(ci-1)/2]>a[ci]){//up-heapify every node to its correct position 
            int t=a[ci];
            a[ci]=a[(ci-1)/2];
            a[(ci-1)/2]=t;
            ci=(ci-1)/2;
        }
        childIndex++;
    }
    //now doing min heap sort inplace in given input array
    int tempSize=n;
    while(tempSize!=1){
        int t=a[0];
        a[0]=a[tempSize-1];
        a[tempSize-1]=t;
        tempSize--;//in first iteration last element is sorted, in second last two are sorted and so on
        int i=0;
        while(true){//O(nlogn)
            if(2*i+2<tempSize){
                if(min(a[2*i+1],a[2*i+2])==a[2*i+1]){
                    int t=a[i];
                    a[i]=a[2*i+1];
                    a[2*i+1]=t;
                    i=2*i+1;
                }else{
                    int t=a[i];
                    a[i]=a[2*i+2];
                    a[2*i+2]=t;
                    i=2*i+2;
                }
            }else if(2*i+1<tempSize){
                if(a[i]>a[2*i+1]){
                    int t=a[i];
                    a[i]=a[2*i+1];
                    a[2*i+1]=t;
                    i=2*i+1;
                }
                break;
            }else{
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}