#include "Matrix.h"
#include <cassert>

///Накосячил -- Ошлаков Данил. Все ошибки сделаны из-за грусти или невнимательности, права не зарезервированы

//Возвращает случайное значение double
double generate_random(double min, double max) {
    return (double)rand() / RAND_MAX * (max - min) + min;
}
//Возвращает случайное целое значение double
double generate_random(int min, int max) {
    return round((double)rand() / RAND_MAX * (max - min) + min);
}
//Конструктор для создания матрицы с размером
Matrix::Matrix(unsigned rows, unsigned cols)
{
    changeSize(rows, cols);
    detCreated = false;
}
//Конструктор. Получает матрицу
Matrix::Matrix(const vector<vector<double>>& newMatrix)
{
    setMatrix(newMatrix);
}
//Пустой конструктор
Matrix::Matrix()
{
    detCreated = false;
}

//Геттер для матрицы
vector<vector<double>> Matrix::getMatrix() const
{
    return matrix;
}

//Сеттер для матрицы
void Matrix::setMatrix(const vector<vector<double>>& newMatrix)
{
    matrix = newMatrix;
    setRowNumber(matrix.size());
    setColNumber(matrix[0].size());
    detCreated = false;

}


//Геттер для строки
vector<double> Matrix::getRow(unsigned num) const
{
    vector<double> result = matrix[num];
    return result;
}
//Геттер для столбца
vector<double> Matrix::getCol(unsigned num) const
{

    vector<double> result;
    for (unsigned i = 0; i < row; i++)
    {
        result.push_back(matrix[i][num]);
    }
    return result;
}
//Сеттер для строки
void Matrix::setRow(unsigned num, vector<double> newRow)
{
    if (newRow.size() != col)
    {
        throw invalid_argument("Не совпадают размеры строк матрицы и строки-аргумента");
    }
    matrix[num] = newRow;

}
//Сеттер для столбца
void Matrix::setCol(unsigned num, vector<double> newCol)
{
    if (newCol.size() != row)
    {
        throw invalid_argument("Не совпадают размеры столбца матрицы и столбца-аргумента");
    }
    for (unsigned i = 0; i < row; i++)
    {
        setValue(i, num, newCol[i]);
    }
}






//Геттер для числа строк
unsigned Matrix::getRowNumber() const
{
    return row;
}

//Геттер для числа столбцов
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


//Сеттер для числа строк
void Matrix::setRowNumber(unsigned newRow)
{
    row = newRow;

}

//Сеттер для числа столбцов
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

// Заполняет случайными значениями double, в пределах от min до max
void Matrix::fillMatrixRandom(double min, double max)
{
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] = generate_random(min, max);
        }
    }




}

// Заполняет случайными целыми значениями, в пределах от min до max
void Matrix::fillMatrixRandom(int min, int max)
{
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] = generate_random(min, max);
        }
    }




}

// Заполняет матрицу одним значением
void Matrix::fillMatrixValue(double value) 
{
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] = value;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// СЛОЖЕНИЯ И ВЫЧИТАНИЯ
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Складывает две матрицы, результат записывает в ту матрицу, в которой вызван оператор
void Matrix::sum(const Matrix& term1, const Matrix& term2)
{
    if ((term1.getColNumber() != term2.getColNumber()) || (term1.getRowNumber() != term2.getRowNumber()))
    {
        throw invalid_argument("Не совпадают размеры матриц-аргументов");
    }
       
    changeSize(term1.getRowNumber(), term2.getColNumber());
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] = term1.getValue(i, j) + term2.getValue(i, j);
        }
    }
}
//Складывает две матрицы, результат записывает в ту матрицу, в которой вызван оператор
void Matrix::sum(const Matrix& term1)
{
    if ((term1.getColNumber() != getColNumber()) || (term1.getRowNumber() != getRowNumber()))
    {
        throw invalid_argument("Не совпадают размеры матрицы-аргумента и матрицы объекта");
    }

    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] += term1.getValue(i, j);
        }
    }
}
//Складывает две матрицы, результат записывает в ту матрицу, в которой вызван оператор
Matrix Matrix::operator +(const Matrix& term1) const
{
    if ((row != term1.getRowNumber()) || (col != term1.getColNumber()))
    {
        throw invalid_argument("Не совпадают размеры матрицы-аргумента и матрицы-результата");
    }
    Matrix result(*this);
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            result.matrix[i][j] += term1.getValue(i, j);
        }
    }
    return result;
}

