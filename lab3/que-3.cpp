#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Matrix
{
public:
    int nrow;
    int ncol;
    // const int N=3;
    vector<vector<int>> v;
    Matrix(int nrow, int ncol)
    {
        this->nrow = nrow;
        this->ncol = ncol;
    }

    int numRows()
    {
        return nrow;
    }
    int numCols()
    {
        return ncol;
    }

    void clear(int value)
    {
        for (int i = 0; i < nrow; i++)
        {
            // vector<int> temp;
            for (int j = 0; j < ncol; j++)
            {
            int flag = 0;
                    ll ans;
                for (int k = 0; k < v.size(); k++)
                {
                    if (v[k][0] == i && v[k][1] == j)
                    {
                        flag = 1;
                        v[k][2]=0;
                    }
                }
                if (flag==1){
                }
                else {
                    vector<int >temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(value);
                    v.push_back(temp);
                }
            }
        }
    }

    int getItem(int row, int col)
    {
        for (int k = 0; k < v.size(); k++)
        {
            if (v[k][0] == row && v[k][1] == col)
            {
                return v[k][2];
            }
        }
        return 0;
    }

    void setItem(int row, int col, int value)
    {
        vector<int> temp;
        temp.push_back(row);
        temp.push_back(col);
        temp.push_back(value);
        v.push_back(temp);
    }
    void scaleBy(int scalar)
    {
        for (int i = 0; i < v.size(); i++)
        {
            v[i][2] = scalar * v[i][2];
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

    vector<vector<int>> add(vector<vector<int>> rhsmatrix)
    {
        vector<vector<int>> ans(nrow);
        cout << endl;
        for (int i = 0; i < nrow; i++)
        {
            for (int j = 0; j < ncol; j++)
            {
                int flag = 0, value;

                for (int k = 0; k < v.size(); k++)
                {

                    if (v[k][0] == i && v[k][1] == j)
                    {
                        value = v[k][2];
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    ans[i].push_back(value + rhsmatrix[i][j]);
                    // cout<<"one"<<v[i][2];
                }
                else
                {
                    ans[i].push_back(rhsmatrix[i][j]);
                }
            }
        }
        return ans;
    }

    vector<vector<int>> subtract(vector<vector<int>> rhsmatrix)
    {
        vector<vector<int>> ans(nrow);
        cout << endl;
        for (int i = 0; i < nrow; i++)
        {
            for (int j = 0; j < ncol; j++)
            {
                int flag = 0, value;

                for (int k = 0; k < v.size(); k++)
                {

                    if (v[k][0] == i && v[k][1] == j)
                    {
                        value = v[k][2];
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    ans[i].push_back(value - rhsmatrix[i][j]);
                    // cout<<"one"<<v[i][2];
                }
                else
                {
                    ans[i].push_back(-rhsmatrix[i][j]);
                }
            }
        }
        return ans;
    }

    vector<vector<int>> multiply(vector<vector<int>> rhsmatrix)
    {
        vector<vector<int>> ans(nrow);
        vector<vector<int>> lhsmatrix(nrow);
        for (int i = 0; i < nrow; i++)
        {
            for (int j = 0; j < ncol; j++)
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
                if (flag == 1){
                    lhsmatrix[i].push_back(ans);
                    // cout<<lhsmatrix[i][j]<<" ";
                }
                else{
                    lhsmatrix[i].push_back(0);
                    // cout<<lhsmatrix[i][j]<<" ";
                   
                }
            }
            // cout<<endl;
        }
        for (int i = 0; i < nrow; ++i)
        {
            for (int j = 0; j < ncol; ++j)
            {
                ll ans2=0;
                for (int k = 0; k < ncol; ++k)
                {
                    ans2 +=( lhsmatrix[i][k] * rhsmatrix[k][j]);
                    // cout << ans[i][j] << " ";
                }
                ans[i].push_back(ans2);
                // cout<<ans[i][j]<<" ";

            }
        }

        return ans;
    }

    void display()
    {
        for (int i = 0; i < nrow; i++)
        {
            for (int j = 0; j < ncol; j++)
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
                if (flag == 1)
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

    Matrix a(5, 5);
    vector<vector<int>> rhsMatrix = {
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1}};

    a.display();
    a.setItem(3, 2, 6);
    a.setItem(1, 1, 2);

    // a.display();
    cout << endl;
    a.transpose();

    cout << "Addition: " << endl;
    vector<vector<int>> addition;
    addition = a.add(rhsMatrix);
    for (int i = 0; i < addition.size(); i++)
    {
        for (int j = 0; j < addition[0].size(); j++)
        {
            cout << addition[i][j] << " ";
        }
        cout << endl;
    }

    cout << "subtraction: " << endl;
    vector<vector<int>> subtraction;
    subtraction = a.subtract(rhsMatrix);
    for (int i = 0; i < subtraction.size(); i++)
    {
        for (int j = 0; j < subtraction[0].size(); j++)
        {
            cout << subtraction[i][j] << " ";
        }
        cout << endl;
    }

    cout << "multipication: " << endl;
    vector<vector<int>> multiplication;
    
    multiplication = a.multiply(rhsMatrix);
    for (int i = 0; i < multiplication.size(); i++)
    {
        for (int j = 0; j < multiplication[0].size(); j++)
        {
            cout << multiplication[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"Clearing the matrix with a particular value:"<<endl;

    a.clear(3);
    a.display();

    return 0;
}