#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
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

int search(Node* head, int ele ){

    Node* temp = head;
    while (temp!=NULL){
        if (temp->data==ele){
            return 1;
        }
        temp=temp->next;
    }
    return 0;

}

int main(){
    vector <int> arr = {67,88,9};
    int ele=9;
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    cout << search(head,ele) << "\n";
    return 0;
}
