#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>

// type for npcs
struct NPC;
struct Knight;
struct Eichhorn;
struct Pegasus;

using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType {
    Unknown = 0,
    KnightType = 1,
    EichhornType = 2,
    PegasusType = 3
};

struct IFightObserver {
    virtual void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender,bool win) = 0;
};

struct NPC : public std::enable_shared_from_this<NPC> {
    NpcType type;
    int x{0};
    int y{0};
    std::vector<std::shared_ptr<IFightObserver>> observers;

    NPC(NpcType t, int _x, int _y);
    NPC(NpcType t, std::istream &is);

    void subscribe(std::shared_ptr<IFightObserver>observer ); //add_observer
    void fight_notify(const std::shared_ptr<NPC> defender,bool win);
    virtual bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;

    // virtual bool is_knight() const;
    // virtual bool is_Eichhorn() const;
    // virtual bool is_Pegasus() const ;

    // INSTEAD this I will use ...
    virtual bool accept(std::shared_ptr<NPC> visitor) = 0;
    bool visit(std::shared_ptr<Knight> ref);
    bool visit(std::shared_ptr<Eichhorn> ref);
    bool visit(std::shared_ptr<Pegasus> ref);
    //

    virtual bool fight(std::shared_ptr<Knight> other) = 0;
    virtual bool fight(std::shared_ptr<Eichhorn> other) = 0;
    virtual bool fight(std::shared_ptr<Pegasus> other) = 0;
    virtual void print() = 0;
    virtual void print(std::ostream &os) = 0;

    virtual void save(std::ostream &os);

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);
};
