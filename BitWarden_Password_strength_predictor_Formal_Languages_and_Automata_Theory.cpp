#include<iostream>
#include<cstring>
#include<ctype.h>
using namespace std;

class tier1{
    protected:
        bool isNum1, isSymbol1, isLowAlpha1, isUpAlpha1;
        int i, len;
        string password;
    public:

        void initialise(string password, int len){
            this->password = password;
            this->len = len;
            i=0;
        }

        void checkTier1(){
            isNum1 = isSymbol1 = isLowAlpha1 = isUpAlpha1 = false;
            cout<<endl<<"   ";
            if(isdigit(password[i])){
                isNum1 = true;
                while(isdigit(password[i]) && i < len){ cout<<"q1 -> "; i++; }
            }else if(password[i] >= 'a' && password[i] <= 'z'){
                isLowAlpha1 = true;
                while(password[i] >= 'a' && password[i] <= 'z' && i < len){ cout<<"q3 -> "; i++; }
            }else if(password[i] >= 'A' && password[i] <= 'Z'){
                isUpAlpha1 = true;
                while(password[i] >= 'A' && password[i] <= 'Z' && i < len){ cout<<"q4 -> "; i++; }
            }else if(!isalnum(password[i])){
                isSymbol1 = true;
                while(!isalnum(password[i]) && i < len){ cout<<"q2 -> "; i++; }
            }
        }
};

class tier2: public tier1{
    protected:
        bool isNum2, isSymbol2, isLowAlpha2, isUpAlpha2;
    public:
        void checkTier2(){
            isNum2 = isSymbol2 = isLowAlpha2 = isUpAlpha2 = false;
            cout<<endl<<"   ";
            if(i < len){
                if(isNum1){
                    if(password[i] >= 'a' && password[i] <='z'){
                        isLowAlpha2 = true;
                        while(((password[i] >= 'a' && password[i] <='z') || isdigit(password[i])) && i < len){ cout<<"q6 -> "; i++; }
                    }else if(password[i] >= 'A' && password[i] <= 'Z'){
                        isUpAlpha2 = true;
                        while(((password[i] >= 'A' && password[i] <= 'Z') || isdigit(password[i])) && i < len){ cout<<"q7 -> "; i++; }
                    }else{
                        isSymbol2 = true;
                        while((isalnum(password[i]) == 0 || isdigit(password[i])) && i < len){ cout<<"q5 -> "; i++; }
                    }
                }

                if(isSymbol1){
                    if(isdigit(password[i])){
                        isNum2 = true;
                        while((isdigit(password[i]) || isalnum(password[i]) == 0) && i < len){ cout<<"q8 -> "; i++; }
                    }else if(password[i] >= 'a' && password[i] <='z'){
                        isLowAlpha2 = true;
                        while(((password[i] >= 'a' && password[i] <='z') || isalnum(password[i]) == 0) && i < len){ cout<<"q9 -> "; i++; }
                    }else if(password[i] >= 'A' && password[i] <= 'Z'){
                        isUpAlpha2 = true;
                        while(((password[i] >= 'A' && password[i] <= 'Z') || isalnum(password[i]) == 0) && i < len){ cout<<"q10 -> "; i++; }
                    }
                }

                if(isLowAlpha1){
                    if(isdigit(password[i])){
                        isNum2 = true;
                        while((isdigit(password[i]) || (password[i] >= 'a' && password[i] <='z')) && i < len){ cout<<"q11 -> "; i++; }
                    }else if(password[i] >= 'A' && password[i] <= 'Z'){
                        isUpAlpha2 = true;
                        while(((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <='z')) && i < len){ cout<<"q13 -> "; i++; }
                    }else if(!isalnum(password[i])){
                        isSymbol2 = true;
                        while((!isalnum(password[i]) || (password[i] >= 'a' && password[i] <='z')) && i < len){ cout<<"q12 -> "; i++; }
                    }
                }

                if(isUpAlpha1){
                    if(isdigit(password[i])){
                        isNum2 = true;
                        while((isdigit(password[i]) || (password[i] >= 'A' && password[i] <='Z')) && i < len){ cout<<"q14 -> "; i++; }
                    }else if(password[i] >= 'a' && password[i] <= 'z'){
                        isLowAlpha2 = true;
                        while(((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <='Z')) && i < len){ cout<<"q16 -> "; i++; }
                    }else{
                        isSymbol2 = true;
                        while(((isalnum(password[i]) == 0) || (password[i] >= 'A' && password[i] <='Z')) && i < len){ cout<<"q15 -> "; i++; }
                    }
                }
          }else{
              cout<<"\n   Password weak but could be made stronger\n   (final state q33 not reached)";
              exit(0);
          }
    }
};

