#include<iostream>
using namespace std;
int main(){
    cout<<"      Tic-Tac-Toe\n";
    cout<<"        Start\n";
    int grid[3][3],turns = 1,curr = 0,stra = 0,dia1 = 0,dia2 = 0;
    int o = 0,x = 1;
    int n,m;
    for(int z = 0;z<3;++z){
        cout<<"\n";
        for(int s = 0;s<3;++s){
            grid[z][s] = 2;
            cout<<grid[z][s]<<" ";
        }
    }
    printf("\n");
    while(turns <= 9){
       for(int i = 1;i<=2;++i){
           for(int y = 0;y<3;++y){
               printf("\n");
               for(int u = 0;u<3;++u){
                   printf("%i ",grid[y][u]);
               }
           }
           printf("\n");
           printf("\n");
           if(i == 1){
               printf("#Player 1 Turn\n");
               printf("cell_number_of_the_placed:");
               cin>>n>>m;
               while(grid[n][m] == 1 || grid[n][m] == 0 ){
                   printf("Not Applicable!\n");
                   printf("cell_number_of_the_placed:");
                   cin>>n>>m;
               }
               grid[n][m] = x;
               ++turns;
           }else{
               printf("#Player 2 Turn\n");
               printf("cell_number_of_the_placed:");
               cin>>n>>m;
               while(grid[n][m] == 1 || grid[n][m] == 0 ){
                   printf("Not Applicable!\n");
                   printf("cell_number_of_the_placed:");
                   cin>>n>>m;
               }
               grid[n][m] = o;
               ++turns;
           }
           for(int h = 0;h<3;++h){
               curr = 0;
               dia1 = 0;
               dia2 = 0;
               for(int q = 0;q<3;++q){
                   if(grid[h][q] == grid[n][m]){
                       curr += 1;
                       if(curr == 3){
                           if(grid[n][m] == x){
                               printf("Player 1 Won! ");
                               return 0;
                               break;
                           }else{
                               printf("Player 2 Won! ");
                               return 0;
                               break;
                           }
                       }
                   }
                   stra = 0;
                   for(int p = 0;p < 3;++p){
                       if(grid[p][q] == grid[n][m]){
                            stra += 1;
                            if(stra == 3){
                                if(grid[n][m] == x){
                                    printf("Player 1 Won! ");
                                    return 0;
                                    break;
                                }else{
                                    printf("Player 2 Won! ");
                                    return 0;
                                    break;
                                } 
                            }
                       }
                   }
                   for(int w = 0;w<3;w++){
                       if(w == q){
                          if(grid[w][q] == grid[n][m]){
                              dia1+= 1;
                              if(dia1 == 3){
                                 if(grid[n][m] == x){
                                    printf("Player 1 Won!");
                                    return 0;
                                    break;
                                 }else{
                                    printf("Player 2 Won!");
                                    return 0;
                                    break;
                                 }
                              }
                          }
                       }
                   }
                   for(int l = 2;l>-1;l--){
                       if(l == q){
                          if(grid[l][q] == grid[n][m]){
                              dia2 += 1;
                              if(dia2 == 3){
                                 if(grid[n][m] == x){
                                    printf("Player 1 Won!");
                                    return 0;
                                    break;
                                 }else{
                                    printf("Player 2 Won!");
                                    return 0;
                                    break;
                                 }
                              }
                          }
                       }
                   }
               }
           }
           for(int y = 0;y<3;++y){
               printf("\n");
               for(int u = 0;u<3;++u){
                   printf("%i ",grid[y][u]);
               }
           }
           printf("\nTurn: %i ends!\n",turns - 1);
        }
    }
}