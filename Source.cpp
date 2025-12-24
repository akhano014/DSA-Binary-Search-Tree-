#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* Left;
    Node* Right;

    Node(int d) {
        data = d;
        Left = NULL;
        Right = NULL;
    }
};

Node* InsertAtBST(Node*& root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
        root->Right = InsertAtBST(root->Right, data);
    else
        root->Left = InsertAtBST(root->Left, data);

    return root;
}

void Takeinput(Node*& root) {
    int data;
    cout << "Enter data (-1 to stop): ";
    cin >> data;
    while (data != -1) {
        InsertAtBST(root, data);
        cin >> data;
    }
}

void levelorderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else {
            cout << temp->data << " ";
            if (temp->Left)
                q.push(temp->Left);
            if (temp->Right)
                q.push(temp->Right);
        }
    }
}

void InorderTraversal(Node* root) {
    if (root == NULL) return;
    InorderTraversal(root->Left);
    cout << root->data << " ";
    InorderTraversal(root->Right);
}

void PreorderTraversal(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    PreorderTraversal(root->Left);
    PreorderTraversal(root->Right);
}

void PostorderTraversal(Node* root) {
    if (root == NULL) return;
    PostorderTraversal(root->Left);
    PostorderTraversal(root->Right);
    cout << root->data << " ";
}

bool SearchBST(Node*& root, int value) {
    if (root == NULL) {
        return false;
    }
    if (root->data == value) {
        return true;
    }

    if (root->data > value) {
        return SearchBST(root->Left,value);
    }
    else {
        return SearchBST(root->Right, value);
    }
}

int main() {
    Node* root = NULL;
    int choice;

    do {
        cout << "\n\n--- BST MENU ---\n";
        cout << "1. Create BST\n";
        cout << "2. Level Order Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Search in BST\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            Takeinput(root);
            break;

        case 2:
            cout << "Level Order Traversal:\n";
            levelorderTraversal(root);
            break;

        case 3:
            cout << "Inorder Traversal: ";
            InorderTraversal(root);
            cout << endl;
            break;

        case 4:
            cout << "Preorder Traversal: ";
            PreorderTraversal(root);
            cout << endl;
            break;

        case 5:
            cout << "Postorder Traversal: ";
            PostorderTraversal(root);
            cout << endl;
            break;

        case 6: {
            int key;
            cout << "Enter value to search: ";
            cin >> key;

            if (SearchBST(root, key))
                cout << "Value FOUND in BST\n";
            else
                cout << "Value NOT FOUND in BST\n";
            break;
        }

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}

