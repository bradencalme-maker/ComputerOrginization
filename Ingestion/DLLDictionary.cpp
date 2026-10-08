#include "Pair.hpp"
#include "Dictionary.hpp"
#include "DLLDictionary.hpp"
#include "DoublyLinkedList.hpp"
#include "DLLNode.hpp"

DLLDictionary::DLLDictionary()
{
 lst = DoublyLinkedList();
}

bool DLLDictionary::insert(int k, double v) {
 /*
 if (lst.contains(k))
 {
  return false;
 }
 else
 {
  lst.push_front(k,v);
  return true;
 }
  */
    lst.push_front(k,v);
    return true;
}

double DLLDictionary::get(int k)
{
 return lst.search(k,-3.14);
}

bool DLLDictionary::remove(int k){
return lst.remove_key(k);
}

std::vector<Pair<int,double>> DLLDictionary::get_range(int k1, int k2){
 std::vector<Pair<int, double>> v;
 if(!lst.is_empty())
 {
  int count = 0;
  int len = lst.size();
  while(count < len)
  {
   if(lst.at(count).first >= k1 && lst.at(count).first <= k2)
   {
    v.push_back(lst.at(count));
   }
   count++;
  }
 }
 return v;
}

int DLLDictionary::size(){
return lst.size();
}

bool DLLDictionary::is_empty(){
return lst.is_empty();
}

void DLLDictionary::clear(){
lst.clear();
}

std::vector<int> DLLDictionary::keys(){
 std::vector<int> v;
 if (!lst.is_empty())
 {
  int count = 0;
  int len = lst.size();
  while (count < len)
  {
   v.push_back(lst.at(count).first);
   count++;
  }
 }
 return v;
}

std::vector<double> DLLDictionary::values(){
 std::vector<double> v;
 if (!lst.is_empty())
 {
  int count = 0;
  int len = lst.size();
  while (count < len)
  {
   v.push_back(lst.at(count).second);
   count++;
  }
 }
 return v;
}

std::vector<Pair<int,double>> DLLDictionary::entries()
{
 std::vector<Pair<int, double>> v;
 if (!lst.is_empty())
 {
  int count = 0;
  int len = lst.size();
  while (count < len)
  {
  v.push_back(lst.at(count));
  count++;
  }
 }
 return v;
}
