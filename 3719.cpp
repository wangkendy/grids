/*
 * Source: http://poj.grids.cn/practice/3719
 * Description: qsort
 * tag: qsort
 *
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;

struct Student {
    char name[19];
    char lower_name[19];
    char sex;
    int num;
    int age;
};

int stu_cmp(const void *lhs, const void *rhs)
{
    Student *a = (Student*)lhs;
    Student *b = (Student*)rhs;
    return strcmp(a->lower_name, b->lower_name);
}

int main()
{
    Student stu[100];
    int i;
    for (i = 0; i < 100; i++) {
        if (gets(stu[i].name) == NULL)
            break;
        else if (strlen(stu[i].name) == 0) {
            i--;
            continue;
        }
        int len = strlen(stu[i].name);
        for (int k = 0; k < len; k++)
            stu[i].lower_name[k] = tolower(stu[i].name[k]);
        Student *ps = &stu[i];
        scanf("%d,%c %d", &ps->num, &ps->sex, &ps->age);
    }

    qsort(stu, i, sizeof(Student), stu_cmp);

    Student *ps;
    for (int j = 0; j < i; j++) {
        ps = &stu[j];
        printf("%s\n", ps->name);
        printf("%08d,%c %d\n", ps->num, ps->sex, ps->age);
    }
}
