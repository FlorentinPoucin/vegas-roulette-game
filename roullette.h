#ifndef ROULLETTE_H
#define ROULLETTE_H

#include <Imagine/Graphics.h>
#include <Imagine/Images.h>
#include "affichage.h"


using namespace Imagine;

#pragma once

const double dt = 0.05;
const int nb_tour=7;
const int rotation[37]={0,32,15,19,4,21,2,25,17,34,6,27,13,36,11,30,8,23,10,5,24,16,33,1,20,14,31,9,22,18,29,7,28,12,35,3,26};

void InitRandom();

struct Vector {
    double x;
    double y;
};

class Balle {
public:
    Vector pospol;
    Color col;
    double r;
};

void AfficheBallePol (Balle D, int x, int y);
void DecaleBalle (Balle &D);
void AfficheRoullette (int x, int y);
int Spinroullette ();


#endif // ROULLETTE_H
