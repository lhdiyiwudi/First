/*
���  201810420117   ���繤��  Visual Studio
����
********************************************
	 1����¼ϵͳ
		ѧ���������ϵͳ
		����Ա�������ϵͳ

		ͼ�����
		  ����Ա	  ���                   ͼ��Ļ�����Ϣ���� ��ţ����������ߣ������磬��𣬽�����,�۸�
					  ɾ��                   ͼ�飬ͨ��ͼ�����Ż���������ɾ����
					  �鿴					 �鿴ѧ��ͼ��������

		  ѧ��	      �軹��Ǽ�             ���ж��Ƿ����Ȿ�飬�黹��ֹ���ޣ������������еǼǣ�
			          ���˻�������鿴       ���˽�������鿴��

		  ����        ��ѯ                   ͼ��ͨ��ͼ�����ţ����������߽��м�����
					  ���                   ͼ��Ŀ�棬��������Ŀչʾ������
		   
	 2�������˺�
		�ɴ���ѧ���˺�
		�ɴ�������Ա�˺�(���������Ҹ���ָ��������ſ���)
	 3���޸�����
		�������˺�
		�ٸ�������
	 4���˳�ϵͳ
********************************************
ִ�й��̣�ע���˺ţ��ᴴ��һ���ļ����ں��˺���Ϣ����¼ʱ���γ�һ����������ƥ����������˺����룬�ɹ�����������Ľ��棬Ȼ�����ִ�в����������ȶ��ᴴ���ļ�����;
�޸�������Ƚ��ļ����������޸ĺ󣬴�ͷ�������ٴε����ļ���ȡ��ԭ�ļ�ȫ�����ݡ�
		  ͼ�����Ҳ���ƣ���Ϊ���ļ������γ�����������Ҳ��д���ļ�
���ģ��������ļ���������໥ת�����������ļ��������ı���ʽ������ת��
*/

#include <stdio.h>
#include <stdlib.h>//���а���system����
#include <conio.h>//������ͨ������̨���� �������� ����������ĺ�������getch����
#include <string.h>//�����ַ�����
#include <math.h>
#include<malloc.h>//�ռ����
#include<Windows.h>
#include<time.h>//ʱ��ʹ��

char books[30] = "libraryinformation.txt";  //�鼮��Ϣ
char guanlipeople[40] = "adminastrationinformation.txt"; //������Ϣ����
char students[40] = "studentsinformation.txt";//ѧ����Ϣ����
char studentandbook[32] = "student of book information.txt";//ѧ��������Ϣ����
char choice;//ѡ�񰴼�
char studentnumone[17];//ѧ����¼���¼ѧ���˺���Ϊѧ��Ψһ��ʶ
int key = 123456;//�Ҹ�������


//ͼ����Ϣ
struct book
{
	char num[20], name[20], aut[20], pub[20]; //��ţ����������ߣ�������
	int cat;//���
	int  many;//������
	int  kucun;//���
	double price;//�۸�
};
//ͼ������
struct booknode
{
	struct book book;
	struct booknode *next;
};
//������Ϣ
struct borrow
{
	char studentnum[17];//����ţ���ѧ����¼�˺�
	struct tm timetime;//�������ʱ��
	struct book book;//����ͼ����Ϣ
};
//������Ϣ����
struct borrownode
{
	struct borrow borrow;
	struct borrownode*next;
};
//��¼��Ϣ
struct land//��¼��Ϣ
{
	char zhanghao[17];//�˺�
	char password[17];//����
};
//��¼����
struct node
{
	struct land land;
	struct node*next;
};

//����
int displaymenu();//չʾ���˵�
void browse(struct booknode *);//�������ͼ��
void selectinformation();//��ѯͨ���ؼ���Ϣ
void beginregister(char*, char*);//�½��˺�
void enter(char*, char*,char*);//��¼  ��������  ��Ҫ����
void updatekey(char*, char*);//��������
void timedisplay();//ʱ��չʾ
void displayonebook(struct booknode*);//������չʾ
void studentoneborrowshow(struct borrownode*head);//����ѧ����������鿴
struct node *initDate1();//��ʼ�������¼
struct node *initDate2();//��ʼ��ѧ����¼
struct node *importData(FILE *fp);//���������ļ��е�����
struct booknode *initDatebook();//��ʼ��ͼ����Ϣ
struct booknode *importDatabook(FILE *fp);//����ͼ����Ϣ
struct borrownode*initDataborrow();//��ʼ��������Ϣ
struct borrownode*importDataborrow(FILE*fp);//���������Ϣ
//����
int displayguanli();//չʾ�������
void addbooks(char *);//���ͼ��
void drop(char*books);//ɾ��ͼ��
void chakanstudent();//�鿴ѧ���������
//ѧ��
int displaystudents();//չʾѧ������
void borrowreturn();//�������
void studentshow();//ѧ���軹��鿴


void main()
{
	/*
	while (1)
	{
		//system("color 70");//�ױ���������
		displaymenu();//չʾ���˵�
		switch (choice)
		{
		case '1':
			enter(guanlipeople, students,books);//��¼����
			break;
		case '2':
			beginregister(guanlipeople, students);//ע�����
			break;
		case '3':
			updatekey(guanlipeople, students);//��������
			break;
		case '4':exit(0);//�˳�ϵͳ
			break;
		default:
			printf("\nѡ������������\n");
			break;
		}
	}
	*/
	int i = 1;
	i = i++;
	printf("%d\n",i);
	
	system("pause");
}


