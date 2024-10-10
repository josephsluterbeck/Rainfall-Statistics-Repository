// LinkedList.h
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType> {
private:
    Node<ItemType>* headPtr;
    int itemCount;

    Node<ItemType>* getNodeAt(int position) const;
public:
    LinkedList();
    virtual ~LinkedList();
    bool isEmpty() const override;
    int getLength() const override;
    bool insert(int newPosition, const ItemType& newEntry) override;
    bool remove(int position) override;
    void clear() override;
    ItemType getEntry(int position) const override;
    void setEntry(int position, const ItemType& newEntry) override;
};

#include "LinkedList.cpp"
#endif
