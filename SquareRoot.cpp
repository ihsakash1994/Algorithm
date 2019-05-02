void search(int i, int j, int x, int &ans)
{
    if (i > j) return;
    if (i == j) 
    {
        ans = i;
        return;
    }
    
    int mid = (i + j) / 2;
    int temp = mid * mid;
    
    if (temp == x) 
    {
        ans = mid;
        return;
    }
    
    if (temp > x) 
    {
        search(i, mid - 1, x, ans);  
        return; 
    }
    
    ans = mid;
    search(mid + 1, j, x, ans);
}

int FindSqrt(int x)
{
    int ans = x;
    search(1, x, x, ans);
    
    return ans;
}