//����
//���˵�
int displaymenu()
{
	while (1)
	{
		timedisplay();
		printf("\n\t\t\t��ӭʹ��ͼ��ݵ�½ϵͳ\n");
		printf("************************************************************\n");
		printf("\t\t\t1  ��¼ϵͳ\n\t\t\t\tѧ���������ϵͳ\n\t\t\t\t����Ա�������ϵͳ\n");
		printf("\t\t\t2  �����˺�\n\t\t\t\t�ɴ���ѧ���˺�\n\t\t\t\t�ɴ�������Ա�˺�\n");
		printf("\t\t\t\t��û���˺��봴��һ����������ɵ�¼\n\t\t\t\t��Ҫ���������˺�,��������\n");
		printf("\t\t\t3  �޸�����\n\t\t\t\t�������˺�\n\t\t\t\t�ٸ�������\n");
		printf("\t\t\t4  �˳�ϵͳ\n");
		printf("\n\t\t�����˺ž���16Ϊ��\n");
		printf("\n\t\t��Ϊ�������������ȫ�����밴����ʾ����\n\n\t\t��Ӧ����������ʱ�������뺺�ֻ�����ĸ\n");
		printf("************************************************************\n");
		printf("���������ѡ��");
		choice = getche();
		if (1 > (choice - '0') || (choice - '0') > 4)
		{
			printf("\n��������������\n");
			system("pause");
			rewind(stdin);
		}
		else return choice;
	}
}
//���ͼ����Ϣ
void browse(struct booknode*head)
{
	struct booknode*p;
	while (head != NULL)
	{
		printf("\n���Ϊ��%s\n����Ϊ��%s\n���ߣ�%s\n�����磺%s\n���%d\n�����Ϊ��%d\n�۸�%lf\n",head->book.num,head->book.name,head->book.aut,head->book.pub,head->book.cat,head->book.kucun,head->book.price);
		p=head->next ;
		head = p;
	}
	//��һ��ֱ�Ӷ��ļ�����
	/*FILE *fp;
	struct book book;
	fp = fopen(books, "r");
	while (fread(&book,sizeof(struct book),1,fp)==1)
	{
		printf("\n���Ϊ��%s\n����Ϊ��%s\n���ߣ�%s\n�����磺%s\n���%d\n�����Ϊ��%d\n�۸�%lf\n",head->book.num,head->book.name,head->book.aut,head->book.pub,head->book.cat,head->book.kucun,head->book.price);
	}*/
}
//��ѯͼ����Ϣ
void selectinformation()
{
	printf("\n��ӭ����ͼ���ѯ����\n��������ͨ��ͼ�����ţ����������߽��м���\n");
	printf("\n(1)���(2)����(3)����\n");
	choice = getche();
	if (1 > (choice - '0') || (choice - '0') > 3)
	{
		printf("\n��������������\n");
		system("pause");
		rewind(stdin);
	}
	//������Ų�ѯ
	if (choice == '1')
	{
		int judge = 1;
		struct booknode *head, *p;
		struct book book;
		head = initDatebook();//�����鼮��Ϣ
		printf("\n������ͼ����ţ�\n");
		scanf("%s", book.num);
		while (head != NULL)
		{
			if (strcmp(head->book.num, book.num) == 0)
			{
				printf("\n�Ѿ�ƥ�䵽ͼ��\n");
				displayonebook(head);
				judge = 0;
			}
			p = head->next;
			head = p;
		}
		free(head);
		if (judge == 1)
			printf("\nδ�ҵ�ͼ����Ϣ\n");
	}
	//����������ѯ
	if (choice == '2')
	{
		int judge = 1;
		struct booknode *head, *p;
		struct book book;
		head = initDatebook();//�����鼮��Ϣ
		printf("\n������ͼ��������\n");
		scanf("%s", book.name);
		while (head != NULL)
		{
			if (strcmp(head->book.name, book.name) == 0)
			{
				printf("\n�Ѿ�ƥ�䵽ͼ��\n");
				displayonebook(head);
				judge = 0;
			}
			p = head->next;
			head = p;
		}
		free(head);
		if (judge == 1)
			printf("\nδ�ҵ�ͼ����Ϣ\n");
	}
	//�������߲�ѯ
	if (choice == '3')
	{
		int judge = 1;
		struct booknode *head, *p;
		struct book book;
		head = initDatebook();//�����鼮��Ϣ
		printf("\n������ͼ�����ߣ�\n");
		scanf("%s", book.aut);
		while (head != NULL)
		{
			if (strcmp(head->book.aut, book.aut) == 0)
			{
				printf("\n�Ѿ�ƥ�䵽ͼ��\n");
				displayonebook(head);
				judge = 0;
			}
			p = head->next;
			head = p;
		}
		free(head);
		if (judge == 1)
			printf("\nδ�ҵ�ͼ����Ϣ\n");
	}
}
//�½��ļ����˺ţ�
//����˺��Ƿ���ڣ������ڲ���ע��
void beginregister(char*guanli, char*students)
{
	FILE *fp; int select; struct land land;
	int flag = 1;
	int guanlizhuru;
	char zhanghao[17]; char password[17];

	//ע���˺�
	while (flag)
	{
		printf("\n�����ѧ���κ�һ���ļ������ھ���Ҫ����һ��\n�˺����뾡����Ҫ̫�����˳�����$��\n");
		printf("�����˺ţ�");
		scanf("%s", zhanghao);
		strcpy(land.zhanghao, zhanghao);
		//�˳�
		if (strcmp(zhanghao, "$") == 0)
		{
			printf("\n�����ϼ�����\n");
			return;
		}
		//�ж��˺��Ƿ��Ѿ�����

		int flag2;
		struct node *head, *p;
		head = initDate1();//���������Ϣ�ļ��γ�����
		while (head != NULL)
		{
			flag2 = 1;
			flag2 = strcmp(head->land.zhanghao, land.zhanghao);
			if (flag2 == 0)
			{
				printf("\n�˺��Ѿ����ڣ�������ѡ��\n");
				return;
			}
			p = head->next;
			head = p;
		}

		int flag3;
		struct node *head2, *p2;
		head2 = initDate2();//����ѧ����Ϣ�ļ��γ�����
		while (head2 != NULL)
		{
			flag3 = 1;
			flag3 = strcmp(head2->land.zhanghao, land.zhanghao);
			if (flag3 == 0)
			{
				printf("\n�˺��Ѿ����ڣ�������ѡ��\n");
				return;
			}
			p2 = head2->next;
			head2 = p2;
		}

		//����˺Ų����ڼ�������
		printf("�������룺");
		scanf("%s", password);
		strcpy(land.password, password);
		printf("�����Ҫ��Ϊ��������Ҫ�������루�Ҹ�����һ�����룩\n");
		printf("\n���������Ϊ������ѧ����\n����1Ϊ����\n����2Ϊѧ��\n");
		select = getche();
		switch (select)
		{
		case '1':
			printf("\n�������Ҹ������룺");
			scanf("%d", &guanlizhuru);
			if (key == guanlizhuru)
			{
				if ((fp = fopen(guanli, "r")) == NULL)
				{
					fp = fopen(guanli, "w");
					fclose(fp);
				}
				fclose(fp);
				fp = fopen(guanli, "a");
				fwrite(&land, sizeof(struct land), 1, fp);
				fclose(fp);
				printf("ע��ɹ�\n");
				flag = 0;
			}
			else printf("\n�������\n");
			break;
		case '2':
			if ((fp = fopen(students, "r")) == NULL)
			{
				fp = fopen(students, "w");
				fclose(fp);
			}
			fclose(fp);
			fp = fopen(students, "a");
			fwrite(&land, sizeof(struct land), 1, fp);
			fclose(fp);
			printf("ע��ɹ�\n");
			flag = 0;
			break;
		default:printf("\n�����������������\n"); break;
		}rewind(stdin);
	}
}
//��¼��֤��������  ��Ҫ����
//�ж��˺������Ƿ���ȷ����ȷ�������ѧ������������
void enter(char*guanli, char*students,char*books)
{
	char zhanghao[17];
	char mima[17];
	char choose;
	int flag;//�Ƿ�����ж�����
	int judge = 1;//0Ϊ��¼�ɹ�
	printf("\n�������˺�����\n");
	printf("�˺�:");
	scanf("%s", zhanghao);
	printf("����:");
	scanf("%s", mima);
	rewind(stdin);
	struct land lander;
	strcpy(lander.zhanghao, zhanghao);
	strcpy(lander.password, mima);
	printf("��������ǹ�����ѧ����\n (1)����Ա\t(2)ѧ��\n");
	scanf("%c", &choose);

	//�����¼
	if (choose == '1')
	{
		//�ж��˺������Ƿ���ȷ
		struct node *head, *p;
		//�����¼��Ϣͷָ��
		head = initDate1();
		while (head != NULL)
		{
			flag = strcmp(head->land.zhanghao, lander.zhanghao);
			if (flag == 0)
			{
				flag = strcmp(head->land.password, lander.password);
			}
			if (flag == 0) judge = 0;
			p = head->next;
			head = p;
		}
		free(head);


		if (judge == 0)
		{
			//��������������
			int judge2 = 1;
			printf("\n��¼�ɹ�\n��ӭ����������\n");
			while (judge2)
			{
				judge2 = 1;
				struct booknode*head;
				head = initDatebook();
				//����ͼ����Ϣͷָ��
				displayguanli();
				switch (choice)
				{
				case '1':addbooks(books);
					break;
				case '2':drop(books);
					break;
				case '3':selectinformation();
					break;
				case '4':browse(head);
					break;
				case'5':chakanstudent();
					break;
				case'6':
					judge2 = 0;
					break;
				default:
					printf("\n��������\n");
					break;
				}
				free(head);
			}
		}
		else
			printf("��¼ʧ��\n");
	}

	//ѧ����¼
	if (choose == '2')
	{
		//�ж��˺������Ƿ���ȷ
		struct node *head, *p;
		head = initDate2();
		int judge2 = 1;//0��¼ѧ���˺�
		while (head != NULL)
		{
			flag = strcmp(head->land.zhanghao, lander.zhanghao);
			if (flag == 0)
			{
				flag = strcmp(head->land.password, lander.password);
			}
			if (flag == 0) 
			{
				judge = 0; judge2 = 0;
			}

			//�˺�����ƥ����¼�˺�
			if (judge2 == 0)
			{
				strcpy(studentnumone, head->land.zhanghao);
			}
			judge2 = 1;
			p = head->next;
			head = p;
		}
		free(head);


		if (judge == 0)
		{
			//����ѧ����������
			int judge3 = 1;
			printf("\n��¼�ɹ�\n��ӭ����ѧ������\n");
			while (judge3)
			{
				judge3= 1;
				struct booknode*head;
				head = initDatebook();
				//����ͼ����Ϣͷָ��
				displaystudents();
				switch (choice)
				{
				case '1':borrowreturn();
					break;
				case '2':studentshow();
					break;
				case '3':selectinformation();
					break;
				case '4':browse(head);
					break;
				case'5':
					judge3 = 0;
					break;
				default:
					printf("\n��������\n");
					break;
				}
				free(head);
			}
		}
		else
			printf("��¼ʧ��\n");
	}

}
//��������
//����˺������Ƿ���ȷ����ȷ�ſ��Ը���
void updatekey(char*guanli, char*students)
{
	char select;
	printf("\n��ӭ�����޸�����ѡ��\n");
	printf("��������Ҫ�޸ĵ��ǹ���Ա����ѧ����\n(1)����Ա\t(2)ѧ��\n");
	scanf("%c", &select);
	if (select == '1')
	{
		//��������
		struct land lander;
		printf("\n�������˺ţ�");
		scanf("%s", lander.zhanghao);
		printf("\n������ԭ�������룺");
		scanf("%s", lander.password);
		int flag, judge = 1;
		struct node *head, *headtou, *p;
		head = initDate1();//���������Ϣ�ļ�
		headtou = head;//��¼ͷλ��
		while (head != NULL)
		{
			flag = 1;
			flag = strcmp(head->land.zhanghao, lander.zhanghao);
			if (flag == 0)
			{
				flag = strcmp(head->land.password, lander.password);
			}
			//�˺��������ȷ
			while (flag == 0)
			{
				printf("\nԭ�˺�������ȷ\n�������µ�����:");
				rewind(stdin);
				scanf("%s", head->land.password);//�޸�����
				//����������д���ļ�
				FILE*fp;
				fp = fopen(guanlipeople, "w");
				while (headtou != NULL)
				{
					fwrite(&headtou->land, sizeof(struct land), 1, fp);//��һ����¼д�������ļ� 
					headtou = headtou->next;
				}
				fclose(fp);
				printf("\n�޸ĳɹ�\n");
				return;
			}
			p = head->next;
			head = p;
		}
		printf("\n�˺Ż����������");
	}
	if (select == '2')
	{
		//��������
		struct land lander;
		printf("\n�������˺ţ�");
		scanf("%s", lander.zhanghao);
		printf("\n������ԭ�������룺");
		scanf("%s", lander.password);
		int flag, judge = 1;
		struct node *head, *headtou, *p;
		head = initDate2();//���������Ϣ�ļ�
		headtou = head;//��¼ͷλ��
		while (head != NULL)
		{
			flag = 1;
			flag = strcmp(head->land.zhanghao, lander.zhanghao);
			if (flag == 0)
			{
				flag = strcmp(head->land.password, lander.password);
			}
			//�˺��������ȷ
			while (flag == 0)
			{
				printf("\nԭ�˺�������ȷ\n�������µ�����:");
				rewind(stdin);
				scanf("%s", head->land.password);//�޸�����
				//����������д���ļ�
				FILE*fp;
				fp = fopen(students, "w");
				while (headtou != NULL)
				{
					fwrite(&headtou->land, sizeof(struct land), 1, fp);//��һ����¼д�������ļ� 
					headtou = headtou->next;
				}
				fclose(fp);
				printf("\n�޸ĳɹ�\n");
				return;
			}
			p = head->next;
			head = p;
		}
		printf("\n�˺Ż����������");
	}
	printf("\n��������˳��˹���ģ��\n");
}
//ʱ��չʾ
void timedisplay()
{
	struct tm timetime;
	time_t now = time(NULL);//�õ���1900�������
	timetime = *localtime(&now);//���仯Ϊ����ʱ���ʽ����ṹ����
	printf("\n���ڵ�ʱ���ǣ�%d��%d��%d��%d:%d:%d\n",timetime.tm_year+1900,timetime.tm_mon+1,timetime.tm_mday,timetime.tm_hour,timetime.tm_min,timetime.tm_sec );
}
//������չʾ
void displayonebook(struct booknode*head)
{
	printf("\n���Ϊ��%s\n����Ϊ��%s\n���ߣ�%s\n�����磺%s\n���%d\n�����Ϊ��%d\n�۸�%lf\n", head->book.num, head->book.name, head->book.aut, head->book.pub, head->book.cat, head->book.kucun, head->book.price);
}
//����ѧ����������鿴
void studentoneborrowshow(struct borrownode*head)
{
	printf("\n\nѧ����Ϊ��%s ", head->borrow.studentnum);
	printf("\nͼ���Ϊ��%s", head->borrow.book.num);
	printf("\nͼ����Ϊ��%s", head->borrow.book.name);
	printf("\n����Ϊ��%s", head->borrow.book.aut);
	printf("\n������Ϊ��%s", head->borrow.book.pub);
	printf("\nͼ������Ϊ����1����ơ�2���Ŀơ�3����ƹ��ߡ�4���Ŀƹ��ߡ�5���ٿ�\n%d", head->borrow.book.cat);
	printf("\n����Ϊ��%lf", head->borrow.book.price);
	printf("\n������ݣ�%d", head->borrow.timetime.tm_year + 1900);
	printf("\t�·ݣ�%d", head->borrow.timetime.tm_mon + 1);
	printf("\t���ڣ�%d", head->borrow.timetime.tm_mday);
}


