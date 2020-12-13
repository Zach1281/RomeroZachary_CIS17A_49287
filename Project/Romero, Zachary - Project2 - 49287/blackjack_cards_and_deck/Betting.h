/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Betting.h
 * Author: zacha
 *
 * Created on December 11, 2020, 8:20 PM
 */

#ifndef BETTING_H
#define BETTING_H

class Betting {
protected:
    bool isHitting;
    int money;
public:
    Betting(int, bool);
    int win();
    int lose();
};

#endif /* BETTING_H */

