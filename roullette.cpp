#include "roullette.h"
#include <Imagine/Graphics.h>
#define _USE_MATH_DEFINES
#include <iostream>
#include <QtMath>
#include <cmath>
#include <Imagine/Images.h>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace Imagine;

void InitRandom()
{
    srand((unsigned int)time(0));
}

void AfficheBallePol (Balle D, int x, int y)
{
     fillCircle(int(x+D.pospol.x*cos(D.pospol.y)),y+int(D.pospol.x*sin(D.pospol.y)),int(D.r),D.col);
}

void DecaleBalle(Balle &D)
{
    D.pospol.y+=2*M_PI/37.;
}

void AfficheRoullette (int x, int y){
    int w,h;
    byte* rgb;
    loadColorImage(srcPath("images/Roulettefinale.png"),rgb,w,h);
    NativeBitmap roulette(w,h);
    roulette.setColorImage(0,0,rgb,w,h);
    putNativeBitmap(x,y,roulette);
    delete[] rgb;
}

int Spinroullette (){
    int w,h;
    byte* rgb;
    loadColorImage(srcPath("images/Roulettefinale.png"),rgb,w,h);
    NativeBitmap roulette(w,h);
    roulette.setColorImage(0,0,rgb,w,h);
    putNativeBitmap(300,0,roulette);

     Balle B ;
         B.pospol.x = 163.;
         B.pospol.y = -M_PI/2.;
         B.r = 6.;
         B.col = WHITE ; //Color(230,180,20)

    InitRandom();
    int N;
    N=rand()%37;

    cout << "Rien ne va plus" << endl;
    int caseroue;
    for(int i=0; i<37; i++){
        if (N==rotation[i]){
            caseroue=i;
            break;
        }
    }

    int dt=10;
    for (int j=0; j<37*nb_tour+24; j++){
        putNativeBitmap(300,0,roulette);
        AfficheBallePol(B, 540, 240);
        DecaleBalle(B);
        milliSleep(dt);
        dt+=0.5;
    }

    for (int k=0; k<50+caseroue+1; k++){
        putNativeBitmap(300,0,roulette);
        AfficheBallePol(B, 540, 240);
        DecaleBalle(B);
        milliSleep(dt);
        dt+=k/10;
    }

    string couleur;
    if(int(caseroue/2)-caseroue/2.==0){
        couleur=" noir";
    }
    else{
        couleur=" rouge";
    }
    if(N==0){
        couleur=" vert";
    }
    cout<<"Le numero gagnant est le "<<N<<couleur<<endl;
    return N;
}