//����
//���ͼ����Ϣ
void addbooks(char *books)
{
	FILE*fp;
	int flag = 1;
	//���ѡ��
	while (flag)
	{
		printf("\n��1���¼�ͼ�飨2�����ӿ��\nӦ��������ʱ�벻Ҫ����Ӣ�ģ��������ֲ���Ԥ֪�Ĵ���!\n����ͼ������ӿ�棬�����¼ӷ�����ظ�\n");
		printf("���������ѡ��");
		choice = getche();
		if (1 > (choice - '0') || (choice - '0') > 2)
		{
			printf("\n��������������\n");
			system("pause");
			rewind(stdin);
		}
		else flag = 0;
	}

	//�¼�ͼ��
	if (choice == '1')
	{
		struct book book;
		while (1)
		{
			printf("\n\n\n�¼�ͼ�鹦��\nͼ�����Ϊ$���˳��˹���\n������ͼ�������Ϣ\n");
			printf("(1)ͼ��ţ�\n");
			scanf("%s", book.num);
			if (strcmp(book.num, "$") == 0)
			{
				printf("\n�����ϼ�����\n");
				return;
			}
			printf("(2)ͼ������\n");
			scanf("%s", book.name);
			printf("(3)�������֣�\n");
			scanf("%s", book.aut);
			printf("(4)�����磺\n");
			scanf("%s", book.pub);
			printf("(5)���: \n��1����ơ�2���Ŀơ�3����ƹ��ߡ�4���Ŀƹ��ߡ�5���ٿ�\n");
			scanf("%d", &book.cat);
			printf("(6)��������\n");
			scanf("%d", &book.many);
			book.kucun = book.many;
			printf("(7)���: \n%d\n ",book.kucun);

			//printf("\n%d\n",&book.kucun);
			//����&�ͻ���һ���ܴ���޹�����

			printf("(8)���ۣ�\n");
			scanf("%lf", &book.price);

			fp = fopen(books, "a");
			fwrite(&book, sizeof(struct book), 1, fp);
			fclose(fp);
			printf("\n�Ѿ�д��һ���飡\n");
			rewind(stdin);
		}
	}

	//��ӿ��
	if (choice == '2')
	{
		struct book book;
		while (1)
		{
			struct booknode *head;
			head = initDatebook();//����ͼ����Ϣͷ�ļ�,ÿ�α�֤ͷ�����λ��
			struct booknode*p, *headlocal;//headlocal��λ��λ��ַ pѭ��ʹ�� 
			headlocal = head;
			printf("\n\n\n����ͼ���湦��\nͼ�����Ϊ$���˳��˹���\n������ͼ�������Ϣ\n");
			printf("(1)ͼ��ţ�\n");
			scanf("%s", book.num);
			//�˳�
			if (strcmp(book.num, "$") == 0)
			{
				printf("\n�����ϼ�����\n");
				return;
			}
			//Ѱ��ͼ��
			flag = 1;
			while (head != NULL && flag != 0)
			{
				flag = strcmp(head->book.num, book.num);
				if (flag == 0)
				{
					printf("\nͼ�����ҵ�������\n(6)��������\n");
					scanf("%d", &book.many);
					//�������ӵ������еĽڵ���
					head->book.kucun =head->book.kucun + book.many;
					printf("(7)�ֿ��:%d\n", head->book.kucun);
					//д���ļ�
					fp = fopen(books, "w");
					while (headlocal != NULL)
					{
						fwrite(headlocal, sizeof(struct book), 1, fp);
						p = headlocal->next;
						headlocal = p;
					}
					fclose(fp);
					printf("\n�Ѿ�д���¼��\n");
					rewind(stdin);
				}
				p = head->next;
				head = p;
			}
			if (head == NULL&&flag!=0)
				printf("\nδ�ҵ���ͼ��\n");
			free(head);
		}
	}
}
//ɾ��ͼ����Ϣ
void drop(char *books)
{
	while (1)
	{
		printf("\n��ӭ����ɾ��ͼ�鹦��\n\nͼ�����Ϊ$���˳��˹���\n��ɾ����ͼ���ǵ�һ���Ļ�û��ȷ�ϲ�����\n�Ƿ������һ��ͼ���棿��1����\t(2)��\n");
		choice = getche();
		if (1 > (choice - '0') || (choice - '0') > 2)
		{
			printf("\n��������������\n");
			system("pause");
			rewind(stdin);
		}
		//�����һ��ͼ��
		if (choice == '1')
		{
			struct booknode *head;
			head = initDatebook();
			browse(head);
			free(head);
		}
		//ɾ��ͼ�鹦��
		if (choice == '2')
		{
			struct book book;
			printf("\nɾ��ͼ�飺\n����������ɾ����ͼ��ţ�");
			scanf("%s", book.num);
			//�˳�
			if (strcmp(book.num, "$") == 0)
			{
				printf("\n�����ϼ�����\n");
				return;
			}
			//ɾ��������ṹ
			int flag2 = 1;
			struct booknode *head, *p, *q;
			head = initDatebook();
			//����Ѿ�û����,����Ϊ�գ�ֱ�ӷ���
			if (head == NULL)
			{
				printf("\n����Ϊ��,û���鼮��Ϣ\n");
				return;
			}
			p = head;
			q = p->next;
			while (q != NULL)
			{
				//�ҵ��Ȿ��
				if (strcmp(q->book.num, book.num) == 0)
				{
					flag2 = 0;
					//�Է��������
					printf("\nͼ�����ƥ��\n�Ƿ�ɾ���Ȿͼ��\n(1)��(2)��\n");
					choice = getche();
					if (1 > (choice - '0') || (choice - '0') > 2)
					{
						printf("��������������\n");
						system("pause");
						rewind(stdin);
					}
					if (choice == '1')
					{
						//ɾ��ͼ��ʵ��
						p->next = q->next;
						free(q);
						q = p->next;
						printf("\n�Ѿ�ɾ���Ȿͼ�飡\n");
					}
					if (choice == '2')
					{
						printf("\n��ȡ��ɾ��\n");
					}
				}
				else
				{
					p = p->next;
					q = q->next;
				}
			}
			//�������ͷ�ڵ�
			if (head != NULL && 0 == strcmp(head->book.num, book.num))
			{
				q = head;
				head = q->next;
				free(q);
				printf("\n�Ѿ��ҵ����Ѿ�ɾ���Ȿͼ�飡\n");
				flag2 = 0;
			}
			//д���ļ�
			FILE*fp;
			fp = fopen(books, "w");
			while (head != NULL)
			{
				fwrite(head, sizeof(struct book), 1, fp);
				p = head->next;
				head = p;
			}
			fclose(fp);
			//û�ҵ�
			if (flag2 == 1)
				printf("\nδ�ҵ��Ȿͼ��\n");

		}
	}
}
//չʾ����˵�
int displayguanli()
{
	while (1)
	{
		timedisplay();
		printf("\n*************************************************************\n");
		printf("\n\t\t\t��ӭ����������\n");
		printf("\t\t\t(1)���ͼ����Ϣ\n\t\t\t\t������������Ϊ������ٿ�棩\n");
		printf("\t\t\t(2)ɾ��ͼ����Ϣ\n");
		printf("\t\t\t(3)��ѯͼ�飨�����������������ȣ�\n");
		printf("\t\t\t(4)���ͼ��ȫ����Ϣ\n");
		printf("\t\t\t(5)����ѧ���������\n");
		printf("\t\t\t(6)�����ϼ�Ŀ¼\n");
		printf("**************************************************************\n");
		choice = getche();
		if (1 > (choice - '0') || (choice - '0') > 6)
		{
			printf("\n��������������\n");
			system("pause");
			rewind(stdin);
		}
		else return choice;
	}
}
//�鿴ѧ���������
void chakanstudent()
{
	printf("\n��ӭ�鿴ѧ���Ľ������\n");
	while (1)
	{
		printf("\n������$�˳���\n������ѧ��ѧ�ţ�\n");
		struct borrownode*head, *p;
		char xuehao[17];
		scanf("%s", xuehao);
		//�˳�
		if (xuehao[0] == '$')
		{
			printf("\n�˳��鿴����\n");
			return;
		}
		head = initDataborrow();
		int flag = 1;//flag=0�����������Ϣ
		while (head != NULL)
		{
			flag = strcmp(head->borrow.studentnum, xuehao);
			if (flag == 0)
			{
				studentoneborrowshow(head);
			}
			p = head->next;
			head = p;
		}
	}
}


