#include <iostream>
#include "Task_lab_5.h"

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Конструктор класу TreeNode для створення нового вузла дерева з заданим значенням
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

public:
    // Конструктор класу BinaryTree, що ініціалізує корінь дерева як nullptr
    BinaryTree() : root(nullptr) {}

    // Деструктор класу BinaryTree, який видаляє всі вузли дерева
    ~BinaryTree() {
        deleteTree(root);
    }

    // Метод для вставки нового вузла з заданим значенням в дерево
    void insert(int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            cout << "Inserted " << val << " as the root." << endl;
        } else {
            insertRecursive(root, val);
        }
    }

    // Метод для обходу дерева в ширину
    void breadthFirstTraversal() const {
        cout << "Breadth-first traversal: ";
        breadthFirstTraversalHelper(root);
        cout << endl;
    }

    // Метод для обходу дерева в порядку зростання значень
    void inOrderTraversal() const {
        cout << "In-order traversal: ";
        inOrderTraversalHelper(root);
        cout << endl;
    }

    // Метод для обходу дерева в зворотньому порядку
    void reverseOrderTraversal() const {
        cout << "Reverse-order traversal: ";
        reverseOrderTraversalHelper(root);
        cout << endl;
    }

private:
    // Рекурсивний метод для вставки нового вузла в піддерево з коренем node
    void insertRecursive(TreeNode* node, int val) {
        if (val < node->data) {
            if (node->left == nullptr) {
                node->left = new TreeNode(val);
                cout << "Inserted " << val << " to the left of " << node->data << endl;
            } else {
                insertRecursive(node->left, val);
            }
        } else if (val > node->data) {
            if (node->right == nullptr) {
                node->right = new TreeNode(val);
                cout << "Inserted " << val << " to the right of " << node->data << endl;
            } else {
                insertRecursive(node->right, val);
            }
        } else {
            cout << "Value " << val << " already exists in the tree." << endl;
        }
    }

    // Рекурсивний метод для обходу дерева в ширину
    void breadthFirstTraversalHelper(TreeNode* node) const {
        if (node == nullptr)
            return;

        cout << node->data << " ";

        if (node->left != nullptr)
            breadthFirstTraversalHelper(node->left);

        if (node->right != nullptr)
            breadthFirstTraversalHelper(node->right);
    }

    // Рекурсивний метод для обходу дерева в порядку зростання значень
    void inOrderTraversalHelper(TreeNode* node) const {
        if (node == nullptr)
            return;

        inOrderTraversalHelper(node->left);
        cout << node->data << " ";
        inOrderTraversalHelper(node->right);
    }

    // Рекурсивний метод для обходу дерева в зворотньому порядку
    void reverseOrderTraversalHelper(TreeNode* node) const {
        if (node == nullptr)
            return;

        reverseOrderTraversalHelper(node->right);
        cout << node->data << " ";
        reverseOrderTraversalHelper(node->left);
    }

    // Рекурсивний метод для видалення всього дерева
    void deleteTree(TreeNode* node) {
        if (node == nullptr)
            return;

        deleteTree(node->left);
        deleteTree(node->right);

        delete node;
    }
};

int main() {
    mainTask2();
    BinaryTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(17);

    tree.breadthFirstTraversal();
    tree.inOrderTraversal();
    tree.reverseOrderTraversal();

    return 0;
}
