#include "Functions.h"

/*База даних з усіми можливими лексемами, які використовуються у завданні*/
vector <string> lex_directive{ "SEGMENT", "ENDS", "END", "DD", "DQ" };

vector <string> lex_command{ "FTST", "FSUB", "FSUBP", "FXCH"};

vector <string> lex_symb{ "(", ")", ",", "[", "]", "*", ":" };

vector <string> lex_register{ "EAX", "EBX", "ECX", "EDX", "EBP", "ESP", "EDI", "ESI",
							  "CS", "DS", "SS", "ES", "GS", "FS"};

vector <string> lex_identifier{ "DATA", "CODE"};

vector <string> lex_dig {};

/*Функція підняття всіх символів асемблерського файлу у верхній регістр
  і записування їх у новий, відкоректований, файл*/
void Upper() {
	char a[255];
	string str = "";
	int i = 0;
	bool dig = false;

	ifstream fin;
	ofstream fout;
	fin.open("Test.asm", ios_base::in);
	fout.open("CorTest.txt", ios_base::out);
	if (fin.is_open())
		while (!fin.eof())
		{
			fin.getline(a, 255);
			
			while (a[i] != '\0')
			{
				if (a[i] == ':' & a[i - 1] != ' ') fout.put(' ');
				if (a[i - 1] == ':' & a[i] != ' ') fout.put(' ');
				if (a[i] == '[' & a[i - 1] != ' ') fout.put(' ');
				if (a[i - 1] == '[' & a[i] != ' ') fout.put(' ');
				if (a[i] == ']' & a[i - 1] != ' ') fout.put(' ');
				if (a[i - 1] == ']' & a[i] != ' ') fout.put(' ');
				
				if (dig == false) {
					if (a[i] == ',' & a[i - 1] != ' ') fout.put(' ');
					if (a[i - 1] == ',' & a[i] != ' ') fout.put(' ');
					if (a[i] == '-' & a[i - 1] != ' ') fout.put(' ');
					if (a[i - 1] == '-' & a[i] != ' ') fout.put(' ');
				}

				if (a[i] == '*' & a[i - 1] != ' ') fout.put(' ');
				if (a[i - 1] == '*' & a[i] != ' ') fout.put(' ');
				if (a[i] == '(' & a[i - 1] != ' ') fout.put(' ');
				if (a[i - 1] == '(' & a[i] != ' ') fout.put(' ');
				if (a[i] == ')' & a[i - 1] != ' ') fout.put(' ');
				if (a[i - 1] == ')' & a[i] != ' ') fout.put(' ');
				fout << (char)toupper(a[i]);
				i++;
			}

			for (i = 0; a[i] != '\0'; i++)
				str += a[i];
			if (str == "DATA SEGMENT") dig = true;
			if (str == "DATA ENDS") dig = false;

			str = "";
			i = 0;
			fout << "\n";
		}
	else printf("File couldn't be open!\n");

	fin.close();
	fout.close();
}

void list(vector<string>& str, char* buf, int n);

