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

int search_key(Node *root, int ele) {
    if(!root) return -1;
    else if(root->data == ele) {
        return 1;
    }
    else if(root->data > ele) {
        return search_key(root->left, ele);
    } return search_key(root->right, ele);
}

Node* insert_element(Node *root, int ele) {
    if(root == NULL) {
        return new Node(ele);
    } else if(root->data > ele) {
        root->left = insert_element(root->left, ele);
    } else if(root->data < ele) {
        root->right = insert_element(root->right, ele);
    } else cout << "\nKey " << ele << " Already Present\n";
    return root;
}

Node* delete_element(Node *root, int ele) {
    if(root == NULL) {
        cout << "\nKey Not Present in BST\n";
    } else if(root->data > ele) {
        root->left = delete_element(root->left, ele);
    } else if(root->data < ele) {
        root->right = delete_element(root->right, ele);
    } else {
        if(root->left == NULL && root->right == NULL) {
            // leaf node
            delete root;
            return NULL;
        } else if(root->left && root->right) {
            // two children
            Node *tmp = root->right;
            while(tmp->left) {
                tmp = tmp->left;
            }
            swap(root->data, tmp->data);
            root->right = delete_element(root->right, tmp->data);
        } else {
            Node *tmp = root;
            if(root->left) {
                root = root->left;
            }
            if(root->right) {
                root = root->right;
            }
            delete tmp;
        }
    }
    return root;
}

Node* createBST(Node *root) {
    cout << "\nEnter how many keys to insert: ";
    int num;
    cin >> num;
    for(int i = 0; i < num; i++) {
        cout << "\nEnter the key number " << i + 1 << ": ";
        int ele;
        cin >> ele;
        root = insert_element(root, ele);
    }
    cout << "\n### BINARY SEARCH TREE CREATED SUCCESSFULLY ###\n";
    return root;
}

void preorder_traversal(Node *root) {
    if(root) {
        cout << root->data << " ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void inorder_traversal(Node *root) {
    if(root) {
        inorder_traversal(root->left);
        cout << root->data << " ";
        inorder_traversal(root->right);
    }
}

void postorder_traversal(Node *root) {
    if(root) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->data << " ";
    }
}

int sizeOfBST(Node *root) {
    if(root) {
        return 1 + sizeOfBST(root->left) + sizeOfBST(root->right);
    } else return 0;
}

Node* delete_tree(Node *root) {
    if(root) {
        root->left = delete_tree(root->left);
        root->right = delete_tree(root->right);
        delete root;
    }
    return NULL;
}

int main() {
    int key, choice;
    Node *root = NULL;

    while(1) {
        cout << "\n1.Create a Binary Search Tree (BST)";
        cout << "\n2.Insert element in BST";
        cout << "\n3.Delete element from BST";
        cout << "\n4.Preorder Traversal";
        cout << "\n5.Inorder Traversal";
        cout << "\n6.Postorder Traversal";
        cout << "\n7.Size of BST";
        cout << "\n8.Completely Delete the BST";
        cout << "\n9.Exit";
        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch(choice) {
            case 1: root = createBST(root);
            break;

            case 2: cout << "\nEnter the key to insert: ";
            cin >> key;
            root = insert_element(root, key);
            break;

            case 3: cout << "\nEnter the key to delete: ";
            cin >> key;
            root = delete_element(root, key);
            break;

            case 4: cout << "\nPreorder traversal is: ";
            preorder_traversal(root);
            cout << "\n";
            break;

            case 5: cout << "\nInorder traversal is: ";
            inorder_traversal(root);
            cout << "\n";
            break;

            case 6: cout << "\nPostorder traversal is: ";
            postorder_traversal(root);
            cout << "\n";
            break;

            case 7: cout << "\nSize of the BST is: " << sizeOfBST(root) << "\n";
            break;

            case 8: root = delete_tree(root);
            break;

            case 9: exit(1);

            default: cout << "\nWrong Choice\n";
        }
    }
    return 0;
}