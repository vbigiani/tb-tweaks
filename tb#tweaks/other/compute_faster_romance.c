#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char *argv[])
{
  int i, j, k, l, result, result1;
  int upping = 1, cycle,tc,tc1,tc2,tc3,upped;
  int start, start1, dest, dest1;
  int is_best=1;
  int stop=0;
  int best[4]={0,0,0,0};
  int curr[4]={40,40,40,40};
  float err_best = 99999.9;
  float err1_best = 99999.9;
  float err;
  float err1;
  if (argc != 5)
  {
    printf("First number to transform?\n");
    scanf("%d",&start);
    printf("Turn in what?\n");
    scanf("%d",&dest);
    printf("Second number to transform?\n");
    scanf("%d",&start1);
    printf("Turn in what?\n");
    scanf("%d",&dest1);
  }
  else
  {
    start = atoi(argv[1]);
    dest = atoi(argv[2]);
    start1 = atoi(argv[3]);
    dest1 = atoi(argv[4]);
  }
  i = curr[0] = (int) (1000.0 * log((float)dest/(float)dest1)/log((float)start/(float)start1));
  j = curr[1] = (int) (1000.0 * (float)dest/pow((float)start,(float)i/1000.0));
  k = curr[2] = 1000;
  l = curr[3] = 1000;
  best[0] = i;
  best[1] = j;
  best[2] = k;
  best[3] = l;
#ifdef __DEBUG
  printf("\ni:%d j:%d k:%d l:%d ",i,j,k,l);
#endif  
  result  = (j*(int)pow((float)start,(float)i/(float)l))/k;
  result1 = (j*(int)pow((float)start1,(float)i/(float)l))/k;
  err = ((float)result-(float)dest)/(float)dest;
  err_best = err < 0 ? -err : err;
  err1 = ((float)result1-(float)dest1)/(float)dest1;
  err1_best = err1 < 0 ? -err1 : err1;
  for (cycle = 0; cycle < 20000 && stop<8; cycle++)
  {
    upped = 0;
    upping = 1;
    while(upping < 3)
    {
      is_best=0;
      tc=cycle%4;
      i = curr[0];
      j = curr[1];
      k = curr[2];
      l = curr[3];
#ifdef __DEBUG
      printf("\ni:%d j:%d k:%d l:%d (before)",i,j,k,l);
#endif
      if(upping==1) curr[tc]++;
      else curr[tc]--;
      i = curr[0];
      j = curr[1];
      k = curr[2];
      l = curr[3];
#ifdef __DEBUG
      printf("\ni:%d j:%d k:%d l:%d ",i,j,k,l);
#endif
      result  = (j*(int)pow((float)start,(float)i/(float)l))/k;
      result1 = (j*(int)pow((float)start1,(float)i/(float)l))/k;
      err = ((float)result-(float)dest)/(float)dest;
      err = err < 0 ? -err : err;
      err1 = ((float)result1-(float)dest1)/(float)dest1;
      err1 = err1 < 0 ? -err1 : err1;
//       is_best |= (err1<err1_best)&&(err<err_best);
      is_best |= (err1<err1_best*1.2)&&(err<err_best*0.6);
      is_best |= (err1<err1_best*0.6)&&(err<err_best*1.2);
//       is_best |= (err1*err)/(err_best*err1_best)<1.0;
      is_best |= (err1*err1+err*err)<(err1_best*err1_best+err_best*err_best);
      if (is_best)
      {
          err_best=err;
          err1_best=err1;
          best[0] = i;
          best[1] = j;
          best[2] = k;
          best[3] = l;
#ifdef __DEBUG
          printf(" (good)");
#endif
          upped=1;
          stop=0;
      }
      else
      {
        if(upping==1)curr[tc]--;
        else curr[tc]++;
        upping++;
        if(upped)upping=3;
        stop++;
#ifdef __DEBUG
        printf(" (bad - reverted)");
#endif
      }
    }
  }
  i=best[0];
  j=best[1];
  k=best[2];
  l=best[3];
  result  = (j*(int)pow((float)start,(float)i/(float)l))/k;
  result1 = (j*(int)pow((float)start1,(float)i/(float)l))/k;
  err=(float)result-(float)dest;
  err/=dest;
  err=err<0?err*(-1):err;
  err1=(float)result1-(float)dest1;
  err1/=dest1;
  err1=err1<0?err1*(-1):err1;
#ifdef __DEBUG
  printf("\n\n");
#endif
  printf("Best match:\n");
  printf("%d / %d * %5d ^ (%d / %d) = %d (target: %5d, error %6.3f)\n",j,k,start,i,l,result,dest,err);
  printf("%d / %d * %5d ^ (%d / %d) = %d (target: %5d, error %6.3f)\n",j,k,start1,i,l,result1,dest1,err1);
  printf("Use the following code:\n\n// 3600  -> %d \n// 36000 -> %d \nOUTER_SET multiply = %d\n\
OUTER_SET divide = %d\nOUTER_SET exponentiation = %d\nOUTER_SET nth_root = %d\n\n",
    dest,dest1,j,k,i,l);

}
