#include <iostream>
#include <queue>
using namespace std;
int main(){
    priority_queue<int> p;//MAX PQ
    priority_queue<int,vector<int>,greater<int>> minPQ;//MIN PQ
    //greater is like inbuilt function which swaps when parent>child
    p.push(7);
    p.push(2);
    p.push(1);
    p.push(3);
    p.push(8);
    cout<<"size:"<<p.size()<<endl;
    cout<<"top:"<<p.top()<<endl;
    while(!p.empty()){
    cout<<p.top()<<endl;
    p.pop();//elements will come out in decreasing order
    }
    return 0;
}