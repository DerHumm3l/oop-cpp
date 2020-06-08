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

    cout << root->key << endl;

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
    string input;
    node *root = NULL;

    do
    {
        cout << "Geben Sie eine beliebige Zeichenkette ein ('.' zum Beenden): ";
        getline(cin, input);

        if (input == ".")
        {
            break;
        }
        else
        {
            insert(root, input);
        }
    } while (true);

    cout << endl
         << "Sortierte Liste" << endl;
    list(root);

    free(root);

    cout << endl
         << "Enter zum beenden";
    getchar();
}