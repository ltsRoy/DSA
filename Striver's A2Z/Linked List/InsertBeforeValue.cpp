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

Node* convertArr2LL (vector <int> &arr){
    if (arr.empty()) return nullptr;

    Node* head = new Node (arr[0]);
    Node* temp = head;

    for (size_t i=1;i<arr.size();i++){
        temp->next = new Node(arr[i]);
        temp=temp->next; 
    }
    return head;
}

void printLL (Node* head){
    while (head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* insertBeforeValue(Node* head, int ele, int val){

    if (head==NULL){
        cout<<"Not possible";
    }
    else if (head->data==val){
        return new Node(ele,head);
    }
    else {
        Node* temp = head;
        while(temp->next->data!=val){
            temp=temp->next;
        }
        temp->next=new Node(ele,temp->next);
    }
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4};
    Node* head = convertArr2LL(arr);
    printLL(head); 
    cout<<"\n"; 
    head = insertBeforeValue(head, 5, 4);
    printLL(head);
}










