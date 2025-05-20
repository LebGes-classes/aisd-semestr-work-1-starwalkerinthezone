#ifndef AATREE_H
#define AATREE_H

struct Node{
    int value;
    int level;
    Node *right;
    Node *left;

    Node(int value, int level, Node *left, Node *right)
    {
        this->value = value;
        this->level = level;
        this->left = left;
        this->right = right;
    }
};

class AATree{
private:
    Node *root;

    Node *skew(Node *t);
    Node *split(Node *t);
    Node *decreaseLevel(Node *t);
    bool leaf(Node *t);
    Node *successor(Node *t);
    Node *predecessor(Node *t);
    void printTree(Node *node, int depth) const;
    Node *search(Node *node, int value) const;
    Node *deleteNode(int x, Node *t);
    Node *insert(int x, Node *t);

public:
    AATree();
    void inserting(int value);
    void remove(int value);
    Node *searching(int value);
    void print() const;
};
#endif //AATREE_H