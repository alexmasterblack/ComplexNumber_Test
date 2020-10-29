#include "pch.h"
#include <fstream>

TEST(ComplexNumber_Representation, A) {
	ComplexNumber a(1.3, 7.8);

	EXPECT_EQ(a.GetReal().GetFraction(), "13/10");
	EXPECT_EQ(a.GetImag().GetFraction(), "39/5");
}
TEST(ComplexNumber_Representation, B) {
	ComplexNumber a(56.005, 3);

	EXPECT_EQ(a.GetReal().GetFraction(), "11201/200");
	EXPECT_EQ(a.GetImag().GetFraction(), "3/1");
}
TEST(ComplexNumber_Representation, C) {
	ComplexNumber a(-234, -332.1210);

	EXPECT_EQ(a.GetReal().GetFraction(), "-234/1");
	EXPECT_EQ(a.GetImag().GetFraction(), "-332121/1000");
}
TEST(ComplexNumber_Representation, D) {
	ComplexNumber a;

	EXPECT_EQ(a.GetReal().GetFraction(), "0/1");
	EXPECT_EQ(a.GetImag().GetFraction(), "0/1");
}

TEST(ComplexNumberTest_Converting, A) {
	ComplexNumber a;
	double b = -58.82;
	a = b;

	EXPECT_EQ(a.GetReal().GetFraction(), "-2941/50");
	EXPECT_EQ(a.GetImag().GetFraction(), "0/1");
}
TEST(ComplexNumberTest_Converting, B) {
	ComplexNumber a;
	float c = 12.0122;
	a = c;

	EXPECT_EQ(a.GetReal().GetFraction(), "60061/5000");
	EXPECT_EQ(a.GetImag().GetFraction(), "0/1");
}
TEST(ComplexNumberTest_Converting, C) {
	ComplexNumber a;
	int d = 20;
	a = d;

	EXPECT_EQ(a.GetReal().GetFraction(), "20/1");
	EXPECT_EQ(a.GetImag().GetFraction(), "0/1");
}
TEST(ComplexNumberTest_Converting, D) {
	ComplexNumber a = 33.1;

	EXPECT_EQ(a.GetReal().GetFraction(), "331/10");
	EXPECT_EQ(a.GetImag().GetFraction(), "0/1");
}
TEST(ComplexNumberTest_Converting, F) {
	ComplexNumber a(-50, -239.892);
	ComplexNumber b(a);

	EXPECT_EQ(b.GetReal().GetFraction(), "-50/1");
	EXPECT_EQ(b.GetImag().GetFraction(), "-59973/250");
}

TEST(ComplexNumberTest_Plus, A) {
	ComplexNumber a;
	ComplexNumber b(23.56, 12.11);
	ComplexNumber c(3, 24.067);

	a = b + c;
	EXPECT_EQ(a.GetReal().GetFraction(), "664/25");
	EXPECT_EQ(a.GetImag().GetFraction(), "36177/1000");

	b += c;
	EXPECT_EQ(b.GetReal().GetFraction(), "664/25");
	EXPECT_EQ(b.GetImag().GetFraction(), "36177/1000");
}
TEST(ComplexNumberTest_Plus, B) {
	ComplexNumber a;
	ComplexNumber b(0.667, 1);
	ComplexNumber c(-1.5, -8.33);

	a = b + c;
	EXPECT_EQ(a.GetReal().GetFraction(), "-833/1000");
	EXPECT_EQ(a.GetImag().GetFraction(), "-733/100");

	c += b;
	EXPECT_EQ(c.GetReal().GetFraction(), "-833/1000");
	EXPECT_EQ(c.GetImag().GetFraction(), "-733/100");
}
TEST(ComplexNumberTest_Plus, C) {
	ComplexNumber a;
	ComplexNumber b(1.5, -9.2);

	a = b + 70.56;
	EXPECT_EQ(a.GetReal().GetFraction(), "3603/50");
	EXPECT_EQ(a.GetImag().GetFraction(), "-46/5");

	b += 70.56;
	EXPECT_EQ(b.GetReal().GetFraction(), "3603/50");
	EXPECT_EQ(b.GetImag().GetFraction(), "-46/5");
}
TEST(ComplexNumberTest_Plus, D) {
	ComplexNumber a;
	ComplexNumber b(10.0512, 4.21);
	ComplexNumber c(1.3, 1.9);

	a = b + c + 10 - 132.222;
	EXPECT_EQ(a.GetReal().GetFraction(), "-277177/2500");
	EXPECT_EQ(a.GetImag().GetFraction(), "611/100");
}
TEST(ComplexNumberTest_Plus, E) {
	ComplexNumber a;
	ComplexNumber b;
	ComplexNumber c;

	a = a + c + 0;
	EXPECT_EQ(a.GetReal().GetFraction(), "0/1");
	EXPECT_EQ(a.GetImag().GetFraction(), "0/1");
}
TEST(ComplexNumberTest_Plus, F) {
	ComplexNumber a(34, 14.045);

	a += 5.15;
	EXPECT_EQ(a.GetReal().GetFraction(), "783/20");
	EXPECT_EQ(a.GetImag().GetFraction(), "2809/200");
}

