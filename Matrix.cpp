//
// Created by Vladislav Rogovoi on 26.10.2019.
//
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include "Matrix.h"
#include "Vector.h"

using  namespace mat_vec;
using  namespace std;

Matrix :: Matrix(size_t rows_, size_t cols_, double value): rows(rows_), cols(cols_){
    matr = new double*[rows];
    for (int i=0; i<rows; i++){
        matr[i] = new double[cols];
        for (int j; j<cols; ++j)
            matr[i][j] = 0;
    }
};

Matrix :: Matrix(const Matrix &naruto){ //НАРУТО - теневое клонирование!!!
    matr = new double*[naruto.rows];
    rows = naruto.rows;
    cols = naruto.cols;
    for (int i=0; i<rows; i++){
        matr[i] = new double[cols];
        for (int j; j<cols; ++j)
            matr[i][j] = naruto.matr[i][j];
    }
}

//Matrix :: Matrix &operator=(const Matrix &naruto){ //НАРУТО - теневое клонирование !!!
Matrix& Matrix ::operator=(const Matrix &naruto) {
    this->matr = new double*[naruto.rows];
    this->rows = naruto.rows;
    this->cols = naruto.cols;
    for (int i=0; i<this->rows; i++){
        this->matr[i] = new double[this->cols];
        for (int j; j<this->cols; ++j)
            this->matr[i][j] = naruto.matr[i][j];
    }
};

void Matrix :: reshape(size_t rows_, size_t cols_){ // Эрен Егерь - тронсформация в титана))))
    Matrix ErenYeager (rows_, cols_);
    if (rows >= rows_){
        for (int i = 0; i < rows_; ++i) {
            if (cols >= cols_)
                for (int j = 0; j < cols_; ++j) {
                    ErenYeager.matr[i][j] = this->matr[i][j];
                }
            else
                for (int j = 0; j < cols_; ++j) {
                    if (j<cols) ErenYeager.matr[i][j] = this->matr[i][j];
                    else ErenYeager.matr[i][j] = 0;
                }
        }
    }
    else
        for (int i = 0; i < rows_; ++i) {
            if ((cols >= cols_) && (i < rows))
                for (int j = 0; j < cols_; ++j)
                    ErenYeager.matr[i][j] = this->matr[i][j];
            if ((cols >= cols_) && (i >= rows))
                for (int j = 0; j < cols_; ++j)
                ErenYeager.matr[i][j] = 0;
            if ((cols < cols_) && (i < rows))
                for (int j = 0; j < cols_; ++j) {
                    if (j<cols) ErenYeager.matr[i][j] = this->matr[i][j];
                    else ErenYeager.matr[i][j] = 0;
                }
            if ((cols < cols_) && (i >= rows))
                for (int j = 0; j < cols_; ++j) {
                    ErenYeager.matr[i][j]=0;
                }
        }
    rows = rows_;
    cols = cols_;
};

double Matrix :: get(size_t row, size_t col) const{
    return this->matr[row][col];
};

Matrix Matrix :: operator+(const Matrix &lagann) const{ //Безграничное слияние Гуррен - Лаганн
    size_t len1, len2;
    if (rows <= lagann.rows) len1 =rows;
    else len1 =lagann.rows;
    if (cols <= lagann.cols) len1 =cols;
    else len1 =lagann.cols;
    Matrix gurrenLagann(len1, len2);
    for (int i = 0; i < len1; ++i)
        for (int j = 0; j < len2; ++j)
            gurrenLagann.matr[i][j] = this->matr[i][j] + lagann.matr[i][j];
    return gurrenLagann;
};

Matrix& Matrix :: operator+=(const Matrix &lagann){ //Безграничное слияние Гуррен - Лаганн
    size_t len1, len2;
    if (this->rows <= lagann.rows) len1 =this->rows;
    else len1 =lagann.rows;
    if (this->cols <= lagann.cols) len1 =this->cols;
    else len1 =lagann.cols;
    Matrix gurrenLagann(len1, len2);
    for (int i = 0; i < len1; ++i)
        for (int j = 0; j < len2; ++j)
            gurrenLagann.matr[i][j] = this->matr[i][j] + lagann.matr[i][j];
    *this = gurrenLagann;
};

Matrix Matrix :: operator-(const Matrix &rhs) const{
    size_t len1, len2;
    if (rows <= rhs.rows) len1 =rows;
    else len1 =rhs.rows;
    if (cols <= rhs.cols) len1 =cols;
    else len1 =rhs.cols;
    Matrix returnMatr(len1, len2);
    for (int i = 0; i < len1; ++i)
        for (int j = 0; j < len2; ++j)
            returnMatr.matr[i][j] = this->matr[i][j] - rhs.matr[i][j];
    return returnMatr;
};

Matrix& Matrix :: operator-=(const Matrix &rhs){
    size_t len1, len2;
    if (this->rows <= rhs.rows) len1 =this->rows;
    else len1 =rhs.rows;
    if (this->cols <= rhs.cols) len1 =this->cols;
    else len1 = rhs.cols;
    Matrix returnMatr (len1, len2);
    for (int i = 0; i < len1; ++i)
        for (int j = 0; j < len2; ++j)
            returnMatr.matr[i][j] = this->matr[i][j] - rhs.matr[i][j];
    *this = returnMatr;
};

