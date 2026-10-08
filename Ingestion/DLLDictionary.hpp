#ifndef DLLDICTIONARY_HPP
#define DLLDICTIONARY_HPP

#include<vector>
#include "Pair.hpp"
#include "Dictionary.hpp"
#include "DoublyLinkedList.hpp"

class DLLDictionary : Dictionary {
    private:
    DoublyLinkedList lst;

    public:
    DLLDictionary();
    bool insert(int k, double v);
    double get(int k);
    bool remove(int k);
    std::vector<Pair<int,double>> get_range(int k1, int k2);
    int size();
    bool is_empty();
    void clear();
    std::vector<int> keys();
    std::vector<double> values();
    std::vector<Pair<int,double>> entries();

};


#endif
