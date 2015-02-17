#include<stdio.h>
#include<stdlib.h>                                              //For exit()  function
#include<graphics.h>
#include<conio.h>                                               //For getch() function
#include<dos.h>                                                 //For delay() function
#include<math.h>                                                //For sin() and cos() function  
#include<time.h>                                                //For clock() function
//--------------------------------------------
#define RADIUS 18.0
#define RADIUS_M 50
#define TIME 50
#define RADIAN 0.0174532
//---------------------------------------------
void func_1(void);
void draw_car(int);
void move_car(void);
void fuel_meter(int,int);
void menu(void);
void func_2(void);
//---------------------------------------------
struct wheel
{
int centre_x;
int centre_y;
}w;
//----------------------------------------------
int main()
{
int choice;
menu();
scanf("%d",&choice);
switch(choice)
{
case 0 :
exit(1);
break;
case 1 :
func_1();
break;
case 2 :
func_2();
break;
default :
printf("Wrong Choice........exiting!!!");
exit(1);
}
return (0);
}
//----------------------------------------------
void func_1(void)
{
int i=0;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setcolor(CYAN);
settextstyle(7,HORIZ_DIR,3);
outtextxy(70,240,"Press any key to view the moving car ");
getch();
closegraph();
draw_car(i);
move_car();
}
//----------------------------------------------
void draw_car(int j)
{
FILE *fp;
char ch;
clock_t start=0,stop=0;
int d=0,c_x=150,c_y=150;
float time=0.0;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
w.centre_x=100;
w.centre_y=450;
int x[4],y[4];
double i_1=5.0,i_2=5.0,theta_1=0.0,theta_2=0.0;
int m,n,c,k=0;

fp=fopen("SPEED.TXT","r");

while(!kbhit())
{
//**************                                        controlling speed through file.....  
 ch=fgetc(fp);
 
 if(ch==EOF||ch==NULL)
 d=0;
  
 else if(ch=='r')
 d=d+20;
 
 else if(ch=='a')
  if(d>=-30)
   d=d-20;
 //**************
do
{
if(j==10)
start=clock();

cleardevice();

if(j==0)                                                                       //draw wheeles only when j is 0 i.e only when drawing the car
{
//WHEEL 1
setcolor(RED);
circle(w.centre_x,w.centre_y,RADIUS);
setcolor(BLUE);
line(w.centre_x,w.centre_y,w.centre_x,w.centre_y-RADIUS);
setcolor(GREEN);
line(w.centre_x,w.centre_y,w.centre_x+RADIUS,w.centre_y);
setcolor(CYAN);
line(w.centre_x,w.centre_y,w.centre_x,w.centre_y+RADIUS);
setcolor(RED);
line(w.centre_x,w.centre_y,w.centre_x-RADIUS,w.centre_y);
//WHEEL 2
setcolor(RED);
circle(w.centre_x+90,w.centre_y,RADIUS);
setcolor(BLUE);
line(w.centre_x+90,w.centre_y,w.centre_x+90,w.centre_y-RADIUS);
setcolor(GREEN);
line(w.centre_x+90,w.centre_y,w.centre_x+90+RADIUS,w.centre_y);
setcolor(CYAN);
line(w.centre_x+90,w.centre_y,w.centre_x+90,w.centre_y+RADIUS);
setcolor(RED);
line(w.centre_x+90,w.centre_y,w.centre_x+90-RADIUS,w.centre_y);
fuel_meter(150,150);
}
//BODY
setcolor(BLUE);
arc(w.centre_x+j,w.centre_y,0,180,(RADIUS+5));
arc(w.centre_x+90+j,w.centre_y,0,180,(RADIUS+5));
line(w.centre_x+(RADIUS+5)+j,w.centre_y,w.centre_x+90-(RADIUS+5)+j,w.centre_y);
line(w.centre_x-(RADIUS+5)+j,w.centre_y,w.centre_x-40-(RADIUS+5)+j,w.centre_y);
line(w.centre_x+90+(RADIUS+5)+j,w.centre_y,w.centre_x+90+40+(RADIUS+5)+j,w.centre_y);
arc(w.centre_x-(RADIUS+5)+j,w.centre_y,90,180,40);
arc(w.centre_x+90+(RADIUS+5)+j,w.centre_y,0,90,40);
line(w.centre_x-(RADIUS+5)+j,w.centre_y-40,w.centre_x-(RADIUS+5)+28+j,w.centre_y-40);
line(w.centre_x+90+(RADIUS+5)+j,w.centre_y-40,w.centre_x+90+(RADIUS+5)-28+j,w.centre_y-40);
arc(135+j,w.centre_y-40,90,180,30);
arc(155+j,w.centre_y-40,0,90,30);
line(135+j,w.centre_y-70,155+j,w.centre_y-70);
//WINDOWS
setcolor(CYAN);
arc(130+j,w.centre_y-40,90,180,20);
arc(160+j,w.centre_y-40,0,90,20);
line(130+j,w.centre_y-40,110+j,w.centre_y-40);
line(160+j,w.centre_y-40,180+j,w.centre_y-40);
line(130+j,w.centre_y-60,130+j,w.centre_y-40);
line(160+j,w.centre_y-60,160+j,w.centre_y-40);
if(j>=10)                                                //rotation of wheels
{
//**************
if(ch==EOF||ch==NULL)
 {
  setcolor(YELLOW);
  settextstyle(7,HORIZ_DIR,1);
  outtextxy(400,150,"Constant Speed");
 }
 else if(ch=='r')
 {
 setcolor(RED);
 settextstyle(7,HORIZ_DIR,1);
 outtextxy(400,150,"Retarding");
 }
 else if(ch=='a')
 {
  if(d>=-30)
  {
  setcolor(GREEN);
  settextstyle(7,HORIZ_DIR,1);
  outtextxy(400,150,"Accelerating");
  }
  else
  {
  setcolor(YELLOW);
  settextstyle(7,HORIZ_DIR,1);
  outtextxy(400,150,"Maximum Speed Reached");
  }
 }
//**************
if(time<30)
fuel_meter(c_x,c_y);
else if(time>30&&time<60)
fuel_meter(c_x-50,c_y-50);
else if(time>60&&time<90)
fuel_meter(c_x-100,c_y);
else if(time>90&&time<110)
{
 setcolor(RED);
 settextstyle(7,HORIZ_DIR,1);
 outtextxy(200,300,"FUEL TANK ON RESERVE");
 fuel_meter(c_x-100,c_y);
}
else if(time>110)
{
 cleardevice();
 setcolor(RED);
 settextstyle(7,HORIZ_DIR,1);
 outtextxy(200,250,"PRESS ANY KEY TO REFULE");
 getch();
 fuel_meter(c_x,c_y);
 time=0;
}
c=1;
setcolor(RED);
circle(w.centre_x+j,w.centre_y,RADIUS);
circle(w.centre_x+90+j,w.centre_y,RADIUS);
for(m=0;m<4;m++)
 {
  theta_1=i_1*RADIAN;
  x[m]=w.centre_x+j + RADIUS*cos(theta_1);
  y[m]=w.centre_y + RADIUS*sin(theta_1);
  i_1=i_1+90.0;
  setcolor(c);
  line(w.centre_x+j,w.centre_y,x[m],y[m]);
  c++;
 }
 c=1;
 for(n=0;n<4;n++)
 {
  theta_2=i_2*RADIAN;
  x[n]=w.centre_x+j+90 + RADIUS*cos(theta_2);
  y[n]=w.centre_y + RADIUS*sin(theta_2);
  i_2=i_2+90.0;
  setcolor(c);
  line(w.centre_x+j+90,w.centre_y,x[n],y[n]);
  c++;
 }
 setcolor(YELLOW);                                                                       //Head light
 circle(w.centre_x+(RADIUS+5)+90+27+j,w.centre_y-17,1);
 line(w.centre_x+(RADIUS+5)+90+27+j,w.centre_y-17-1,w.centre_x+(RADIUS+5)+90+27+50+j,w.centre_y-17-1-15);
 line(w.centre_x+(RADIUS+5)+90+27+j,w.centre_y-17+1,w.centre_x+(RADIUS+5)+90+27+50+j,w.centre_y-17+1+15);
 arc(w.centre_x+(RADIUS+5)+90+27+50+j,w.centre_y-17,270,90,15);
 setfillstyle(BKSLASH_FILL,YELLOW);
 floodfill(w.centre_x+(RADIUS+5)+90+27+25+j,w.centre_y-17,YELLOW);

 setcolor(YELLOW);                                                                       //Exhaust Pipe
 rectangle(w.centre_x-(RADIUS+5)-40-2+j,w.centre_y-1,w.centre_x-(RADIUS+5)-40+j,w.centre_y);
 setcolor(DARKGRAY);
 circle(w.centre_x-(RADIUS+5)-40-4-k+j,w.centre_y,RADIUS-16+k);
 setfillstyle(CLOSE_DOT_FILL,DARKGRAY);
 floodfill(w.centre_x-(RADIUS+5)-40-4-k+j,w.centre_y-2,DARKGRAY);
 if(k>15)
 k=5;
 else
 k=k+5;
 i_1=i_1-450.0+2.0;
 i_2=i_2-450.0+2.0;
}
j=j+2;
delay(TIME+d);
}while(j>10&&j<620);
if(j<5)
break;
j=10;
stop=clock();
time=time+(stop-start)/CLK_TCK;                                                           //Controlling Fuel Meter
}
if(j<5)
{
printf("Press any key to start the car : ");
getch();
cleardevice();
}

fclose(fp);
closegraph();
}
//----------------------------------------------
void move_car(void)
{
int i=10;
printf("Press any key to stop the car : ");
draw_car(i);
}
void fuel_meter(int x,int y)                         
{
setcolor(BLUE);
circle(100,150,RADIUS_M);
circle(100,150,RADIUS_M+5);
setfillstyle(SOLID_FILL,BLUE);
floodfill(100+RADIUS_M+2,150,BLUE);
setcolor(GREEN);
outtextxy(50,150,"R");
outtextxy(100,100,"H");
outtextxy(150,150,"F");
setcolor(YELLOW);
settextstyle(7,HORIZ_DIR,1);
outtextxy(70,150,"FUEL");
setcolor(RED);
line(100,150,x,y);
}

void menu(void)                                   //Menu
{
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tPress 1 for the moving car ");
printf("\n\n\n\n\t\t\tPress 2 for editing the speed file \n");
printf("\n\n\n\n\t\t\tPress 0 to exit \n");
}

void func_2(void)                                //Edit Speed File
{
FILE *fp;
char ans,ch;
fp=fopen("SPEED.TXT","a");                      //Opens File In Appened Mode                    
if(fp==NULL)                                    //Checks if File Exists 
{
printf("Cannot open File..........exiting ");
exit(1);
}  
do                                               //Appends Character by Character      
{
printf("Enter the character to be added to the file : ");
scanf("%s",&ch);
fputc(ch,fp);
printf("Enter another : (y/n) : ");
scanf("%s",&ans);
}while(ans=='y'||ans=='Y');
fclose(fp);
menu();
}