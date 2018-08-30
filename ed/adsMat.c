#include <stdio.h>

#define MAXR 10
#define MAXC 5

struct TMat{
   int last_row, last_col;
   int mat[MAXR][MAXC];
};

void initMat(struct TMat *m) {
   m->last_row=-1;
   m->last_col=-1;
}

void setMat(struct TMat *m, int value) {
   m->last_col++;
   if (m->last_col>=MAXC)
   {
       m->last_col=0;
       m->last_row++;
   }

   if (m->last_row>=MAXR)
   {
       printf("No available space!\n");
       return;
   }
   if (m->last_row==-1) m->last_row++;
   m->mat[m->last_row][m->last_col]=value;
}

void printMat(struct TMat m) {
    int i,j;
    for (j=0;j<=m.last_row && j<MAXR;j++) {
        if (j==m.last_row) {
            for (i=0;i<=m.last_col;i++) {
               printf(" %d",m.mat[j][i]);
            }
        } else
           for (i=0;i<MAXC;i++)
               printf(" %d",m.mat[j][i]);

        printf("\n");
    }
    return;
}

int getValue(struct TMat m, int value) {
    int i, j;
    for (i = 0; i < m.last_row; i++) {

        if (i == m.last_row) {
            for (j = 0; j < m.last_col; j++) {
                if (m.mat[i][j] == value) {
                    return 1;
                }
            }
        } else {
            for (j = 0; j < MAXC; j++) {
                if (m.mat[i][j] == value) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main()
{
   struct TMat matriz;
   initMat(&matriz);
   for (int i=0;i<27;i++)
      setMat(&matriz,i);
   printMat(matriz);
   printf("\n%d\n", getValue(matriz,10));

   return 0;
}
