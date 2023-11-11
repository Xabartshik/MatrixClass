#include "Matrix.h"
//���������� ��������� �������� double
double generate_random(double min, double max) {
    return (double)rand() / RAND_MAX * (max - min) + min;
}
//���������� ��������� ����� �������� double
double generate_random(int min, int max) {
    return round((double)rand() / RAND_MAX * (max - min) + min);
}
//����������� ��� �������� ������� � ��������
Matrix::Matrix(unsigned rows, unsigned cols)
{
    changeSize(rows, cols);
    detCreated = false;
}
//�����������. �������� �������
Matrix::Matrix(vector<vector<double>> newMatrix)
{
    matrix = newMatrix;
    setColNumber(newMatrix[0].size());
    setRowNumber(newMatrix.size());
    detCreated = false;
}
//������ �����������
Matrix::Matrix()
{
    detCreated = false;
}

//������ ��� �������
vector<vector<double>> Matrix::getMatrix() const
{
    return matrix;
}

//������ ��� �������
void Matrix::setMatrix(vector<vector<double>> newMatrix)
{
    matrix = newMatrix;
    setRowNumber(matrix.size());
    setColNumber(matrix[0].size());
}


//������ ��� ������
vector<double> Matrix::getRow(unsigned num) const
{
    vector<double> result = matrix[num];
    return result;
}
//������ ��� �������
vector<double> Matrix::getCol(unsigned num) const
{

    vector<double> result;
    for (unsigned i = 0; i < row; i++)
    {
        result.push_back(matrix[i][num]);
    }
    return result;
}
//������ ��� ������
void Matrix::setRow(unsigned num, vector<double> newRow)
{
    if (newRow.size() != col)
    {
        throw invalid_argument("�� ��������� ������� ����� ������� � ������-���������");
    }
    matrix[num] = newRow;

}
//������ ��� �������
void Matrix::setCol(unsigned num, vector<double> newCol)
{
    if (newCol.size() != row)
    {
        throw invalid_argument("�� ��������� ������� ������� ������� � �������-���������");
    }
    for (unsigned i = 0; i < row; i++)
    {
        setValue(i, num, newCol[i]);
    }
}






//������ ��� ����� �����
unsigned Matrix::getRowNumber() const
{
    return row;
}

//������ ��� ����� ��������
unsigned Matrix::getColNumber() const
{
    return col;
}

double Matrix::getDet() 
{
    if (detCreated == false)
    {
        det();
        return determinant;
    }
    else return determinant;
}

void Matrix::setDet(double newDet)
{
determinant = newDet;

}


//������ ��� ����� �����
void Matrix::setRowNumber(unsigned newRow)
{
    row = newRow;

}

//������ ��� ����� ��������
void Matrix::setColNumber(unsigned newCol)
{
    col = newCol;
}

void Matrix::changeSize(unsigned newRow, unsigned newCol)
{
    setRowNumber(newRow);
    setColNumber(newCol);
    matrix.resize(newRow, vector<double>(newCol, 0.0));
    for (unsigned i = 0; i < row; i++)
    {
        matrix[i].resize(newCol, 0.0);
    }
    detCreated = false;
}

// ��������� ���������� ���������� double, � �������� �� min �� max
void Matrix::fillMatrixRandom(double min, double max)
{
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] = generate_random(min, max);
        }
    }




}

// ��������� ���������� ������ ����������, � �������� �� min �� max
void Matrix::fillMatrixRandom(int min, int max)
{
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] = generate_random(min, max);
        }
    }




}

// ��������� ������� ����� ���������
void Matrix::fillMatrixValue(double value) 
{
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] = value;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �������� � ���������
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////
//���������� ��� �������, ��������� ���������� � �� �������, � ������� ������ ��������
void Matrix::sum(const Matrix& term1, const Matrix& term2)
{
    if ((term1.getColNumber() != term2.getColNumber()) || (term1.getRowNumber() != term2.getRowNumber()))
    {
        throw invalid_argument("�� ��������� ������� ������-����������");
    }
       
    changeSize(term1.getRowNumber(), term2.getColNumber());
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] = term1.getValue(i, j) + term2.getValue(i, j);
        }
    }
}
void Matrix::sum(const Matrix& term1)
{
    if ((term1.getColNumber() != getColNumber()) || (term1.getRowNumber() != getRowNumber()))
    {
        throw invalid_argument("�� ��������� ������� �������-��������� � ������� �������");
    }

    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] += term1.getValue(i, j);
        }
    }
}
//���������� ��� �������, ��������� ���������� � �� �������, � ������� ������ ��������
Matrix Matrix::operator +(const Matrix& term1) const
{
    if ((row != term1.getRowNumber()) || (col != term1.getColNumber()))
    {
        throw invalid_argument("�� ��������� ������� �������-��������� � �������-����������");
    }
    Matrix result(*this);
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            result.matrix[i][j] += term1.getValue(i, j);
        }
    }
    return result;
}

