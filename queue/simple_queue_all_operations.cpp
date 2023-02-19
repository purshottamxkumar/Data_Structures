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

void insert_element(Node **start, Node **end, int value) {
    Node *tmp = new Node(value);
    if(*start == NULL) {
        *start = *end = tmp;
        return ;
    }
    Node *newtmp = *end;
    while(newtmp->next) {
        newtmp = newtmp->next;
    }
    newtmp->next = tmp;
}

void delete_element(Node **start, Node **end) {
    if(*start == NULL) return ;
    if((*start)->next == NULL) {
        delete *start;
        *start = *end = NULL;
    }

    Node *tmp = *start;
    *start = (*start)->next;
    delete tmp;
}

void create_queue(Node **start, Node **end) {
    cout << "\nEnter how many elements to insert: ";
    int num;
    cin >> num;
    for(int i = 0; i < num; i++) {
        cout << "\nEnter the " << i + 1 << " element: ";
        int ele;
        cin >> ele; 
        insert_element(start, end, ele);
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
    cout << "\nElements are : ";
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
        cout << "\n1.Create Simple Queue";
        cout << "\n2.Insert Element";
        cout << "\n3.Delete Element";
        cout << "\n4.Count Number of Elements";
        cout << "\n5.Display all the Elements";
        cout << "\n6.Exit";
        cout << "\n\nEnter Your Choice: ";
        int choice;
        cin >> choice;

        switch(choice) {
            case 1: create_queue(&start, &end);
            break;

            case 2: cout << "\nEnter the element to insert: ";
            cin >> data;
            insert_element(&start, &end, data);
            break;

            case 3: delete_element(&start, &end);
            break;

            case 4: cout << "\nNumber of Elements: " << count_elements(start) << "\n";
            break;

            case 5: display_elements(start);
            break;

            case 6: exit(1);

            default:
            cout << "\nWrong Choice\n";
        }
    }
    cout << "\nHappy Coding!!\n";
    return 0;
}