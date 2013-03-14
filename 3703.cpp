/*
 * Source: http://poj.grids.cn/practice/3703
 * Description: big point
 * tag: 
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
public:
    Point():ruled(false){}
    bool operator< (const Point& rhs) const {
        if (x == rhs.x)
            return y < rhs.y;
        else
            return x < rhs.x;
    }

    friend istream& operator>> (istream& in, Point& point) {
        return in >> point.x >> point.y;
    }

    friend ostream& operator<< (ostream& out, Point& point) {
        return out << "(" << point.x << "," << point.y << ")";
    }
    
    bool rules(const Point& rhs) {
        if (y >= rhs.y)
            return true;
        return false;
    }
    
    bool is_ruled() {
        return ruled;
    }

    void set_ruled() {
        ruled = true;
    }

private:
    int x;
    int y;
    bool ruled;
};

int main()
{
    int T;
    vector<Point> vp;
    Point p;
    cin >> T;
    while (T--) {
        cin >> p;
        vp.push_back(p);
    }
    sort(vp.begin(), vp.end());
    for (int i = vp.size() - 1; i > 0; i--) {
        if (vp[i].is_ruled()) continue;
        for (int j = i - 1; j >=0; j--) {
           if (vp[i].rules(vp[j]))
               vp[j].set_ruled();
        }
    }
    for (int i = 0; i < vp.size(); i++) {
        if (!vp[i].is_ruled()) {
            cout << vp[i];
            if (i != vp.size() - 1)
                cout << ',';
        }
    }
    return 0;
}