//ѧ��
//ѧ���軹��鿴
void studentshow()
{
	printf("\n��ӭ����ѧ�����˽軹��鿴����\n");
	printf("\n��Ľ��������\n");
	struct borrownode *head, *p;
	head = initDataborrow();
	int flag = 1;
	while (head != NULL)
	{
		flag=strcmp(head->borrow.studentnum, studentnumone);
		if (flag == 0)                                          
		{
			studentoneborrowshow(head);
		}
		p = head->next;
		head = p;
	}
}
//չʾѧ�������˵�
int displaystudents()
{
	while (1)
	{
		timedisplay();
		printf("\n****************************************************************\n");
		printf("\t\t\t��ӭ����ѧ������\n");
		printf("\t\t\t(1)�軹�����\n");
		printf("\t\t\t(2)�鿴�軹�����\n");
		printf("\t\t\t(3)��ѯͼ�飨�����������������ȣ�\n");
		printf("\t\t\t(4)���ͼ��ȫ����Ϣ\n");
		printf("\t\t\t(5)�����ϼ�Ŀ¼\n");
		printf("****************************************************************\n");
		choice = getche();
		if (1 > (choice - '0') || (choice - '0') > 5)
		{
			printf("\n��������������\n");
			system("pause");
			rewind(stdin);
		}
		else return choice;
	}
}
//�軹�����
void borrowreturn()
{
	printf("\n��ӭ����ѧ���軹��鿴����\n��1�����飨2������\n");
	printf("���������ѡ��");
	choice = getche();
	if (1 > (choice - '0') || (choice - '0') > 2)
	{
		printf("\n��������������\n");
		system("pause");
		rewind(stdin);
	}
	//����
	if (choice == '1')
	{
		struct book bookk;//������������������
		int flag = 1;//ѭ����־
		while (flag)
		{
			char choice2;//��1����Ż��ߣ�2������
			printf("\n�������������Ż����������飺\n��1����ţ�2������\n (3)�˳����鹦��\n");
			choice2 = getche();
			if (1 > (choice2 - '0') || (choice2 - '0') > 3)
			{
				printf("\n��������������\n");
				system("pause");
				rewind(stdin);
			}
			//�������
			if (choice2 == '1')
			{
				struct booknode *head, *headtou, *headtou2, *p = NULL;
				int flag2 = 1, judge = 1;//judge=0�ҵ��鼮
				head = initDatebook();
				headtou = head;
				headtou2 = head;
				printf("\n������������ͼ�����\n");
				scanf("%s", bookk.num);
				while (head != NULL)
				{
					flag2 = strcmp(head->book.num, bookk.num);//�ҵ�ͼ��
					if (flag2 == 0)
					{
						judge = 0;
						printf("\n���ҵ�������ͼ��\n");
						displayonebook(head);
						//ȷ�ϲ���
						printf("\n�Ƿ�Ҫ���Ȿ�飺��1���ǣ�2����\n");
						choice = getche();
						if (1 > (choice2 - '0') || (choice2 - '0') > 2)
						{
							printf("\n��������������\n");
							system("pause");
							rewind(stdin);
						}
						//����ʵ��
						if (choice == '1')
						{
							//����һ
							head->book.kucun = head->book.kucun - 1;
							//д���ļ�,�鼮����һ
							FILE*fp;
							fp = fopen(books, "w");
							while (headtou != NULL)
							{
								fwrite(headtou, sizeof(struct book), 1, fp);
								p = headtou->next;
								headtou = p;
							}
							fclose(fp);
							headtou = headtou2;
							//ʱ��õ�
							struct tm timetime;
							time_t now = time(NULL);//�õ���1900�������
							timetime = *localtime(&now);//���仯Ϊ����ʱ���ʽ����ṹ����
							//ѧ��������Ϣ��һ
							struct borrow borrow;
							strcpy(borrow.studentnum, &studentnumone);
							strcpy(borrow.book.num, head->book.num);
							strcpy(borrow.book.name, head->book.name);
							strcpy(borrow.book.aut, head->book.aut);
							strcpy(borrow.book.pub, head->book.pub);
							borrow.book.cat = head->book.cat;
							borrow.book.price = head->book.price;
							borrow.timetime.tm_year = timetime.tm_year;
							borrow.timetime.tm_mon = timetime.tm_mon;
							borrow.timetime.tm_mday = timetime.tm_mday;

							//д���ļ���������Ϣ��һ
							FILE*fp2;
							fp2 = fopen(studentandbook, "a");
							fwrite(&borrow, sizeof(struct borrow), 1, fp2);
							fclose(fp2);
							printf("\n����ɹ�\n");
						}
						//ȡ��
						if (choice == '2')
						{
							printf("\n�Ѿ�ȡ��\n");
						}
					}
					p = head->next;
					head = p;
				}
				if (judge != 0)
				{
					printf("\nδ�ҵ���ͼ��\n");
				}
				choice = NULL;
			}
			//��������
			if (choice2 == '2')
			{
				struct booknode *head, *headtou, *headtou2, *p;
				int flag2 = 1, judge = 1;//judge=0�ҵ��鼮
				head = initDatebook();
				headtou = head;
				headtou2 = head;
				printf("\n������������ͼ������\n");
				scanf("%s", bookk.name);
				while (head != NULL)
				{
					flag2 = strcmp(head->book.name, bookk.name);//�ҵ�ͼ��
					if (flag2 == 0)
					{
						judge = 0;
						printf("\n���ҵ�������ͼ��\n");
						displayonebook(head);
						//ȷ�ϲ���
						printf("\n�Ƿ�Ҫ���Ȿ�飺��1���ǣ�2����\n");
						choice = getche();
						if (1 > (choice2 - '0') || (choice2 - '0') > 2)
						{
							printf("\n��������������\n");
							system("pause");
							rewind(stdin);
						}
						//����ʵ��
						if (choice == '1')
						{
							//����һ
							head->book.kucun = head->book.kucun - 1;
							//д���ļ�,�鼮����һ
							FILE*fp;
							fp = fopen(books, "w");
							while (headtou != NULL)
							{
								fwrite(headtou, sizeof(struct book), 1, fp);
								p = headtou->next;
								headtou = p;
							}
							fclose(fp);
							headtou = headtou2;
							//ʱ��õ�
							struct tm timetime;
							time_t now = time(NULL);//�õ���1900�������
							timetime = *localtime(&now);//���仯Ϊ����ʱ���ʽ����ṹ����
							//ѧ��������Ϣ��һ
							struct borrow borrow;
							strcpy(borrow.studentnum, &studentnumone);
							strcpy(borrow.book.num, head->book.num);
							strcpy(borrow.book.name, head->book.name);
							strcpy(borrow.book.aut, head->book.aut);
							strcpy(borrow.book.pub, head->book.pub);
							borrow.book.cat = head->book.cat;
							borrow.book.price = head->book.price;
							borrow.timetime.tm_year = timetime.tm_year;
							borrow.timetime.tm_mon = timetime.tm_mon;
							borrow.timetime.tm_mday = timetime.tm_mday;

							//д���ļ���������Ϣ��һ
							FILE*fp2;
							fp2 = fopen(studentandbook, "a");
							fwrite(&borrow, sizeof(struct borrow), 1, fp2);
							fclose(fp2);
							printf("\n����ɹ�\n");
						}
						//ȡ��
						if (choice == '2')
						{
							printf("\n�Ѿ�ȡ��\n");
						}
					}
					p = head->next;
					head = p;
				}
				if (judge != 0)
				{
					printf("\nδ�ҵ���ͼ��\n");
				}
				choice = NULL;
			}
			//�˳����鹦��
			if (choice2 == '3')
			{
				flag = 0;
			}
		}
	}
	//����
	if (choice == '2')
	{
		while (1)
		{
			printf("\n����ֻ�ܸ���ͼ��Ų���\n����ɹ��Ὣͼ��������Ϊ���ѻ��鼮��\n�����˺�Ϊ��%s\n���˳��軹�����������$��\n����������ͼ����ţ�", &studentnumone);
			char bookkk[17];
			scanf("%s", bookkk);
			//�˳�
			if (bookkk[0]== '$' )
			{
				printf("\n�˳��軹�����\n");
				return;
			}

			struct booknode *head, *headtou, *p;
			struct borrownode*head2, *headtou2, *p2;
			int flag = 1;//0�ӽ�����Ϣ���ҵ��뵱ǰ�˺��йصĽ�����Ϣ�ṹ��
			int flag2 = 1;//0�ҵ������ļ��ļ����˺��е�ͼ���
			int flag3 = 1;//0ͼ���ļ����ҵ�
			int flagg = 1;//�Ƿ������δ�ҵ�ͼ�顱
			char huanshu[9] = "�ѻ��鼮";
			head = initDatebook();//ͼ����Ϣ
			head2 = initDataborrow();//������Ϣ
			headtou = head;
			headtou2 = head2;
			while (head2 != NULL)
			{
				//�ӽ�����Ϣ���ҵ��뵱ǰ�˺��йصĽ�����Ϣ�ṹ��
				flag = strcmp(head2->borrow.studentnum, studentnumone);
				if (flag == 0)
				{
					//�ҵ������ļ��ļ����˺��е�ͼ���
					flag2 = strcmp(head2->borrow.book.num, bookkk);
					if (flag2 == 0)
					{
						//����ʵ��
						strcpy(head2->borrow.book.name, huanshu);
						//ͼ�����һ
						while (head != NULL)
						{
							flag3 = strcmp(head->book.num, bookkk);
							if (flag3 == 0)
							{
								head->book.kucun = head->book.kucun + 1;
								flagg = 0;//ȫ���޸�ʵ��,����������Ƕλ�
							}
							p = head->next;
							head = p;
						}
					}
				}
				p2 = head2->next;
				head2 = p2;
			}
			//д�������Ϣ�ļ�
			FILE*fp2;
			fp2 = fopen(studentandbook, "w");
			while (headtou2 != NULL)
			{
				fwrite(headtou2, sizeof(struct borrow), 1, fp2);
				p2 = headtou2->next;
				headtou2 = p2;
			}
			fclose(fp2);
			//д��ͼ����Ϣ�ļ�
			FILE*fp;
			fp = fopen(books, "w");
			while (headtou != NULL)
			{
				fwrite(headtou, sizeof(struct book), 1, fp);
				p = headtou->next;
				headtou = p;
			}
			fclose(fp);

			//û�ҵ�
			if (flagg == 1)
				printf("\nδ�ҵ��Ȿͼ��\n");
			if (flagg == 0)
				printf("\n�Ѿ�����ɹ�\n");
		}
	}
}


