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

void insert_element_from_start(Node **start, Node **end, int data) {
    Node *tmp = new Node(data);
    tmp->next = *start;
    if(*start) {
        *start = tmp;
    } else {
        *start = *end = tmp;
    }
}

void insert_element_from_end(Node **start, Node **end, int data) {
    Node *tmp = new Node(data);
    if(*end) {
        (*end)->next = tmp;
        *end = tmp;
    } else {
        *start = *end = tmp;
    }
}

void delete_element_from_start(Node **start, Node **end) {
    if(*start) {
        Node *tmp = *start;
        if((*start)->next == NULL) {
            *start = *end = NULL;
        } else {
            *start = (*start)->next;
        }
        delete tmp;
    } else cout << "\nDeque is Empty\n";
}

void delete_element_from_end(Node **start, Node **end) {
    if(*end) {
        Node *tmp = *end;
        if((*start)->next == NULL) {
            *start = *end = NULL;
            delete tmp;
        } else {
            Node *t = *start;
            while(t->next != tmp) {
                t = t->next;
            }
            t->next = NULL;
            delete tmp;
        }
    } else cout << "\nDeque is Empty\n";
}

void create_deque(Node **start, Node **end) {
    cout << "\nEnter how many elements to add: ";
    int num;
    cin >> num;
    for(int i = 0; i < num; i++) {
        cout << "\nEnter the element number " << i + 1 << " : ";
        int ele;
        cin >> ele;
        insert_element_from_end(start, end, ele);
    }
}

int count_elements(Node *start) {
    int cnt = 0;
    while(start) {
        cnt++;
        start = start->next;
    }
    return cnt;
}

void display_elements(Node *start) {
    cout << "\nElements are: ";
    while(start) {
        cout << start->data << " ";
        start = start->next;
    } cout << "\n";
}

int main() {
    Node *start, *end;
    start = end = NULL;
    int data;

    while(1) {
        cout << "\n1.Create Simple Deque";
        cout << "\n2.Insert Element At Beginning";
        cout << "\n3.Insert Element At End";
        cout << "\n4.Delete Element From Beginning";
        cout << "\n5.Delete Element From End";
        cout << "\n6.Count Number of Elements";
        cout << "\n7.Display all the Elements";
        cout << "\n8.Exit";
        cout << "\n\nEnter Your Choice: ";
        int choice;
        cin >> choice;

        switch(choice) {
            case 1: create_deque(&start, &end);
            break;

            case 2: cout << "\nEnter the element to insert at beginning: ";
            cin >> data;
            insert_element_from_start(&start, &end, data);
            break;

            case 3: cout << "\nEnter the element to insert at end: ";
            cin >> data;
            insert_element_from_end(&start, &end, data);
            break;

            case 4: delete_element_from_start(&start, &end);
            break;

            case 5: delete_element_from_end(&start, &end);
            break;

            case 6: if(start) {
                cout << "\nNumber of Elements: " << count_elements(start) << "\n";
            } else cout << "\nEmpty Deque\n";
            break;

            case 7: display_elements(start);
            break;

            case 8: exit(1);

            default:
            cout << "\nWrong Choice\n";
        }
    }
    cout << "\nHappy Coding!!\n";
    return 0;
}