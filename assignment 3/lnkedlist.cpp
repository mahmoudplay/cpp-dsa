#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    public:
    Node* head;

    LinkedList(){
        head = nullptr;
    }

    bool isEmpty(){
        return head == NULL;
    }

    void insert(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;

        cout << value << " has been added" << endl;
    }

    void display(){
        if(isEmpty()){ 
            cout << "The list is empty" << endl;
            return;
        }

        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        
        cout << endl;
    }

    void counter(){
        Node* temp = head;
        int i = 0;
        while(temp != NULL){
            temp = temp->next;
            i++;
        }
        
        cout << i << endl;
    }

};

int main(){
    LinkedList lst;
    int choice;

    bool lop = true;

    while (lop) {
        cout << "Select your opration:\n[1] Insert number\n[2] Display\n[3] Counter of elemets\n[4] Exit\n\nYour choice: ";
        cin >> choice;

        cout << "\n";
        
        switch (choice) {
        case 1:
            int num;
            cout << "Enter the number: ";
            cin >> num;
            lst.insert(num);
            break;
        case 2:
            lst.display();
            break;
        case 3:
            lst.counter();
            break;
        case 4:
            cout << "Thanks for using" << endl;
            lop = false;
            break;
        default:
            cout << "error" << endl;
            break;
        }

        cout << "\n\n";
    }
}