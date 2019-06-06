#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void init_intro(char (*intro)[80], char **pint);
int input_intro(char (*intro)[80]);
void sort_intro(char **pint, int cnt);
void printf_intro(int mode, void *vp, int cnt);


int main(void)
{
	char intro[10][80]; //10x80
	char *pint[10];
	int cnt;
	
	 
	
	init_intro(intro, pint);
	cnt = input_intro(intro);
	sort_intro(pint, cnt);
	printf_intro(1, pint, cnt);//0�� ���� �Էµ� �λ縻, 1�� ���ĵ� �λ縻 
	printf_intro(0, intro, cnt);

	return 0;
}


//init�� intro ���� 
void init_intro(char (*intro)[80], char **pint) {
	int i=0;
	for(i=0;i<10;i++) {
		pint[i] = intro[i];
	}
}

int input_intro ( char (*intro)[80] ) {

	int l_cnt;
	char buffer[80];
	while( 1 ) {//end�� �ԷµǸ� ���� //�λ縻 ���� 
		/*
		printf("�λ縻 �Է� : ");
		
		  fgets( buffer, 79, stdin); //���� ���� �Է��ϸ� �˴ٿ� 
		//gets( intro[i]);	//���Լ� ���¹� , �Է¹޾� �� ����
		//strcpy( buffer, intro[i] );
		printf("�Է¹��� ���ڿ�: %s",buffer);
		strcpy(intro[l_cnt],buffer);
		
		printf("�Է¹��� ���ڿ�: %s",intro+l_cnt);
		if( 0 == strcmp("end\n",buffer  )) {
			break;
		}
		else {}
		l_cnt++;
		
		*/
		printf("> �λ縻 �Է� : ");
		gets(buffer);
		if(strcmp(buffer, "end") == 0) break;
		strcpy(intro[l_cnt], buffer);
		l_cnt++;
	}
	fflush(stdin);
	return l_cnt; 
}


//�λ縻 ������ ����
void sort_intro(char **pint, int cnt) {
	int i,j;
	for(i=0;i<9;i++ ) {
		for(j=0;j<9;j++) {
			if (strcmp(pint[i],pint[j]) < 0 )
            {
            	
            	char* tmp = pint[i];
            	pint[i] = pint[j];
            	pint[j] = tmp;
            }
		}
	}
	  
	puts("end of sort");
}



 //0�� ���� �Էµ� �λ縻, 1�� ���ĵ� �λ縻
void printf_intro(int mode, void *vp, int cnt) {
	int i; 
	char **intp;
	char (*intro)[80];
	
	if ( mode == 0 ) {
    	char (*intro)[80] = vp;

    	puts("������� ��� .... ");
        //printf("original list is :\n");
        for (i = 0; i < cnt; i++) {
        	printf("%s", intro[i]);	
		}
    }
	
	
	else if( mode == 1)  {//���ĵ� �λ縻 
		char **intp = vp;
		puts("���������� ��� ... \n");		//���ĵ� �λ縻 �� pint������ �迭�� �̿� 
		for( i=0; i<cnt;i++) {	//vp ��  pint �� �����µ�, �� ������ �����ϱ� 
			printf("%s\n", intp[i]);
		} 
	}
	
	
	else {//���� �Էµ� �λ縻 vp�� �̿��� intro2�����迭 ���ڿ����//2�����迭�� �Է¹޴� �迭������ 
		for(i=0;i<10;i++) {
			puts("un intended ERROR!!!!!!!");
		}
		
	}
}

//
/*
/

//

void printf_intro(int mode, void *vp, int cnt)
{
	int i;

	if(mode == 0)
	{
		char (*intro)[80] = vp;
		printf("\n@ �Է¼����� ���...\n");
		for(i = 0; i < cnt; i++)
		{
			printf("%s\n", intro[i]);
		}
			fflush(stdin);
	}
	else if(mode == 1)
	{
		char **intp = vp;
		printf("\n@ ���������� ���...\n");
		for(i = 0; i < cnt; i++)
		{
			printf("%s\n", intp[i]);
		}
	}
}

//
*/

