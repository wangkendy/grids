/*
 * Source: http://poj.grids.cn/practice/3714
 * Description: dish ordering
 * tag: recursion
 * author: wangkendy (wkendy@gmail.com)
 */

#include <iostream>
#include <vector>
using namespace std;

struct Dish {
    int price;
    int score;
};

int max_score = 0;
int budget;

void recur_pick(const vector<Dish>& menu, int num, int total_price, int total_score)
{
    if (num == menu.size() - 1) {   // base case
        if (total_price + menu[num].price <= budget)
            total_score += menu[num].score;
        if (total_score > max_score)
            max_score = total_score;
    } else {
        if (total_price + menu[num].price <= budget) {
            recur_pick(menu, num + 1, 
                    total_price + menu[num].price, 
                    total_score + menu[num].score);
        }
        recur_pick(menu, num + 1, total_price, total_score);
    }

}

int main()
{
    int C, N;
    while ( cin >> C >> N) {
        vector<Dish> menu(N);
        max_score = 0;
        budget = C;
        for (int i = 0; i < N; i++)
            cin >> menu[i].price >> menu[i].score;
        recur_pick(menu, 0, 0, 0);
        cout << max_score << endl;
    }
    return 0;
}
