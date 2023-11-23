#include "SLLSet.h"
#include <iostream>

SLLSet::SLLSet()
{
	size = 0;
	head = NULL;
}
SLLSet::SLLSet(int sortedArray[], int arrSize)
{
	size = arrSize;// even though array size is already given, make my own variable size just for good coding practice
	head = NULL;//initialize head
	SLLNode*current = head;//initialize the current node to head
	int count;//declare variable count here for good coding hygiene
	
	for (count = 0; count < size; count++){//iterate through every element in the array
		if (head == NULL)// if head is NULL it means we are at head node.
		{
			head = new SLLNode(sortedArray[count],NULL);
			current = head;//thus, create a new node to head node.
		}
		else//when current not head node,
		{
			 current->next= new SLLNode(sortedArray[count],NULL);//create the next node with the value from the array
			 current = current->next;//to the next node
		}
	}


}
int SLLSet::getSize()
{
	return size;
	
	//fixME
//	return 0;
}
SLLSet SLLSet::copy()
{
	
	//fixME
	 //return *(new SLLSet())
	SLLSet copyV;//copyV(the value of the copy) is in class SLLSet
	copyV.size = size;//set up the size of the copy

	SLLNode*current = head;//Initialize the current node, to head node
	SLLNode*copy = copyV.head;//Initialize the current copy of the node, to head node in the copy.

	do{//loop starts

		if (copy == NULL){//when copy is NULL, it means the program is at the start of the copying process,
			copyV.head = new SLLNode(current->value, NULL);//create new node in the copy with the current node value and NULL
			copy = copyV.head;//storage the head node of the copy to copy
		}

		else if(copy != NULL){//if node in the copy is not NULL, it means we are not at the end,
			copy->next = new SLLNode(current->value, NULL);//create a new "next node" in copy that storages the value of the current iteration and NULL
			copy = copy -> next;//get ready for the next node to copy
		}
		current = current -> next;//after each iteration, move the current value to next
	}while(current != NULL);//loop runs as long as current is not at the end of the nodes
	return copyV;//return the copy(with its values of course
}
bool SLLSet::isIn(int v)
{
    //fixME
	SLLNode* current = head; //initialize current(in class SLLNode) to head.

while (current != NULL){
		if (current->value == v){//if integer v is an element of the current SLLset, return true
			return true;
		}
		current = current->next; //move to the next node
	}//loop runs while SLLNode is not at the end of the nodes yet
	return false;//return false if not true
}
void SLLSet::add(int v)
{
    SLLNode* current = head;
    SLLNode* pre = NULL;
    
    //case one of v not in SLLset
    if (head == NULL){//if head is NULL this is the head node
    	head = new SLLNode(v,NULL);//add V to head node
    	size = 1;//set size to one since this is head node
    }
    //case 2 of v is smaller than values in head
    else if(v < head ->value){
    	head = new SLLNode(v,head);//create new node equal to v
    	size ++;//size plus one, compare to before
    }
    //case 3 of v is bigger than all values in head
    else if(v > head -> value){
    	do{
    		pre = current;
    		current = current -> next;
    	}while(current != NULL && current -> value < v);//while current value is not NULL and it is smaller than v
    	//case 4, when current value is NULL, or there are no current value that is v
    	if (current == NULL || current -> value != v){
    		pre -> next = new SLLNode(v, current);// make a new node with value v in between the two nodes
    		size++;//size plus one after this
    	}

    }
}
void SLLSet::remove(int v)
{
   SLLNode* current = head;//set the pointer current point to head, initialization work
   SLLNode* pre = NULL;//initialize previous pointer to NULL, as it does not have a value at the beginning of the program
   //case 1
   if (head ->value == v){//if the head points to value v(the first node is v), then we move the head to next one,
	   head = head->next;
	   size --;//size will shrink by 1 now head is not here
   }
   //case 2: run every node to find v then remove v
   else{
	   while ((current != NULL)&&(current -> value != v)){//run loop when the current pointer is not the last, AND the current pointer not yet pointing to V

		   pre = current;//set the previous node to current node as we move up
		   current = current->next;//move the current pointer to next
		   //size--;
	   }
	   //we found v, remove it
	   if(current != NULL && current ->value == v){//if the current pointer is not at the end of the list yet and the current value is v
		   pre -> next = current -> next; //move the pointer up by one. Skip node v to achieve the purpose of removing this node
		   size --;//shrink the size down by one after removal
		   }
   }
}
SLLSet SLLSet::setUnion(SLLSet s)
{
	 SLLNode* current1 = this->head;//initialize pointer current for set 1 to head
	 SLLNode* current2 = s.head;//initialize pointer current for set 2 to head
//case 1
	 if (current1 != NULL && current2 !=NULL)//if both of he lists are not empty, then
	 {
		 while(current1 != NULL){//repeat until no more empty spot in lists
			 s.add(current1-> value);//add them data in the nodes up
			 current1 = current1->next;//move to the next node
		 }
		 return s;//return the union of 2 lists
	 }
//case 2
	 else if(current1 == NULL)//if set 1 is empty
	 {
		 SLLSet new_list = s.copy();//just copy set one into the new set
		 return new_list;//return the new set
	 }

	 else
	 {
		 SLLSet new_list = this -> copy();//if set 2 is empty,add set 1 to the new set, return set 1
		 return new_list;//return the new set
	 }


//	 return *(new SLLSet())
}
SLLSet SLLSet::intersection(SLLSet s)
{
    	//fixME
	// return *(new SLLSet())
	SLLSet ans; //Initialize the answer set
	SLLNode* currentans=ans.head;//initialize the answer pointer

	SLLNode* current1=head; //initialize the current pointer for this to head
	SLLNode* current2=s.head;//Repeat the first line for s

	//case 1, if both s and this are empty

	if(current2==NULL || current1==NULL){

		ans.head=NULL;//then everything in answer is just NULL and the size is 0
		ans.size=0;

	 }

	else{//otherwise

	while(current1!=NULL && current2!=NULL)//loop through lists s and this
	{
//case2, both value in s and this are the same, and answer is NULL.
	if(current1->value==current2->value){
		 if(currentans==NULL)
		 {
	    	ans.head=new SLLNode(current1->value,NULL);//we put value in the node in this, and NULL, into the head positioned node in answer
	    	currentans=ans.head;//reset the pointer for answer to the beginning
		 }
		 //case 3, both value in s and this are the same, and answer not NULL.
		 else
		 {
	    	currentans->next=new SLLNode(current1->value,NULL);//we put the value in the node in this, and null, into the same positioned node in answer set
	    	currentans=currentans->next;//move the current pointer for answer up by 1 place
		 }
	    current1=current1->next;//move the current pointers for this, s, and next up by one
	    current2=current2->next;
	    ans.size+=1;//size for the answer set plus 1
}
//case4, the value in this is smaller than the value in s. (node)
	else if(current1->value < current2->value)
	{
		   current1=current1->next;// current pointer to this move up by one
	   }
//case5 he value in s is smaller than the value in this. (node)
	   else
	   {
		   current2=current2->next;// current pointer to s move up by one
	   }
	  }

	}
	 return ans;// resturn answer set after the loop
}
SLLSet SLLSet::difference(SLLSet s)
{
//    	//fixME
//	 //return *(new SLLSet())
	SLLSet ans;

	if(this->size==0)//check if set 1 is empty
	{
		return SLLSet();//return NULL
	}

	ans = this->copy();//only if it is not, we copy set one. Cuz u cant copy an empty string
	SLLNode* current2 = s.head;//initialize set 2 pointer


	for(int i = 0; i < s.size; i++){//check through every node
		if(ans.isIn(current2->value)==true){//if this is in s
					ans.remove(current2->value);//remove it from s
				}
				current2 = current2 ->next;//next one



	}
	return ans;//return answer

}
SLLSet SLLSet::setUnion(SLLSet sArray[],int size)
{
    	//fixME
	// return *(new SLLSet())
	SLLSet ans;//initialize the answer set
	int count;//counter for for loop
	for(count = 0; count < size; count++){//iterate through the whole union set
		ans = ans.setUnion(sArray[count]);//add every element in the array to the answer set
	}
	return ans;//return answer
}
string SLLSet::toString()
{
   //fixME
   //return "";
	string result;//declare result as a string
	SLLNode * current = head;//start the list pointer at head

	if (head == NULL){
		return "";//if the first list pointer is NULL return empty string
	}

	while (current != NULL){//while the current list pointer is not at the end of the list, iterate.

		if (current->next != NULL){//if the next list pointer is not NULL

			result += to_string(current->value);//store the current value in result as string
			result += ", ";
			current = current->next;
		}
		else{
			result += to_string(current->value);//return current value in string
			current = current->next;//go to the next node
			}
		}

	return result;
}
