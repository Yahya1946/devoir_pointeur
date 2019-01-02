#include <stdio.h>

int NBDiv(int long N ) ;
int NBPAIR(int long N , int * P) ;

int main(int argc, char const *argv[])
{
	int long N;
	int  P1[N/2];
	printf("donner un entier\n");
	scanf("%ld",&N);
	int  P2[NBPAIR(N , P1)];
	printf("le nombre de diviseur est : %d \n",NBDiv(N) );
	printf("le nombre de pairs est : %d \n",NBPAIR(N , P1) );
	
	for (int  i = 0; i < 2*NBPAIR(N , P1) ; ++i)
	{
		P2[i] = P1[i] ;
	}
	for (int  i = 0; i < 2*NBPAIR(N , P1) ; i=i+2)
	{
		printf(" la pair numéro %d est %d, %d: \n", i/2 + 1 ,P2[i] ,P2[i+1]);
	}
	
	
	return 0;
}

int NBDiv(int long N )
{
	int nbDiv = 0 ;
	for (int i = 2 ; i < (N/2 + 1); ++i)
	{
		if (N % i == 0)
		{
			nbDiv++ ;
		}
	}
	return nbDiv ;
}

int NBPAIR(int long N , int  * P)
{
	int nbPair = 0 ; 
	int j = 0, q ;
	for (int i = 2 ; i < (N/2 + 1); ++i)
	{
		if (N % i == 0)
		{
			q = N / i ;	
			if (i <= q && NBDiv(i) == NBDiv(q))
			{
				P[j] = i ;
				P[j+1]= q ;
				j = j + 2 ;
			}
			
		}
	}
	return j/2 ;
}
