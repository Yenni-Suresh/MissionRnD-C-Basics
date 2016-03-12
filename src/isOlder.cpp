/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int find(char *dob1, char *dob2, int *d1, int *d2, int *m1, int *m2, int *y1, int *y2)
{
	int i = 0, p = 10;
	while (i < 2)
	{
		if (dob1[i] == '\0'||dob2[i] =='\0')
			return -1;
		*d1 = *d1 + (dob1[i] - 48) * p;
		*d2 = *d2 + (dob2[i] - 48) * p;
		i++;
		p = p / 10;
	}
	i++;
	p = 10;
	while (i < 5)
	{
		if (dob1[i] == '\0' || dob2[i] == '\0')
			return -1;
		*m1 = *m1 + (dob1[i] - 48) * p;
		*m2 = *m2 + (dob2[i] - 48) * p;
		i++;
		p = p / 10;
	}
	i++;
	p = 1000;
	while (i < 10)
	{
		if (dob1[i] == '\0' || dob2[i] == '\0')
			return -1;
		*y1 = *y1 + (dob1[i] - 48) * p;
		*y2 = *y2 + (dob2[i] - 48) * p;
		i++;
		p = p / 10;
	}
}

int isOlder(char *dob1, char *dob2) {

	int i,d1=0,d2=0,m1=0,m2=0,y1=0,y2=0,l1=0,l2=0,result;
	result=find(dob1, dob2,&d1,&d2,&m1,&m2,&y1,&y2);
	if (result == -1)
		return -1;
	if (y1 == 0 || y2 == 0 || m1 == 0 || m2 == 0 || d1 == 0 || d2 == 0 || y2 > 9999 || y1 > 9999 || m1 > 12 || m2 >12 )
		return -1;
	if (m1 == 2 || m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)
	{
		if (y1 % 4 == 0 && m1 == 2)
		{
			if (d1 > 29)
				return -1;
		}
		else if (m1 == 2 && d1 > 28)
			return -1;
		else if (d1 > 30)
			return -1;
	}
	else if (d1 > 31)
		return - 1;
	if (m2 == 2 || m2 == 4 || m2 == 6 || m2 == 9 || m2 == 11)
	{
		if (y2 % 4 == 0 && m2 == 2)
		{
			if (d2 > 29)
				return -1;
		}
		else if (m2 == 2 && d2 > 28)
			return -1;
		else if (d2 > 30)
			return -1;
	}
	else if (d2 > 31)
		return -1;
	if (y1 < y2)
		return 1;
	else if (y2 < y1)
		return 2;
	else if (m1 < m2)
		return 1;
	else if (m2 < m1)
		return 2;
	else if (d1 < d2)
		return 1;
	else if (d2 < d1)
		return 2;
	else return 0;
}

