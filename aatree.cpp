#include <iostream>
#include "aatree.h"

using namespace std;

AATree::AATree() : root(nullptr) {}


Node *AATree::skew(Node *t){
    if (t == nullptr)
    {
        return nullptr;
    }
    else if (t->left == nullptr)
    {
        return t;
    }
    else if (t->left->level == t->level)
    {
        Node *node = new Node(t->value, t->level, t->left->right, t->right);
        Node *node_res = new Node(t->left->value, t->left->level, t->left->left, node);
        return node_res;
    }
    else
    {
        return t;
    }
}

Node *AATree::split(Node *t){
    if (t == nullptr)
    {
        return nullptr;
    }
    else if (t->right == nullptr || t->right->right == nullptr)
    {
        return t;
    }
    else if (t->level == t->right->right->level)
    {
        Node *node1 = new Node(t->value, t->level, t->left, t->right->left);
        Node *node2 = new Node(t->right->value, t->right->level + 1, node1, t->right->right);
        return node2;
    }
    else
    {
        return t;
    }
}

Node *AATree::insert(int x, Node *t){
    if (t == nullptr)
    {
        return new Node(x, 1, nullptr, nullptr);
    }
    else if (x < t->value)
    {
        t->left = insert(x, t->left);
    }
    else if (x > t->value)
    {
        t->right = insert(x, t->right);
    }
    t = skew(t);
    t = split(t);
    return t;
}

Node *AATree::decreaseLevel(Node *t){
    int lm = 0;
    int rm = 0;
    if (t->left != nullptr)
    {
        lm = t->left->level;
    }
    if (t->right != nullptr)
    {
        rm = t->right->level;
    }
    int shouldBe = min(lm, rm) + 1;
    if (shouldBe < t->level)
    {
        t->level = shouldBe;

        if (shouldBe < t->right->level)
        {
            t->right->level = shouldBe;
        }
    }
    return t;
}

bool AATree::leaf(Node *t){
    if (t->right == nullptr && t->left == nullptr)
    {
        return true;
    }
    return false;
}

Node *AATree::successor(Node *t){
    t = t->right;
    while (t->left != nullptr)
    {
        t = t->left;
    }
    return t;
}

Node *AATree::predecessor(Node *t){
    t = t->left;
    while (t->right != nullptr)
    {
        t = t->right;
    }
    return t;
}

Node *AATree::deleteNode(int x, Node *t){
    if (t == nullptr)
    {
        return t;
    }
    else if (x > t->value)
    {
        t->right = deleteNode(x, t->right);
    }
    else if (x < t->value)
    {
        t->left = deleteNode(x, t->left);
    }
    else
    {
        if (leaf(t))
        {
            return nullptr;
        }
        else if (t->left == nullptr)
        {
            Node *l = successor(t);
            std::cout << l->value << std::endl;
            t->right = deleteNode(l->value, t->right);
            t->value = l->value;
        }
        else
        {
            Node *l = predecessor(t);
            t->left = deleteNode(l->value, t->left);
            t->value = l->value;
        }
    }
    t = decreaseLevel(t);
    t = skew(t);
    t->right = skew(t->right);
    if (t->right != nullptr)
    {
        t->right->right = skew(t->right->right);
    }
    t = split(t);
    t->right = split(t->right);
    return t;
}

Node *AATree::search(Node *node, int value) const{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (value == node->value)
    {
        return node;
    }
    if (value < node->value)
    {
        return search(node->left, value);
    }
    else
    {
        return search(node->right, value);
    }
}

void AATree::printTree(Node *node, int depth) const{
    if (node == nullptr)
    {
        return;
    }
    printTree(node->right, depth + 1);
    for (int i = 0; i < depth; i++)
    {
        std::cout << "    ";
    }
    std::cout << node->value << " [L" << node->level << "]" << std::endl;

    printTree(node->left, depth + 1);
}
void AATree::inserting(int value){
    root = insert(value, root);
}

void AATree::remove(int value){
    root = deleteNode(value, root);
}

Node *AATree::searching(int value){
    return search(root, value);
}

void AATree::print() const{
    printTree(root, 0);
}