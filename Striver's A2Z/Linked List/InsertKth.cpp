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

Node* insertKth(Node* head, int ele, int pos){
    
    if(head==NULL and pos==1){
        return new Node(ele);
    }
    else if (head==NULL and pos!=1){
        cout<<"Not possible";
    }
    else if (pos==1){
        return new Node(ele,head);
    }
    else if (pos>1){
        Node* temp = head;
        int cnt = 1;
        while(cnt<pos-1){
            temp=temp->next;
            cnt++;
        }
        temp->next=new Node(ele,temp->next);
    }
    return head;
} 
    
int main(){
    vector <int> arr = {1,2,3,4};
    Node* head = convertArr2LL(arr);
    printLL(head); 
    cout<<"\n"; 
    head = insertKth(head, 3, 5);
    printLL(head);
}