//���������ļ��е�����
struct node *importData(FILE *fp)
{
	struct node*head = NULL, *p, *q;//headָ������ͷ;pָ���½ڵ�; //qָ���������һ���ڵ� 
	struct land land;//������¼����ʱ���� 
	fread(&land, sizeof(struct land), 1, fp);//�������ļ��ж�ȡһ���˺���Ϣ 
	while (1 != feof(fp))          //����ļ�û�н���,����ѭ�� 
	{
		if (head == NULL)//������ĵ�һ���ڵ�Ĵ��� 
		{
			//����ڵ�ռ� 
			head = (struct node*)malloc(sizeof(struct node));
			head->land = land;//�Ѵ��ļ��ж���ļ�¼,���������һ���ڵ� 
			head->next = NULL;//�ѽڵ�ĺ��ָ����NULL 
			q = head;
		}
		else//�ǵ�һ���ڵ�Ĵ���
		{
			p = (struct node*)malloc(sizeof(struct node));
			p->land = land;
			p->next = NULL;
			q->next = p; // �����½ڵ㵽��β 
			q = p; //��qָ��ָ���½ڵ�
		}
		fread(&land, sizeof(struct land), 1, fp);// �������ļ��ж�ȡ��һ����¼ 
	}return head;//���ص�����ı�ͷָ�� 
}
//��ʼ������Ա��¼ϵͳ1
struct node *initDate1()
{
	FILE*fp;
	struct node *land;
	// �����1��ʹ��ϵͳ���ļ����ɹ� 
	if ((fp = fopen(guanlipeople, " r")) == NULL)
	{
		fp = fopen(guanlipeople, "w");
		fclose(fp);
		printf("\n�ɹ��½�һ���ļ��������˳�ϵͳ����ִ�в�����\n");
		exit(0);
	}
	else      //��������ļ�����,ֱ�ӵ������� 
		land = importData(fp);//���������ļ������� 
	fclose(fp);//�ر��ļ� 
	return land;//���ش洢���ݵĵ�����ͷ 
}
//��ʼ��ѧ����¼ϵͳ
struct node *initDate2()
{
	FILE*fp;
	struct node *land;
	// �����1��ʹ��ϵͳ���ļ����ɹ� 
	if ((fp = fopen(students, " r")) == NULL)
	{
		fp = fopen(students, "w");
		fclose(fp);
		printf("\n�ɹ��½�һ���ļ��������˳�ϵͳ����ִ�в�����\n");
		exit(0);
	}
	else      //��������ļ�����,ֱ�ӵ������� 
		land = importData(fp);//���������ļ������� 
	fclose(fp);//�ر��ļ� 
	return land;//���ش洢���ݵĵ�����ͷ 
}


