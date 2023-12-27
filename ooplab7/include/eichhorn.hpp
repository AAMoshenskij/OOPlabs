#pragma once
#include "npc.hpp"

struct Eichhorn : public NPC {
    Eichhorn(int x, int y);
    Eichhorn(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;
    bool fight(std::shared_ptr<Pegasus> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Eichhorn> other) override;
    bool accept(std::shared_ptr<NPC> visitor) override;

    friend std::ostream &operator<<(std::ostream &os, Eichhorn &eichhorn);
};