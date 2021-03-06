/*Decimal->deci
Binary->bin
Octal->oct
Hexadecimal->hex*/
#include<stdio.h>
#include<math.h>
#include<string.h>
unsigned long long deci_bin(unsigned long long n)
{
	int i, rem[50];
	unsigned long long bin = 0;
	for(i=0 ; n!=0 ; i++)
	{
		rem[i] = n % 2;
		n = n / 2;
	}
	i--;//i has to be decresed by one as one additional time it has been incremented in previous loop.
	while (i >= 0)
	{
		bin = bin + rem[i] * pow(10, i);
		i--;
	}
	return bin;
}
unsigned long long bin_deci(unsigned long long n)
{
	int i, num[25];
	unsigned long long deci = 0;
	for (i = 0; n != 0; i++)
	{
		num[i] = n % 10;
		n = n/10;
		if (num[i] != 1 && num[i] != 0)//If input has digit other than 0 and 1.  
		{
			printf("\n**INVALID INPUT**");
			return 0;
		}
	}
	i--;//i has to be decresed by one as one additional time it has been incremented in previous loop.
	while (i >= 0)
	{
		deci = deci + num[i] * pow(2, i);
		i--;
	}
	return deci;
}
unsigned long long deci_oct(unsigned long long n)
{
	int i, rem[10], oct = 0;
	for (i = 0; n != 0; i++)
	{
		rem[i] = n % 8;
		n = n / 8;
	}
	i--;//i has to be decresed by one as one additional time it has been incremented in previous loop.
	while (i >= 0)
	{
		oct = oct + rem[i] * pow(10, i);
		i--;
	}
	return oct;
}
void deci_hex(unsigned long long n)
{
	int i, rem[10], hex = 0;
	for (i = 0; n != 0; i++)
	{
		rem[i] = n % 16;
		n = n / 16;
	}
	i--;//i has to be decresed by one as one additional time it has been incremented in previous loop.
	printf("Result is ");
	while (i >= 0)
	{
		if(rem[i]<10)
		printf("%d", rem[i]);
		else
		printf("%c", rem[i] + 55);
		i--;
	}
}//******deci_hex function can not be used in intermediate function as it's return type is void.*******
unsigned long long oct_deci(unsigned long long n)
{
	int i, num[10];
	unsigned long long deci = 0;
	for (i = 0; n != 0; i++)
	{
		num[i] = n % 10;
		n = n / 10;
		if (num[i] == 8 || num[i] == 9)//If input has digit other than 0,1,2,3,4,5,6,7.  
		{
			printf("\n**INVALID INPUT**");
			return 0;
		}
	}
	i--;//i has to be decresed by one as one additional time it has been incremented in previous loop.
	while (i >= 0)
	{
		deci = deci + num[i] * pow(8, i);
		i--;
	}
	return deci;
}
unsigned long long hex_deci(char hex[5])
{
	int num=0,len=0,i,flag=0;
	unsigned long long deci = 0;
	len=strlen(hex);
	len--;//string is basically an array so it's start with 0.
	for (i = 0; hex[i] != NULL; i++)
	{
		if (hex[i] >= '1'&& hex[i] <= '9')

		{
			num = hex[i] - 48; flag = 1;
		}
		else if (hex[i] >= 'A'&& hex[i] <= 'F')
		{
			num = hex[i] - 65 + 10; flag = 1;
		}
		else if (hex[i] >= 'a'&& hex[i] <= 'f')
		{
			num = hex[i] - 97 + 10; flag = 1;
		}
		deci = deci + num * pow(16, len);
		len--;
		if (flag == 0)
		{
			printf("\n**INVALID INPUT**");
			return 0;
		}


	}
	return deci;

}
int main()
{
	int choice = 0, in_type = 0, out_type = 0;
	unsigned long long n = 0, temp1 = 0, result = 0;
	char hex[5];
	do
	{
		printf("Select input data type\nPress:-\n");
		printf("1::Decimal 2::Binary 3::Octal 4::Hexadecimal");
		scanf_s("%d", &in_type);
		printf("\nSelect output data type\nPress:-\n");
		printf("1::Decimal 2::Binary 3::Octal 4::Hexadecimal");
		scanf_s("%d", &out_type);
		gets(hex);
		if (in_type == 4 && out_type == 1)
		{
			printf("Enter input data");
			gets(hex);
		}
		if (in_type == out_type)
			printf("\n**INVALID ENTRY**");
		else if (in_type == 1 && out_type == 2)
		{
			printf("Enter input data");
			scanf_s("%llu", &n);
			result = deci_bin(n);
			printf("Result is %llu", result);
		}
		else if (in_type == 2 && out_type == 1)
		{
			printf("Enter input data");
			scanf_s("%llu", &n);
			if(n==0)//Special case.
			printf("Result is 0");
			result = bin_deci(n);
			if(result!=0)//Function will return 0 in case of invalid input.
			printf("Result is %llu", result);
		}
		else if (in_type == 1 && out_type == 3)
		{
			printf("Enter input data");
			scanf_s("%llu", &n);
			result = deci_oct(n);
			printf("Result is %llu", result);
		}
		else if (in_type == 1 && out_type == 4)
		{
			printf("Enter input data");
			scanf_s("%llu", &n);
			deci_hex(n);
		}
		else if (in_type == 2 && out_type == 3)
		{
			printf("Enter input data");
			scanf_s("%llu", &n);
			temp1 = bin_deci(n);//Bin->deci->oct.
			result = deci_oct(temp1);
			if (result != 0)//Function will return 0 in case of invalid input.
			printf("Result is %llu", result);
		}
		else if (in_type == 2 && out_type == 4)
		{
			printf("Enter input data");
			scanf_s("%llu", &n);
			temp1 = bin_deci(n);//Bin->deci->hexa.
			if (temp1 != 0)//Function will return 0 in case of invalid input.
			deci_hex(temp1);
		}
		else if (in_type == 3 && out_type ==1)
		{
			printf("Enter input data");
			scanf_s("%llu", &n);
			result = oct_deci(n);
			if (result != 0)//Function will return 0 in case of invalid input.
			printf("Result is %llu", result);
		}
		else if (in_type == 3 && out_type == 4)
		{
			printf("Enter input data");
			scanf_s("%llu", &n);
			temp1 = oct_deci(n);//Bin->deci->hexa.
			if (temp1 != 0)//Function will return 0 in case of invalid input.
			deci_hex(temp1);
		}
		else if (in_type == 3 && out_type == 2)
		{
			printf("Enter input data");
			scanf_s("%llu", &n);
			temp1 = oct_deci(n);//Bin->deci->hexa.
			result = deci_bin(temp1);
			if (result != 0)//Function will return 0 in case of invalid input.
			printf("Result is %llu", result);
		}
		else if (in_type == 4 && out_type == 1)
		{
			result = hex_deci(hex);
			if (result != 0)//Function will return 0 in case of invalid input.
			printf("Result is %llu", result);
		}
		else if (in_type == 4 && out_type == 2)
		{
			printf("Enter input data");
			gets(hex);
			temp1 = hex_deci(hex);
			result = deci_bin(temp1);
			if (result != 0)//Function will return 0 in case of invalid input.
			printf("Result is %llu", result);
		}
		else if (in_type == 4 && out_type == 3)
		{
			printf("Enter input data");
			gets(hex);
			temp1 = hex_deci(hex);
			result = deci_oct(temp1);
			if (result != 0)//Function will return 0 in case of invalid input.
			printf("Result is %llu", result);
		}
		printf("\n\nTo again execute program press 1\nTo EXIT press 0");
		scanf_s("%d", &choice);
		printf("\n-----------------------------------------------------------------------------------------------------\n");
	} while (choice != 0);
	return 0;
}
