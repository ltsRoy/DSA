#include <vector>
#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    Node(int data1,Node* next1)
    {
        data=data1;
        next=next1;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* convertArr2LL(vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for (size_t i = 1; i < arr.size(); i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    return head;
}

void printLL (Node* head){
    while (head!=NULL){
        cout<<head->data<<"\n";
        head=head->next;
    }
}
Node* deletehead(Node* head){
    if (head==NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main(){
    vector <int> arr = {1,2,3,4};
    Node* head = convertArr2LL(arr);
    printLL(head);  
    head = deletehead(head);
    printLL(head);
}