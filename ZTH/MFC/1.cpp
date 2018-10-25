#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(){
	union{
		int i;
		char s[4];
	}b;
	int a;
	b.i=0x123456;
	a=0x12345678;
	while(1);
	return 0;
}