TEST(ComplexNumberTest_Minus, A) {
	ComplexNumber a;
	ComplexNumber b(1.5, 6);
	ComplexNumber c(1.5, 6);

	a = b - c;
	EXPECT_EQ(a.GetReal().GetFraction(), "0/1");
	EXPECT_EQ(a.GetImag().GetFraction(), "0/1");

	b -= c;
	EXPECT_EQ(b.GetReal().GetFraction(), "0/1");
	EXPECT_EQ(b.GetImag().GetFraction(), "0/1");
}
TEST(ComplexNumberTest_Minus, B) {
	ComplexNumber a;
	ComplexNumber b(31.01, 5);
	ComplexNumber c(2, -5.6);

	a = b - c;
	EXPECT_EQ(a.GetReal().GetFraction(), "2901/100");
	EXPECT_EQ(a.GetImag().GetFraction(), "53/5");

	b -= c;
	EXPECT_EQ(b.GetReal().GetFraction(), "2901/100");
	EXPECT_EQ(b.GetImag().GetFraction(), "53/5");
}
TEST(ComplexNumberTest_Minus, C) {
	ComplexNumber a;
	ComplexNumber b(-8.009, -57.6);
	ComplexNumber c(1.5, 1.5);

	a = b - 4 - c - 41.089 + 2;
	EXPECT_EQ(a.GetReal().GetFraction(), "-26299/500");
	EXPECT_EQ(a.GetImag().GetFraction(), "-591/10");
}
TEST(ComplexNumberTest_Minus, D) {
	ComplexNumber a;
	ComplexNumber b;

	a -= b;
	EXPECT_EQ(a.GetReal().GetFraction(), "0/1");
	EXPECT_EQ(a.GetImag().GetFraction(), "0/1");
}
TEST(ComplexNumberTest_Minus, E) {
	ComplexNumber a(34, 14.045);

	a -= 5;
	EXPECT_EQ(a.GetReal().GetFraction(), "29/1");
	EXPECT_EQ(a.GetImag().GetFraction(), "2809/200");
}

