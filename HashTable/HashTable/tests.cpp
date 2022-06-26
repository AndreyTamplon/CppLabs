#include <iostream>
#include <gtest/gtest.h>
#include "HashTable.h"
#include <vector>
#include <iterator>
#include <sstream>
class Fixation : public ::testing::Test
{
protected:
    HashTable filled_test_table;
    HashTable empty_test_table;
    std::string test_text = {"We're no strangers to love\n"
                             "You know the rules and so do I\n"
                             "A full commitment's what I'm thinking of\n"
                             "You wouldn't get this from any other guy\n"
                             "I just wanna tell you how I'm feeling\n"
                             "Gotta make you understand\n"
                             "Never gonna give you up\n"
                             "Never gonna let you down\n"
                             "Never gonna run around and desert you\n"
                             "Never gonna make you cry\n"
                             "Never gonna say goodbye\n"
                             "Never gonna tell a lie and hurt you\n"
                             "We've known each other for so long\n"
                             "Your heart's been aching but you're too shy to say it\n"
                             "Inside we both know what's been going on\n"
                             "We know the game and we're gonna play it\n"
                             "And if you ask me how I'm feeling\n"
                             "Don't tell me you're too blind to see\n"
                             "Never gonna give you up\n"
                             "Never gonna let you down\n"
                             "Never gonna run around and desert you\n"
                             "Never gonna make you cry\n"
                             "Never gonna say goodbye\n"
                             "Never gonna tell a lie and hurt you\n"
                             "Never gonna give you up\n"
                             "Never gonna let you down\n"
                             "Never gonna run around and desert you\n"
                             "Never gonna make you cry\n"
                             "Never gonna say goodbye\n"
                             "Never gonna tell a lie and hurt you\n"
                             "Never gonna give, never gonna give\n"
                             "(Give you up)\n"
                             "We've known each other for so long\n"
                             "Your heart's been aching but you're too shy to say it\n"
                             "Inside we both know what's been going on\n"
                             "We know the game and we're gonna play it\n"
                             "I just wanna tell you how I'm feeling\n"
                             "Gotta make you understand\n"
                             "Never gonna give you up\n"
                             "Never gonna let you down\n"
                             "Never gonna run around and desert you\n"
                             "Never gonna make you cry\n"
                             "Never gonna say goodbye\n"
                             "Never gonna tell a lie and hurt you\n"
                             "Never gonna give you up\n"
                             "Never gonna let you down\n"
                             "Never gonna run around and desert you\n"
                             "Never gonna make you cry\n"
                             "Never gonna say goodbye\n"
                             "Never gonna tell a lie and hurt you\n"
                             "Never gonna give you up\n"
                             "Never gonna let you down\n"
                             "Never gonna run around and desert you\n"
                             "Never gonna make you cry\n"
                             "Never gonna say goodbye"};
    void SetUp()
    {
        std::istringstream iss(test_text);
        std::vector<std::string> splitted_text((std::istream_iterator<std::string>(iss)),
                                               std::istream_iterator<std::string>());
        for(unsigned int i = 0; i < splitted_text.size(); ++i)
        {

            filled_test_table.insert(splitted_text[i], {i, i + 40});
        }
    }

};
TEST_F(Fixation, CopyConstructor)
{
    HashTable copy(filled_test_table);
    EXPECT_EQ(copy, filled_test_table);
}

TEST_F(Fixation, empty)
{
    EXPECT_EQ(empty_test_table.empty(), true);
    EXPECT_EQ(filled_test_table.empty(), false);
}

TEST_F(Fixation, MoveConstructor)
{
    HashTable original_table(filled_test_table);
    HashTable moved_table(std::move(filled_test_table));
    EXPECT_EQ(moved_table, original_table);
    EXPECT_EQ(filled_test_table.empty(), true);
}

TEST_F(Fixation, CopyOperator)
{
    HashTable copy = filled_test_table;
    EXPECT_EQ(copy, filled_test_table);
}

TEST_F(Fixation, MoveOperator)
{
    HashTable original_table(filled_test_table);
    HashTable moved_table = std::move(filled_test_table);
    EXPECT_EQ(moved_table, original_table);
    EXPECT_EQ(filled_test_table.empty(), true);
}

TEST_F(Fixation, swap)
{
    HashTable copy = filled_test_table;
    filled_test_table.swap(empty_test_table);
    EXPECT_EQ(copy, empty_test_table);
    EXPECT_EQ(filled_test_table.empty(), true);
}

TEST_F(Fixation, contains)
{
    EXPECT_EQ(filled_test_table.contains("one"), false);
    EXPECT_EQ(filled_test_table.contains("two"), false);
    EXPECT_EQ(filled_test_table.contains("three"), false);
    EXPECT_EQ(filled_test_table.contains("four"), false);
    EXPECT_EQ(filled_test_table.contains("five"), false);
    EXPECT_EQ(filled_test_table.contains("Gotta"), true);
    EXPECT_EQ(filled_test_table.contains("make"), true);
    EXPECT_EQ(filled_test_table.contains("you"), true);
    EXPECT_EQ(filled_test_table.contains("understand"), true);
}

TEST_F(Fixation, clear)
{
    filled_test_table.clear();
    EXPECT_EQ(filled_test_table.empty(), true);
    EXPECT_EQ(filled_test_table.contains("never"), false);
}

TEST_F(Fixation, erase)
{

    filled_test_table.erase("never");
    EXPECT_EQ(filled_test_table.contains("never"), false);
    filled_test_table.erase("gonna");
    EXPECT_EQ(filled_test_table.contains("gonna"), false);
    filled_test_table.erase("give");
    EXPECT_EQ(filled_test_table.contains("give"), false);
    filled_test_table.erase("you");
    EXPECT_EQ(filled_test_table.contains("you"), false);
    filled_test_table.erase("up");
    EXPECT_EQ(filled_test_table.contains("up"), false);
}

TEST_F(Fixation, SquareBrackets)
{
    EXPECT_EQ((filled_test_table)["strangers"].age, 2);
    EXPECT_EQ((filled_test_table)["strangers"].weight, 42);
    (filled_test_table)["strangers"].age = 20;
    (filled_test_table)["strangers"].weight = 205;
    EXPECT_EQ((filled_test_table)["strangers"].age, 20);
    EXPECT_EQ((filled_test_table)["strangers"].weight, 205);
    EXPECT_EQ((filled_test_table)["not existing word"].age, 0);
    EXPECT_EQ((filled_test_table)["not existing word"].weight, 0);

}

TEST_F(Fixation, at)
{
    EXPECT_EQ((filled_test_table).at("strangers").age, 2);
    EXPECT_EQ((filled_test_table).at("strangers").weight, 42);
    (filled_test_table).at("strangers").age = 20;
    (filled_test_table).at("strangers").weight = 205;
    EXPECT_EQ((filled_test_table).at("strangers").age, 20);
    EXPECT_EQ((filled_test_table).at("strangers").weight, 205);
    ASSERT_THROW((filled_test_table).at("not existing word").age, std::out_of_range);
}

TEST_F(Fixation, insert)
{
    empty_test_table.insert("word", {1, 2});
    EXPECT_EQ(empty_test_table.contains("word"), true);
    EXPECT_EQ((empty_test_table)["word"].age, 1);
    EXPECT_EQ((empty_test_table)["word"].weight, 2);
}

TEST_F(Fixation, equality)
{
    HashTable copy = filled_test_table;
    EXPECT_EQ(copy == filled_test_table, true);
    EXPECT_EQ(copy == empty_test_table, false);
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
