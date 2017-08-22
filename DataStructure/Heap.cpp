#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>

#define Max_Length_Arr 112345
#define ll long long

using namespace std;

// Global array stores and used across the solution.
// Keeping it global to prevent stack overflow.
ll arr[Max_Length_Arr];

class Heap
{
    public:
        int sizeOfArray = 0, height = 1;

        Heap (int len)
        {
            sizeOfArray = len;
            height = log2(len) + 1;
        }

        void FillArrRandomly()
        {
            for (int i = 1; i <= sizeOfArray; i++)
            {
                arr[i] = ((ll)41 * (ll)(i+1))%97;
            }
        }

        static power(ll x, ll y)
        {
            ll ans = 1;
            while (y)
            {
                if (y % 2 == 1)ans = ans * x;
                x = x * x;
                y = y / 2;
            }
            return ans;
        }

        void maxHeapify (int  headNode)
        {
            int leftChild = 2 * headNode;
            int rightChild = 2 * headNode + 1;
            int potentialHeadNode = headNode;

            if (leftChild <= sizeOfArray)
            {
                if (arr[leftChild] > arr[headNode])
                {
                    potentialHeadNode = leftChild;
                }
            }

            if (rightChild <= sizeOfArray)
            {
                if (arr[rightChild] > arr[potentialHeadNode])
                {
                    potentialHeadNode = rightChild;
                }
            }

            if (potentialHeadNode != headNode)
            {
                swap(arr[headNode], arr[potentialHeadNode]);
                maxHeapify(potentialHeadNode);
            }
        }

        void makeHeapFromArr()
        {
            for (int i = sizeOfArray/2; i >= 1; i--)
            {
                maxHeapify(i);
            }
        }

        void print(int ix)
        {
            int level = log2(ix);
            if (power(2, level) - 1 == ix)
            {
                cout << " " << arr[ix] << endl;
            }
            else if (power(2, level) == ix)
            {
                int numSpace = (2*power(2, height-1)) - (2*power(2, level) + 1);
                numSpace /= 2;
                while (numSpace--)cout << " ";
                cout << " " << arr[ix];
            }
            else
            {
                cout << " " << arr[ix] << " ";
            }
        }

        void printArr ()
        {
            queue<int> q;
            q.push(1);

            while (!q.empty())
            {
                int i = q.front();
                cout << arr[i] << " ";
                q.pop();
                if (2*i <= sizeOfArray)q.push(2*i);
                if (2*i+1 <= sizeOfArray)q.push(2*i + 1);

            }
        }

        void printArr2 ()
        {
           for (int i = 1; i <= sizeOfArray; i++)cout << arr[i] << " ";
           cout << endl;
        }
};


int main ()
{
    Heap obj(7);
    obj.FillArrRandomly();
    cout << obj.sizeOfArray << " " << obj.height << endl;
    obj.printArr();
    cout << endl;
    obj.printArr2();
    cout << endl;
    obj.makeHeapFromArr();
    obj.printArr();
    cout << endl;

//    while (1)
//    {
//        int x, y;
//        cin >> x >> y;
//        cout << obj.power(x, y) << endl;
//    }
}
