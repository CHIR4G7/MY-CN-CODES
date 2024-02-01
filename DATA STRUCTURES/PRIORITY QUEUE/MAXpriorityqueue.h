#include <vector>
#include <iostream>

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

    int getSize()
    {
        return pq.size();
    }

    int getMax()
    {
        if (pq.size() == 0)
        {
            return 0;
        }
        else
        {
            return pq[0];
        }
    }

    void insert(int element)
    {
        pq.push_back(element);
        int childindex = (pq.size() - 1);

        while (childindex > 0)
        {
            int parentindex = ((childindex - 1) / 2);
            if (pq[childindex] > pq[parentindex])
            {
                int temp = pq[childindex];
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

    int removeMax()
    {
        if (pq.size() == 0)
        {
            return INT32_MIN;
        }

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentindex = 0;
        int lcindex = (2 * (parentindex) + 1);
        int rcindex = (2 * (parentindex) + 2);

        while (parentindex < pq.size())
        {
            int maxindex = parentindex;
            if (pq[maxindex] < pq[lcindex])
            {
                maxindex = lcindex;
            }
            if (rcindex < pq.size() && pq[maxindex] < pq[rcindex])
            {
                maxindex = rcindex;
            }
            if (maxindex == parentindex)
            {
                break;
            }
            int temp = pq[maxindex];
            pq[maxindex] = pq[parentindex];
            pq[parentindex] = temp;

            parentindex = maxindex;
            lcindex = (2 * (parentindex) + 1);
            rcindex = (2 * (parentindex) + 2);
        }
        return ans;
    }
};