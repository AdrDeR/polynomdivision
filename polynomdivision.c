//////////////////////////////////////////////////////////////////////////
// Polynom Division in C
//
// Author:  Adriano De Rosa
// Created: December 23rd, 2002
// Updated: August 1st, 2020: conio.h removed for usage on linux systems. Dynamic array added
//          
//
//////////////////////////////////////////////////////////////////////////

#include<stdio.h>   // Required for printf, scanf
#include<stdlib.h>  // Required for malloc, free, realloc

//#include<ncurses.h>

void main()
{
                
 int* poly= malloc(sizeof(int[10]));  // Dynamisches array für polynom koeffizienten
 int* q   = malloc(sizeof(int[10]));  // 

 //int poly[6], q[6];  // so würde es statisch aussehen .... nicht so flexibel

 int m, r, i;

 printf("\t POLYNOMDIVISION");
 printf("\n Enter the highest degree of the equation: ");
 
 scanf("%d",&m);  // Eigabe 

 // Arraygrößen anpassen auf Polynomgrad
 poly = realloc(poly, sizeof(int[m])); 
 q    = realloc(q, sizeof(int[m]));    

 for(i=0;i<=m;i++)
	{
 	 printf("\n Coefficient x[%d] = ", m-i);
 	 scanf("%d",&poly[i]);
	}

 printf("\n Enter the value of constant in (x-r) : ");
 scanf("%d",&r);

 q[0] = poly[0];
 for(i=1;i<=m;i++)
	{
	 q[i] = (q[i-1]*r)+poly[i];
	}

 printf("\n Coefficients of quotient are: \n");

 for(i=0;i<m;i++)
	{
	 printf("\t%d",q[i]);
	}

 printf("\n Remainder is: %d", q[m]);
 printf("\n");
 
 free (poly);
 free (q);

}


