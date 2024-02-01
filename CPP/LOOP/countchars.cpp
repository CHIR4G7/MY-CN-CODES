
#include <iostream>
using namespace std;
 
int main()
{
    char c;
    c = cin.get();
    
    int c_num = 0;
    int c_char = 0;
    int c_space = 0;

    while(c!='$')
    {

          if('a'<=c && c<='z')
          {
              c_char++;
          }
          else if('0'<=c && c<='9')
          {
              c_num++;
          }
          else
          {
              c_space++;
          }
		
          c = cin.get();
    }
    cout << c_char << " " << c_num << " " << c_space;
}