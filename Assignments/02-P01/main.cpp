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

void printHeading(ofstream &outfile);

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

        void print(ofstream &outfile);
        void sort();
        int size();
};

int main()
{
    ifstream infile;
    infile.open("test.dat");                    //  opening input and output files
    ofstream outfile;
    outfile.open("test.out");
    printHeading(outfile);

    int x = 0;

    listVector v1;                              //  creating list-based vector using the default constructor named v1

    v1.pushFront(18);
    v1.pushFront(20);                           //  pushing 3 values to the front of v1.
    v1.pushFront(25);

    v1.pushRear(18);
    v1.pushRear(20);                            // pushing 3 values to the rear of v1.
    v1.pushRear(25);

    v1.print(outfile);                                 //  printing v1.
    // [25, 20, 18, 18, 20, 25]

    
    int A[] = {11,25,33,47,51};                 //  declaring an array of size 5 for a list-based vector.
    listVector v2(A,5);                         //  creating a list-based vector using the parametized constructor for an array named v2.
    v2.print(outfile);                                 //  printing v2
    // [11, 25, 33, 47, 51]

    v2.pushFront(9);
    v2.inOrderPush(27);                         //  pushing 3 values onto v2 using numerous push functions inside the class.
    v2.pushRear(63);
    
    v2.print(outfile);                                 //  printing v2 after the values have been pushed.
    // [9, 11, 25, 33, 47, 51, 63]

    v1.pushRear(v2);                            //  pushing v2 to the rear of v1
    v1.print(outfile);
    // [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

    x = v1.popFront();
    x = v1.popFront();                          //  popping 3 front values off of v1.
    x = v1.popFront();
    
    v1.print(outfile);                          //  printing v1.
    // [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]

    cout<<x<<endl;
    outfile << x << endl;                       //  printing the last "front" value in v1.
    // 18

    x = v1.popRear();
    x = v1.popRear();                           //  popping 3 values off the rear of v1.
    x = v1.popRear();
    
    v1.print(outfile);                          //  printing v1.
    // [18, 20, 25, 9, 11, 25, 27, 33]

    cout<<x<<endl;
    outfile << x << endl;                       //  printing the last "rear" value of v1.
    // 47

    x = v2.popAt(3);                            //  popping the value at index 3 in v2.
    v2.print(outfile);                          //  printing v2 after the value at index 3 has been popped off.
    // [9, 11, 25, 33, 47, 51, 63]

    cout<<x<<endl;
    outfile << x << endl;                       //  printing the value that was at index 3 in v2.
    // 27

    x = v2.find(51);                            //  finding and printing the index for the value 51 in v2.
    cout<<x<<endl;
    outfile << x << endl;
    // 5

    x = v2.find(99);                            //  finding and printing the index for the value 99 in v2.
    cout<<x<<endl;
    outfile << x << endl;
    // -1

    listVector v3(v1);                          //  creating v3 using the list-based vector constructor, using v1 as input, and printing out v3.
    v3.print(outfile);
    // [18, 20, 25, 9, 11, 25, 27, 33]

    v3.pushFront(v2);                           //  pushing the list-based vector v2 to the front of v3, and printing out the combined result.
    v3.print(outfile);
    //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

    listVector v4(infile);                      //  using the "test.dat" for the input for creating the list-based vector v4.
    v4.pushRear(v3);                            //  pushing v3 to the rear of v4 and printing out the combination.
    v4.print(outfile);
    // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]
}

/**
     * Public : listVector
     * 
     * Description:
     *      This function creates an instance of the listVector class and initializes it to null.
     * 
     * Params:
     *      - N/A
     * 
     * Returns:
     *      - N/A
     */
listVector::listVector()
{
    front = rear = nullptr;                     //  setting both front & rear to null.
}

/**
     * Public : listVector
     * 
     * Description:
     *      This creates an instance of the listVector class using an array as the input.
     * 
     * Params:
     *      - const int []
     *      - const int 
     * 
     * Returns:
     *      - N/A
     */
