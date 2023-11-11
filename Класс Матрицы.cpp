#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <math.h>
#include "Matrix.h"

///Накосячил -- Ошлаков Данил. Все ошибки сделаны из-за грусти или невнимательности, права не зарезервированы
int main()
{
	SetConsoleCP(1251);//Штука чинит кодировку
	SetConsoleOutputCP(1251);
	Matrix test;
	Matrix test2;
	Matrix test3;
	Matrix test4;
vector<vector<double>> test_mat = { {1.0, 2.0, 3.0},
									{4.0, 5.0, 6.0} };
vector<vector<double>> test_mat2 = { {1.0, 2.0},
									 {4.0, 5.0},
									 {7.0, 8.0} };
vector<vector<double>> test_mat3 = {
		{1, 2, 0},
		{0, 1, 2},

};
vector<vector<double>> test_mat4 = {
		{3, 2, -5, -1},
		{2, -1, 3, 13},
		{1, 2, -1, 9},
};
vector<double> output;
	//fill_matrix_manually(test_mat);
	//test_mat.resize(4, vector<double>(4));
	test.setMatrix(test_mat);
	test2.setMatrix(test_mat2);
	test3.setMatrix(test_mat3);
	test4.setMatrix(test_mat4);
	//test.changeSize(5, 5);
	try 
	{
		output=test4.solveGauss();
		matrix_output(test4);
	}
	catch ( invalid_argument e ) {
		cout << e.what() << endl;
	}




	return 0;
}