#include "gtest/gtest.h"
#include <iostream>

using namespace std;

class CMapTest : public ::testing::Test 
{
protected:
	CMapTest()
	{

	}

	virtual void SetUp() 
	{
		_t = 82;
	}

	virtual void TearDown() 
	{
	}

	int _t;
};

TEST_F(CMapTest, CheckIntValue)
{
	//CMap m;
	EXPECT_EQ(82, _t);
}

int main(int argc, char **argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	system("pause");
	return 0;
}