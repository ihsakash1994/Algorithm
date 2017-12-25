#include<iostream>
#include<cstdio>

#define maxn 112345
using namespace std;

int ah[maxn];
void printAh(int h)
{
    for (int i = 0; i <= h; i++)
    {
        cout << ah[i] << " ";
    }

    cout << endl;
}

int takeInput()
{
    int h;
    cin >> h;
    for(int i = 0; i <= h; i++)
    {
        cin >> ah[i];
    }

    return h;
}

int findAmbiguousStructure(int heightOfTree)
{
    for(int i = 1; i <= heightOfTree; i++)
    {
        if (ah[i] > 1 && ah[i-1] > 1)
        {
            return i;
        }
    }
    return -1;
}

void printTree(int heightOfTree, int ambiguousStructure)
{
    //printAh(heightOfTree);
    //cout << ambiguousStructure << " : Height\n";
    //cout << heightOfTree << " : Height\n";
    int parent = 0;
    for (int i = 0; i <= heightOfTree; i++)
    {
        for (int j = 0; j < ah[i]; j++)
        {
            if (ambiguousStructure == i && j == 0)
            {
                cout << parent-1 << " ";
            }
            else
            {
                cout << parent << " ";
            }
        }

        parent += ah[i];
    }

    cout << endl;
}

int main()
{
    int heightOfTree = takeInput();
    //printAh(heightOfTree);
    int ambiguousStructure = findAmbiguousStructure(heightOfTree);

    //printAh(heightOfTree);
    if (ambiguousStructure == -1)
    {
        cout << "perfect" << endl;
    }
    else
    {
        cout << "ambiguous" << endl;
        printTree(heightOfTree, -1);
        printTree(heightOfTree, ambiguousStructure);
    }
}
