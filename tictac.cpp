#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;
class tic
{
public:
 string s,s1;// for names
 char c,c1;//for choices
 char g[9];//for desidn array
 void design()// to make layout
 {
  cout<<setw(73)<<"    |"<<"     |\n";
  cout<<setw(70)<<"  "<<g[0]<<" |"<<"  "<<g[1]<<"  |"<<"  "<<g[2]  <<"\n";
  cout<<setw(73)<<"    |"<<"     |\n";
  cout<<setw(84)<<"--------------------\n";
  cout<<setw(73)<<"    |"<<"     |\n";
  cout<<setw(70)<<"  "<<g[3]<<" |"<<"  "<<g[4]<<"  |"<<"  "<<g[5]  <<"\n";
  cout<<setw(73)<<"    |"<<"     |\n";
  cout<<setw(84)<<"--------------------\n";
  cout<<setw(73)<<"    |"<<"     |\n";
  cout<<setw(70)<<"  "<<g[6]<<" |"<<"  "<<g[7]<<"  |"<<"  "<<g[8]  <<"\n";
  cout<<setw(73)<<"    |"<<"     |\n";
 }
 int game(int p)// to take position
 {
  int t;
   cout<<setw(80)<<right<<"ENTER POSITION\n";
 t=getNumber();                         // to take valid position
  if(p==1)
  g[t-1]='X';
  else
   g[t-1]='O';
   design();                       // checking condition
   if((g[0]=='X'&&g[1]=='X'&&g[2]=='X')||(g[0]=='O'&&g[1]=='O'&&g[2]=='O'))
 return 3;
else if((g[3]=='X'&&g[4]=='X'&&g[5]=='X')||(g[3]=='O'&&g[4]=='O'&&g[5]=='O'))
 return 3;
 else if((g[6]=='X'&&g[7]=='X'&&g[8]=='X')||(g[6]=='O'&&g[7]=='O'&&g[8]=='O'))
 return 3;
 else if((g[0]=='X'&&g[4]=='X'&&g[8]=='X')||(g[0]=='O'&&g[4]=='O'&&g[8]=='O'))
 return 3;
 else if((g[2]=='X'&&g[4]=='X'&&g[6]=='X')||(g[2]=='O'&&g[4]=='O'&&g[6]=='O'))
 return 3;
  else if((g[0]=='X'&&g[3]=='X'&&g[6]=='X')||(g[0]=='O'&&g[3]=='O'&&g[6]=='O'))
   return 3;
    else if((g[1]=='X'&&g[4]=='X'&&g[7]=='X')||(g[1]=='O'&&g[4]=='O'&&g[7]=='O'))
   return 3;
     else if((g[0]=='X'&&g[3]=='X'&&g[6]=='X')||(g[0]=='O'&&g[3]=='O'&&g[6]=='O'))
   return 3;
        else if((g[2]=='X'&&g[5]=='X'&&g[8]=='X')||(g[2]=='O'&&g[5]=='O'&&g[8]=='O'))
   return 3;
   else
    return 2;
 }
 int getNumber()                         // to get a valid number
 {
  int num;
  cout<<setw(70)<<" ";
  cin>>num;
  if(g[num-1]=='X'||g[num-1]=='O')
  {
   cout<<setw(80)<<"ALREADY TAKEN\n";
   return getNumber();
  }
  if(num<1||num>9)
  {
    cout<<setw(80)<<"INVALID NUMBER\n";
   getNumber();
  }
  return num;
 }
 void name()                   // to get name of playerws
 {
  g[0]='1';
  g[1]='2';
  g[2]='3';
  g[3]='4';
  g[4]='5';
  g[5]='6';
  g[6]='7';
  g[7]='8';
  g[8]='9';
  cout<<setw(90)<<right<<"ENTER YOUR NAME FIRST PLAYER\n";
  cout<<setw(70)<<" ";
  cin>>s;
  cout<<"\n"<<setw(86)<<"ENTER YOUR CHOICE [X/O]\n";
  cout<<setw(70)<<" ";
  cin>>c;
  if(c!='O'&&c!='X')
  {
   c=invalid();
  }
  cout<<"\n"<<setw(90)<<"ENTER YOUR NAME SECOND PLAYER\n";
  cout<<setw(70)<<" ";
  cin>>s1;
  cout<<"\n"<<setw(86)<<"ENTER YOUR CHOICE [X/O]\n";
    cout<<"\n"<<setw(82)<<"YOU CAN'T OPT FOR "<<c<<"\n";
  cout<<setw(70)<<" ";
  cin>>c1;
if(c1==c)                     // two players cant have same choices
  {
   c1=invalid1();
  }
  if(c1!='O'&& c1!='X')
  {
   c1=invalid();
  }
 }
 char invalid()
 {
     cout<<setw(80)<<"ENTER AGAIN\n";
  char s;
  cout<<setw(70)<<" ";
  cin>>s;
  if(s!='X'&& s!='O')
  {
   cout<<setw(80)<<"WRONG CHOICE\n";
   return invalid();
  }
  return s;
 }
 char invalid1()
 {
  char s;
       cout<<setw(80)<<"ENTER AGAIN\n";
  cout<<setw(70)<<" ";
  cin>>s;
  if(s==c)                                  // if both enterd same choice
  {
   cout<<setw(80)<<"WRONG CHOICE\n";
   return invalid1();
  }
  if(s!='O'&& s!='X')
  {
      cout<<setw(80)<<"WRONG CHOICE\n";
   return invalid1();
  }
  return s;
 }
};
int main()
{
 tic ob;
 ob.name();
 int i,p;
 ob.design();
 for(i=0;i<9;i++)
 {
  system("cls");
  if(i%2==0)
  {
   cout<<setw(80)<<right<<"FIRST PLAYER\n";
   p=ob.game(1);
   if(p==3)
   {
    cout<<setw(80)<<"*********************\n";
    cout<<setw(65)<<ob.s<<" IS A WINNER\n";
    cout<<setw(80)<<"*********************\n";
    break;
   }
   else
    continue;
  }
  if(i%2!=0)
  {
   cout<<setw(80)<<right<<"SECOND PLAYER\n";
   p=ob.game(2);
   if(p==3)
   {
    cout<<setw(80)<<"*********************\n";
    cout<<setw(65)<<ob.s1<<" IS A WINNER\n";
    cout<<setw(80)<<"*********************\n";
    break;
   }
   else
    continue;
  }
 }
 if(p==2)
  cout<<setw(65)<<"NO ONE IS A WINNER\n";
}
