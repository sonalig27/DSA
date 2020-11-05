
#include <iostream>
#include "Queue.h"

using namespace std;


class Tree {
private:
    Node* root;
public:
    Tree() {
        root = NULL;
    }

    Node* getRoot() {
        return root;
    }
    void createTree() {
        int data;
        Queue q(10);
        Node* temp, * p;
        cout << "Enter the root node: ";
        cin >> data;
        root = new Node();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        q.enqueue(root);
        while (!q.isEmpty()) {
            p = q.dequeue();
            cout << "Enter the left child of node "<<p->data <<" :";
            cin >> data;
            if (data != -1) {
                temp = new Node();
                temp->data = data;
                temp->left = NULL;
                temp->right = NULL;
                p->left = temp;
                q.enqueue(temp);
            }
            cout << "Enter the right child of node " << p->data << " :";
            cin >> data;
            if (data != -1) {
                temp = new Node();
                temp->data = data;
                temp->left = NULL;
                temp->right = NULL;
                p->right = temp;
                q.enqueue(temp);
            }
        }
    }

    void preOrder(Node* p) {
        if (p != NULL) {
            cout << p->data << " ";
            preOrder(p->left);
            preOrder(p->right);
        }
    }

    void inOrder(Node* p) {
        if (p != NULL) {
            inOrder(p->left);
            cout << p->data << " ";
            inOrder(p->right);
        }
    }

    void postOrder(Node* p) {
        if (p != NULL) {
            postOrder(p->left);
            postOrder(p->right);
            cout << p->data << " ";
        }
    }

    void levelOrder() {
        Queue q(10);
        Node* p;
        cout << root->data << " ";
        q.enqueue(root);
        while (!q.isEmpty()) {
            p = q.dequeue();
            if (p->left) {
                cout << p->left->data << " ";
                q.enqueue(p->left);
            }
            if (p->right) {
                cout << p->right->data << " ";
                q.enqueue(p->right);
            }
        }
    }

    int countNodes(Node* p) {
        int x, y;
        if (p != NULL) {
            x = countNodes(p->left);
            y = countNodes(p->right);
            return x + y + 1;
        }
        return 0;

    }

    int treeHeight(Node* p) {
        int x, y;
        if (p != NULL) {
            x = treeHeight(p->left);
            y = treeHeight(p->right);
            if (x > y)
                return x + 1;
            else
                return y + 1;
        }
        return 0;

    }

    int countDegree2Nodes(Node* p) {
        int x, y;
        if (p != NULL) {
            x = countDegree2Nodes(p->left);
            y = countDegree2Nodes(p->right);
            if (p->left && p->right)
                return x + y + 1;
            else
                return x + y;
        }
        return 0;

    }


    int countDegree1Nodes(Node* p) {
        int x, y;
        if (p != NULL) {
            x = countDegree1Nodes(p->left);
            y = countDegree1Nodes(p->right);
            if ((p->left != NULL) ^ (p->right !=NULL))
                return x + y + 1;
            else
                return x + y;
        }
        return 0;

    }
    int countLeafNodes(Node* p) {
        int x, y;
        if (p != NULL) {
            x = countLeafNodes(p->left);
            y = countLeafNodes(p->right);
            if (!p->left && !p->right)
                return x + y + 1;
            else
                return x + y;
        }
        return 0;

    }

    int sumNodes(Node* p) {
        int x, y;
        if (p != NULL) {
            x = sumNodes(p->left);
            y = sumNodes(p->right);
            return x + y + p->data;
        }
        return 0;

    }

    void destroyTree(Node *p) {
        if (p != NULL) {
            destroyTree(p -> left);
            destroyTree(p -> right);
            delete p;
        }
    }
};

int main()
{
    Tree* t1 = new Tree();
    t1->createTree();
    cout << "Successfully Filled the tree" << endl;
    t1->preOrder(t1->getRoot());
    cout << endl;
    t1->inOrder(t1->getRoot());
    cout << endl;
    t1->postOrder(t1->getRoot());
    cout << endl;
    t1->levelOrder();
    cout << endl;
    cout << t1->countNodes(t1->getRoot()) <<endl;
    cout << endl;
    cout << t1->sumNodes(t1->getRoot()) << endl;
    cout << endl;
    cout << t1->countDegree2Nodes(t1->getRoot()) << endl;
    cout << endl;
    cout << t1->countDegree1Nodes(t1->getRoot()) << endl;
    cout << endl;
    cout << t1->countLeafNodes(t1->getRoot()) << endl;
    cout << endl;
    cout << t1->treeHeight(t1->getRoot()) << endl;
    t1->destroyTree(t1->getRoot());
}