/*Функція виконування лексичного аналізу відкоректованого файлу*/
void Read() {
	/*Задання та ініціалізація змінних*/
		int i = 0, j = 0;
		int count_lines = 1, tabl_count = 0, symb_count = 0;
		long double digit = 0;
		string::size_type sz = 0;
		char line[255];
		char buff[255];
		bool permiss = true, find_lex = false, identif = false, find_dig = false;
		bool mnem = false, mark_on = false, mark = false;
		int mnem_pos = 0, mark_pos = 0;
		bool operand1 = false, operand2 = false, reg = false;
		int oper_pos1 = 0, oper_pos2 = 0, oper_num1 = 1, oper_num2 = 1;
		string lexem = "";
		string str = "";
		vector <string> lex_str;

	ifstream fin;
	ifstream fasm;
	fin.open("CorTest.txt", ios_base::in);
	fasm.open("Test.asm", ios_base::in);
	ofstream fout;
	fout.open("Lex.txt", ios_base::out);

	if (fasm.is_open())
	{
		while (!fasm.eof()) {
			/*Вивід рядка асемблерного файлу та його номеру*/
			int n = 0;
			{
				bool empt = false;
				fasm.getline(buff, 255);
				fout << "|----------------------------------------------------------------" << endl;
				fout << "#" << count_lines << "#   " << setw(10);
				fout << buff << endl;
				for (int i = 0; buff[i] != '\0'; i++) {
					if (isgraph(buff[i]) == 0 || buff[i] == '\0' || buff[i] == '\n')
						empt = true;
					else {
						empt = false;
						break;
					}
				}
				n = i;
				if (empt == false) 
					fout << "Numb|    Lexem|    Symb num|      Type|" << endl;
			}
			tabl_count = 0;

			if (fin.is_open()) {
				while (!fin.eof()) {
					/*Перевірка: чи рядок відкривався уже в цьому циклі чи ні.
					  Якщо так то більше його не зчитуєм. Якщо ні, 
					  то зчитати наступний з відкоректованого файлу*/
					if (permiss == true) {
						fin.getline(line, 255);
						permiss = false;
					}

					/*Записуємо лексему з рядку line в рядок lexem*/
					while (isgraph(line[j])) {
						lexem += line[j];
						j++;
						symb_count++;
					}
					j++;

					lex_str.push_back(lexem);

					/*Перевірка на пустий рядок*/
					if (lexem == "\0") lexem = "";
					else fout << tabl_count << setw(20 - lexem.size()) << lexem << setw(10) << symb_count;
					
					/*Пошук лексеми у векторах і якщо вона є, то виведення її значення у файл аналізу*/
					
					if (find_lex == false)
					for (int i = 0; i < lex_directive.size(); i++) {
						if (lexem == lex_directive[i]) {
							fout << setw(25 - lexem.size()) << "Directive\n";
							find_lex = true;
							mnem = true;
							mnem_pos = tabl_count;
							break;
						}
					}

					if (find_lex == false)
					for (int i = 0; i < lex_command.size(); i++) {
						if (lexem == lex_command[i]) {
							fout << setw(25 - lexem.size()) << "Command\n";
							find_lex = true;
							mnem = true;
							mnem_pos = tabl_count;
							break;
						}
					}

					if (find_lex == false)
					for (int i = 0; i < lex_symb.size(); i++) {
						if (lexem == lex_symb[i]) {
							fout << setw(25 - lexem.size()) << "Symbol\n";
							find_lex = true;
							break;
						}
					}

					if (find_lex == false)
					for (int i = 0; i < lex_register.size(); i++) {
						if (lexem == lex_register[i]) {
							fout << setw(25 - lexem.size()) << "Register\n";
							if (operand1 == false) {
								operand1 = true;
								reg = true;
								oper_pos1 = tabl_count;
							}
							find_lex = true;
							break;
						}
					}

					if (find_lex == false)
						if (lexem == "ST") {
							fout << setw(25 - lexem.size()) << "Stek\n";
							if (operand1 == false) {
								operand1 = true;
								oper_num1 = 4;
								oper_pos1 = tabl_count;
							}
							else {
								operand2 = true;
								oper_num2 = 4;
								oper_pos2 = tabl_count;
							}
							find_lex = true;
						}

					find_dig = true;

					for (int i = 0; i < lexem.size(); i++)
						if (isalpha(lexem[i])) {
							find_dig = false;
							break;
						}

					for (i = 0; line[i] != '\0'; i++)
						str += line[i];
					if (str == "DATA SEGMENT") {
						identif = true; mark_on = true;
					}
					if (str == "DATA ENDS") {
						identif = false; mark_on = false;
					}
					str = "";

					if (find_lex == false && lexem != "" && find_dig == false && identif == true)
						lex_identifier.push_back(lexem);

					if (find_lex == false && lexem != "" && find_dig == true){
						digit = stold(lexem, &sz);
						lex_dig.push_back(lexem);
						fout << setw(25 - lexem.size()) << "Digit\n";
						if (mark_on == true) {
							if (operand1 == false) {
								operand1 = true;
								oper_num1 = 1;
								oper_pos1 = tabl_count;
							}
						}
						find_dig = false;
					}

					if (find_lex == false)
						for (int i = 0; i < lex_identifier.size(); i++) {
							if (lexem == lex_identifier[i]) {
								fout << setw(30 - lexem.size()) << "Identifier\n";
								if (mark_on == true) {
									mark = true; mark_pos = tabl_count;
								}
								else {
									if (i == 0 || i == 1) {
										mark = true; mark_pos = tabl_count;
									}
								}
								find_lex = true;
								break;
							}
						}

					/*Очищення рядка lexem. Перевірка на закінчення рядка line.
					  Якщо рядок line закінчився, то виконати переривання циклу і 
					  перейти на зчитування наступного рядку. Якщо рядок line
					  не закінчився, то не дозволяти циклу більше зчитувати рядки з 
					  відкоректованого файлу і виконувати аналіз поточного*/
					if (reg == true) oper_num1++;
					if (lexem != "") tabl_count++;
					lexem = "";
					symb_count = 0;
					find_lex = false;
					if (line[j] == '\0' || line[j - 1] == '\0') {
						permiss = true;
						break;
					}
					
				}
			}
			else printf("File (CorTest.txt) couldn't be open!\n");

			if (mark == true) {
				fout << "Mark field: " << mark_pos << endl;
			}

			if (mnem == true) {
				fout << "Mnemocode field: " << mnem_pos << endl;
			}
			
			if (operand1 == true) {
				fout << "Operand 1 field (pos, num of lex): " << oper_pos1 << ", " << oper_num1 << endl;
			}
			if (operand2 == true) {
				fout << "Operand 2 field (pos, num of lex): " << oper_pos2 << ", " << oper_num2 << endl;
			}

			list(lex_str, buff, 16);

			/*Ініціалізація та інкрементація змінних*/
			mnem = false;
			mark = false;
			operand1 = false;
			operand2 = false;
			reg = false;
			oper_num1 = 0;
			oper_num2 = 0;
			lex_str.clear();
			count_lines++;
			lexem = "";
			j = 0;
		}
	}
	else cout << "File(Test.asm) couldn't be open!\n";

	ofstream del;
	del.open("list.txt", ios_base::app);
	del << "\nJora Production (R) Macro Assembler Version 1999\n\n";
	del.close();

	fin.close();
	fasm.close();
	fout.close();
}

