#include "BSTNode.hpp"

/* 
 * Implement BSTNode functions here
*/
BSTNode::BSTNode() {
    left = right = nullptr;
    key = 0;
    value = 0.0;
}

BSTNode::BSTNode(const BSTNode& other){
    key = other.key;
    value = other.value;
    if (other.left == nullptr && other.right == nullptr){
        left = right = nullptr;
    }
    else if (other.left == nullptr) {
        left = nullptr;
        right = new BSTNode(*other.right);
    } else if (other.right == nullptr) {
        left = new BSTNode(*other.left);
        right = nullptr;
    } else {
        left = new BSTNode(*other.left);
        right = new BSTNode(*other.right);
    }
}

BSTNode& BSTNode::operator=(const BSTNode& other){
    if(left != nullptr) {
        delete left;
        left = nullptr;
    }
    if (right != nullptr) {
        delete right;
        right = nullptr;
    }
    if (other.left == nullptr && other.right == nullptr){
        left = right = nullptr;
    }
    else if (other.left == nullptr) {
        left = nullptr;
        right = new BSTNode(*other.right);
    } else if (other.right == nullptr) {
        left = new BSTNode(*other.left);
        right = nullptr;
    } else {
        left = new BSTNode(*other.left);
        right = new BSTNode(*other.right);
    }
    return *this;
}


BSTNode::BSTNode(int k, double v) : BSTNode(){
    key = k;
    value = v;
}

BSTNode::BSTNode(int k, double v, BSTNode* l, BSTNode* r) : BSTNode(k,v){
    left = l;
    right = r;
}

BSTNode::~BSTNode(){
    if (left != nullptr){
        delete left;
        left = nullptr;
    }
    if (right != nullptr){
        delete right;
        right = nullptr;
    }
}