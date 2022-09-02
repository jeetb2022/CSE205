#include <bits/stdc++.h>
using namespace std;

class Array2D
{
public:
    int row;
    int col;
    int **a;

    // int a[row][col];
    Array2D(int x,int y)
    {
        // cout<<x<<endl;
        this->row=x;
        this->col=y;
        a = new int *[y];
        for (int i = 0; i < x; i++)
        {
            a[i] = new int[y];
        }
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                a[i][j] = 0;
            }
        }
    }
    int numRows()
    {
        return this->row;
    }
    int numCols()
    {
        return this->col;
    }

    void clear(int value)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                a[i][j] = value;
            }
        }
    }

    int getItem(int i1,int i2)
    {
        return a[i1][i2];
    }

    void setItem(int i1,int i2, int val)
    {
        a[i1][i2]=val;
    }

    void display()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int row, col;
    cin >> row >> col;
    Array2D a(row,col);
    a.clear(3);
    a.setItem(1,2,5);
    cout<<a.getItem(1,2)<<endl;
    a.display();
}