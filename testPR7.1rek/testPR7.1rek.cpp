#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.1rek/pr7.1rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testPR71rek
{
	TEST_CLASS(testPR71rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int a[2][3] = {
               {-3, 2, 5},
               {0, -4, 7}
            };
            int* C[2] = { a[0], a[1] };
            int S = 0;
            int k = 0;
            Sum(C, 2, 3, S, k, 0, 0);
            Assert::AreEqual(-5, S);
            Assert::AreEqual(4, k);
		}
	};
}
