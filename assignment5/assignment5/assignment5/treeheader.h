#ifndef TREEHEADER_H
#define TREEHEADER_H

struct Date {
	int month, day, year;
	Date *left, *right;
};

class TreeList {
private:
	Date *root;
public:
	TreeList(Date *root);
	TreeList(const TreeList &ll);
	const TreeList& operator=(const TreeList& ll);
	void display(Date *root);
	Date* insert(Date *root, Date *newDate);
	Date* remove(Date *root, Date *key);
	Date* search(Date *root, Date *key);
	~TreeList();
};
#endif


