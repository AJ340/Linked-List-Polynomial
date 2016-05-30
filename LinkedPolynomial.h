//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
//  Modified by Ioannis Stamos.

/** ADT polynomial: Link-based implementation of bag modified to polynomial BY ANDRES QUINONES
    @file Linkedpolynomial.h 
    Listing 4-3 */
#ifndef TEACH_CSCI235_LinkedPolynomial_H_
#define TEACH_CSCI235_LinkedPolynomial_H_

#include "Node.h"

template<class ItemType>
class LinkedPolynomial
{
public:
   LinkedPolynomial();
   /*Copy constructor. Uses CopyNodesFrom to make a deep copy of passed polynomial
      @param a_polynomial a polynomial to copy */
   LinkedPolynomial(const LinkedPolynomial<ItemType>& a_polynomial);

   /* Overloading of the assignment operator.
      @param right_hand_side right hand side of assignment statement*/
   LinkedPolynomial<ItemType>& operator=(const LinkedPolynomial<ItemType>& right_hand_side);

   // Destructor should be virtual. Calls CLear().
   virtual ~LinkedPolynomial();        

   /* Gets number of nodes in polynomial
      @return term_count_ count of all nodes belonging to object*/               
   int GetCurrentSize() const;   

   //check if LinkedPolynomial is empty
   // @return 0 if term_count_ is 0
   // @return 1 if item_count is not 0
   bool IsEmpty() const;  

   /* adds node to end of list as long as node with passed exponent doesnt exist
      @param a_coefficient a coeeficient for new node
      @param an_exponent an exponent for new node
      @return 0 add failed due to existance of a node with an_exponent
      @return 1 add to the end was successful*/       
   bool Add(const ItemType& a_coefficient, const ItemType& an_exponent);

   /* deletes and deallocates heap space for polynomial*/   
   void Clear();   

   /* Uses DisplayPolyRecur to cout polynomial*/
   void DisplayPolynomial(); 

   /* Gets degree (highest exponent) of polynomial
      @return the highest exponent, 
      @return 0 if polynomial is empty return*/
   ItemType Degree() const;

   /* Finds the coefficient of node with passed exponent
      @param exponent an exponent of a node to search for
      @return coefficient of exponent*/
   ItemType Coefficient(const ItemType& exponent);

   /* Changes the coefficient of node with passed exponent
      @param new_coefficient a new coefficient
      @param exponent exponent of node to change*/
   bool ChangeCoefficient(ItemType new_coefficient, ItemType exponent);

   /* Adds two polynomials, sum is stored in object function is called on
      @param b_polynomial a polynomial to add */
   void AddPolynomial(const LinkedPolynomial<ItemType> &b_polynomial);

private:
   // Pointer to first node
   Node<ItemType>* head_ptr_; 

   // Current count of polynomial terms
   int term_count_;           
   
   // @param a_polynomial a given polynomial.
   // Allocates space and copies all the nodes from a_polynomial.
   // The function does not check whether this polynomial contains
   // any items, but it assumes that it is empty.
   void CopyNodesFrom(const LinkedPolynomial<ItemType> &a_polynomial);

   //@param n a pointer to a Node
   // Couts the data in polynomial in format (Coefficient*x^exponent + next node)
   void DisplayPolyRecur(Node<ItemType>* n);

   //Recursive helper function, finds the node that contains exponent
   //@param exponent exponent to look for
   //@param targ place in list to start searching from
   //@return nullptr if exponent wasnt found
   //@return !nullptr address of node with exponent
   Node<ItemType>* FindNodeWithExponent(const ItemType& exponent, Node<ItemType>* targ);
}; // end LinkedPolynomial

#include "LinkedPolynomial.cpp"
#endif  //TEACH_CSCI235_LinkedPolynomial_H_
