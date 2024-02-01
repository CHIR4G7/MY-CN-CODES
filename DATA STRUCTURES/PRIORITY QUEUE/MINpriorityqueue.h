#include <iostream>
#include <vector>
template <typename T>

class PriorityQueue
{
    std::vector<int> pq;

public:
    PriorityQueue()
    {
    }

    bool isEmpty()
    {
        if (pq.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // return number of elements present in priority queuq
    int getsize()
    {
        return pq.size();
    }

    // getmin

    int getMin()
    {
        if (pq.size() != 0)
        {
            return pq[0];
        }
        else
        {
            return 0; // representing that priority queue is empty
        }
    }

    // insert

    void insert(int element)
    {
        pq.push_back(element);
        int childindex = (pq.size() - 1);

        while (childindex > 0)
        {
            int parentindex = ((childindex - 1) / 2);

            if (pq[childindex] < pq[parentindex])
            {
                T temp = pq[childindex];
                pq[childindex] = pq[parentindex];
                pq[parentindex] = temp;
            }
            else
            {
                break;
            }
            childindex = parentindex;
        }
    }

    int removeMin()
    {
        if (pq.size() == 0 )
        {
            return 0;
        }

        int ans = pq[0];

        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        // down heap
        int parentindex = 0;
        int lcindex = (2 * (parentindex) + 1);
        int rcindex = (2 * (parentindex) + 2);

        while (parentindex < pq.size())
        {
            int minindex = parentindex;
            if (pq[minindex] > pq[lcindex])
            {
                minindex = lcindex;
            }

            if (rcindex<pq.size() && pq[rcindex] < pq[minindex])
            {
                minindex = rcindex;
            }

            if(minindex==parentindex)
            {
                break;
            }
            int temp = pq[minindex];
            pq[minindex] = pq[parentindex];
            pq[parentindex] = temp;

            parentindex = minindex;
            int lcindex = (2 * (parentindex) + 1);
            int rcindex = (2 * (parentindex) + 2);
        }
        return ans;
    }
};