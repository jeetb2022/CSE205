#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class LifeGrid
{
public:
    vector<vector<int>> v;
    vector<pair<int, int>> liveCells;
    int nrows, ncols;
    LifeGrid(int nrows, int ncols)
    {
        this->nrows = nrows;
        this->ncols = ncols;
    }

    // Member Functions()
    int numRows()
    {
        int ans;
        ans = v.size();
        return ans;
    }
    int numCols()
    {
        int ans;
        ans = v[0].size();
        return ans;
    }

    void configure(vector<pair<int, int>> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            liveCells.push_back(v[i]);
        }
    }

    void clearCell(int row, int col)
    {
        for (int i = 0; i < liveCells.size(); i++)
        {
            if (liveCells[i].first == row && liveCells[i].second == col)
            {
                auto it = liveCells.begin() + i;
                liveCells.erase(it);
            }
        }
    }

    void setCell(int row, int col)
    {
        liveCells.push_back({row, col});
    }

    bool isLiveCell(int row, int col)
    {
        int flag = 0;
        for (int i = 0; i < liveCells.size(); i++)
        {
            if (liveCells[i].first == row && liveCells[i].second == col)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display()
    {
        for (int i = 0; i < nrows; i++)
        {
            for (int j = 0; j < ncols; j++)
            {
                int flag = 0;
                for (int k = 0; k < liveCells.size(); k++)
                {

                    if (i == liveCells[k].first && j == liveCells[k].second)
                    {
                        cout << 1 << " ";
                        flag = 1;
                    }
                }
                if (flag == 0)
                {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }

    int numLiveNeighbors(int row, int col)
    {
        int ct = 0;
        for (int j = col - 1; j < col + 2; j++)
        {
            for (int k = row - 1; k < row + 2; k++)
            {
                for (int i = 0; i < liveCells.size(); i++)
                {
                    if ((liveCells[i].first == k && liveCells[i].second == j) && (k != row || j != col))
                    {
                        ct++;
                    }
                }
            }
        }
        return ct;
    }
};

int main()
{
    LifeGrid a(5, 5);
    a.setCell(2, 3);
    a.configure({{1, 3}, {4, 4}, {2, 4}});
    a.display();
    a.setCell(4, 4);
    a.setCell(1, 1);
    a.setCell(1, 4);
    cout << endl;
    a.clearCell(1, 4);
    int liveNeighbours = a.numLiveNeighbors(3, 3);
    cout << "The number of live neighbours is : " << liveNeighbours << endl;

    return 0;
}