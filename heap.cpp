		#include<iostream>
		using namespace std;



		class BinaryHeap
		{
		    public:
		    int* arr;//pointer to the beginning of the array which implements the binary heap
		    int maxSize;//stores the maximum size of the array
		    int currSize;//stores the current size of the array


		    BinaryHeap(int maxSize)
		    {
			arr=new int[maxSize];//array with the passed size is declared
			this->maxSize=maxSize;//date memeber maxSize is initialized
			currSize=0;//current size is inilialized to zero
		    }


		//.................................................................................................................................
		    void swap(int a,int b)//function to swap the elements at two array indice
		    {
			arr[a]=arr[a]+arr[b];
			arr[b]=arr[a]-arr[b];
			arr[a]=arr[a]-arr[b];
		    }
		//.................................................................................................................................
		    int getParent(int i){return (i-1)/2;  }    // return the index of parent of the node at the index i
			
		   
		//.................................................................................................................................
		    int getLeft(int i){return (i*2)+1;}       // return the index of left child of the node at the index i
		
		//.................................................................................................................................
		    int getRight(int i){return (i*2)+2;}      // return the index of right child of the node at the index i
		    
			
		    
		//.................................................................................................................................
		    int getMin(){return arr[0];}         // return the minimum element in the heap
		 

		//.................................................................................................................................


		    void insert(int num)
		    {
			if(currSize==maxSize)//if array index is not out of bounds
			cout<<"Heap Overflow"<<endl;//else heap overflows
			else
			{
			    arr[currSize++]=num;//the value is added into the next element at the end
			    int i=currSize-1;
			    while(i>0&&arr[i]<arr[getParent(i)])//loop to check the hierarchy of the heap elements
			    {
				swap(i,getParent(i));//if the hierarchy is broken then the elemnts are swapped
				i=getParent(i);//the heirarchy is checker for the parent of the current node till the root is reached
			    }
			}
		    }


		//.................................................................................................................................
			  
		    void display(int i,int space)
		    {
			if(i<currSize)//if the end of the subtree has not been reached
			{
			    display(getRight(i),++space);//the right subtree is displayed with an increased tab space
			    cout<<endl;//a new line to print the current node value

			    for(int i=1;i<space;i++)//for loop to print the correct number of
			    cout<<"\t";//tab spaces

			    cout<<arr[i]<<endl;//the value at the root of the current subtree is displayed
		
			    display(getLeft(i),space);
		
			}
		    }


		//.................................................................................................................................

		    int extractMin()//function to return the minimum of the elements in the heap
		    {
			if(currSize==0)//if the heap is empty
			return -9999;//then heap underflow occurs
			else if(currSize==1)//else if the heap has a single value
			return arr[currSize--];//it is returned and current size becomes zero
			else
			{
			    int min=getMin();//the minimum of the heap is stored
			    arr[0]=arr[--currSize];//the last element of the heap is copied to the root
			    minHeapify(0);//minHeapify moves the root value to its correct position in the heap
			    return min;//the deleted element is returned
			}        
		    }



		//.................................................................................................................................
		    void decreaseKey(int i)//function to reduce the value of the node to be deleted to the minimum in the tree
		    {
			arr[i]=getMin()-1;//value of the node to be deletd is decreased
			while(i>0&&arr[i]<arr[getParent(i)])//it is compared with its parent
			{
			    swap(i,getParent(i));//and swapped it it is lesser then the value at the parent node
			    i=getParent(i);//the rule is checked for its parent till there are no violations or the root is reached
			}
		    }//end of the function to reduce the value of the node to be deleted to the minimum in the tree





		    void deleteAt(int i)//function to delete the element at index i
		    {
			decreaseKey(i);//the value at index i is made the minimum in the heap and floats to the root using decreaseKey()
			i=extractMin();//extractMin() extracts the minimum from the tree
		    }

		//...............................................................................................................................

		    void minHeapify(int i)//function to check the realtion of the parent with the child
		    {
			int least=i;//stores the index of the child with the minimum value
			if(getLeft(i)<currSize&&arr[getLeft(i)]<arr[least])//the relation of the left child with the parent is checked
			least=getLeft(i);
			if(getRight(i)<currSize&&arr[getRight(i)]<arr[least])//the relation of the right child with the parent is checked
			least=getRight(i);    
			if(least!=i)//if the rule is not satisfied
			{
			    swap(i,least);//they are swapped
			    minHeapify(least);//the rule is checked for the child of the current node
			}
		    }
		//.................................................................................................................................
		};
		//.................................................................................................................................
		int main(){
		    BinaryHeap bh1(20);
		    for(int i=10;i>0;i--)
		    bh1.insert(i);
		    bh1.display(0,0);
			cout<<"*****************************************************************"<<endl;
		    int i=bh1.extractMin();
		    cout<<i<<endl;
		    bh1.display(0,0);
			cout<<"*****************************************************************"<<endl;
		    bh1.deleteAt(3);
		    bh1.display(0,0);
			cout<<"*****************************************************************"<<endl;
		    cout<<endl;
		}
