#pragma once
#include "npc.hpp"

struct Knight : public NPC {
    Knight(int x, int y);
    Knight(std::istream &is);
    void print() override;
    void print(std::ostream &os) override;
    void save(std::ostream &os) override;
    // bool is_knight() const override;
    bool accept(std::shared_ptr<NPC> visitor) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Eichhorn> other) override;
    bool fight(std::shared_ptr<Pegasus> other) override;
    friend std::ostream &operator<<(std::ostream &os, Knight &knight);
};