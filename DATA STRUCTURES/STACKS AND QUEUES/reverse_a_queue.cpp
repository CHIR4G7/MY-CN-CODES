#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &input) {
	// Write your code here
    //storing elements in stack
    stack<int> s;
    while(input.size()!=0)
    {
        int i = input.front();
        s.push(i);
        input.pop();

    }
    //again then putting them back in queue
    while(s.size()!=0)
    {
        int i = s.top();
        input.push(i);
        s.pop();
    }
    //printing the queue
    while(input.size()!=0)
    {
        cout << input.front() << " ";
        input.pop();

    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}