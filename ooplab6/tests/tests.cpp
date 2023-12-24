#include <gtest/gtest.h>
#include "npc.hpp"
#include "eichhorn.hpp"
#include "pegasus.hpp"
#include "knight.hpp"
#include "fighting.hpp"

TEST(NPCInteractions, test1) {
    std::shared_ptr<NPC> eichhorn = std::make_shared<Eichhorn>(0, 0);
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(1, 1);

    bool murder = eichhorn->accept(knight);
    ASSERT_TRUE(murder);
}

TEST(NPCInteractions, test2) {
    std::shared_ptr<NPC> eichhorn = std::make_shared<Eichhorn>(0, 0);
    std::shared_ptr<NPC> pegasus = std::make_shared<Pegasus>(1, 1);

    bool murder = eichhorn->accept(pegasus);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test3) {
    std::shared_ptr<NPC> eichhorn1 = std::make_shared<Eichhorn>(0, 0);
    std::shared_ptr<NPC> eichhorn2 = std::make_shared<Eichhorn>(1, 1);

    bool murder = eichhorn1->accept(eichhorn2);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test4) {
    std::shared_ptr<NPC> knight1 = std::make_shared<Knight>(0, 0);
    std::shared_ptr<NPC> knight2 = std::make_shared<Knight>(1, 1);

    bool murder = knight1->accept(knight2);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test5) {
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(0, 0);
    std::shared_ptr<NPC> pegasus = std::make_shared<Pegasus>(1, 1);

    bool murder = knight->accept(pegasus);
    ASSERT_TRUE(murder);
}

TEST(NPCInteractions, test6) {
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(0, 0);
    std::shared_ptr<NPC> eichhorn = std::make_shared<Eichhorn>(1, 1);

    bool murder = knight->accept(eichhorn);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test7) {
    std::shared_ptr<NPC> pegasus = std::make_shared<Pegasus>(0, 0);
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(1, 1);

    bool murder = pegasus->accept(knight);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test8) {
    std::shared_ptr<NPC> pegasus1 = std::make_shared<Pegasus>(0, 0);
    std::shared_ptr<NPC> pegasus2 = std::make_shared<Pegasus>(1, 1);

    bool murder = pegasus1->accept(pegasus2);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test9) {
    std::shared_ptr<NPC> pegasus = std::make_shared<Pegasus>(0, 0);
    std::shared_ptr<NPC> eichhorn = std::make_shared<Eichhorn>(1, 1);

    bool murder = pegasus->accept(eichhorn);
    ASSERT_TRUE(murder);
}

TEST(ObserverTests, test) {
    std::shared_ptr<NPC> pegasus = std::make_shared<Pegasus>(0, 0);
    std::shared_ptr<NPC> eichhorn = std::make_shared<Eichhorn>(1, 1);
    
    eichhorn->subscribe(TextObserver::get());
    testing::internal::CaptureStdout();
    pegasus->accept(eichhorn);
    std::string output = testing::internal::GetCapturedStdout();
    
    testing::internal::CaptureStdout();
    std::cout << std::endl << "Murder --------" << std::endl <<  "Eichhorn: { x:1, y:1} " << std::endl
              << "pegasus: { x:0, y:0} " << std::endl;
    std::string answer = testing::internal::GetCapturedStdout();
    
    ASSERT_TRUE(output == answer);
}

int main(int argc, char** argv){

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
