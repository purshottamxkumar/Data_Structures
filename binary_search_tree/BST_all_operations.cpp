#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* add_element(Node *root, int ele) {
    if(root == NULL) {
        return new Node(ele);
    } else if(root->data == ele) {
        cout << "\nKey already Present\n";
    } else if(root->data > ele) {
        root->left = add_element(root->left, ele);
    } else root->right = add_element(root->right, ele);
    return root;
}

Node* remove_element(Node *root, int ele) {
    
}

Node* create_bst(Node *root) {
    cout << "\nEnter how many elements to add: ";
    int num;
    cin >> num;
    for(int i = 0; i < num; i++) {
        int ele;
        cin >> ele;
        root = add_element(root, ele);
    }
}

int main() {
    int data, choice;
    Node *root = NULL;

    while(1) {
        cout << "\n1.Create a Binary Search Tree";
        cout << "\n2.Insert element in BST";
        cout << "\n3.Delete element from BST";
        cout << "\n4.Preorder Traversal";
        cout << "\n5.Inorder Traversal";
        cout << "\n6.Postorder Traversal";
        cout << "\n7.Size of BST";
        cout << "\n8.Exit";
        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch(choice) {
            case 1: create_bst(root);
            break;
        }
    }
    return 0;
}