listVector::listVector(const int arr[], const int& size)
{
    front = rear = nullptr;                     //  setting front & rear to null

    for(int i = 0; i < size; i++)               //  traverse the array.
    {
        if(!front && !rear)                     //  if front & rear are null, push the value to the front.
        {
            pushFront(arr[i]);
        }
        else
        {
            pushRear(arr[i]);                   //  if front and rear are not null, push to the rear.
        }
    }
}

/**
     * Public : listVector
     * 
     * Description:
     *      This creates an instance of the listVector class using an input file as input.
     *  
     * Params:
     *      - input file ("test.dat")
     * 
     * Returns:
     *      - N/A
     */
listVector::listVector(ifstream &infile)
{
    front = rear = nullptr;                     //  setting front and rear to null.
    int value = 0;
    while(!infile.eof())                        //  while infile is not at the end.
    {
        infile >> value;                        //  read in value in from the infile.
        if(!front && !rear)
        {
            pushFront(value);                   //  if front & rear are null, push to the front.
        }
        else
        {
            pushRear(value);                    //  otherwise push to the rear.
        }
    }
}

/**
     * Public : listVector
     * 
     * Description:
     *      This creates an instance of the listVector class using another listVector as input.
     * 
     * Params:
     *      - listVector
     * 
     * Returns:
     *      - N/A
     */
listVector::listVector(listVector &other)
{
    front = rear = nullptr;                     //  setting front and rear to null.
    Node* travel = other.front;                 //  setting travel to the front of the other listVector.

    if(!front && !rear)
        {
            pushFront(travel->element);         //  if front and rear are null, push first element in other listVector to front of current.
            travel = travel->next;              //  traverse other listVector.
        }
    
    while(travel)                               //  while travel is not null, push element to the rear of current listVect and traverse.
    {
        pushRear(travel->element);
        travel = travel->next;
    }
}

/**
     * Public : pushFront
     * 
     * Description:
     *      This pushes an int value to the front of the listVector.
     * 
     * Params:
     *      - const int
     * 
     * Returns:
     *      - N/A
     */
void listVector::pushFront(const int &value)
{
    Node* temp = new Node(value);               //  creating a new Node for the value.
    temp->next = front;                         //  adding new Node before front, and setting front equal to the new Node.
    front = temp;
}

/**
     * Public : pushFront
     * 
     * Description:
     *      This pushes a listVector to the front of the current listVector.
     * 
     * Params:
     *      - listVector
     * 
     * Returns:
     *      - N/A
     */
void listVector::pushFront(listVector &other)
{
    Node* travel = other.front;                 //  creating travel that is equal to the front of the other listVect.
    int index = 0;
    while(travel)                               //  while travel is not null, enter and traverse.
    {
       int tempVal = travel->element;
       pushAt(index, tempVal);                  //  push the value of the other listVect at the index declared at the top.
       travel = travel->next;
       index++;                                 //  increase the index to keep the order of the pushed elements.
    }
}

/**
     * Public : pushRear
     * 
     * Description:
     *      This adds a single int value to the rear/end of the listVector.
     * 
     * Params:
     *      - const int
     * 
     * Returns:
     *      - N/A
     */
void listVector::pushRear(const int &value)
{
    Node* temp = new Node(value);               //  create new Nodes for new value and travel.
    Node* travel = front;
    if(front == NULL)
    {
        front = temp;                           //  if front is null, then rear must be null, so push new Node to the front.
        rear = temp;
    }
    while(travel->next != NULL)
    {
        travel = travel->next;                  //  traverse until the end of the listVect is found.
    }
    travel->next = temp;                        //  add new node to the end of the listVect and update rear.
    rear = temp;
}

/**
     * Public : pushRear
     * 
     * Description:
     *      This adds an entire listVector to the rear/end of the current listVector.
     * 
     * Params:
     *      - listVector
     * 
     * Returns:
     *      - N/A
     */
void listVector::pushRear(listVector &other)
{
    Node* travel = other.front;                 //  create new node travel equal to the other listVect's front.
    while(travel)
    {
       pushRear(travel->element);               //  while travel is not null, add other listVect element to the rear of current listVect.
       travel = travel->next;                   //  traverse other listVect.
    }
}

