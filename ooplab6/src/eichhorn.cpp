#include "eichhorn.hpp"
#include "pegasus.hpp"
#include "knight.hpp"

Eichhorn::Eichhorn(int x, int y) : NPC(EichhornType, x, y) {}
Eichhorn::Eichhorn(std::istream &is) : NPC(EichhornType, is) {}

void Eichhorn::print() {
    std::cout << *this;
}

void Eichhorn::print(std::ostream &outfs) {
    outfs << *this;
}

void Eichhorn::save(std::ostream &os) {
    os << EichhornType << std::endl;
    NPC::save(os);
}
// bool Eichhorn::is_Eichhorn() const {
//     return true;
// }

bool Eichhorn::accept(std::shared_ptr<NPC> visitor) {
    std::shared_ptr<Eichhorn> This = std::make_shared<Eichhorn>(*this);
    return visitor->visit(This);
}

bool Eichhorn::fight(std::shared_ptr<Knight> other) {
    fight_notify(other, false);
    return false;
}

bool Eichhorn::fight(std::shared_ptr<Eichhorn> other) {
    fight_notify(other, false);
    return false;
}

bool Eichhorn::fight(std::shared_ptr<Pegasus> other) {
    fight_notify(other, true);
    return true;
}

std::ostream &operator<<(std::ostream &os, Eichhorn &eichhorn) {
    os << "Eichhorn: " << *static_cast<NPC *>(&eichhorn) << std::endl;
    return os;
}
