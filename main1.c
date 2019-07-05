#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define FALSE 0
#define TRUE 1
#define M 10                        //最大进程数
#define N 10                        //最大资源类数
int m;                              //进程数
int n;                              //资源数目
int id;                             //进程ID号

int Available[N];	                //资源总数
int MAX[M][N];		                //最大需求矩阵
int Need[M][N];		                //需求矩阵
int Allocate[M][N];	                //分配矩阵
int Request[N];		                //请求资源
int Work[N];		                //工作向量
int Finish[M];                      //进程完成标志
int work_allocation[M][N];

void init_system();
void init_system2();
void print_infor();
int try_allocate();
void return_back();
int is_safe();

int flag = FALSE;
int safe[M];

void init_system()
{
	int i=0,j=0;
	char ch;
	int temp;
//	printf("请输入进程数目:\n");
	m=5;
//	printf("请输入资源种数:\n");
	n=3;
	// printf("请输入各类资源总数:\n");
	// for(; i < n;i++)
	// 	Available[i]=rand()%20;
	// printf("输入各进程对各资源的最大需求:\n");
	// for(i = 0;i < m;i++)
	// {
	// 	printf("进程P%d:\n",i);
	// 	for(j=0 ; j < n;j++)
	// 	{
	// 		MAX[i][j]=rand()%10;
	// 		printf("MAX[%d][%d]=%d",i,j,MAX[i][j]);
	// 	}
	// }
    Available[0]=3;
    Available[1]=3;
    Available[2]=2;
    MAX[0][0]=7;
    MAX[0][1]=5;
    MAX[0][2]=3;
    MAX[1][0]=3;
    MAX[1][1]=2;
    MAX[1][2]=2;
    MAX[2][0]=9;
    MAX[2][1]=0;
    MAX[2][2]=2;
    MAX[3][0]=2;
    MAX[3][1]=2;
    MAX[3][2]=2;
    MAX[4][0]=4;
    MAX[4][1]=3;
    MAX[4][2]=3;


    Allocate[0][0]=0   ;
    Allocate[0][1]=1   ;
    Allocate[0][2]=0   ;

    Allocate[1][0]=  2 ;
    Allocate[1][1]=  0 ;
    Allocate[1][2]=  0 ;

    Allocate[2][0]=   3;
    Allocate[2][1]=   0;
    Allocate[2][2]=   2;

    Allocate[3][0]=  2 ;
    Allocate[3][1]=  1 ;
    Allocate[3][2]=  1 ;

    Allocate[4][0]=  0 ;
    Allocate[4][1]=  0 ;
    Allocate[4][2]=  2 ;

	
  for(i = 0;i<m;i++)
                for(j=0;j<n;j++)
		{
                        Need[i][j] = MAX[i][j] - Allocate[i][j];
			work_allocation[i][j] = Allocate[i][j]+Work[j];
		}
	bzero(Request,sizeof(Request));
    bzero(Work,sizeof(Work));
	bzero(Finish,sizeof(Finish));
	 /*初始时刻 Need*/
        for(i = 0;i<m;i++)
                for(j=0;j<n;j++)
		{
                        Need[i][j] = MAX[i][j] - Allocate[i][j];
			work_allocation[i][j] = Allocate[i][j]+Work[j];
		}
}void init_system2()
{
	int i=0,j=0;

	m=5;
	n=3;
	Available[0]=2;
Available[1]=3;
Available[2]=3;

    MAX[0][0]=5;
    MAX[0][1]=5;
    MAX[0][2]=9;
    MAX[1][0]=5;
    MAX[1][1]=3;
    MAX[1][2]=6;
    MAX[2][0]=4;
    MAX[2][1]=0;
    MAX[2][2]=11;
    MAX[3][0]=4;
    MAX[3][1]=2;
    MAX[3][2]=5;
    MAX[4][0]=4;
    MAX[4][1]=2;
    MAX[4][2]=4;


    Allocate[0][0]=2   ;
    Allocate[0][1]=1   ;
    Allocate[0][2]=2   ;

    Allocate[1][0]=  4 ;
    Allocate[1][1]=  0 ;
    Allocate[1][2]=  2 ;

    Allocate[2][0]=   4;
    Allocate[2][1]=   0;
    Allocate[2][2]=   5;

    Allocate[3][0]=  2;
    Allocate[3][1]=  0 ;
    Allocate[3][2]=  4 ;

    Allocate[4][0]=  3 ;
    Allocate[4][1]=  1 ;
    Allocate[4][2]=  4 ;

	
  for(i = 0;i<m;i++)
                for(j=0;j<n;j++)
		{
                        Need[i][j] = MAX[i][j] - Allocate[i][j];
			work_allocation[i][j] = Allocate[i][j]+Work[j];
		}
	bzero(Request,sizeof(Request));
    bzero(Work,sizeof(Work));
	bzero(Finish,sizeof(Finish));
	 /*初始时刻 Need*/
        for(i = 0;i<m;i++)
                for(j=0;j<n;j++)
		{
                        Need[i][j] = MAX[i][j] - Allocate[i][j];
			work_allocation[i][j] = Allocate[i][j]+Work[j];
		}
}

