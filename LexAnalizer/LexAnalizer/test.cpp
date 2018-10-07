#include "Functions.h"

int main() {
	ofstream del;
	del.open("list.txt", ios_base::trunc);
	del.close();

	del.open("list.txt", ios_base::app);
	del << "Jora Production (R) Macro Assembler Version 1999\n\n";
	del.close();

	Upper();
	Read(); 
	SegnGr();

	//system("pause");
	return 0;
}