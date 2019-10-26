//
// Created by Vladislav Rogovoi on 26.10.2019.
//


#ifndef NUMBER1_VECTOR_H
#define NUMBER1_VECTOR_H

#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

//#pragma once

//#include "Base.h"
#include "Vector.h"
using namespace mat_vec;
using namespace std;

Vector :: Vector(size_t size, double value): len(size){ //ª®­áâàãªâ®à
            this->arr = new double [len];
            for (int i = 0; i < len; i++){
                this->arr[i] = 0;
            }
};

Vector :: Vector(const Vector &src){
    this->arr = new double [src.len];
    for (int i = 0; i < len; ++i)
        this->arr[i] = src.arr[i];
};

size_t Vector :: size() const{
    return len;
};

Vector Vector :: normalized() const{
    Vector returnVec (len);
    for (int i = 0; i < len; i++){
        returnVec.arr[i] = arr[i]/len;
    }
    return returnVec;
};

void Vector :: normalize(){
    for (int i = 0; i < len; i++){
        arr[i] = arr[i]/len;
    }
};

Vector Vector :: operator+(const Vector &lagann) const{// …‡ƒ€ˆ—Ž… ‘‹ˆŸˆ… ƒ“… - ‹€ƒ€ -- ‚› ‡€ ŠŽƒŽ €‘ „…†ˆ’…!!!!
    if (this->len == lagann.len)
    {
        Vector returnVector (this->len);
        for (int i = 0; i < this->len; i++)
        {
            returnVector.arr[i] = (*this).arr[i] + lagann.arr[i];
        }
        return returnVector;
    }
};

Vector& Vector ::operator+=(const Vector &lagann){
    if (this->len == lagann.len)
    {
        Vector returnVector (this->len);
        for (int i = 0; i < this->len; i++)
        {
            returnVector.arr[i] = (*this).arr[i] + lagann.arr[i];
        }
        *this = returnVector;
    }
};

Vector Vector :: operator-(const Vector &lagann) const{
    if (this->len == lagann.len)
    {
        Vector returnVector (this->len);
        for (int i = 0; i < this->len; i++)
        {
            returnVector.arr[i] = (*this).arr[i] - lagann.arr[i];
        }
        return returnVector;
    }
};

Vector& Vector ::operator-=(const Vector &lagann){
    if (this->len == lagann.len)
    {
        Vector returnVector (this->len);
        for (int i = 0; i < this->len; i++)
        {
            returnVector.arr[i] = (*this).arr[i] - lagann.arr[i];
        }
        *this = returnVector;
    }
};

Vector Vector :: operator^(const Vector &rhs) const{
    if (this->len == rhs.len) {
        Vector returnVector (this->len);
        for (int i = 0; i < this->len; ++i)
            returnVector[i] = this->arr[i] * rhs.arr[i];
        return returnVector;
    }
};

Vector& Vector :: operator^=(const Vector &rhs){
    if (this->len == rhs.len) {
        Vector returnVector (this->len);
        for (int i = 0; i < this->len; ++i)
            returnVector[i] = this->arr[i] * rhs.arr[i];
        *this = returnVector;
    }
};

double Vector :: operator*(const Vector &rhs) const{
    if (this->len == rhs.len) {
        double ans;
        for (int i = 0; i < rhs.len; ++i)
            ans += this->arr[i] * rhs.arr[i];
        return ans;
    }
};

Vector Vector :: operator*(double k) const {
    Vector ansVec(this->len);
    for (int i = 0 ; i < this->len; ++i)
        ansVec.arr[i] = this->arr[i] * k;
    return ansVec;

};

Vector& Vector :: operator*=(double k) {
    for (int i = 0 ; i < this->len; ++i)
        this->arr[i] *= k;
};

Vector Vector :: operator/(double k) const{
    Vector ansVec(this->len);
    for (int i = 0 ; i < this->len; ++i)
        ansVec.arr[i] = this->arr[i] / k;
    return ansVec;
};

Vector& Vector :: operator/=(double k){
    for (int i = 0 ; i < this->len; ++i)
        this->arr[i] /= k;
};

Vector Vector :: operator*(const Matrix &mat) const{
    Vector returnVector (this->len);
    if (mat.rows == this->len)
        for (int i = 0; i < mat.cols; ++i)
            for (int j = 0; j < mat.rows; ++j)
                returnVector[i] = mat.matr[i][j] * this->arr[i]; //íâ® § à ¡®â ¥â, ª®£  ¯¥à¥¯¨èã ¢¥ªâ®à 
};

Vector& Vector :: operator*=(const Matrix &mat){
    if (mat.rows == this->len) {
        Vector returnVector(this->len);
        for (int i = 0; i < mat.cols; ++i)
            for (int j = 0; j < mat.rows; ++j)
                returnVector[i] = mat.matr[i][j] * this->arr[i]; //íâ® § à ¡®â ¥â, ª®£  ¯¥à¥¯¨èã ¢¥ªâ®à 
        *this = returnVector;
    }
};

bool Vector :: operator==(const Vector &rhs) const{
    if (this->len != rhs.len) return false;
    for (int i = 0; i< this->len; i++){
        if (this->arr[i] != rhs.arr[i]) return false;
    }
    return true;
};

bool Vector :: operator!=(const Vector &rhs) const {
    if (this->len != rhs.len) return true;
    for (int i = 0; i < this->len; i++) {
        if (this->arr[i] != rhs.arr[i]) return true;
    }
    return false;
}

#endif //NUMBER1_VECTOR_H

