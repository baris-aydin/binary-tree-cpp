#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() { root = nullptr; }

    // Insert function
    Node* insert(Node* root, int data) {
        if (!root) return new Node(data);
        if (data < root->data) root->left = insert(root->left, data);
        else root->right = insert(root->right, data);
        return root;
    }

    // Inorder Traversal (Left, Root, Right)
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Preorder Traversal (Root, Left, Right)
    void preorder(Node* root) {
        if (!root) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    // Postorder Traversal (Left, Right, Root)
    void postorder(Node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    // Search function
    bool search(Node* root, int key) {
        if (!root) return false;
        if (root->data == key) return true;
        if (key < root->data) return search(root->left, key);
        return search(root->right, key);
    }

    // Find the minimum value node
    Node* minValueNode(Node* root) {
        while (root && root->left) root = root->left;
        return root;
    }

    // Delete node from BST
    Node* deleteNode(Node* root, int key) {
        if (!root) return root;

        if (key < root->data) root->left = deleteNode(root->left, key);
        else if (key > root->data) root->right = deleteNode(root->right, key);
        else {
            // Node with one child or no child
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } 
            else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Node with two children
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
};

int main() {
    BinaryTree tree;

    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Preorder Traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorder(tree.root);
    cout << endl;

    cout << "Searching for 40: " << (tree.search(tree.root, 40) ? "Found" : "Not Found") << endl;

    cout << "Deleting 40\n";
    tree.root = tree.deleteNode(tree.root, 40);

    cout << "Inorder after deletion: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
