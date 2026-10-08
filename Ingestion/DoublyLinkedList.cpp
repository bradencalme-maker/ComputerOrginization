#include "DoublyLinkedList.hpp"
#include "DLLNode.hpp"
#include<vector>

DoublyLinkedList::DoublyLinkedList() {
    head = tail = nullptr;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other){

 head = tail = nullptr;
 DLLNode* other_iter = other.head;
 while(other_iter != nullptr)
 {
  this->push_back(other_iter->key, other_iter->value);
  other_iter = other_iter->next;
 }
}

DoublyLinkedList::~DoublyLinkedList() {
    if (head != nullptr) {
        delete head;
        head = nullptr;
    }
}

//is_empty
bool DoublyLinkedList::is_empty(){
 return head == nullptr;
}

//size
int DoublyLinkedList::size() {
    DLLNode* iter = head;
    int count = 0;
    while (iter != nullptr) {
        count++;
        iter = iter -> next;
    }
    return count;
}

//length
int DoublyLinkedList::length() { return size(); }


//push_front
void DoublyLinkedList::push_front(int k, double v) {
 if (is_empty()) {
  head = tail = new DLLNode(k,v);
 }
 else {
  head = new DLLNode(head, nullptr, k, v);
  head->next->prev = head;
 }
}

//push_back
void DoublyLinkedList::push_back(int k, double v) {
 if (is_empty()){
  head = tail = new DLLNode(k,v);
 }
 else {
  tail = new DLLNode(nullptr, tail, k, v);
  tail->prev->next = tail;
 }
}

//insert
bool DoublyLinkedList::insert(int k, double v, int i){
 if (i < 0){
  return false;
 }
 else{
  DLLNode* iter = head;
  if (i == 0){
   push_front(k,v);
   return true;
  }
  else if (iter == nullptr) { //could be is_empty() instead
   return false;
  }
  int count = 1;
  while (iter != nullptr && count != i) {
   iter = iter->next;
   count++;
  }  // at end of loop iter points at the node before the slot 
  if (iter == nullptr){
   return false;
  }
//  for (int count == 0; iter != nullptr; iter = iter->next) could do this instead of while loop
  else if (count == i)
  {
   DLLNode* new_node = new DLLNode(iter->next, iter, k,v);
   if (iter != tail)
   {
     iter->next->prev = new_node;
   }
   iter->next = new_node;
   if (iter == tail)
   {
    tail = new_node;
   }
   return true;
  }
  else
  {
   return false;
  }
 }
}


//search
double DoublyLinkedList::search(int k, double dfault)
{
 DLLNode* iter = head;
 for(; iter != nullptr && iter->key != k;iter = iter->next);
 if (iter == nullptr)
 {
  return dfault;
 }
 else
 {
  return iter->value;
 }
}

//get_front
Pair<int,double> DoublyLinkedList::get_front()
{
 if (is_empty())
 {
  Pair<int, double> p1 (-1, -1.1);
  return p1;
 }
 else
 {
  Pair<int,double> p2 (head->key,head->value);
  return p2;
 }
}

//get_back
Pair<int,double> DoublyLinkedList::get_back()
{
 if (is_empty())
 {
  Pair<int, double> p1 (-1, -1.1);
  return p1;
 }
 else
 {
  Pair<int,double> p2 (tail->key,tail->value);
  return p2;
 }
}


//contains
bool DoublyLinkedList::contains(int k)
{
 if(is_empty())
 {
  return false;
 }
 else
 {
  DLLNode* iter = head;
  for(;iter != nullptr && iter->key != k;iter = iter->next);
  if (iter == nullptr)
  {
   return false;
  }
  else
  {
   return true;
  }
 }
}



DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& other)
{
 if (this != &other)
 {
  DLLNode* iter_other = other.head;
  while (iter_other != nullptr)
  {
   this->push_back(iter_other->key,iter_other->value);
   iter_other = iter_other->next;
  }
 }
 return *this;
}

//at
Pair<int, double> DoublyLinkedList::at(int i)
{
 if (!is_empty())
 {
  DLLNode* iter = head;
  int count = 0;
  while(iter != nullptr)
  {
   if (i == count)
   {
    Pair<int, double> p2 (iter->key, iter->value);
    return p2;
   }
   iter = iter->next;
   count++;
  }
 }
 Pair<int, double> p1 (-1,-1.1);
 return p1;
}

//contains_value
bool DoublyLinkedList::contains_value(double v)
{
  if(is_empty())
 {
  return false;
 }
 else
 {
  DLLNode* iter = head;
  for(;iter != nullptr && iter->value != v;iter = iter->next);
  if (iter == nullptr)
  {
   return false;
  }
  else
  {
   return true;
  }
 }
}

//find
int DoublyLinkedList::find(int k, int dfault)
{
  if(is_empty())
 {
  return dfault;
 }
 else
 {
  DLLNode* iter = head;
  int index = 0;
  for(;iter != nullptr && iter->key != k;iter = iter->next)
  {
   index++;
  }
  if (iter == nullptr)
  {
   return dfault;
  }
  else
  {
   return index;
  }
 }
}

//pop_front
bool DoublyLinkedList::pop_front()
{
 if(!is_empty())
 {
  DLLNode* bye = head;
  head = head->next;
  if (head != nullptr)
  {
   head->prev = nullptr;
  }
  else
  {
   tail = nullptr;
  }
  bye->next = nullptr;
  delete bye;
  return true;
 }
 return false;
}

//pop_back
bool DoublyLinkedList::pop_back()
{
 if(!is_empty())
 {
  DLLNode* bye = tail;
  tail = tail->prev;
  if (tail != nullptr)
  {
   tail->next = nullptr;
  }
  else {
  head = nullptr;
  }
  bye->prev = nullptr;
  delete bye;
  return true;
 }
 return false;
}

//remove
bool DoublyLinkedList::remove(int i)
{
 if (!is_empty())
 {
  if (i == 0)
  {
   pop_front();
   return true;
  }
  else if(i == size()-1)
  {
   pop_back();
   return true;
  }
  else
  {
   DLLNode* curr = head;
   for (int count = 0; curr != nullptr && count != i-1; count++)
   {
    curr = curr->next;
   }
    if (curr == nullptr)
    {
     return false;
    }
    DLLNode* bye = curr->next;
    curr->next = bye->next;
    curr->next->prev = curr;
    bye->next = bye->prev = nullptr;
    delete bye;
    return true;
  }
 }
 return false;
}

//remov_key
bool DoublyLinkedList::remove_key(int k)
{
 if (!is_empty())
 {
  DLLNode* bye = head;
  for (;bye != nullptr && bye->key !=k; bye = bye->next);
  if (bye == nullptr)
  {
   return false;
  }
  else if (bye == head)
  {
   pop_front();
   return true;
  }
  else if (bye == tail)
  {
   pop_back();
   return true;
  }
  else
  {
   DLLNode* curr = bye->prev;
   curr->next = bye->next;
   curr->next->prev = curr;
   bye->next = bye->prev = nullptr;
   delete bye;
   return true;
  }
 }
 return false;
}

//clear
void DoublyLinkedList::clear()
{
 while (head != nullptr)
 {
  pop_front();
 }
}




















