
#pragma once

#include "Base.h"
#include "Matrix.h"


namespace mat_vec {

// Умножение всех элементов вектора на число слева (k * v)
    Vector operator*(double k, const Vector &v);

    class Vector {
    private:
        friend class Matrix;    //Указанный класс имеет доступ к приватным полям Matrix
        double *arr;
        size_t len;
    public:
        // Конструирует вектор размера size со значениями value
        explicit Vector(size_t size, double value = 0); //сделал

        // Конструктор копирования
        Vector(const Vector &src); //сделал

        // Оператор присваивания
        //Vector &operator=(const Vector &rhs);

        // Деструктор
        //~Vector();

        // Возвращает размер вектора
        size_t size() const; //сделал

        // Доступ к n-му элементу вектора
        //double operator[](size_t n) const;
        //double &operator[](size_t n);
        class t_proxy {
        public:
            double *arr;
            int ind;
            inline t_proxy(double *_arr, int _ind) : arr(_arr), ind(_ind){}
            t_proxy(const t_proxy &_src);    //Приватный copy-конструктор (запрет на копирование объекта);
            friend class Vector;    //Указанный класс имеет доступ к приватным полям t_proxy!
            inline t_proxy &operator = (int _val) {
                this->arr[ind] = _val;
                return *this;
            };
            inline operator int () const {	//Перегружаем оператор приведения типа;
                return this->arr[ind];
            }
        };

        t_proxy operator[] (int i) {
            return t_proxy(arr, i);
        }

        // L2 норма вектора
        double norm() const;

        // Возвращает новый вектор, полученный нормализацией текущего (this)
        Vector normalized() const; //сделал

        // Нормализует текущий вектор
        void normalize(); //сделал

        // Поэлементное сложение векторов
        Vector operator+(const Vector &rhs) const; //+
        Vector &operator+=(const Vector &rhs); //+

        // Поэлементное вычитание векторов
        Vector operator-(const Vector &rhs) const; //+
        Vector &operator-=(const Vector &rhs); //+

        // Поэлементное умножение векторов
        Vector operator^(const Vector &rhs) const; //+
        Vector &operator^=(const Vector &rhs); //+

        // Скалярное произведение
        double operator*(const Vector &rhs) const; //+

        // Умножение всех элементов вектора на скаляр справа (v * k)
        Vector operator*(double k) const; //+
        Vector &operator*=(double k); //+

        // Деление всех элементов вектора на скаляр
        Vector operator/(double k) const; //+
        Vector &operator/=(double k); //+

        // Умножение вектора на матрицу
        Vector operator*(const Matrix &mat) const;
        Vector &operator*=(const Matrix &mat);

        // Поэлементное сравнение
        bool operator==(const Vector &rhs) const;
        bool operator!=(const Vector &rhs) const;

    private:
    };
} // namespace mat_vec
