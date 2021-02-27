#include<conio.h>
#include<graphics.h>
#define L 75
#define R 77
#define U 72
#define D 80
#define DEL 83
#define PGD 81
#define PGU 73
#define HOME 71
#define END 79
#define F1 59
#define F2 60
#define F3 61
#define F4 62
#define F5 63
#define F6 64
#define F7 65
#define F8 66
#define F9 67
#define F10 68
#define F11 133
#define F12 134
#define INS 82
#define ALTS 31
#define ALTO 24
int x=350,y=230,c,w=0,z=0;
void main(void)
{
int gd=DETECT,gm;
char ch,ch1,ch2,text[60];
void *q;
initgraph(&gd,&gm,””);
setcolor(GREEN);
outtextxy(200,0,”THIS IS A PAINT BRUSH SCREEN “);
rectangle(10,10,600,460);
rectangle(10,10,150,460);
setcolor(7);
outtextxy(12,20, “F1 : BLACK”);
setcolor(1);
outtextxy(12,50, “F2 : BLUE”);
setcolor(2);
outtextxy(12,80, “F3 : GREEN”);
setcolor(3);
outtextxy(12,110,”F4 : CYAN”);
setcolor(4);
outtextxy(12,140,”F5 : RED”);
setcolor(5);
outtextxy(12,170,”F6 : MAGENTA”);
setcolor(8);
outtextxy(12,200,”F7 : GRAY”);
setcolor(9);
outtextxy(12,230,”F8 : LIGHTBLUE”);
setcolor(10);
outtextxy(12,260,”F9 : LIGHTGREEN”);
setcolor(12);
outtextxy(12,290,”F10: LIGHTRED”);
setcolor(14);
outtextxy(12,320,”F11: YELLOW”);
setcolor(15);
outtextxy(12,350,”F12: WHITE”);
rectangle(10,380,150,460);
outtextxy(12,390,”INS:”);
outtextxy(12,400,”1.CIRCLE”);
outtextxy(12,410,”2.SQUARE”);
outtextxy(12,420,”3.HORIZONTAL LINE”);
outtextxy(12,430,”4.VERTICAL LINE”);
while( getch()==0)
{
switch(getch())
{
case F1: c=0;break;
case F2: c=1;break;
case F3: c=2;break;
case F4: c=3;break;
case F5: c=4;break;
case F6: c=5;break;
case F7: c=8;break;
case F8: c=9;break;
case F9: c=10;break;
case F10: c=12;break;
case F11: c=14;break;
case F12: c=15;break;
case L :x–; image(x,y,c);break;
case R :x++; image(x,y,c);break;
case U :y–; image(x,y,c);break;
case D :y++; image(x,y,c);break;
case DEL : image(x,y, 0);break;
case PGD : y=y+3;break;
case PGU : y=y-3;break;
case HOME : x=x-3;break;
case END : x=x+3;break;
case INS : ch2=getch();
setcolor(c);
if((int)ch2-48==1)
{
ch1=getch();
circle(x,y,2*(int)ch1-48);
}
else if((int)ch2-48==2)
{
ch1=getch();
rectangle(x,y,x+2*(int)ch1-48,y+2*(int)ch1-48);
}
else if((int)ch2-48==3)
{

w=x+20;
line(x,y,w,y);
gotoxy(w,y);
}
else if((int)ch2-48==4)
{
z=y+20;
line(x,y,x,z);
moveto(x,z);
}
break;

}
}
}
image(int x,int y, int c)
{
putpixel(x,y,c);
putpixel(x++,y,c);
putpixel(x,y,c);
putpixel(x–,y,c);
}

