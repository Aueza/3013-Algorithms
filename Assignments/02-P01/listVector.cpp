#include "listVector.h"

listVector::listVector()
{
    front = rear = nullptr;
}

listVector::listVector(const int arr[], const int& size)
{

}

listVector::listVector(const int &vect)
{

}

//declaring all push functions
void listVector::pushFront(const int &value)
{
    Node* temp = new Node(value);
    if(!front && !rear)
    {
        front = rear = temp;
    }
    else
    {
        front->next = temp;
        front = temp;
    }
}
        
void listVector::pushFront(const listVector &vect)
{

}
        
void listVector::pushRear(const int &value)
{

}
        
void listVector::pushRear(const listVector &vect)
{

}
        
void listVector::pushAt(const int &location, const int &value)
{

}
        
void listVector::inOrderPush(const int &value)
{

}

//declaring all pop functions
int listVector::popFront()
{
    int tempVal = front->element;
    Node* temp = front;
    front = front->next;
    delete temp;
    return tempVal;
}
        
int listVector::popRear()
{
    return -1;
}
        
int listVector::popAt(const int &location)
{
    return -1;
}
        
int listVector::find(const int &value)
{
    return -1;
}