/*Функція переведення числа з десяткової в любу іншу систему числення*/
void calc(int num, int base, string s, bool per) {
	ofstream fout;
	fout.open("list.txt", ios_base::app);

	if (per == true && num < 10) {
		fout << s;
		per = false;
	}

	if (num == 0) 
		return;
	int rem = num % base;
	if (rem <= 9) {
		calc(num / base, base, s, per);
		fout << rem;
	}
	else {
		calc(num / base, base, s, per);
		fout << char(rem - 10 + 'A');
	}

	fout.close();
}

int zm = 0;
void bias(int n, int delta) {
	ofstream fout;
	fout.open("list.txt", ios_base::app);
	bool permiss = true;

if (zm <= 15 && permiss == true) {
	if (zm == 0) {
		fout << "000" << zm << "\t";
		zm += delta;
	}
	else {
		calc(zm, n, "000", true); fout << '\t';
		zm += delta;
	}
	permiss = false;
}

if (zm >= 16 && zm <= 160 && permiss == true) {
	calc(zm, n, "00", true); fout << '\t';
	zm += delta;
	permiss = false;
}

fout.close();
}

int err_num = 0;
void list(vector<string>& str, char* buf, int n) {
	ofstream fout;
	fout.open("list.txt", ios_base::app);
	string::size_type sz = 0;
	bool seg = false;
	bool err = true;

	for (int i = 0; i < str.size(); i++) {
		/*Зміщення для сегмента*/
		if (str[i] == "SEGMENT") {
			zm = 0;
			seg = true;
			fout << "000" << zm << "\t";
		}
		if (str[i] == "ENDS") {
			if (zm < 10) {
				calc(zm, n, "000", true); fout << '\t';
			}
			else {
				calc(zm, n, "00", true); fout << '\t';
			}
		}

		/*Зміщення для DD директив*/
		if (str[i] == "DD") {
			bias(n, 4);
		}
		/*Зміщення для DQ директив*/
		if (str[i] == "DQ") {
			bias(n, 8);
		}
		/*Зміщення для команд*/
		if (str[i] == "FTST") {
			bias(n, 2);
		}
		if (str[i] == "FSUB") {
			int j = 0;
			bool f = false;
			while (j < lex_identifier.size()) {
				if (str[i + 3] == lex_identifier[j]) f = true;
					j++;
			}
			j = 0;
			if (f == true)
				while (j < lex_register.size()) {
					if (str[i + 5] == lex_register[j]) f = true;
					j++;
				}
			if (str[i + 1] == "ES" && f == true) bias(n, 8);
			if (str[i + 1] == "DS" && f == true) bias(n, 7);
			if (str[i + 1] == "CS" && f == true) bias(n, 8);
			if (str[i + 1] == "SS" && f == true) bias(n, 8);
		}
		if (str[i] == "FSUBP") {
			bias(n, 2);
		}
		if (str[i] == "FXCH") {
			bias(n, 2);
		}

		/*Директива END*/
		if (str[i] == "END") {
			fout << "\t\t\t";
		}
	}


	/*Вивід рядка тестового файлу*/
	fout << buf << endl;

	/*Помилка*/
	for (int i = 0; i < str.size(); i++) {
		err = true;
		if (err == true)
			for (int j = 0; j < lex_directive.size(); j++) {
				if (str[i] == lex_directive[j]) {
					err = false; break;
				}
			}
		
		if (err == true)
			for (int j = 0; j < lex_register.size(); j++) {
				if (str[i] == lex_register[j]) {
					err = false; break;
				}
			}
		
		if (err == true)
			for (int j = 0; j < lex_command.size(); j++) {
				if (str[i] == lex_command[j]) {
					err = false; break;
				}
			}
		
		if (err == true)
			for (int j = 0; j < lex_symb.size(); j++) {
				if (str[i] == lex_symb[j]) {
					err = false; break;
				}
			}
		
		if (str[i] == "ST") {
			long double dig = 0;
			dig = stold(str[i+2], &sz);
			if (dig <=7 && dig >=0)
			err = false;
		}
		
		if (err == true)
			for (int j = 0; j < lex_identifier.size(); j++) {
				if (str[i] == lex_identifier[j]) {
					err = false; break;
				}
			}
		
		if (err == true)
			for (int j = 0; j < lex_dig.size(); j++) {
				if (str[i] == lex_dig[j]) {
					err = false; break;
				}
			}

		if (str[0] == "\n" || str[0] == "\0" && str.size() == 1) err = false;
		if (str[str.size()-1] == "\n" || str[str.size()-1] == "\0") err = false;
		if (str[i] == "\n" || str[i] == "\0" || str[i] == "\t") err = false;

		if (err == true) break;
	}
	if (err == true) {
		err_num++;
		fout << "\t\tError!!!\n";
	}

	fout.close();
}

