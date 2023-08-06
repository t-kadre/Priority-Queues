#include <bits/stdc++.h>
using namespace std;
//Max PQ->that element comes out first which has max value of priority, Min PQ->opposite
//we should use balanced BST to store data and implement Max/Min PQ as all useful functions like insert, getMin/getMax, removeMin/removeMax can be done in O(logn)
//which is better than having two functions in O(1) and one in O(n) as max time would become n^2 with n entries
//logn<n so if we have n entries then max time any function out of these would take will be nlogn, whereas all other data structures would take n^2
//we use HEAPS data structure to store PQ->Heaps have two properties: they are COMPLETE BINARY TREES, & they satisfy HEAP ORDER PROPERTY
//CBT: binary tree made by inserting elements level wise left to right, which means:all levels except the last fully filled & last also can or cannot be fully filled
//LAST LEVEL must be filled left to right
//CAN ONLY DELETE ELEMENT WHICH WAS INSERTED AT LAST to maintain CBT
//using heaps to solve two problems that were there with BST: maintaining its height (balancing) & storing or saving it would be difficult 
//CALCULATING HEIGHT OF A CBT: MIN no. of nodes of CBT with height h=2^(h-1), MAX "=(2^h)-1 so 2^(h-1)<=n<=(2^h)-1, solving these two inequalities separately
//log(n+1)<=h<=logn+1 (BASE 2) so logn<=h<=logn (when n very large) so both in worst & best case we can achieve height=logn so we dont need to balance
//we'll save a CBT in an array filling it level wise L to R where the children of node at ith index are at indexes 2i+1,2i+2 so inserting & deleting in CBT will take O(1)
//parent index = (child index-1)/2 
//HEAP ORDER PROPERTY OF MIN HEAP BASED ON MIN PQ->every node's priority is smaller than its children, MAX PQ->MAX HEAP reverse (for now numbers=their priority)
//INSERTING IN A MIN HEAP->first insert at correct position according to CBT then keep comparing it to its parent and swapping if MIN heap isnt maintained
//UP-HEAPIFY=this process of comparing to its parent node & swapping if property isnt maintained
//so inserting in MIN/MAX HEAP=O(logn) as worst case no. of comparisons made=height=logn
//DELETING FROM A MIN HEAP->ROOT SHOULD BE DELETED so swap root and last element of CBT then delete new last element of CBT then DOWN HEAPIFY the new root to its correct position
//DOWN-HEAPIFY=swap the smaller of the two children with new root/parent until correct position is achieved 
//so again logn time due to down heapify BUT getMin will be O(1) as only accessing the root
class MinPQ{
    vector<int> pq;
    public:
    int getSize(){
        return pq.size();
    };
    bool isEmpty(){
        return pq.size()==0;
    };
    int getMin(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    };
    void insert(int element){
        pq.push_back(element);
        int i=pq.size()-1;
        while(pq[(i-1)/2]>pq[i]){//UP-HEAPIFY
            int j=pq[i];
            pq[i]=pq[(i-1)/2];
            pq[(i-1)/2]=j;
            i=(i-1)/2;
        }
    };
    int removeMin(){//HEAP SORT
        if(isEmpty()){
            return 0;
        }
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int pi=0;
        while(pq[pi]>min(pq[(2*pi)+1],pq[(2*pi)+2])){//DOWN-HEAPIFY
            if((2*pi)+2<pq.size()){ 
                if(min(pq[(2*pi)+1],pq[(2*pi)+2])==pq[(2*pi)+1]){
                    int t=pq[pi];
                    pq[pi]=pq[(2*pi)+1];
                    pq[(2*pi)+1]=t;
                    pi=(2*pi)+1;
                }else{
                    int t=pq[pi];
                    pq[pi]=pq[(2*pi)+2];
                    pq[(2*pi)+2]=t;
                    pi=(2*pi)+2;
                }
            }else if((2*pi)+1<pq.size()){
                if(pq[pi]>pq[(2*pi)+1]){
                    int t=pq[pi];
                    pq[pi]=pq[(2*pi)+1];
                    pq[(2*pi)+1]=t;
                    pi=(2*pi)+1;
                }
            }else{
                break;
            }
        }
        return ans;
    };
};
//HEAP SORT=removeMin() function except just swap first & last element (dont pop last element) & down-heapify till excluding last element, now you have sorted in vector itself 
//TIME COMPLEXITY OF HEAP SORT= O(nlogn) as n times insertion and deletion -> nlogn+nlogn=2nlogn
//SPACE COMPLEXITY= O(n) as max vector of size n used 
//IMPROVING SPACE COMPLEXITY
//DOING INPLACE HEAP SORT IN INPUT ARRAY ITSELF SO NO EXTRA ARRAY/VECTOR USED
//SO GIVEN INPUT ARRAY->HEAP FORMATION INPLACE(IN INPUT ARRAY ITSELF)->HEAP SORT INPLACE IN INPUT ARRAY ITSELF (LINE 83)
int main(){
    MinPQ p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);
    cout<<p.getSize()<<endl;
    cout<<p.getMin()<<endl;
    while(!p.isEmpty()){
        cout<<p.removeMin()<<" ";//elements will come out in sorted order from Min Heap / Min PQ -> HEAP SORT
    }
    cout<<endl;
    cout<<p.getSize()<<endl;
    return 0;
}