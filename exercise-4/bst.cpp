#include <iostream>
#include <string>

using namespace std;

struct node
{
    node *leftChild;
    node *rightChild;
    string key;
};

void insert(node *&root, string key)
{
    if (root == nullptr)
    {
        root = new node();
        root->key = key;
    }
    else if (root->key.compare(key) > 0)
    {
        insert(root->leftChild, key);
    }
    else
    {
        insert(root->rightChild, key);
    }
}

void list(node &root)
{
}

void free(node &root)
{
}

int main(int argc, char *argv[])
{
    node *root = NULL;

    insert(root, "aaa");
    insert(root, "bbb");
}