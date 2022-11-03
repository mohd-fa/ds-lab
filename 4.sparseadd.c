//342 Mohammed FA           Implement sparse matrix addition

#include<stdio.h>

struct elem{ 
	int value;
	int row;
	int col;
};
	
int main(){
	int i,j,k,a[10][10],b[10][10];
	struct elem matrixa[10], matrixb[10], sum[10], transposea[10], transposeb[10];
	
	printf("\nEnter the order of matrix a :");
	scanf("%d",&matrixa[0].row);
	scanf("%d",&matrixa[0].col);
	
	printf("\nEnter the elements of matrix a :");
	matrixa[0].value = 0;
	for (i=0; i<matrixa[0].row; i++)
		for (j=0; j<matrixa[0].col; j++){
			scanf("%d",&a[i][j]);
			if (a[i][j] != 0) {
				matrixa[matrixa[0].value+1].row = i;
				matrixa[matrixa[0].value+1].col = j;
				matrixa[matrixa[0].value+1].value = a[i][j];
				matrixa[0].value++;
			}
		}
	
	printf("\nMatrix A: \n");
	for (i=0; i<matrixa[0].row; i++){
		for (j=0; j<matrixa[0].col; j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	
	printf("\nTuple form Matrix A: \n");
	printf("row\tcol\tvalue\n");
	for (i=0; i<=matrixa[0].value; i++)
		printf("%d\t%d\t%d\n",matrixa[i].row,matrixa[i].col,matrixa[i].value);
	
	// tranpose
	transposea[0].row = matrixa[0].col;
	transposea[0].col = matrixa[0].row;
	transposea[0].value = matrixa[0].value;
	k=1;
	for(i=0;i<=matrixa[0].col;i++)
		for(j=1;j<=matrixa[0].value;j++)
			if (matrixa[j].col == i){
				transposea[k].row = matrixa[j].col;
				transposea[k].col = matrixa[j].row;
				transposea[k].value = matrixa[j].value;
				k++;
			}
			
			
	printf("\nTuple form transpose of Matrix A: \n");
	printf("row\tcol\tvalue\n");
	for (i=0; i<=matrixa[0].value; i++){
		printf("%d\t%d\t%d\n",transposea[i].row,transposea[i].col,transposea[i].value);
	}
	
	
	printf("\nEnter the order of matrix b :");
	scanf("%d",&matrixb[0].row);
	scanf("%d",&matrixb[0].col);
		
	printf("\nEnter the elements of matrix b :");
	matrixb[0].value = 0;
	for (i=0; i<matrixb[0].row; i++)
		for (j=0; j<matrixb[0].col; j++){
			scanf("%d",&b[i][j]);
			if (b[i][j] != 0) {
				matrixb[matrixb[0].value+1].row = i;
				matrixb[matrixb[0].value+1].col = j;
				matrixb[matrixb[0].value+1].value = b[i][j];
				matrixb[0].value++;
			}
		}
	
	printf("\nMatrix B: \n");
	for (i=0; i<matrixb[0].row; i++){
		for (j=0; j<matrixb[0].col; j++){
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	
	printf("\nTuple form Matrix B: \n");
	printf("row\tcol\tvalue\n");
	for (i=0; i<=matrixb[0].value; i++){
		printf("%d\t%d\t%d\n",matrixb[i].row,matrixb[i].col,matrixb[i].value);
	}
	
	// tranpose
	transposeb[0].row = matrixb[0].col;
	transposeb[0].col = matrixb[0].row;
	transposeb[0].value = matrixb[0].value;
	k=1;
	for(i=0;i<=matrixb[0].col;i++)
		for(j=1;j<=matrixb[0].value;j++)
			if (matrixb[j].col == i){
				transposeb[k].row = matrixb[j].col;
				transposeb[k].col = matrixb[j].row;
				transposeb[k].value = matrixb[j].value;
				k++;
			}
			
			
	printf("\nTuple form transpose of Matrix B: \n");
	printf("row\tcol\tvalue\n");
	for (i=0; i<=transposeb[0].value; i++){
		printf("%d\t%d\t%d\n",transposeb[i].row,transposeb[i].col,transposeb[i].value);
	}
	
	
	if(matrixa[0].row != matrixb[0].row || matrixa[0].col != matrixb[0].col){
		printf("\n\nAddition not possible.");
		return 0;
	}
	
	//addition
	sum[0].row = matrixa[0].row;
	sum[0].col = matrixa[0].col;
	i=1;
	j=1;
	k=1;
	while(i<=matrixa[0].value && j<=matrixb[0].value){
		if (matrixa[i].row == matrixb[j].row && matrixa[i].col == matrixb[j].col){
			sum[k].row = matrixa[i].row;
			sum[k].col = matrixa[i].col;
			sum[k].value = matrixa[i].value + matrixb[j].value;
			k++,i++,j++;
		}
		else if (matrixa[i].row < matrixb[j].row ){
			sum[k].row = matrixa[i].row;
			sum[k].col = matrixa[i].col;
			sum[k].value = matrixa[i].value;
			k++,i++;
		}
		else if(matrixa[i].row > matrixb[j].row ){
			sum[k].row = matrixb[j].row;
			sum[k].col = matrixb[j].col;
			sum[k].value = matrixb[j].value;
			k++,j++;
		}
		else {
			if (matrixa[i].col < matrixb[j].col ){
				sum[k].row = matrixa[i].row;
				sum[k].col = matrixa[i].col;
				sum[k].value = matrixa[i].value;
				k++,i++;
			}
			else {
				sum[k].row = matrixb[j].row;
				sum[k].col = matrixb[j].col;
				sum[k].value = matrixb[j].value;
				k++,j++;
			}
		}
	}
	while(i<=matrixa[0].value){
		sum[k].row = matrixa[i].row;
		sum[k].col = matrixa[i].col;
		sum[k].value = matrixa[i].value;
		k++,i++;
	}
	while(j<=matrixb[0].value){
		sum[k].row = matrixb[j].row;
		sum[k].col = matrixb[j].col;
		sum[k].value = matrixb[j].value;
		k++,j++;
	}
	sum[0].value = k-1;
	
	printf("\nTuple form Sum: \n");
	printf("row\tcol\tvalue\n");
	for (i=0; i<=sum[0].value; i++){
		printf("%d\t%d\t%d\n",sum[i].row,sum[i].col,sum[i].value);
	}

	return 0;
}
