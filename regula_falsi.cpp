#include<iostream>
#include <math.h>
#include<vector>
using namespace std;

vector<float > coeff;
float temp;

 void setFun(int deg){
    coeff.clear();
    for(int i=0;i<=deg;i++)
      {
        cout<<"Enter the coeff of the x^"<<i<<endl;
        cin>>temp;
        coeff.push_back(temp);
      }

 }

 float fun(float val){
    int len=coeff.size();
    float res=0.00;

    for (int i=0;i<len;i++){
        res+=(coeff[i]*pow(val,i));

    }

    return  res;
  }

   void regula_falsi(float a,float b,int iter){

        float c,fa=0.000,fb=0.000,fc=0.000;

        while(iter){

            fa=fun(a);
            fb=fun(b);

            if(fa*fb>0){

                cout<<"\ninvalid initials points\n";
                break;
            }
            else if(fa*fb<0){

                c=(a*fb-b*fa)/(fb-fa);

                fc=fun(c);

                if(fa*fc){
                    b=c;
                    cout<<"\nApprox root after "<<iter<<"iterations is "<<c<<endl;
                }
                else if(fb*fc){
                    a=c;
                    cout<<"\nApprox root after "<<iter<<"iterations is "<<c<<endl;
                }
                else {
                     cout<<"Root of the equation is "<<c;
                     break;
                }

            }
            else {
                cout<<"Root of the equation is "<<c;
                break;
            }

            iter--;
        }

   }


   int main(){

    int deg,iter;
    float a,b;
    cout<<"Enter the degree of the equation \n";
    cin>>deg;


    setFun(deg);

    cout<<"Enter the initial points\n";
    cin>>a>>b;
    cout<<"Enter the no of iteration to perform\n";
    cin>>iter;
    regula_falsi(a,b,iter);

    return 0;

   }












