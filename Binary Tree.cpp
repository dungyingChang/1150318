#include <iostream>
#include <string>
using namespace std;

// ==================== 節點類別 ====================
class TreeNode {
public:
    string data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// ==================== Binary Tree 類別 ====================
class BinaryTree {
private:
    TreeNode* root;

    // 顯示樹結構（旋轉90度）
    void displayTree(TreeNode* node, int space) {
        if (node == NULL) return;

        space += 5;

        displayTree(node->right, space);

        cout << endl;
        for (int i = 5; i < space; i++) {
            cout << " ";
        }
        cout << node->data << endl;

        displayTree(node->left, space);
    }

    // 前序走訪：根 -> 左 -> 右
    void preorder(TreeNode* node) {
        if (node == NULL) return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // 中序走訪：左 -> 根 -> 右
    void inorder(TreeNode* node) {
        if (node == NULL) return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // 後序走訪：左 -> 右 -> 根
    void postorder(TreeNode* node) {
        if (node == NULL) return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() {
        root = NULL;
    }

    void setRoot(string value) {
        root = new TreeNode(value);
    }

    TreeNode* getRoot() {
        return root;
    }

    TreeNode* addLeft(TreeNode* parent, string value) {
        if (parent == NULL) return NULL;
        parent->left = new TreeNode(value);
        return parent->left;
    }

    TreeNode* addRight(TreeNode* parent, string value) {
        if (parent == NULL) return NULL;
        parent->right = new TreeNode(value);
        return parent->right;
    }

    void display() {
        if (root == NULL) {
            cout << "Tree is empty." << endl;
            return;
        }

        cout << "Binary Tree structure:" << endl;
        displayTree(root, 0);
    }

    void traversal() {
        if (root == NULL) {
            cout << "Tree is empty." << endl;
            return;
        }

        cout << "\nPreorder Traversal: ";
        preorder(root);

        cout << "\nInorder Traversal: ";
        inorder(root);

        cout << "\nPostorder Traversal: ";
        postorder(root);

        cout << endl;
    }
};

// ==================== 主程式 ====================
int main() {
    BinaryTree tree;

    // 建立根節點
    tree.setRoot("A");
    TreeNode* root = tree.getRoot();

    // 建立二元樹
    TreeNode* B = tree.addLeft(root, "B");
    TreeNode* C = tree.addRight(root, "C");

    TreeNode* D = tree.addLeft(B, "D");
    TreeNode* E = tree.addRight(B, "E");

    TreeNode* F = tree.addLeft(C, "F");
    TreeNode* G = tree.addRight(C, "G");

    // 顯示樹結構
    tree.display();

    // 顯示走訪結果
    tree.traversal();

    return 0;
}
