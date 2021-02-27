#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>
void fun(int x,int y,int n,int a)
{
 textcolor(13);
 gotoxy(x,y);
 cprintf("%d->%c",n,a);
}
void box(int c,int r,int s,int y)
{
int i ;
textcolor(3);
gotoxy(s,y);
cprintf("%c",218);
for(i=s+1;i<c+1;i++)
 {
 gotoxy(i,y);
 cprintf("%c",196);
 }
 for(i=s+1;i<c+1;i++)
 {
 gotoxy(i,r);
 cprintf("%c",196);
 }
 gotoxy(c,y);
cprintf("%c",191);
for(i=y+1;i<r;i++)
{
 gotoxy(s,i);
 cprintf("%c",179);
}
for(i=y+1;i<r;i++)
{
 gotoxy(c,i);
 cprintf("%c",179);
}
gotoxy(s,i);
cprintf("%c",192);
 gotoxy(c,i);
 cprintf("%c",217);
}
void help()
{
box(78,24,2,1);
box(70,9,52,5);
box(77,23,30,15);
gotoxy(50,15);
printf("Play Like This");
gotoxy(31,16);
printf("1.Choose a two digit number and add the digits");
gotoxy(31,17);
printf("2.Subtract the sum from original number");
gotoxy(31,18);
printf("3.See the symbol opposit to the number you got");
gotoxy(31,19);
printf("4.Press any key The MIND READER will ");
gotoxy(31,20);
printf(" display the symbol you got");
gotoxy(31,21);
printf("5.For Best Results Please don't Turn your ");
gotoxy(31,22);
printf(" Eyes from the screen");
}
void ran()
{
 time_t t;
int r,i;
int a[]={1,2,3,4,5,6,14,15,16,17,18,19,20,21,22,23,24,25,27,29,
 30,33,34,35,36,37,38,40,41,42,43,60,62,61,63,64,123,124,
 125,126,127,128,154,155,156,171,172,174,175,229,234,235,
 236,237,238,239, 240,242,243,244,245,246,247,251,254};
srand((unsigned) time(&t));
 r=rand() % 65;
 help();
textcolor(10);
gotoxy(50,2);
cprintf("MAIND READER");
for(i=1;i<23;i++)
 {
 textcolor(13);
 gotoxy(3,i+1);
 cprintf("%d->%c ",i,a[rand()%65]);
 gotoxy(10,i+1);
 cprintf("%d->%c ",i+22,a[rand()%65]);
 gotoxy(17,i+1);
 cprintf("%d->%c ",i+44,a[rand()%65]);
 gotoxy(24,i+1);
 cprintf("%d->%c ",i+66,a[rand()%65]);
 }
 fun(3,10,9,r);
 fun(3,19,18,r);
 fun(10,6,27,r);
 fun(10,15,36,r);
 fun(17,2,45,r);
 fun(17,11,54,r);
 fun(17,20,63,r);
 fun(24,7,72,r);
 fun(24,16,81,r);
for(i=1;i<12;i++)
 {
 gotoxy(31,i+1);
 cprintf("%d->%c ",i+88,a[rand()%65]);
 }
 gotoxy(55,7);
textcolor(15+BLINK);
cprintf("Press Any Key");
getch();
 gotoxy(55,7);
textcolor(BLACK);
cprintf("Press Any Key");
 gotoxy(61,7);
textcolor(15+BLINK);
cprintf("%c",r);
 }
void main()
{
int i;
clrscr();
ran();
getch();
}
Advertisements
