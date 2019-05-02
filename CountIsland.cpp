vector<pair<int, int>> directions; 
void dfs(vector<vector<char>> &matrix, vector<vector<bool>> &isVisited, int ix, int jx)
{
    int row = matrix.size(), col = matrix[0].size(); 
    for (int i = 0; i < directions.size(); i++)
    {
        int x = ix + directions[i].first, y = jx + directions[i].second;
        if (x >= 0 && x < row && y >= 0 && y < col)
        {
            if (matrix[x][y] == '#' && !isVisited[x][y])
            {
                isVisited[x][y] = true;
                dfs(matrix, isVisited, x, y);
            }
        }
    }
}

int CountIsland(vector<vector<char>> &matrix)
{
    if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
    
    int row = matrix.size(), col = matrix[0].size();
    vector<vector<bool>> isVisited(row, vector<bool>(col, false));
    
    directions.clear();
    directions.push_back(make_pair(1, 0));
    directions.push_back(make_pair(-1, 0));
    directions.push_back(make_pair(0, 1));
    directions.push_back(make_pair(0, -1));
    
    int islandCount = 0;
    for (int i  = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == '#' && !isVisited[i][j])
            {
                islandCount++;
                isVisited[i][j] = true;
                dfs(matrix, isVisited, i, j);
            }
        }
    }
    
    return islandCount;
}
