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