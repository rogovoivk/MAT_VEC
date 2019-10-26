
#pragma once

#include "Base.h"
#include "Matrix.h"


namespace mat_vec {

// ��������� ��� ����⮢ ����� �� �᫮ ᫥�� (k * v)
    Vector operator*(double k, const Vector &v);

    class Vector {
    private:
        friend class Matrix;    //�������� ����� ����� ����� � �ਢ��� ���� Matrix
        double *arr;
        size_t len;
    public:
        // ���������� ����� ࠧ��� size � ���祭�ﬨ value
        explicit Vector(size_t size, double value = 0); //ᤥ���

        // ��������� ����஢����
        Vector(const Vector &src); //ᤥ���

        // ������ ��ᢠ������
        //Vector &operator=(const Vector &rhs);

        // ��������
        //~Vector();

        // �����頥� ࠧ��� �����
        size_t size() const; //ᤥ���

        // ����� � n-�� ������ �����
        //double operator[](size_t n) const;
        //double &operator[](size_t n);
        class t_proxy {
        public:
            double *arr;
            int ind;
            inline t_proxy(double *_arr, int _ind) : arr(_arr), ind(_ind){}
            t_proxy(const t_proxy &_src);    //�ਢ��� copy-��������� (����� �� ����஢���� ��ꥪ�);
            friend class Vector;    //�������� ����� ����� ����� � �ਢ��� ���� t_proxy!
            inline t_proxy &operator = (int _val) {
                this->arr[ind] = _val;
                return *this;
            };
            inline operator int () const {	//��ॣ�㦠�� ������ �ਢ������ ⨯�;
                return this->arr[ind];
            }
        };

        t_proxy operator[] (int i) {
            return t_proxy(arr, i);
        }

        // L2 ��ଠ �����
        double norm() const;

        // �����頥� ���� �����, ����祭�� ��ଠ����樥� ⥪�饣� (this)
        Vector normalized() const; //ᤥ���

        // ��ଠ����� ⥪�騩 �����
        void normalize(); //ᤥ���

        // ������⭮� ᫮����� ����஢
        Vector operator+(const Vector &rhs) const; //+
        Vector &operator+=(const Vector &rhs); //+

        // ������⭮� ���⠭�� ����஢
        Vector operator-(const Vector &rhs) const; //+
        Vector &operator-=(const Vector &rhs); //+

        // ������⭮� 㬭������ ����஢
        Vector operator^(const Vector &rhs) const; //+
        Vector &operator^=(const Vector &rhs); //+

        // �����୮� �ந��������
        double operator*(const Vector &rhs) const; //+

        // ��������� ��� ����⮢ ����� �� ᪠��� �ࠢ� (v * k)
        Vector operator*(double k) const; //+
        Vector &operator*=(double k); //+

        // ������� ��� ����⮢ ����� �� ᪠���
        Vector operator/(double k) const; //+
        Vector &operator/=(double k); //+

        // ��������� ����� �� ������
        Vector operator*(const Matrix &mat) const;
        Vector &operator*=(const Matrix &mat);

        // ������⭮� �ࠢ�����
        bool operator==(const Vector &rhs) const;
        bool operator!=(const Vector &rhs) const;

    private:
    };
} // namespace mat_vec
