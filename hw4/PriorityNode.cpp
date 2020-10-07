template <class ItemType>
PriorityNode<ItemType>::PriorityNode()
{
    m_next = NULL;
}

template <class ItemType>
PriorityNode<ItemType>::PriorityNode(const ItemType& anItem, const int& priority)
{
    m_item = anItem;
    m_priority = priority;
    m_next = NULL;
}

template <class ItemType>
void PriorityNode<ItemType>::setItem(const ItemType& anItem)
{
    m_item = anItem;
}

template <class ItemType>
void PriorityNode<ItemType>::setNext(PriorityNode<ItemType>* nextNodePtr)
{
    m_next = nextNodePtr;
}

template <class ItemType>
ItemType PriorityNode<ItemType>::getItem() const
{
    return m_item;
}

template <class ItemType>
PriorityNode<ItemType>* PriorityNode<ItemType>::getNext() const
{
    return m_next;
}

template <class ItemType>
int PriorityNode<ItemType>::getPriority() 
{
    return m_priority;
}
