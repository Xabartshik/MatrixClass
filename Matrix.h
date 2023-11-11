#pragma once
#include <cstdlib>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;
class Matrix
{
private:
	//����� ����� � ��������
	unsigned row, col;
	//������� �������������� �����
	vector<vector<double>> matrix;
	//���������� ���������� ��� ������������. ���� ��� false, �� ������������ ���������, ���� true, �� ��������� �� ����������
	bool detCreated;
	//������������
	double determinant;



public:
	//����������� ��� �������� ������� � ��������
	Matrix(unsigned rows, unsigned cols);
	//������ �����������
	Matrix();
	//�����������. �������� �������
	Matrix(vector<vector<double>> newMatrix);
	//������ ��� �������
	vector<vector<double>> getMatrix() const;
	//������ ��� �������
	void setMatrix(vector<vector<double>> newMatrix);

	void changeSize(unsigned newRow, unsigned newCol);
	//������ ��� ����� �����
	unsigned getRowNumber() const;
	//������ ��� ����� ��������
	unsigned getColNumber() const;
	//������ ��� ����� �����
	void setRowNumber(unsigned newRow);
	//������ ��� ����� ��������
	void setColNumber(unsigned newCol);

	// ��������� ���������� ���������� double, � �������� �� min �� max
	void fillMatrixRandom(double min, double max);
	// ��������� ���������� ������ ����������, � �������� �� min �� max
	void fillMatrixRandom(int min, int max);
	// ��������� ������� ����� ���������
	void fillMatrixValue(double Value);
	//������. ������������� �������� ������������
	void setDet(double newDet);
	//������� �������� ������������
	double getDet();


	//������ ��� ������
	vector<double> getRow(unsigned num) const;
	//������ ��� �������
	vector<double> getCol(unsigned num) const;
	//������ ��� ������
	void setRow(unsigned num, vector<double> newRow);
	//������ ��� �������
	void setCol(unsigned num, vector<double> newCol);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//���������� ��� �������, ��������� ���������� � �� �������, � ������� ������ ��������
	void sum(const Matrix& term1, const Matrix& term2);
	//���������� ��� ������� -- �������� � ��������, ��������� ���������� � �� �������, � ������� ������ ��������
	void sum(const Matrix& term1);
	//���������� ��� ������� -- �������� � ��������, ��������� ���������� � �� �������, � ������� ������ ��������
	Matrix operator + (const Matrix& term1) const;
	//���������� ��� ������� -- �������� � ��������, ��������� ���������� � �� �������, � ������� ������ ��������
	void operator += (const Matrix& term1);
	//�������� ��� �������, ��������� ���������� � �� �������, � ������� ������ ��������
	void substract(const Matrix& term1, const Matrix& term2);
	//�������� ��� �������, ��������� ���������� � �� �������, � ������� ������ ��������
	void substract(const Matrix& term1);
	//�������� ��� �������, ��������� ���������� � �� �������, � ������� ������ ��������
	Matrix operator - (const Matrix& term1) const;
	//�������� ��� �������, ��������� ���������� � �� �������, � ������� ������ ��������
	void operator -= (const Matrix& term1);
	//��������� Value � �������, ��������� ���������� � �� �������, � ������� ������ ��������
	void sum(const Matrix& term1, double Value);
	//��������� Value � �������, ��������� ���������� � �� �������, � ������� ������ ��������
	Matrix operator +(double Value) const;
	//��������� Value � �������, ��������� ���������� � �� �������, � ������� ������ ��������
	void operator += (double Value);
	//��������� Value �� �������, ��������� ���������� � �� �������, � ������� ������ ��������
	void substract(const Matrix& term1, double Value);
	//��������� Value �� �������, ��������� ���������� � �� �������, � ������� ������ ��������
	Matrix operator - (const double Value) const;
	//��������� Value �� �������, ��������� ���������� � �� �������, � ������� ������ ��������
	void operator -= (const double Value);
	//���������� �������� ������� � ������

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	double getValue(const double row, const double col) const;
	void setValue(const double row, const double col, const double value);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//���������
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//�������� ������� term1 �� �������� value ��������. ��������� ������ � �������, ��� ��� ������ �����
	void mul(const Matrix& term1, double Value);
	//�������� ������� �� �������� value ��������. ��������� ������ � �������, ��� ��� ������ �����
	Matrix operator * (double Value) const;
	//�������� ������� �� �������� value ��������. ��������� ������ � �������, ��� ��� ������ �����
	void operator *= (double Value);
	//�������� ������� term1 �� ������� term2. ��������� ������ � �������, ��� ��� ������ �����
	void mul(const Matrix& term1, const Matrix& term2);
	//�������� ������� ��  ������� term1. ��������� ������ � �������, ��� ��� ������ �����
	Matrix operator * (const Matrix& term1) const;
	//�������� ������� ��  ������� term1. ��������� ������ � �������, ��� ��� ������ �����
	void operator *= (const Matrix& term1);





	// ������������� �������
	void transponse();
	//�������� ������� � ������������� ���� ������� ������
	void diagonal();
	// ��������� ������������. �������� ���� ������������ �� True
	void det();
	//�������� �������� �������
	void reverse();
	//������ ������� �������
	vector<double> solveGauss() const;
};

//���������� ��������� �������� double
double generate_random(double min, double max);
//���������� ��������� ����� �������� double
double generate_random(int min, int max);















//����� �������. 
void matrix_output(const Matrix & matrix);
//������ ����
void fill_matrix_manually(vector<vector<double>>& matrix);