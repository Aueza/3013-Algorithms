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
        void sort();
};

int main()
{
    ifstream infile;
    infile.open("test.dat");

    int testArr[] = { 65, 23, 6, 54, 10 };

    listVector test(testArr, 5);
    test.print();

    test.sort();
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

    if(!front && !rear)
        {
            pushFront(travel->element);
            travel = travel->next;
        }
    
    while(travel)
    {
        pushRear(travel->element);
        travel = travel->next;
    }
}

//declaring all push functions
void listVector::pushFront(const int &value)
{
    Node* temp = new Node(value);
    temp->next = front;
    front = temp;
}

//need to change from pop to ->element
void listVector::pushFront(listVector &other)
{
    Node* travel = other.front;
    int index = 0;
    while(travel)
    {
       int tempVal = travel->element;
       pushAt(index, tempVal);
       travel = travel->next;
       index++;
    }
}

void listVector::pushRear(const int &value)
{
    Node* temp = new Node(value);
    Node* travel = front;
    if(front == NULL)
    {
        front = temp;
        rear = temp;
    }
    while(travel->next != NULL)
    {
        travel = travel->next;
    }
    travel->next = temp;
    rear = temp;
}
        
void listVector::pushRear(listVector &other)
{
    Node* travel = other.front;
    while(travel)
    {
       pushRear(travel->element);
       travel = travel->next;
    }
}

void listVector::pushAt(const int &location, const int &value)
{
    Node* temp = new Node(value);
    Node* previous = front;
    Node* travel = front;

    if(location == 0)
    {
        temp->next = front;
        front = temp;
        return;
    }  
    if(location != 0)
    {
        for(int i = 0; i < location; i++)
        {
       
            if(travel == NULL)
            {
                cout << "unable to access location " << location << endl;
                return;
            }
            else
            {
                previous = travel;
                travel = travel->next;
            }
        }
    } 
    
    if(previous == rear)
    {
        temp->next = travel;
        previous->next = temp;
        rear = temp;
        cout << "rear = " << rear->element << endl;
    }
    temp->next = travel;
    previous->next = temp;
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
    Node* previous = front;
    Node* travel = front;

    if(location == 0)
    {
        return popFront();
    }

    if(location != 0)
    {
        for(int i = 0; i < location; i++)
        {
       
            if(travel->next == NULL)
            {
                return -1;
            }
            else
            {
                previous = travel;
                travel = travel->next;
            }
        }
    } 
    
    if(previous == rear)
    {
        int tempVal = popRear();
        previous = rear;
        return tempVal;
    }
    
    previous->next = travel->next;
    return travel->element;
    delete travel;

}
        
int listVector::find(const int &value)
{
    Node* travel = front;
    int key = value;
    int indexCount = 0;
    while(travel)
    {
        if(travel->element == key)
        {
            return indexCount;
        }
        else
        {
            indexCount++;
            travel = travel->next;
        }
    }
    return -1;
}

void listVector::print()
{
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

void listVector::sort()
{
    
}