#include <vector>
#include <iostream>
using namespace std;

class Node{
    int data;
    Node* next;

    Node (int data1, Node* next1){
        data=data1;
        next=next1;
    }

    Node (int data1){
        data=data1;
        next=nullptr;
    }
};

int main(){
    vector<int> arr = {1,2,3,4};
    Node* y = new Node(arr[0]);
    cout<<y<<"\n";
    cout<<y->data<<"\n";
    cout<<y->next<<"\n";
}