Matrix Matrix :: operator*(const Matrix &rhs) const{
    if (this->rows == rhs.rows) {

        Matrix *returnMatrix = new Matrix(cols, rhs.rows);

        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rhs.rows; j++) {
                returnMatrix->matr[i][j] = 0;
                for (int k = 0; k < rows; k++)
                    returnMatrix->matr[i][j] += this->matr[i][k] * rhs.matr[k][j];
            }
        }
        return *returnMatrix;
    }
};

Matrix& Matrix ::operator*=(const Matrix &rhs){
    if (this->rows == rhs.rows) {

        Matrix *returnMatrix = new Matrix(this->cols, rhs.rows);

        for (int i = 0; i < this->cols; i++) {
            for (int j = 0; j < rhs.rows; j++) {
                returnMatrix->matr[i][j] = 0;
                for (int k = 0; k < this->rows; k++)
                    returnMatrix->matr[i][j] += this->matr[i][k] * rhs.matr[k][j];
            }
        }
        *this = *returnMatrix;
    }
};

Matrix Matrix :: operator*(double k) const{
    Matrix* returnMatrix = new Matrix(rows,cols);
    for (int i = 0; i < this->rows; ++i)
        for (int j = 0; j < this->cols; ++j)
            returnMatrix->matr[i][j] = this->matr[i][j] * k;
    return *returnMatrix;
};

Matrix& Matrix :: operator*=(double k){
    Matrix* returnMatrix = new Matrix(this->rows,cols);
    for (int i = 0; i < this->rows; ++i)
        for (int j = 0; j < this->cols; ++j)
            returnMatrix->matr[i][j] = this->matr[i][j] * k;
    *this = *returnMatrix;
};

Matrix Matrix :: operator/(double k) const{
    Matrix* returnMatrix = new Matrix(rows,cols);
    for (int i = 0; i < this->rows; ++i)
        for (int j = 0; j < this->cols; ++j)
            returnMatrix->matr[i][j] = this->matr[i][j] / k;
    return *returnMatrix;
};

Matrix& Matrix :: operator/=(double k){
    Matrix* returnMatrix = new Matrix(this->rows,cols);
    for (int i = 0; i < this->rows; ++i)
        for (int j = 0; j < this->cols; ++j)
            returnMatrix->matr[i][j] = this->matr[i][j] / k;
    *this = *returnMatrix;
};

Matrix Matrix :: transposed() const{
    Matrix* returnMatrix = new Matrix(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            returnMatrix->matr[j][i] = this->matr[i][j];
    return *returnMatrix;
};

void Matrix :: transpose(){
    Matrix* returnMatrix = new Matrix(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            returnMatrix->matr[j][i] = this->matr[i][j];
    *this = *returnMatrix;
};

double Matrix :: det(){
    int p=0, k =0;
    if ((this->rows<2) || (this->rows>6)) k=0;
    else k=1;
    double kst;
    for (int i=0; i<rows-1; i++)
    {
        int t=1;
        while(this->matr[i][i]==0)
        {
            for(int j=0; j<rows; j++)
            {
                this->matr[i][j]=kst;
                this->matr[i][j]=this->matr[i+t][j];
                this->matr[i+t][j]=kst;
            }
            p++;
            t++;
        }

        for (k=i+1; k<this->rows; k++)
        {
            kst=this->matr[k][i]/this->matr[i][i];
            for(int j=0; j<this->rows; j++)
                this->matr[k][j]-=this->matr[i][j]*kst;
        }
    }

    kst=pow(-1,p);
    for(int i=0; i<this->rows; i++)
        kst*=this->matr[i][i];

    return kst;
};

Matrix Matrix :: inv() {
    Matrix* returnMatrix = new Matrix(rows,cols);
    double ddet = Det(matr, this->rows);
    if (ddet) {
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->rows; j++) {
                int m = this->rows - 1;
                double **temp_matr = new double *[m];
                for (int k = 0; k < m; k++)
                    temp_matr[k] = new double[m];
                Get_matr(this->matr, this->rows, temp_matr, i, j);
                returnMatrix->matr[i][j] = pow(-1.0, i + j + 2) * Det(temp_matr, m) / ddet;
                FreeMem(temp_matr, m);
            }
        }
    }

};

Vector Matrix :: operator*(const Vector &vec) const{
    Vector returnVector (vec.len);
    if (this->rows == vec.len)
        for (int i = 0; i < this->cols; ++i)
            for (int j = 0; j < rows; ++j)
                returnVector[i] = this->matr[i][j] * vec.arr[i]; //это заработает, кога перепишу вектора
};

bool Matrix :: operator==(const Matrix &rhs) const{
    if (this->rows == rhs.rows && this->cols == rhs.cols){
        for (int i = 0; i < this->rows; i++){
            if (matr[i] != rhs.matr[i]) return false;
        }
    } else return false;
    return true;
};

bool Matrix :: operator!=(const Matrix &rhs) const{
    if (this->rows == rhs.rows && this->cols == this->cols){
        for (int i = 0; i < rows; i++){
            if (matr[i] != rhs.matr[i]) return true;
        }
    } else return true;
    return false;
};