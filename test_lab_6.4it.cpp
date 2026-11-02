
#include <gtest/gtest.h>

// Оголошення функцій
int count_greater(double a[], int n, double C);
double product_after_max_abs(double a[], int n);
void rearrange_array(double a[], int n);

// Тест 1: підрахунок елементів, більших за C
TEST(Lab64Test, CountGreater)
{
    double a[20] = {
        1, 5, 3, 8, 2, 10, 4, 6, 7, 9,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20
    };

    EXPECT_EQ(count_greater(a, 20, 10), 10);
}

// Тест 2: немає елементів, більших за C
TEST(Lab64Test, NoElementsGreater)
{
    double a[20] = {
        -1, -2, -3, -4, -5, -6, -7, -8, -9, -10,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };

    EXPECT_EQ(count_greater(a, 20, 10), 0);
}

// Тест 3: добуток елементів після найбільшого за модулем
TEST(Lab64Test, ProductAfterMaxAbs)
{
    double a[20] = {
        1, 2, -3, 20, 2, 3, 1, 2, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

    EXPECT_DOUBLE_EQ(product_after_max_abs(a, 20), 12);
}

// Тест 4: найбільший за модулем елемент останній
TEST(Lab64Test, MaxAbsLast)
{
    double a[20] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, -20
    };

    EXPECT_DOUBLE_EQ(product_after_max_abs(a, 20), 1);
}

// Тест 5: перестановка від'ємних і невід'ємних чисел
TEST(Lab64Test, RearrangeArray)
{
    double a[20] = {
        1, -2, 3, -4, 5, -6, 7, -8, 9, -10,
        11, -12, 13, -14, 15, -16, 17, -18, 19, -20
    };

    double expected[20] = {
        -2, -4, -6, -8, -10, -12, -14, -16, -18, -20,
        1, 3, 5, 7, 9, 11, 13, 15, 17, 19
    };

    rearrange_array(a, 20);

    for (int i = 0; i < 20; i++) {
        EXPECT_DOUBLE_EQ(a[i], expected[i]);
    }
}

// Тест 6: масив без від'ємних чисел
TEST(Lab64Test, NoNegativeNumbers)
{
    double a[20] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20
    };

    double expected[20] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20
    };

    rearrange_array(a, 20);

    for (int i = 0; i < 20; i++) {
        EXPECT_DOUBLE_EQ(a[i], expected[i]);
    }
}