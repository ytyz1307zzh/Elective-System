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
		int number;                                  //课程编号
		char course[10];                           //存储课程名称
		int students;                              //每门课当前剩余名额
		
	};
	struct student
	{
		char id[20];                              //选课学生的学号
		char name[20];                            //选课学生的姓名
		char school[20];                          //选课学生的院系
		char key[20];                             //学生的登录密码
		char select[20];                           //学生所选的课
	};
	int person;
	char password[20];
	int classmates[20];                             //每门课已选人数
	int rookie=0;                                  //有多少学生登录过选课系统
	cout<<"欢迎使用本系统"<<endl;
	cout<<"1.教务"<<endl;
	cout<<"2.学生"<<endl;
	cout<<"3.退出"<<endl;
	memset(classmates,0,sizeof(classmates));
	while(cin>>person)
	{
	if(person==3)
		return 0;
	if(person==1)                                   //教务登录
	  {
		for(;;)
		{
			cout<<"请输入密码"<<endl;
		    cin>>password;
		    int result1=strcmp(password,"jiaowu");     //教务密码为“jiaowu”，判断密码是否正确
			if(result1==0)break;
			else
            {
				cout<<"密码错误"<<endl;
			    int choice1;
			    cout<<"1.重新输入"<<endl;
			    cout<<"2.退出"<<endl;
			    cin>>choice1;
			    if(choice1==2)
					return 0;
			}
		}
		int choice2;
		cout<<"1.添加课程"<<endl;
		cout<<"2.修改课程"<<endl;
		cout<<"3.查看结果"<<endl;
		cout<<"4.返回"<<endl;
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
					cerr<<"无法打开文件"<<endl;
					system("pause");
					return 1;
				}
			    cout<<"请输入添加的课程"<<endl;
			    dean.number=count;
				cin>>dean.course;               //输入课程
				
				cout<<"已添加课程"<<dean.course;
				cout<<"，编号为"<<dean.number<<endl;
				cout<<"输入课程最大人数"<<endl;
				cin>>dean.students;
				
				file<<dean.number<<" "<<setw(10)<<dean.course<<" "<<setw(3)<<dean.students<<" ";
				cin.get();
				file.close();
				cout<<"1.添加课程"<<endl;
				cout<<"2.修改课程"<<endl;
				cout<<"3.查看结果"<<endl;
				cout<<"4.返回"<<endl;
			}
			if(choice2==2)
			{
				struct teacher dean;
				system("cls");
				ifstream infile("course.txt");
				if(!infile)
				{
					cerr<<"无法打开文件"<<endl;
					system("pause");
					return 1;
				}
				int length;
				
					while(infile>>dean.number)
					{
						
						infile>>dean.course>>dean.students;
						
							length=strlen(dean.course);
							cout<<dean.number;
							cout<<left<<setw(4+length)<<dean.course<<dean.students<<endl;         //打印表格，显示当前课程剩余名额
						
					}
				
				infile.close();
				int changenum;
				char temp1[20];
				int temp2;
				cout<<"请输入修改的课程编号"<<endl;
				cin>>changenum;
				cout<<"将其修改为"<<endl;
				cin>>temp1;
				cout<<"新课程的最大人数为"<<endl;
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
				cout<<"1.添加课程"<<endl;
				cout<<"2.修改课程"<<endl;
				cout<<"3.查看结果"<<endl;
				cout<<"4.返回"<<endl;
			}
			
			if(choice2==3)
			{
				struct teacher dean;
				system("cls");
				ifstream infile("course.txt");
				if(!infile)
				{
					cerr<<"无法打开文件"<<endl;
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
							cout<<left<<setw(4+length)<<dean.course<<dean.students<<endl;         //打印表格，显示当前课程剩余名额
					}
				
				infile.close();
				int look;
				cout<<"请输入您想查看的课程编号"<<endl;
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
				cout<<left<<setw(12)<<" "<<"学号";
				cout<<left<<setw(12)<<" "<<"姓名";
				cout<<left<<setw(12)<<" "<<"院系";
				cout<<endl;
				 
				ifstream infile2("students.txt");                //教务查看该门课已选学生名单
				struct student st;
				if(!infile2)
				{
					cerr<<"无法打开文件"<<endl;
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
				cout<<"1.添加课程"<<endl;
				cout<<"2.修改课程"<<endl;
				cout<<"3.查看结果"<<endl;
				cout<<"4.返回"<<endl;
			}
		}
		if(choice2==4)
		{
			cout<<"1.教务"<<endl;
	        cout<<"2.学生"<<endl;
	        cout<<"3.退出"<<endl;
		}
	   }
	  
	if(person==2)
	 {
		 struct student st;
		 
			 for(int j=0;j<20;j++)
				 st.select[j]='n';
		 char logid[20];                             //输入学号登陆
		 int check;
		 int character;
		 cout<<"请输入学号"<<endl;
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
				check=strcmp(st.id,logid);         //查询该学生是否以前登陆过
				 if(check==0)
				 break;          
			 }
		 }
		 if(check==0)                          //以前登陆过
		 { 
			 for(;;)
		    {
			  cout<<"请输入登录密码"<<endl;
		      cin>>password;
		      int result2=strcmp(password,st.key);   
			  if(result2==0)break;
			  else
                {
			    	cout<<"密码错误"<<endl;
			        int choice3;
			        cout<<"1.重新输入"<<endl;
			        cout<<"2.退出"<<endl;
			        cin>>choice3;
			        if(choice3==2)
					return 0;
			    }
		     }
		 } 
		 infile.close();
		 if(check!=0)                          //第一次登陆
		 {
			 ofstream outfile("students.txt",ios::app);
			 character++;
			 strcpy(st.id,logid);
			 cout<<"请设置登录密码,";
			 cout<<"密码应为小于20位的字母和数字"<<endl;
			 cin>>st.key;
			 cout<<"请输入你的姓名"<<endl;
			 cin>>st.name;
			 cout<<"请输入你的院系"<<endl;
			 cin>>st.school;
			  for(int j=0;j<19;j++)
				 st.select[j]='n';
			  st.select[19]=0;
			 outfile<<setw(10)<<st.id<<" "<<setw(10)<<st.key<<" "<<setw(10)<<st.name<<" "<<setw(10)<<st.school<<" "<<setw(20)<<st.select<<" ";
			 outfile.close();
		 }
		int choice4;
		cout<<"1.选课"<<endl;
		cout<<"2.退课"<<endl;
		cout<<"3.查看结果"<<endl;
		cout<<"4.返回"<<endl;
		while(cin>>choice4 && choice4!=4)
		{
				struct teacher dean;
				system("cls");
				ifstream infile("course.txt");
				if(!infile)
				{
					cerr<<"无法打开文件"<<endl;
					system("pause");
					return 1;
				}
				int length;
					while(infile>>dean.number)
					{
						
						infile>>dean.course>>dean.students;
						length=strlen(dean.course);
						cout<<dean.number;
						cout<<left<<setw(4+length)<<dean.course<<dean.students<<endl;         //打印表格，显示当前课程剩余名额	
					}
				infile.close();
			if(choice4==1)
			{
				fstream file2("students.txt",ios::in|ios::out);
				fstream file1("course.txt",ios::in|ios::out);
				if(!file1||!file2)
				{
					cerr<<"无法打开文件"<<endl;
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
				cout<<"请输入课程编号进行选课"<<endl;
				cin>>choose;
				st.select[choose]='y';
				classmates[choose]++;                 //该门课已选学生数+1
				file1.seekp(0);
				for(;;)
				{
					file1>>dean.number>>dean.course>>dean.students;
					
					if(dean.number==choose)
					{dean.students--;
					file1.seekp((choose-1)*17);
					file1<<dean.number<<" "<<setw(10)<<dean.course<<" "<<setw(3)<<dean.students<<" ";
						break;}						 //该门课剩余名额数-1
				}
				file1.close();
				file2.seekp((character-1)*65);
				file2<<setw(10)<<st.id<<" "<<setw(10)<<st.key<<" "<<setw(10)<<st.name<<" "<<setw(10)<<st.school<<" "<<setw(20)<<st.select<<" ";
				file2.close();
				cout<<"选课成功"<<endl;
				
				ifstream infile("course.txt");
				if(!infile)
				{
					cerr<<"无法打开文件"<<endl;
					system("pause");
					return 1;
				}
				int length;
				
					while(infile>>dean.number)
					{
						infile>>dean.course>>dean.students;
						length=strlen(dean.course);
							cout<<dean.number;
							cout<<left<<setw(4+length)<<dean.course<<dean.students<<endl;         //打印表格，显示当前课程剩余名额
					}
				
				infile.close();
				cout<<"1.选课"<<endl;
				cout<<"2.退课"<<endl;
				cout<<"3.查看结果"<<endl;
				cout<<"4.返回"<<endl;
			}
			if(choice4==2)
			{
				fstream file2("students.txt",ios::in|ios::out);
				fstream file1("course.txt",ios::in|ios::out);
				if(!file1||!file2)
				{
					cerr<<"无法打开文件"<<endl;
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
				cout<<"请输入课程编号进行退课"<<endl;
				cin>>choose;
				st.select[choose]='n';
				classmates[choose]--;                 //该门课已选学生数-1
				file1.seekp(0);
				for(;;)
				{
					file1>>dean.number>>dean.course>>dean.students;
					if(dean.number==choose)
					{dean.students++;
					file1.seekp((choose-1)*17);
					file1<<dean.number<<" "<<setw(10)<<dean.course<<" "<<setw(3)<<dean.students<<" ";
						break;}						 //该门课剩余名额数+1
				}
				file1.close();
				file2.seekp((character-1)*65);
				file2<<setw(10)<<st.id<<" "<<setw(10)<<st.key<<" "<<setw(10)<<st.name<<" "<<setw(10)<<st.school<<" "<<setw(20)<<st.select<<" ";
				file2.close();
				cout<<"退课成功"<<endl;
				
				ifstream infile("course.txt");
				if(!infile)
				{
					cerr<<"无法打开文件"<<endl;
					system("pause");
					return 1;
				}
				int length;
				
					while(infile>>dean.number)
					{
						
						infile>>dean.course>>dean.students;
							length=strlen(dean.course);
							cout<<dean.number;
							cout<<left<<setw(4+length)<<dean.course<<dean.students<<endl;         //打印表格，显示当前课程剩余名额
						
					}
				
				infile.close();
				cout<<"1.选课"<<endl;
				cout<<"2.退课"<<endl;
				cout<<"3.查看结果"<<endl;
				cout<<"4.返回"<<endl;
			}
			if(choice4==3)
			{
				cout<<setw(8)<<" "<<"学号";
				cout<<setw(8)<<" "<<"姓名";
				cout<<setw(8)<<" "<<"院系";
				struct teacher dean;
				int total;
				ifstream infile1("course.txt");
				if(!infile1)
				{
					cerr<<"无法打开文件"<<endl;
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
					cerr<<"无法打开文件"<<endl;
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
				cout<<"1.选课"<<endl;
				cout<<"2.退课"<<endl;
				cout<<"3.查看结果"<<endl;
				cout<<"4.返回"<<endl;
			}
		}
		if(choice4==4)
		  {
				cout<<"1.教务"<<endl;
				cout<<"2.学生"<<endl;
				cout<<"3.退出"<<endl;
		  }
	  }
	 }
	
	system("pause");
	return 0;
}