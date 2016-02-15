/***************************************************************************************
  RK2.c 1.0
  (C) 12/04/2013 18:04:27 by MARCOS BRITO, marbri91@gmail.com
Description: Metodo Runge Kutta para ecuaciones de orden 2
			Despeja x'' y sustituyelo por y
			x'' = f(t,x,x')
			---------------
			y = x'
			y' = f(t,x,y)
 **************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double f(double t,double x, double y)
{
   return y;
}
double g(double t,double x,double y)
{
   return -x;
}

int main(int argc, char **argv)
{
   double x=0, y=0, t=0, h=0, m=0, k=0;
   double F[4]={0,0,0,0};
   double G[4]={0,0,0,0};
   int i=0;
   if(argc<5)
   {
      printf("Usage: ./RK2 x0 y0 init steps end\n");
      return 0;
   }
   x=atof(argv[1]);
   y=atof(argv[2]);
   t=atof(argv[3]);
   k=atof(argv[4]);
   m=atof(argv[5]);
   h=(m-t)/k;
   printf("%.10g %.15g\n",t,x);
   for (i=0; i<k; i++)
   {
      F[0]=f(t,x,y);
      G[0]=g(t,x,y);
      F[1]=f(t+h/2,x+h*F[0]/2,y+h*G[0]/2);
      G[1]=g(t+h/2,x+h*F[0]/2,y+h*G[0]/2);
      F[2]=f(t+h/2,x+h*F[1]/2,y+h*G[1]/2);
      G[2]=g(t+h/2,x+h*F[1]/2,y+h*G[1]/2);
      F[3]=f(t+h,x+h*F[2],y+h*G[2]);
      G[3]=g(t+h,x+h*F[2],y+h*G[2]);
      x+=(h/6)*(F[0]+2*F[1]+2*F[2]+F[3]);
      y+=(h/6)*(G[0]+2*G[1]+2*G[2]+G[3]);
      t=t+h;
	   printf("%.10g %.15g\n",t,x);
   }
	return 0;
}