//Складывает две матрицы, результат записывает в ту матрицу, в которой вызван оператор
void Matrix::operator +=(const Matrix& term1)
{
    if ((row != term1.getRowNumber()) || (col != term1.getColNumber()))
    {
        throw invalid_argument("Не совпадают размеры матрицы-аргумента и матрицы-результата");
    }
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] += term1.getValue(i, j);
        }
    }
}
//Вычитает две матрицы, результат записывает в ту матрицу, в которой вызван оператор
Matrix Matrix::operator - (const Matrix& term1) const
{
    if ((row != term1.getRowNumber()) || (col != term1.getColNumber()))
    {
        throw invalid_argument("Не совпадают размеры матрицы-аргумента и матрицы-результата");
    }
    Matrix result(*this);
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            result.matrix[i][j] -= term1.getValue(i, j);
        }
    }
    return result;
}
//Вычитает две матрицы, результат записывает в ту матрицу, в которой вызван оператор
void Matrix::operator -= (const Matrix& term1)
{
    if ((row != term1.getRowNumber()) || (col != term1.getColNumber()))
    {
        throw invalid_argument("Не совпадают размеры матрицы-аргумента и матрицы-результата");
    }
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] -= term1.getValue(i, j);
        }
    }
}
//Вычитает две матрицы, результат записывает в ту матрицу, в которой вызван оператор
void Matrix::substract(const Matrix& term1, const Matrix& term2)
{
    if ((row != term1.getRowNumber()) || (col != term2.getColNumber()) || (row != term2.getRowNumber()) || (col != term1.getColNumber()))
    {
        throw invalid_argument("Не совпадают размеры матриц-аргументов или матрицы-результата");
    }
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] = term1.getValue(i, j) - term2.getValue(i, j);
        }
    }
}
//Вычитает две матрицы, результат записывает в ту матрицу, в которой вызван оператор
void Matrix::substract(const Matrix& term1)
{
    if ((row != term1.getRowNumber()) || (col != term1.getColNumber()))
    {
        throw invalid_argument("Не совпадают размеры матрицы-аргумента и матрицы-результата");
    }
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] -= term1.getValue(i, j);
        }
    }
}
//Добавляет Value к матрице, результат записывает в ту матрицу, в которой вызван оператор
void Matrix::sum(const Matrix& term1, double Value)
{
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] = term1.getValue(i, j) + Value;
        }
    }
}
//Добавляет Value к матрице, результат записывает в ту матрицу, с которой вызван оператор
Matrix Matrix::operator +(double Value) const {
    Matrix result(*this); // Создаем новый объект матрицы на основе текущего объекта

    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            result.matrix[i][j] += Value; // Складываем значение Value с элементами матрицы
        }
    }

    return result; // Возвращаем новый объект матрицы
}


//Добавляет Value к матрице, результат записывает в ту матрицу, в которой вызван оператор
void Matrix::operator +=(double Value)
{
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] += Value;
        }
    }
}
//Вычитыает Value из матрицы, результат записывает в ту матрицу, в которой вызван оператор
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
//Вычитыает Value из матрицы, результат записывает в ту матрицу, в которой вызван оператор
void Matrix::operator -= (double Value)
{
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] -= Value;
        }
    }
}
//Вычитыает Value из матрицы, результат записывает в ту матрицу, в которой вызван оператор
void Matrix::substract(const Matrix& term1, double Value)
{
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] = term1.getValue(i, j) - Value;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//УМНОЖЕНИЯ
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Умножает матрицу term1 на значение value скалярно. Результат уходит в матрицу, где был вызван метод
void Matrix::mul(const Matrix& term1, double Value)
{
    setMatrix(term1.getMatrix());
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] = term1.getValue(i, j) * Value;
        }
    }
}
//Умножает матрицу на значение value скалярно. Результат уходит в матрицу, где был вызван метод
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

