class Stackusingstring
{
    private :
    char *data;
    int nextindex;
    int capacity;

    public :

    Stackusingstring()
    {
        data = new char[5];
        nextindex = 0;
        capacity = 5;
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

    void push(char c)
    {
        if(nextindex==capacity)
        {
            char *newdata = new char[]
        }
    }
};