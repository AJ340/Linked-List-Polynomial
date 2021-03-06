//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
//  Modified by Ioannis Stamos. 
//
//    MODIFIED TO REPRESENT A NODE IN LINKEDPOLYNOMIAL BY ANDRES QUINONES.
//    INSTEAD OF NODE CONTAINING AN ITEM, IT CONTAINS 2, A COEFFICIENT AND EXPONENT

/** @file Node.h 
    Listing 4-1 */
#ifndef TEACH_CSCI235_LINKEDBAG_NODE_H_
#define TEACH_CSCI235_LINKEDBAG_NODE_H_

// Basic Node class to be used in linked-based implementations.
// Sample usage (creates a list of two nodes and displays it):
// Node<int> *a_node = new Node<int>;
// a_node->SetItem(10);
// Node<int> *b_node = new Node<int>(20);
// a_node->SetNext(b_node);
// Node<int> *current_node = a_node;
// while (current_node != nullptr) {
//    cout << current_node->GetItem() << " " << endl;
//    current_node = current_node->GetNext();
// }

template<class ItemType>
class Node {   
public:
   Node();

   // @param a_coefficient a given coefficient for a polynomial term 
   // @param an_exponent a given exponent for a polynomial term.
   // Constucts a node holding a_coefficient, an_exponent and pointing to nullptr.
   Node(const ItemType& a_coefficient, const ItemType& an_exponent);

   // @param a_coefficient a given coefficient for a polynomial term 
   // @param an_exponent a given exponent for a polynomial term.
   // @param next_node pointer to next_nodex
   // Constucts a node holding an_item and pointing to next_node.
   Node(const ItemType& a_coefficient, const ItemType& an_exponent, Node<ItemType>* next_node);

   // @param a_coefficient
   // Sets the coefficient_ to a_coefficient.
   void SetCoefficient(const ItemType& a_coefficient);

   // @param an_exponent
   // Sets the exponent_ to an_exponent.
   void SetExponent(const ItemType& an_exponent);

   // @param next_node pointer to next node.
   // Sets next point to next_node.
   void SetNext(Node<ItemType>* next_node);

   // @return current coefficient.
   ItemType GetCoefficient() const;

   // @return current exponent.
   ItemType GetExponent() const;

   // @return pointer to next node.
   Node<ItemType>* GetNext() const;

private:
   ItemType        coefficient_; // First data item. Coefficient of polynomial
   ItemType        exponent_; // Second data item. Exponent of polynomial
   Node<ItemType>* next_node_; // Pointer to next node
}; // end Node

#include "Node.cpp"
#endif  // TEACH_CSCI235_LINKEDBAG_NODE_H_
