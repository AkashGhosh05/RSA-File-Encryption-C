#include<stdio.h>
#include<string.h>
int gcd(int a, int b)
{
    int temp;
    while(1)
    {
        temp=a%b;
        if (temp==0)
          return b;
        a=b;
        b=temp;
    }
}
unsigned long long mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod) 
{
    unsigned long long result = 1;
    base %=mod;
    while (exp>0) 
	{
        if (exp%2==1)
            result=(result*base)%mod;
        exp>>=1;
        base=(base*base)%mod;
    }
    return result;
}
int main()
{
	char filename[100], text[1000];
	//RSA
	unsigned long long p=353, q=367, i,c, d, e=3, pk;
	unsigned long long n=p*q, prod=(p-1)*(q-1);
    while (e<prod)
    {
        if (gcd(e,prod)==1)
            break;
        else
            e++;
    }
    int k=2;
    do
    {
        d=(1+(k*prod))/e;
        if(d==(int)d)
            break;
        else
            k++;
    }while(k<d);
    int x;
    while(1)
    {
    	printf("MENU:\n1.Encryption\n2.Decryption\n3.Exit\nEnter Your Choice:");
    	scanf("%d",&x);
    	getchar();
    	switch(x)
		{
    		case 1://encryption
    			printf("Enter the filename: ");
            	fgets(filename, 100, stdin);
   			 	filename[strcspn(filename,"\n")]=0;
				FILE *f1=fopen(filename, "r+");
				if (!f1) 
				{
        			printf("Could not open file.\n");
        			return 1;
    			}
    			FILE *fe = fopen("Encrypted.txt", "w+");
    			while (fgets(text, sizeof(text), f1))
    			{
    				for(i=0;text[i]!='\0';i++)
    				{
    					c=mod_exp((unsigned long long)text[i],e,n);
        				fprintf(fe,"%llu ",c);
					}
				}
    			printf("Your Private Key is: %llu\n",d);
				printf("Encryption Done\n");
				fclose(fe);
    			fclose(f1);
    			break;
    		case 2://decryption
    			printf("Enter the filename: ");
            	fgets(filename, 100, stdin);
    			filename[strcspn(filename,"\n")]=0;
            	FILE *f2=fopen(filename, "r+");
				if (!f2) 
				{
        			printf("Could not open file.\n");
        			return 1;
    			}
    			printf("Enter Your Private Key:\n");
    			scanf("%llu",&pk);
    			if(pk!=d)
    			{
    				printf("Wrong Key");
    				break;
				}
    			i=0;
    			while (fscanf(f2,"%llu",&c)==1) 
				{
        			unsigned long long m = mod_exp(c,pk,n);
        			text[i++]=(char)m;
    			}
    			text[i]='\0';
    			FILE *fd = fopen("Decrypted.txt", "w+");
    			fprintf(fd,"%s",text);
    			printf("Decryption Done\n");
    			fclose(fd);
    			fclose(f2);
    			break;
    		case 3:
    			exit(0);
    		default:
    			printf("INVALID INPUT");
		}
	}
}

