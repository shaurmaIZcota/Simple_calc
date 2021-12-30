#include <iostream>
#include <math.h>
#include <Windows.h>
#include <string>

enum signs {
	PLUS = '+',
	MINUS = '-',
	MULT = '*',
	DIVIS = '/',
	EXPO = '^',
	SQRT = 's',
	FACT = '!'
};

double addition(double a, double b) { return a + b; }

double subtraction(double a, double b) { return a - b; }

double multiplication(double a, double b) { return a * b; }

double division(double a, double b) { return a / b; }

double exponentiation(double a, double b) { return pow(a, b); }


bool validator_oper(double a, double b, char chr) {
	if (chr =='/' && b == 0) {
		return 0;
	}
	return 1;
}

bool validator_oper2(double a, char chr) {
	if (a < 0) {
		return 0;
	}
	if (chr == '!' && a != round(a)) {
		return 0;
	}
	return 1;
}

double factor(double N)
{
	int F = 1;
	for (int i = 1; i <= N; i++) {
		F *= i;
	}
	return F;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double num_a, num_b;
	double result;
	char chr;
	bool finish = false;
	std::cout << "Здравствуйте! Я - простейший калкулятор" << std::endl;
	std::string in;
	while (!finish) {
		do {
			std::cout << "Введите первое число: ";
			std::cin >> in;
		}while (in.find(',') != std::string::npos);	
		num_a = atof(in.c_str());
		do {
			std::cout << "Введите оператор (+, -, *, /, ^, !, s): ";
			std::cin >> chr;
			
		} while (chr != PLUS && chr != MINUS && chr != MULT && chr != DIVIS && chr != EXPO && chr!=FACT && chr!=SQRT);
		if (chr != FACT && chr != SQRT) {		

			do {
				std::cout << "Введите второе число: ";
				std::cin >> in;
			} while (in.find(',') != std::string::npos);
			num_b = atof(in.c_str());

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
				case EXPO:
					result = exponentiation(num_a, num_b);
				}
				std::cout <<"\n"<< num_a<<chr<<num_b<<" = "<<result<< std::endl;
				continue;
			}
			else { 
				std::cout << "Недопустимая операция. Повторите попытку"<< std::endl;
				continue;
			}
		}
		else {
			if (validator_oper2(num_a, chr)) {
				switch (chr) {
				case FACT:
					result = factor(num_a);
					break;
				case SQRT:
					result = sqrt(num_a);
					break;
				}
				std::cout << "\n" << chr << num_a << " = " << result << std::endl;
				continue;
			}
			else {
				std::cout << "Недопустимая операция. Повторите попытку" << std::endl;
				continue;
			}
		}
		
	}
	
	
	return 0;
}
