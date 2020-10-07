// Prim Wandeevong // CS 302 - Homework 5: BinarySearchTree.cpp // 4-21-20 //
#include "BinaryNode.h"
#include "BinarySearchTree.h"
using namespace std;

//Default Constructor
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(NULL) 
{
}

//Parameterized Constructor
template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType &newEntry) 
{
    BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
    rootPtr = placeNode(rootPtr, newNodePtr);
    return true;
}

//Place Node Method
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::placeNode(BinaryNode<ItemType> *treePtr, BinaryNode<ItemType> *newNode) 
{
    BinaryNode<ItemType>* tempPtr;

    if (treePtr == NULL) 
    {
        return newNode;
    }  
    else if (treePtr->getItem() > newNode->getItem()) 
    {
        tempPtr = placeNode(treePtr->getLeftChildPtr(), newNode);
        treePtr->setLeftChildPtr(tempPtr);
    } 
    else 
    {
        tempPtr = placeNode(treePtr->getRightChildPtr(), newNode);
        treePtr->setRightChildPtr(tempPtr);
    }

    return treePtr;
}

//Get Height From Root Method
template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
    return getHeightFromNode(rootPtr);
}

//Get Height From Node Method
template<class ItemType>
int BinarySearchTree<ItemType>::getHeightFromNode(BinaryNode<ItemType> *treePtr) const 
{
    if (treePtr == NULL) 
    {
        return 0;
    } 
    else 
    {
        int leftHeight = getHeightFromNode(treePtr->getLeftChildPtr());
        int rightHeight = getHeightFromNode(treePtr->getRightChildPtr());
        return max(leftHeight, rightHeight) + 1;
    }
}

//Preorder Traverse Method - From Root
template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse() const 
{
    cout << "[PREORDER]" << endl;
    preorderTraverseFromNode(rootPtr);
    cout << endl << endl;
}

//Inorder Traverse Method - From Root
template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse() const 
{
    cout << "[INORDER]" << endl;
    inorderTraverseFromNode(rootPtr);
    cout << endl << endl;
}

//Postorder Traverse Method - From Root
template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse() const 
{
    cout << "[POSTORDER]" << endl;
    postorderTraverseFromNode(rootPtr);
    cout << endl << endl;
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverseFromNode(BinaryNode<ItemType> *treePtr) const 
{
    if (treePtr == NULL) 
    {
        return;
    }

    cout << treePtr->getItem() << " ";
    preorderTraverseFromNode(treePtr->getLeftChildPtr());
    preorderTraverseFromNode(treePtr->getRightChildPtr());
}



template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverseFromNode(BinaryNode<ItemType> *treePtr) const 
{
    if (treePtr == NULL) 
    {
        return;
    }

    inorderTraverseFromNode(treePtr->getLeftChildPtr());
    cout << treePtr->getItem() << " ";
    inorderTraverseFromNode(treePtr->getRightChildPtr());
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverseFromNode(BinaryNode<ItemType> *treePtr) const 
{
    if (treePtr == NULL) 
    {
        return;
    }

    postorderTraverseFromNode(treePtr->getLeftChildPtr());
    postorderTraverseFromNode(treePtr->getRightChildPtr());
    cout << treePtr->getItem() << " ";
}