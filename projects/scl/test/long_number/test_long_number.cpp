#include <iostream>
#include <gtest/gtest.h>

#include "long_number.hpp"

TEST(get_digits_number, check_positive) {
	DSedegova::LongNumber x("12345");
	ASSERT_EQ(5, x.get_digits_number())
		<< "����������� ���������� ���������� �������� � ����� " << x;
}

TEST(get_digits_number, check_negative) {
	DSedegova::LongNumber x("-1");
	ASSERT_EQ(1, x.get_digits_number())
		<< "����������� ���������� ���������� �������� � ����� " << x;
}

class EqualityFixture : public testing::Test {
public:
	DSedegova::LongNumber one_v1 = DSedegova::LongNumber("1");
	DSedegova::LongNumber one_v2 = DSedegova::LongNumber("1");
	DSedegova::LongNumber stzero_one = DSedegova::LongNumber("0001");
	DSedegova::LongNumber zero_v1 = DSedegova::LongNumber("000");
	DSedegova::LongNumber zero_v2 = DSedegova::LongNumber("0");
	DSedegova::LongNumber twelve = DSedegova::LongNumber("12");
	DSedegova::LongNumber negative_one = DSedegova::LongNumber("-1");
};

TEST_F(EqualityFixture, equal) {
	ASSERT_TRUE(one_v1 == one_v2) << "�������� " << one_v1 << " == " << one_v2;
}

TEST_F(EqualityFixture, zero_equal) {
	ASSERT_TRUE(zero_v1 == zero_v2) << "�������� " << zero_v1 << " == " << zero_v2;
}

TEST_F(EqualityFixture, stzero_equal) {
	ASSERT_TRUE(stzero_one == one_v1) << "�������� " << stzero_one << " == " << one_v1;
}

TEST_F(EqualityFixture, not_equal) {
	ASSERT_FALSE(one_v1 == twelve) << "�������� " << one_v1 << " == " << twelve;
}

TEST_F(EqualityFixture, not_equal_negative_var) {
	ASSERT_FALSE(one_v1 == negative_one)
		<< "�������� " << one_v1 << " == " << negative_one;
}

TEST(compare_greater, positive_greater) {
	DSedegova::LongNumber x("123");
	DSedegova::LongNumber y("45");
	ASSERT_TRUE(x > y) << "�������� " << x << " > " << y;
}

TEST(compare_greater, negative_greater) {
	DSedegova::LongNumber x("-123");
	DSedegova::LongNumber y("-45");
	ASSERT_TRUE(x < y) << "�������� " << x << " > " << y;
}

TEST(compare_greater, positive_not_greater) {
	DSedegova::LongNumber x("123");
	DSedegova::LongNumber y("456");
	ASSERT_FALSE(x > y) << "�������� " << x << " > " << y;
}

TEST(compare_less, positive_less) {
	DSedegova::LongNumber x("123");
	DSedegova::LongNumber y("456");
	ASSERT_TRUE(x < y) << "�������� " << x << " < " << y;
}

TEST(compare_less, negative_less) {
	DSedegova::LongNumber x("-123");
	DSedegova::LongNumber y("-456");
	ASSERT_TRUE(x > y) << "�������� " << x << " < " << y;
}

TEST(compare_less, positive_not_less) {
	DSedegova::LongNumber x("123");
	DSedegova::LongNumber y("45");
	ASSERT_FALSE(x < y) << "�������� " << x << " < " << y;
}

TEST(absolute, positive_abs) {
	DSedegova::LongNumber x("10");
	ASSERT_EQ(DSedegova::LongNumber("10"), x.abs(x)) << "�������� abs(" << x << ")";
}

TEST(absolute, negative_abs) {
	DSedegova::LongNumber x("-10");
	ASSERT_EQ(DSedegova::LongNumber("10"), x.abs(x)) << "�������� abs(" << x << ")";
}

TEST(toInt, positive) {
	DSedegova::LongNumber x("10");
	ASSERT_EQ(10, x.toInt(x)) << "�������� toInt(" << x << ")";
}

TEST(toInt, negative) {
	DSedegova::LongNumber x("-10");
	ASSERT_EQ(-10, x.toInt(x)) << "�������� toInt(" << x << ")";
}

TEST(addition, positive_sum) {
	DSedegova::LongNumber x("123");
	DSedegova::LongNumber y("456");
	DSedegova::LongNumber result = x + y;
	ASSERT_EQ(DSedegova::LongNumber("579"), result) << "�������� " << x << " + " << y;
}

TEST(addition, first_zero_sum) {
	DSedegova::LongNumber x("003");
	DSedegova::LongNumber y("006");
	DSedegova::LongNumber result = x + y;
	ASSERT_EQ(DSedegova::LongNumber("9"), result) << "�������� " << x << " + " << y;
}

TEST(addition, carry_sum) {
	DSedegova::LongNumber x("99");
	DSedegova::LongNumber y("61");
	Dsedegova::LongNumber result = x + y;
	ASSERT_EQ(DSedegova::LongNumber("160"), result) << "�������� " << x << " + " << y;
}

TEST(addition, negative_sum) {
	DSedegova::LongNumber x("-123");
	DSedegova::LongNumber y("-456");
	DSedegova::LongNumber expected("-579");
	ASSERT_EQ(expected, x + y) << "�������� " << x << " + " << y;
}

TEST(subtract, subtract_positive_numbers) {
	DSedegova::LongNumber num1("54321");
	DSedegova::LongNumber num2("12345");
	DSedegova::LongNumber result = num1 - num2;

	ASSERT_EQ(DSedegova::LongNumber("41976"), result) << "������������ �������� ������������� �����";
}

TEST(subtract, subtract_negative_numbers) {
	DSedegova::LongNumber num1("-54321");
	DSedegova::LongNumber num2("-12345");
	DSedegova::LongNumber result = num1 - num2;

	ASSERT_EQ(DSedegova::LongNumber("-41976"), result) << "������������ �������� ������������� �����";
}

TEST(divide, divide_positive_numbers) {
	DSedegova::LongNumber num1("100");
	DSedegova::LongNumber num2("25");
	DSedegova::LongNumber result = num1 / num2;

	ASSERT_EQ(DSedegova::LongNumber("4"), result) << "������������ ������������� ������� ������������� �����";
}

TEST(divide, divide_negative_numbers) {
	DSedegova::LongNumber num1("-100");
	DSedegova::LongNumber num2("25");
	DSedegova::LongNumber result = num1 / num2;

	ASSERT_EQ(DSedegova::LongNumber("-4"), result) << "������������ ������������� ������� �������������� ����� �� �������������";
}

TEST(modulo, modulo_positive_numbers) {
	DSedegova::LongNumber num1("100");
	DSedegova::LongNumber num2("25");
	DSedegova::LongNumber result = num1 % num2;

	ASSERT_EQ(DSedegova::LongNumber("0"), result) << "������������ ������� ��" << num1 << " mod " << num2;
}

TEST(modulo, modulo_negative_numbers) {
	DSedegova::LongNumber num1("-100");
	DSedegova::LongNumber num2("25");
	DSedegova::LongNumber result = num1 % num2;

	ASSERT_EQ(DSedegova::LongNumber("0"), result) << "������������ ������� ��" << num1 << " mod " << num2;
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}