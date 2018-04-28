#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

  vector<float> coeff;
  float temp;
  vector<float> setFun(int deg){
    coeff.clear();
    for(int i=0;i<=deg;i++)
      {
        cout<<"Enter the coeff of the x^"<<i<<endl;
        cin>>temp;
        coeff.push_back(temp);
      }

     return coeff;
   }
   float fun(float val);
   void bisection(float a,float b,int iter);

int main(){

    float a=0.00,b=0.00;
    int deg,iter;

    cout<<"Enter the degree of the function\n ";
    cin>>deg;

    vector<float> poin=setFun(deg);
    cout<<"ENTER THE INITIAL POINTS :: \n ";
    cin>>a>>b;

    cout<<"Enter the no of iteration to perform\n";
    cin>>iter;

    bisection(a,b,iter);

    return 0;

}

 float fun(float val) {
     float sum=0.00;
     int length=coeff.size();
     for (int i=0;i<=length;i++){
        sum+=(coeff[i]*pow(val,i));
     }
     return sum;

   }
 void bisection(float a,float b,int iter){
  float c,fa=0.00,fb=0.00,fc=0.00;
    while(iter){
        float c=(a+b)/2;
        float fa=fun(a);
        float fb=fun(b);
        float fc=fun(c);

          if((fa*fb)>=0){
              cout<<"\ninvalid initial points\n";
           }
          else{
              cout<<"Approx value of root after "<<iter<<"iterations is "<<c<<"\n\n";
                 if(fc==0.0000){
                    cout<<"the root is "<<c<<endl;
                    break;
                  }
                 else if((fa*fc)<0){
                     b=c;
                  }
                 else {
                    a=c;
                  }
          }
         iter--;
      }

   }


