using namespace std;

//creating struct for the nodes
struct Node
{
    int element;
    int *ptr;
};

//class initialization
class Vector
{
    private:
        //declaring private member variables
        int front, rear;
        Node node;
    public:
        //declaring constructors
        void Vector();
        void Vector(const int &f, const int &r);
        Vector Vector(const int &vect);

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