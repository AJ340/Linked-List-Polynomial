//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
// Modified by Ioannis Stamos. 

// MODIFIED TO POLYNOMIAL BY ANDRES QUINONES

/** ADT Polynomial: Link-based implementation.
    @file LinkedPolynomial.cpp */

#include "LinkedPolynomial.h"
#include "Node.h"
#include <cstddef>
#include <iostream> 
using namespace std;

template<class ItemType>
void LinkedPolynomial<ItemType>::CopyNodesFrom(const LinkedPolynomial<ItemType> &a_Polynomial) {
  term_count_ = a_Polynomial.term_count_;  
  Node<ItemType>* a_Polynomial_current_pointer = a_Polynomial.head_ptr_;  // Pointer to beginning of a_Polynomial.
   
  if (a_Polynomial_current_pointer == nullptr) {  // a_Polynomial is empty.
    head_ptr_ = nullptr;  
    return;
  } 
  // Copy first node
  head_ptr_ = new Node<ItemType>();
  head_ptr_->SetCoefficient(a_Polynomial_current_pointer->GetCoefficient());
  head_ptr_->SetExponent(a_Polynomial_current_pointer->GetExponent());

  
  // Copy remaining nodes
  Node<ItemType>* last_pointer = head_ptr_;      // Points to last node in new chain
  a_Polynomial_current_pointer = a_Polynomial_current_pointer->GetNext();     // Advance original-chain pointer
  
  while (a_Polynomial_current_pointer != nullptr) {
    // Create a new node holding the term of a_Polynomial_current_pointer.
    Node<ItemType>* new_node_pointer = new Node<ItemType>(a_Polynomial_current_pointer->GetCoefficient(),a_Polynomial_current_pointer->GetExponent());
    
    // Link new node to end of new chain
    last_pointer->SetNext(new_node_pointer);
    
    // Advance pointer to new last node
    last_pointer = last_pointer->GetNext();
    
    // Advance original-chain pointer
    a_Polynomial_current_pointer = a_Polynomial_current_pointer->GetNext();
  }  // end while
  last_pointer->SetNext(nullptr); 
}

template<class ItemType>
LinkedPolynomial<ItemType>::LinkedPolynomial() : head_ptr_(nullptr), term_count_(0)
{
}  

template<class ItemType>
LinkedPolynomial<ItemType>::LinkedPolynomial(const LinkedPolynomial<ItemType>& a_Polynomial)
{
  CopyNodesFrom(a_Polynomial);
}  

template<class ItemType>
LinkedPolynomial<ItemType>& LinkedPolynomial<ItemType>::operator=(const LinkedPolynomial<ItemType>& right_hand_side) {
  if (this != &right_hand_side) {  
    Clear(); // First deallocate all memory.
    CopyNodesFrom(right_hand_side);  // Then copy everything.
  }
  return *this;  // Return self.
}

template<class ItemType>
LinkedPolynomial<ItemType>::~LinkedPolynomial()
{
  Clear();
}  

template<class ItemType>
bool LinkedPolynomial<ItemType>::IsEmpty() const
{
  return term_count_ == 0;
}  

template<class ItemType>
int LinkedPolynomial<ItemType>::GetCurrentSize() const
{
  return term_count_;
}  

template<class ItemType>
bool LinkedPolynomial<ItemType>::Add(const ItemType& a_coefficient, const ItemType& an_exponent)
{
	Node<ItemType>* temp_ptr=head_ptr_;
	if(IsEmpty())
	{
		//if polynomial is empty first node is created

		//create new node with parameters and GetNext pointing to nullptr
		Node<ItemType>* new_node_ptr = new Node<ItemType>(a_coefficient, an_exponent); 
		//make the head_ptr_ of polynomial point to newly created node
		head_ptr_=new_node_ptr;
		//increase term count to reflect change
		term_count_++;
	}
	else
	{
		// otherwise we must check if a node with an_exponent exists already

		//traverse to the end of the list
		while(temp_ptr !=nullptr)	
		{
		//while traversing. Check if exponent exists already. If so, add fails so return false.
			if(temp_ptr->GetExponent()==an_exponent)
				return false;

			if(temp_ptr->GetNext() == nullptr)
			{
				//if program gets to this point then a node with passed an_exponent doesnt exist. so we can add at the end
			Node<ItemType>* new_node_ptr = new Node<ItemType>(a_coefficient, an_exponent); 
				//Make last node in linked list point to the newly created node.
			temp_ptr->SetNext(new_node_ptr);
				//increase term count to reflect change
			term_count_++;
			}
		temp_ptr = temp_ptr->GetNext(); // move on to next node
		}
		return true;
	}
	// When temp points to last node. Create new one on heap with params and pointing to nullptr
	
  return true; //Return true when add was successful
}  

