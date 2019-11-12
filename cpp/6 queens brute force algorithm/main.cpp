#include <iostream>

using namespace std;

void reinas();
bool choque(bool tablero[6][6]);

int main()
{
    system("clear");
    bool tablero[6][6];
    bool res = false;
    int cont=0;

    //Create Chessboard
    for(int i=0;i<6;i++){
      for(int j=0;j<6;j++){
            tablero[i][j] = false;
      }
    }

    // Queens movement
    for(int a = 0; a < 6; a++){
      for(int b = 0; b < 6; b++){
        for(int c = 0; c < 6; c++){
          for(int d = 0; d < 6; d++){
            for(int e = 0; e < 6; e++){
              for(int f = 0; f < 6; f++){
                  tablero[0][a]=true;
                  tablero[1][b]=true;
                  tablero[2][c]=true;
                  tablero[3][d]=true;
                  tablero[4][e]=true;
                  tablero[5][f]=true;
                  res = choque(tablero);
                  if(res == true){
                    for (int i = 0; i < 6; i++) {
                      for (int j = 0; j < 6; j++) {
                          if(tablero[i][j] == true){
                              cout << " 1 / ";
                          }else{cout << " 0 / ";}
                       }
                     cout << endl;
                    }
                    cout << endl;
                    cont++;
                    cout << cont;
                    cout << endl << endl;
                  }
                  tablero[0][a]=false;
                  tablero[1][b]=false;
                  tablero[2][c]=false;
                  tablero[3][d]=false;
                  tablero[4][e]=false;
                  tablero[5][f]=false;
               }
             }
           }
         }
       }
     }
    return 0;
}

bool choque(bool tablero[6][6]){
    bool atq = true;
      for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
          if(tablero[i][j] == true){
            //Atack in X direction
            for(int x=i+1;x<6;x++){
              if(tablero[x][j] == true){
                atq = false;
              }
            }
            for(int x=i-1;x>0;x--){
              if(tablero[x][j] == true){
                atq = false;
              }
            }
            //Atack in Y direction
            for(int y=j+1;y<6;y++){
              if(tablero[i][y] == true){
                atq = false;
              }
            }
            for(int y=j-1;y>0;y--){
              if(tablero[i][y] == true){
                atq = false;
              }
            }
            //Atack in DIAGONAL Right up/down
            int y=j;
            for(int x=i+1;x<6;x++){
              if(y+1 == 6){break;}else{y++;}
              if(tablero[x][y] == true){
                atq = false;
              }
            }
            y=j;
            for(int x=i+1;x<6;x++){
              if(y-1 == -1){break;}else{y--;}
              if(tablero[x][y] == true){
                atq = false;
              }
            }
            //Atack in DIAGONAL Left up/down
            y=j;
            for(int x=i-1;x>0;x--){
              if(y+1 == 6){break;}else{y++;}
              if(tablero[i][y] == true){
                atq = false;
              }
            }
            y=j;
            for(int x=i-1;x>0;x--){
              if(y-1 == -1){break;}else{y--;}
              if(tablero[i][y] == true){
                atq = false;
              }
            }
          }
        }
      }
    return atq;
}
