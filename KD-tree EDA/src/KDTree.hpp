#ifndef SRC_KDTREE_HPP_
#define SRC_KDTREE_HPP_

#include <cmath>
#include <iostream>
#include <set>
#include <stdexcept>
#include <utility>
#include "Point.hpp"
#include "Node.hpp"

using namespace std;

template <size_t N, typename ElemType>
class KDTree {
public:
    typedef std::pair<Point<N>, ElemType> value_type;

    Node<N,ElemType> *root;

    KDTree();

    ~KDTree();

    KDTree(const KDTree &rhs);
    KDTree &operator=(const KDTree &rhs);

    size_t dimension() const;

    size_t size() const;
    bool empty() const;

    bool contains(const Point<N> &pt) const;

    void insert(const Point<N> &pt, const ElemType &value=ElemType());
    
    Node<N,ElemType>* Search( Node<N,ElemType>* temp,const Point<N>& pt) const;
    
    ElemType &operator[](const Point<N> &pt);
    
    ElemType &at(const Point<N> &pt); 
    const ElemType &at(const Point<N> &pt) const; 
    
    ElemType knn_value(const Point<N> &key, size_t k) const; 
    
    std::vector<ElemType> knn_query(const Point<N> &key, size_t k) const;
private:
    size_t dimension_;
    size_t size_;
};

template <size_t N, typename ElemType>
KDTree<N, ElemType>::KDTree() {
    dimension_ = N;
    size_ = 0;
    root = nullptr;
}

template <size_t N, typename ElemType>
KDTree<N, ElemType>::~KDTree() {
    
}

template <size_t N, typename ElemType>
KDTree<N, ElemType>::KDTree(const KDTree &rhs) {
    this->root= rhs.root;
    this->dimension_=rhs.dimension();
    this->size_=rhs.size();
}

template <size_t N, typename ElemType>
KDTree<N, ElemType> &KDTree<N, ElemType>::operator=(const KDTree &rhs) {
    if (this != &rhs) {
        freeResource(root);
        this->root = rhs.root;
        this->size = rhs.size;
    }
    return *this;
}

template <size_t N, typename ElemType>
size_t KDTree<N, ElemType>::dimension() const {
  return dimension_;
}

template <size_t N, typename ElemType>
size_t KDTree<N, ElemType>::size() const {
  return size_;
}

template <size_t N, typename ElemType>
bool KDTree<N, ElemType>::empty() const {
    if (size_ == 0){
        return true;
    }
    return false;
}

template <size_t N, typename ElemType>
Node<N,ElemType>* KDTree<N, ElemType>::Search(Node<N,ElemType>* temp, const Point<N>& pt) const{
    if (temp == nullptr || temp -> p == pt) {
        return temp;
    }
    const Point<N>& p1 = temp -> p;
    int level = temp -> level;
    if (pt[level % N] < p1[level % N]) {
        if (temp ->left == nullptr){
            return temp;
        }
        else{
            return (Search(temp->left ,pt));
        }
    } 
    else {
        if (temp -> right == nullptr){
            return temp;
        }
        else{
            return (Search(temp->right ,pt));
        }
    }
    level++;
}

template <size_t N, typename ElemType>
bool KDTree<N, ElemType>::contains(const Point<N> &pt) const {
    auto temp = Search(root, pt);
    if(temp != nullptr && temp->p == pt)
        return true;
    return false;
}

template <size_t N, typename ElemType>
void KDTree<N, ElemType>::insert(const Point<N> &pt, const ElemType &value) {
    auto temp = Search(root, pt);
    if (temp == nullptr) {
        root = new Node<N,ElemType>(pt, 0, value);
        size_ = 1;
      }
    else {
        if (temp->p == pt){
            temp->value = value;
        }
        else{
            int level = temp->level;
            Node<N,ElemType>* nNode = new Node<N,ElemType>(pt, level + 1, value);
            if (pt[level % N] < temp->p[level % N]) {
                temp->left = nNode;
            }
            else {
                temp->right = nNode;
            }
            size_++;
        }
    }
}

template <size_t N, typename ElemType>
ElemType &KDTree<N, ElemType>::operator[](const Point<N> &pt) {
    auto temp = Search(root, pt);
    if (temp != nullptr && temp->p == pt){
        return temp->value;
    }
    else {
        insert(pt);
        if (temp == nullptr){
            return root->value;
        }
        else{
            if (temp->left != nullptr && temp->left->p == pt){
                return temp->left->value;
            }
            else{
                return temp->right->value;
            }
        }
    }
}

template <size_t N, typename ElemType>
ElemType &KDTree<N, ElemType>::at(const Point<N> &pt) {
    const KDTree<N, ElemType>& constThis = *this;
    return const_cast<ElemType&>(constThis.at(pt));
}

template <size_t N, typename ElemType>
const ElemType &KDTree<N, ElemType>::at(const Point<N> &pt) const {
    auto node = Search(root, pt);
    if (node == nullptr || node->p != pt) {
        throw out_of_range("The point was not found");
    } 
    else {
        return node->value;
    }
}   

template <size_t N, typename ElemType>
ElemType KDTree<N, ElemType>::knn_value(const Point<N> &key, size_t k) const {
  
}

template <size_t N, typename ElemType>
std::vector<ElemType> KDTree<N, ElemType>::knn_query(const Point<N> &key,size_t k) const {
    //no hay tiempooooo :c
}

#endif  