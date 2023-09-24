#include<stdio.h>
int main(){
	int a,b,i,j;
	int sum=0;
	int c[300];
	scanf("%d %d",&a,&b);
	j=a;
	for(i=0;j<=b;i++){
		sum+=j;
		c[i]=j;
		j++;
	}
	for(i=0;i<(b-a+1);i++){
		printf("%5d",c[i]);
		if((i+1)%5==0){
			printf("\n");
		}
	}
    if((b-a+1)%5!=0){
	printf("\n");
    }
	printf("Sum = %d",sum);
	return 0;
}