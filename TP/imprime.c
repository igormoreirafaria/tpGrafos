#include <stdio.h>
int main(){
	int cont=0;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			printf("%d 	" , cont);
			cont++;
		}
		printf("\n\n");
	}
	return 0;
}