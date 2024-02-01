#include <iostream>
using namespace std;

int power(int x, int n)
{

    if (n == 0 || x == 1)
    {
        return 1;
    }
    int po = power(x, (n - 1));
    int output = x * po;
    return output;
}

void print(int n)
{
    // write your code here
    if (n == 1)
    {
        cout << 1 << " ";
        return;
    }
    print(n - 1);
    cout << n << " ";
}

int count(int n)
{
    // write your code here
    if (n == 0)
    {
        return 0;
    }
    return count(n / 10) + 1;
}

int sum(int input[], int n)
{

    if (n == 0)
        return 0;

    int total = input[0] + sum(input + 1, n - 1);
    return total;
}

bool checkNumber(int input[], int size, int x)
{

    if (size <= 0)
    {
        return false;
    }
    else
    {
        if (input[0] == x)
        {
            return true;
        }
        bool checksmaller = checkNumber(input + 1, size - 1, x);
        return checksmaller;
    }
}

// FIRST INDEX
int help(int input[], int size, int x, int i)
{

    if (size == 0)
        return -1;
    if (input[0] == x)
        return i;

    help(input + 1, size - 1, x, i + 1);
}

int firstIndex(int input[], int size, int x)
{
    /* Don't write main().
       Don't read input, it is passed as function argument.
       Return output and don't print it.
       Taking input and printing output is handled automatically.
    */
    int i = 0;
    int ans = help(input, size, x, i);
    return ans;
}

// LAST INDEX
int lastIndex(int input[], int size, int x)
{

    if (size == 0)
        return -1;

    if (input[size - 1] == x)
        return size - 1;

    return lastIndex(input, size - 1, x);
}

// ALL INDICES
int allIndexes(int input[], int size, int x, int output[])
{

    if (size == 0)
        return 0;
    int smallCount = allIndexes(input, size - 1, x, output);
    if (input[size - 1] == x)
    {
        output[smallCount] = size - 1;
        return smallCount + 1;
    }
    else
    {
        return smallCount;
    }
}


int multiplyNumbers(int m, int n) {
    // Write your code here
    if(n==0)
    {
        return 0;
    }
    return m + multiplyNumbers(m,n-1);

}

int countZeros(int n) {
    // Write your code here
          if (n <10)
        {
            if(n==0)
            {
                return 1;
            }
              return 0;
        }
        int rem = n % 10;
         if (rem == 0)

        {
            return countZeros(n / 10) + 1;
        }
        else
        {
            return countZeros(n/10);
        }
   

}


int main()
{
}