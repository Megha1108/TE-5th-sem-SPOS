#include <bits/stdc++.h>
using namespace std;
class synchronization
{
    int a[5];
    int mutex = 1;
    int empty = 5;
    int full = 0;
    void wait(int &x)
    {
        if (x > 0)
            x--;
    }
    void signal(int &x)
    {
        x++;
    }

public:
    void producer()
    {
        cout << "Empty: " << empty << " Full: " << full << " Mutex: " << mutex << endl;
        if (empty != 0 && mutex == 1)
        {
            cout << "Data to be produced: ";
            wait(empty);
            wait(mutex);
            cin >> a[full];
            cout << "Data produced is: " << a[full] << endl;
            signal(mutex);
            signal(full);
        }
    }
    void consumer()
    {
        cout << "Empty: " << empty << " Full: " << full << " Mutex: " << mutex << endl;
        if (full != 0 && mutex == 1)
        {
            wait(full);
            wait(mutex);
            cout << "Data consumed is: " << a[full] << endl;
            signal(mutex);
            signal(empty);
        }
    }
};
int main()
{
    int fchoice;
    synchronization s;
    do
    {
        cout << "-----------MENU----------" << endl;
        cout << "1.Producer\n2.Consumer\n3.Exit" << endl;
        cout << "Enter the choice" << endl;
        cin >> fchoice;
        switch (fchoice)
        {
        case 1:
            s.producer();
            break;
        case 2:
            s.consumer();
            break;
        case 3:
            break;
        default:
            break;
        }
    } while (fchoice != 3);
    return 0;
}