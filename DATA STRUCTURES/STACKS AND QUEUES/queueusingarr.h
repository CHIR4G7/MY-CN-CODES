class QueueusingArray
{
private:
    int nextIndex;
    int firstIndex;
    int *data;
    int size;
    int capacity;

public:
    QueueusingArray()
    {
        data = new int[size];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = 5;
    }

    int getsize()
    {
        return size;
    }

    bool empty()
    {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int element)
    {
        if (size == capacity)
        {
        }

        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        size++;
    }

    int front()
    {
        if (size = 0)
        {
            return -1;
        }
        else
        {
            return data[firstIndex];
        }
    }

    void dequeue()
    {
        if (size == 0)
        {
            return;
        }
        int ans = data[firstIndex];
        firstIndex = (firstIndex+1) % capacity;
        size--;
        if(size==0)
        {
            nextIndex = 0;
            firstIndex=-1;
        }
        
    }
};