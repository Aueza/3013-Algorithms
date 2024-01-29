#pragma once
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
class Vector
{
    private:
        //declaring private member variables
        Node* front;
        Node* rear;
    public:
        //declaring constructors
        Vector();
        Vector(const int arr[], const int& size);
        Vector(const int &vect);

        //declaring all push functions
        void pushFront(const int &value);
        void pushFront(const Vector &vect);
        void pushRear(const int &value);
        void pushRear(const Vector &vect);
        void pushAt(const int &location, const int &value);
        void inOrderPush(const int &value);

        //declaring all pop functions
        int popFront();
        int popRear();
        int popAt(const int &location);
        int find(const int &value);
};