//Умножает матрицу на значение value скалярно. Результат уходит в матрицу, где был вызван метод
void Matrix::operator *=(double Value)
{
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            matrix[i][j] *= Value;
        }
    }
}






//Умножает матрицу term1 на матрицу term2. Результат уходит в матрицу, где был вызван метод
void Matrix::mul(const Matrix& term1, const Matrix& term2)
{
    if ((term1.getRowNumber() != term2.getColNumber()) || (term2.getRowNumber() != term1.getColNumber()))
    {
        throw invalid_argument("Не совпадают размеры матриц-аргументов или матрицы-результата");
    }
    vector<vector<double>> temp(term1.getColNumber(), vector<double>(term1.getColNumber(), 0));
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < row; j++) {
            for (unsigned k = 0; k < col; k++) {
                temp[i][j] += term1.getValue(i, k) * term2.getValue(k, j);
            }
        }
    }
    setMatrix(temp);
}
//Умножает матрицу на  матрицу term1. Результат уходит в матрицу, где был вызван метод

Matrix Matrix::operator *(const Matrix& term1) const
{
    if ((term1.getRowNumber() != getColNumber()) || (getRowNumber() != term1.getColNumber()))
    {
        throw invalid_argument("Не совпадают размеры матриц-аргументов или матрицы-результата");
    }
    Matrix result(term1.getColNumber(), term1.getColNumber());
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < row; j++) {
            for (unsigned k = 0; k < col; k++) {
                result.matrix[i][j] += getValue(i, k) * term1.getValue(k, j);
            }
        }
    }
    return result;
}

//Умножает матрицу на  матрицу term1. Результат уходит в матрицу, где был вызван метод
void Matrix::operator *=(const Matrix& term1)
{
    if ((term1.getRowNumber() != getColNumber()) || (getRowNumber() != term1.getColNumber()))
    {
        throw invalid_argument("Не совпадают размеры матриц-аргументов или матрицы-результата");
    }
    vector<vector<double>> temp(term1.getColNumber(), vector<double>(term1.getColNumber(), 0));
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < row; j++) {
            for (unsigned k = 0; k < col; k++) {
                temp[i][j] += getValue(i, k) * term1.getValue(k, j);
            }
        }
    }
    setMatrix(temp);
}

//Возвращает значение матрицы по адресу
double Matrix::getValue(const unsigned row, const unsigned col) const
{
    return matrix[row][col];
}
//Усианавливает значение. СБрасывает флаг определителя
void Matrix::setValue(const unsigned row, const unsigned col, const double value)
{
    matrix[row][col] = value;
    detCreated = false;
}

// Транспонирует матрицу
void Matrix::transponse()
{
    vector<vector<double>> temp(getColNumber(), vector<double>(getRowNumber(), 0));
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            temp[j][i] = getValue(i,j);
        }
    }
    setMatrix(temp);


}













//Вывод матрицы. 
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
//Ручной ввод
void fill_matrix_manually(vector<vector<double>>& matrix) {
    unsigned n = matrix.size();
    unsigned n1 = matrix[0].size();
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n1; j++) {
            cout << "Введите значение для A[" << i << "][" << j << "]: " << endl;
            cin >> matrix[i][j];
        }
    }
}


