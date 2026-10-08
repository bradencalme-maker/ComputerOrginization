#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include<vector>
#include "Pair.hpp"

class Dictionary {
    public:
    virtual bool insert(int k, double v) = 0;
    virtual double get(int k) = 0;
    virtual bool remove(int k) = 0;
    virtual std::vector<Pair<int,double>> get_range(int k1, int k2) = 0;
    virtual int size() = 0;
    virtual bool is_empty() = 0;
    virtual void clear() = 0;
    virtual std::vector<int> keys() = 0;
    virtual std::vector<double> values() = 0;
    virtual std::vector<Pair<int,double>> entries() = 0;
};

#endif
