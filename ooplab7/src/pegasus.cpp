#include "pegasus.hpp"
#include "eichhorn.hpp"
#include "knight.hpp"

Pegasus::Pegasus(int x, int y) : NPC(PegasusType, x, y) {}
Pegasus::Pegasus(std::istream &is) : NPC(PegasusType, is) {}

void Pegasus::print() {
    std::cout << *this;
}

bool Pegasus::accept(std::shared_ptr<NPC> visitor) {
    return visitor->fight(std::shared_ptr<Pegasus>(this,[](Pegasus*){}));
}

void Pegasus::save(std::ostream &os) {
    os << PegasusType << std::endl;
    NPC::save(os);
}


bool Pegasus::fight(std::shared_ptr<Pegasus> other) {
    fight_notify(other, false);
    return false;
}

bool Pegasus::fight(std::shared_ptr<Knight> other) {
    fight_notify(other, true);
    return true;
}

bool Pegasus::fight(std::shared_ptr<Eichhorn> other) {
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Pegasus &pegasus) {
    os << "pegasus: " << *static_cast<NPC *>(&pegasus) << std::endl;
    return os;
}