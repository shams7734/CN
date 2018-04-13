/*  Implementation of IP address Calculator
	2015kucp1034
	Shams Ali
	
	This calculator calculates the usable IP address of a subnet .
	User needs to enter the IP address in the form as asked when user run the code.
	For calculating addresses user needs to enter minimum number of hosts or subnets required.
	
	It also tells the Class of IP address,Default Subnet,Custom Subnet etc. 
	
*/
#include<bits/stdc++.h>
using namespace std;

int p,q,r,s;

// Function to convert binary to integer

int convertBinaryToInt(int *a,int n)
{                           
    int x=0,i;
    for(i=0;i<n;i++){
        x = x + a[i]*pow(2,(n-1)-i);
    }
    return x;
}

//Function to convert integer to binary

void convertIntToBinary(int x,int *a,int n)
{                    
    int i;
    for(i = 0;i<n;i++){
        a[n-1-i] = (x%2);
        x = x/2;
    }
}

//   Function to check whether input is correct or not

void checkp(int temp)
{
	if(temp>255)
	{
		printf("Enter the correct value of P i.e between 0 and 255\n");
		cin>>p;
	}
}

void checkq(int temp)
{
	if(temp>255)
	{
		printf("Enter the correct value of Q i.e between 0 and 255\n");
		cin>>q;
	}
}

void checkr(int temp)
{
	if(temp>255)
	{
		printf("Enter the correct value of R i.e between 0 and 255\n");
		cin>>r;
	}
}

void checks(int temp)
{
	if(temp>255)
	{
		printf("Enter the correct value of S i.e between 0 and 255\n");
		cin>>s;
	}
}