class tier3: public tier2{
    protected:
        bool isNum3, isSymbol3, isLowAlpha3, isUpAlpha3;
        bool okUpto17, okUpto18, okUpto19, okUpto20, okUpto21, okUpto22, okUpto23, okUpto24, okUpto25, okUpto26, okUpto27, okUpto28;
    public:
        void checkTier3(){
            okUpto17 = okUpto18 = okUpto19 = okUpto20 = okUpto21 = okUpto22 = okUpto23 = okUpto24 = okUpto25 = okUpto26 = false;
            okUpto27 = okUpto28 = isNum3 = isSymbol3 = isLowAlpha3 = isUpAlpha3 = false;
            cout<<endl<<"   ";
            if(i < len){
                if((isNum1 && isSymbol2) || (isSymbol1 && isNum2) ){
                    if(password[i] >= 'a' && password[i] <= 'z'){
                        isLowAlpha3 = true;
                        okUpto17 = true;
                        while((password[i] >= 'a' && password[i] <= 'z') || (isdigit(password[i])) || (!isalnum(password[i])) && i<len){
                            cout<<"q17 -> "<<okUpto17; i++;
                        }
                    }else if(password[i] >= 'A' && password[i] <= 'Z'){
                        isUpAlpha3 = true;
                        okUpto18 = true;
                        while((password[i] >= 'A' && password[i] <= 'Z') || (isdigit(password[i])) || (!isalnum(password[i])) && i<len){
                            cout<<"q18 -> "; i++;
                        }
                    }
                }else if((isNum1 && isLowAlpha2) || (isLowAlpha1 && isNum2)){
                    //q19 and q20
                    if(!isalnum(password[i])){
                        isSymbol3 = true;
                        okUpto19 = true;
                        while((password[i] >= 'a' && password[i] <= 'z') || (isdigit(password[i])) || (!isalnum(password[i])) && i<len){
                            cout<<"q19 -> "; i++;
                        }
                    }else if(password[i] >= 'A' && password[i] <= 'Z'){
                        isUpAlpha3 = true;
                        okUpto20 = true;
                        while(((password[i] >= 'A' && password[i] <= 'Z') || (isdigit(password[i])) || (password[i] >= 'a' && password[i] <= 'z'))  && i<len){
                            cout<<"q20 -> "; i++;
                        }
                    }
                }else if((isNum1 && isUpAlpha2) || (isUpAlpha1 && isNum2)){
                    //q21 and q22
                    if(!isalnum(password[i])){
                        isSymbol3 = true;
                        okUpto21 = true;
                        while(((password[i] >= 'A' && password[i] <= 'Z') || (isdigit(password[i])) || (!isalnum(password[i])))  && i<len){
                            cout<<"q21 -> "; i++;
                        }
                    }else if(password[i] >= 'a' && password[i] <= 'z'){
                        isLowAlpha3 = true;
                        okUpto22 = true;
                        while(((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z') || (isdigit(password[i]))) && i<len){
                            cout<<"q22 -> "; i++;
                        }
                    }
                }else if((isSymbol1 && isLowAlpha2) || (isLowAlpha1 && isSymbol2)){
                    //q23 and q24
                    if(isdigit(password[i])){
                        isNum3 = true;
                        okUpto23 = true;
                        while(((password[i] >= 'a' && password[i] <= 'z') || (isdigit(password[i])) || (!isalnum(password[i]))) && i<len){
                            cout<<"q23 -> "; i++;
                        }
                    }else if(password[i] >= 'A' && password[i] <= 'Z'){
                        isUpAlpha3 = true;
                        okUpto24 = true;
                        while(((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z') || (!isalnum(password[i]))) && i<len){
                            cout<<"q24 -> "; i++;
                        }
                    }
                }else if((isSymbol1 && isUpAlpha2) || (isUpAlpha1 && isSymbol2)){
                    //q25 and q26
                    if(isdigit(password[i])){
                        isNum3 = true;
                        okUpto25 = true;
                        while(((password[i] >= 'A' && password[i] <= 'Z') || (isdigit(password[i])) || (!isalnum(password[i]))) && i<len){
                            cout<<"q25 -> "; i++;
                        }
                    }else if(password[i] >= 'a' && password[i] <= 'z'){
                        isUpAlpha3 = true;
                        okUpto26 = true;
                        while(((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z') || (!isalnum(password[i]))) && i<len){
                            cout<<"q26 -> "; i++;
                        };
                    }
                }else if((isLowAlpha1 && isUpAlpha2) || (isUpAlpha1 && isLowAlpha2)){
                    //q27 and q28
                    if(isdigit(password[i])){
                        isNum3 = true;
                        okUpto27 = true;
                        while(((password[i] >= 'A' && password[i] <= 'Z') || (isdigit(password[i])) || (password[i] >= 'a' && password[i] <= 'z')) && i<len){
                            cout<<"q27 -> "; i++;
                        }
                    }else if(!isalnum(password[i])){
                        isUpAlpha3 = true;
                        okUpto28 = true;
                        while(((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z') || (!isalnum(password[i]))) && i<len){
                            cout<<"q28 -> "; i++;
                        }
                    }
                }
            }else{
                cout<<"\n   Password ok-ish but could be made stronger\n   (final state q33 not reached)";
                exit(0);
            }
        }
};

class tier4: public tier3{
    protected:
        bool okUpto29, okUpto30, okUpto31, okUpto32;
    public:
        void checkTier4(){
            cout<<endl<<"   ";
            okUpto29 = okUpto30 = okUpto31 = okUpto32 = false;
            if(i < len){
                if(okUpto17 || okUpto19 || okUpto23){
                    if(password[i] >= 'A' && password[i] <= 'Z'){
                        okUpto29 = true;
                        while((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z') || (isdigit(password[i])) || (!isalnum(password[i])) && i <len){
                            cout<<"q29 -> ";
                            i++;
                        }
                    }
                }else if(okUpto18 || okUpto21 || okUpto25){
                    if(password[i] >= 'a' && password[i] <= 'z'){
                        okUpto30 = true;
                        while((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z') || (isdigit(password[i])) || (!isalnum(password[i])) && i<len){
                            cout<<"q30 -> ";
                            i++;
                        }
                    }
                }else if(okUpto20 || okUpto22 || okUpto27){
                    if(!isalnum(password[i])){
                        okUpto31 = true;
                        while(((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z') || (isdigit(password[i])) || (!isalnum(password[i]))) && i < len){
                            cout<<"q31 -> ";
                            i++;
                        }
                    }
                }else if(okUpto24 || okUpto26 || okUpto28){
                    if(isdigit(password[i])){
                        okUpto32 = true;
                        while((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z') || (isdigit(password[i])) || (!isalnum(password[i])) && i < len){
                            cout<<"q32 -> ";
                            i++;
                        }
                    }
                }
            }else{
                cout<<"\n   Password good but could be made stronger\n   (final state q33 not reached)";
                exit(0);
            }
        }

        void checkFinal(){
            if(okUpto29 || okUpto30 || okUpto31 || okUpto32){
                cout<<"q33 \n   (final state q33 reached)\n\n   "<<password<<" is a strong password!"<<endl;
            }else{
                cout<<"   (final state q33 not reached) password is not strong";
            }
        }
};

int main(){
    string password;
    bool blank;

    cout<<"***************************************\n";
    cout<<"\t\tBitWarden\n";
    cout<<"***************************************\n";
    cout<<"\n   Enter password: ";
    getline(cin, password);

    int len = password.length();

    for(int i=0; i<len; i++){
        if(password[i] == ' ') blank = true;;
    }

    if(len > 128){
        cout<<"\n   Password too long\n";
    }else if(blank){
        cout<<"\n   Password should not contain blanks\n";
    }else{

        cout<<"\n   State transitions:\n   q0 -> ";

        tier4 t4;
        t4.initialise(password, len);
        t4.checkTier1();
        t4.checkTier2();
        t4.checkTier3();
        t4.checkTier4();
        t4.checkFinal();
    }

    return 0;
}
