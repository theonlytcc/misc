// StLtry.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"

#ifndef _TCCIOSTREAM_
#include <iostream>
#define _TCCIOSTREAM_
#endif
#ifndef _TCCSTRING_
#include <string>
#define _TCCSTRING_
#endif
#ifndef _TCCALGORITHM_
#define _TCCALGORITHM_
#include <algorithm>
#endif
#include "how_vector.h"
#include "AboutC11.h"
#define Tomychar(x) #x
#include <stdio.h>
#include <malloc.h>

using namespace std;

int main()
{
	int* ptrInt = NULL;
	int lenOne = 0, lenTwo = 0,frtflag=0,iOne=0,iTwo=0;
	char inNumone[1000] = { 0 }, inNumtwo[1000];
	while (scanf("%s %s", inNumone, inNumtwo)!=NULL) {
		lenOne = strlen(inNumone);
		lenTwo = strlen(inNumtwo); 
		ptrInt = (int*)malloc(sizeof(int)*(lenOne + lenTwo));
		if (ptrInt != NULL) {
			for (int i = 0; i < (lenOne + lenTwo); i++) {
				iOne=*(inNumone+(lenOne-i-1))
			}
			for (int i = (lenOne + lenTwo - 1); i >= 0; i--) {
				if (frtflag == 0) {
					if (*(ptrInt + i) != 0) {
						frtflag = 1;
						printf("%d", *(ptrInt + i));
					}
				}else {
					printf("%d", *(ptrInt + i));
				}
			}
			printf("\n");
			frtflag = 0;
			free(ptrInt);
			ptrInt = NULL;
		}else {
			printf("error memory\n");
		}
	}
    return 0;
}

