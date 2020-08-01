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

 int n, r, i;

 printf("\t POLYNOMDIVISION");
 printf("\n Enter the highest degree of the equation: ");
 
 scanf("%d",&n);  // Einabe 

 // Arraygrößen anpassen auf Polynomgrad
 poly = realloc(poly, sizeof(int[n])); 
 q    = realloc(q, sizeof(int[n]));    

 for(i=0;i<=n;i++)
	{
 	 printf("\n Input the coefficient x[%d] = ", n-i);
 	 scanf("%d",&poly[i]);
	}

 printf("\n Enter the value of constant in (x-r) : ");
 scanf("%d",&r);

 q[0] = poly[0];
 for(i=1;i<=n;i++)
	{
	 q[i] = (q[i-1]*r)+poly[i];
	}

 printf("\n The quotient coefficients are: \n");

 for(i=0;i<n;i++)
	{
	 printf("\t%d",q[i]);
	}

 printf("\n The remainder is: %d", q[n]);
 printf("\n");
 
 free (poly); // free the memory ...
 free (q);

}


