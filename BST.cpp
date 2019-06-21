#include <iostream>
#include "BST.h"

BST::BST() {}
BST::~BST() {}

//pretty much destroys the tree by removing the first root
void BST::clear() {

   //since it is a shared pointer, by removing the first root causes a cascading effect that
   //effectively clears the entire tree
   std::shared_ptr<BST_Node> root;
}

//searches to see if an element is in the tree through recursion
bool BST::contains(const int data) const
{

    //calls the overloaded contains method
    return contains(root, data);
}

bool BST::contains(std::shared_ptr<BST_Node> node, const int data) const
{
   //set the initial found flag to true
   bool found = true;

   //if the node is null then the element is not present
   if (node == NULL)

      //the flag is set to false and the recursive structure unwinds
      found = false;
   else if (data<node->data)
      
      //otherwise if the data is less that the value of the data in the current node
      //it searches down the left branch
      found = contains(node->left, data);
   else if (data>node->data)
      //if it is greater than the value in the node then it searches the right branch
      found = contains(node->right, data);

   //if none of the above if statements are called then the element must be present and
   //a true value is returned
   return found;
}

//Adds a new node to the tree
void BST::add(const int data) {

    //checks to see if the root is null
    if (root==NULL) {
       //if it is, creates the root node
       std::shared_ptr<BST_Node> newNode (new BST_Node(data));
       root = newNode;
    } else {
       //otherwise recursively searches the tree for an empty node
       add(root,data);
    } 
}

void BST::add(std::shared_ptr<BST_Node> node, const int data) {

     //checks to see if the value is less than the current value
     //and if the left root is empty. If it is, it adds a new node    
     if(data<node->data && node->left == NULL) {
         std::shared_ptr<BST_Node> newNode (new BST_Node(data));
         node->left = newNode;

     //otherwise checks to see if the value is greater than the current value
     //and if the right root is empty. If it is, it adds a new node  
     } else if(data>node->data && node->right == NULL) {
         std::shared_ptr<BST_Node> newNode (new BST_Node(data));
         node->right = newNode;

     //otherwise if it is less than the current value recursively searches the left branch
     } else if (data<node->data) {
         add(node->left, data);

     //otherwise if it is greater than the current value recursively searches the right branch
     } else if (data>node->data) {
         add(node->right, data);

     //if all else fails, the value is already in the tree and an error is reported
     } else {
         std::cerr<<"The element "<<data<<" is already present "<<std::endl;
     }
}