//��ʼ��ͼ����Ϣ
struct booknode *initDatebook()
{
	FILE*fp;
	struct booknode *book;
	// �����1��ʹ��ϵͳ���ļ����ɹ� 
	if ((fp = fopen(books, " r")) == NULL)
	{
		fp = fopen(books, "w");
		fclose(fp);
		printf("\n(����������)�ɹ��½�һ��ͼ����Ϣ�ļ��������˳�ϵͳ���������У���ִ�в�����\n");
		exit(0);
	}
	else      //��������ļ�����,ֱ�ӵ������� 
		book = importDatabook(fp);//���������ļ������� 
	fclose(fp);//�ر��ļ� 
	return book;//���ش洢���ݵĵ�����ͷ 
}
//����ͼ���ļ��е�����
struct booknode *importDatabook(FILE *fp)
{
	struct booknode*head = NULL, *p, *q;//headָ������ͷ;pָ���½ڵ�; //qָ���������һ���ڵ� 
	struct book book;//������¼����ʱ���� 
	fread(&book, sizeof(struct book), 1, fp);//�������ļ��ж�ȡһ���˺���Ϣ 
	while (1 != feof(fp))          //����ļ�û�н���,����ѭ�� 
	{
		if (head == NULL)//������ĵ�һ���ڵ�Ĵ��� 
		{
			//����ڵ�ռ� 
			head = (struct booknode*)malloc(sizeof(struct booknode));
			head->book = book;//�Ѵ��ļ��ж���ļ�¼,���������һ���ڵ� 
			head->next = NULL;//�ѽڵ�ĺ��ָ����NULL 
			q = head;
		}
		else//�ǵ�һ���ڵ�Ĵ���
		{
			p = (struct booknode*)malloc(sizeof(struct booknode));
			p->book = book;
			p->next = NULL;
			q->next = p; // �����½ڵ㵽��β 
			q = p; //��qָ��ָ���½ڵ�
		}
		fread(&book, sizeof(struct book), 1, fp);// �������ļ��ж�ȡ��һ����¼ 
	}return head;//���ص�����ı�ͷָ�� 
}


