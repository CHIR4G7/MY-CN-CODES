class Deque
{
    private :
    int *deq;
    int front;
    int rear;
    int size;

    public :

    Deque(int size)
    {
        deq = new int[size];
        front = -1;
        rear = -1;
        this->size = size;
    }

    void insertFront(int ele)
    {
        if(front==-1 && rear==-1)
        {
            front=0;
            rear = 0;
            deq[front] = ele;
            return;
        }
        if((front+1) % size == rear)
        {
            cout << "-1" << endl;
            return;
        }
        front = (front+1) % size;
        deq[front] = ele;
    }

    void insertRear(int ele)
    {
        if(front==-1 && rear==-1)
        {
            front = 0;
            rear = 0;
            deq[rear] = ele;
            return;
        }

        if(front == rear - 1 || rear ==0 && front == si-1)
        {
            cout << -1
        }
    }

};