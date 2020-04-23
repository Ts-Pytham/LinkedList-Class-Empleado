#include <iostream>
#include <iomanip>
#include "func_extras.h"
using std::string;

class Empleado {
	private:
		string nombre;
		long double salario;
		int antiguedad;
	public:
		Empleado* sig;
		Empleado() {};
		Empleado(string nombre, long double salario, int antiguedad);
		void Show();
		int GetAntiguedad() { return antiguedad; }
		long double GetSalario() { return salario; }
		string GetName() { return nombre; }

};


Empleado::Empleado(string nombre, long double salario, int antiguedad) {
	this->nombre = nombre;
	this->salario = salario;
	this->antiguedad = antiguedad;
}

void Empleado::Show() {
	std::cout << "Empleado: " << this->nombre << "\nSalario: " << std::fixed << std::setprecision(3) << this->salario << "\nAntiguedad: " << this->antiguedad << std::endl << std::endl;
}
class LinkedList {
	private:
		Empleado* new_node = NULL;
	public:
		bool IsEmpty();
		void Insert(Empleado* data);
		void Remove(string name);
		int Size();
		void Show();
		bool Search(string name);
		Empleado* Get(int pos);

};


bool LinkedList::IsEmpty() {
	return new_node == NULL;
}
void LinkedList::Insert(Empleado* data) {
	if (IsEmpty())
		new_node = data;
	else {
		Empleado* p = new_node;
		while (p->sig != NULL)
			p = p->sig;

		p->sig = data;
	}
}

void LinkedList::Remove(string name) {
	if (!IsEmpty()) {
		Empleado* p = new_node;
		Empleado* ant = NULL;
		while ((p != NULL) && (to_compare(p->GetName(), name) != 0)) {
			ant = p;
			p = p->sig;
		}
		if (p == NULL)
			std::cout << "El valor no se encuentra en la lista. " << std::endl;
		else if (ant == NULL) {
			new_node = new_node->sig;
			std::cout << "Se elimino correctamente el nombre: " << name << std::endl;
			delete p;
		}
		else {
			ant->sig = p->sig;
			std::cout << "Se elimino correctamente el nombre: " << name << std::endl;
			delete p;
		}

	}
}
int LinkedList::Size() {
	if (IsEmpty()) {
		return 0;
	}
	else {
		int i = 0;
		Empleado* p = new_node;
		while (p != NULL) {
			p = p->sig;
			++i;
		}
		return i;
	}
}


void LinkedList::Show() {
	if (!IsEmpty()) {
		Empleado* p = new_node;
		while (p != NULL) {
			p->Show();
			p = p->sig;
		}
	}
}

bool LinkedList::Search(string name) {
	if (!IsEmpty()) {
		Empleado* p = new_node;
		while (p != NULL) {
			if (to_compare(name, p->GetName()) == 0)
				return true;
			p = p->sig;
		}
	}
	return false;
}
Empleado* LinkedList::Get(int pos) {
	if (pos < Size()) {
		Empleado* p = new_node;
		int i = 0;
		while (p != NULL) {
			if (pos == i)
				return p;
			++i;
			p = p->sig;
		}
	}
	std::cout << "No se encontro al empleado" << std::endl;
	return NULL;

}
