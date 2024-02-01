// will make it a header file later

//
class StackusingArray
{
private:
    int *data;
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
        if (nextindex == 0)
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
        if (nextindex == capacity)
        {
            int *newdata = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newdata[i] = data[i];
            }
            capacity = 2 * capacity;
            delete[] data;
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
        return data[nextindex - 1];
    }

    // merge sort
    private :

    void merge(int *arr,int si,int mid,int ei)
    {
         int n1=mid - si + 1;//size of the first array
    int n2 = ei - mid;
    
    int left[n1];
    int right[n2];
    
    
    for(int i=0;i<n1;i++)
    {
        left[i] = arr[si+i];
    }
    for(int j=0;j<n2;j++)
    {
        right[j] = arr[mid+1+j];
    }
    
    
    int i=0,j=0,k=si;
    while(i<n1 && j<n2)
    {
        if(left[i]<right[j])
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        arr[k] = left[i];
            i++;
            k++;
        
    }
    while(j<n2)
    {
        arr[k] = right[j];
            j++;
            k++;
    }
    }
    
    void mergesort(int *data, int si, int ei)
    {
        if (si < ei)
        {
            int mid = (si + ei) / 2;
            mergesort(data, si, mid);
            mergesort(data, mid + 1, ei);
            merge(data, si, mid, ei);
        }
    }

public :

    void mergeSort(int *data, int size)
    {
        int si = 0;
        int ei = size - 1;
        mergesort(data, si, ei);
    }
};