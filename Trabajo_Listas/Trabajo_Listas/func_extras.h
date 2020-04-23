#include <iostream>
using std::string;


char mapeo[11][38] = {
	"1222222222222222222222222222222222226",
	"3   Bienvenido a la base de datos   3",
	"4222222222222222222222222222222222228",
	"3   Empresa: Dream Programators S.A 3",
	"4222222222222222222222222222222222228",
	"3   Usuario:  Ts-Pytham.            3",
	"3   Password: **********            3",
	"4222222222222222222222222222222222228",
	"3   Acceso total al sistema         3",
	"5222222222222222222222222222222222227",

};

char menu[15][75] = {
	"1222222222222222222222222222222222226",
	"3        MENU PARA EMPLEADOR        3",
	"4222222222222222222222222222222222228",
	"3   1) Ingresar empleado.           3",
	"3   2) Borrar empleado.             3",
	"3   3) Promedio de salarios.        3",
	"3   4) Porcentaje de salarios menor 3",
	"3   a un millon.                    3",
	"3   5) Empleado mas antiguo.        3",
	"3   6) Mostrar todos los empleados. 3",
	"3   7) Mostrar datos del empleado.  3",
	"3   8) Salir.                       3",
	"5222222222222222222222222222222222227",
};
//=======================================FUNCIONES EXTRAS================================
void delay(int segs) {
	for (time_t i = (time(NULL) + segs); time(NULL) != i; time(NULL));
}

int to_compare(string str1, string str2) {
	if (str2.length() == str1.length()) {
		if (str1 == str2)
			return 0;
		int len = str1.length();
		for (int i = 0; i < len; ++i) {
			if (toupper(str1[i]) != toupper(str2[i]))
				return 1;
		}
		return 0;
	}
	else
		return 1;
}

int strfind(string word, string sentence) {
	int lenOra = sentence.length(), lenPal = word.length(), j = 0, aux = 0;
	for (int i = 0; i < lenOra; ++i) {

		if (toupper(word[j]) == toupper(sentence[i])) {
			aux++;
			j++;
		}
		else {
			aux = 0;
			j = 0;
		}
		if (lenPal == aux)
			return 0;
	}
	return 1;
}
void mostrar_menu() {
	for (int i = 0; i < 15; ++i) {
		std::cout << "\t\t";
		for (int j = 0; j < 75; ++j) {
			if (menu[i][j] == '1' && menu[i][j + 1] != ')')
				std::cout << char(201);
			else if (menu[i][j] == '2' && menu[i][j + 1] != ')')
				std::cout << char(205);
			else if (menu[i][j] == '3' && menu[i][j + 1] != ')')
				std::cout << char(186);
			else if (menu[i][j] == '4' && menu[i][j + 1] != ')')
				std::cout << char(204);
			else if (menu[i][j] == '5' && menu[i][j + 1] != ')')
				std::cout << char(200);
			else if (menu[i][j] == '6' && menu[i][j + 1] != ')')
				std::cout << char(187);
			else if (menu[i][j] == '7' && menu[i][j + 1] != ')')
				std::cout << char(188);
			else if (menu[i][j] == '8' && menu[i][j + 1] != ')')
				std::cout << char(185);
			else
				std::cout << menu[i][j];
		}
		std::cout << "\n";
	}
}

void mostrar() {
	for (int i = 0; i < 11; ++i) {
		std::cout << "\t\t";
		for (int j = 0; j < 38; ++j) {
			if (mapeo[i][j] == '1')
				std::cout << char(201);
			else if (mapeo[i][j] == '2')
				std::cout << char(205);
			else if (mapeo[i][j] == '3')
				std::cout << char(186);
			else if (mapeo[i][j] == '4')
				std::cout << char(204);
			else if (mapeo[i][j] == '5')
				std::cout << char(200);
			else if (mapeo[i][j] == '6')
				std::cout << char(187);
			else if (mapeo[i][j] == '7')
				std::cout << char(188);
			else if (mapeo[i][j] == '8')
				std::cout << char(185);
			else
				std::cout << mapeo[i][j];
		}
		std::cout << "\n";
	}
}
