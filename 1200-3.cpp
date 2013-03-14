/*
 * Source: http://poj.grids.cn/practice/1200/
 * Description: Crazy Search
 * tag: stl map
 *
 */

#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main()
{
    int N, NC;
    char ch;
    int total = 0;
    map<string,int> mapsi;
    string word;
    scanf("%d %d", &N, &NC);
    getchar();
    for(int i = 1; i < N; i++) {    //read in N-1 char
        scanf("%c", &ch);
        word += ch;
    }
    while(scanf("%c", &ch) != EOF && ch != '\n') {
        word += ch;
        if (mapsi[word] == 0) {
            mapsi[word] = 1;
            total++;
        }
        word.erase(0,1);
    }
    printf("%d", total);
    return 0;
}
