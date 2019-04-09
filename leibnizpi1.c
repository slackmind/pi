/******************************************************

A simple program to compute pi using Leibniz's formula
PI/4 = 1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + 1/13 - 1/(n+2)

This will use successively more iterations to show how accuracy impoves


******************************************************/

#include<stdio.h>

int main()
{
	long double PI = 3.14159265358979;  // from Google!
	long double pi;
	long double fraction;
	long double intermediate = 1;
	long double abs_dif;
	long double percent_dif;
	int iterations = 2;
	long double odd_number = 3;

	while ( iterations < 8193 )
	{
		for (int i = 0; i<iterations; i++)
		{
			fraction = 1/odd_number;

			( i%2 ) ? (intermediate += fraction) : (intermediate -= fraction);
			
			odd_number += 2;
		}

		// perhaps this is slightly more accurate than *4 ?
		pi = intermediate+intermediate+intermediate+intermediate; 
		abs_dif = pi - PI;
		percent_dif = PI/pi;

		printf("\n***********************************************************\n");
		printf("\nAfter %d iterations Pi has been approximated to: \n%Lf", iterations, pi);
		printf("\nThis answer is %Lf away and within %Lf percent.", abs_dif, percent_dif);
		printf("\n\n***********************************************************");

		iterations += iterations;
	}
	printf("\nPress any key to exit.");
	getchar();

	return 0;
}