#include <iostream>
#include <math.h>
#include <Windows.h>
using namespace std;

enum signs {
	PLUS = '+',
	MINUS = '-',
	MULT = '*',
	DIVIS = '/'
};

double addition(double a, double b) { return a + b; }

double subtraction(double a, double b) { return a - b; }

double multiplication(double a, double b) { return a * b; }

double division(double a, double b) { return a / b; }


bool validator_oper(double a, double b, char chr) {
	if (chr =='/' && b == 0) {
		return 0;
	}
	return 1;
}



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double num_a, num_b;
	double result;
	char chr;
	bool finish = false;
	cout << "Здравствуйте! Я - простейший калкулятор" << endl;
	
	while (!finish) {
		cout << "Введите первое число: ";
		cin >> num_a;
		do {
			cout << "Введите оператор (+, -, *, /): ";
			cin >> chr;
		} while (chr != PLUS && chr != MINUS && chr != MULT && chr != DIVIS);
		
		cout << "Введите второе число: ";
		cin >> num_b;

		if (validator_oper(num_a, num_b, chr)) {
			switch (chr) {
			case PLUS:
				result = addition(num_a, num_b);
				break;
			case MINUS:
				result = subtraction(num_a, num_b);
				break;
			case MULT:
				result = multiplication(num_a, num_b);
				break;
			case DIVIS:
				result = division(num_a, num_b);
				break;
			}
			cout <<"\n"<< num_a<<chr<<num_b<<" = "<<result<<endl;
			continue;
		}
		else { 
			cout << "Недопустимая операция. Повторите попытку"<<endl;
			continue;
		}
	}
	
	
	return 0;
}