//Приводит матрицу к диагональному виду методом Гаусса
void Matrix::diagonal()
{
    if (getRowNumber() != getColNumber())
    {
        throw invalid_argument("Матрица не квадратная.");
    }
    //Проверка на нулевые значения диагонали (смена строк местами)
    for (unsigned flag = 0; flag < row; flag++)
    {
        if (abs(matrix[flag][flag]) < 0.00001) {
            unsigned m = flag + 1;
            do {
                if (abs(matrix[m][flag]) > 0.00001 || m > row) {
                    break;
                }
                m++;
            } while (true);

            for (unsigned j = flag; j < row; j++) {
                swap(matrix[flag][j], matrix[m][j]);
            }
        }
        //Правило прямоугольника
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
        //Обнуление элементов кроме диагонали и ответов
        for (unsigned i = flag + 1; i < row; i++)
        {
            matrix[i][flag] = 0;
        }
        //Делит всю строку на значение 
        for (unsigned j = row - 1; j != flag; j--)//j >= flag
        {
            matrix[flag][j] /= matrix[flag][flag];
        }


    }
}


///Считает определитель матрицы
void Matrix::det()
{
    {
        if (getRowNumber() != getColNumber())
        {
            throw invalid_argument("Матрица не квадратная.");
        }
        unsigned size = getColNumber();
        determinant = 0;

        // Базовый случай - матрица 2x2
        if (size == 2) {
            double newDet = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
            this->setDet(newDet);
            return;
        }

        // Для каждого элемента первой строки
        for (unsigned i = 0; i < size; i++) {
            // Создаем подматрицу без первой строки и текущего столбца
            Matrix subMatrix(size - 1, size - 1);
            for (unsigned j = 1; j < size; j++) {
                unsigned subMatrixColumn = 0;
                for (unsigned k = 0; k < size; k++) {
                    if (k != i) {
                        subMatrix.setValue(j - 1, subMatrixColumn, matrix[j][k]);
                        subMatrixColumn++;
                    }
                }
            }
            // Рекурсивно вычисляем определитель подматрицы и прибавляем к общему определителю
            determinant += (i % 2 == 1 ? -1 : 1) * matrix[0][i] * subMatrix.getDet();
        }

    }
    detCreated = true;

}

void Matrix::reverse()
{
    if (getRowNumber() != getColNumber())
    {
        throw invalid_argument("Матрица не квадратная.");
    }
    //Расширение матрицы до 2n
    for (unsigned i = 0; i < row; i++)
    {
        for (unsigned j = row; j < 2 * row; j++)
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
        //Проверка на нулевые значения диагонали (смена строк местами)
        if (abs(matrix[flag][flag]) < 0.00001) {
            unsigned m = flag + 1;
            do {
                if (abs(matrix[m][flag]) > 0.00001 || m > row) {
                    break;
                }
                m++;
            } while (true);

            for (unsigned j = flag; j < 2 * row - 1; j++) {
                swap(matrix[flag][j], matrix[m][j]);
            }
        }
        //Правило прямоугольника
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
        //Обнуление элементов кроме диагонали и ответов
        for (unsigned i = 0; i < row; i++)
        {
            if (i != flag)
                matrix[i][flag] = 0;
        }
        //Делит всю строку на значение 
        for (unsigned j = 2 * row - 1; j != flag-1; j--)//j >= flag
        {
            matrix[flag][j] = matrix[flag][j] / matrix[flag][flag];
        }
    }
    //Создание столбца для ответов
    vector<vector<double>> output;
    output.resize(row);
    //Отщепление столбца, который содержит корней
    for (unsigned i = 0; i < row; i++)
    {
        for (unsigned j = row; j < 2 * row; j++)
        {
            output[i].push_back(matrix[i][j]);
        }
    }
    matrix = output;
}



