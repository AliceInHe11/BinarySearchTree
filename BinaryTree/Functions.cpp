#include"Functions.h"

void init(BST& r) {	r = NULL;}

bool isEmpty(BST r) { return r == NULL;}

nodeptr makenode(typeinfo x) {
	nodeptr p = new node;
	if (p == NULL) 
		return p;
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

int insert(BST& r, typeinfo x) {
	nodeptr p = makenode(x);
	if (isEmpty(r))
		r = p;
	else 
		if (r->data == x)  
			throw "Node da ton tai!"; 
		else 
			if (x < r->data)
				insert(r->left, x);
			else
				insert(r->right, x);	
	return 1;
}

void createTree(BST& r) {
	typeinfo x;
	do {
		cout << "\nEnter x (enter -99 to exit): "; cin >> x;
		if (x == -99)break;
		try { insert(r, x); }
		catch (const char* s) { cout << s; }
	} while (true);
}

void LNR(BST r) {
	if (r!=NULL) {
		LNR(r->left);
		cout << r->data << "  ";
		LNR(r->right);
	}
}

void NRL(BST r) {
	if (r != NULL) {
		cout << r->data << "  "; 
		NRL(r->right); 
		NRL(r->left); 
	}
}

void LRN(BST r) {
	if (r!=NULL) {
		LRN(r->left);
		LRN(r->right);
		cout << r->data << "  ";
	}
}

int height(BST r) {
	if (isEmpty(r)) 
		return 0;
	int left = height(r->left);
	int right = height(r->right);
	if (left > right)
		return left + 1;
	else
		return right + 1;
}

void level(BST r, int k) {//xuat 1 tang
	if (!r) return;
	if (k == 0)
		cout << r->data << "\t";
	else {
		level(r->left, k - 1);
		level(r->right, k - 1);
	}
}


void printLevelOrder(BST& r) {//xuat cay
	int h = height(r);
	for (int i = 0; i < h; i++) {
		cout << endl;
		level(r, i);
	}
}


int countleaf(BST r) {
	if (!r) return 0;
	int left = countleaf(r->left);
	int right = countleaf(r->right);
	if (!r->left && !r->right ) //boi so , uoc so ,cp,hoan thien ,nguyen to
		return left + right + 1;
	return left + right;
}

nodeptr search(BST r, typeinfo x) {
	if (r)
	{
		if (r->data == x)
			return r;
		else
			if (r->data > x)
				return search(r->left, x);
			else return search(r->right, x);
	}
	return NULL;
}

nodeptr search_kodequi(BST r, typeinfo x) {
	while (r) {
		if (x == r->data)return r;
		else
			if (r->data > x)
				r = r->left;
			else
				return r = r->right;
	}
	return NULL;
}

bool writeData(const char* filename, BST r) {
	FILE* f = fopen(filename, "w");
	if (f == NULL) return false;
	int n = fwrite(&r, sizeof(r), 1, f);
	fclose(f);
	if (n == 1)
		return true;
	else
		return false;
}

bool readData(const char* filename, BST r) {
	FILE* f = fopen(filename, "rb");
	if (f == NULL) return false;
	int n = fread(&r, sizeof(r), 1, f);
	fclose(f);
	if (n == 1)
		return true;
	else
		return false;
}