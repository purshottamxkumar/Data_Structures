// A menu driven program containing all the basic operations in the single linked list
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

int count_list(Node *head) {
    int cnt = 0;
    Node *tmp = head;
    while(tmp) {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

Node* addAtBeg(Node *head, int val) {
    Node *tmp = new Node(val);

    if(head == NULL) {
        return tmp;
    }
    
    tmp->next = head;
    head = tmp;
    return head;
}

Node* addAtEnd(Node *head, int val) {
    Node *tmp = new Node(val);

    if(head == NULL) {
        return tmp;
    }

    Node *newtmp = head;
    while(newtmp->next) {
        newtmp = newtmp->next;
    }
    newtmp->next = tmp;
    return head;
}

Node* delFromBeg(Node *head) {
    if(head == NULL) {
        return head;
    }

    Node* tmp = head;
    head = head->next;
    delete tmp;
    return head;
}

Node* delFromEnd(Node *head) {
    if(head == NULL) {
        return head;
    }

    Node *tmp = head;
    if(count_list(head) == 1) {
        delete head;
        return NULL;
    }

    while(tmp->next->next) {
        tmp = tmp->next;
    }

    delete tmp->next;
    tmp->next = NULL;
    return head;
}

Node* construct_list(Node *head) {
    int num;
    cout << "\nEnter the number of nodes you want to add: ";
    cin >> num;

    for(int i = 0; i < num; i++) {
        cout << "\nEnter the element " << i + 1 << " : ";
        int ele;
        cin >> ele;
        head = addAtEnd(head, ele);
    }

    return head;
}

Node* deleteWholeList(Node *head) {
    if(head == NULL) {
        return head;
    }

    Node *tmp;
    while(head) {
        tmp = head;
        head = head->next;
        delete tmp;
    }

    return NULL;
}

void display_list(Node *head) {
    cout << "\nNodes are: \n\n";
    while(head) {
        cout << head->data << " ";
        head = head->next;
    } cout << "\n";
}

Node* reverse_list(Node *head) {
    Node *curr, *prev, *next;
    curr = head;
    prev = NULL;

    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main() {
    Node *head = NULL;
    int data;

    cout << "\nThese are the options: \n";
    while(1) {
        cout << "\n0.Construct a new Single Linked List";
        cout << "\n1.Insert at Beginning";
        cout << "\n2.Insert at End";
        cout << "\n3.Delete from Beginning";
        cout << "\n4.Delete from End";
        cout << "\n5.Reverse Linked List";
        cout << "\n6.Display the List";
        cout << "\n7.Count Number of Nodes";
        cout << "\n8.Completely Delete the list";
        cout << "\n9.Exit";

        cout << "\nEnter the choice: ";
        int choice;
        cin >> choice;
        switch(choice) {
            case 0: head = construct_list(head);
            break;

            case 1: cout << "\nEnter the element to add at beginning: ";
            cin >> data;
            head = addAtBeg(head, data);
            break;

            case 2: cout << "\nEnter the element to add at end: ";
            cin >> data;
            head = addAtEnd(head, data);
            break;

            case 3: head = delFromBeg(head);
            break;

            case 4: head = delFromEnd(head);
            break;

            case 5: head = reverse_list(head);
            break;

            case 6: display_list(head);
            break;

            case 7: cout << "\nNumber of nodes in the list are : " << count_list(head) << "\n";
            break;

            case 8: head = deleteWholeList(head);
            break;

            case 9: exit(1);

            default:
            cout << "\nWrong Choice of Option\n";
        }
    } cout << "\nHappy Coding!!!\n";

    return 0;
}