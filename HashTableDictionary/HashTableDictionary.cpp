#include <iostream>
#include "Dictionary.hpp"
#include <unordered_map>
#include "HashTableDictionary.hpp"
#include<vector>
#include "Pair.hpp"

HashTableDictionary::HashTableDictionary()
{
 lst = std::unordered_map<int, double>();
}

bool HashTableDictionary::insert(int k, double v) {
    return lst.try_emplace(k,v).second;
}

double HashTableDictionary::get(int k)
{
 return lst.at(k);
}

bool HashTableDictionary::remove(int k){
    return lst.erase(k);
}

std::vector<Pair<int,double>> HashTableDictionary::get_range(int k1, int k2){
    std::vector<Pair<int, double>> correct;
    Pair<int, double> s(0,0.0);
    for (int i = k1; i <= k2; i++){
        auto p = lst.find(i);
        if (p != lst.end()){
            s.first = p->first;
            s.second = p->second;
            correct.push_back(s);
        }
    }
    return correct;
}

int HashTableDictionary::size(){
return lst.size();
}

bool HashTableDictionary::is_empty(){
return lst.empty();
}

void HashTableDictionary::clear(){
    lst.clear();
}

std::vector<int> HashTableDictionary::keys(){
    std::vector<int> correct;
    for (auto iter = lst.begin(); iter != lst.end(); iter++){
            correct.push_back(iter->first);
    }
    return correct;
}

std::vector<double> HashTableDictionary::values(){
    std::vector<double> correct;
    for (auto iter = lst.begin(); iter != lst.end(); iter++){
            correct.push_back(iter->second);
    }
    return correct;
}

std::vector<Pair<int,double>> HashTableDictionary::entries()
{
    std::vector<Pair<int, double>> correct;
    Pair<int, double> s(0,0.0);
    for (auto iter = lst.begin(); iter != lst.end(); iter++){
            s.first = iter->first;
            s.second = iter->second;
            correct.push_back(s);
    }
    return correct;
}
