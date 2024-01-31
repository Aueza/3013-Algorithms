#include <iostream>
#include <fstream>

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
        listVector(ifstream &infile);
        listVector(listVector &other);

        //declaring all push functions
        void pushFront(const int &value);
        void pushFront(listVector &other);
        void pushRear(const int &value);
        void pushRear(listVector &other);
        void pushAt(const int &location, const int &value);
        void inOrderPush(const int &value);

        //declaring all pop functions
        int popFront();
        int popRear();
        int popAt(const int &location);
        int find(const int &value);

        void print();
};

int main()
{
    ifstream infile;
    infile.open("test.dat");

    int testArr[] = { 2, 4, 6, 8, 10 };

    listVector test(testArr, 5);
    test.print();

    listVector test2(test);
    test2.print();

    test.pushFront(15);
    test.print();
}

listVector::listVector()
{
    front = rear = nullptr;
}

listVector::listVector(const int arr[], const int& size)
{
    front = rear = nullptr;

    for(int i = 0; i < size; i++)
    {
        if(!front && !rear)
        {
            pushFront(arr[i]);
        }
        else
        {
            pushRear(arr[i]);
        }
    }
}

listVector::listVector(ifstream &infile)
{
    front = rear = nullptr;
    int value = 0;
    while(!infile.eof())
    {
        infile >> value;
        if(!front && !rear)
        {
            pushFront(value);
        }
        else
        {
            pushRear(value);
        }
    }
}

listVector::listVector(listVector &other)
{
    front = rear = nullptr;
    Node* travel = other.front;
    while(travel->next != NULL)
    {
        pushFront(other.popRear());
    }
    pushFront(other.popFront());
}

//declaring all push functions
void listVector::pushFront(const int &value)
{
    Node* temp = new Node(value);
    temp->next = front;
    front = temp;
}
        
void listVector::pushFront(listVector &other)
{
    Node* travel = other.front;
    while(travel->next != NULL)
    {
        pushFront(other.popRear());
    }
    pushFront(other.popFront());
}
        
void listVector::pushRear(const int &value)
{
    Node* temp = new Node(value);
    Node* travel = front;
    if(!front && !rear)
    {
        front->next = temp;
        rear = temp;
    }
    while(travel->next != NULL)
    {
        travel = travel->next;
    }
    travel->next = temp;
    rear = travel->next;
}
        
void listVector::pushRear(listVector &other)
{

}
        
void listVector::pushAt(const int &location, const int &value)
{
    Node* temp = new Node(value);
    Node* travel = front;
}
        
void listVector::inOrderPush(const int &value)
{

}

//declaring all pop functions
int listVector::popFront()
{
    if(!front && !rear)
    {
        return front->element;
    }
    int tempVal = front->element;
    Node* temp = front;
    front = front->next;
    return tempVal;
}
        
int listVector::popRear()
{
    Node* travel = front;
    while(travel->next->next != NULL)
    {
        travel = travel->next;
    }
    rear = travel->next;
    travel->next = NULL;
    int tempVal = rear->element;
    rear = travel;
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

void listVector::print(){
    Node* travel = front;
    while(travel){
      cout<<travel->element;
      if(travel->next){
        cout<<"->";
      }
      travel = travel->next;
    }
    cout<<endl<<endl;
  }