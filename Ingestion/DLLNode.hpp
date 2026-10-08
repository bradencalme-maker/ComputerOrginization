#ifndef DLLNODE_H
#define DLLNODE_H

class DLLNode {
    public:
        DLLNode* next;
        DLLNode* prev;
        int key;
        double value;
        DLLNode();
        DLLNode(int k, double v);
        DLLNode(DLLNode* n, DLLNode* p, int k, double v);
        ~DLLNode();
        
};

#endif
