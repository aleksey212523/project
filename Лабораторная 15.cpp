#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
struct lek
	{
		char name[50];
		int k;
		double cena;
		int srkeep;
	};
void input(lek *a,int &n);
void random(lek *a,int &n);
void finput(lek *a,int &k);
double desh(lek *a,int n);
double dor(lek *a,int n);
int colvo_lek(lek *a,int n);
void bolee_three(lek *a,int n);
void fbolee_three(lek *a,int n);
double sum_cena(lek *a,int n);
void output(double desh,double dor,int colvo,double sum);
void foutput(double desh,double dor,int colvo,double sum);
int main()
{
	setlocale(0,"");
	srand(time(NULL));
	int n,k,l;
	lek arr[100];
do{
		do{
		printf("¬ведите 1-с клавиатуры,2-рандом,3-из файла,0-выход.\n");
		scanf("%d",&n);
		}while(n!=1 && n!=2 && n!=3 && n!=0);
	if(n!=0)	
	{
		if(n==1)
			{
				do{
					printf("¬ведите кол-во элементов:\n");
					scanf("%d",&k);
				}while(k<=0);
				input(arr,k);
			}
		else 
		if(n==2)
			{
				do{
					printf("¬ведите кол-во элементов:\n");
					scanf("%d",&k);
				}while(k<=0);
				random(arr,k);
			}
		else
		if(n==3)
			{
				finput(arr,k);
			}
		do{
		printf("¬ведите 1-вывести на экран,2-вывести в файл.\n");
		scanf("%d",&l);
		}while(l!=1 && l!=2);
		if(l==1)
			{
				output(desh(arr,k),dor(arr,k),colvo_lek(arr,k),sum_cena(arr,k));
				bolee_three(arr,k);
			}
		else
		if(l==2)
			{
				foutput(desh(arr,k),dor(arr,k),colvo_lek(arr,k),sum_cena(arr,k));
				fbolee_three(arr,k);
			}
	}
}while(n!=0);	
return 1;
}


void input(lek *a,int &n)
{
	for(int i=0;i<n;i++)	
		{
			printf("¬ведите название лекарства %d\n",i+1);
			scanf("%s",&a[i].name);
			do{
			printf("¬ведите количество лекарств %d\n",i+1);
			scanf("%d",&a[i].k);
			}while(a[i].k<0);
			do{
			printf("¬ведите цену лекарства %d\n",i+1);
			scanf("%lf",&a[i].cena);
			}while(a[i].cena<=0);
			do{
			printf("¬ведите срок годности лекарства %d (в мес€цах)\n",i+1);
			scanf("%d",&a[i].srkeep);
			}while(a[i].srkeep<=0);
		}
}
void random(lek *arr,int &n)
{
	int a,b,c,d,e,f;
	do{
	printf("¬ведите диапазон рандомного количества:\n");
	scanf("%d",&a);
	scanf("%d",&b);
	}while(a<0 || b<0);
	do{
	printf("¬ведите диапазон рандомной цены:\n");
	scanf("%d",&c);
	scanf("%d",&d);
	}while(c<=0 || d<=0);
	do{
	printf("¬ведите диапазон рандомного срока годности:\n");
	scanf("%d",&e);
	scanf("%d",&f);
	}while(e<=0 || f<=0);
	for(int i=0;i<n;i++)
		{
			printf("¬ведите название лекарства %d:\n",i+1);
			scanf("%s",&arr[i].name);
			arr[i].k=rand()%(b-a+1)+a;
			arr[i].cena=(rand()%(100*d-100*c+1)+100*a)/100.0;
			arr[i].srkeep=rand()%(f-e+1)+e;
		}
	for(int j=0;j<n;j++)
		printf("%s %d %.2lf %d\n",arr[j].name,arr[j].k,arr[j].cena,arr[j].srkeep);
}
void finput(lek *a,int &k)
{
	k=0;
	FILE *massiv=fopen("struct.txt","r");
	while(!feof(massiv))
		{
			fscanf(massiv,"%s %d %lf %d",&a[k].name,&a[k].k,&a[k].cena,&a[k].srkeep);
			k++;
		}
	fclose(massiv);
}
double desh(lek *a,int n)
{
	int k;
	double min=a[0].cena;
	for(int i=0;i<n;i++)
		{
		if (a[i].cena<min)
			{
				min=a[i].cena;	
			}
		}
	return min;
}
double dor(lek *a,int n)
{
	int k;
	double max=a[0].cena;
	for(int i=0;i<n;i++)
		{
		if (a[i].cena>max)
			{
				max=a[i].cena;	
			}
		}
	return max;
}
int colvo_lek(lek *a,int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=a[i].k;
	return sum;
}
void bolee_three(lek *a,int n)
{
	int k=0;
	printf("Ћекарства, которые имеют срок хранени€ более 3 мес.:\n");
	for(int i=0;i<n;i++)
		{
			if(a[i].srkeep>3)
			{
				printf("%s\n",a[i].name);
				k++;
			}
		}
	if(k==0) printf("-\n");
}
void fbolee_three(lek *a,int n)
{
	FILE *massiv=fopen("Rez.txt","a");
	int k=0;
	fprintf(massiv,"Ћекарства, которые имеют срок хранени€ более 3 мес.:\n");
		for(int i=0;i<n;i++)
			{
				if(a[i].srkeep>3)
				{
					fprintf(massiv,"%s\n",a[i].name);
					k++;	
				}
			}
	if (k==0) printf("-\n");
	fclose(massiv);
}
double sum_cena(lek *a,int n)
{
	double sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i].cena;
	}
	return sum;
}
void output(double desh,double dor,int colvo,double sum)
{
	printf("—амое дешЄвое лекарство стоит: %.2lf\n",desh);
	printf("—амое дорогое лекарство стоит: %.2lf\n",dor);
	printf("ќбщее кол-во: %d\n",colvo);
	printf("—уммарна€ стоимость: %.2lf\n",sum);	
}
void foutput(double desh,double dor,int colvo,double sum)
{
	FILE *massiv=fopen("Rez.txt","w");
	fprintf(massiv,"—амое дешЄвое лекарство стоит: %.2lf\n",desh);
	fprintf(massiv,"—амое дорогое лекарство стоит: %.2lf\n",dor);
	fprintf(massiv,"ќбщее кол-во: %d\n",colvo);
	fprintf(massiv,"—уммарна€ стоимость: %.2lf\n",sum);
	fclose(massiv);
}
