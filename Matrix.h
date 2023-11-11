#pragma once
#include <cstdlib>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;
class Matrix
{
private:
	//Число строк и столбцов
	unsigned row, col;
	//Матрица действительных чисел
	vector<vector<double>> matrix;
	//Логическая переменная для определителя. Если она false, то определитель считается, если true, то достается из переменной
	bool detCreated;
	//Определитель
	double determinant;



public:
	//Конструктор для создания матрицы с размером
	Matrix(unsigned rows, unsigned cols);
	//Пустой конструктор
	Matrix();
	//Конструктор. Получает матрицу
	Matrix(vector<vector<double>> newMatrix);
	//Геттер для матрицы
	vector<vector<double>> getMatrix() const;
	//Сеттер для матрицы
	void setMatrix(vector<vector<double>> newMatrix);

	void changeSize(unsigned newRow, unsigned newCol);
	//Геттер для числа строк
	unsigned getRowNumber() const;
	//Геттер для числа столбцов
	unsigned getColNumber() const;
	//Сеттер для числа строк
	void setRowNumber(unsigned newRow);
	//Сеттер для числа столбцов
	void setColNumber(unsigned newCol);

	// Заполняет случайными значениями double, в пределах от min до max
	void fillMatrixRandom(double min, double max);
	// Заполняет случайными целыми значениями, в пределах от min до max
	void fillMatrixRandom(int min, int max);
	// Заполняет матрицу одним значением
	void fillMatrixValue(double Value);
	//Сеттер. Принудительно изменяет определитель
	void setDet(double newDet);
	//Геттера возврата определителя
	double getDet();


	//Геттер для строки
	vector<double> getRow(unsigned num) const;
	//Геттер для столбца
	vector<double> getCol(unsigned num) const;
	//Сеттер для строки
	void setRow(unsigned num, vector<double> newRow);
	//Сеттер для столбца
	void setCol(unsigned num, vector<double> newCol);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Складывает две матрицы, результат записывает в ту матрицу, в которой вызван оператор
	void sum(const Matrix& term1, const Matrix& term2);
	//Складывает две матрицы -- исходную и заданную, результат записывает в ту матрицу, в которой вызван оператор
	void sum(const Matrix& term1);
	//Складывает две матрицы -- исходную и заданную, результат записывает в ту матрицу, в которой вызван оператор
	Matrix operator + (const Matrix& term1) const;
	//Складывает две матрицы -- исходную и заданную, результат записывает в ту матрицу, в которой вызван оператор
	void operator += (const Matrix& term1);
	//Вычитает две матрицы, результат записывает в ту матрицу, в которой вызван оператор
	void substract(const Matrix& term1, const Matrix& term2);
	//Вычитает две матрицы, результат записывает в ту матрицу, в которой вызван оператор
	void substract(const Matrix& term1);
	//Вычитает две матрицы, результат записывает в ту матрицу, в которой вызван оператор
	Matrix operator - (const Matrix& term1) const;
	//Вычитает две матрицы, результат записывает в ту матрицу, в которой вызван оператор
	void operator -= (const Matrix& term1);
	//Добавляет Value к матрице, результат записывает в ту матрицу, в которой вызван оператор
	void sum(const Matrix& term1, double Value);
	//Добавляет Value к матрице, результат записывает в ту матрицу, в которой вызван оператор
	Matrix operator +(double Value) const;
	//Добавляет Value к матрице, результат записывает в ту матрицу, в которой вызван оператор
	void operator += (double Value);
	//Вычитыает Value из матрицы, результат записывает в ту матрицу, в которой вызван оператор
	void substract(const Matrix& term1, double Value);
	//Вычитыает Value из матрицы, результат записывает в ту матрицу, в которой вызван оператор
	Matrix operator - (const double Value) const;
	//Вычитыает Value из матрицы, результат записывает в ту матрицу, в которой вызван оператор
	void operator -= (const double Value);
	//Возвращает значение матрицы в ячейке

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	double getValue(const double row, const double col) const;
	void setValue(const double row, const double col, const double value);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//УМНОЖЕНИЯ
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Умножает матрицу term1 на значение value скалярно. Результат уходит в матрицу, где был вызван метод
	void mul(const Matrix& term1, double Value);
	//Умножает матрицу на значение value скалярно. Результат уходит в матрицу, где был вызван метод
	Matrix operator * (double Value) const;
	//Умножает матрицу на значение value скалярно. Результат уходит в матрицу, где был вызван метод
	void operator *= (double Value);
	//Умножает матрицу term1 на матрицу term2. Результат уходит в матрицу, где был вызван метод
	void mul(const Matrix& term1, const Matrix& term2);
	//Умножает матрицу на  матрицу term1. Результат уходит в матрицу, где был вызван метод
	Matrix operator * (const Matrix& term1) const;
	//Умножает матрицу на  матрицу term1. Результат уходит в матрицу, где был вызван метод
	void operator *= (const Matrix& term1);





	// Транспонирует матрицу
	void transponse();
	//Приводит матрицу к диагональному виду методом Гаусса
	void diagonal();
	// Вычисляет определитель. Изменяет флаг определителя на True
	void det();
	//Получает обратную матрицу
	void reverse();
	//Решает матрицу Гауссом
	vector<double> solveGauss() const;
};

//Возвращает случайное значение double
double generate_random(double min, double max);
//Возвращает случайное целое значение double
double generate_random(int min, int max);















//Вывод матрицы. 
void matrix_output(const Matrix & matrix);
//Ручной ввод
void fill_matrix_manually(vector<vector<double>>& matrix);