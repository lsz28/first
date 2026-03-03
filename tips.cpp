//整型
double d=(double)a/b;
double d=static_cast<double>(n);
//向取整
double t=ceil(s/v);
double t=floor(s/v);
//设置精度
cout<<fixed<<setprecision(2)<<a;
cout<<setfill('0')<<setw(2)<<b;
//时间
h=s/3600
m=(s%3600)/60
s=s%60
跨天计算就加上24*3600
//取平方根
int a=4;
double b=sqrt(a); 
//取最大公约数
int gcd(int a,int b)
{
	a=abs(a);
	b=abs(b);
	while(b!=0)
	{
		int temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}
//排序
sort(vec.begin(),vec.end());

bool judge(int a,int b)
{
	if()
	return a>b;
}
sort(vec.begin(),vec.end(),judge)(如果a>b就不换,即真就不换) 

int len=sizeof(arr)/sizeof(arr[0]);
sort(arr,arr+len);

//遍历多位数
int a;
string s=to_string(a);
vector<int>danshu;
for(int i=0;i<s.size();i++)
{
	danshu.push_back(s[i]-'0'); 
}

数字法
vector<int>weishu;
while(temp%10>0)
{
	weishu.push_back(temp%10);
	temp=temp/10;
} 

//字符串和整型之间的转换 
int num=345;
string s=to_string(num);

string s="123";
int num=stoi(s);

//判断是否是质数
bool iszhishu(int a)
{
	if(a<=1)
	return false;
	
	
		for(int i=2;i*i<=n;i++)
		{
			if(a&i==0)
			return false;
		}
		
	
	return true;
} 

//字母重复次数计算
string s="A";
int chongfu[52];
for(int i=0;i<n;i++)
{
	if(s[i]>='A'&&s[i]<='Z')//注意,这里变换了坐标 
	{
		chongfu[s[i]-'A']++;//A的ascii减了之后就变成0,所以重复[0]=1; 
	}
	else if(s[i]>='a'&&s[i]<='z')
	{
		chongfu[26+s[i]-'a']++;
	}
} 
cout<<chongfu[0]; 
