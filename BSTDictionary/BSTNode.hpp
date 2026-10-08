#ifndef BSTNODE_HPP
#define BSTNODE_HPP

// Define a BSTNode Class here:
/* Include variables:
 * Key (int)
 * Value (double)
 * left
 * right
 * 
 * Include functions
 * constructors (3)
 * destructor
 * copy constructor
 * assignment overload
*/
class BSTNode {
    public:
    BSTNode* left;
    BSTNode* right;
    int key;
    double value;
    BSTNode();
    BSTNode(const BSTNode& other);
    BSTNode& operator=(const BSTNode& other);
    ~BSTNode();
    BSTNode(int k, double v);
    BSTNode(int k, double v, BSTNode* l, BSTNode* r);
};

#endif