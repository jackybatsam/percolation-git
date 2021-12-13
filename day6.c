#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define days 249
#define limit 2147000000L
//unsigned long list[] = {3,4,3,1,2};
unsigned long list[] = {3,4,3,1,2,1,5,1,1,1,1,4,1,2,1,1,2,1,1,1,3,4,4,4,1,3,2,1,3,4,1,1,3,4,2,5,5,3,3,3,5,1,4,1,2,3,1,1,1,4,1,4,1,5,3,3,1,4,1,5,1,2,2,1,1,5,5,2,5,1,1,1,1,3,1,4,1,1,1,4,1,1,1,5,2,3,5,3,4,1,1,1,1,1,2,2,1,1,1,1,1,1,5,5,1,3,3,1,2,1,3,1,5,1,1,4,1,1,2,4,1,5,1,1,3,3,3,4,2,4,1,1,5,1,1,1,1,4,4,1,1,1,3,1,1,2,1,3,1,1,1,1,5,3,3,2,2,1,4,3,3,2,1,3,3,1,2,5,1,3,5,2,2,1,1,1,1,5,1,2,1,1,3,5,4,2,3,1,1,1,4,1,3,2,1,5,4,5,1,4,5,1,3,3,5,1,2,1,1,3,3,1,5,3,1,1,1,3,2,5,5,1,1,4,2,1,2,1,1,5,5,1,4,1,1,3,1,5,2,5,3,1,5,2,2,1,1,5,1,5,1,2,1,3,1,1,1,2,3,2,1,4,1,1,1,1,5,4,1,4,5,1,4,3,4,1,1,1,1,2,5,4,1,1,3,1,2,1,1,2,1,1,1,2,1,1,1,1,1,4};
//unsigned long long int seed[264] = {1,1,1,1,1,1,1,1,1};
long double seed[264] = {1,1,1,1,1,1,1,1,1};

int main(){
	int n;
	for(n=9;n<264;n++){
		int preIndex = n - 9;
		//unsigned long result = 1 + seed[preIndex];
		long double result = 1 + seed[preIndex];
		while(preIndex >= 7){
			preIndex -= 7;
			result += seed[preIndex];
		}
		seed[n] = result;
		printf("%d: %Lf\n",n , result);
	}
	//unsigned long long int ans = 0;
	long double ans = 0;
	//printf("!%lu, %lu, %lu, %lu!\n", sizeof(unsigned long), sizeof(unsigned long long int), sizeof(double), sizeof(long double));
	int number[6] = {0};
	for(n=0;n<sizeof(list)/sizeof(long);n++){
		number[list[n]]++;
	}
	for(n=0;n<6;n++){
		printf("%d: %d\n",n ,number[n]);
	}

	for(n=0;n<sizeof(list)/sizeof(long);n++){
		ans += seed[614 - list[n]];
	}
	printf("ans = %LF", ans);

	return 1;
}
/*
{
	long i, j, k;
	long new_fish = 0, change_index; 
	long number = sizeof(list)/sizeof(int);
	long other_number=0;
	int *list_tmp, *list_tmp2;

	list_tmp = malloc(sizeof(int)*limit);
	list_tmp2 = malloc(sizeof(int)*limit);

	list_tmp[0] = list[0];


	//printf("seed[256] = %d\n", seed[17]);
	return 1;

	for(k=0;k<days;k++){
		new_fish = 0;
		for(i=0;i<number;i++){
			if(i<limit){
				list_tmp[i]--;
				if(list_tmp[i] == -1){
					list_tmp[i] = 6;
					new_fish++;
				}
			}else if(i<(2*limit)){
				change_index = i-limit;
				
				list_tmp2[change_index]--;
				if(list_tmp2[change_index] == -1){
					list_tmp2[change_index] = 6;
					new_fish++;
				}
			}
		}
		if(new_fish != 0)
		{
			for(j=number; j<number+new_fish;j++){
				if(j<limit)
				{
					list_tmp[j] = 8;
				}else if(j<(2*limit)){
					change_index = j-limit;
					list_tmp2[change_index] = 8;
				}
			}
			number += new_fish;
		}
	}
	printf("number = %lu\n", number);

	for(i=0;i<number;i++){
		if(i<limit){
			if(list_tmp[i]<=5){
				other_number++;
			}
		}else if(i<(2*limit)){
			change_index = i-limit;
			if(list_tmp2[change_index]<=5){
				other_number++;
			}
		}
	}	

	free(list_tmp);
	free(list_tmp2);

	number += other_number;
	printf("x_number = %lu\n",other_number);
	printf("z_number = %lu\n",number);

	return 0;
}*/