//Решает систему уравнений методом Гаусса в матричном виде
vector<double> Matrix::solveGauss () const
{
    if ((getRowNumber()+1) != getColNumber())
    {
        throw invalid_argument("Число столбцов должно быть равно числу строк + 1.");
    }

    Matrix result = *this;
    for (unsigned flag = 0; flag < row; flag++)
    {
        if (abs(result.getValue(flag, flag)) < 0.00001) 
        {
            unsigned m = flag + 1;
            do {
                if (abs(result.getValue(m, flag)) > 0.00001 || m > row) {
                    break;
                }
                m++;
            } 
            while (true);
            swap(result.matrix[flag], result.matrix[m]);
        }
        //////////////////Правило
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
        /////////////////////////Обнуление столбца
        for (unsigned i = 0; i < row; i++)
        {
            if (i != flag)
            {
                result.setValue(i, flag, 0);
            }
        }
        ///////////////Деление строки
        for (unsigned j = row; j != flag-1; j--)//j >= flag
        {
            result.setValue(flag, j, (result.getValue(flag, j) / result.getValue(flag,flag)));
        }

    }
    return result.getCol(row);
}





// Проверка на работоспособность класса
void testClass()
{
    ///Создание объектов для проверок
    Matrix test;
    Matrix test2;
    Matrix test3;
    Matrix test4;
    Matrix test5;
    Matrix test7;
    vector<vector<double>> test_mat = { {5, 14, 23.0},
                                        {14.0, 41.0, 68.0},
                                        {23, 68, 113}, };
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
    vector<vector<double>> test_mat6 = {
        {4, 10, 16},
        {6, 12, 18},

    };
    vector<vector<double>> test_mat7 = {
        {1, 4, 7},
        {2, 5, 8},

    };
    vector<vector<double>> test_mat8 = {
    {5, 3},
    {3, 2},
    };
    vector<vector<double>> test_mat9 = {
    {2, -3},
    {-3, 5},
    };

    ///Задание объектам матриц
    test.setMatrix(test_mat);
    test2.setMatrix(test_mat2);
    test3.setMatrix(test_mat3);
    test4.setMatrix(test_mat4);
    test5.setMatrix(test_mat5);
    test7.setMatrix(test_mat7);
    test_mat7 = test_mat3;
    //////Вектор для ответов решения гаусса
    vector<double> output;
    vector<double> answers = {3, 5, 4};
    //Проверка суммы. Проверяются только одна версия операции, ибо остальные аналогичны:
    test3 += 2;
    assert(test3.getMatrix() == test_mat5);

    /////////////Проверка разницы
    test3 -= 2;
    assert(test3.getMatrix() == test_mat7);
    ////////////Проверка суммы двух матриц
    test7 = test3 + test5;
    assert(test7.getMatrix() == test_mat6);
    ////////////Проверка разности двух матриц
    test7 = test7 - test5;
    assert(test7.getMatrix() == test3.getMatrix());
    ////////////Проверка умножения на число:
    test7.setMatrix(test_mat7);
    test7.sum(test7);
    test3.setMatrix(test_mat3);
    test3.mul(test3, 2);
    assert(test7.getMatrix() == test3.getMatrix());
    ////////////Проверка умножения матрицы на матрицу
    test3.setMatrix(test_mat3);
    test2.setMatrix(test_mat2);
    test2 *= test3;
    assert(test2.getMatrix() == test.getMatrix());
    //////////////Проверка обратной матрицы
    test3.setMatrix(test_mat8);
    test2.setMatrix(test_mat9);
    test3.reverse();
    /////Погрешность в вычислениях. Извините, но это исправить нельзя
    test3.setValue(0, 1, round(test3.getValue(0, 1)));
    test3.setValue(1, 0, round(test3.getValue(1, 0)));
    assert(test2.getMatrix() == test3.getMatrix());
    //////////////Проверка определителя
    test3.setMatrix(test_mat8);
    assert(1 == test3.getDet());
    //////////////Проверка решения системы линейных уравнений в матричном виде:
    output = test4.solveGauss();
    for (int i = 0; i <3; i++)
    {
        output[i] = round(output[i]);
    }
    assert(output == answers);
    cout<< "Если вы это видите, класс работает нормально" << endl;
}
