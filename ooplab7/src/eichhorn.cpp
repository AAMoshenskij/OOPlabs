#include "eichhorn.hpp"
#include "pegasus.hpp"
#include "knight.hpp"

Eichhorn::Eichhorn(int x, int y) : NPC(EichhornType, x, y) {}
Eichhorn::Eichhorn(std::istream &is) : NPC(EichhornType, is) {}

bool Eichhorn::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Eichhorn>(this,[](Eichhorn*){}));
}

void Eichhorn::print()
{
    std::cout << *this;
}

void Eichhorn::save(std::ostream &os)
{
    os << EichhornType << std::endl;
    NPC::save(os);
}


bool Eichhorn::fight(std::shared_ptr<Pegasus> other)
{
    fight_notify(other, true);
    return true;
}

bool Eichhorn::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, false);
    return false;
}

bool Eichhorn::fight(std::shared_ptr<Eichhorn> other)
{
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Eichhorn &eichhorn)
{
    os << "eichhorn: " << *static_cast<NPC *>(&eichhorn) << std::endl;
    return os;
}

