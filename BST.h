#include "BST_Node.h"
#include <memory>

class BST {
public:
   BST();
   ~BST();

   void clear();
   bool contains(const int data) const;
   void add(const int data);

private:
   std::shared_ptr<BST_Node> root;
   void add(std::shared_ptr<BST_Node> node, const int data);
   bool contains(std::shared_ptr<BST_Node> node, const int data) const;
};
