#ifndef HASHTABLEDICTIONARY_HPP
#define HASHTABLEDICTIONARY_HPP

#include <iostream>
#include <unordered_map>
#include<vector>
#include "Pair.hpp"

class HashTableDictionary : Dictionary{

    private:
    std::unordered_map<int, double> lst;

    public:
    HashTableDictionary();
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