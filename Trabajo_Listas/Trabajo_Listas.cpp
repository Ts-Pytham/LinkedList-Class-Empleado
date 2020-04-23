#include <iostream>
#include <string>
#include <ctime>
#include "Lista_Empleado.h"
using std::string;


//=====================================FUNCIONES EXTERNAS DEL TAD====================================

double porcentaje(LinkedList list) {
	int cont = 0;
	for (int i = 0; i < list.Size(); ++i) {
		Empleado* empleado = list.Get(i);
		long double salario = empleado->GetSalario();
		if (salario < 1000000)
			++cont;
	}
	return ((long double)cont / list.Size()) * 100;
}

string antiguo(LinkedList list) {
	Empleado* empleado = list.Get(0);
	int mayor = empleado->GetAntiguedad();
	string n_mayor = empleado->GetName();
	for (int i = 1; i < list.Size(); ++i) {
		Empleado* empleado = list.Get(i);
		if (empleado->GetAntiguedad() > mayor) {
			mayor = empleado->GetAntiguedad();
			n_mayor = empleado->GetName();
		}
	}
	return n_mayor;
}

double promedio_salario(LinkedList list) {
	long double suma = 0;
	for (int i = 0; i < list.Size(); ++i) {
		Empleado* empleado = list.Get(i);
		suma += empleado->GetSalario();
	}
	return suma / list.Size();
}

void mostrar_datos(LinkedList list) {
	string name;
	int op;
	bool correcto = false;
	std::cout << "Ingrese 1 si quiere busqueda normal (escribir solo el nombre).\nIngrese 2 para busqueda avanzada (escribe un trozo del nombre y es encontrado)" << std::endl;
	std::cin >> op;
	std::cout << "Introduzca el nombre que quiere buscar en la lista: " << std::endl;
	std::cin.ignore();
	getline(std::cin, name);
	std::cout << "Esto puede tardar unos segundos en encontrar el dato..." << std::endl;
	delay(2);
	std::cout << "Esto puede tardar unos segundos en encontrar el dato.." << std::endl;
	delay(2);
	std::cout << "Esto puede tardar unos segundos en encontrar el dato..." << std::endl;
	delay(1);

	for (int i = 0; i < list.Size(); ++i) {
		Empleado* empleado = list.Get(i);
		if (op == 1) {
			if (to_compare(name, empleado->GetName()) == 0) {
				empleado->Show();
				correcto = true;
				break;
			}
		}
		else {
			if (strfind(name, empleado->GetName()) == 0) {
				empleado->Show();
				correcto = true;
				break;
			}
		}
	}
	if (!correcto)
		std::cout << "El dato no se pudo encontrar. (Nota: intente probar la busqueda avanzada)" << std::endl;
}

void eliminar_nombre(LinkedList& list) {
	string name;
	std::cout << "Digite el nombre a eliminar: " << std::endl;
	std::cin.ignore();
	getline(std::cin, name);
	std::cout << "Esto puede tardar unos segundos en borrar el empleado..." << std::endl;
	delay(2);
	std::cout << "Esto puede tardar unos segundos en borrar el empleado.." << std::endl;
	delay(2);
	std::cout << "Esto puede tardar unos segundos en borrar el empleado..." << std::endl;
	delay(1);
	list.Remove(name);
}

void ingresar_empleado(LinkedList& list) {
	int antiguedad;
	long double salario;
	string name;
	std::cin.ignore();
	while (true) {
		std::cout << "Ingrese el nombre del empleado: " << std::endl;
		getline(std::cin, name);
		if (!list.Search(name))
			break;
		else {
			std::cout << "El empleado ya se encuentra en la lista" << std::endl;
			name = "";
		}
	}
	std::cout << "Ingrese el salario:" << std::endl;
	std::cin >> salario;

	std::cout << "Ingrese la antiguedad: " << std::endl;
	std::cin >> antiguedad;

	Empleado* empleado = new Empleado(name, salario, antiguedad);

	list.Insert(empleado);

}


int main() {
	LinkedList list;
	int op;
	mostrar();
	delay(2);
	while (true) {
		mostrar_menu();
		std::cout << "Ingrese una opcion: " << std::endl;
		std::cin >> op;
		switch (op)
		{
		case 1: {
			ingresar_empleado(list);
			system("pause");
			break;
		}
		case 2: {
			eliminar_nombre(list);
			system("pause");
			break;
		}
		case 3: {
			std::cout << "El promedio de los salarios de todos los empleados es: " << promedio_salario(list) << std::endl;
			system("pause");
			break;
		}
		case 4: {
			std::cout << "El porcentajes de salarios menor a 1M es de: " << porcentaje(list) << "%." << std::endl;
			system("pause");
			break;
		}
		case 5: {
			std::cout << "El empleado mas antiguo es: " << antiguo(list) << std::endl;
			system("pause");
			break;
		}
		case 6: {
			list.Show();
			system("pause");
			break;
		}
		case 7: {
			mostrar_datos(list);
			system("pause");
			break;
		}
		case 8: {
			std::cout << "Cerrando base de datos..." << std::endl;
			delay(2);
			std::cout << "Cerrando base de datos.." << std::endl;
			delay(2);
			std::cout << "Cerrada, vuelva pronto." << std::endl;
			system("pause");
			return 0;
		}
		default:
			std::cout << "Opcion incorrecta" << std::endl;
			break;
		}
		system("cls");
	}

	return 0;
}