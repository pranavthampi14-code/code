#include <iostream>
#include <string>
using namespace std;
struct Node {
    string keyword;
    string meaning;
    Node *left, *right;
};
// Create new node
Node* createNode(string key, string mean) {
    Node* newNode = new Node;
    newNode->keyword = key;
    newNode->meaning = mean;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert keyword into BST
Node* insert(Node* root, string key, string mean) {
    if (root == NULL) return createNode(key, mean);
    if (key < root->keyword)
        root->left = insert(root->left, key, mean);
    else if (key > root->keyword)
        root->right = insert(root->right, key, mean);
    else
        cout << "Keyword already exists!\n";
    return root;
}
Node* search(Node* root, string key, int &comparisons) {
    if (root == NULL) return NULL;
    comparisons++;
    if (root->keyword == key) return root;
    if (key < root->keyword) return search(root->left, key, comparisons);
    return search(root->right, key, comparisons);
}
// Update meaning of a keyword
void update(Node* root, string key, string newMeaning) {
    int comparisons = 0;
    Node* found = search(root, key, comparisons);
    if (found) {
        found->meaning = newMeaning;
        cout << "Updated successfully!\n";
    } else {
        cout << "Keyword not found!\n";
    }
}

// Find minimum node (used in deletion)
Node* findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

// Delete keyword
Node* deleteNode(Node* root, string key) {
    if (root == NULL) return root;

    if (key < root->keyword)
        root->left = deleteNode(root->left, key);
    else if (key > root->keyword)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: No child / Case 2: One child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        Node* temp = findMin(root->right);
        root->keyword = temp->keyword;
        root->meaning = temp->meaning;
        root->right = deleteNode(root->right, temp->keyword);
    }
    return root;
}

// Display ascending order (inorder)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->keyword << " : " << root->meaning << endl;
        inorder(root->right);
    }
}

// Display descending order (reverse inorder)
void reverseInorder(Node* root) {
    if (root != NULL) {
        reverseInorder(root->right);
        cout << root->keyword << " : " << root->meaning << endl;
        reverseInorder(root->left);
    }
}

// Main menu-driven program
int main() {
    Node* root = NULL;
    int choice;
    string key, mean;

    do {
        cout << "\n--- Dictionary Menu ---\n";
        cout << "1. Add Keyword\n";
        cout << "2. Delete Keyword\n";
        cout << "3. Update Meaning\n";
        cout << "4. Display Ascending Order\n";
        cout << "5. Display Descending Order\n";
        cout << "6. Search Keyword (with comparisons)\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter keyword: ";
                cin >> key;
                cout << "Enter meaning: ";
                cin.ignore();
                getline(cin, mean);
                root = insert(root, key, mean);
                break;

            case 2:
                cout << "Enter keyword to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                break;

            case 3:
                cout << "Enter keyword to update: ";
                cin >> key;
                cout << "Enter new meaning: ";
                cin.ignore();
                getline(cin, mean);
                update(root, key, mean);
                break;

            case 4:
                cout << "\nAscending Order:\n";
                inorder(root);
                break;

            case 5:
                cout << "\nDescending Order:\n";
                reverseInorder(root);
                break;

            case 6: {
                cout << "Enter keyword to search: ";
                cin >> key;
                int comparisons = 0;
                Node* found = search(root, key, comparisons);
                if (found)
                    cout << "Found: " << found->keyword << " -> " << found->meaning 
                         << " (Comparisons: " << comparisons << ")\n";
                else
                    cout << "Keyword not found! (Comparisons: " << comparisons << ")\n";
                break;
            }

            case 7:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 7);

    return 0;
}
