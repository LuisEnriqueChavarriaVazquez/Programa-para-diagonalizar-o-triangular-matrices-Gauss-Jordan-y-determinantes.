/*INSTITUTO POLITECNICO NACIONAL
  ESCUELA SUPERIOR DE COMPUTO
  
  ALGEBRA LINEAL  
*/

#include<stdio.h>
#include<iostream>


void mainGaussJordan();
void PideDatos(int *Dim, float Sist[][102]);
void EscribeDatos(int Dim, float Sist[][102]);
void ResuelveGauss(int Dim, float Sist[][102]);


void upperTriangle();
void lowerTriangle();
void determinante();

using namespace std;


int main(void)
{
	system ("color F0");
	cout << "  \n  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
	cout << "  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
	cout << "  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
	cout << "  °°°°° Instituto Politecnico Nacional." << endl;
	cout << "  °°°°° Escuela Superior de Computo." << endl;
	cout << "  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
	cout << "  °°°°° Profesor: Roberto Vazquez Arreguin." << endl;
	cout << "  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
	cout << "  °°°°° Chavarria Vazquez Luis Enrique." << endl;
	cout << "  °°°°° Campero Beleche Brandon Antonio." << endl;
	cout << "  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
	cout << "  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
	cout << "  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
	
	int out = 1;
	
	while(out){

	int opcion;
		cout << "\n  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
		cout << "  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
		cout << "  °°°°°  //// Dime que es lo que quieres hacer ////\n" << endl;
		cout << "  °°°°°  ** Resolver una matriz por Gauss-Jordan. [1]" << endl;
		cout << "  °°°°°  ** Diagonalizar una matriz de forma inferior [2]" << endl;
		cout << "  °°°°°  ** Diagonalizar una matriz de forma superior [3]" << endl;
		cout << "  °°°°°  ** Determinante de una matriz [4]" << endl;
		cout << "  °°°°°  ** Salir del programa [5] \n" << endl;
		cout << "  °°°°°  ** Regresar al menu [Cualquier numero o letra]" << endl;
		cout << "  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
		cout << "  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
	
		cout << "\n  Escriba su opcion: ";
		cin >> opcion;
		cout << "\n" << endl;
	
		switch(opcion) {
			case 1: 
				system("CLS");
				mainGaussJordan();
			break;
			case 2: 
				system("CLS");
				lowerTriangle();
			break;
			case 3: 
				system("CLS");
				upperTriangle();
			break;
			case 5:
				out =0;
				break;
			case 4: 
				system("CLS");
				determinante();
			break;
		
		default:
			break;
		}
	}
}

void mainGaussJordan(){
	int C,Dimension;
    float Sistema[101][102];
    PideDatos(&Dimension,Sistema);
    printf("\n\n\n El sistema de MATRICES que introdujo es el siguiente. \n\n");
    EscribeDatos(Dimension,Sistema);
    ResuelveGauss(Dimension,Sistema);
    printf("\n\n°°°° Las soluciones son las siguientes:\n");
    for(C=1;C<=Dimension;C++) printf("\n X%d=%f\n",C,Sistema[C][Dimension+1]);
   
    scanf("");
}

void PideDatos(int *Dim,float Sist[][102])
{
    int A,B;
    printf("\n\n °°°Resolucion de cualquier sistema de matrices por GAUSS-JORDAN.°°°");
    printf("\n\n\n [Hasta 5000 incognitas] Dame el numero de incognitas: ");
    scanf("%d",&*Dim);
    printf("\n\n Introduzca los componentes del sistema [A|B]:");
    printf("\n\n Matriz 1:\n");
    for(A=1;A<=*Dim;A++) for(B=1;B<=*Dim;B++){
        printf("\n °°°° Elemento A(%d,%d):",A,B); scanf("%f",&Sist[A][B]);}
    printf("\n\n\n [Resultado] Vector 2:\n");
    for(A=1;A<=*Dim;A++){
        printf("\n °°°° Elemento B(%d):",A);scanf("%f",&Sist[A][*Dim+1]);
    }}

void EscribeDatos(int Dim, float Sist[][102])
{
    int A,B;
    for(A=1;A<=Dim;A++){
        for(B=1;B<=(Dim+1);B++){
            printf("%7.2f",Sist[A][B]);
            if(B==Dim) printf("   |");}
        printf("\n");
    }}