int main()
{
	int i,j,k;
	printf("Enter the IP address in the form of P.Q.R.S\n");
	printf("Enter the value of P\n");
	cin>>p;
	checkp(p);
	printf("Enter the value of Q\n");
	cin>>q;
	checkq(q);
	printf("Enter the value of R\n");
	cin>>r;
	checkr(r);
	printf("Enter the value of S\n");
	cin>>s;
	checks(s);
	
	printf("The Entered IP Address is %d.%d.%d.%d\n",p,q,r,s);
	
	int status=0;
	
	//   Finding class of IP and Default Subnet
	
	if( p>0 && p<127 )
	{
		printf("This IP belongs to Class A\n");
		printf("Default Subnet for this IP is 255.0.0.0\n");
		status=1;
	}
	else if( p>=128 && p<=191  )
	{
		printf("This IP belongs to Class B\n");
		printf("Default Subnet is 255.255.0.0\n");
		status=2;
	}
	else if( p>=192 && p<=223 )
	{
		printf("This IP belongs to Class C\n");
		printf("Default Subnet is 255.255.255.0\n");
		status=3;
	}
	else if( p>=224 && p<=239 )
	{
		printf("This IP belongs to Class D\n");
		status=4;
	}
	else if( p>=240 && p<=255 )
	{
		printf("This IP belongs to Class E\n");
		status=5;
	}
	
		
	
	//    Finding Network Address
	
	int bin_r[8],bin_s[16];
	int net_r,net_s;
	
	
	if(status==1)
	{	
		printf("Network Address is %d.%d.%d.%d\n\n",p,0,0,0);	
	}
	
	else if(status==2)
	{
		printf("Network Address is %d.%d.%d.%d\n\n",p,q,0,0);
	}
	
	else if(status==3)
	{
		printf("Network Address is %d.%d.%d.%d\n\n",p,q,r,0);
	}
	
	//  Select 0 or 1 according to your need for subnets and hosts
	
	int min=0,power=0;
	int bits=0;
	int check=0;
	printf("Enter 0 for minimum number of subnets \n");
	printf("Enter 1 for maximum number of hosts per subnet\n");
	cin>>check;
	
	//   Finding  IP Addresse Range of each Subnet and Custom Subnet
	
	int subnets[16],custom_bin[8];
	int custom=0,l=0;
	
	//   For minimum number of subnets 
	
	if(check==0)
	{
	
		printf("Enter minimum number of subnets required\n");
		cin>>min;
	
		for(i=0;i<16;i++)
		{
			power=pow(2,i);
			if(power>=min)
				break;
		}
	
		bits=i;
	
		printf("Minimum number of network bits required are %d\n\n",bits);
		printf("Number of host bits required are %d\n\n",16-bits);
	
		if(bits<8)
		{
			for(i=0;i<power;i++)
			{
			
				convertIntToBinary(i,subnets,bits);
			
				for(j=0;j<bits;j++)
				{
					bin_r[j]=subnets[j];
				}
		
				for(j=bits;j<8;j++)
				{
					bin_r[j]=0;
				}
				net_r=convertBinaryToInt(bin_r,8);
				for(k=0;k<7;k++)
					bin_s[k]=0;
				bin_s[k]=1;
				net_s=convertBinaryToInt(bin_s,8);
			
				for(l=0;l<bits;l++)
					custom_bin[l]=1;
				for(l=bits;l<8;l++)
					custom_bin[l]=0;
				
				custom=convertBinaryToInt(custom_bin,8);
			
				if(i==0)
					printf("Custom subnet is %d.%d.%d.%d\n\n",255,255,custom,0);
				
				printf("%d Subnet address is %d.%d.%d.%d\n",i+1,p,q,net_r,net_s-1);
				printf("IP address of this subnet ranges between %d.%d.%d.%d ",p,q,net_r,net_s-1);
		
				for(j=bits;j<8;j++)
					bin_r[j]=1;
				net_r=convertBinaryToInt(bin_r,8);
				for(k=0;k<7;k++)
					bin_s[k]=1;
				bin_s[k]=0;
				net_s=convertBinaryToInt(bin_s,8);
				printf(" and %d.%d.%d.%d\n\n",p,q,net_r,net_s+1);
			}

		}
	
		if(bits>=8)
		{
			for(i=0;i<power;i++)
			{
			
				convertIntToBinary(i,subnets,bits);
			
				for(j=0;j<8;j++)
				{
					bin_r[j]=subnets[j];
				}
				net_r=convertBinaryToInt(bin_r,8);
			
				for(k=0;k<bits-8;k++)
				{
					bin_s[k]=subnets[j];
					j++;
				}
				for(k=bits-8;k<7;k++)
				{
					bin_s[k]=0;
				}
				bin_s[k]=1;
				net_s=convertBinaryToInt(bin_s,8);
			
				if(i==0)
					printf("Custom subnet is %d.%d.%d.%d\n\n",255,255,255,net_s-1);
			
				printf("%d Subnet address is %d.%d.%d.%d\n",i+1,p,q,net_r,net_s-1);
				printf("IP address of this subnet ranges between %d.%d.%d.%d ",p,q,net_r,net_s-1);
			
				for(k=bits-8;k<7;k++)
				{
					bin_s[k]=1;
				}
				bin_s[k]=0;
				net_s=convertBinaryToInt(bin_s,8);
				printf(" and %d.%d.%d.%d\n\n",p,q,net_r,net_s+1);
			}
		}
	}
	
	//   For minimum number of hosts 
	
	int power1=0;
	if(check==1)
	{
	
		printf("Enter minimum number of hosts required\n");
		cin>>min;
	
		for(i=0;i<16;i++)
		{
			power=pow(2,i);
			if(power>=min)
				break;
		}
		
		bits=i;
		
		int networks=(16-bits);
		power1=pow(2,networks);
		//cout<<power1<<"shams"<<endl;
	
		printf("Minimum number of hosts bits required are %d\n\n",bits);
		printf("Number of networks bits required are %d\n\n",16-bits);
	
		if( (16-bits)<8 )
		{
			for(i=0;i<power1;i++)
			{
			
				convertIntToBinary(i,subnets,16-bits);
			
				for(j=0;j<16-bits;j++)
				{
					bin_r[j]=subnets[j];
				}
		
				for(j=16-bits;j<8;j++)
				{
					bin_r[j]=0;
				}
				net_r=convertBinaryToInt(bin_r,8);
				for(k=0;k<7;k++)
					bin_s[k]=0;
				bin_s[k]=1;
				net_s=convertBinaryToInt(bin_s,8);
			
				for(l=0;l<16-bits;l++)
					custom_bin[l]=1;
				for(l=bits;l<8;l++)
					custom_bin[l]=0;
				
				custom=convertBinaryToInt(custom_bin,8);
			
				if(i==0)
					printf("Custom subnet is %d.%d.%d.%d\n\n",255,255,custom,0);
				
				printf("%d Subnet address is %d.%d.%d.%d\n",i+1,p,q,net_r,net_s-1);
				printf("IP address of this subnet ranges between %d.%d.%d.%d ",p,q,net_r,net_s-1);
		
				for(j=16-bits;j<8;j++)
					bin_r[j]=1;
				net_r=convertBinaryToInt(bin_r,8);
				for(k=0;k<7;k++)
					bin_s[k]=1;
				bin_s[k]=0;
				net_s=convertBinaryToInt(bin_s,8);
				printf(" and %d.%d.%d.%d\n\n",p,q,net_r,net_s+1);
			}

		}
	
		if( (16-bits)>=8 )
		{
			for(i=0;i<power1;i++)
			{
			
				convertIntToBinary(i,subnets,16-bits);
			
				for(j=0;j<8;j++)
				{
					bin_r[j]=subnets[j];
				}
				net_r=convertBinaryToInt(bin_r,8);
			
				for(k=0;k<16-bits-8;k++)
				{
					bin_s[k]=subnets[j];
					j++;
				}
				for(k=16-bits-8;k<7;k++)
				{
					bin_s[k]=0;
				}
				bin_s[k]=1;
				net_s=convertBinaryToInt(bin_s,8);
			
				if(i==0)
					printf("Custom subnet is %d.%d.%d.%d\n\n",255,255,255,net_s-1);
			
				printf("%d Subnet address is %d.%d.%d.%d\n",i+1,p,q,net_r,net_s-1);
				printf("IP address of this subnet ranges between %d.%d.%d.%d ",p,q,net_r,net_s-1);
			
				for(k=16-bits-8;k<7;k++)
				{
					bin_s[k]=1;
				}
				bin_s[k]=0;
				net_s=convertBinaryToInt(bin_s,8);
				printf(" and %d.%d.%d.%d\n\n",p,q,net_r,net_s+1);
			}
		}
	}
	
}
