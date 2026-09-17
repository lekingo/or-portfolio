#include <gtest/gtest.h>
#include <stdexcept>
#include <array>

class NoNegArgs{
    public:
    NoNegArgs(int x){
        if(x<0){
            throw std::invalid_argument("Argument cannot < 0.");
        }
    }
};


class SquareTest : public ::testing::TestWithParam<std::array<int, 2>>{
protected: 
    void SetUp() override{
        
    }
};

class Rectangle{
    int _wi;
    int _le;
public:    
    Rectangle(int wi, int le){
        _wi = wi;
        _le = le;
    }

    ~Rectangle(){

    }

    int area(){
        return _wi * _le;
    }

    int perimeter(){
        return 2 * _wi + 2 * _le;
    }
};


class RectangleTest : public ::testing::Test {
protected:
    void SetUp() override {
        // runs before every TEST_F using this fixture
        rect = Rectangle(4, 5);
    }

    // shared member(s), accessible in every test below
    Rectangle rect{0, 0};
};


bool isEvent(int n){
    if(n>5){
        return true;
    } else {
        return false;
    };

    std::cout << "something went wrong!!" << std::endl;
    return false;
}

TEST(SanityCheck, BasicMath) {
    EXPECT_EQ(2 + 2, 4);
}

TEST(SanityCheck, StringsMatch) {
    EXPECT_STREQ("hello", "hello");
}

TEST(TestChallenges, ExpectTrue){
    EXPECT_TRUE(isEvent(6));
}

TEST(TestChallenges, ExpectFalse){
    EXPECT_FALSE(isEvent(3));
}

TEST(TestChallenges, FloatingChallenge1){
    EXPECT_NE(0.1+0.2, 0.3);
}

TEST(TestChallenges, FloatingChallenge2){
    EXPECT_NEAR(0.1+0.2, 0.3, 1e-9);
}

TEST_F(RectangleTest, AreaIsCorrect) {
    EXPECT_EQ(rect.area(), 20);
}

TEST_F(RectangleTest, PerimeterIsCorrect) {
    EXPECT_EQ(rect.perimeter(), 18);
}

TEST(TestChallenges, RaiseArgInvalid){
    EXPECT_THROW(NoNegArgs(-1), std::invalid_argument);
}

TEST(TestChallenges, RaiseArgInvalidNoThrow){
    EXPECT_NO_THROW(NoNegArgs(1));
}

TEST_P(SquareTest, CheckSquareNumbers){
    std::array<int, 2> n2 = GetParam();
    EXPECT_EQ(n2[0] * n2[0], n2[1]);
}

INSTANTIATE_TEST_SUITE_P(
    SqaureNumberTesters, 
    SquareTest, 
    ::testing::Values(
        std::array<int,2> {2, 4}, 
        std::array<int,2>{6, 36})
);