//���������� ��� �������, ��������� ���������� � �� �������, � ������� ������ ��������
void Matrix::operator +=(const Matrix& term1)
{
    if ((row != term1.getRowNumber()) || (col != term1.getColNumber()))
    {
        throw invalid_argument("�� ��������� ������� �������-��������� � �������-����������");
    }
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] += term1.getValue(i, j);
        }
    }
}
//�������� ��� �������, ��������� ���������� � �� �������, � ������� ������ ��������
Matrix Matrix::operator - (const Matrix& term1) const
{
    if ((row != term1.getRowNumber()) || (col != term1.getColNumber()))
    {
        throw invalid_argument("�� ��������� ������� �������-��������� � �������-����������");
    }
    Matrix result(*this);
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            result.matrix[i][j] -= term1.getValue(i, j);
        }
    }
    return result;
}
//�������� ��� �������, ��������� ���������� � �� �������, � ������� ������ ��������
void Matrix::operator -= (const Matrix& term1)
{
    if ((row != term1.getRowNumber()) || (col != term1.getColNumber()))
    {
        throw invalid_argument("�� ��������� ������� �������-��������� � �������-����������");
    }
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] -= term1.getValue(i, j);
        }
    }
}
//�������� ��� �������, ��������� ���������� � �� �������, � ������� ������ ��������
void Matrix::substract(const Matrix& term1, const Matrix& term2)
{
    if ((row != term1.getRowNumber()) || (col != term2.getColNumber()) || (row != term2.getRowNumber()) || (col != term1.getColNumber()))
    {
        throw invalid_argument("�� ��������� ������� ������-���������� ��� �������-����������");
    }
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] = term1.getValue(i, j) - term2.getValue(i, j);
        }
    }
}
//�������� ��� �������, ��������� ���������� � �� �������, � ������� ������ ��������
void Matrix::substract(const Matrix& term1)
{
    if ((row != term1.getRowNumber()) || (col != term1.getColNumber()))
    {
        throw invalid_argument("�� ��������� ������� �������-��������� � �������-����������");
    }
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] -= term1.getValue(i, j);
        }
    }
}
//��������� Value � �������, ��������� ���������� � �� �������, � ������� ������ ��������
void Matrix::sum(const Matrix& term1, double Value)
{
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] = term1.getValue(i, j) + Value;
        }
    }
}

Matrix Matrix::operator +(double Value) const {
    Matrix result(*this); // ������� ����� ������ ������� �� ������ �������� �������

    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            result.matrix[i][j] += Value; // ���������� �������� Value � ���������� �������
        }
    }

    return result; // ���������� ����� ������ �������
}


//��������� Value � �������, ��������� ���������� � �� �������, � ������� ������ ��������
void Matrix::operator +=(double Value)
{
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] += Value;
        }
    }
}
//��������� Value �� �������, ��������� ���������� � �� �������, � ������� ������ ��������
Matrix Matrix::operator - (double Value) const
{
    Matrix result(*this);
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            result.matrix[i][j] -= Value;
        }
    }
    return result;
}
//��������� Value �� �������, ��������� ���������� � �� �������, � ������� ������ ��������
void Matrix::operator -= (double Value)
{
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] -= Value;
        }
    }
}
//��������� Value �� �������, ��������� ���������� � �� �������, � ������� ������ ��������
void Matrix::substract(const Matrix& term1, double Value)
{
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] = term1.getValue(i, j) - Value;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//���������
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//�������� ������� term1 �� �������� value ��������. ��������� ������ � �������, ��� ��� ������ �����
void Matrix::mul(const Matrix& term1, double Value)
{
    setMatrix(term1.getMatrix());
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] = term1.getValue(i, j) * Value;
        }
    }
}
//�������� ������� �� �������� value ��������. ��������� ������ � �������, ��� ��� ������ �����
Matrix Matrix::operator *(double Value)const
{
    Matrix result(*this);
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            result.matrix[i][j] *= Value;
        }
    }
    return result;
}

