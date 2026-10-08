#include <iostream>
#include "BST.hpp"
#include "Pair.hpp"
#include "BSTDictionary.hpp"
#include "Dictionary.hpp"
#include "BSTNode.hpp"
#include <vector>

int main() {
    BSTDictionary diction;
    diction.insert(4,14.4);
    diction.insert(2,12.2);
    diction.insert(1, 11.1);
    diction.insert(3,13.3);
    diction.insert(6,16.6);
    diction.insert(5,15.5);
    diction.insert(7,17.7);
    std::cout << diction.size() << std::endl; //should be 7
    std::cout << diction.get(3) << std::endl; //should be 13.3
    diction.remove(2);
    std::cout << diction.size() << std::endl; //should be 6
    diction.remove(4);
    std::cout << diction.get(4) << std::endl; //should be -3.14
    std::vector<Pair<int, double>> v = diction.entries();
    std::cout <<  v.size() << std::endl; //should be 5
    std::cout << diction.is_empty() << std::endl; //should be 0
    std::vector<Pair<int, double>> g = diction.get_range(5,7);
    std::cout <<  g.size() << std::endl; //should be 3
    std::vector<int> k = diction.keys();
    std::cout << k.size() << std::endl; //should be 5
    std::vector<double> d = diction.values();
    std::cout << d.size() << std::endl; //should be 5
    diction.clear();
    std::cout << diction.is_empty() << std::endl; //should be 1
    return 0;
}