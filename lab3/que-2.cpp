#include <bits/stdc++.h>
using namespace std;

class Array2D
{
public:
    int row;
    int col;
    // const int N=3;
    vector<vector<int>> v;
    Array2D(int row, int col)
    {
        this->row = row;
        this->col = col;
    }

    int numRows()
    {
        return row;
    }
    int numCols()
    {
        return col;
    }

    void clear(int value)
    {
        for (int i = 0; i < row; i++)
        {
            vector<int> temp;
            for (int j = 0; j < col; j++)
            {
                temp.push_back(value);
            }
            v.push_back(temp);
        }
    }

    int getItem(int i1, int i2)
    {
        for (int k = 0; k < v.size(); k++)
        {
            if (v[k][0] == i1 && v[k][1] == i2)
            {
                return v[k][2];
            }
        }
        return 0;
    }

    void setItem(int i1, int i2, int value)
    {
        vector<int> temp;
        temp.push_back(i1);
        temp.push_back(i2);
        temp.push_back(value);
        v.push_back(temp);
    }

    void display()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int flag = 0;
                int ans;
                for (int k = 0; k < v.size(); k++)
                {
                    if (v[k][0] == i && v[k][1] == j)
                    {
                        flag = 1;
                        ans = v[k][2];
                    }
                }
                if (flag==1)
                    cout << ans << " ";
                else
                    cout << "0"
                         << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Array2D a(5, 5);
    // a.clear(3);
    a.setItem(3, 4, 6);
    a.setItem(1, 1, 2);
    cout << a.getItem(1, 2) << endl;
    a.display();
}