//�������� ������� �� �������� value ��������. ��������� ������ � �������, ��� ��� ������ �����
void Matrix::operator *=(double Value)
{
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] *= Value;
        }
    }
}






//�������� ������� term1 �� ������� term2. ��������� ������ � �������, ��� ��� ������ �����
void Matrix::mul(const Matrix& term1, const Matrix& term2)
{
    if ((term1.getRowNumber() != term2.getColNumber()) || (term2.getRowNumber() != term1.getColNumber()))
    {
        throw invalid_argument("�� ��������� ������� ������-���������� ��� �������-����������");
    }
    vector<vector<double>> temp(term1.getColNumber(), vector<double>(term1.getColNumber(), 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                temp[i][j] += term1.getValue(i, k) * term2.getValue(k, j);
            }
        }
    }
    setMatrix(temp);
}
//�������� ������� ��  ������� term1. ��������� ������ � �������, ��� ��� ������ �����

Matrix Matrix::operator *(const Matrix& term1) const
{
    if ((term1.getRowNumber() != getColNumber()) || (getRowNumber() != term1.getColNumber()))
    {
        throw invalid_argument("�� ��������� ������� ������-���������� ��� �������-����������");
    }
    Matrix result(term1.getColNumber(), term1.getColNumber());
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                result.matrix[i][j] += getValue(i, k) * term1.getValue(k, j);
            }
        }
    }
    return result;
}

//�������� ������� ��  ������� term1. ��������� ������ � �������, ��� ��� ������ �����
void Matrix::operator *=(const Matrix& term1)
{
    if ((term1.getRowNumber() != getColNumber()) || (getRowNumber() != term1.getColNumber()))
    {
        throw invalid_argument("�� ��������� ������� ������-���������� ��� �������-����������");
    }
    vector<vector<double>> temp(term1.getColNumber(), vector<double>(term1.getColNumber(), 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                temp[i][j] += getValue(i, k) * term1.getValue(k, j);
            }
        }
    }
    setMatrix(temp);
}

//���������� �������� ������� �� ������
double Matrix::getValue(const double row, const double col) const
{
    return matrix[row][col];
}
//������������� ��������. ���������� ���� ������������
void Matrix::setValue(const double row, const double col, const double value)
{
    matrix[row][col] = value;
    detCreated = false;
}

// ������������� �������
void Matrix::transponse()
{
    vector<vector<double>> temp(getColNumber(), vector<double>(getRowNumber(), 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            temp[j][i] = getValue(i,j);
        }
    }
    setMatrix(temp);


}













//����� �������. 
void matrix_output(const Matrix & matrix)
{
    unsigned const width = 10;
    unsigned const precision = 5;

    unsigned n = matrix.getRowNumber();
    unsigned n1 = matrix.getColNumber();
    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0; j < n1; j++)
        {
            cout.width(width);
            cout.precision(precision);
            cout << right << matrix.getValue(i, j);
        }
        cout << endl;
    }
    cout << endl;
}
//������ ����
void fill_matrix_manually(vector<vector<double>>& matrix) {
    int n = matrix.size();
    int n1 = matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n1; j++) {
            cout << "������� �������� ��� A[" << i << "][" << j << "]: " << endl;
            cin >> matrix[i][j];
        }
    }
}


//�������� ������� � ������������� ���� ������� ������
void Matrix::diagonal()
{
    if (getRowNumber() != getColNumber())
    {
        throw invalid_argument("������� �� ����������.");
    }
    for (unsigned flag = 0; flag < row; flag++)
    {
        if (abs(matrix[flag][flag]) < 0.00001) {
            int m = flag + 1;
            do {
                if (abs(matrix[m][flag]) > 0.00001 || m > row) {
                    break;
                }
                m++;
            } while (true);

            for (int j = flag; j < row; j++) {
                swap(matrix[flag][j], matrix[m][j]);
            }
        }
        for (unsigned i = 0; i < row; i++)
        {
            for (unsigned j = flag + 1; j <  row; j++)
            {
                if ((i != flag))
                {
                    matrix[i][j] = (matrix[i][j] * matrix[flag][flag] - matrix[flag][j] * matrix[i][flag]) / matrix[flag][flag];
                }
            }
        }
        for (unsigned i = flag + 1; i < row; i++)
        {
            matrix[i][flag] = 0;
        }

        for (unsigned j = row - 1; j != flag; j--)//j >= flag
        {
            matrix[flag][j] /= matrix[flag][flag];
        }


    }
}



