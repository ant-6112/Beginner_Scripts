//Bollywood-Hollywood Flims Guessing Game where you are given blanks as the number of characters present in the Not-Knnown Movie,
//Then You Guess A Letter From The English Alphabet One At A Time With ONly A Fixed Number Of Wrong Charcters Allowed.
#include<bits\stdc++.h>
using namespace std;
int main(){
    vector<string> movies_h = {"The-amazing-spider-man","spiderman","godzilla","the-avengers","richie-rich","home-alone","toy-story-4","it","anabelle"};
    vector<string> movies_b = {"3-idiots","dangal","pk","phobia","padmavati","the-sky-is-pink","zero","bahubali-beggining","bahubali-the-conclusion","thappad"};
    printf("     Bollywood/Hollywood\n");
    printf("            Start\n");
    printf("Do you want a random movie or the one specified by Player_2:\n(Type R for Random Movie and U for User Specified Movie)");
    char he;
    cin>>he;
    printf("\n");
    string a;
    char d;
    if(he == 'U'){
        printf("Write a Movie Down for The Other Player To Guess , One Character at a time - Player_1:");
        cin>>a;
        printf("\n");
        printf("Is it a Bollywood Or Hollywood Movie ? \n(Type B for Bollywood and H for Hollywood.)");
        cin>>d;
    }else{
        printf("Do You want a Bollywood Or Hollywood Movie ? \n(Type B for Bollywood and H for Hollywood.)");
        cin>>d;
        printf("\n");
        if(d == 'H'){
            printf("Write a random number between 0 and %i :",movies_h.size());
            int ran;
            cin>>ran;
            a = movies_h[ran];
        }else{
            printf("Write a random number between 0 and %i :",movies_b.size());
            int ran;
            cin>>ran;
            a = movies_b[ran];
        }
    }
    printf("\n");
    char truth;
    printf("Do You Need Vowels ? \n(Write Y for Yes And N for No).");
    cin>>truth;
    printf("\n");
    printf("\n");
    int turns = 1,corr = 0,wrn = 0,number = 0,t = 0;
    vector<char> hell;
    char lis[5] = {'a' , 'e' , 'i' ,'o','u'};
    char boll[10] = "Bollywood";
    char holl[10] = "Hollywood";
    string ans[a.size()];
    for(int y= 0;y<a.size();y++){
        ans[y] = "__ ";
    }
    while(true){
        cout<<"Turn:"<<turns<<"\n";
        printf("     ");
        for(int k = 0;k<10;++k){
            if(d == 'B'){
               printf("%c ",boll[k]);
            }else{
               printf("%c ",holl[k]); 
            }
        }
        printf("\n\n");
        for(int q = 0;q<a.size();q++){
                cout<<ans[q];
        }
        cout<<"\n";
        if(turns == 1 && truth == 'Y'){
            for(int i = 0;i<a.size();++i){
                for(int p = 0;p<5;p++){
                    if(a[i] == lis[p]){
                        ans[i] = char(int(lis[p]) - 32);
                        number+=1;
                    }
                }
            }
            cout<<"\n";
            printf("Just Printing The Vowels:\n");
            for(int q = 0;q<a.size();q++){
                cout<<ans[q];
            }
            printf("\n");
        }
        char gu;
        printf("\n");
        printf("Guess a Character:");
        cin>>gu;
        /*printf("Write The Position:");
        int o;
        cin>>o;
        cout<<"\n";*/
        printf("\n\n");
        int mn = 0;
        int yu;
        end:
        yu = 0;
        for(int uy = 0;uy<hell.size();++uy){
            if(gu == hell[uy]){
                printf("Character Already Used\n");
                yu += 1;
            }
        }
        if(yu == 1){
            printf("Enter Another Character:");
            cin>>gu;
            goto end;
        }
        hell.push_back(gu);
        for(int x = 0;x < a.size();++x){
                for(int w = 0;w<5;++w){
                    if(gu == lis[w] && truth == 'Y'){
                        printf("You Can't Enter A Vowel!!\n");
                        turns = turns + 1;
                        break;
                    }
                }
                if(a[x] == gu){
                    printf("You Entered A Correct Letter!!\n");
                    corr = corr + 1;
                    mn += 1;
                    ans[x] = char(int(gu - 32));
                }
        }

        if(mn == 0){
            printf("You Entered A Wrong Letter!!\n");
            wrn += 1;
            if(d == 'B'){
                boll[t] = '/';
            }else{
                holl[t] = '/';
            }
            t = t + 1;
            turns = turns + 1;
        }else{
            turns = turns + 1;
        }
        if(wrn == 9){
            printf("You Lost!\n");
            printf("Corrected Answers:%i",corr);
            break;
        }  
        if(corr == a.size() - number){
            printf("You Won!\n");
            printf("Corrected Answers:%i\n",corr);
            break;
        }
    }
    for(int q = 0;q<a.size();q++){
                cout<<ans[q];
    }
}
