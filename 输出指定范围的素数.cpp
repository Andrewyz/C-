C语言实现输出指定范围的素数/质数

老版本：主函数中实现
一.素数在数组中顺序存储
二.素数与数组下标相同
新版本：主函数中实现
老版本：主函数中实现

思路：
1.判断区间为3～sqrt（本身）
2.排除偶数//被判断数和判断数中都排除

一.素数在数组中顺序存储

#include<stdio.h>
#include<math.h>
#define swap(a,b){a=a^b;b=a^b;a=a^b;}//定义数字交换的宏

int main(void) {
    
    
    int sub=1,sqr;//定义sub记录下标,从1开始;定义sqr缩小判断范围
   const int N=1000;
    printf("输出2-%d之间的素数\n",N);
    int prime[N]={2,0};//定义数组存放素数,除prime[0]外全部初始化为0
    for(int i=3;i<=N;i+=2){//判断从3到N的奇数,排除大于2偶数
        // if(i%2==0) continue;//如果i为2的倍数,不是素数,继续下次循环 i++时
        
        sqr=sqrt(i);
        int flag=0;
        for(int j=3;j<=sqr;j+=2){//判断从3到sqr的奇数是否能整除i
            if(i%j==0) {
                flag=1;
                break;
            }
        }
        if(flag) continue;//如果能被整除,跳过该循环
        
        prime[sub++]=i;
    }
    for(int i=0;i<sub;i++)
        printf("%d\t",prime[i]);
    puts("");
    
    return (0);
}
二.素数与数组下标相同

#include<stdio.h>
#include<math.h>
#define swap(a,b){a=a^b;b=a^b;a=a^b;}//定义数字交换的宏

int main(void) {
    
    
    int sqr;//从1开始;定义sqr缩小判断范围
    const int N=1000;
    printf("输出2-%d之间的素数\n",N);
    int prime[N+1]={0,0,2,0};//定义数组存放素数,除prime[2]外全部初始化为0
    for(int i=3;i<=N;i+=2){//判断从3到N的奇数,排除大于2偶数
       // if(i%2==0) continue;//如果i为2的倍数,不是素数,继续下次循环 i++时用
        
        sqr=sqrt(i);
        int flag=0;
        for(int j=3;j<=sqr;j+=2){//判断从3到sqr的奇数是否能整除i
            if(i%j==0) {
                flag=1;
                break;
            }
        }
        if(flag) continue;//如果能被整除,跳过该循环
        
        prime[i]=i;
    }
    for(int i=0;i<=N;i++)
        if(prime[i]!=0)
            printf("%d\t",prime[i]);
    puts("");
    
    return (0);
}
新版本：主函数中实现

思路：
1.大于2的偶数都不是质数，只对奇数进行整除判断
2.只整除小于等于no的平方根的质数//由长方形面积和约数

算法依据

#include<stdio.h>

int *prime(int n){
    int prime[100000]={0};//数组元素个数可以扩展
    int ptr =0;
    prime[ptr++]=2;
    prime[ptr++]=3;
    for(int no=5;no<=n;no+=2){//大于2的偶数都不是质数
        int flag=0;
        
        for(int i=1;prime[i]*prime[i]<=no;i++){//只整除小于等于no的平方根的质数
            if (no%prime[i]==0) {
                flag=1;
                break;
            }
        }
        if(!flag)
            prime[ptr++]=no;
    }
    
    return prime;
}
int main(void) {
    const int N=100000;//求N及以下的素数
    int *a=prime(N);
    int counter=0;
    for(int i=0;i<N/2;i++){//素数个数不会大于N/2
        if(a[i]==0) break;//遇到0,则后面皆为0 跳出
        printf("%d\t",a[i]);
        counter++;
        
    }
    printf("\n\t1~%d的素数y个数为:%d\n",N,counter);//测速时可以注释掉输出
    
    return (0);
}
可以将主函数体放置于下面的代码测试不同算法的性能

#include <ctime>//需要额外添加该编译预处理指令

int main(void) {
    int tstart ,tstop; //分别记录起始和结束时间
    //测试函数花费时间
    tstart=clock ();
    ····················须测速代码
    tstop=clock ();
    printf("花费时间(ms):%d\n",tstop- tstart);//ms为单位
    return (0);
}


