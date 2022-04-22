#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
 
int main(void)
{
  /* request auto detection */
  int gdriver = DETECT, gmode, errorcode;
  
  /* initialize graphics mode */
  initgraph(&gdriver, &gmode, "");
  
  /* read result of initialization */
  errorcode = graphresult();
  
  if (errorcode != grOk) /* an error occurred */
  {
    printf("Graphics error: %s\n", grapherrormsg(errorcode));
    printf("Press any key to halt:");
    getch();
    exit(1); /* return with error code */
  }
  
  /* draw a line */
  line(0, 0, getmaxx(), getmaxy());
  
  /* clean up */
  getch();
  closegraph();
  return 0;
}
The below program draws a circle in the current drawing color with its center at (150,150) and the radius (100) given by radius.

1
2
3
4
5
6
7
8
9
10
11
12
/* Sample program to draw a circle*/
#include<graphics.h>
#include<conio.h>
main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,""); /* initialization of graphic mode */
  circle(150,150,100);
  getch();
  closegraph(); /* Restore orignal screen mode */
}
/* End of program */
