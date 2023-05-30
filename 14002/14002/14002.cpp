#include <iostream>
#include <vector>

using namespace std;

#define MAX 1001
int A;
int arr[MAX];
int dp[MAX];
vector<int> list[MAX]; //수열의 값 넣어주는 곳
vector<int> ans;


int main(void)
{
    cin >> A;
    for (int i = 1; i <= A; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= A; i++)
    {
        dp[i] = 1;
        list[i].push_back(arr[i]);
        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                if (dp[i] < dp[j] + 1)
                {
                    list[i].clear();
                    list[i] = list[j];
                    list[i].push_back(arr[i]);
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if (ans.size() < list[i].size())
        {
            ans = list[i];
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}