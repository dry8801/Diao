#include<stdio.h>
#include<stdlib.h>
#define N 		 			8
#define File_0 	 			"DateList.txt"
#define File_High 	 		"DateList_High.txt"
#define File_Normal 		"DateList_Normal.txt"
#define File_Low 	 		"DateList_Low.txt"
#define ApplyForMemory(x)	x = (struct Datastruct*)malloc(n * sizeof(struct Datastruct))
#define 
unsigned int n;
float	Precision;
struct Datastruct {
	int name, sign;
	float data_error[8];
};
/*
�ж������Ƿ��ھ��ȷ�Χ֮�� 
*/
void Precison_Judge(struct Datastruct *const tmp) {
	int i;
	float P1=-Precision,P2=Precision; 
	for (i = 0; i < 8; i++) {
		if (tmp->data_error[i] <= P1 || tmp->data_error[i] >= P2) {
			tmp->sign = 0;
			return;
		}
	}
	tmp->sign = 1;
}
/*
���ļ��л�ȡ����,����Precison_Judge 
*/
void gain_data(struct Datastruct *const DataStruct,const char Str[]) {
	FILE* fp;
	unsigned int i, j;
	fp = fopen(Str, "r"); 
	if (fp==NULL) {
		printf("%s�ļ���ʧ��\n",Str);
		return;
	}
	else ;
	for (i = 0; i < n; i++) {
		fscanf(fp, "%d", &(DataStruct[i].name));
		for (j = 0; j < N; j++) {
			fscanf(fp, "%f", DataStruct[i].data_error+j);
		}
		Precison_Judge(&DataStruct[i]);
	}
	while (fclose(fp)) {
		printf("�ļ��ر�ʧ��\n");
		system("pause");
	}
	system("cls");
}
/*
ѡ��ɸѡ������,��ӡ���ұ��� 
*/
void SelectPrecision_Data(struct Datastruct* const DataStruct) {
	unsigned int i;
	char s[]="name";
	FILE* fp;
	fp = fopen("QualifiedDataOut.txt", "w"); 
	if (fp==NULL) {
		printf("QualifiedDataOut.txt�ļ�����ʧ��\n");
		return;
	}
	else ;
	fprintf(fp, "%s\n",s);
	printf("%s\n",s);
	for (i = 0; i < n; i++) if (DataStruct[i].sign) {
		fprintf(fp, "%d\n", DataStruct[i].name);
		printf("%d\n", DataStruct[i].name);
	}
	system("pause");
	system("cls");
	while (fclose(fp)) {
		printf("�ļ��ر�ʧ��\n");
		system("pause");
	}
	printf("QualifiedDataOut.txt�ļ�����ɹ�\n");
	system("pause");
}
/*
ƥ��ߵ��¾��� 
*/
void Select_TowText(const char* File_str1,
						  const char* File_str2  ){
	//gain_data();
} 
int main(void) {
	int mode,SelectTxt;
	struct Datastruct* DataST,DataST_High,DataST_Normal,DataST_Low;
	printf("������LCJ-G2.5����:");
	scanf("%d", &n);
	printf("������ɸѡ���ȼ���(����������):");
	scanf("%f", &Precision);
	while(1){
		system("cls");
		printf("1-�޸�LCJ-G2.5����		2-�޸�ɸѡ����\n");
		printf("3-�ӵ���һ���ı���ɸ������	4-ѡ�������ı���ɸ������\n");
		printf("5-�Ӹ��¡����¡������г�����\n");
		printf("ע���Ӷ��ı���ɸ��������Ҫÿ���ı������㾫������\n");
		printf("��ǰ�����뾫�����£�\n");
		printf("LCJ-G2.5���� n = %d 		����Precision = %f\n",n,Precision);
		printf("��������ѡ��ģʽmode: "); 
		scanf("%d",&mode);
		system("cls");
		switch(mode){
			case 1:{
				printf("������LCJ-G2.5����:");
				scanf("%d", &n);
				break;
			}
			case 2:{
				printf("������ɸѡ���ȼ���(����������):");
				scanf("%f", &Precision);
				break;
			}
			case 3:{
				DataST = (struct Datastruct*)malloc(n * sizeof(struct Datastruct));
				gain_data(DataST, File_0);
				SelectPrecision_Data(DataST);
				free(DataST);
				break;
			}
			case 4:{
				printf("1-���ºͳ���  2-���º͵���  3-���º͵���\n");
				DataST_High   = (struct Datastruct*)malloc(n * sizeof(struct Datastruct));
				DataST_Normal = (struct Datastruct*)malloc(n * sizeof(struct Datastruct));
				DataST_Low 	  = (struct Datastruct*)malloc(n * sizeof(struct Datastruct));
				gain_data(DataST_High	, File_High);
				gain_data(DataST_Normal	, File_Normal);
				gain_data(DataST_Low	, File_Low);
				printf("��ѡ�����ģʽ��");
				scanf("%d",&SelectTxt);
				switch(SelectTxt){
					case 1:{
						Select_TowText(File_High, File_Normal);
						break;
					}
					case 2:{
						Select_TowText(File_High, File_Low   );
						break;
					}
					case 3{

						Select_TowText(File_Normal, File_Low );
						break;
					}
					default:break;
				}
				free
				break;
			}
		}
	}
	return 0;
}
