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

void list(node *&root)
{
    if (root->leftChild != nullptr)
    {
        list(root->leftChild);
    }

    cout << "Ich bin Knoten mit dem Wert " << root->key << endl;

    if (root->rightChild != nullptr)
    {
        list(root->rightChild);
    }
}

void free(node *&root)
{
    if (root->leftChild != nullptr)
    {
        free(root->leftChild);
    }
    if (root->rightChild != nullptr)
    {
        free(root->rightChild);
    }

    root->leftChild = NULL;
    root->rightChild = NULL;
    delete root;
}

int main(int argc, char *argv[])
{
    node *root = NULL;

    insert(root, "aaa");
    insert(root, "bbb");
    insert(root, "ccc");
    insert(root, "ddd");
    insert(root, "eee");

    list(root);

    free(root);

    getchar();
}