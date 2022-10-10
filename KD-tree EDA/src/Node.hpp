#include <iostream>
#include "Point.hpp"

template <size_t N, typename ElemType>
struct Node {
  typedef std::pair<Point<N>, ElemType> value_type;
  Node *left;
  Node *right;
  ElemType value;
  int level;
  Point<N> p;
  Node(){
    left=nullptr;
    right=nullptr;
    this-> level = level;
  }
  Node(value_type &value,int Level);
  Node(const Point<N>& Pt, int Level, const ElemType& Value=ElemType()){
    left = nullptr;
    right = nullptr;
    value = Value;
    level = Level; 
    p = Pt;
  }
};
