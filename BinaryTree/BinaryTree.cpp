#include"Functions.h"

int main() {
	BST a;
	init(a);

	//if (readData("DATA.dat", a) == true)
	//	cout << "\nData reading successful.";
	//else
	//	cout << "\nData reading failed.";

	createTree(a);

	cout << "LNR: "; LNR(a);
	cout << endl << "LRN: "; LRN(a);
	cout << endl << "NRL: "; NRL(a);
	cout << endl << "Tree heigh's: " << height(a);
	cout << endl << "Leaf: " << countleaf(a);

	//if (writeData("DATA.txt", a) == true)
	//	cout << "\nData recording successful.";
	//else
	//	cout << "Data recording failed.";

	system("pause");
	return 0;
}