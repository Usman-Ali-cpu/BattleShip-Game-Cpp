// Inverse Matrix Modulo-2
#include <iostream>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <string>
#include <fstream>		//remove ".h" to enable string declaration
//#include <sstream>
#include <time.h>
//#include <new>
#include <sys/types.h>
#include <sys/timeb.h>
using namespace std;

//----------------------------------------------------------------------------
short *svector(int nl,int nh)
{
	short *v;

 v=(short *)calloc(((unsigned)(nh-nl+1)),sizeof(short));
	return v-nl;
}
//----------------------------------------------------------------------------
void free_svector(short *v,int nl,int nh)
{
	free((short*) (v+nl));
}

//----------------------------------------------------------------------------
short **smatrix(int nrl,int nrh,int ncl,int nch)
{
	int i;
	short **m;

	m=(short **) calloc((unsigned int) (nrh-nrl+1),sizeof(short*));
	m -= nrl;

	i=nrl;while(i<=nrh){
		m[i]=(short *) calloc((unsigned int) (nch-ncl+1),sizeof(short));
		m[i] -= ncl;
	i++;}
	return m;
}
//----------------------------------------------------------------------------
void free_smatrix(short **m,int nrl,int nrh,int ncl,int nch)
{
	int i;

	i=nrh;while(i>=nrl){free((short*) (m[i]+ncl));i--;}
	free((short*) (m+nrl));
}

// Inverse Matrix Modulo-2
void InverseMatrixModulo2(int rs,int cs,short **mi,short **r)
{
	short *s,*t,**m;
	int i,j,k,n,w,check,dummy;

	if (rs!=cs){cout<<"The matrix to invert is not square\n";cin>>dummy;}
	if (r==mi){cout<<"The result matrix is the same as the operand\n";cin>>dummy;}

	m=smatrix(0,rs,0,cs);
	s=svector(0,rs);
	t=svector(0,rs);

	check=1;n=rs;w=cs;
	i=0;while(i<rs){j=0;while(j<cs){if(mi[i][j]==(-1)){mi[i][j]=1;}j++;}i++;}

	i=0;while(i<rs){j=0;while(j<cs){m[i][j]=mi[i][j];r[i][j]=0;j++;}i++;}
	for (i=0;i<n;i++){r[i][i]=1;}

	i=0;while((i<n)&&(check!=0)){ 
		dummy=0;j=i-1;while((j<n-1)&&(dummy==0)){j++;if(m[i][j]==1){dummy=1;}}
		if (j==n){check=0;}

		if(check!=0){
		if(j!=i){
			k=0;while(k<n){t[k]=m[k][i];k++;}
			k=0;while(k<n){m[k][i]=m[k][j];k++;}
			k=0;while(k<n){m[k][j]=t[k];k++;}

			k=0;while(k<n){t[k]=r[k][i];k++;}
			k=0;while(k<n){r[k][i]=r[k][j];k++;}
			k=0;while(k<n){r[k][j]=t[k];k++;}
		}

		j=0;while(j<n){
			if((j!=i) && (m[i][j]==1)){
				k=0;while(k<n){s[k]=m[k][j];k++;}
				k=0;while(k<n){t[k]=m[k][i];k++;}
				for(k=0;k<n;k++){s[k] ^= t[k];}
				for(k=0;k<n;k++){m[k][j]=s[k];}

				k=0;while(k<n){s[k]=r[k][j];k++;}
				k=0;while(k<n){t[k]=r[k][i];k++;}
				for(k=0;k<n;k++){s[k] ^= t[k];}
				for(k=0;k<n;k++){r[k][j]=s[k];}
			}
		j++;}}
	i++;}

	free_svector(t,0,rs);
	free_svector(s,0,rs);
	free_smatrix(m,0,rs,0,cs);

	i=0;while(i<rs){j=0;while(j<cs){if(r[i][j]==(-1)){r[i][j]=1;}j++;}i++;}
	if(check!=1){cout<<"Incorrect Inverse Matrix\n";cin>>dummy;}
}

void InverseMatrixModulo2Test()
{
	int i,j,nr,cs;
	short **mi,**r;

	nr=5;cs=5;
	mi=smatrix(0,nr,0,cs);
	r=smatrix(0,nr,0,cs);

	mi[0][0]=0; mi[0][1]=0; mi[0][2]= 0; mi[0][3]=0; mi[0][4]=0;
	mi[1][0]=0; mi[1][1]=0; mi[1][2]= 0; mi[1][3]=0; mi[1][4]=0;
	mi[2][0]=0; mi[2][1]=0; mi[2][2]= 0; mi[2][3]=0; mi[2][4]=0;	
	mi[3][0]=0; mi[3][1]=0; mi[3][2]= 0; mi[3][3]=0; mi[3][4]=0;
	mi[4][0]=0; mi[4][1]=0; mi[4][2]= 0; mi[4][3]=0; mi[4][4]=0;	

	InverseMatrixModulo2(nr,cs,mi,r);
	
	i=0;while(i<nr){
		j=0;while(j<cs){		
			cout<<r[i][j]<<" ";
		j++;}cout<<"\n";
	i++;}
	
	free_smatrix(r,0,nr,0,cs);
	free_smatrix(mi,0,nr,0,cs);
}

int main()
{
	InverseMatrixModulo2Test();
	return 0;
}
