// Prim Wandeevong // CS 302 - Homework 5: BinarySearchTree.h // 4-21-20 //
#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H
#include "BinaryNode.h"

template<class ItemType>
class BinarySearchTree
{
    private:
        BinaryNode<ItemType> *rootPtr;

    protected:
        //------------------------------------------------------------
        // Protected Utility Methods Section:
        // Recursive helper methods for the public methods.
        //------------------------------------------------------------
        // Places a given new node at its proper position in this binary
        // search tree.
        BinaryNode<ItemType> *placeNode(BinaryNode<ItemType> *subTreePtr, BinaryNode<ItemType> *newNode);
        int getHeightFromNode(BinaryNode<ItemType> *subTreePtr) const;
        void preorderTraverseFromNode(BinaryNode<ItemType> *subTreePtr) const;
        void inorderTraverseFromNode(BinaryNode<ItemType> *subTreePtr) const;
        void postorderTraverseFromNode(BinaryNode<ItemType> *subTreePtr) const;

    public:
        //------------------------------------------------------------
        // Constructor and Destructor Section.
        //------------------------------------------------------------
        BinarySearchTree();
        //------------------------------------------------------------
        // Public Methods Section.
        //------------------------------------------------------------
        int getHeight() const;
        bool add(const ItemType& newEntry);

        //------------------------------------------------------------
        // Public Traversals Section.
        //------------------------------------------------------------
        void preorderTraverse() const;
        void inorderTraverse() const;
        void postorderTraverse() const;
}; 

#include "BinarySearchTree.cpp"
#endif