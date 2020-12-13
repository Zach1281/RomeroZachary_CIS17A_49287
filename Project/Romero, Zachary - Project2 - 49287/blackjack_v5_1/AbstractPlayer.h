#ifndef ABSTRACTPLAYER_H
#define ABSTRACTPLAYER_H
#include <string>
#include <iomanip>
using namespace std;

class AbstractPlayer {
private:
    string name;
    int money;
public:
    virtual void win();
    virtual void loss();
};

#endif /* ABSTRACTPLAYER_H */

