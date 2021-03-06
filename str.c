int my_strcmp(const char *X, const char *Y)
{
	while(*X)
	{
		// if characters differ or end of second string is reached
		if (*X != *Y)
			break;

		// move to next pair of characters
		X++;
		Y++;
	}
	// return the ASCII difference after converting char* to unsigned char*
	return *(const unsigned char*)X - *(const unsigned char*)Y;
}

int my_strlen(const char *str)
{
    int len;
    for (len = 0; str[len]; len++);
    return len;
}

void my_strset(char *str, char rep, int size)
{
    int i;
    for(i=0;i<size;i++)
        str[i]=rep;
}

void str_reverse(char str[], int length)
{
    int start = 0; 
    int end = length -1; 
    char tmp;
    while (start < end) 
    { 
        tmp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = tmp;
        start++; 
        end--; 
    } 
}

void my_itoa(int num, char *str, int base)
{
    // int i = 0;
    // short neg=0;
    // int rem;
    // if (num == 0) 
    // { 
    //     str[i++] = '0'; 
    //     str[i] = '\0'; 
    //     return; 
    // } 
    // if (num < 0 && base==10)
    // {
    //     neg=1;
    //     num=-num;
    // }
    // while (num != 0) 
    // { 
    //     rem = num % base; 
    //     str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
    //     num = num/base; 
    // } 
    // if (neg) 
    //     str[i++] = '-'; 
    // str[i] = '\0';
    // str_reverse(str, i); 

}

void my_strcat(char *dst, char *src)
{
    char *ptr = dst + my_strlen(dst);
    while(*src != '\0')
        *ptr++ = *src++;
    *ptr='\0';
}

long my_atoi(const char* S)
{
	long num = 0;

	int i = 0;
	
	// run till we have reached end of the string or
	// current character is non-numeric
	while (S[i] && (S[i] >= '0' && S[i] <= '9'))
	{
		num = num * 10 + (S[i] - '0');
		i++;
	}

	return num;
}