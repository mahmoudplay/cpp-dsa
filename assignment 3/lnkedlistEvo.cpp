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

    void search(int value){
        if(isEmpty()){ 
            cout << "The list is empty" << endl;
            return;
        }

        Node* temp = head;
        int i = 1;

        while(temp != NULL){
            if(temp->data == value){
                cout << "Found " << temp->data << " in position number " << i << endl;
                return;
            }

            temp = temp->next;
            i++;
        }

        cout << "Not found" << endl;
    }

    void append(int value){

        Node* temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        temp->next = newNode;

        cout << value << " has been added in last" << endl;
    }

    void insertAtPosition(int pos, int value){
        Node* temp = head;

        for(int i = 1; i<pos-1; i++){
            if(temp == NULL){
                cout << "Out of range" << endl;
                return;
            }

            temp = temp->next;
        }

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = temp->next;

        temp->next = newNode;

        cout << value << " has been added in position number " << pos << endl;
    }

    void deleteNode(int pos){
        Node* temp = head;

        for(int i = 1; i<pos-1; i++){
            if(temp == NULL){
                cout << "Out of range" << endl;
                return;
            }

            temp = temp->next;
        }

        cout << temp->next->data << " has been deleted" << endl;

        temp->next = temp->next->next;
    }

};

int main(){
    LinkedList lst;
    int choice;

    bool lop = true;

    while (lop) {
        cout << "Select your opration:\n[1] Insert number\n[2] Display\n[3] Counter of elemets\n[4] Search for a number\n[5] Append number\n[6] Insert in position\n[7] Delete a number\n[8] Exit\n\nYour choice: ";
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
            int numS;
            cout << "Enter the number: ";
            cin >> numS;
            lst.search(numS);
            break;
        case 5:
            int numA;
            cout << "Enter the number: ";
            cin >> numA;
            lst.append(numA);
            break;
        case 6:
            int pos, numP;
            cout << "Enter the position: ";
            cin >> pos;
            cout << "Enter the number: ";
            cin >> numP;
            lst.insertAtPosition(pos,numP);
            break;
        case 7:
            int posD;
            cout << "Enter the position: ";
            cin >> posD;
            lst.deleteNode(posD);
            break;
        case 8:
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