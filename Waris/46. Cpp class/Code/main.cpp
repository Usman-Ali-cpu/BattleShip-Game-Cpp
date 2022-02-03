#include <iostream>
#include <vector>

using namespace std;

enum Type
{
    Type1,
    Type2,
    Type3,
    Type4,
};

struct Game
{
    string name;
    enum Type t;
    int hitPoints;
    friend ostream &operator<<(ostream &out, const Game &g);
    Game operator++(int)
    {
        Game temp;
        temp.hitPoints++;
        return temp;
    }
    Game operator--(int)
    {
        Game temp;
        temp.hitPoints--;
        return temp;
    }
};

ostream &operator<<(ostream &out, const Game &g)
{
    out << g.name << "  ";
    out << g.t << "    ";
    out << g.hitPoints << "  ";
    return out;
}
int main()
{
    vector<Game> game;
    Game g1;
    g1.name = "Name1";
    g1.hitPoints = 1;
    g1.t = Type1;
    game.push_back(g1);
    Game g2;
    g2.name = "Name2";
    g2.hitPoints = 2;
    g2.t = Type2;
    game.push_back(g2);
    Game g3;
    g3.name = "Name3";
    g3.hitPoints = 3;
    g3.t = Type3;
    game.push_back(g3);
    Game g4;
    g4.name = "Name4";
    g4.hitPoints = 4;
    g4.t = Type4;
    g4--;
    game.push_back(g4);
    Game g5;
    g5.name = "Name5";
    g5.hitPoints = 5;
    g5.t = Type1;
    game.push_back(g5);
    Game shield;
    shield.name = "Name6";
    shield.hitPoints = 6;
    shield++;
    shield.t = Type2;
    game.push_back(shield);
    cout << "Name  Type  HitPoint" << endl;
    cout << g1 << "\n";
    cout << g2 << "\n";
    cout << g3 << "\n";
    cout << g4 << "\n";
    cout << g5 << "\n";
    cout << shield << "\n";

    return 0;
}