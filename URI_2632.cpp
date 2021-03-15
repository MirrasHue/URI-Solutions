#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <vector>

enum Spell
{
    fire,
    water,
    earth,
    air,

    none
};

class Point2D
{
public:
    float x, y;
    Point2D(float _x, float _y) : x(_x), y(_y){}
};

class EnemyUnits : public Point2D
{
public:
    float width, height;

    EnemyUnits(float x0, float y0, float _width, float _height);
};

EnemyUnits::EnemyUnits(float x0, float y0, float _width, float _height)
    : Point2D(x0 + _width / 2.f, y0 + _height / 2.f), width(_width), height(_height)
{}

Spell GetSpellByName(const std::map<std::string, Spell>& StrToSpell, const std::string& spellName)
{
    /// If itr is equal to the end of this map, this string is not a spell name
    auto itr = StrToSpell.find(spellName);
    return (itr != StrToSpell.end()) ? itr->second : Spell::none;
}

bool IsOverlapping(const Point2D& DropSpot, const EnemyUnits& Army, const std::vector<int>& SpellProperties, Spell SpellType, int level)
{
    float x = std::abs(DropSpot.x - Army.x);
    float y = std::abs(DropSpot.y - Army.y);

    if(x > (Army.width / 2.f + SpellProperties[4*SpellType + level])) return false;
    if(y > (Army.height / 2.f + SpellProperties[4*SpellType + level])) return false;

    if(x <= (Army.width / 2.f)) return true;
    if(y <= (Army.height / 2.f)) return true;

    float Dist_DS_Army = pow(x - (Army.width / 2.f), 2) + pow(y - (Army.height / 2.f), 2);
    return (Dist_DS_Army <= pow(SpellProperties[4*SpellType + level], 2)) ? true : false;
}

int main()
{    
    std::map<std::string, Spell> StrToSpell;
    StrToSpell.emplace("fire", Spell::fire);
    StrToSpell.emplace("water", Spell::water);
    StrToSpell.emplace("earth", Spell::earth);
    StrToSpell.emplace("air", Spell::air);

    std::vector<int> SpellProperties =
    {
        ///Damage, radius lv1, radius lv2, radius lv3
        200, 20, 30, 50,
        300, 10, 25, 40,
        400, 25, 55, 70,
        100, 18, 38, 60
    };

    int t, width, height, x0, y0, cx, cy, level;
    std::string spellName;

    std::cin>>t;

    for(int i = 0; i < t; i++)
    {
        std::cin>>width>>height>>x0>>y0;
        std::cin>>spellName>>level>>cx>>cy;

        Spell SpellType = GetSpellByName(StrToSpell, spellName);

        if(SpellType != Spell::none)
        {
            Point2D DropSpot(cx, cy);
            EnemyUnits Army(x0, y0, width, height);

            bool overlap = IsOverlapping(DropSpot, Army, SpellProperties, SpellType, level);

            if(overlap)
                std::cout<<SpellProperties[4*SpellType]<<'\n';
            else
                std::cout<<0<<'\n';
        }
    }

    return 0;
}
