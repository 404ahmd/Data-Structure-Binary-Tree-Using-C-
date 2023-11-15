#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    //CONSTRUCTOR FOR CREATE A NEW NODE
    Node (int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

//CLASS FOR BINARY TREE
class binaryTree{
    private:
    Node *root;

    //RECRUSIVE FUNCTION FOR INSERT DATA INTO TREE
    Node *insertRecrusive(Node *current, int value){
        if (current == NULL)
        {
            return new Node(value);
        }

        if (value < current->data)
        {
            current->left = insertRecrusive(current->left, value);
        }else if(value > current->data){
            current->right = insertRecrusive(current->right, value);
        }
        
        return current;
    }


    //RECRUSIVE FUNCTION FOR SEARCHING DATA FORM TREE
    Node *searchRecrusive(Node *current, int value){
        if (current == nullptr || current->data == value)
        {
            return current;
        }

        if (value < current->data)
        {
            return searchRecrusive(current->left, value);
        }else{
            return searchRecrusive(current->right, value);
        }
        
        
    }

    //RECRUSIVE FUNCITON FOR PRINT DATA BY PREORDER
    void preorderRecrusive(Node *current){
        if (current != nullptr)
        {
            cout<<current->data<<" ";
            preorderRecrusive(current->left);
            preorderRecrusive(current->right);
        }
        
    }

    //RECRUSIVE FUNCITON FOR PRINT DATA BY INORDER
    void inorderRecrusive(Node *current){
        if (current != nullptr)
        {
            inorderRecrusive(current->left);
            cout<<current->data<<" ";
            inorderRecrusive(current->right);
        }
        
    }

    //RECRUSIVE FUNCITON FOR PRINT DATA BY POSTORDER
    void postorderRecrusive(Node *current){
        if (current != nullptr)
        {
            postorderRecrusive(current->left);
            postorderRecrusive(current->right);
            cout<<current->data<<" ";
        }
        
    }

    public:
    binaryTree(){
        root = nullptr;
    }

    //FUNCTION FOR INSERT A NEW DATA INTO  TREE
    void insertData(int value){
        root = insertRecrusive(root, value);
    }

    //FUNCTION FOR SEARCH DATA ON A TREE
    bool searchData(int value){
        Node *result = searchRecrusive(root, value);
        return result != nullptr;
    }

    //FUNCTION FOR PRINT DATA BY PREORDER
    void printPreorder(){
        cout<<"Preorder :";
        preorderRecrusive(root);
    }

      //FUNCTION FOR PRINT DATA BY INORDER
    void printInorder(){
        cout<<"\n Inorder :";
        inorderRecrusive(root);
    }

      //FUNCTION FOR PRINT DATA BY POSTORDER
    void printPostorder(){
        cout<<"\n Postorder :";
        postorderRecrusive(root);
    }
};


int main(int argc, char const *argv[])
{
    binaryTree Tree;
    Tree.insertData(10);
    Tree.insertData(20);
    Tree.insertData(30);
    Tree.insertData(40);
    Tree.insertData(50);

    Tree.printPreorder();
    Tree.printInorder();
    Tree.printPostorder();

    //SEARCHING DATA FROM TREE
    int searchValue = 40;
    if (Tree.searchData(searchValue))
    {
        cout<<searchValue<<"\n Find on a tree \n";
    }else
    {
        cout<<searchValue<<"\n Value Not Found \n";
    }
    
    
    return 0;
}


