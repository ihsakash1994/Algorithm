int BSearchFirst(vector<int> &a, int x, int i, int j)
{
    if (i > j) return -1;
    if (i == j)
    {
        if (a[i] == x) return i;
        else return -1;
    }
    
    int mid = (i + j) / 2;
    if (a[mid] == x && (mid == 0 || a[mid-1] != x))return mid;
    if (a[mid] < x) return BSearchFirst(a, x, mid+1, j);
    
    return BSearchFirst(a, x, i, mid-1);
}

int BSearchLast(vector<int> &a, int x, int i, int j)
{
    if (i > j) return -1;
    if (i == j)
    {
        if (a[i] == x) return i;
        else return -1;
    }
    
    int mid = (i + j) / 2;
    if (a[mid] == x && (mid == a.size() - 1 || a[mid + 1] != x)) return mid;
    if (a[mid] > x) return BSearchLast(a, x, i, mid-1);
    
    return BSearchLast(a, x, mid+1, j);
}

int CountFrequency(vector<int> &a, int x)
{
    int firstIx = BSearchFirst(a, x, 0, a.size() - 1);
    if (firstIx == -1) return 0;
    
    int lastIx = BSearchLast(a, x, 0, a.size() - 1);    
    return lastIx - firstIx + 1; 
}
