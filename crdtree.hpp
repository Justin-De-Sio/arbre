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

template<typename T>
void localAdd (const std::shared_ptr<CNode<T>> & ptr, const T &Val)
{
    if (ptr->getLC() == nullptr)
    {
        std::shared_ptr<CNode <T>> tmp (new CNode<T> (Val));
        ptr->setLC(tmp);
        return;
    }
    else if (ptr->getRC () == nullptr)
    {
        std::shared_ptr<CNode <T>> tmp (new CNode<T> (Val));
        ptr->setRC(tmp);
        return;
    }
    else if (std::rand() % 2)
        localAdd (ptr->getLC(), Val);
    else
        localAdd (ptr->getRC(), Val);
}

template<typename T>
void RDTree<T>::add(const T &Val)
{
    localAdd (m_Root, Val);
}


template<typename T>
void localShow (const std::shared_ptr<CNode<T>> & ptr)
{
    if (ptr == nullptr) return;
    localShow (ptr->getLC());
    std::cout << ptr->GetData () << std::endl;
    localShow (ptr->getRC());
}


template<typename T>
void RDTree<T>::show () const
{

    std::cout << m_Root->GetData () << std::endl;
    localShow (m_Root->getLC());
    localShow (m_Root->getRC());
}



#endif // CRANDOMTREE_HPP