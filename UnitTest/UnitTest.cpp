#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_7.3_REC/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(TestFirstZeroColumn)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];


			a[0][0] = 1; a[0][1] = 0; a[0][2] = 3;
			a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
			a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

			int result = firstZeroColumn(a, rowCount, colCount, 0, 0, -1);

			Assert::AreEqual(1, result);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestRowSum)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];


			a[0][0] = -2; a[0][1] = 4; a[0][2] = -6;
			a[1][0] = 1; a[1][1] = 3; a[1][2] = 5;
			a[2][0] = -8; a[2][1] = 6; a[2][2] = -4;

			int result = rowSum(a, 0, colCount, 0, 0);

			Assert::AreEqual(-8, result);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
		TEST_METHOD(TestChangeRows)
		{
            const int rowCount = 3;
            const int colCount = 4;
            int** a = new int* [rowCount];

            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            a[0][0] = 2; a[0][1] = -4; a[0][2] = 6; a[0][3] = 8;
            a[1][0] = -1; a[1][1] = 3; a[1][2] = -5; a[1][3] = 7;
            a[2][0] = -2; a[2][1] = 4; a[2][2] = -6; a[2][3] = 8;

            changeRows(a, rowCount, colCount, 0, 0);

            Assert::AreEqual(a[0][0], -1);
            Assert::AreEqual(a[1][1], -4);
            Assert::AreEqual(a[2][1], 4);
            Assert::AreEqual(a[2][3], 8);

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;

		}
	};
}