int try_allocate()
{
	int i,temp,j;
	int ret = TRUE;
	for(i = 0;i<m;i++)
                for(j=0;j<n;j++)
                 work_allocation[i][j] = Allocate[i][j]+Work[j];

	printf("请输入请求进程号:\n");
    scanf("%d",&id);

		if(id < 0 | id > m)
			printf("%d进程不存在!\n",id);
		else{
			printf("%d进程\n",id);
			
	}
	printf("请输入请求资源数(eg: 1 0 2):");
	scanf("%d %d %d",&Request[0],&Request[1],&Request[2]);
   
printf("Request%d( %d %d %d)\n",id,Request[0],Request[1],Request[2]);
	
	printf("开始为进程P%d分配资源:\n",id);
	for(i = 0;i < n;i++)
	{
		if(Request[i] > Need[id][i])
                {       
                        printf("进程请求资源数大于所需资源数,不予分配!\n");
			ret =  FALSE;
                }else if(Request[i] > Available[i]){
                        printf("进程请求资源数大于可用资源数，无法分配!\n");
			ret = FALSE;
		}
		Available[i] -= Request[i];
        Allocate[id][i] += Request[i];
        Need[id][i] -= Request[i];
	}	
	return ret;
}

void print_infor()
{
	int i,j,k;
	printf("\t  Work             Need          Allocation    Work+Allocation Finish\n");
	for(j = 0 ; j < 4; j++)
	{
		printf("\t  ");
		for(i = 0 ; i < n; i++)
		printf("%c  ",(char)('A'+i));
	}

	printf("\n******************************************************************************\n");
	for(k=0;k<m;k++)
	{
		if(flag == TRUE)
			i = safe[k];
		else i = k;
		printf("P%d\t",i);
		for(j=0;j<n;j++)
			printf("%3d",work_allocation[i][j]-Allocate[i][j]);
		printf("\t");
		for(j=0;j<n;j++)
                        printf("%3d",Need[i][j]);
		printf("\t");
		for(j=0;j<n;j++)
                        printf("%3d",Allocate[i][j]);
		printf("\t");
		for(j=0;j<n;j++)
                        printf("%3d",work_allocation[i][j]);
		printf("\t");
		if(Finish[i] == FALSE)
			printf("false\n");
		else printf("true\n");
	}
}

void return_back()
{
	int i,j;
	bzero(Finish,sizeof(Finish));
	for(i = 0;i < n;i++)
        {
                Available[i] += Request[i];
                Allocate[id][i] -= Request[i];
                Need[id][i] += Request[i];
        }
	bzero(work_allocation,sizeof(work_allocation));
        for(i = 0;i<m;i++)
                for(j=0;j<n;j++)
		{
			work_allocation[i][j] = Allocate[i][j];
		}
}

/*安全性检查函数*/
int is_safe()
{
	int i,j;
	int count = 0; 
	bzero(work_allocation,sizeof(work_allocation));
	printf("**********Work向量**********\n");
	for(i = 0;i < n;i++)
        {
                Work[i] = Available[i];
		work_allocation[0][i] = Work[i];
        }
	for(i = 0;i < m;i++)
		Finish[i] = FALSE;
	for(i = 0;i < m;i++)
	{
		if(Finish[i] == FALSE)
		{
			for(j=0;j<n;j++)
			{
				if(Need[i][j] > Work[j])
				break;
			}
			if(j == n)
			{
				printf("P%d\t",i);
				safe[count++] = i;
				for(j=0;j<n;j++)
				{
					Work[j] += Allocate[i][j];
					work_allocation[i][j] = Work[j];
					printf("%d\t",Work[j]);
				}
				printf("\n");
				Finish[i] = TRUE;  //进程i能顺利完成
				if(i == m-1)
					i = -1;//重新开始
			}
		}	
	}
	printf("\n");
	for(i = 0;i<m;i++)
	{
		if(Finish[i] == FALSE) 
		{	
			printf("进程P%d不能顺利完成！\n",i);
			return FALSE;
		}
	}
	/*如果前面未返回，则存在安全序列*/
	printf("存在如下安全序列:\n");
	for(i = 0 ;i < m; i++)
		printf("P%d",safe[i]);
	printf("\n");
    {

    }
	return TRUE;
}

int main(void)
{
	int ret = FALSE;
	int choice;
	while(1)
	{
		printf("欢迎使用模拟避免进程死锁算法，请选择你要进行的操作:\n");
		printf("\t**1、test1初始化\n");
 //       init_system();
		printf("\t**2、test2初始化\n");
		printf("\t**3、系统分配Request\n");	
		printf("\t**4、ShowInfo\n");
		printf("\t**5、当前状态安全性检查\n");
		printf("\t**0、退出系统\n");
		scanf("%d",&choice);
		if(choice == 1)
			init_system();
        else if(choice==2)
        {
            init_system2();
              }
        
		else if(choice == 3)
		{
            system("clear");
			if(try_allocate() == TRUE)
			{
				flag = is_safe();
        			if(flag == FALSE)
        			{
                			printf("系统不安全,不能予以分配!\n");
                			return_back();
       	 			}else{
                			printf("系统安全！分配成功!\n");
                			return_back();
                            print_infor();
                            for (int  i = 0; i < n; i++)
                            {
                                Need[id][i]-=Request[i];
                                Allocate[id][i]+=Request[i];
                                Available[i]-=Request[i];
                            }
        			}
			}else{
				printf("分配失败!\n");
				return_back();
			}
		}
		else if(choice == 3)
			print_infor();
		else if(choice == 0)
			break;
		else if(choice == 4)
			print_infor();
		else if(choice == 5)
		{
			if((flag = is_safe()) == FALSE)
				printf("当前状态不安全!\n");
			else	printf("当前状态安全！\n");
		}
		else
			printf("输入不合法!重新输入!\n");
	}
}