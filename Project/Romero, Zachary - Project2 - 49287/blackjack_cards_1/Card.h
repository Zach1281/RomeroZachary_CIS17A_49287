#ifndef CARD_H
#define CARD_H

class Card {
private:
    char cardNum;
public:
    Card(char);
    char value();
    char face();
    char suit();
};

#endif /* CARD_H */

