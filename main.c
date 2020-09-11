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
判断数据是否在精度范围之内 
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
从文件中获取数据,调用Precison_Judge 
*/
void gain_data(struct Datastruct *const DataStruct,const char Str[]) {
	FILE* fp;
	unsigned int i, j;
	fp = fopen(Str, "r"); 
	if (fp==NULL) {
		printf("%s文件打开失败\n",Str);
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
		printf("文件关闭失败\n");
		system("pause");
	}
	system("cls");
}
/*
选择筛选好数据,打印并且保存 
*/
void SelectPrecision_Data(struct Datastruct* const DataStruct) {
	unsigned int i;
	char s[]="name";
	FILE* fp;
	fp = fopen("QualifiedDataOut.txt", "w"); 
	if (fp==NULL) {
		printf("QualifiedDataOut.txt文件创建失败\n");
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
		printf("文件关闭失败\n");
		system("pause");
	}
	printf("QualifiedDataOut.txt文件保存成功\n");
	system("pause");
}
/*
匹配高低温精度 
*/
void Select_TowText(const char* File_str1,
						  const char* File_str2  ){
	//gain_data();
} 
int main(void) {
	int mode,SelectTxt;
	struct Datastruct* DataST,DataST_High,DataST_Normal,DataST_Low;
	printf("请输入LCJ-G2.5个数:");
	scanf("%d", &n);
	printf("请输入筛选精度级别(请输入正数):");
	scanf("%f", &Precision);
	while(1){
		system("cls");
		printf("1-修改LCJ-G2.5个数		2-修改筛选精度\n");
		printf("3-从单独一个文本中筛出数据	4-选择两个文本，筛出数据\n");
		printf("5-从高温、常温、低温中出数据\n");
		printf("注：从多文本中筛出数据需要每个文本都满足精度需求\n");
		printf("当前个数与精度如下：\n");
		printf("LCJ-G2.5个数 n = %d 		精度Precision = %f\n",n,Precision);
		printf("请根据序号选择模式mode: "); 
		scanf("%d",&mode);
		system("cls");
		switch(mode){
			case 1:{
				printf("请输入LCJ-G2.5个数:");
				scanf("%d", &n);
				break;
			}
			case 2:{
				printf("请输入筛选精度级别(请输入正数):");
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
				printf("1-高温和常温  2-高温和低温  3-常温和低温\n");
				DataST_High   = (struct Datastruct*)malloc(n * sizeof(struct Datastruct));
				DataST_Normal = (struct Datastruct*)malloc(n * sizeof(struct Datastruct));
				DataST_Low 	  = (struct Datastruct*)malloc(n * sizeof(struct Datastruct));
				gain_data(DataST_High	, File_High);
				gain_data(DataST_Normal	, File_Normal);
				gain_data(DataST_Low	, File_Low);
				printf("请选择配对模式：");
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
