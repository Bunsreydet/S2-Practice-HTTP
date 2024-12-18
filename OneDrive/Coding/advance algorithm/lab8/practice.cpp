#include<iostream>
#include<fstream>
#include<limits>
using namespace std;

struct Node
{
    string data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class BST
{
    public:

    int size;
    Node *root;

    BST()
    {
        size = 0;
        root = NULL;
    }

    Node* insert(Node *root, string newData)
    {
    
        if(root == NULL)
        {
            root = new Node;
            root ->data = newData;
            root ->left = NULL;
            root ->right = NULL;
            size++;
        }
        else if(newData > root->data)
        {
            root->right = insert(root->right, newData);
        }
        else if(newData < root->data)
        {
            root->left = insert(root->left, newData);
        }
        return root;
    }

    void preorder(Node *root) //top-down & left to right DLR
    {
        if(root != NULL)
        {
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(Node *root) //root->left LDR
    {
        if(root!=NULL)
        {
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }

    void postOrder(Node *root)  //LRD
    {
        if(root!=NULL)
        {
            inorder(root->left);
            inorder(root->right);
            cout<<root->data<<" ";
        }
    }

    bool search(string data)
    {
        Node *t;
        t = root;
        while (t != NULL)
        {
            if(t -> data == data)
            {
                return true;
            }
            else if(data > t -> data)
            {
                t = t -> right;
            }
            else
            {
                t = t -> left;
            }
        }
        return false;
    }


    ~BST()
    {
        deleteTree(root);
    }

    void deleteTree(Node* root)
    {
        if(root != NULL)
        {
            deleteTree(root -> left);
            deleteTree(root -> right);
            delete root;
        }
    }
};

int main()
{
    BST* tree = new BST();

    ifstream Myfile("Lab08_Data_ID_Numbers_1M.csv");
    int count = 0;
    string data;
    if(Myfile.is_open())
    {
        while(!Myfile.eof())
        {
            if(count == 0)
            {
                string temp;
                getline(Myfile,temp);
                count = 1;
            }
            else
            (
                getline(Myfile, Data, ",");
            )
        }  
    }

    cout << "Inorder traversal after insertion: ";
    tree.inorder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    tree.preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postOrder(root);
    cout << endl;
    
    int n;
    while(true)
    {
        cout<<"Enter the ID to search: ";
        if(!(cin>>n))
        {
            cout<<"Invalid input.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if(tree.search(n))
        {
            cout<<"This ID "<<n<<"exists in the BST: \n";
        }
        else
        {
            cout<<"Not found\n";
        }
    }
    return 0;
}