TEST(ComplexNumberTest_Multiplication, A) {
	ComplexNumber a;
	ComplexNumber b;
	ComplexNumber c;

	a = c * b;
	EXPECT_EQ(a.GetReal().GetFraction(), "0/1");
	EXPECT_EQ(a.GetImag().GetFraction(), "0/1");

	c *= b;
	EXPECT_EQ(c.GetReal().GetFraction(), "0/1");
	EXPECT_EQ(c.GetImag().GetFraction(), "0/1");
}
TEST(ComplexNumberTest_Multiplication, B) {
	ComplexNumber a;
	ComplexNumber b(1.5, 2.5);
	ComplexNumber c(87.1, -9);

	a = b * c;
	EXPECT_EQ(a.GetReal().GetFraction(), "3063/20");
	EXPECT_EQ(a.GetImag().GetFraction(), "817/4");

	c *= b;
	EXPECT_EQ(c.GetReal().GetFraction(), "3063/20");
	EXPECT_EQ(c.GetImag().GetFraction(), "817/4");
}
TEST(ComplexNumberTest_Multiplication, C) {
	ComplexNumber a;
	ComplexNumber b(-2, -9);
	ComplexNumber c(25.23, -9);

	a = b * c;
	EXPECT_EQ(a.GetReal().GetFraction(), "-6573/50");
	EXPECT_EQ(a.GetImag().GetFraction(), "-20907/100");

	c *= b;
	EXPECT_EQ(c.GetReal().GetFraction(), "-6573/50");
	EXPECT_EQ(c.GetImag().GetFraction(), "-20907/100");
}
TEST(ComplexNumberTest_Multiplication, D) {
	ComplexNumber a;
	ComplexNumber b(4.8, 20.02);

	a = b * 45.1 * 3;
	EXPECT_EQ(a.GetReal().GetFraction(), "16236/25");
	EXPECT_EQ(a.GetImag().GetFraction(), "1354353/500");
}
TEST(ComplexNumberTest_Multiplication, E) {
	ComplexNumber a(2.5, 1);

	a *= -15;
	EXPECT_EQ(a.GetReal().GetFraction(), "-75/2");
	EXPECT_EQ(a.GetImag().GetFraction(), "-15/1");
}
TEST(ComplexNumberTest_Multiplication, F) {
	ComplexNumber a(-50.76, 20);

	a *= -0.5;
	EXPECT_EQ(a.GetReal().GetFraction(), "1269/50");
	EXPECT_EQ(a.GetImag().GetFraction(), "-10/1");
}

TEST(ComplexNumberTest_Division, A) {
	ComplexNumber a;
	ComplexNumber b(4, 2);
	ComplexNumber c(5, 7);

	a = b / c;
	EXPECT_EQ(a.GetReal().GetFraction(), "17/37");
	EXPECT_EQ(a.GetImag().GetFraction(), "-9/37");

	b /= c;
	EXPECT_EQ(b.GetReal().GetFraction(), "17/37");
	EXPECT_EQ(b.GetImag().GetFraction(), "-9/37");
}
TEST(ComplexNumberTest_Division, B) {
	ComplexNumber a;
	ComplexNumber b(4.5, -9.2);
	ComplexNumber c(-5, 7.2);

	a = b / c;
	EXPECT_EQ(a.GetReal().GetFraction(), "-261/226");
	EXPECT_EQ(a.GetImag().GetFraction(), "20/113");

	b /= c;
	EXPECT_EQ(b.GetReal().GetFraction(), "-261/226");
	EXPECT_EQ(b.GetImag().GetFraction(), "20/113");
}
TEST(ComplexNumberTest_Division, C) {
	ComplexNumber a;
	ComplexNumber c(-122.8, 20);

	a /= c;
	EXPECT_EQ(a.GetReal().GetFraction(), "0/1");
	EXPECT_EQ(a.GetImag().GetFraction(), "0/1");
}
TEST(ComplexNumberTest_Division, D) {
	ComplexNumber a;
	ComplexNumber b(8, 6.07);
	ComplexNumber c(1.5, 0.8);

	a = b / c / 9;
	EXPECT_EQ(a.GetReal().GetFraction(), "8428/13005");
	EXPECT_EQ(a.GetImag().GetFraction(), "541/5202");
}
TEST(ComplexNumberTest_Division, E) {
	ComplexNumber a;
	ComplexNumber b(1.3, 0.89);
	ComplexNumber c(11, 1);

	a = b / c / -5.9;
	EXPECT_EQ(a.GetReal().GetFraction(), "-1519/71980");
	EXPECT_EQ(a.GetImag().GetFraction(), "-849/71980");
}
TEST(ComplexNumberTest_Division, F) {
	ComplexNumber a(5.12, 89);
	a /= 8;
	EXPECT_EQ(a.GetReal().GetFraction(), "16/25");
	EXPECT_EQ(a.GetImag().GetFraction(), "89/8");
}
TEST(ComplexNumberTest_Division, G) {
	ComplexNumber a(5.12, 89);
	//на ноль нельзя делить
	ASSERT_THROW(a /= 0, std::exception);
}

