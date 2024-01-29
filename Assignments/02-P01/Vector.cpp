#include "Vector.h"

Vector::Vector()
{
    front = rear = nullptr;
}

Vector::Vector(const int arr[], const int& size)
{

}

Vector::Vector(const int &vect)
{

}

//declaring all push functions
void Vector::pushFront(const int &value)
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
        
void Vector::pushFront(const Vector &vect)
{

}
        
void Vector::pushRear(const int &value)
{

}
        
void Vector::pushRear(const Vector &vect)
{

}
        
void Vector::pushAt(const int &location, const int &value)
{

}
        
void Vector::inOrderPush(const int &value)
{

}

//declaring all pop functions
int Vector::popFront()
{
    int tempVal = front->element;
    Node* temp = front;
    front = front->next;
    delete temp;
    return tempVal;
}
        
int Vector::popRear()
{

}
        
int Vector::popAt(const int &location)
{

}
        
int Vector::find(const int &value)
{

}