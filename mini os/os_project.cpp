#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include<string.h>
#include <sys/stat.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
int flag=0;
//used in cd
char *edit(char t[],int l,char ans[])
{
if(l<(strlen(t)-1))
	{
	edit(t,l+1,ans);
	}

if(flag==1)
	{
	ans[l]=t[l];
	}
if(flag==0)
	{
	if(t[l]=='/')
	{
	flag=1;
	ans[l]='\0';
	}
	}
}
int main(int argc, char** argv)
{
//cout<<"***************************WELCOME TO OUR TERMINAL****************************************"<<endl;
 cout<<"\n\n\n\n******************"
        "************************";
    cout<<"\n\n\t-WELCOME TO OUR SHELL-"<<endl;
    cout<<"\tMADE BY:"<<endl;
cout<<"\n";
cout<<"               "<<"DIVYANSH JAIN"<<"                 "<<endl;
cout<<"               "<<"PRANAV GOYAL "<<"                 "<<endl;
cout<<"               "<<"ADITYA PODDAR"<<"                 "<<endl;
cout<<"               "<<"DANISH KHAN"  <<"                 "<<endl;
    cout<<"\n\n\n\n*******************"
        "***********************";
cout<<"\n";
cout<<"\n";
cout<<"HERE WE USE THESE BASIC COMMANDS"<<endl;
cout<<"To close the terminal"<<"                               "<<"exit"<<endl;
cout<<"To clear all the terminal"<<"                           "<<"clear"<<endl;
cout<<"To append the  file"<<"                                 "<<"wp"<<endl;
cout<<"To read text from the file"<<"                          "<<"echo"<<endl;
cout<<"To create a file"<<"                                    "<<"touch"<<endl;
cout<<"To reaname the file"<<"                                 "<<"rename"<<endl;
cout<<"To copy the file"<<"                                    "<<"cp"<<endl;
cout<<"To remove the file"<<"                                  "<<"remove"<<endl;
cout<<"To list the file"<<"                                    "<<"ls"<<endl;
cout<<"To change the directory"<<"                             "<<"cd"<<endl;
cout<<"To check the history of command used"<<"                "<<"history"<<endl;
cout<<"\n";
cout<<"\n";
    //setlinebuf(stdin);
    char my_cwd[1024]; //for data type command prompt
    getcwd(my_cwd, 1024);
char command[1024];
vector<vector<string> > history;


//***********************************exit*****************************************
while(strcmp(command,"exit")!=0)
	{
	cin.sync();
	printf("%s -> ",my_cwd);
	scanf("%s",command);
vector<string> temp;
temp.push_back((string)command);


//***********************************************wp********************************
if(strcmp(command,"wp")==0)
{
char file[1024];
//cin>>file;
vector<string> data;//define data string
string data2="hh";
char p[]={'"','\0'};
vector<string> a;//define a string
char c[1024];
cin>>c;//here  we take input from the user
if(strcmp(c,p)==0)
{
while(1)
{
cin>>c;
if(strcmp(c,p)==0)
break;
a.push_back((string)c);
}
cin>>file;
char loc2[1024];
strcpy(loc2,my_cwd);
strcpy(strcpy(loc2,"/"),file);
FILE *fp;
fp=fopen(loc2,"a");
for(vector<string>::iterator it=a.begin();it!=a.end();it++)
{
string tt=(*it);
int count=0;
char pp[1024];
for(int i=0;i<tt.size();i++)
{
pp[count++]=tt[i];
}
pp[count]='\0';
fprintf(fp,"%s ",pp);
}
fclose(fp);
}
else
{
cout<<"error in command\n";
}
}



//***********************************************echo**************************************************
if(strcmp(command,"echo")==0)
{
char file[1024];
cin>>file;
char loc2[1024];
strcpy(loc2,my_cwd);
strcpy(strcpy(loc2,"/"),file);
FILE *fp;
fp=fopen(file,"r");
if(fp!=NULL)
{
char c=fgetc(fp);
while(c!=EOF)
{
cout<<c;
c=fgetc(fp);
}
}
else
{
cout<<"File not exists\n";
}
}


//*******************************************touch****************************
if(strcmp(command,"touch")==0)
{
char file[1024];
cin>>file;
char loc2[1024];
strcpy(loc2,my_cwd);
strcpy(strcpy(loc2,"/"),file);
if(fopen(loc2,"r")!=NULL)
{
cout<<"File already Exists\n";
}
else
{
if(fopen(loc2,"w")!=NULL)
{
cout<<"File created"<<endl;
}
else
{
cout<<"Error occured in file creation"<<endl;
}
}
}



//************************************rename***********************************
if(strcmp(command,"rename")==0)
{
char file[1024],file2[1024];
cin>>file>>file2;
char loc[1024],loc2[1024];
strcpy(loc2,my_cwd);
strcpy(loc,my_cwd);
strcpy(strcpy(loc2,"/"),file2);
if(fopen(file2,"r")!=NULL)
{
cout<<"file already exists\n";
}
else{
if(rename(strcpy(strcpy(loc,"/"),file),loc2)==0){
cout<<"File ranamed\n";
}
else
{
cout<<"error occured\n";
}
}
}



//*********************************history************************
if(strcmp(command,"history")==0)
{
for(vector<vector<string> >::iterator it=history.begin();it!=history.end();it++)
{
for(vector<string>::iterator it1=it->begin();it1!=it->end();it1++)
{
cout<<(*it1)<<" ";
}
cout<<endl;
}
}



//**********************************cp****************************
if(strcmp(command,"cp")==0)
    {
    FILE *fp,*fp1;
    char source[1024],dest[1024];
    scanf("%s%s",source,dest);
    char loc[1024],loc2[1024];
strcpy(loc2,my_cwd);
strcpy(loc,my_cwd);
temp.push_back((string)source);
temp.push_back((string)dest);
    fp=fopen(strcpy(strcpy(loc,"/"),source),"r");
    fp1=fopen(strcpy(strcpy(loc2,"/"),dest),"w");
    char *buffer;
    long long numbytes;
    fseek(fp, 0L, SEEK_END);
    numbytes = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    buffer = (char*)calloc(numbytes, sizeof(char));
    fread(buffer, sizeof(char), numbytes, fp);
    fwrite(buffer, sizeof(char), numbytes, fp1);
    printf("File Copied\n");
	fclose(fp);
	fclose(fp1);
    }



//*************************remove*********************************
	if(strcmp(command,"remove")==0)
	{
	char temp2[1024];
	scanf("%s",temp2);
temp.push_back((string)temp2);
	if(remove(temp2)==0)
	{
	printf("File %s has been deleted",temp2);
	printf("\n");
	}
	else{

	printf("File not Found");
	printf("\n");
	}
	}

//**********************************ls****************************

	if(strcmp(command,"ls")==0)
	{
	 DIR           *d;
    struct dirent *dir;
    d = opendir(my_cwd);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
            {
            printf("%s\t", dir->d_name);
            }
    printf("\n");
    closedir(d);
  }
	}


//*****************************************cd********************************
	if(strcmp(command,"cd")==0)
		{
		char temp2[1024];
		scanf("%s",temp2);
temp.push_back((string)temp2);
		if(strcmp(temp2,"..")==0)
			{
			flag=0;
			char ans[1024];
			int i=0;
			int count=0;

			for(i=0;i<strlen(my_cwd);i++)
			{
			if(my_cwd[i]=='/')
			{
			count++;
			}
			}
			if(count>1){

			edit(my_cwd,0,ans);
			strcpy(my_cwd,ans);
			}
			history.push_back(temp);
			continue;
			}
		struct stat sb;
		char temp3[1024];
		strcpy(temp3,my_cwd);
		strcat(temp3,"/");
		strcat(temp3,temp2);
		const char *t=temp3;
		  if (stat(t, &sb) == 0 && S_ISDIR(sb.st_mode))
 		   {
       			strcpy(my_cwd,temp3);
		    }
    		else
    		{
			printf("Directory Not Exists\n");
    		}
	}


//***********************************clear**********************************
	if(strcmp(command,"clear")==0)//clear vala kam kr rha h
	{
	system("clear");
	}
         history.push_back(temp);
}
return 0;
}
