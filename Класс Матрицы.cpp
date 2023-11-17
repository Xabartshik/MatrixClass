#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <windows.h>
#include <math.h>
#include "Matrix.h"

///Накосячил -- Ошлаков Данил. Все ошибки сделаны из-за грусти или невнимательности, права не зарезервированы
int main()
{

	setlocale(LC_ALL, "");

	Matrix test;
	Matrix test2;
	Matrix test3;
	Matrix test4;
	Matrix test5;
vector<vector<double>> test_mat = { {1.0, 2.0, 3.0},
									{4.0, 5.0, 6.0},
									{2, 5, 9}, };
vector<vector<double>> test_mat2 = { {1.0, 2.0},
									 {4.0, 5.0},
									 {7.0, 8.0} };
vector<vector<double>> test_mat3 = {
		{1, 4, 7},
		{2, 5, 8},

};

vector<vector<double>> test_mat4 = {
		{3, 2, -5, -1},
		{2, -1, 3, 13},
		{1, 2, -1, 9},
};
vector<vector<double>> test_mat5 = {
		{3, 6, 9},
		{4, 7, 10},

};
vector<double> output;
double d_output;

	test.setMatrix(test_mat);
	test2.setMatrix(test_mat2);
	test3.setMatrix(test_mat3);
	test4.setMatrix(test_mat4);
	test5.setMatrix(test_mat5);
	//test.changeSize(5, 5);
	testClass();


	//Ассерты


	return 0;
}