#include <stdio.h>


int max(int arr[],int length)
{
	int maxxx = 0;
	int iii;
	for(iii = 1; iii<length;iii++)
	{
		if(arr[iii]>arr[maxxx])
		{
			maxxx = iii;
		}
	}
	return maxxx;
}

int main()
{
	int N,M;
	int votes[26];
	int vote_quotient[26];
	int delegates[26] = {0};
	float recent_votes[26];
	int init_ascii = 65;
	int i,ii,m,vot,curr;
	float maxx;
	int total_delegates = 0;
	scanf("%d %d",&N,&M);
	for(i=0;i<N;i++)
	{
		scanf("%d",&vot);
		votes[i] = vot;
	}
	for(i=0;i<N;i++)
	{
		vote_quotient[i] = 1;
	}

	for(i = 0;i<N;i++)
	{
		recent_votes[i] = (float)votes[i]/vote_quotient[i];
	}
	
	while(total_delegates<M)
	{
		maxx = recent_votes[0];
		curr = 0;
		for(ii = 0; ii<N;ii++)
		{
			if(recent_votes[ii]>maxx)
			{
				maxx = recent_votes[ii];
				curr = ii;

			}
			else if(recent_votes[ii]==maxx && delegates[ii]>delegates[curr])
			{
				maxx = recent_votes[ii];
				curr = ii;
			}
		}
		delegates[curr] +=1;
		vote_quotient[curr] += 1;
		recent_votes[curr] = (float)votes[curr]/vote_quotient[curr];
		total_delegates++;
	}
	for(i = 0;i<N;i++)
	{
		
		m = max(delegates,N);
		if(delegates[m]>0){
		printf("%c: %d\n",65+m,delegates[m]);
		delegates[m] = 0;}

	}
}
