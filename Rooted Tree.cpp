#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ==================== 節點類別 ====================
class TreeNode {
public:
    string data;                  // 節點資料
    vector<TreeNode*> children;   // 子節點清單

    TreeNode(string value) {
        data = value;
    }
};

// ==================== Rooted Tree 類別 ====================
class RootedTree {
private:
    TreeNode* root;

    // 遞迴顯示樹結構
    void displayTree(TreeNode* node, int level) {
        if (node == NULL) return;

        for (int i = 0; i < level; i++) {
            cout << "  ";
        }
        cout << "- " << node->data << endl;

        for (int i = 0; i < node->children.size(); i++) {
            displayTree(node->children[i], level + 1);
        }
    }

    // 前序走訪：根 -> 子節點
    void preorder(TreeNode* node) {
        if (node == NULL) return;

        cout << node->data << " ";
        for (int i = 0; i < node->children.size(); i++) {
            preorder(node->children[i]);
        }
    }

    // 後序走訪：子節點 -> 根
    void postorder(TreeNode* node) {
        if (node == NULL) return;

        for (int i = 0; i < node->children.size(); i++) {
            postorder(node->children[i]);
        }
        cout << node->data << " ";
    }

public:
    RootedTree() {
        root = NULL;
    }

    // 建立根節點
    void setRoot(string value) {
        root = new TreeNode(value);
    }

    // 取得根節點
    TreeNode* getRoot() {
        return root;
    }

    // 新增子節點
    TreeNode* addChild(TreeNode* parent, string value) {
        if (parent == NULL) return NULL;

        TreeNode* child = new TreeNode(value);
        parent->children.push_back(child);
        return child;
    }

    // 顯示整棵樹
    void display() {
        if (root == NULL) {
            cout << "Tree is empty." << endl;
            return;
        }

        cout << "Rooted Tree structure:" << endl;
        displayTree(root, 0);
    }

    // 顯示走訪結果
    void traversal() {
        if (root == NULL) {
            cout << "Tree is empty." << endl;
            return;
        }

        cout << "\nPreorder Traversal: ";
        preorder(root);

        cout << "\nPostorder Traversal: ";
        postorder(root);

        cout << endl;
    }
};

// ==================== 主程式 ====================
int main() {
    RootedTree tree;

    // 建立根節點
    tree.setRoot("A");
    TreeNode* root = tree.getRoot();

    // 第一層子節點
    TreeNode* B = tree.addChild(root, "B");
    TreeNode* C = tree.addChild(root, "C");
    TreeNode* D = tree.addChild(root, "D");

    // 第二層子節點
    tree.addChild(B, "E");
    tree.addChild(B, "F");

    tree.addChild(C, "G");

    tree.addChild(D, "H");
    tree.addChild(D, "I");

    // 顯示樹結構
    tree.display();

    // 顯示樹的走訪
    tree.traversal();

    return 0;
}
