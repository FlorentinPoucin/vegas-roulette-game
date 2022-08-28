#ifndef TAPIS_H
#define TAPIS_H


#include <Imagine/Graphics.h>
using namespace Imagine;

#pragma once

const int rouge[18]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
const int noir[18]={2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};


void AfficheTapis (int x, int y);

void initialisemise(int mise[49]);

void actualiseargent(int mise[49], int &S, int result);

void miseelementaire(int jeton, int&S, int mise[49], int x, int y);

void misecomplete(int&S, int mise[49]);

void selectionjeton(int &jeton, int x,int y,bool &cliquejeton);


#endif // TAPIS_H
