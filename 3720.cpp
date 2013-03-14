/*
 * Source: http://poj.grids.cn/practice/3720
 * Description: letter tree
 * tag: stack, tree
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    char val;
    bool has_left;
    int level;
    Node *left;
    Node *right;
};

int count_level(string& line)
{
    int i;
    for (i = 0; i < line.size(); i++)
        if (line[i] != '-')
            break;
    return i;
}

void print_tree_in(Node *root)
{
    if (root != NULL) {
        print_tree_in(root->left);
        cout << root->val;
        print_tree_in(root->right);
    }
}

void print_tree_pre(Node *root)
{
    if (root != NULL) {
        cout << root->val;
        print_tree_pre(root->left);
        print_tree_pre(root->right);
    }
}

void print_tree_post(Node *root)
{
    if (root != NULL) {
        print_tree_post(root->left);
        print_tree_post(root->right);
        cout << root->val;
    }
}

int main()
{
    int T;
    string line;
    cin >> T;
    while (T--) {
        vector<Node*> vn;
        while (cin >> line) {
            if (line[0] == '0')
                break;
            int level = count_level(line);
            char val = line[level];
            Node *p =  NULL;
            if (val != '*') {
                p = new Node;
                p->val = val;
                p->level = level;
                p->left = NULL;
                p->right = NULL;
                p->has_left = false;
            }
            for (int i = vn.size() - 1; i >= 0; i--) {
                if (vn[i]->level == level - 1) {
                    if (vn[i]->has_left)
                        vn[i]->right = p;
                    else {
                        vn[i]->left = p;
                        vn[i]->has_left = true;
                    }
                    break;
                }
            }
            if (p)
                vn.push_back(p);
        }

        print_tree_pre(vn[0]);
        cout << endl;
        print_tree_post(vn[0]);
        cout << endl;
        print_tree_in(vn[0]);
        cout << endl;
        if (T != 0)
            cout << endl;
    }
    return 0;
}
