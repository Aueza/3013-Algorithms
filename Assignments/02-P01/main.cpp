/*****************************************************************************
*                    
*  Author:           Ethan Saenz
*  Email:            ethacs18@gmail.com
*  Label:            P01
*  Title:            Vector Class
*  Course:           CMPS 3013
*  Semester:         Spring 24
* 
*  Description:
*       This program implements a struct paired with a class that allows a linked 
        list to be used as a vector. The class uses numerous push and pop functions 
        that add/remove values through the vector. As well as allowing for 
        multiple ways to inititalize a vector. This class is not intended to 
        replace the STL vector library, but it introduces complex / abstract
        data types.
*        
*  Usage:
*        This program will read in a file containing whatever values to be read into
* 
*  Files:            
        main.cpp   : driver program
*****************************************************************************/

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

/**
 * listVector
 * 
 * Description:
 *      This class creates a list-based vector. Using vector-like functions such 
 *      as pop and push. While also using multiple parametized constructors
 *      to allow for different methods of initialization.
 * 
 * Public Methods:
 *      -               listVector()
 *      -               listVector(const int arr[], const int& size)
 *      -               listVector(ifstream &infile)
 *      -               listVector(listVector &other)
 * 
 *      - void          pushFront(const int &value)        
 *      - void          pushFront(listVector &other)
 *      - void          pushRear(const int &value)
 *      - void          pushRear(listVector &other)
 *      - void          pushAt(const int &location, const int &value)
 *      - void          inOrderPush(const int &value)
 * 
 *      - int            popFront()
 *      - int            popRear()
 *      - int            popAt(const int &location)
 *      - int            find(const int &value)
 * 
 *      - void           print()
 *      - void           sort()
 *      - int            size()
 * 
 * Private Methods:
 *      - Node*          front
 *      - Node*          rear
 *      
 * 
 * Usage: 
 * 
 *      - listVector v1                         //  Create an instance of vector w/ front & rear 
 *                                              //  initialized to nullptr.
 * 
 *      - listVector v2(array, 5)               //  Create an instance of vector using an int array
 *                                              //  and its size as params.
 * 
 *      - listVector v3(infile)                 //  Create an instance of vector using a file
 *                                              //  that contains the numbers used to fill it.
 * 
 *      - listVector v4(v3)                     //  Create an instance of a vector using another
 *                                              //  vector (clones the original vector).   
 */
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
        int size();
};

int main()
{
    ifstream infile;
    infile.open("test.dat");                    //  opening input and output files
    ofstream outfile;
    outfile.open("test.out");

    int x = 0;

    listVector v1;                              //  creating list-based vector using the default constructor named v1

    v1.pushFront(18);
    v1.pushFront(20);                           //  pushing 3 values to the front of v1.
    v1.pushFront(25);

    v1.pushRear(18);
    v1.pushRear(20);                            // pushing 3 values to the rear of v1.
    v1.pushRear(25);

    v1.print();                                 //  printing v1.
    // [25, 20, 18, 18, 20, 25]

    
    int A[] = {11,25,33,47,51};                 //  declaring an array of size 5 for a list-based vector.
    listVector v2(A,5);                         //  creating a list-based vector using the parametized constructor for an array named v2.
    v2.print();                                 //  printing v2
    // [11, 25, 33, 47, 51]

    v2.pushFront(9);
    v2.inOrderPush(27);                         //  pushing 3 values onto v2 using numerous push functions inside the class.
    v2.pushRear(63);
    
    v2.print();                                 //  printing v2 after the values have been pushed.
    // [9, 11, 25, 33, 47, 51, 63]

    v1.pushRear(v2);                            //  pushing v2 to the rear of v1
    v1.print();
    // [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

    x = v1.popFront();
    x = v1.popFront();                          //  popping 3 front values off of v1.
    x = v1.popFront();
    
    v1.print();                                 //  printing v1.
    // [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]

    cout<<x<<endl;                              //  printing the last "front" value in v1.
    // 18

    x = v1.popRear();
    x = v1.popRear();                           //  popping 3 values off the rear of v1.
    x = v1.popRear();
    
    v1.print();                                 //  printing v1.
    // [18, 20, 25, 9, 11, 25, 27, 33]

    cout<<x<<endl;                              //  printing the last "rear" value of v1.
    // 47

    x = v2.popAt(3);                            //  popping the value at index 3 in v2.
    v2.print();                                 //  printing v2 after the value at index 3 has been popped off.
    // [9, 11, 25, 33, 47, 51, 63]

    cout<<x<<endl;                              //  printing the value that was at index 3 in v2.
    // 27

    x = v2.find(51);                            //  finding and printing the index for the value 51 in v2.
    cout<<x<<endl;
    // 5

    x = v2.find(99);                            //  finding and printing the index for the value 99 in v2.
    cout<<x<<endl;
    // -1

    listVector v3(v1);                          //  creating v3 using the list-based vector constructor, using v1 as input, and printing out v3.
    v3.print();
    // [18, 20, 25, 9, 11, 25, 27, 33]

    v3.pushFront(v2);                           //  pushing the list-based vector v2 to the front of v3, and printing out the combined result.
    v3.print();
    //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

    listVector v4(infile);                      //  using the "test.dat" for the input for creating the list-based vector v4.
    v4.pushRear(v3);                            //  pushing v3 to the rear of v4 and printing out the combination.
    v4.print();
    // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]
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
    sort();
    Node* t1 = front;
    int key = value;
    int count = 0;

    while(t1)
    {
        if(key > t1->element)
        {
            t1 = t1->next;
            count++;
        }
        else if(key < t1->element)
        {
            pushAt(count, value);
            break;
        }
        else if(key == t1->element)
        {
            pushAt(count, value);
            break;
        }
    }

    if(t1 == NULL)
    {
        pushRear(value);
    }
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
    cout << '[';
    while(travel){
      cout<<travel->element;
      if(travel->next){
        cout<<", ";
      }
      travel = travel->next;
    }
    cout << ']';
    cout<<endl<<endl;
}

void listVector::sort()
{
    Node* travel1 = front;
    Node* travel2 = front;

    for(int i = 0; i < size(); i++)
    {
        for(int j = 0; j < size(); j++)
        {
            if(travel1->element < travel2->element)
            {
                int tempVal = travel1->element;
                travel1->element = travel2->element;
                travel2->element = tempVal;
            }
            travel2 = travel2->next;
        }
        travel2 = front;
        travel1 = front->next;
        for(int k = 0; k < i; k++)
            travel1 = travel1->next;
    }
}

int listVector::size()
{
    Node* travel = front;
    int count = 0;
    while(travel)
    {
        count++;
        travel = travel->next;
    }
    return count;
}