#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<cstring>
using namespace std;
int main()
 {
	struct teacher
	{
		int number;                                  //�γ̱��
		char course[10];                           //�洢�γ�����
		int students;                              //ÿ�ſε�ǰʣ������
		
	};
	struct student
	{
		char id[20];                              //ѡ��ѧ����ѧ��
		char name[20];                            //ѡ��ѧ��������
		char school[20];                          //ѡ��ѧ����Ժϵ
		char key[20];                             //ѧ���ĵ�¼����
		char select[20];                           //ѧ����ѡ�Ŀ�
	};
	int person;
	char password[20];
	int classmates[20];                             //ÿ�ſ���ѡ����
	int rookie=0;                                  //�ж���ѧ����¼��ѡ��ϵͳ
	cout<<"��ӭʹ�ñ�ϵͳ"<<endl;
	cout<<"1.����"<<endl;
	cout<<"2.ѧ��"<<endl;
	cout<<"3.�˳�"<<endl;
	memset(classmates,0,sizeof(classmates));
	while(cin>>person)
	{
	if(person==3)
		return 0;
	if(person==1)                                   //�����¼
	  {
		for(;;)
		{
			cout<<"����������"<<endl;
		    cin>>password;
		    int result1=strcmp(password,"jiaowu");     //��������Ϊ��jiaowu�����ж������Ƿ���ȷ
			if(result1==0)break;
			else
            {
				cout<<"�������"<<endl;
			    int choice1;
			    cout<<"1.��������"<<endl;
			    cout<<"2.�˳�"<<endl;
			    cin>>choice1;
			    if(choice1==2)
					return 0;
			}
		}
		int choice2;
		cout<<"1.��ӿγ�"<<endl;
		cout<<"2.�޸Ŀγ�"<<endl;
		cout<<"3.�鿴���"<<endl;
		cout<<"4.����"<<endl;
		while(cin>>choice2 && choice2!=4)
		{
		    if(choice2==1)
		    {
				int count=0;
				struct teacher dean;
				system("cls");
				ifstream infile("course.txt");
				if(!infile)
					count=1;
				else
				{
					infile.seekg(0);
					while(!infile.eof())
					{
						count++;
						infile>>dean.number>>dean.course>>dean.students;
						
					}
					infile.close();
				}
				ofstream file("course.txt",ios::app);
				if(!file)
				{
					cerr<<"�޷����ļ�"<<endl;
					system("pause");
					return 1;
				}
			    cout<<"��������ӵĿγ�"<<endl;
			    dean.number=count;
				cin>>dean.course;               //����γ�
				
				cout<<"����ӿγ�"<<dean.course;
				cout<<"�����Ϊ"<<dean.number<<endl;
				cout<<"����γ��������"<<endl;
				cin>>dean.students;
				
				file<<dean.number<<" "<<setw(10)<<dean.course<<" "<<setw(3)<<dean.students<<" ";
				cin.get();
				file.close();
				cout<<"1.��ӿγ�"<<endl;
				cout<<"2.�޸Ŀγ�"<<endl;
				cout<<"3.�鿴���"<<endl;
				cout<<"4.����"<<endl;
			}
			if(choice2==2)
			{
				struct teacher dean;
				system("cls");
				ifstream infile("course.txt");
				if(!infile)
				{
					cerr<<"�޷����ļ�"<<endl;
					system("pause");
					return 1;
				}
				int length;
				
					while(infile>>dean.number)
					{
						
						infile>>dean.course>>dean.students;
						
							length=strlen(dean.course);
							cout<<dean.number;
							cout<<left<<setw(4+length)<<dean.course<<dean.students<<endl;         //��ӡ�����ʾ��ǰ�γ�ʣ������
						
					}
				
				infile.close();
				int changenum;
				char temp1[20];
				int temp2;
				cout<<"�������޸ĵĿγ̱��"<<endl;
				cin>>changenum;
				cout<<"�����޸�Ϊ"<<endl;
				cin>>temp1;
				cout<<"�¿γ̵��������Ϊ"<<endl;
				cin>>temp2;
				fstream file("course.txt",ios::in|ios::out);
				file.seekp(0);
				for(int i=1;;i++)
				{
					file>>dean.number>>dean.course>>dean.students;
					
					if(dean.number==changenum)
					{
						dean.number=changenum;
						strcpy(dean.course,temp1);
						dean.students=temp2;
						file.seekp((changenum-1)*17);
						file<<dean.number<<" "<<setw(10)<<dean.course<<" "<<setw(3)<<dean.students<<" ";
						break;
					}
				}
				file.close();
				cout<<"1.��ӿγ�"<<endl;
				cout<<"2.�޸Ŀγ�"<<endl;
				cout<<"3.�鿴���"<<endl;
				cout<<"4.����"<<endl;
			}
			
			if(choice2==3)
			{
				struct teacher dean;
				system("cls");
				ifstream infile("course.txt");
				if(!infile)
				{
					cerr<<"�޷����ļ�"<<endl;
					system("pause");
					return 1;
				}
				infile.seekg(0);
				int length;
			
					while(infile>>dean.number)
					{
						infile>>dean.course>>dean.students;
						
							length=strlen(dean.course);
							cout<<dean.number;
							cout<<left<<setw(4+length)<<dean.course<<dean.students<<endl;         //��ӡ�����ʾ��ǰ�γ�ʣ������
					}
				
				infile.close();
				int look;
				cout<<"����������鿴�Ŀγ̱��"<<endl;
				cin>>look;
				fstream file("course.txt",ios::in|ios::out);
				file.seekp(0);
				
				while(file>>dean.number)
				{
					file>>dean.course>>dean.students;
					if(dean.number==look)
						break;	
				}
				cout<<right<<setw(20)<<dean.course;
				cout<<endl;
				cout<<left<<setw(12)<<" "<<"ѧ��";
				cout<<left<<setw(12)<<" "<<"����";
				cout<<left<<setw(12)<<" "<<"Ժϵ";
				cout<<endl;
				 
				ifstream infile2("students.txt");                //����鿴���ſ���ѡѧ������
				struct student st;
				if(!infile2)
				{
					cerr<<"�޷����ļ�"<<endl;
					system("pause");
					return 1;
				}
				while(infile2>>st.id)
				{
					infile2>>st.key>>st.name>>st.school>>st.select;
					if(st.select[look]=='y')
					{
						cout<<right<<setw(16)<<st.id;
						cout<<right<<setw(16)<<st.name;
						cout<<right<<setw(16)<<st.school;
					}
					cout<<endl;
				}
				infile2.close();
				file.close();
				cout<<endl;
				cout<<"1.��ӿγ�"<<endl;
				cout<<"2.�޸Ŀγ�"<<endl;
				cout<<"3.�鿴���"<<endl;
				cout<<"4.����"<<endl;
			}
		}
		if(choice2==4)
		{
			cout<<"1.����"<<endl;
	        cout<<"2.ѧ��"<<endl;
	        cout<<"3.�˳�"<<endl;
		}
	   }
	  
	if(person==2)
	 {
		 struct student st;
		 
			 for(int j=0;j<20;j++)
				 st.select[j]='n';
		 char logid[20];                             //����ѧ�ŵ�½
		 int check;
		 int character;
		 cout<<"������ѧ��"<<endl;
		 cin>>logid;
		 ifstream infile("students.txt");
		 if(!infile)
			 character=0;
		 else
		 {
			 character=0;
			while(infile>>st.id)
			{
				character++;
				infile>>st.key>>st.name>>st.school>>st.select;
				check=strcmp(st.id,logid);         //��ѯ��ѧ���Ƿ���ǰ��½��
				 if(check==0)
				 break;          
			 }
		 }
		 if(check==0)                          //��ǰ��½��
		 { 
			 for(;;)
		    {
			  cout<<"�������¼����"<<endl;
		      cin>>password;
		      int result2=strcmp(password,st.key);   
			  if(result2==0)break;
			  else
                {
			    	cout<<"�������"<<endl;
			        int choice3;
			        cout<<"1.��������"<<endl;
			        cout<<"2.�˳�"<<endl;
			        cin>>choice3;
			        if(choice3==2)
					return 0;
			    }
		     }
		 } 
		 infile.close();
		 if(check!=0)                          //��һ�ε�½
		 {
			 ofstream outfile("students.txt",ios::app);
			 character++;
			 strcpy(st.id,logid);
			 cout<<"�����õ�¼����,";
			 cout<<"����ӦΪС��20λ����ĸ������"<<endl;
			 cin>>st.key;
			 cout<<"�������������"<<endl;
			 cin>>st.name;
			 cout<<"���������Ժϵ"<<endl;
			 cin>>st.school;
			  for(int j=0;j<19;j++)
				 st.select[j]='n';
			  st.select[19]=0;
			 outfile<<setw(10)<<st.id<<" "<<setw(10)<<st.key<<" "<<setw(10)<<st.name<<" "<<setw(10)<<st.school<<" "<<setw(20)<<st.select<<" ";
			 outfile.close();
		 }
		int choice4;
		cout<<"1.ѡ��"<<endl;
		cout<<"2.�˿�"<<endl;
		cout<<"3.�鿴���"<<endl;
		cout<<"4.����"<<endl;
		while(cin>>choice4 && choice4!=4)
		{
				struct teacher dean;
				system("cls");
				ifstream infile("course.txt");
				if(!infile)
				{
					cerr<<"�޷����ļ�"<<endl;
					system("pause");
					return 1;
				}
				int length;
					while(infile>>dean.number)
					{
						
						infile>>dean.course>>dean.students;
						length=strlen(dean.course);
						cout<<dean.number;
						cout<<left<<setw(4+length)<<dean.course<<dean.students<<endl;         //��ӡ�����ʾ��ǰ�γ�ʣ������	
					}
				infile.close();
			if(choice4==1)
			{
				fstream file2("students.txt",ios::in|ios::out);
				fstream file1("course.txt",ios::in|ios::out);
				if(!file1||!file2)
				{
					cerr<<"�޷����ļ�"<<endl;
					system("pause");
					return 1;
				}
				file2.seekp(0);
				while(file2>>st.id)
				{
					file2>>st.key>>st.name>>st.school>>st.select;
					int check=strcmp(st.id,logid); 
					if(check==0)break;
				}
				int choose;
				struct teacher dean;
				cout<<"������γ̱�Ž���ѡ��"<<endl;
				cin>>choose;
				st.select[choose]='y';
				classmates[choose]++;                 //���ſ���ѡѧ����+1
				file1.seekp(0);
				for(;;)
				{
					file1>>dean.number>>dean.course>>dean.students;
					
					if(dean.number==choose)
					{dean.students--;
					file1.seekp((choose-1)*17);
					file1<<dean.number<<" "<<setw(10)<<dean.course<<" "<<setw(3)<<dean.students<<" ";
						break;}						 //���ſ�ʣ��������-1
				}
				file1.close();
				file2.seekp((character-1)*65);
				file2<<setw(10)<<st.id<<" "<<setw(10)<<st.key<<" "<<setw(10)<<st.name<<" "<<setw(10)<<st.school<<" "<<setw(20)<<st.select<<" ";
				file2.close();
				cout<<"ѡ�γɹ�"<<endl;
				
				ifstream infile("course.txt");
				if(!infile)
				{
					cerr<<"�޷����ļ�"<<endl;
					system("pause");
					return 1;
				}
				int length;
				
					while(infile>>dean.number)
					{
						infile>>dean.course>>dean.students;
						length=strlen(dean.course);
							cout<<dean.number;
							cout<<left<<setw(4+length)<<dean.course<<dean.students<<endl;         //��ӡ�����ʾ��ǰ�γ�ʣ������
					}
				
				infile.close();
				cout<<"1.ѡ��"<<endl;
				cout<<"2.�˿�"<<endl;
				cout<<"3.�鿴���"<<endl;
				cout<<"4.����"<<endl;
			}
			if(choice4==2)
			{
				fstream file2("students.txt",ios::in|ios::out);
				fstream file1("course.txt",ios::in|ios::out);
				if(!file1||!file2)
				{
					cerr<<"�޷����ļ�"<<endl;
					system("pause");
					return 1;
				}
				file2.seekp(0);
				while(file2>>st.id)
				{
					file2>>st.key>>st.name>>st.school>>st.select;
					int check=strcmp(st.id,logid); 
					if(check==0)break;
				}
				int choose;
				struct teacher dean;
				cout<<"������γ̱�Ž����˿�"<<endl;
				cin>>choose;
				st.select[choose]='n';
				classmates[choose]--;                 //���ſ���ѡѧ����-1
				file1.seekp(0);
				for(;;)
				{
					file1>>dean.number>>dean.course>>dean.students;
					if(dean.number==choose)
					{dean.students++;
					file1.seekp((choose-1)*17);
					file1<<dean.number<<" "<<setw(10)<<dean.course<<" "<<setw(3)<<dean.students<<" ";
						break;}						 //���ſ�ʣ��������+1
				}
				file1.close();
				file2.seekp((character-1)*65);
				file2<<setw(10)<<st.id<<" "<<setw(10)<<st.key<<" "<<setw(10)<<st.name<<" "<<setw(10)<<st.school<<" "<<setw(20)<<st.select<<" ";
				file2.close();
				cout<<"�˿γɹ�"<<endl;
				
				ifstream infile("course.txt");
				if(!infile)
				{
					cerr<<"�޷����ļ�"<<endl;
					system("pause");
					return 1;
				}
				int length;
				
					while(infile>>dean.number)
					{
						
						infile>>dean.course>>dean.students;
							length=strlen(dean.course);
							cout<<dean.number;
							cout<<left<<setw(4+length)<<dean.course<<dean.students<<endl;         //��ӡ�����ʾ��ǰ�γ�ʣ������
						
					}
				
				infile.close();
				cout<<"1.ѡ��"<<endl;
				cout<<"2.�˿�"<<endl;
				cout<<"3.�鿴���"<<endl;
				cout<<"4.����"<<endl;
			}
			if(choice4==3)
			{
				cout<<setw(8)<<" "<<"ѧ��";
				cout<<setw(8)<<" "<<"����";
				cout<<setw(8)<<" "<<"Ժϵ";
				struct teacher dean;
				int total;
				ifstream infile1("course.txt");
				if(!infile1)
				{
					cerr<<"�޷����ļ�"<<endl;
					system("pause");
					return 1;
				}
				
					while(infile1>>dean.number)
					{
						infile1>>dean.course>>dean.students;
						cout<<right<<setw(3)<<dean.number;
						cout<<right<<setw(9)<<dean.course;   
					}
					total=dean.number;
				
				infile1.close();
				cout<<endl;
				ifstream infile2("students.txt");
				if(!infile2)
				{
					cerr<<"�޷����ļ�"<<endl;
					system("pause");
					return 1;
				}
				while(infile2>>st.id)
				{
					infile2>>st.key>>st.name>>st.school>>st.select;
					int check=strcmp(st.id,logid); 
					if(check==0)break;
				}
				cout<<right<<setw(12)<<st.id;
				cout<<right<<setw(12)<<st.name;
				cout<<right<<setw(12)<<st.school;
				for(int i=1;i<=total;i++)
				{
					cout<<setw(12)<<st.select[i];
				}
				infile2.close();
				cout<<endl;
				cout<<"1.ѡ��"<<endl;
				cout<<"2.�˿�"<<endl;
				cout<<"3.�鿴���"<<endl;
				cout<<"4.����"<<endl;
			}
		}
		if(choice4==4)
		  {
				cout<<"1.����"<<endl;
				cout<<"2.ѧ��"<<endl;
				cout<<"3.�˳�"<<endl;
		  }
	  }
	 }
	
	system("pause");
	return 0;
}