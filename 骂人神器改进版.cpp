#include<stdio.h>
#include <Windows.h>
int main()
{
	int i;		
	char c;
	HGLOBAL hMen;   
    TCHAR strText[256] ;
	FILE *p;
	printf("��ܰ�����⣩��ʾ���뽫Ҫ���˵Ļ��ŵ�F���£��������.txt���档�ûس����Ÿ�����\n\n\n");
	printf("����������ó���������һ��������������4�����л�������Ҫִ�г����ҳ�档������˳���������0���ڴ����룺");
	scanf("%d",&i);
	while(i != 0)		
	{
		p = fopen("F:\\�������.txt","r+");
		if(NULL == p)
		{
			printf("���ļ�ʧ�ܣ�\n");
			return 0;
		}
		Sleep(4000);
		while((c = fgetc(p))!=EOF)	//��û�е��ļ��Ľ�β����ѭ��
		{
			fseek(p,-1,SEEK_CUR);	//���ļ�ָ����ǰ��һλ
			fgets(strText,300,p);			//��ȡһ�з���strText�����У�strText�������Ǳ����ı��е�һ������
			if (!OpenClipboard(NULL)|| !EmptyClipboard())    
			{   
				printf("�򿪻���ռ��а����\n");   
				return 0;   
			}   
			
			// ����ȫ���ڴ�    
			hMen = GlobalAlloc(GMEM_MOVEABLE, ((strlen(strText)+1)*sizeof(TCHAR)));    

			if (!hMen)   
			{   
				printf("����ȫ���ڴ����\n");    
				// �رռ��а�    
				CloseClipboard(); 
				return 0;         
			}   

			// �����ݿ�����ȫ���ڴ���   
			// ��ס�ڴ���    
			LPSTR lpStr = (LPSTR)GlobalLock(hMen);    

			// �ڴ渴��   
			memcpy(lpStr, strText, ((strlen(strText))*sizeof(TCHAR)));    
			// �ַ�������    
			lpStr[strlen(strText)] = (TCHAR)0;   
			// �ͷ���    
			GlobalUnlock(hMen);   

			// ���ڴ��е����ݷŵ����а���   
			SetClipboardData(CF_TEXT, hMen);   
			CloseClipboard();

			keybd_event(0x11,0,0,0);			//0x11��ctrl��  0x0D��enter��		0x56�� V ����  ������16���Ʊ�ʾ��	������������0��ʾ���£�2��ʾ�ɿ���
			keybd_event(0x56,0,0,0);			
			keybd_event(0x11,0,2,0);
			keybd_event(0x56,0,2,0);
			keybd_event(0x11,0,0,0);
			keybd_event(0x0D,0,0,0);
			keybd_event(0x11,0,2,0);
			keybd_event(0x0D,0,2,0);
			Sleep(200);			
		}
		system("cls");
		printf("��ܰ�����⣩��ʾ���뽫Ҫ���˵Ļ��ŵ�F���£��������.txt���档�ûس����Ÿ�����\n\n\n");
		printf("����������ó���������һ��������������4�����л�������Ҫִ�г����ҳ�档������˳���������0���ڴ����룺");
		scanf("%d",&i);
	}
	fclose(p);
}
