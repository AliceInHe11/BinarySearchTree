#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

typedef int typeinfo;
struct node {
	typeinfo data;
	node* left;
	node* right;
};

typedef node* nodeptr;
typedef node* BST;
typedef nodeptr BST;

void init(BST& r);
bool isEmpty(BST r);
nodeptr makenode(typeinfo x);
int insert(BST& r, typeinfo x);
void createTree(BST& r);
//duyet cay
void LNR(BST r);
void NRL(BST r);
void LRN(BST r);

int height(BST r);
void level(BST r, int k);
void printLevelOrder(BST& r);
int countleaf(BST r);
nodeptr search(BST r, typeinfo x);
nodeptr search_kodequi(BST r, typeinfo x);

bool writeData(const char* filename, BST r);
bool readData(const char* filename, BST r);