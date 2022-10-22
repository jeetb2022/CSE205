#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{   

    int arr[6] = {3,2,1,4,5,6};
    int flag = 0;
    string s = "";
    for (int i = 0; i < 6; i++)
    {
        int ct = 6 - i - 1;
        for (int j = i + 1; j < 6; j++)
        {
            // cout << "f ";
            s += "f";
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else
            {
                ct--;
            }
            // for(auto i : arr){
            //     cout << i << " ";
            // }
            // cout << endl;
            // cout << ct << endl;
            if (ct == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    cout << s.length() << endl;
    return 0;
}