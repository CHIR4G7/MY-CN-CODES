#include <iostream>
#include <string>
using namespace std;
template <typename V>

class MapNode
{
    public :

    string key;
    V value;
    MapNode *next;

    MapNode(string key,V value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

template <typename V>

class OurMap
{
    MapNode<V> **buckets;
    int size;
    int numBuckets;

    public :

    OurMap()
    {
        size = 0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];

        for(int i=0;i<numBuckets;i++)
        {
            buckets[i] = NULL;
        }
    }

    ~OurMap()
    {
        for(int i=0;i<numBuckets;i++)
        {
            delete buckets[i];
        }
        delete []buckets;
    }

    int getsize()
    {
        return size;
    }

    private :

    int getbucketindex(string key)
    {
        //hashcode
        int hashcode = 0;
        int currentcoefficient = 1;
        for(int i=key.length()-1;i>=0;i--)
        {
            hashcode+=(key[i]*currentcoefficient);
            hashcode = hashcode%numBuckets;

            currentcoefficient*=37;
            currentcoefficient = currentcoefficient%numBuckets;//to keep it in interger range and array size raange
        }

        return hashcode % numBuckets;//compression ke baad
    }

    //rehashing function

    void rehash()
    {
        MapNode<V> **temp = buckets;
        buckets = new MapNode<V>*[2*numBuckets];
        int oldbucketcount = numBuckets;
        numBuckets*=2;

        for(int i=0;i<numBuckets;i++)
        {
            buckets[i] = NULL;
        }
        size=0;
        for(int i=0;i<oldbucketcount;i++)
        {
            MapNode<V> *head = temp[i];
            while(head!=NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key,value);
                head = head->next;
            }
        }

        for(int i=0;i<oldbucketcount;i++)
        {
            delete temp[i];
        }
        delete [] temp;
    }

    public :

    void insert(string key,V value)
    {
        int bucketIndex = getbucketindex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while(head!=NULL)
        {
            if(head->key==key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }

        head = buckets[bucketIndex];
        MapNode<V> *newnode = new MapNode<V>(key,value);
        newnode->next = head;
        buckets[bucketIndex] = newnode;
        size++;

        //chck loaad factor
        double LoadFactor = (1.0*(count)) / numBuckets;
        if(LoadFactor>0.7)
        {
            //rehashing
            rehash();i
        }
    }

    V getValue(string key)
    {
        int bucketindex = getbucketindex(key);
        MapNode<V> *head = buckets[bucketindex];

        while(head!=NULL)
        {
            if(head->key==key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    V remove(string key)
    {
        int bucketindex = getbucketindex(key);
        MapNode<V> *head = buckets[bucketindex];
        MapNode<V> *prev = NULL;

        while(head!=NULL)
        {
            if(head->key==key)
            {
                if(prev==NULL)
                {
                    buckets[bucketindex] = head->next;
                }
                else
                {h
                prev->next = head->next;
                }
                V val = head->value;
                head->next = NULL;
                size--;
                delete head;
                return val;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};