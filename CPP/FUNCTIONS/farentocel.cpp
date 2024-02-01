#include <iostream>
using namespace std;

void printTable(int start, int end, int step) {
  
    
    int farenhiet = start;
    int celsius;
    while(farenhiet<=(end))
    {
        celsius = 5.0/9 * (farenhiet - 32);
        cout << farenhiet << " " << celsius << endl;
        farenhiet = farenhiet + step;
        
    }
    
}
 
int main()
{
     int start, end, step;
    cin >> start >> end >> step;
  
    printTable(start, end, step);
}