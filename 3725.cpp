/*
 * Source: http://poj.grids.cn/practice/3725
 * Description:
 * tag: set
 * author: wangkendy (wkendy@gmail.com)
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min_dev_sum = 0x7fffffff;
int max_set_count = -1;

void find_set_count(vector<int> &nums, vector<int> &set_sum)
{
    int min;
    int index;
    int dev_sum;
    for (int i = 0; i < nums.size(); i++) {
        min = 0x7fffffff;
        for (int j = 0; j < set_sum.size(); j++) {
            if (min > set_sum[j]) {
                min = set_sum[j];
                index = j;
            }
        }
        set_sum[index] += nums[i];
    }
    for (int i = 0; i < set_sum.size(); i++) {
        dev_sum += abs(nums[0] - set_sum[i]);
    }
    if (dev_sum <= min_dev_sum) {
        min_dev_sum = dev_sum;
        max_set_count = set_sum.size();
    }
}

int main()
{
    int K;
    int sum = 0;
    int max = -2;
    cin >> K;
    vector<int> vi(K, 0);
    for (int i = 0; i < K; i++) {
        cin >> vi[i];
        sum += vi[i];
        if (max < vi[i])
            max = vi[i];
    }
    sort(vi.rbegin(), vi.rend());
    int set_count = sum / max;
    vector<int> set_sum(set_count, 0);
    find_set_count(vi, set_sum);
    vector<int> set_sum2(set_count + 1, 0);
    find_set_count(vi, set_sum2);
    cout << max_set_count << endl;
}
