#include<iostream>
using namespace std;

   class Node{
    public:
//node have data and two pointers 
	    int data;
	    Node * left;
	    Node * right;
//call constructor
	    Node(int value){
			data = value;
			left = NULL;
			right = NULL;
	                   }  
};


class BST{
public:
    Node * root;
//constructor
    BST(){
        root = NULL;
         }

//rules of bst

//helper function to make calling of function in main simple
    void insertHelper(int value){
        insert(root, value);
    }

    void insert(Node *curr, int value){

		// If root is NULL, then create a node and make it root. 
		if (root == NULL) root = new Node(value);

		// Else Decide to move left or right. 
		else if (value < curr->data)  {
			    // if left is already NULL, create a new node and link it. 
			    if (curr->left == NULL) curr->left = new Node(value);
			    // Move left and call insert there. 
			    else insert(curr->left, value);
		         }

		else {
			    // if right is already NULL, create a new node and link it. 
			    if (curr->right == NULL) curr->right = new Node(value);
			    // Move right and call insert there. 
			    else insert(curr->right, value);
		     }
                     }
//.....................................................................................



    void displayHelper(){
        display(root);
                         }


    void display(Node * curr){

        //base Case for empty tree and leaf nodes children.
        if( curr ==  NULL) return;
//printing left then middle then right 
		// IN order print.
		// Print left. 
		display(curr->left);

		// Print myself.
		cout << curr->data << ", ";

		// Print right.
		display(curr->right);
    }

//........................................................................
    Node * searchHelper(int value){
        return search(root, value);
                                  }


    Node * search(Node * curr, int value){
        // Are you the value? or Are you NULL?  if yes return curr
        if(curr == NULL || curr->data == value ) return curr;

        // else you search in right or left. 

        // Left
        else if(value < curr->data) return search(curr->left, value);
        // Right
        else  return search(curr->right, value);
    }
//.....................................................................................

};
//..............................................

int main(){

    BST bst1;

    bst1.insertHelper(5);
    bst1.insertHelper(3);
    bst1.insertHelper(1);
    bst1.insertHelper(4);
    bst1.insertHelper(2);
//display
    bst1.displayHelper();

    if(bst1.searchHelper(5) != NULL){
        cout << endl << bst1.searchHelper(5)->data << endl;
                                    }
    else cout<<"binary tree is empty"<<endl;
}























