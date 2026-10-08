#ifndef BST_HPP
#define BST_HPP
#include <vector>
#include<iostream>
#include "BSTNode.hpp"
#include "Pair.hpp"

// Define a BST Class here:
/* Include variables:
 * root (private)
 * 
 * public functions:
 * insert
 * search
 * inorder_traversal  (print the list keys and values in these orders)
 * postorder_traversal
 * preorder_traversal
 * remove
 * size (reports the number of nodes)
 * height (reports the height)
 * constructor
 * destructor
 * copy constructor
 * assignment overload
 * 
 * private recursive functions as necessary 
 */
class BST {
    private:
    BSTNode* root;
    bool insert(int k, double v, BSTNode* c);
    double search(int k, double dflt, BSTNode* c);
    void inorder_traversal(BSTNode* c);
    void postorder_traversal(BSTNode* c);
    void preorder_traversal(BSTNode* c);
    bool remove(int k, BSTNode* c, BSTNode* r);
    void destructor_help(BSTNode* c);
    int size(BSTNode* c);
    int height(BSTNode* c);
    BSTNode* left_most(BSTNode* c);
    void keys(BSTNode* c, std::vector<int>& v);
    void values(BSTNode* c, std::vector<double>& v);
    void entries(BSTNode* c, std::vector<Pair<int, double>>& v);

    public:
    BST();
    ~BST();
    BST(const BST& other);
    BST& operator=(const BST& other);

    /*
    add keys values entries is empty and clear
    */
    bool is_empty();
    void clear();
    std::vector<int> keys();
    std::vector<double> values();
    std::vector<Pair<int, double>> entries();


    bool insert(int k, double v);
    double search(int k, double dflt); //maybe add a default value if we dont learn how to throw errors
    void inorder_traversal();
    void postorder_traversal();
    void preorder_traversal();
    bool remove(int k);
    int size();
    int height();
};
#endif