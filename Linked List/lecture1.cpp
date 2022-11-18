#include<iostream>

using namespace std;

class node{
    public:
        int data;
        node* next;
        node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class LinkedList{
    public:
        node *head, *tail;
        LinkedList(){
            head = tail = NULL;
        } 
        void add(int data){
            if(head==NULL) //linked list is empty
            {
                node *n = new node(data);
                this->head = n;
                this->tail = n;
            } else { // Linked List is not empty
                node *newNode = new node(data);
                tail->next = newNode;
                tail = tail->next;
            }
        }

        void add(int data, int pos){
            if(head==NULL) //linked list is empty
            {
                node *n = new node(data);
                this->head = n;
                this->tail = n;
                return;
            }
            node *temp = this->head;
            for(int i=0; i<pos; i++){
                temp=temp->next;
            }
            node* n = temp->next;
            temp->next = NULL;
            node *a = new node(data);
            temp->next = a;
            a->next = n;
        }

        void print(){
            cout<<"\nprinting node\n";
            node* temp = this->head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }

        void deleteNode(int pos){
            if(head==NULL) return;

            if(pos==0){
                node* temp = this->head;
                head = head->next;
                temp->next = NULL;
                delete temp;
                return;
            }

            int len = 0;
            node* temp = this->head;
            while(temp!=NULL){
                len++;
                temp = temp->next;
            }

            if(pos>=len) return;

            temp = this->head;
            node* prev = NULL;
            for(int i=0; i<pos; i++){
                prev = temp;
                temp=temp->next;
            }
            prev->next = temp->next;
            temp->next = NULL;
            delete temp;
        }
};

int main(){
    LinkedList ll;
    ll.print();
    ll.add(1);
    ll.add(2);
    ll.add(3);
    ll.add(4);
    ll.print();
    ll.deleteNode(2);
    ll.print();
    ll.add(50,1);
    ll.print();
}