/**
     * Public : pushAt
     * 
     * Description:
     *      This pushes/adds a single int value at a specific index.
     * 
     * Params:
     *      - const int
     *      - const int
     * 
     * Returns:
     *      - N/A
     */
void listVector::pushAt(const int &location, const int &value)
{
    Node* temp = new Node(value);
    Node* previous = front;                     //  creating new nodes for the value and traveling.
    Node* travel = front;

    if(location == 0)                           
    {
        temp->next = front;
        front = temp;                           //  if pushing at front, add node to the front, and break out.
        return;
    }  
    if(location != 0)
    {
        for(int i = 0; i < location; i++)       //  traversing listVect until appropriate index is reached.
        {
       
            if(travel == NULL)
            {
                cout << "unable to access location " << location << endl;           //  check if index exists, if not, break out.
                return;
            }
            else                                //  else, continue traversing listVect.
            {
                previous = travel;
                travel = travel->next;
            }
        }
    } 
    
    if(previous == rear)                        //  if wanting to push rear, add node to the rear, update rear.
    {
        temp->next = travel;
        previous->next = temp;
        rear = temp;
    }
    temp->next = travel;                        // if not front or rear, update value at specified index.
    previous->next = temp;
}

/**
     * Public : inOrderPush
     * 
     * Description:
     *      This functions sorts the entire listVector and pushes/adds an int value in the appropriate order.
     * 
     * Params:
     *      - const int
     * 
     * Returns:
     *      - N/A
     */       
void listVector::inOrderPush(const int &value)
{
    sort();                                     //  sorting the listVect.
    Node* t1 = front;
    int key = value;                            //  intitializing values.
    int count = 0;

    while(t1)                                   //  while t1 is not null, enter
    {
        if(key > t1->element)                   
        {
            t1 = t1->next;                      //  if the key is greater, keep traversing.
            count++;
        }
        else if(key < t1->element)
        {
            pushAt(count, value);               //  if the key is less than, push the value at that index.
            break;
        }
        else if(key == t1->element)
        {
            pushAt(count, value);               //  if the key is equal, push the value at that index.
            break;
        }
    }

    if(t1 == NULL)
    {
        pushRear(value);                        //  if t1 reaches the end of the listVect, push the value to the rear of the listVect.
    }
}

/**
     * Public : popFront
     * 
     * Description:
     *      This returns the value being stored in the front of the listVector.
     * 
     * Params:
     *      - N/A
     * 
     * Returns:
     *      - int : the first value in the listVector.
     */
int listVector::popFront()
{
    if(!front && !rear)                         //  if front and rear are equal to null, return the front element.
    {
        return front->element;
    }
    int tempVal = front->element;
    Node* temp = front;                         //  else pop the front element and update front
    front = front->next;
    return tempVal;
}

/**
     * Public : popRear
     * 
     * Description:
     *      This traverses the listVector to the rear and returns the value being stored at the end/rear.
     * 
     * Params:
     *      - N/A
     * 
     * Returns:
     *      - int : The last value in the listVector.
     */
int listVector::popRear()
{
    Node* travel = front;
    while(travel->next->next != NULL)           //  traversing listVect until the next 2 value is not null.
    {
        travel = travel->next;  
    }
    rear = travel->next;
    travel->next = NULL;                        //  getting value at the rear and updating rear.
    int tempVal = rear->element;
    rear = travel;
    return tempVal;                             //  returning rear value.

}

/**
     * Public : popAt
     * 
     * Description:
     *      This function traverses the listVector to a specific index and pops/removes the value at that location.
     * 
     * Params:
     *      - const int
     * 
     * Returns:
     *      - int : The value at the specific index.
     */       