//��ʼ��������Ϣ
struct borrownode*initDataborrow()
{
	FILE*fp;
	struct borrownode *studentborrow;
	// �����1��ʹ��ϵͳ���ļ����ɹ� 
	if ((fp = fopen(studentandbook, " r")) == NULL)
	{
		fp = fopen(studentandbook, "w");
		fclose(fp);
		printf("\n(����������)�ɹ��½�һ��������Ϣ�ļ����ղŵĲ�����δ���棡�����˳�ϵͳ���������У���ִ�в�����\n");
		exit(0);
	}
	else      //��������ļ�����,ֱ�ӵ������� 
		studentborrow = importDataborrow(fp);//���������ļ������� 
	fclose(fp);//�ر��ļ� 
	return studentborrow;//���ش洢���ݵĵ�����ͷ 
}
//���������Ϣ
struct borrownode*importDataborrow(FILE*fp)
{
	struct borrownode*head = NULL, *p, *q;//headָ������ͷ;pָ���½ڵ�; //qָ���������һ���ڵ� 
	struct borrow borrow;//������¼����ʱ���� 
	fread(&borrow, sizeof(struct borrow), 1, fp);//�������ļ��ж�ȡһ���˺���Ϣ 
	while (1 != feof(fp))          //����ļ�û�н���,����ѭ�� 
	{
		if (head == NULL)//������ĵ�һ���ڵ�Ĵ��� 
		{
			//����ڵ�ռ� 
			head = (struct borrownode*)malloc(sizeof(struct borrownode));
			head->borrow= borrow;//�Ѵ��ļ��ж���ļ�¼,���������һ���ڵ� 
			head->next = NULL;//�ѽڵ�ĺ��ָ����NULL 
			q = head;
		}
		else//�ǵ�һ���ڵ�Ĵ���
		{
			p = (struct borrownode*)malloc(sizeof(struct borrownode));
			p->borrow = borrow;
			p->next = NULL;
			q->next = p; // �����½ڵ㵽��β 
			q = p; //��qָ��ָ���½ڵ�
		}
		fread(&borrow, sizeof(struct borrow), 1, fp);// �������ļ��ж�ȡ��һ����¼ 
	}return head;//���ص�����ı�ͷָ�� 
}
