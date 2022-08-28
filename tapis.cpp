#include "tapis.h"

using namespace std;

void AfficheTapis (int x, int y){
    int w0,h0;
    byte* rgb0;
    loadColorImage(srcPath("images/Tapisfinal.png"),rgb0,w0,h0);
    NativeBitmap tapis(w0,h0);
    tapis.setColorImage(0,0,rgb0,w0,h0);
    putNativeBitmap(x,y,tapis);
    delete[] rgb0;
}

void initialisemise(int mise[49]){ // on initialise les mises à 0
    for (int i=0;i<49;i++){
        mise[i]=0;
    }
}

void actualiseargent(int mise[49], int &S, int result){
    int gain=0;
    bool couleur=false;
    gain=mise[result]*36; // gain sur case unique

    if (result>0 && result<13){ // gains sur douzaines
        gain = gain + 3*mise[37];
    }
    if (result>12 && result<25){
        gain = gain + 3*mise[38];
    }
    if (result>24){
        gain = gain + 3*mise[39];
    }

    if (result > 0 && result<19){ // gains sur moitiés (1-18) et (19-36)
        gain = gain + 2*mise[40];
    }
    if (result>18){
        gain = gain + 2*mise[41];
    }

    if (result%2==0 && result>0){
        gain = gain + 2*mise[42];
    }

    if (result%2==1){
        gain = gain + 2*mise[43];
    }

    for (int i=0;i<18;i++){ // on regarde si le résultat est rouge
        if (rouge[i]==result){
            couleur=true;
        }
    }

    if (couleur){   // gain couleur (rouge ou noir)
        gain = gain + 2*mise[44];
    }
    if (result>0 && !couleur){
        gain = gain + 2*mise[45];
    }

    S=S+gain; // on actualise la masse de money du gambler

    int misetotale=0;
    for (int i=0; i<49; i++){
        misetotale+=mise[i];
    }
    int benefice=gain-misetotale;
    if(benefice>=0){
        cout<<"Vous avez gagne "<<benefice<<" euros"<<endl;
    }
    else{
        cout<<"Vous avez perdu "<<(-1)*benefice<<" euros"<<endl;
    }

}

