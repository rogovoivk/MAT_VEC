
#pragma once

#include "Base.h"
#include <tuple>

namespace mat_vec {

    class Matrix  {
        friend class Vector;    //�������� ����� ����� ����� � �ਢ��� ���� Matrix
    private:
        double ** matr;
        size_t rows, cols;
    public:
        // ���������� ������ � ࠧ��ࠬ� size x size, ����������� value
        Matrix(size_t size, double value = 0): rows(size), cols(size){
        matr = new double*[size];
        for (int i=0; i<size; i++){
                matr[i] = new double[size];
                for (int j; j<size; ++j)
                        matr[i][j] = 0;
        }
        };

        // �����頥� �������� ������
        //s//tatic Matrix eye(size_t size);

        // �����頥� ������ � ࠧ��ࠬ� rows x cols, ����������� value
        Matrix(size_t _rows, size_t _cols, double value = 0); //����

        // ��������� ����஢����
        Matrix(const Matrix &src);  //ᤥ����

        // ������ ��ᢠ������
        Matrix &operator=(const Matrix &rhs); //ᤥ����

        // ��������
        //~Matrix();

        // ������� �ਭ� � ����� ������, �� ������� �� �⮬
        // ���冷� ᫥������� ����⮢ �� ������ ���孥�� � �ࠢ��� �������:
        //
        // [1 2 3] -> [1 2]
        // [4 5 6] -> [3 4]
        //            [5 6]
        void reshape(size_t rows, size_t cols); // ᤥ����

        // �����頥� ���� {rows, cols} -- ������⢮ ��ப � �⮫�殢 ������
        //std::pair<size_t, size_t> shape() const;

        // �����頥� ����� �� ����樨 [row, col]
        double get(size_t row, size_t col) const; // ᤥ���

        // ������⭮� ᫮�����
        Matrix operator+(const Matrix &rhs) const; // ᤥ���
        Matrix &operator+=(const Matrix &rhs); // ᤥ���

        // ������⭮� ���⠭��
        Matrix operator-(const Matrix &rhs) const; //ᤥ���
        Matrix &operator-=(const Matrix &rhs); //ᤥ���

        // ����筮� 㬭������
        Matrix operator*(const Matrix &rhs) const; //ᤥ���
        Matrix &operator*=(const Matrix &rhs); //ᤥ���

        // ��������� ��� ����⮢ ������ �� ����⠭��
        Matrix operator*(double k) const; //ᤥ���
        Matrix &operator*=(double k); //ᤥ����

        // ������� ��� ����⮢ ������ �� ����⠭��
        Matrix operator/(double k) const; //ᤥ����
        Matrix &operator/=(double k);  //ᤥ����

        // �����頥� ����� ������, ����祭��� �࠭ᯮ��஢����� ⥪�饩 (this)
        Matrix transposed() const; //ᤥ����

        // �࠭ᯮ����� ⥪���� ������
        void transpose(); //ᤥ����

        // ��।���⥫�
        double det(); //ᤥ����

        // ���⭠� �����
        Matrix inv(); //ᤥ���
        //�ᯮ����⥫��
        //void Get_matr(int **matr, int n, int **temp_matr, int indRow, int indCol)

        // ��������� ������ �� �����
        Vector operator*(const Vector &vec) const; //�����⨬ ᤥ���

        // ������⭮� �ࠢ�����
        bool operator==(const Matrix &rhs) const; //ᤥ����
        bool operator!=(const Matrix &rhs) const; //ᤥ����


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
                int temp = 0;   //�६����� ��६����� ��� �࠭���� ��।���⥫�
                int k = 1;      //�⥯���
                if(n < 1){
                        //cout<<"�� ���� ࠧ��� ������!!!" << endl;
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