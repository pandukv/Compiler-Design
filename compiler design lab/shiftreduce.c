1:  #include"stdio.h"  
2:  #include"ctype.h"  
3:  #include"string.h"  
4:  char stack[10], gram[10][10], input[10];  
5:  int size, elem[5], sizei, sizes;  
6:  int getGram(){  
7:       int i,j,k;  
8:       char ch;  
9:       printf("\nEnter Number of Rules : ");  
10:       scanf("%d",&size);  
11:       printf("\nEnter Rule as 'E=E+T' : ");  
12:       for(i=0;i<size;i++){  
13:                 scanf("%s%c",gram[i],&ch);  
14:       }  
15:       for(i=0;i<size;i++)  
16:            printf("\n%s",gram[i]);  
17:  }  
18:  int getInput(){  
19:       char ch;  
20:       printf("\nEnter size of input by element : ");  
21:       scanf("%d",&sizei);  
22:       sizei+=1;  
23:       printf("\nEnter Input as 'a+b' followed by '$' : ");  
24:       scanf("%s%c",input,&ch);  
25:       printf("\nInput is %s",input);  
26:  }  
27:  char validate(){  
28:       int i,j,flag=0,pos;  
29:       char ch='q';  
30:       printf("\n\tStackTop : %c\n\tStack : %s",stack[sizes-1],stack);  
31:       for(i=0;i<size;i++){  
32:            if(stack[sizes-1]==gram[i][2]){  
33:                 flag=1;  
34:                 pos=i;  
35:                 break;  
36:            }  
37:       }  
38:       if(flag==1){  
39:            ch=gram[pos][0];  
40:            printf("\nReduce %s",gram[pos]);  
41:       }  
42:       return ch;  
43:  }  
44:  int applyOp(){  
45:       char ch;  
46:       int i;  
47:       for(i=0;i<sizei;i++){  
48:            if(input[i]!='$'){  
49:                 stack[sizes]=input[i];  
50:                 printf("\nShift %c",input[i]);  
51:                 input[i]=' ';  
52:                 sizes=strlen(stack);  
53:            }  
54:            /*if(stack[i]=='a'||'b')  
55:                 stack[i]='E';  
56:            else */  
57:            ch=validate();  
58:            if(ch!='q'){  
59:                 stack[sizes-1]=ch;  
60:            }  
61:       }  
62:       for(i=0;i<size;i++){  
63:            if(gram[i][3]==stack[2])  
64:                 printf("\nReduce %s\n",gram[i]);  
65:       }  
66:  }  
67:  int main(){  
68:       stack[0]='$';  
69:       sizes=strlen(stack);  
70:       getGram();  
71:       getInput();  
72:       applyOp();  
73:  }  