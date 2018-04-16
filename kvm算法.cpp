#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
#include <string.h>  
  
int next[1000];  //��¼��תλ��   
int kmp_next(char *base)  
{  
    int i,j;  
    i=0;       
    j=-1;  
    next[0]=-1;      //��¼��һ���ַ�����תλ��Ϊ-1   
    while(base[i]!='\0')  
    {  
        //�����ת��-1��˵��ֻ�ܴ�ͷ��ʼƥ�䣻  
        //�����ǰƥ������ת���ƥ���ƥ��   
        if(j==-1||(base[i]==base[j]))  
        {  
           //�鿴��һƥ�������   
           i++;  
           j++;  
           //�����һƥ��㻹��ƥ��ģ�����һ����ַһ��   
           if(base[i]==base[j])  
           {  
               next[i]=next[j];  
           }  
           //���һƥ��㲻ƥ�䣬����һ����ַΪ��ǰǰ׺��ַ   
           else  
           {  
               next[i]=j;  
           }  
        }  
        else  
        {  
            j=next[j];  
        }  
    }  
}  
  
int kmp(char *b,char *base)  
{  
     int i,j;  
     i=0;j=0;  
     //ͨ����ת���飬���п���ƥ��   
     while(b[i]!='\0'&&base[j]!='\0')  
     {  
        if(b[i]==base[j])  
        {  
            i++;j++;  
        }  
        else  
        {  
            j=next[j];  
            if(j==-1)  
            {  
               i++;j++;  
            }  
        }  
     }  
     if(base[j]=='\0')  
     {  
         return i-j;  
     }  
     else  
         return -1;  
}  
  
int main()  
{  
      char base[]="DABCDABD";  
      char b[1000];  
      kmp_next(base);  
      for(int i=0;i<strlen(base);i++)  
      {  
          printf("%d ",next[i]);  
      }  
      printf("\n %s \n",base);  
      while(scanf("%s",b)!=EOF)  
      {  
          printf("%d \n",kmp(b,base));                    
      }  
    system("pause");  
}  
