
#pragma once

#include "Base.h"
#include <tuple>

namespace mat_vec {

    class Matrix  {
        friend class Vector;    //Указанный класс имеет доступ к приватным полям Matrix
    private:
        double ** matr;
        size_t rows, cols;
    public:
        // Конструирует матрицу с размерами size x size, заполненную value
        Matrix(size_t size, double value = 0): rows(size), cols(size){
        matr = new double*[size];
        for (int i=0; i<size; i++){
                matr[i] = new double[size];
                for (int j; j<size; ++j)
                        matr[i][j] = 0;
        }
        };

        // Возвращает единичную матрицу
        //s//tatic Matrix eye(size_t size);

        // Возвращает матрицу с размерами rows x cols, заполненную value
        Matrix(size_t _rows, size_t _cols, double value = 0); //есть

        // Конструктор копирования
        Matrix(const Matrix &src);  //сделано

        // Оператор присваивания
        Matrix &operator=(const Matrix &rhs); //сделано

        // Деструктор
        //~Matrix();

        // Изменяет ширину и высоту матрицы, не изменяя при этом
        // порядок следования элементов от левого верхнего к правому нижнему:
        //
        // [1 2 3] -> [1 2]
        // [4 5 6] -> [3 4]
        //            [5 6]
        void reshape(size_t rows, size_t cols); // сделано

        // Возвращает пару {rows, cols} -- количество строк и столбцов матрицы
        //std::pair<size_t, size_t> shape() const;

        // Возвращает элемент на позиции [row, col]
        double get(size_t row, size_t col) const; // сделал

        // Поэлементное сложение
        Matrix operator+(const Matrix &rhs) const; // сделал
        Matrix &operator+=(const Matrix &rhs); // сделал

        // Поэлементное вычитание
        Matrix operator-(const Matrix &rhs) const; //сделал
        Matrix &operator-=(const Matrix &rhs); //сделал

        // Матричное умножение
        Matrix operator*(const Matrix &rhs) const; //сделал
        Matrix &operator*=(const Matrix &rhs); //сделал

        // Умножение всех элементов матрицы на константу
        Matrix operator*(double k) const; //сделал
        Matrix &operator*=(double k); //сделано

        // Деление всех элементов матрицы на константу
        Matrix operator/(double k) const; //сделано
        Matrix &operator/=(double k);  //сделано

        // Возвращает новую матрицу, полученную транспонированием текущей (this)
        Matrix transposed() const; //сделано

        // Транспонирует текущую матрицу
        void transpose(); //сделано

        // Определитель
        double det(); //сделано

        // Обратная матрица
        Matrix inv(); //сделал
        //вспомогательные
        //void Get_matr(int **matr, int n, int **temp_matr, int indRow, int indCol)

        // УМножение матрицы на вектор
        Vector operator*(const Vector &vec) const; //допустим сделал

        // Поэлементное сравнение
        bool operator==(const Matrix &rhs) const; //сделано
        bool operator!=(const Matrix &rhs) const; //сделано


        void FreeMem(double **matr, int n)
        {
                for(int i = 0; i < n; i++)
                        delete [] matr[i];
                delete [] matr;
        }


        void Get_matr(double **matr, int n, double **temp_matr, int indRow, int indCol)
        {
                int ki = 0;
                for (int i = 0; i < n; i++){
                        if(i != indRow){
                                for (int j = 0, kj = 0; j < n; j++){
                                        if (j != indCol){
                                                temp_matr[ki][kj] = matr[i][j];
                                                kj++;
                                        }
                                }
                                ki++;
                        }
                }
        }

        int Det(double **matr, int n)
        {
                int temp = 0;   //временная переменная для хранения определителя
                int k = 1;      //степень
                if(n < 1){
                        //cout<<"Не верный размер матрицы!!!" << endl;
                        return 0;
                }
                else if (n == 1)
                        temp = matr[0][0];
                else if (n == 2)
                        temp = matr[0][0] * matr[1][1] - matr[1][0] * matr[0][1];
                else{
                        for(int i = 0; i < n; i++){
                                int m = n - 1;
                                double **temp_matr = new double * [m];
                                for(int j = 0; j < m; j++)
                                        temp_matr[j] = new double [m];
                                Get_matr(matr, n, temp_matr, 0, i);
                                temp = temp + k * matr[0][i] * Det(temp_matr, m);
                                k = -k;
                                FreeMem(temp_matr, m);
                        }
                }
                return temp;
        }

    private:
    };

} // namespace mat_vec