#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* push_element(Node *top, int ele) {
    Node *tmp = new Node(ele);
    tmp->next = top;
    top = tmp;
    return top;
}

Node* pop_element(Node *top) {
    if(top) {
        int data = top->data;
        Node *tmp = top;
        top = top->next;
        delete tmp;
    }
    return top;
}

Node* create_stack(Node *top) {
    cout << "\nEnter how many elements to add: ";
    int num;
    cin >> num;

    for(int i = 0; i < num; i++) {
        cout << "\nEnter the element " << i + 1 << " : ";
        int ele;
        cin >> ele;
        top = push_element(top, ele);
    }

    return top;
}

void display(Node *top) {
    if(top) {
        cout << "\nElements are: ";
        while(top) {
            cout << top->data << " ";
            top = top->next;
        } cout << "\n";
    } else cout << "\nStack is Empty\n";
}

int top_element(Node *top) {
    if(top) {
        return top->data;
    } else return -1;
}

int stack_size(Node *top) {
    int cnt = 0;
    while(top) {
        cnt++;
        top = top->next;
    }
    return cnt;
}

int main() {
    int data;
    Node *top = NULL;

    while(1) {
        cout << "\n1.Create Stack";
        cout << "\n2.Push Element";
        cout << "\n3.Pop Element";
        cout << "\n4.Display all Elements";
        cout << "\n5.Show top element";
        cout << "\n6.Find Size of Stack";
        cout << "\n7.Check if Stack is Empty";
        cout << "\n8.Exit";

        cout << "\nEnter Your Choice: ";
        int choice;
        cin >> choice;

        switch(choice) {
            case 1: top = create_stack(top);
            break;

            case 2: cout << "\nEnter the element to add: "; 
            cin >> data;
            top = push_element(top, data);
            break;

            case 3: top = pop_element(top);
            break;

            case 4: display(top);
            break;

            case 5: if(top_element(top) != -1) {
                cout << "\nTop element is: " << top_element(top) << "\n";
            } else cout << "\nEmpty Stack\n";
            break;

            case 6: cout << "\nThe size of the Stack is: " << stack_size(top) << "\n";
            break;

            case 7: if(top) {
                cout << "\nStack is Not Empty";
            } else cout << "\nStack is Empty";
            cout << "\n";
            break;

            case 8: exit(1);

            default: 
            cout << "\nWrong Choice\n";
        }
    }
    return 0;
}