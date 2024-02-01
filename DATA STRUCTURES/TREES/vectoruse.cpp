#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
   //vector<int> *vp = new vector<int> ();//dynamically
    
    vector<int> v;//statically

    //inserting elements in a vector
    v.push_back(10);
    v.push_back(20);//10 ke peeche 20 add hoga
    v.push_back(30);

    // cout << v[0] << endl;//treat it like an array
    // cout << v[1] << endl;
    // cout << v[2] << endl;
    
    v[1] = 100;
    //cout << v[1] << endl;

    /*
    v[3] = 1002;
    v[4] = 1234;
    these should not be done
    */
   

    //when we use push back function it does check the space available in the array and then adds the element
    //but when we use v[i] = n; then it does not check wether space is available or not

    v.push_back(23);
    v.push_back(234);

     cout << v[0] << endl;//treat it like an array
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v[4] << endl;
    cout << v[5] << endl;
    cout << v[6] << endl; 

    //isme isne jo 2 elements maine square brackets se daale the unko nhi consider kiya , par pushback function ne jo elements bheje the uno consider kr liya
    /*
    
    we will use [ ] brackets only to get data and update data..not to insert data;
    */

   //size function
   cout << "size : " << v.size() << endl;

   cout << v.at(2) << endl;
   //cout << v.at(6) << endl;//will throw an error that storage not accessible
    
    //delete last element
    v.pop_back();

    //capacity function
    cout << v.capacity() << endl;

}