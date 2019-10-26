#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include <gtest/gtest.h>

using namespace mat_vec;
using namespace std;

TEST (TestAll, Test1){   //тест на создание, доступ к элементам по индексам, и подщет кол-ва единичных бит в массиве на конст-ое время
    Vector test (9);
    test[8] = 1;
    test[0] = 1;
    for (int i = 0; i< test.size();i++){
        if (i == 0 || i == 8)
            EXPECT_GE(test[i], 1);
        else
            EXPECT_GE(test[i], 0);
    }
}

TEST (TestAll, TestNormalise){   //тест на создание, доступ к элементам по индексам, и подщет кол-ва единичных бит в массиве на конст-ое время
    Vector test (9);
    test[1] = 40;
    test[8] = 10;
    test[0] = 100;
    test.normalize();
    for (int i = 0; i< test.size();i++){
        if (i == 0)
            EXPECT_GE(test[i], 10);
        if (i = 1)
            EXPECT_GE(test[i], 4);
        if (i = 8)
            EXPECT_GE(test[i], 1);
        else
            EXPECT_GE(test[i], 0);
    }
}

TEST (TestAll, TestPlus){   //тест на создание, доступ к элементам по индексам, и подщет кол-ва единичных бит в массиве на конст-ое время

    Vector test (9);
    Vector test1 (9);
    test[8] = 1;
    test[0] = 1;
    test1[0] = 9;
    test1[8] = 9;
    test[5] = 5;
    test1[6] = 6;

    Vector test2 (3);
    test2 = test + test1;
    for (int i = 0; i< test.size();i++){
        if (i == 0)
            EXPECT_GE(test[i], 10);
        if (i == 5)
            EXPECT_GE(test[i], 5);
        if (i == 6)
            EXPECT_GE(test[i], 6);
        if (i == 8)
            EXPECT_GE(test[i], 10);
        if (i != 0 || i !=5 || i!=6 || i!=8)
            EXPECT_GE(test[i], 0);
    }

}

int main() {

    Matrix testm (3);


    return RUN_ALL_TESTS();

}