void Matrix::det()
{
    {
        int size = getColNumber();
        determinant = 0;

        // ������� ������ - ������� 2x2
        if (size == 2) {
            double newDet = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
            this->setDet(newDet);
            return;
        }

        // ��� ������� �������� ������ ������
        for (int i = 0; i < size; i++) {
            // ������� ���������� ��� ������ ������ � �������� �������
            Matrix subMatrix(size - 1, size - 1);
            for (int j = 1; j < size; j++) {
                int subMatrixColumn = 0;
                for (int k = 0; k < size; k++) {
                    if (k != i) {
                        subMatrix.setValue(j - 1, subMatrixColumn, matrix[j][k]);
                        subMatrixColumn++;
                    }
                }
            }
            // ���������� ��������� ������������ ���������� � ���������� � ������ ������������
            determinant += (i % 2 == 1 ? -1 : 1) * matrix[0][i] * subMatrix.getDet();
        }

    }
}

void Matrix::reverse()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = row; j < 2 * row; j++)
        {
            if (i == (j - row))
            {
                matrix[i].push_back(1);
            }
            else
            {
                matrix[i].push_back(0);
            }
        }
    }

    for (unsigned flag = 0; flag < row; flag++)
    {
        if (abs(matrix[flag][flag]) < 0.00001) {
            int m = flag + 1;
            do {
                if (abs(matrix[m][flag]) > 0.00001 || m > row) {
                    break;
                }
                m++;
            } while (true);

            for (int j = flag; j < 2 * row - 1; j++) {
                swap(matrix[flag][j], matrix[m][j]);
            }
        }
        for (unsigned i = 0; i < row; i++)
        {
            for (unsigned j = flag + 1; j < 2 * row; j++)
            {
                if ((i != flag))
                {
                    matrix[i][j] = (matrix[i][j] * matrix[flag][flag] - matrix[flag][j] * matrix[i][flag]) / matrix[flag][flag];
                }
            }
        }
        for (unsigned i = 0; i < row; i++)
        {
            if (i != flag)
                matrix[i][flag] = 0;
        }
        for (unsigned j = 2 * row - 1; j != flag; j--)//j >= flag
        {
            matrix[flag][j] = matrix[flag][j] / matrix[flag][flag];
        }
    }
    vector<vector<double>> output;
    output.resize(row);
    for (int i = 0; i < row; i++)
    {
        for (int j = row; j < 2 * row; j++)
        {
            output[i].push_back(matrix[i][j]);
        }
    }
    matrix = output;
}

vector<double> Matrix::solveGauss () const
{
    Matrix result = *this;
    for (unsigned flag = 0; flag < row; flag++)
    {
        if (abs(result.getValue(flag, flag) < 0.00001)) 
        {
            int m = flag + 1;
            do {
                if (abs(result.getValue(m, flag)) > 0.00001 || m > row) {
                    break;
                }
                m++;
            } 
            while (true);
            swap(result.matrix[flag], result.matrix[m]);
        }
        //////////////////�������
        for (unsigned i = 0; i < row; i++)
        {
            for (unsigned j = flag+1; j < col; j++)
            {
                if ((i != flag))
                {
                    result.matrix[i][j] = (result.matrix[i][j] * result.matrix[flag][flag] - result.matrix[flag][j] * result.matrix[i][flag]) / result.matrix[flag][flag];;
                }
            }
        }
        /////////////////////////��������� �������
        for (unsigned i = 0; i < row; i++)
        {
            if (i != flag)
            {
                result.setValue(i, flag, 0);
            }
        }
        ///////////////������� ������
        for (unsigned j = row; j != flag-1; j--)//j >= flag
        {
            result.setValue(flag, j, (result.getValue(flag, j) / result.getValue(flag,flag)));
        }

    }
    return result.getCol(row);
}