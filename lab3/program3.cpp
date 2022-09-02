#include <bits/stdc++.h>
// #include<Array2D>
using namespace std;

class Array2D
{
public:
    int row;
    int col;
    // const int N=3;
    vector<vector<int>> v;
    Array2D(int r, int c)
    {
        this->row = r;
        this->col = c;
    }

    int numRows()
    {
        return this->row;
    }
    int numCols()
    {
        return this->col;
    }

    vector<vector<int>> makeVector()
    {
        return v;
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

    void setItem(int i1, int i2, int val)
    {
        vector<int> temp;
        temp.push_back(i1);
        temp.push_back(i2);
        temp.push_back(val);
        // for(int i=0;i<temp.size();i++)
        // {
        //     cout<<temp[i]<<" ";
        // }
        v.push_back(temp);
    }

    void scaleBy(int x)
    {
        for (int k = 0; k < v.size(); k++)
        {
            v[k][2] *= x;
        }
    }

    void transpose()
    {
        for (int k = 0; k < v.size(); k++)
        {
            int temp = v[k][0];
            v[k][0] = v[k][1];
            v[k][1] = temp;
        }
        display();
    }

    void add(vector<vector<int>> x, vector<vector<int>> y)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                bool flag1 = false;
                bool flag2 = false;
                int ans1 = 0, ans2 = 0;
                for (int p = 0; p < x.size(); p++)
                {
                    if (x[p][0] == i && x[p][1] == j)
                    {
                        flag1 = true;
                        ans1 = x[p][2];
                    }
                }
                for (int q = 0; q < y.size(); q++)
                {
                    if (y[q][0] == i && y[q][1] == j)
                    {
                        flag2 = true;
                        ans2 = y[q][2];
                    }
                }
                if (flag1 && flag2)
                {
                    // cout<<ans1<<" "<<ans2<<endl;
                    v.push_back({i, j, ans1 + ans2});
                }
                else if (flag1 == true && flag2 == false)
                {
                    // cout<<ans1<<" "<<ans2<<endl;
                    v.push_back({i, j, ans1});
                }
                else if (flag1 == false && flag2 == true)
                {
                    // cout<<ans1<<" "<<ans2<<endl;
                    v.push_back({i, j, ans2});
                }
            }
        }
        display();
    }

    void sub(vector<vector<int>> x, vector<vector<int>> y)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                bool flag1 = false;
                bool flag2 = false;
                int ans1 = 0, ans2 = 0;
                for (int p = 0; p < x.size(); p++)
                {
                    if (x[p][0] == i && x[p][1] == j)
                    {
                        flag1 = true;
                        ans1 = x[p][2];
                    }
                }
                for (int q = 0; q < y.size(); q++)
                {
                    if (y[q][0] == i && y[q][1] == j)
                    {
                        flag2 = true;
                        ans2 = y[q][2];
                    }
                }
                if (flag1 && flag2)
                {
                    // cout<<ans1<<" "<<ans2<<endl;
                    v.push_back({i, j, ans1 - ans2});
                }
                else if (flag1 == true && flag2 == false)
                {
                    // cout<<ans1<<" "<<ans2<<endl;
                    v.push_back({i, j, ans1});
                }
                else if (flag1 == false && flag2 == true)
                {
                    // cout<<ans1<<" "<<ans2<<endl;
                    v.push_back({i, j, -ans2});
                }
            }
        }
        display();
    }

    void multiply(vector<vector<int>> x, vector<vector<int>> y)
    {
        for (int i = 0; i < x.size();)
        {
            int r = x[i][0], col, ans;
            for (int j = 0; j < y.size();)
            {
                int c = y[j][0];
                int tempa = i;
                int tempb = j;
                int sum = 0;
                while (tempa < x.size() && x[tempa][0] == r && tempb < y.size() && y[tempb][0] == c)
                {
                    if (x[tempa][1] < y[tempb][1])
                        tempa++;
                    else if (x[tempa][1] > y[tempb][1])
                        tempb++;
                    else
                        sum += x[tempa++][2] * y[tempb++][2];
                }
                if (sum != 0)
                {
                    v.push_back({r, c, sum});
                }
                while (j < y.size() && y[j][0] == c)
                    j++;
                while (i < x.size() && x[i][0] == r)
                    i++;
            }
        }
        display();
    }

    void display()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                bool flag = false;
                int ans;
                for (int k = 0; k < v.size(); k++)
                {
                    if (v[k][0] == i && v[k][1] == j)
                    {
                        flag = true;
                        ans = v[k][2];
                    }
                }
                if (flag)
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
    a.setItem(3, 4, 6);
    a.setItem(1, 3, 2);
    a.setItem(1, 1, 2);
    cout << "Matrix A:" << endl;
    a.display();
    cout << endl;

    a.scaleBy(3);
    cout<<"Scale of A by 3:"<<endl;
    a.display();
    cout << endl;

    Array2D b(5, 5);
    b.setItem(1, 3, 3);
    b.setItem(4, 1, 4);
    cout << "Matrix B:" << endl;
    b.display();
    cout << endl;

    vector<vector<int>> veca, vecb;
    veca = a.makeVector();
    vecb = b.makeVector();
    sort(vecb.begin(), vecb.end());
    sort(veca.begin(), veca.end());


    Array2D Operation(5, 5);
    cout << "Multiplication of Matrix A & B:" << endl;
    Operation.multiply(veca, vecb);
    cout << endl;

    
    cout<<"Addition of Matrix A & B:"<<endl;
    Operation.add(veca, vecb);
    cout<<endl;

    cout<<"Subtraction of Matrix A & B:"<<endl;
    Operation.sub(veca,vecb);
    cout<<endl;
    
    cout<<"Transpose of A:"<<endl;
    a.transpose();
    cout<<endl;
}