void miseelementaire(int jeton, int&S, int mise[49], int x, int y){

    if (x>15 && x<280 && y<411 && y>15){ // si le joueur clique sur le tapis, c'est qu'il a misé, il perd donc un jeton
        S=S-jeton;

    }

    int w,h;
    byte* rgb;
    loadColorImage(srcPath("images/tasdejetons.png"),rgb,w,h);
    NativeBitmap jetons(w,h);
    jetons.setColorImage(0,0,rgb,w,h);


    if (x>49 && x<280){
        if (y<37){
            mise[0]=mise[0]+jeton; //0
            cout<<"Vous avez mise "<<jeton<<" euros sur 0"<<endl;
            putNativeBitmap(175,15,jetons);
        }
    }
    if (x>15 && x<50){ // le joueur a cliqué quelquepart sur la première colonne
        if (y>37 && y<=95){
            mise[40]=mise[40]+jeton; // 1-18
            cout<<"Vous avez mise "<<jeton<<" euros sur 1-18"<<endl;
            putNativeBitmap(23,59,jetons);
        }
        if (y>95 && y<153){
            mise[42]=mise[42]+jeton; // pair (even)
            cout<<"Vous avez mise "<<jeton<<" euros sur pair"<<endl;
            putNativeBitmap(23,115,jetons);
        }
        if (y>152 && y<210){
            mise[44]=mise[44]+jeton; // rouge
            cout<<"Vous avez mise "<<jeton<<" euros sur rouge"<<endl;
            putNativeBitmap(23,172,jetons);
        }
        if (y>209 && y<267){
            mise[45]=mise[45]+jeton; // noir
            cout<<"Vous avez mise "<<jeton<<" euros sur noir"<<endl;
            putNativeBitmap(23,229,jetons);
        }
        if (y>266 && y<325){
            mise[43]=mise[43]+jeton; // impair
            cout<<"Vous avez mise "<<jeton<<" euros sur impair"<<endl;
            putNativeBitmap(23,287,jetons);
        }
        if (y>324 && y<383){
            mise[41]=mise[41]+jeton; // 19-36
            cout<<"Vous avez mise "<<jeton<<" euros sur 19-36"<<endl;
            putNativeBitmap(23,345,jetons);
        }
    }
    if (x>49 && x<85){
        if (y>37 && y<=152){
            mise[37]=mise[37]+jeton; // 1st 12
            cout<<"Vous avez mise "<<jeton<<" euros sur 1st 12"<<endl;
            putNativeBitmap(60,90,jetons);
        }
        if (y>152 && y<=267){
            mise[38]=mise[38]+jeton; // 2nd 12
            cout<<"Vous avez mise "<<jeton<<" euros sur 2nd 12"<<endl;
            putNativeBitmap(60,202,jetons);
        }
        if (y>267 && y<=383){
            mise[39]=mise[39]+jeton; // 3rd 12
            cout<<"Vous avez mise "<<jeton<<" euros sur 3rd 12"<<endl;
            putNativeBitmap(60,315,jetons);
        }
    }
    if (x>87 && x<152){
        if (y>37 && y<65){
            mise[1]=mise[1]+jeton; // 1
            cout<<"Vous avez mise "<<jeton<<" euros sur 1"<<endl;
            putNativeBitmap(112,43,jetons);
        }
        if (y>64 && y<95){
            mise[4]=mise[4]+jeton; // 4
            cout<<"Vous avez mise "<<jeton<<" euros sur 4"<<endl;
            putNativeBitmap(112,72,jetons);
        }
        if (y>94 && y<123){
            mise[7]=mise[7]+jeton; // 7
            cout<<"Vous avez mise "<<jeton<<" euros sur 7"<<endl;
            putNativeBitmap(112,101,jetons);
        }
        if (y>122 && y<151){
            mise[10]=mise[10]+jeton; //10
            cout<<"Vous avez mise "<<jeton<<" euros sur 10"<<endl;
            putNativeBitmap(112,130,jetons);
        }
        if (y>150 && y<181){
            mise[13]=mise[13]+jeton; //13
            cout<<"Vous avez mise "<<jeton<<" euros sur 13"<<endl;
            putNativeBitmap(112,158,jetons);
        }
        if (y>180 && y<209){
            mise[16]=mise[16]+jeton; //16
            cout<<"Vous avez mise "<<jeton<<" euros sur 16"<<endl;
            putNativeBitmap(112,187,jetons);
        }
        if (y>208 && y<238){
            mise[19]=mise[19]+jeton; //19
            cout<<"Vous avez mise "<<jeton<<" euros sur 19"<<endl;
            putNativeBitmap(112,216,jetons);
        }
        if (y>237 && y<267){
            mise[22]=mise[22]+jeton; //22
            cout<<"Vous avez mise "<<jeton<<" euros sur 22"<<endl;
            putNativeBitmap(112,245,jetons);
        }
        if (y>266 && y<296){
            mise[25]=mise[25]+jeton; //25
            cout<<"Vous avez mise "<<jeton<<" euros sur 25"<<endl;
            putNativeBitmap(112,274,jetons);
        }
        if (y>295 && y<325){
            mise[28]=mise[28]+jeton; //28
            cout<<"Vous avez mise "<<jeton<<" euros sur 28"<<endl;
            putNativeBitmap(112,302,jetons);
        }
        if (y>324 && y<354){
            mise[31]=mise[31]+jeton; //31
            cout<<"Vous avez mise "<<jeton<<" euros sur 31"<<endl;
            putNativeBitmap(112,331,jetons);
        }
        if (y>353 && y<383){
            mise[34]=mise[34]+jeton; //34
            cout<<"Vous avez mise "<<jeton<<" euros sur 34"<<endl;
            putNativeBitmap(112,360,jetons);
        }
        if (y>382 && y<411){
            mise[46]=mise[46]+jeton; // "2 to 1" 1ère colonne
            cout<<"Vous avez mise "<<jeton<<" euros sur 1ere colonne"<<endl;
            putNativeBitmap(112,388,jetons);
        }
    }
    if (x>151 && x<216){
        if (y>37 && y<65){
            mise[2]=mise[2]+jeton; // 2
            cout<<"Vous avez mise "<<jeton<<" euros sur 2"<<endl;
            putNativeBitmap(177,43,jetons);
        }
        if (y>64 && y<95){
            mise[5]=mise[5]+jeton; // 5
            cout<<"Vous avez mise "<<jeton<<" euros sur 5"<<endl;
            putNativeBitmap(177,72,jetons);
        }
        if (y>94 && y<123){
            mise[8]=mise[8]+jeton; // 8
            cout<<"Vous avez mise "<<jeton<<" euros sur 8"<<endl;
            putNativeBitmap(177,101,jetons);
        }
        if (y>122 && y<151){
            mise[11]=mise[11]+jeton; //11
            cout<<"Vous avez mise "<<jeton<<" euros sur 11"<<endl;
            putNativeBitmap(177,130,jetons);
        }
        if (y>150 && y<181){
            mise[14]=mise[14]+jeton; //14
            cout<<"Vous avez mise "<<jeton<<" euros sur 14"<<endl;
            putNativeBitmap(177,158,jetons);
        }
        if (y>180 && y<209){
            mise[17]=mise[17]+jeton; //17
            cout<<"Vous avez mise "<<jeton<<" euros sur 17"<<endl;
            putNativeBitmap(177,187,jetons);
        }
        if (y>208 && y<238){
            mise[20]=mise[20]+jeton; //20
            cout<<"Vous avez mise "<<jeton<<" euros sur 20"<<endl;
            putNativeBitmap(177,216,jetons);
        }
        if (y>237 && y<267){
            mise[23]=mise[23]+jeton; //23
            cout<<"Vous avez mise "<<jeton<<" euros sur 23"<<endl;
            putNativeBitmap(177,245,jetons);
        }
        if (y>266 && y<296){
            mise[26]=mise[26]+jeton; //26
            cout<<"Vous avez mise "<<jeton<<" euros sur 26"<<endl;
            putNativeBitmap(177,272,jetons);
        }
        if (y>295 && y<325){
            mise[29]=mise[29]+jeton; //29
            cout<<"Vous avez mise "<<jeton<<" euros sur 29"<<endl;
            putNativeBitmap(177,302,jetons);
        }
        if (y>324 && y<354){
            mise[32]=mise[32]+jeton; //32
            cout<<"Vous avez mise "<<jeton<<" euros sur 32"<<endl;
            putNativeBitmap(177,331,jetons);
        }
        if (y>353 && y<383){
            mise[35]=mise[35]+jeton; //35
            cout<<"Vous avez mise "<<jeton<<" euros sur 35"<<endl;
            putNativeBitmap(177,360,jetons);
        }
        if (y>382 && y<411){
            mise[47]=mise[47]+jeton; // "2 to 1" 2ème colonne
            cout<<"Vous avez mise "<<jeton<<" euros sur 2eme colonne"<<endl;
            putNativeBitmap(177,388,jetons);
        }
    }
    if (x>215 && x<280){
        if (y>37 && y<65){
            mise[3]=mise[3]+jeton; // 3
            cout<<"Vous avez mise "<<jeton<<" euros sur 3"<<endl;
            putNativeBitmap(240,43,jetons);
        }
        if (y>64 && y<95){
            mise[6]=mise[6]+jeton; // 6
            cout<<"Vous avez mise "<<jeton<<" euros sur 6"<<endl;
            putNativeBitmap(240,72,jetons);
        }
        if (y>94 && y<123){
            mise[9]=mise[9]+jeton; // 9
            cout<<"Vous avez mise "<<jeton<<" euros sur 9"<<endl;
            putNativeBitmap(240,101,jetons);
        }
        if (y>122 && y<151){
            mise[12]=mise[12]+jeton; //12
            cout<<"Vous avez mise "<<jeton<<" euros sur 12"<<endl;
            putNativeBitmap(240,130,jetons);
        }
        if (y>150 && y<181){
            mise[15]=mise[15]+jeton; //15
            cout<<"Vous avez mise "<<jeton<<" euros sur 15"<<endl;
            putNativeBitmap(240,158,jetons);
        }
        if (y>180 && y<209){
            mise[18]=mise[18]+jeton; //18
            cout<<"Vous avez mise "<<jeton<<" euros sur 18"<<endl;
            putNativeBitmap(240,187,jetons);
        }
        if (y>208 && y<238){
            mise[21]=mise[21]+jeton; //21
            cout<<"Vous avez mise "<<jeton<<" euros sur 21"<<endl;
            putNativeBitmap(240,216,jetons);
        }
        if (y>237 && y<267){
            mise[24]=mise[24]+jeton; //24
            cout<<"Vous avez mise "<<jeton<<" euros sur 24"<<endl;
            putNativeBitmap(240,245,jetons);
        }
        if (y>266 && y<296){
            mise[27]=mise[27]+jeton; //27
            cout<<"Vous avez mise "<<jeton<<" euros sur 27"<<endl;
            putNativeBitmap(240,274,jetons);
        }
        if (y>295 && y<325){
            mise[30]=mise[30]+jeton; //30
            cout<<"Vous avez mise "<<jeton<<" euros sur 30"<<endl;
            putNativeBitmap(240,302,jetons);
        }
        if (y>324 && y<354){
            mise[33]=mise[33]+jeton; //33
            cout<<"Vous avez mise "<<jeton<<" euros sur 33"<<endl;
            putNativeBitmap(240,331,jetons);
        }
        if (y>353 && y<383){
            mise[36]=mise[36]+jeton; //36
            cout<<"Vous avez mise "<<jeton<<" euros sur 36"<<endl;
            putNativeBitmap(240,360,jetons);
        }
        if (y>382 && y<411){
            mise[48]=mise[48]+jeton; // "2 to 1" 3ème colonne
            cout<<"Vous avez mise "<<jeton<<" euros sur 3eme colonne"<<endl;
            putNativeBitmap(240,388,jetons);
        }
    }
    delete[] rgb;
}

