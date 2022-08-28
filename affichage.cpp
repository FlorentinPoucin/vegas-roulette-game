#include "affichage.h"

void animationdebut (){

    //On affiche le fond d'accueil
    int w,h;
    byte* rgb;
    loadColorImage(srcPath("images/Accueil.png"),rgb,w,h);
    NativeBitmap lasvegas(w,h);
    lasvegas.setColorImage(0,0,rgb,w,h);
    putNativeBitmap(0,0,lasvegas);

    //On affiche le bouton play now
    int w2,h2;
    byte* rgb2;
    loadColorImage(srcPath("images/playnow.png"),rgb2,w2,h2);
    NativeBitmap playnow(w2,h2);
    playnow.setColorImage(0,0,rgb2,w2,h2);
    putNativeBitmap(520,320,playnow);

    //On fait clignoter le bouton 5 fois
    for(int k=0; k<5; k++){
        putNativeBitmap(0,0,lasvegas);
        milliSleep(500);
        putNativeBitmap(480,410,playnow);
        milliSleep(500);
    }
    click();
}

void animationfin(){
    int w,h;
    byte* rgb;
    loadColorImage(srcPath("images/Bankrupt.png"),rgb,w,h); //(608,342)
    NativeBitmap bankrupt(w,h);
    bankrupt.setColorImage(0,0,rgb,w,h);
    putNativeBitmap(0,0,bankrupt);
}
