#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <dos.h>
#define barw 5
#define del 50

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[],int size, int col){
   int i;
   for(i=0;i<size;i++){
      setfillstyle(SOLID_FILL, col);
      bar((i*barw)+4, getmaxy(),i*barw+7,(getmaxy()-arr[i]));
      outtextxy((getmaxx()/2)-90,30,"BUBBLE SORT WITH MUSIC");
      }
}

void colorBarG(int arr[],int position){
 setfillstyle(SOLID_FILL,10);
 bar((position*barw)+4,getmaxy(),position*barw+7,getmaxy()-arr[position]);
}

void colorBarR(int arr[],int position){
 setfillstyle(SOLID_FILL,4);
 bar((position*barw)+4,getmaxy(),position*barw+7,getmaxy()-arr[position]);
}
void clearBar(int arr[],int position){
 setfillstyle(EMPTY_FILL,7);
 bar((position*barw)+4,getmaxy(),position*barw+7,getmaxy()-arr[position]);
}
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
   {
       for (j = 0; j < n-i-1; j++)
       {
	   colorBarR(arr,j);
	   sound(arr[j]);
	   delay(del);
	   if (arr[j] > arr[j+1])
	   {  clearBar(arr,j);
	      swap(&arr[j], &arr[j+1]);
	   }
	   printArray(arr,n,7);
	   //colorBarR(arr,j);
       }
   }
   nosound();
}

int main()
{
   int gdriver = DETECT, gmode, errorcode;
   int i,size=70;
   time_t t;
   int arr[70];
   srand((unsigned) time(&t));
   for(i=0; i<size; i++)
    arr[i]=rand() % 400;

   initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an errorcode */
   }
   printArray(arr,size,7);
   bubbleSort(arr,size);
   for(i=0;i<size;i++){
      setfillstyle(SOLID_FILL, 10);
      bar((i*barw)+4, getmaxy(),i*barw+7,(getmaxy()-arr[i]));
      sound(arr[i]);
      delay(del);
      }
      nosound();
   getch();
   closegraph();
   return 0;
}