void misecomplete(int&S, int mise[49]){
    cout<<"Vous disposez de "<<S<<" euros"<< endl;
    int x,y,a;
    int jeton;
    bool cliquejeton;
    a=getMouse(x,y);
    while(a==1){
        selectionjeton(jeton,x,y,cliquejeton);
        cout<<"Vous avez selectionne un jeton de valeur "<<jeton<< " euros"<<endl;
        if(S-jeton<0){
            cout<<"Vous n'avez plus les moyens !"<<endl;
        }
        else{
            if (!cliquejeton){ // si le joueur n'a pas sélectionné un jeton, c'est sûrement qu'il a joué
                miseelementaire(jeton,S,mise,x,y);}
            if (cliquejeton){
                a=getMouse(x,y); // si il a sélectionné un jeton, on attend un nouveau click pour qu'il le mise
                miseelementaire(jeton,S,mise,x,y);
            }
        }
        a=getMouse(x,y);
    }
}


void selectionjeton(int &jeton, int x,int y, bool &cliquejeton){
    if (y>417 && y<464){
        if (x>49 && x<96){
            jeton=1;
            cliquejeton=true;
        }
        if (x>99 && x<146){
            jeton=5;
            cliquejeton=true;
        }
        if (x>152 && x<198){
            jeton=25;
            cliquejeton=true;
        }
        if (x>204 && x<251){
            jeton=100;
            cliquejeton=true;
        }

    }
    else{
        jeton=1;
        cliquejeton=false;
    }
}
