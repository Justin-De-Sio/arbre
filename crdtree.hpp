#ifndef CRDTREE_HPP
#define CRDTREE_HPP
#include <memory>
#include <iostream>
#include "node.hpp"
#include <stdlib.h>

template <typename T>
class crdtree
{
private:
    std::shared_ptr<CNode<T>> m_root;

public:
    crdtree (const T & val);
    ~crdtree () {}

    void add (const T & val);
    void show () const;
    //    bool find (const T & val) const;
};

template<typename T>
crdtree<T>::crdtree(const T &val) : m_root (new CNode<T> (val))
{}

template<typename T>
void crdtree<T>::add(const T &val)
{
    //s'il n'y a rien à gauche
    if (m_root->getGauche() == nullptr)
        //on fait une insertion
        m_root->setGauche (std::shared_ptr<CNode<T>>
                                   (new CNode<T> (val)));
        //s'il n'y a rien à droite
    else if (m_root->getDroit () == nullptr)
        //on fait une insertion
        m_root->setDroit (std::shared_ptr<CNode<T>>
                                  (new CNode<T> (val)));
}

template<typename T>
void crdtree<T>::show() const
{
    //on affiche la racine
    std::cout << m_root->getData () << std::endl;
    //si fils gauche
    if (m_root->getGauche () != nullptr)
        //on affiche
        std::cout << m_root->getGauche () ->getData () << std::endl;
    //si fils droit
    if (m_root->getDroit () != nullptr)
        //on affiche
        std::cout << m_root->getDroit () ->getData () << std::endl;
}














#endif // CRDTREE_HPP