TEST(ComplexNumberTest_Equality, A) {
	ComplexNumber a(1, 1);
	ComplexNumber b(1, 1);
	ASSERT_TRUE(a == b);

	ComplexNumber c(4.5, 92.12);
	ASSERT_FALSE(a == c);

	ComplexNumber d(0);
	ComplexNumber f;
	ASSERT_TRUE(d == f);
}
TEST(ComplexNumberTest_Equality, B) {
	ComplexNumber a(10.221, 10);
	ComplexNumber b(-10.221, -10);
	ASSERT_TRUE(a != b);

	ComplexNumber c(4, 67.56);
	ComplexNumber d(4, 67.56);
	ASSERT_FALSE(c != d);
}
TEST(ComplexNumberTest_Equality, C) {
	ComplexNumber a(5, 90.2);
	ASSERT_TRUE(a != -a);

	ComplexNumber b(11.067, 31.78);
	ComplexNumber c(-11.067, -31.78);
	ASSERT_TRUE(b == -c);
}

TEST(ComplexNumberTest_Abs, A) {
	ComplexNumber a(4, 6);
	ASSERT_TRUE(a.Abs() == sqrt(pow(4, 2) + pow(6, 2)));

	ComplexNumber b(-10.35, 78.1);
	ASSERT_TRUE(b.Abs() == sqrt(pow(-10.35, 2) + pow(78.1, 2)));

	ComplexNumber c(9, 0);
	ASSERT_TRUE(c.Abs() == sqrt(pow(9, 2)));
}

TEST(ComplexNumberTest_Arg, A) {
	ComplexNumber c(10, -0.23);
	ASSERT_TRUE(c.Arg().GetDouble() == -0.0229959);

	ComplexNumber a(1.5, 1.5);
	ASSERT_TRUE(a.Arg().GetDouble() == 0.785398);

	ComplexNumber b(78.12, 56.76);
	ASSERT_TRUE(b.Arg().GetDouble() == 0.628339);

	ComplexNumber d(-1, 4);
	ASSERT_TRUE(d.Arg().GetDouble() == 1.81578);

	ComplexNumber e(-1, -2.7);
	ASSERT_TRUE(e.Arg().GetDouble() == -1.9255);
}

TEST(ComplexNumberTest_Pow, A) {
	ComplexNumber a;
	ComplexNumber b(4, 6);

	a = b.Pow();
	ASSERT_EQ(a.GetReal().GetFraction(), "-20/1");
	ASSERT_EQ(a.GetImag().GetFraction(), "48/1");
}
TEST(ComplexNumberTest_Pow, B) {
	ComplexNumber c;
	ComplexNumber d(-6, -2.5);

	c = d.Pow(3);
	ASSERT_EQ(c.GetReal().GetFraction(), "-207/2");
	ASSERT_EQ(c.GetImag().GetFraction(), "-2035/8");
}
TEST(ComplexNumberTest_Pow, C) {
	ComplexNumber e;
	ComplexNumber f(-2.7, 0);

	e = f.Pow(4);
	ASSERT_EQ(e.GetReal().GetFraction(), "531441/10000");
	ASSERT_EQ(e.GetImag().GetFraction(), "0/1");
}

TEST(ComplexNumberTest_Set, A) {
	ComplexNumber a;
	a.SetReal(5.23);

	ASSERT_EQ(a.GetReal().GetFraction(), "523/100");
	ASSERT_EQ(a.GetImag().GetFraction(), "0/1");

	a.SetImag(-234.002);
	ASSERT_EQ(a.GetReal().GetFraction(), "523/100");
	ASSERT_EQ(a.GetImag().GetFraction(), "-117001/500");
}
TEST(ComplexNumberTest_Set, B) {
	ComplexNumber b(-40, 23.22);
	b.SetReal(5);
	b.SetImag(-1.5);

	ASSERT_EQ(b.GetReal().GetFraction(), "5/1");
	ASSERT_EQ(b.GetImag().GetFraction(), "-3/2");
}

TEST(ComplexNumberTest_ostream, A) {
	std::ofstream fout("test.txt");

	ComplexNumber a(1.4, 80.11);
	fout << a << std::endl;
	fout << std::endl;

	ComplexNumber b;
	fout << b << std::endl;

	fout << std::endl;
	b.SetReal(24.121);
	b.SetImag(0);

	fout << b << std::endl;
}