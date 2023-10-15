#include <gtest/gtest.h>
#include "four.h" 


TEST(test_01, basic_test_set){
    bool checked = false; //проверка на корректность вычитания (из меньшего нельзя вычесть большее)
    try{
        
        Four bf_great {"3123202"};
        Four bf_small {"12"};

        bf_small.deduct(bf_great);

    }catch(exception &ex){
        checked = true;
    }

    ASSERT_TRUE(checked);
}

TEST(test_02, basic_test_set){
    Four bf_great {"1223"}; //проверка на вычитание нуля
    Four bf_small {"0"};

    Four bf_copy {bf_great};

    bf_great.deduct(bf_small);

    ASSERT_TRUE(bf_great.equal(bf_copy));
}

TEST(test_03, basic_test_set){
    bool checked = false;
    try{
        
        Four bf_null {""};

    }catch(exception &ex){ //no number was given
        checked = true;
    }

    ASSERT_TRUE(checked);
}

TEST(test_04, basic_test_set){
    Four bf_great {"1021333321"};
    Four bf_small {"0000000333"};
    
    ASSERT_TRUE(bf_great.greater(bf_small));
}

TEST(test_05, basic_test_set){
    bool checked = false;//check exception of non-4-decimal numbers
    try{
        Four not_11dec {"43639784637"};
    }
    catch(exception &ex){
        checked = true;
    }

    ASSERT_TRUE(checked);
}

TEST(test_06, basic_test_set){  //простая проверка сложения
    Four bf_great {"1023"}; 
    Four bf_small {"12"};
    bf_great.add(bf_small);
    ASSERT_TRUE(bf_great.equal(Four{"1101"}));
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