template<class ItemType>
void LinkedPolynomial<ItemType>::Clear()
{
  Node<ItemType>* current_node_to_delete = head_ptr_;
  while (head_ptr_ != nullptr) {
    head_ptr_ = head_ptr_->GetNext();
    // Return node to the system
    current_node_to_delete->SetNext(nullptr);
    delete current_node_to_delete;
    current_node_to_delete = head_ptr_;  // Move to the next one.
  }  // end while
  term_count_ = 0;
}  


template<class ItemType>
void LinkedPolynomial<ItemType>::DisplayPolyRecur(Node<ItemType>* n) 
{
	if(n == nullptr) //Base Case1 :Makes sure n is pointing to a node and not nullptr
		return;
	cout << n->GetCoefficient() << "*x^" << n->GetExponent(); //cout node in desired format. ex. 3*x^7
		//set temp_ptr to point to next node
	if (n->GetNext() != nullptr)
		//if temp is = to nullptr then end of Polynomial
		cout << " + ";
	DisplayPolyRecur(n->GetNext()); 		//recursive call to cout rest of Polynomial
}

template<class ItemType>
void LinkedPolynomial<ItemType>::DisplayPolynomial() 
{
	//Uses recursion in DisplayPolyRecur() to cout entire polynomial
	DisplayPolyRecur(head_ptr_);
	cout << endl;
}

template<class ItemType>
ItemType LinkedPolynomial<ItemType>::Degree() const
{
	ItemType highest_exp;
	Node<ItemType>* temp_ptr = head_ptr_;
	//If Polynomial is empty, return 0
	if(IsEmpty())
	{
		cout << "Error: Polynomial is empty" << endl;
		return 0;
	}
	//Set highest_exp to first node's exponent
	highest_exp=head_ptr_->GetExponent();
	while(temp_ptr != nullptr)	//Loop used to traverse the list
	{
		//Compare next node's exponent to current highest_exp
		if((temp_ptr->GetExponent())>highest_exp)
			//Store the higher of the two in variable	
			highest_exp=temp_ptr->GetExponent();	
		//Make temp_ptr point to next node
		temp_ptr= temp_ptr->GetNext();	
	}
	return highest_exp;	//Return highest exponent in polynomial
}	//End of Degree()

template<class ItemType>
Node<ItemType>* LinkedPolynomial<ItemType>:: FindNodeWithExponent(const ItemType& exponent,Node<ItemType>* targ)
{
	Node<ItemType>* found_at=nullptr;

	//Base case: end of linkedpolynomial
	if(targ==nullptr)
		return nullptr;
	//check if exponent is found
	if(targ->GetExponent()==exponent)
		return targ;
	//call same function for nextnode and exponent. Found at will store nullptr if isnt found
	// or an address of a node with exponent
	found_at=FindNodeWithExponent(exponent,targ->GetNext());
	return found_at; // Return found_at
}

template<class ItemType>
ItemType LinkedPolynomial<ItemType>::Coefficient(const ItemType& exponent)
{
	//Uses FindNodeWithExponent to get node with exponent
	Node<ItemType>* target = FindNodeWithExponent(exponent,head_ptr_);
	//If exponent wasnt found return coefficient 0
	if(target == nullptr)
		return 0;
	else 
		// if it is found return coefficient of that node
		return target->GetCoefficient();
}

template<class ItemType>
bool LinkedPolynomial<ItemType>::ChangeCoefficient(ItemType new_coefficient, ItemType exponent)
{
	//Uses FindNodeWithExponent to get node with exponent
	Node<ItemType>* target = FindNodeWithExponent(exponent,head_ptr_);
	//If exponent wasnt found return 0 to signal failure
	if(target == nullptr)
		return false;
	else 
	{
		//change the coefficient currently there to new_coeffiecient
		target->SetCoefficient(new_coefficient);
		return true; // Return true to signal success
	}
}

template<class ItemType>
void LinkedPolynomial<ItemType>::AddPolynomial(const LinkedPolynomial<ItemType> & b_Polynomial)
{
	Node<ItemType>* polyB_track = b_Polynomial.head_ptr_;
	// lets call the polynomail this fuction is called on A

	// loop functions until end of list is reached
	while(polyB_track != nullptr)
	{
		//Check if exponent of element in b_polynomial exists in A
		Node<ItemType>* where_p = FindNodeWithExponent(polyB_track->GetExponent(),head_ptr_);
		//If search in A, for an exponent of a node in b returns nullptr,
		// then they do not share a term with a similar exponent
		if(where_p==nullptr)
			//Add that element in b to the end of A
			Add(polyB_track->GetCoefficient(),polyB_track->GetExponent());
		else
			//Otherwise they both have terms with that exponent, so set the coefficient of 
			// like term in A to (the coefficient of that term + coefficient of like term in b_polynomial)
			where_p->SetCoefficient(where_p->GetCoefficient()+polyB_track->GetCoefficient());
		//set track to point to next node in b_polynomial
		polyB_track =polyB_track->GetNext();
	}
}








