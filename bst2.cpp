#include<iostream>
using namespace std;


class Node{
public:
//parent include
    int data;
    Node * left;
    Node * right;
    Node * parent;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
        parent = NULL;
    }  
};
//.......................................

class BST{
public:
    Node * root;
    int i;
    BST(){
        root = NULL;
        i=0;
    }

//...........................................................

    void insertHelper(int value){
        insert(root, value);
    }
    void insert(Node *curr, int value){
        // If root is NULL, then create a node and make it root. 
       		 if (root == NULL) root = new Node(value);

        // Else Decide to move left or right. 
        	else if (value < curr->data)  {
						// if left is already NULL, create a new node and link it. 
						if (curr->left == NULL) {
									curr->left = new Node(value);
							   		curr->left->parent = curr;
						   						}
						// Move left and call insert there. 
						else insert(curr->left, value);
       										 }


           else {
                     // if right is already NULL, create a new node and link it. 
				    if (curr->right == NULL) {
				        curr->right = new Node(value);
				        curr->right->parent = curr;
            								}
                     // Move right TILL RIGHT IS NULL and call insert there. 
           			else insert(curr->right, value);
            }
    }

//............................................................
    void displayHelper(){
        display(root);
    }
    void display(Node * curr){
         
        // Case for empty tree and leaf nodes children.
        if( curr ==  NULL) return;
        // IN order print.
        // Print left. 
        display(curr->left);
   
     // Print myself.
        cout << curr->data << ", ";
        // Print right.
        display(curr->right);

 }
//............................................................................


    Node * searchHelper(int value)
	{
        return search(root, value);
    }


    Node * search(Node * curr, int value){
                 //base case
		        // Are you the value? or Are you NULL?  if yes return curr
				if(curr == NULL || curr->data == value ) return curr;


				// else you search in right or left. 
				// Left
			   else if(value < curr->data) return search(curr->left, value);
				// Right
				else  return search(curr->right, value);
    									}


//......................................................................
    void print2DUtil(Node *root, int space)  
    {  
				// Base case  
				if (root == NULL)return; 
				
				  
				// Increase distance between levels  
				space += 5;  
				
				// Process right child first  
				print2DUtil(root->right, space);  
		
				// Print current node after space  
				// count  
				cout<<endl;  
				for (int i = 0; i < space; i++) {  cout<<" ";}  
				     
				cout<<root->data<<endl;  
		
				// Process left child  
				print2DUtil(root->left, space);  
    }  
  
 
    void print2D()  
    {  
				cout << "******************************" << endl;
				// Pass initial space count as 0  
				print2DUtil(root, 0);  
				cout << "******************************" << endl;
				
    }
//..........................................................................
//replacing of n1 by n2
void replaceatparent(Node*n1,Node*n2){
//base case
if(n1==root)root=n2;
else{

		if(n1->parent->left==n1){
				n1->parent->left=n2;
				n2->parent=n1->parent;
				n1->parent=NULL;
				return;
					}
		else{
			n1->parent->right=n2;
				n2->parent=n1->parent;
				n1->parent=NULL;
				return;	
	        }
   }
   
   }   
//....................................................................

void findminhelper()
{   
    Node*p=findmin(root);
	cout<<"minimum is::"<<p->data<<endl;
   
}

Node*findmin(Node*current){
//base case
			if(current==NULL) return current;

			while(current->left!=NULL){
					current=current->left;
						             }
			return current;
                      }

//.......................................................
void findmaxhelper()
{   
    Node*p=findmax(root);
	cout<<"maximum is::"<<p->data<<endl;
   
}

Node*findmax(Node*current){
//base case
			if(current==NULL) return current;

			while(current->right!=NULL){
					current=current->right;
						             }
			return current;
                      }
//.......................................................

    void binary_delete(Node * current, int key){
//base case
if(current==NULL)return;


//find key where it is
 Node *curr = searchHelper(key);

if(curr==NULL){cout<<"key not present"<<endl; return;}



//(curr!=NULL)
else{	
	 
			//1st if curr is leaf have no childrens
			if(curr->left==NULL&&curr->right==NULL){
					if(curr==root){
						root=NULL;
					    return;
					}


					else{



					if(curr->parent->left==curr) curr->parent->left=NULL;
					else curr->parent->right=NULL;
					delete curr;
					return;
						}
			} 

		  //2nd if one of the child is not NULL
			else if(curr->left==NULL||curr->right==NULL){

				if(curr==root){
			
						if(curr->left!=NULL){
						root=curr->left;
						delete curr;
						}

						else {root=curr->right;
						delete curr;
							}
						return;

						}

			else{


                  //check curr is left of his parent then curr only child is left/ right and make curr parent ;;;right;;;to curr child
				if(curr->parent->right==curr){
				    if(curr->right!=NULL){
					
					curr->parent->right=curr->right;
                  //don't forgot the link of parent of node to its previous one
					curr->right->parent=curr->parent;
					delete curr;
					return;
					}
					
					else {curr->parent->right=curr->left;
						//parent connection
						curr->left->parent=curr->parent;
						delete curr;
						return;
						}
				}
		//curr is at his parent left make parent ::left to curr child
				else{ 
						if(curr->left!=NULL)	
						{curr->parent->left=curr->left;
                         //parent connection
						curr->left->parent=curr->parent;}
							
						else{ curr->parent->left=curr->right;
						         //parent connection

                        		curr->right->parent=curr->parent;}		
				}
				delete curr;
		        return;                   
			}
			}

		
		//3rd if curr has two childrens

		else{

			if(curr->left->right==NULL){
				curr->data=curr->left->data;
				Node* i=curr->left;
				
			 	curr->left=curr->left->left;
			 	delete i;
			 	return;
			}
				else{
				Node*p=findmax(curr->left);
				//replace data
				curr->data=p->data;
				//now delete that leaf node which data replaced
				p->parent->right=p->left;
				delete p;
				return;
			}
			

		  }
      }  



}
//............................................................


//......................................................................
};
//.......................................................................
int main(){
    
    BST bst1;
    bst1.insertHelper(4);
    bst1.insertHelper(2);
    bst1.insertHelper(3);
    bst1.insertHelper(1);
    bst1.insertHelper(6);
    bst1.insertHelper(5);
    bst1.insertHelper(7);
    bst1.insertHelper(8);

    cout<<"Sorted list :"<<endl;
 bst1.displayHelper();

    if(bst1.searchHelper(3) != NULL){
        cout << endl << bst1.searchHelper(3)->data << endl;
    }
//cout<<"No of nodes in the tree"<<endl;
	//bst1.counthelper();
    bst1.findminhelper();
   // bst1. heighthelper();



     bst1.print2D();
     
   //cout<<endl<<"number of element bt these: "<<bst1.rangeSearch(2,6)<<endl;
 	
    bst1.binary_delete(bst1.root,5);
    bst1.print2D();
    bst1.binary_delete(bst1.root,6);
    bst1.print2D();
    cout << "Deleting 2" << endl;
    bst1.binary_delete(bst1.root,2);
    bst1.print2D();
    bst1.binary_delete(bst1.root,4);
    bst1.print2D();
    bst1.binary_delete(bst1.root,7);
    bst1.print2D();
    bst1.binary_delete(bst1.root,8);
    bst1.print2D();
    bst1.binary_delete(bst1.root,3);
    bst1.print2D();
    bst1.binary_delete(bst1.root,1);
    bst1.print2D();
    bst1.binary_delete(bst1.root,1);
    bst1.print2D();

}
