#include<bits/stdc++.h>

#define Ban8aly ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 4;
const int n = 3;
using namespace std;
bool check (char arr[n][n])
{
    bool flag = false;
    //rows
    if (arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2]&&arr[0][1]!='.') flag  = true;
    if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2]&&arr[1][2]!='.') flag  = true;
    if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2]&&arr[2][2]!='.') flag  = true;
    // columns
    if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0]&&arr[2][0]!='.') flag  = true;
    if (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1]&&arr[2][1]!='.') flag  = true;
    if (arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2]&&arr[2][2]!='.') flag  = true;
    //diameter
    if(arr[0][0] == arr[2][2] && arr[0][0] == arr[1][1] && arr[0][0]!='.') flag = true;
    if(arr[2][0] == arr[0][2] && arr[0][2] == arr[1][1] && arr[1][1]!='.') flag = true;
    //---------
    return flag;
}

void printArray(char arr[n][n])
{

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "\n\n";
    }
}
void printArray(string arr[n][n])
{

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "\n\n";
    }
}
unordered_map<string,pair<int , int>> mm ;
unordered_map<string, bool> m2;
int main()
{
    //Shout out for  SHATTA


    string indexes [9] = {"topR","topM","topL","midR","midM","midL","bottomR","bottomM","bottomL"};
    static int moves; // counter to exit the loop after nine moves

    char arr2[n][n] {{'x','o','x'}
                    ,{'o','.','o'}
                    ,{'x','.','.'}};
    mm["topL"] = {0,0}, mm["topM"] = {0,1}, mm["topR"] = {0,2};
    mm["midL"] = {1,0}, mm["midM"] = {1,1}, mm["midR"] = {1,2};
    mm["bottomL"] = {2,0}, mm["bottomM"] = {2,1}, mm["bottomR"] = {2,2};

    printf("\t\tX & O\n\t\t-----\n\nX always starts first!\n\nType indexes as shown in the following grid\n\n");
// the game starts here
    char arr[n][n];
   string arr3[n][n] {{"topL","topM","topR"},{"midL","midM","midR"},{"bottomL","bottomM","bottomR"}};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = '.';
        }
    }
    printArray(arr3);

    while(moves < 9)
    {
        bool flag = false;
        string str; cin >> str;
        for(int i = 0; i < 9; i++) {
            if (str == indexes[i]) {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            cout << "Enter a Valid index\n";
        }
        else
        {
            if(m2[str])
            {
                cout << "You have already entered (" << str <<")\n";
            }
            else
            {
                m2[str] = true;
                if(moves&1)
                arr[mm[str].first][mm[str].second] = 'o';
                else
                    arr[mm[str].first][mm[str].second] = 'x';
                printArray(arr);
                moves++;
                if(check(arr))
                {
                    cout << (moves & 1?"Player X wins the game": "Player O wins the game");
                    printf("\n\n");
                    cout << "programmed by Adham khaled";
                    return 0;
                }
            }
        }

    }
    printf("It's a tie!\n\nProgrammed by Adham khaled");

}