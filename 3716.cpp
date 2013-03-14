/*
 * Source: http://poj.grids.cn/practice/3716
 * Description: configuration file
 * tag: string
 * author: wangkendy (wkendy@gmail.com)
 *
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ConfItem {
    string name;
    string value;
};

int main() {
    string line;
    vector<ConfItem*> vc;
    ConfItem *p;
    while (getline(cin, line)) {
        if (line.size() == 0) continue;
        if (line[0] == '#') continue;
        p = new ConfItem;
        int p1 = line.find(' ');
        int p2;
        p1 = line.find_first_not_of(' ', p1);
        p2 = line.find(' ', p1);
        p->name = line.substr(p1, p2 - p1);
        p1 = line.find_first_not_of(' ', p2);
        p->value = line.substr(p1);
        vc.push_back(p);
    }
    cout << vc.size() << endl;
    for (int i = 0; i < vc.size(); i++) {
        cout << vc[i]->name << ' ' << vc[i]->value << endl;
    }
    return 0;
}
