// MY OWN MAP IMPLEMENTATION
#include <string>
using namespace std;
template <typename V> // for the value

class MapNode // for the linked list.
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
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

template <typename V> // for the value

class ourMap
{
    MapNode<V> **buckets;
    int size;       // size of bucket.
    int numBuckets; // size of the array.

private:
    int getbucketindex(string key)
    {
        // hashcode
        int hashcode = 0;
        int currentCoffecient = 1; // p raied to the power 0.
        for (int i = key.length() - 1; i >= 0; i++)
        {
            hashcode += key[i] * currentCoffecient;
            hashcode = hashcode % numBuckets;
            currentCoffecient *= 37; // choosing 37 as the prime function.(totally your choice).
            /*
            power of the modulus function-

            (a*b*c) % r = ( (a%r) * (b%r) * (c%r) ) % r;
            */

            // to keep the currentcofficient in the range.
            currentCoffecient = currentCoffecient % numBuckets;
        }

        // compression
        return hashcode % numBuckets;
    }

    void rehash()
    {
        MapNode<V> **temp = buckets;                // storing the previous bucket array in temp
        buckets = new MapNode<V> *[2 * numBuckets]; // now creating a new bucket array of double size.

        // removing all the garbage from the new buckets array.
        for (int i = 0; i < (2 * numBuckets); i++)
        {
            buckets[i] = NULL;
        }

        // now storing the size of preious bucket array, for traversal.
        int oldbucketcount = numBuckets;
        // new num buckets array in created of double size.
        numBuckets *= 2;
        size = 0;

        // every node of the previous cuckets array, if it is link of the linked list also, then we copy it to the new array.
        for (int i = 0; i < oldbucketcount; i++)
        {
            MapNode<V> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }

        // deleting the temp array...
        for (int i = 0; i < oldbucketcount; i++)
        {
            MapNode<V> *head = temp[i];
        }
        delete[] temp;
    }

public:

    ourMap()
    {
        size = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];

        // clearing garbage adresses
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~ourMap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }

 

    int getSize()
    {
        return size;
    }

    void insert(string key, V value)
    {
        // first thing we have to get the hucket index.
        int bucketIndex = getbucketindex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head-> value = value;
                return;
            }

            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        size++;
        double loadfactor = ((1.0) * size) / numBuckets;
        if (loadfactor > 0.7)
        {
            rehash();
        }
    }

    V getValue(string key)
    {
        int bucketIndex = getbucketindex(key);
        MapNode<V> **head = buckets[bucketIndex];

        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    V remove(string key)
    {
        int bucketIndex = getbucketindex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;

        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                size--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }

    double getLoadFactor()
    {
        return (1.0 * size) / numBuckets;
    }

};