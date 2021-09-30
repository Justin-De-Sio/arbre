#ifndef CRANDOMTREE_HPP
#define CRANDOMTREE_HPP

#include <cstdlib> //rand ()
#include <memory.h> // shared_ptr (), ...
#include <iostream> // rand ()
#include "node.hpp"

template <typename T>
class RDTree
{
private:
    //T m_data;
    std::shared_ptr<CNode<T>> m_Root;
    //void localAdd (const std::shared_ptr<CNode<T>> & ptr, const T &Val);
    // void localShow (const std::shared_ptr<CNode<T>> & ptr);
public:
    RDTree (const T & val);
    ~ RDTree() {}
    void add (const T & Val);
    void show () const;
};

template<typename T>
RDTree<T>::RDTree(const T &val)
{
    std::shared_ptr<CNode <T>> tmp (new CNode<T> (val));
    m_Root = tmp;
}
