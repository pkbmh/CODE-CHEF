// including header files
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<bitset>
using namespace std ;
//defining major used items
#define s(f) scanf("%d",&f)
#define sl(f) scanf("%lld",&f)
#define ss(f) scanf("%s",f)
#define REP(i,n) for ( int i = 0 ; i < n ; i++ )
#define REPAB(i ,a,b) for ( int i =a ;i <= b ; i++)
#define SIZE 10000000
//fast input function
#define getcx getchar_unlocked
inline void inp( int &n )
{
        n=0;
        int ch=getcx();int sign=1;
        while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

        while(  ch >= '0' && ch <= '9' )
                n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
		n=n*sign;
}

bitset<SIZE> prime ;
int num[SIZE] ;
void precompute( ) 
{
	prime.set() ;
	int i ;
	for( i = 0 ; i < SIZE ;i+=2) prime[i]=false ;
	prime[1]=false;
	prime[2] = true ;
	for ( i = 3 ; i < SIZE ; i+=2)
	{
		if ( prime[i]) for ( int j = 2 ; j*i < SIZE ;++j) prime[i*j] = false ;
	}

	int count = -1 ; 
	REPAB(i,0,SIZE) if (prime[i]) num[i]=++count;
	//REP(j,50)	if (prime[j]) cout << j << " " << num[j] << endl ;
}

int N ;
int arr[400][400] ;
int crack[400][400] ;
void Debug(int N)
{
	
}
void dfs_even (int i , int j ) 
{
	int t = arr[i][j] ;
	if ( i < 1 || j < 1 || i > N || j > N  )	return ;

	if (!prime[t] && !crack[i][j])
	{
		crack[i][j] = true ;
		if (!( arr[i-1][j]&1) ) dfs_even(i-1,j) ;
		if (!( arr[i][j-1]&1) ) dfs_even(i,j-1) ;
		if (!( arr[i][j+1]&1) ) dfs_even(i,j+1) ;
		if (!( arr[i+1][j]&1) ) dfs_even(i+1,j) ; 
	}
}

void dfs_odd (int i , int j )
{
	int t = arr[i][j] ;
	if ( i < 1 || j < 1 || i > N || j > N  )	return ;
	if (!prime[t] && !crack[i][j])
	{
		crack[i][j] = true ;
		if ( arr[i-1][j]&1 ) dfs_odd(i-1,j);
		if ( arr[i][j-1]&1 ) dfs_odd(i,j-1);
		if ( arr[i][j+1]&1 ) dfs_odd(i,j+1);
		if ( arr[i+1][j]&1 ) dfs_odd(i+1,j);
	}
}

int main ( )
{
	precompute();
	int test ;
	inp(test );
	while ( test -- )
	{
		// input
		inp(N) ; 
		memset(crack , 0 , sizeof(crack)) ;
		REPAB(i,1,N) REPAB(j,1,N)	inp(arr[i][j]) ;		
		
		// solving
		long long int count = 0 ;
		REPAB(i,1,N) REPAB(j,1,N)
		{
			if (!crack[i][j])
			{
				int tmp = arr[i][j] ;
				if ( prime[tmp])
				{
					int z = num[tmp] ;
//					REP(k,tmp) if (prime[k]) ++z ;
					count += z ;	
				}
				else
				{
					// if odd
					if ( tmp&1 )
					{
						count += tmp/2 + 2 ;
						dfs_odd (i,j);
						
					}
					else
					{
						count += tmp/2 ;
						dfs_even (i,j);
					}
				}
			}
		}
//		cout <<  count  <<  endl ;
		printf("%lld\n",count) ;
	}
	return 0 ;
}