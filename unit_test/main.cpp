#include "gtest/gtest.h"
#include <iostream>
#include "../CMap.h"
#include "../CInputEnglish.h"

using namespace std;

class CMapTest : public ::testing::Test 
{
protected:
	CMapTest()
	{
		//CInputEnglish inputEnglish(_map);


		
	}

	virtual void SetUp() 
	{
		//_t = 82;
	}

	virtual void TearDown() 
	{
	}


	CMap _map;
};

TEST_F(CMapTest, CheckLoadingFile)
{
	CInputEnglish inputEnglish(_map);
	EXPECT_EQ(-1, inputEnglish.ReadFile("Text999.txt"));

}

TEST_F(CMapTest, CheckContent)
{
	CInputEnglish inputEnglish(_map);

	// Sevent times "The".
	// Five times "the".
	inputEnglish.ReadFile("text1.txt");

	EXPECT_EQ(7, _map.GetWordMap("The").GetWord().GetCount());
	EXPECT_EQ(5, _map.GetWordMap("the").GetWord().GetCount());
	EXPECT_EQ(5, _map.GetWordMap(".").GetWord().GetCount());
	EXPECT_EQ(3, _map.GetWordMap(",").GetWord().GetCount());
	EXPECT_EQ(1, _map.GetWordMap(";").GetWord().GetCount());
}

TEST_F(CMapTest, CheckRepeatingContent)
{
	CInputEnglish inputEnglish(_map);
	inputEnglish.ReadFile("Text2.txt");

	EXPECT_EQ(30, _map.GetWordMap("Alex").GetWord().GetCount());
}

int main(int argc, char **argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	system("pause");
	return 0;
}