#include "Pair.hpp"
#include "Dictionary.hpp"
#include "BSTDictionary.hpp"
#include "BST.hpp"
#include "BSTNode.hpp"

BSTDictionary::BSTDictionary()
{
 lst = BST();
}

bool BSTDictionary::insert(int k, double v) {
    lst.insert(k,v);
    return true;
}

double BSTDictionary::get(int k)
{
 return lst.search(k,-3.14);
}

bool BSTDictionary::remove(int k){
return lst.remove(k);
}

std::vector<Pair<int,double>> BSTDictionary::get_range(int k1, int k2){
 std::vector<Pair<int, double>> v = lst.entries();
 std::vector<Pair<int, double>> correct;
 for (int i = 0; i < v.size(); i++){
    if(v[i].first <= k2 && v[i].first >= k1) {
        correct.push_back(v[i]);
    }
}
  return correct;
}

int BSTDictionary::size(){
return lst.size();
}

bool BSTDictionary::is_empty(){
return lst.is_empty();
}

void BSTDictionary::clear(){
lst.clear();
}

std::vector<int> BSTDictionary::keys(){
 return lst.keys();
}

std::vector<double> BSTDictionary::values(){
 return lst.values();
}

std::vector<Pair<int,double>> BSTDictionary::entries()
{
 return lst.entries();
}
