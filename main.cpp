#include <iostream>
#include "aatree.h"

int main()
{
    std::cout << "hello, world!" << std::endl;
    AATree tree;

    tree.inserting(4);
    tree.inserting(2);
    tree.print();
    std::cout << std::endl << "END" << std::endl;

    tree.inserting(1);
    tree.print();
    std::cout << std::endl << "END" << std::endl;

    tree.inserting(3);
    tree.print();
    std::cout << std::endl << "END" << std::endl;

    tree.inserting(10);
    tree.inserting(6);
    tree.inserting(5);
    tree.inserting(8);
    tree.inserting(7);
    tree.inserting(9);
    tree.inserting(12);
    tree.inserting(11);
    tree.inserting(13);
    tree.print();

    tree.remove(1);
    tree.print();
    std::cout << std::endl << "END" << std::endl;

    Node *node12 = tree.searching(12);
    if (node12 != nullptr)
    {
        std::cout << node12->value;
    }

    return 0;
}