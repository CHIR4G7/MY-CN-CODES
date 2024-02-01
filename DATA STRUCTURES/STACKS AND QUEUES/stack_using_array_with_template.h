// will make it a header file later

template <typename T>

class StackusingArray
{
private:
    T *data;
    int nextindex;
    int capacity;

public:
    // constructor
    StackusingArray()
    {
        data = new int[capacity];
        nextindex = 0;
        capacity = 5; // will create a dynamic array which will increase its size whenever needed
    }

    int size()
    {
        return nextindex;
    }
    bool isEmpty()
    {
        if(nextindex==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int element)
    {
        if(nextindex==capacity)
        {
            T *newdata = new T[2 * capacity];
            for(int i=0;i<capacity;i++)
            {
                newdata[i] = data[i];
            }
            capacity = 2 * capacity;
            delete []data;
            data = newdata;
        }
        data[nextindex] = element;
        nextindex++;
    }
    void pop()
    {
        nextindex--;
        
    }
    int top()
    {
        return data[nextindex-1];
    }
};