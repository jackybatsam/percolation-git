#include <stdio.h>
#include <stdlib.h>
#define N 8

void add(int*, int*, int*);
void subtract(int*, int*, int*);
void multiply(int*, int, int*);
void divide(int*, int, int*);
void toComp(int*, int*);  // 轉補數
void absv(int*, int*);    // 轉絕對值
void print(int*);         // 顯示大整數

long value[6] = {
3, 5217223242,//(3053201612,2164021630)
4, 4726100874,
5, 4368232009
};

int main(){
	/*long number, a=3053201612, b=2164021630; 

	number = a+b;
	
	printf("number = %lu", number);
*/
    int a[] = {0, 0, 0, 1234, 5678, 9910, 1923, 1124};
    int b[] = {9999, 9999, 9999, 9999, 9999, 9999, 9999, 9901}; // -99
    int c1[N], c2[N], c3[N], c4[N], c5[N] = {0};
	int a1[] = {0,0,0,0,0,62,682,1033};
	int a2[] = {0,0,0,0,0,56,1708,9148};
	int a3[] = {0,0,0,0,0,52,1722,3242};
	int a4[] = {0,0,0,0,0,47,2610,874};
	int a5[] = {0,0,0,0,0,43,6823,2009};
	int d1[N],d2[N],d3[N],d4[N] = {0};

    //add(a, b, c1);       print(c1);
   // subtract(a, b, c2);  print(c2);
	multiply(a1, 144, c1); print(c1);
	multiply(a2, 39, c2); print(c2);
	multiply(a3, 45, c3); print(c3);
	multiply(a4, 34, c4); print(c4);
	multiply(a5, 38, c5); print(c5);

	add(c1,c2,d1); print(d1);
	add(d1,c3,d2); print(d2);
	add(d2,c4,d3); print(d3);
	add(d3,c5,d4); print(d4);
	
   // divide(a, -3, c4);   print(c4);

	return 0;
}


void add(int* a, int* b, int* c) { 
    if(b[0] == 9999) {
        int comp[N] = {0};
        toComp(b, comp);
        subtract(a, comp, c);
    } else {
        int i, carry = 0; 
        for(i = N - 1; i >= 0; i--) {
            c[i] = a[i] + b[i] + carry; 
            if(c[i] < 10000) {
                carry = 0; 
            } else { // 進位 
                c[i] = c[i] - 10000; 
                carry = 1; 
            } 
        } 
    }
} 

void subtract(int* a, int* b, int* c) {
    if(b[0] == 9999) {
        int comp[N] = {0};
        toComp(b, comp);
        add(a, comp, c);
    } else {
        int i, borrow = 0; 
        for(i = N - 1; i >= 0; i--) { 
            c[i] = a[i] - b[i] - borrow; 
            if(c[i] >= 0) {
                borrow = 0;
            } else { // 借位 
                c[i] = c[i] + 10000; 
                borrow = 1; 
            } 
       } 
    }
} 

void multiply(int* a, int b, int* c) { // b 為乘數
    int op1[N] = {0}; absv(a, op1);
    int op2 = abs(b);

    int i, tmp, carry = 0; 
    for(i = N - 1; i >= 0; i--) { 
        tmp = op1[i] * op2 + carry; 
        c[i] = tmp % 10000;    
        carry = tmp / 10000; 
    }
    
    if((a[0] == 9999 && b > 0) || (a[0] == 0 && b < 0)) {
        toComp(c, c);
    }
} 

void divide(int* a, int b, int *c) {  // b 為除數 
    int op1[N] = {0}; absv(a, op1);
    int op2 = abs(b);
    
    int i, tmp, remain = 0; 
    for(i = 1; i < N; i++) { 
        tmp = op1[i] + remain; 
        c[i] = tmp / op2; 
        remain = (tmp % op2) * 10000; 
    }

    if((a[0] == 9999 && b > 0) || (a[0] == 0 && b < 0)) {
        toComp(c, c);
    }    
}

void toComp(int* src, int* comp) {
    int j;
    for(j = 0; j < N; j++) {
        comp[j] = 9999 - src[j];
    }
    comp[N - 1] += 1;
}

void absv(int* src, int* op) {
    if(src[0] == 9999) {
        toComp(src, op);
    } else {
        int i;
        for(i = 0; i < N; i++) {
            op[i] = src[i];
        }
    }
}

void print(int* c) {
    int v[N] = {0}; absv(c, v);
    
    if(c[0] == 9999) {
        printf("-");
    }
    
    int isDropZero = 1;
    int i;
    for(i = 0; i < N; i++) {
        char s[5] = {'\0'};
        sprintf(s, "%04d", v[i]);
        if(isDropZero) {
            int j;
            for(j = 0; s[j] == '0' && j < 4; j++);
            if(j < 4) {
                isDropZero = 0;
                for(; j < 4; j++) {
                    printf("%c", s[j]);
                }
            } else if(i == N - 1) {
                printf("0");
            }
        } else {
            printf("%s",s);
        }
    }
    printf("\n");
}

