#include <iostream>

using namespace std;

//creating a struct for the nodes
struct Node
{
    int element;
    Node* next;
    Node(int ele)
    {
        element = ele;
        next = nullptr;
    }
};

//class initialization
class listVector
{
    private:
        //declaring private member variables
        Node* front;
        Node* rear;
    public:
        //declaring constructors
        listVector();
        listVector(const int arr[], const int& size);
        listVector(const int &vect);

        //declaring all push functions
        void pushFront(const int &value);
        void pushFront(const listVector &vect);
        void pushRear(const int &value);
        void pushRear(const listVector &vect);
        void pushAt(const int &location, const int &value);
        void inOrderPush(const int &value);

        //declaring all pop functions
        int popFront();
        int popRear();
        int popAt(const int &location);
        int find(const int &value);
};

int main()
{
    listVector test;
    test.pushFront(10);
    test.pushRear(5);
    test.pushFront(2);

    int num1 = test.popRear();
    int num2 = test.popRear();
    cout << num1 << " " << num2;
}

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
        temp->next = front;
        front = temp;
    }
}
        
void listVector::pushFront(const listVector &vect)
{

}
        
void listVector::pushRear(const int &value)
{
    Node* temp = new Node(value);
    rear->next = temp;
    rear = temp;
    cout << "rear is now..." << rear->element << endl;
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
    int tempVal = rear->element;
    Node* traveler = front;

    while(traveler)
    {
        if(traveler->next = rear)
        {
            rear = traveler;
            cout << "rear now pointing to..." << rear->element << endl;
            delete traveler;
            
        }
        else
        {
            traveler = traveler->next;
            cout << "traveling to..." << traveler->element << endl;
        }      
    }
    return tempVal;
}
        
int listVector::popAt(const int &location)
{
    return -1;
}
        
int listVector::find(const int &value)
{
    return -1;
}