int listVector::popAt(const int &location)
{
    Node* previous = front;                     //  creating traveling nodes.
    Node* travel = front;

    if(location == 0)                           //  if location is equal to the front, return value at front.
    {
        return popFront();
    }

    if(location != 0)                           //  if location is not equal to front, traverse and find index
    {
        for(int i = 0; i < location; i++)
        {
       
            if(travel->next == NULL)            //  check is index exists.
            {
                return -1;
            }
            else
            {
                previous = travel;              //  continue traversing listVect
                travel = travel->next;
            }
        }
    } 

    if(previous == rear)        
    {
        int tempVal = popRear();
        previous = rear;                        //  if the index is equal to rear, return rear and udpate rear ptr.
        return tempVal;
    }
    
    previous->next = travel->next;
    return travel->element;                     //  if not rear or front, return value at specific index, update previous and next nodes.
    delete travel;

}

/**
     * Public : find
     * 
     * Description:
     *      This function traverses the listVector, searches for a specific value, and returns the index of that value.
     * 
     * Params:
     *      - const int
     * 
     * Returns:
     *      - int : The index of a specific value.
     */        
int listVector::find(const int &value)
{
    Node* travel = front;
    int key = value;                            //  variable creation, node to travel, value to find and index.
    int indexCount = 0;
    while(travel)                               //  while travel is not null
    {
        if(travel->element == key)
        {
            return indexCount;                  //  if the element at travel is equal the key, return the index.
        }
        else
        {
            indexCount++;                       //  else continue traveling and increment index.
            travel = travel->next;
        }
    }
    return -1;                                  //  if value not found, return -1 for not in listVect
}

/**
     * Public : print
     * 
     * Description:
     *      This function prints the listVector to the console and an outfile.
     * 
     * Params:
     *      - output file ("test.out")
     * 
     * Returns:
     *      - N/A
     */
void listVector::print(ofstream &outfile)
{
    Node* travel = front;                       //  create traveling node.
    cout << '[';
    outfile << '[';
    while(travel){                              //  while travel is not equal to node
      cout<<travel->element;
      outfile << travel->element;               //  print out the element at the index.
      if(travel->next){
        cout<<", ";
        outfile << ", ";                        //  formatting
      }
      travel = travel->next;                    //  continue traversing
    }
    cout << ']';
    outfile << ']';
    cout<<endl;                                 //  formatting
    outfile << endl;
}

/**
     * Public : sort
     * 
     * Description:
     *      This function traverses the array and sorts the elements using a bubble sort method.
     * 
     * Params:
     *      - N/A
     * 
     * Returns:
     *      - N/A
     */
void listVector::sort()                         // code from stackOverflow
{
    Node* travel1 = front;                      //  create traveling nodes
    Node* travel2 = front;

    for(int i = 0; i < size(); i++)             
    {
        for(int j = 0; j < size(); j++)
        {
            if(travel1->element < travel2->element)             //  compare the traveling nodes elements
            {
                int tempVal = travel1->element;
                travel1->element = travel2->element;            //  if leading travel is less, switch the values
                travel2->element = tempVal;
            }
            travel2 = travel2->next;                            //  update traveling nodes
        }
        travel2 = front;
        travel1 = front->next;
        for(int k = 0; k < i; k++)                              //  prevents travel nodes from traversing the whole listVect everytime.
            travel1 = travel1->next;
    }
}

/**
     * Public : size
     * 
     * Description:
     *      This function traverses the listVector and increments a count variable every traversal.
     * 
     * Params:
     *      - N/A
     * 
     * Returns:
     *      - int : The total size of the listVector.
     */
int listVector::size()
{
    Node* travel = front;                           //  creating traveling node
    int count = 0;
    while(travel)                                   //  while travel is not null
    {
        count++;
        travel = travel->next;                      // increment count and update travel
    }
    return count;                                   //  return the total number of indexes
}

/**
     * Public : printHeading
     * 
     * Description:
     *      This function prints the heading to the outfile.
     * Params:
     *      - outfile
     * 
     * Returns:
     *      - N/A
     */
void printHeading(ofstream &outfile)
{
    outfile << "Ethan Saenz\n";
    outfile << "02 / 04 / 2024\n";                  //  outfiles heading to the test.out file
    outfile << "Spring 3013\n\n";
}
