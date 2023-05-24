// Matrix mutable
#include<bits/stdc++.h>

using namespace std;

void matrix_mul(int a[10][10],int b[10][10],int c[10][10],int r1,int c1,int c2){
   #pragma omp parallel for 
    for(int i=0; i<r1; i++){
        for(int j =0;j<c2 ;j++){
            c[i][j] =0;
            for(int k=0;k<c1; k++){
                c[i][j]+= a[i][k]*b[k][j];
            }
        }
    }
    
    cout<<"MUL ele of c matx"<<endl;
    for(int i=0 ;i<r1; i++){
        for(int j =0; j<c2; j++){
            cout<<c[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    
}
int main(){
    int a[10][10],b[10][10], c[10][10], r1,c1,r2,c2;
    
    cout<<"Enter row and colunm for a matx";
    cin>>r1>>c1;
    cout<<"Enter row and colunm for b matx";
    cin>>r2>>c2;
    
    cout<<"Enter ele of A matx"<<endl;
    for(int i=0 ;i<r1; i++){
        for(int j =0; j<c1; j++){
            cin>>a[i][j];
        }
    }
    cout<<"Enter ele of B matx"<<endl;
    for(int i=0 ;i<r2; i++){
        for(int j =0; j<c2; j++){
            cin>>b[i][j];
        }
    }


    if(c1==r2){
        matrix_mul(a,b,c,r1,c1,c2);
    }
    else {
        cout<<"mul not possible"<<endl;
    }
}