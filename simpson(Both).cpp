#include<iostream>
#include<math.h>
#include<vector>

using namespace std;
vector<float > coeff;
vector<int>formCode;
float temp;

void setFun(int deg);
float fun(float val);
float Simpson13(float ll,float ul,float inter);
float Simpson38(float ll,float ul,float inter);

int main(){

 int deg,mthdchoi;
 float inter,ll,ul;
 char choice;
      do{
         cout<<"\nEnter the degree of the equation\n";
         cin>>deg;
         setFun(deg);

         cout<<"Enter the lower limit and upper limit of integ.\n";
         cin>>ll>>ul;

         cout<<"Enter the no of iteration to perform\n";
         cin>>inter;

         cout<<"Which method do you want to opt?\n1. Simpson 1/3rd rule\n2.Simpson 3/8th rule";
         cin>>mthdchoi;
         if(mthdchoi==1){
                cout<<"\nInteg. of given f(x) from "<<ll<<" to "<<ul<<" by Simpson 1/3rd rule is "<<Simpson13(ll,ul,inter)<<endl;
                cout<<"\n==========press Y to continue===========\n";
         }
         else if(mthdchoi==2){
                cout<<"\nInteg. of given f(x) from "<<ll<<" to "<<ul<<" by Simpson 3/8th rule is "<<Simpson38(ll,ul,inter)<<endl;
                cout<<"\n==========press Y to continue===========\n";
         }
         else {
            cout<<"unknown  method ....";
         }

         cin>>choice;

      }while(choice=='y'||choice=='Y');
 return 0;

}

 void setFun(int deg){
    coeff.clear();
    formCode.clear();
    char choice;
    int a;
    for(int i=0;i<=deg;i++)
      {
        cout<<"Enter the coeff of the x^"<<i<<endl;
        cin>>temp;
        coeff.push_back(temp);
      }
      do{
        cout<<"For converting f(x) to 1/f(x) form Press 1.\nFor converting it to (f(x))^2 form  Press 2.\nfor converting f(x) to (f(x))^3 Press 3\n";
        cout<<"\nFor converting f(x) to sqrt(f(x)) Press 4\nFor converting f(x) to cuberoot(f(x)) Press 5. ";
        cin>>a;
        formCode.push_back(a);
        cout<<"Press Y to change f(x) even more...\n";
        cin>>choice;
      }while(choice=='y'||choice=='Y');


 }
  float fun(float val){
    int len=coeff.size();
    float res=0.00;

    for (int i=0;i<len;i++){
         res+=(coeff[i]*pow(val,i));

    }
   // code below is needed for the function of some diff type like 1/f(x) f(x)^n

   for(int i=0;i<formCode.size();i++){

         if(formCode.at(i)==1&&res!=0.0000){
            res=1/res;
         }
         else if(formCode.at(i)==2){
            res*=res;
         }
         else if(formCode.at(i)==3){
           res=pow(res,3);
         }
         else if(formCode.at(i)==4){
            res=sqrt(res);
         }
         else if(formCode.at(i)==5){
            res=pow(res,(1/3));
         }
         else break;
    }
    cout<<"The result of f(x) is \t"<<res<<"\n\n\n";
    return  res;
  }

  float Simpson13(float ll,float ul,float inter ){

    float h=(ul-ll)/inter,res=0.000;

    for(int i=0;i<=inter;i++){
        if(i==0&&i==inter){
            res+=fun(ll+i*h);
        }
        else if (!(i%2)){
           res+=4.00*(fun(ll+i*h));
        }
        else {
           res+=2.00*(fun(ll+i*h));
        }
     }

    res*=h/3;
    return res;

  }
     float Simpson38(float ll,float ul,float inter ){

        float h=(ul-ll)/inter,res=0.000;

        for(int i=0;i<=inter;i++){
            if(i==0&&i==inter){
                res+=fun(ll+i*h);
            }
            else if (!(i%3)){
               res+=2.00*(fun(ll+i*h));
            }
            else {
               res+=3.00*(fun(ll+i*h));
            }
         }

        res*=3*h/8;
        return res;

  }


