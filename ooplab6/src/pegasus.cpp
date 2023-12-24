#include "eichhorn.hpp"
#include "pegasus.hpp"
#include "knight.hpp"

Pegasus::Pegasus(int x, int y) : NPC(PegasusType, x, y) {}
Pegasus::Pegasus(std::istream &is) : NPC(PegasusType, is) {}

void Pegasus::print() {
    std::cout << *this;
}

void Pegasus::print(std::ostream &outfs) {
    outfs << *this;
}

void Pegasus::save(std::ostream &os) {
    os << PegasusType << std::endl;
    NPC::save(os);
}

// bool Pegasus::is_Pegasus() const {
//     return true;
// }

bool Pegasus::accept(std::shared_ptr<NPC> visitor) {
    std::shared_ptr<Pegasus> This = std::make_shared<Pegasus>(*this);
    return visitor->visit(This);
}


bool Pegasus::fight(std::shared_ptr<Eichhorn> other) {
    fight_notify(other, false);
    return false;
}

bool Pegasus::fight(std::shared_ptr<Knight> other) {
    fight_notify(other, true);
    return true;
}

bool Pegasus::fight(std::shared_ptr<Pegasus> other) {
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Pegasus &pegasus) {
    os << "Pegasus: " << *static_cast<NPC *>(&pegasus) << std::endl;
    return os;
}