void ResuelveGauss(int Dim, float Sist[][102])
{
    int NoCero,Col,C1,C2,A;
    float Pivote,V1;
   
    for(Col=1;Col<=Dim;Col++){
        NoCero=0;A=Col;
        while(NoCero==0){
           if((Sist[A][Col]>0.0000001)||((Sist[A][Col]<-0.0000001))){
                NoCero=1;}
            else A++;}
        Pivote=Sist[A][Col];
        for(C1=1;C1<=(Dim+1);C1++){
            V1=Sist[A][C1];
            Sist[A][C1]=Sist[Col][C1];
            Sist[Col][C1]=V1/Pivote;}
        for(C2=Col+1;C2<=Dim;C2++){
            V1=Sist[C2][Col];
            for(C1=Col;C1<=(Dim+1);C1++){
                Sist[C2][C1]=Sist[C2][C1]-V1*Sist[Col][C1];}
    }}
   
    for(Col=Dim;Col>=1;Col--) for(C1=(Col-1);C1>=1;C1--){
        Sist[C1][Dim+1]=Sist[C1][Dim+1]-Sist[C1][Col]*Sist[Col][Dim+1];
        Sist[C1][Col]=0;
    }
} 

/*Triangulacion del contenido*/
 
void lowerTriangle()
{
 	 int arr1[10][10],i,j,n;
  float determinant=0;

  printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
       printf("\n\nDiagonalizacion inferior de la matriz :\n");
      printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");


     printf("Ingrese el tamano de la matriz : ");
     scanf("%d", &n); 
	 printf("Ingrese los elementos de la matriz:\n");
       for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
	           cout << "°°° Elemento: [" << i+1 << "],[" << j+1 << "].";
	           scanf("%d",&arr1[i][j]);
            }
        }  
	 printf("La matriz original es :\n");
	 for(i=0;i<n;i++)
	 {
	   for(j=0;j<n ;j++)
	     printf("% 4d",arr1[i][j]);
	    printf("\n");
	 }

   printf("\nDiagonalizando la matriz.\n");
   for(i=0;i<n;i++){
      printf("\n");
      for(j=0;j<n;j++)
           if(i<=j)
             printf("% 4d",arr1[i][j]);
           else
             printf("% 4d",0);
  }
       printf("\n\n");
}

 
void upperTriangle()
{
 	int arr1[10][10],i,j,n;
  float determinant=0;
  
  printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
printf("\n\nDiagonalizacion superior de la matriz :\n");
       printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");

     printf("Ingrese el tamano de la matriz : ");
     scanf("%d", &n); 
	 printf("Ingrese los elementos de la matriz:\n");
       for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
	           cout << "°°° Elemento: [" << i+1 << "],[" << j+1 << "].";
	           scanf("%d",&arr1[i][j]);
            }
        }  
	 printf("La matriz original es :\n");
	 for(i=0;i<n;i++)
	 {
	   for(j=0;j<n ;j++)
	     printf("% 4d",arr1[i][j]);
	    printf("\n");
	 }

   printf("\nDiagonalizando la matriz.\n");
   for(i=0;i<n;i++)
     {
      printf("\n");
      for(j=0;j<n;j++)
           if(i>=j)
             printf("% 4d",arr1[i][j]);
           else
             printf("% 4d",0);
  }
       printf("\n\n");
}

void determinante(){
	 float  matrix[10][10], ratio, det;
    int i, j, k, n;
    printf("Ingrese el tamano de la matriz: ");
    scanf("%d", &n);
    printf("Ingrese los elementos de la matriz: \n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
        	cout << "°°° Elemento: [" << i+1 << "],[" << j+1 << "].";
            scanf("%f", &matrix[i][j]);
        }
    }
    /* Conversion of matrix to upper triangular */
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(j>i){
                ratio = matrix[j][i]/matrix[i][i];
                for(k = 0; k < n; k++){
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }
    det = 1; //storage for determinant
    for(i = 0; i < n; i++)
        det *= matrix[i][i];
    printf("El determinante de la matriz es: %.2f\n\n", det);
 
}
