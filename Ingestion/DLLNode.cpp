#include "DLLNode.hpp"

//default constructor
DLLNode::DLLNode(){
 next = prev = nullptr;
 value = 0.0;
 key = 0;
}

DLLNode::DLLNode(int k, double v) : DLLNode() {     //: DLLNode calls firt constructor first than runs this one
 value = v;
 key = k;
}

DLLNode::DLLNode(DLLNode* n, DLLNode* p, int k, double v) : DLLNode(k,v) {
 next = n;
 prev = p;
}

DLLNode::~DLLNode(){
 if (next != nullptr){
  delete next;    //recursive once here it will rerunn this from the start on the next node
  next = nullptr;
 }
}
