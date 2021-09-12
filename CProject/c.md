### 21.结构体数组

```c
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct stStudent{
	int age;
	int level;
};

struct stStudent arr[5] = {
	{0,0},{1,1},{2,2},{3,3},{4,4}
};
void main(){
	system("pause");
	return;
}
```

结构体数组在内存中是连续存放的

![image-20210909152504187](c.assets/image-20210909152504187.png)

### 22.指针类型

指针类型的变量宽度永远是4个字节，无论类型是什么，无论有几个*；

指针其实就是一种新的类型罢了

![image-20210910095037269](c.assets/image-20210910095037269.png)

#### 1.自增操作

```C
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void main(){
	char**** x;
	short**** y;
	int**** z;
	x = (char****)100;
	y = (short****)100;
	z = (int****)100;

	x++;
	y++;
	z++;

	printf("%d %d %d",x,y,z);
	system("pause");
	return;
}
```

![image-20210910105950789](c.assets/image-20210910105950789.png)

```C
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void main(){
	char* x;
	short* y;
	int* z;
	x = (char*)100;
	y = (short*)100;
	z = (int*)100;

	x++;
	y++;
	z++;

	printf("%d %d %d",x,y,z);
	system("pause");
	return;
}
```

![image-20210910110334660](c.assets/image-20210910110334660.png)

总结：

不带*类型的变量，++或者--都是加1或者减1，例如

int a = 0; a++;   a->1

带**类型的变量，++或者--新增（减少）的数量是去掉一个* * 之后变量的宽度：

例如：

```bash
char** a = (char**) 100;
a++;
a -> 104
//去掉一个* int** -> int* 还是一个指针变量，指针变量宽度是4字节，因此，自增4
char* a = (char*) 100;
a ++;
a -> 101
//去掉一个*  char* -> char,变成了一个char类型变量，宽度是1个字节，因此，自增1
```

#### 2.加减运算

```C
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void main(){
	char* x;
	short* y;
	int* z;
	x = (char*)100;
	y = (short*)100;
	z = (int*)100;

	x = x + 5;
	y = y + 5;
	z = z + 5;

	printf("%d %d %d",x,y,z);
	system("pause");
	return;
}
```

![image-20210910111152301](c.assets/image-20210910111152301.png)

char * 砍掉 * 变为 char,占用一个字节单位，所以x = x + (1 * 5) = 105

short * 砍掉 * 变为 short,占用二个字节单位，所以y = y + (2 * 5) = 110

int * 砍掉 * 变为 int,占用四个字节单位，所以z = z + (4 * 5) = 120

```C
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void main(){
	char** x;
	short** y;
	int** z;
	x = (char**)100;
	y = (short**)100;
	z = (int**)100;

	x = x + 5;
	y = y + 5;
	z = z + 5;

	printf("%d %d %d",x,y,z);
	system("pause");
	return;
}
```

![image-20210910111514275](c.assets/image-20210910111514275.png)

char ** 砍掉 * 变为 char * ,仍是指针变量占用四个字节单位，所以x = x + (4 * 5) = 120

short ** 砍掉 * 变为 short * ,仍是指针变量占用四个字节单位，所以y = y + (4 * 5) = 120

int ** 砍掉 * 变为 int * ,仍是指针变量占用四个字节单位，所以z = z + (4 * 5) = 120

**指针只能做加减操作，以及比较大小。**

### 23.&的使用

&是地址符，任何变量都可以使用&来获取地址，但不能用在常量上

```C
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
struct Point{
    int x;
    int y;
};
char a;
short b;
int c;
struct Point p;
void main(){
    a = 1;
    b = 2;
    printf("%x,%x,%x,%x \n",&a,&b,&c,&p);
    system("pause");
    return;
}
```

![image-20210912222912297](c.assets/image-20210912222912297.png)

全局变量的地址在运行前就已经给好了

```bash
10:       char a;
11:       short b;
12:       int c;
13:       struct Point p;
14:       printf("%x,%x,%x,%x \n",&a,&b,&c,&p);
00401428   lea         eax,[ebp-14h]
0040142B   push        eax
0040142C   lea         ecx,[ebp-0Ch]
0040142F   push        ecx
00401430   lea         edx,[ebp-8]
00401433   push        edx
00401434   lea         eax,[ebp-4]
00401437   push        eax
00401438   push        offset string "%x,%x,%x,%x \n" (0042405c)
0040143D   call        printf (00401490)
00401442   add         esp,14h
15:       system("pause");
00401445   push        offset string "pause" (00424054)
0040144A   call        system (00401550)
0040144F   add         esp,4
16:       return;
17:   }
```

局部变量的地址在运行时才能确定



& + 一个变量，得到的结果就是 原来的变量加个*

比如：

```C
int a = 0;
int* p1 = &a; 	//原来的变量是int，加个* 变为int*

char* c;
char** p2= &c;	//同理

short*** s;
short**** p3 = &s
```

```C
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void main(){
    char x;
    char* p1;
    char** p2;
    char*** p3;
    char**** p4;
    p1 = &x;
    p2 = &p1;
    p3 = &p2;
    p4 = &p3;
    system("pause");
    return;
}
```

