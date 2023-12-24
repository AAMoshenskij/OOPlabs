#pragma once
#include "npc.hpp"

struct Pegasus : public NPC {
    Pegasus(int x, int y);
    Pegasus(std::istream &is);
    void print() override;
    void print(std::ostream &os) override;
    void save(std::ostream &os) override;
    // bool is_Pegasus() const override;
    bool accept(std::shared_ptr<NPC> visitor) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Eichhorn> other) override;
    bool fight(std::shared_ptr<Pegasus> other) override;
    friend std::ostream &operator<<(std::ostream &os, Pegasus &pegasus);
};