/*Таблиця Segments and Groups,
  Symbols
  Errors */
void SegnGr() {
	ofstream fout;
	fout.open("list.txt", ios_base::app);

	fout << "\n\nSegments and Groups:\n" << endl;
	fout << "                N a m e         	Length	 Align	Combine Class\n\n";
	fout.close();

	ifstream fin;
	fin.open("list.txt", ios_base::in);
	char buff[255];
	int j = 0;
	string word = "";
	vector<string> str{};
	vector<string> tbl1{};
	vector<string> tbl2{};

	while (!fin.eof()) {
		fin.getline(buff, 255);
		word = "";
		while (buff[j] != '\0') {
			if (isgraph(buff[j])) 
				word += buff[j];
			else { str.push_back(word); word = ""; }
			j++;
		}
		str.push_back(word); word = "";
		j = 0;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == "SEGMENT") {
				tbl1.push_back(str[i - 1]);
			}
			if (str[i] == "ENDS") {
				tbl1.push_back(str[0]);
			}

		}
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == "DD" || str[i] == "DQ" || str[i] == "dd" || str[i] == "dq" ||
				str[i] == "Dd" || str[i] == "Dq" || str[i] == "dD" || str[i] == "dQ") {
				tbl2.push_back(str[i - 1]);
				tbl2.push_back(str[0]);
			}
		}
		str.clear();
	}
	fin.close();

	ofstream ffout;
	ffout.open("list.txt", ios_base::app);

	int i = 0;
	while (i < tbl1.size()) {
		ffout << tbl1[i] << " . . . . . . . . . . . . . .  	";
		i++;
		ffout << tbl1[i] << endl;
		i++;
	}

	ffout << "\nSymbols:\n\n";
	ffout << "                N a m e         	Type	 Value	 Attr\n\n";
	i = 0;
	while (i < tbl2.size()) {
		ffout << tbl2[i] << "  . . . . . . . . . . . . .  	";
		i++;
		ffout << "L DWORD   ";
		ffout << tbl2[i] << "	 ";
		i++;
		ffout << tbl1[0] << endl;
	}

	ffout << "\n\t\t" << err_num << " Severe Errors\n";

	ffout.close();
}