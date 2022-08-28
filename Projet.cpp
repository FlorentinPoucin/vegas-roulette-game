#include <Imagine/Graphics.h>
#include <iostream>
#include <QtMath>
#include <cmath>
#include <Imagine/Images.h>

#include "roullette.h"
#include "tapis.h"
#include "affichage.h"

using namespace std;
using namespace Imagine;


int main()
{
    int S=100; // argent du joueur
    int result; // stocke le résultat de la roulette à chaque tour de jeu
    int mise[49]; // liste stockant les mises sur chaque case du tapis

    openWindow(width,height);

    animationdebut();

    fillRect(0,0,width, height,BLACK);
    AfficheTapis(0,0);
    AfficheRoullette(300,0);

    while(S>0){
        initialisemise(mise);
        misecomplete(S,mise);
        result=Spinroullette();
        actualiseargent(mise,S,result);
        AfficheTapis(0,0);
    }

    milliSleep(1000);
    animationfin();
    cout<<"Bankrupt"<<endl;
    endGraphics();
    return 0;
}
