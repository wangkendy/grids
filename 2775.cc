/*
 * source: http://poj.grids.cn/practice/2775/
 * tag: recursion
 *
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;

struct Dir {
	char name[20];
	struct Dir* sibling;
	struct Dir* child;
};

void create_tree(struct Dir *root)
{
	string name;
	struct Dir *dir;
	struct Dir *child;
	cin >> name;
	if (name[0] != ']' && name[0] != '#') {
		child = (struct Dir*) malloc (sizeof(struct Dir));
		child->child = NULL;
		child->sibling = NULL;
		sprintf(child->name, "%s", name.c_str());
		root->child = child;
		if (name[0] == 'd') create_tree(child);
		cin >> name;
		while (name[0] != '*' && name[0] != ']') {
			dir = (struct Dir*) malloc (sizeof(struct Dir));
			sprintf(dir->name, "%s", name.c_str());
			dir->sibling = NULL;
			child->sibling = dir;
			child = dir;
			if (name[0] == 'd') {
				create_tree(dir);
			}
			cin >> name;
		}
	}
}

void print_tree(struct Dir *root, int level)
{
	set<string> files;	
	for (int i = 0; i < level; i++) 
		cout << "|     ";
	cout << root->name << endl;
	struct Dir *dir = root->child;
	while (dir != NULL) {
		if (dir->name[0] == 'd') {
			print_tree(dir, level+1);
		} else {
			files.insert(string(dir->name));
		}
		dir = dir->sibling;
	}
	set<string>::iterator it = files.begin();
	for (; it != files.end(); it++) {
		for (int i = 0; i < level; i++)
			cout << "|     ";
		cout << *it << endl;
	}
}

void free_tree(struct Dir *root)
{
	struct Dir *dir = root->child;
	root->child = NULL;
	struct Dir *temp;
	while (dir != NULL) {
		if (dir->name[0] == 'd')
			free_tree(dir);
		temp = dir;
		dir = dir->sibling;
		free(temp);
	}
}

int main()
{
	struct Dir root;
	int ca = 1;
	sprintf(root.name, "ROOT");
	root.child = NULL;
	create_tree(&root);
	while (root.child != NULL) {
		cout << "DATA SET " << ca++ << ":" << endl;
		print_tree(&root, 0);
		cout << endl;
		free_tree(&root);
		create_tree(&root);
	}
	return 0;
}
