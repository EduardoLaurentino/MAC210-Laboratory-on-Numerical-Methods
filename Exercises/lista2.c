#include<stdio.h>
#include<math.h>
/**
 * P*A = L*U
 * P = permutation matrix
 * L = lower triangular
 * U = upper triangular
 */
void perm(float dest[3][3], float src[3][3], int n, float p[3][3]) {
  
}
void palu(float a[3][3], int n, float p[3]) {
  for (int k = 0; k < n; k++)
    for (int i = k + 1; i < n; i++) {
      float l_ik = a[i][k]/a[k][k];

      a[i][k] = l_ik;
      
      for (int j = k + 1; j < n; j++)
        a[i][j] = a[i][j] - l_ik * a[k][j];
    }
}

void gauss(float a[3][3], int n) {
  for (int k = 0; k < n; k++)
    for (int i = k + 1; i < n; i++) {
      float l_ik = a[i][k]/a[k][k];

      a[i][k] = l_ik;
      
      for (int j = k + 1; j < n; j++)
        a[i][j] = a[i][j] - l_ik * a[k][j];
    }
}

void cholesky(float a[3][3], int n) {
  for (int k = 0; k < n - 1; k++) {
    a[k][k] = sqrt(a[k][k]);
    for (int i = k + 1; i < n; i++)
      a[i][k] = a[i][k]/a[k][k];
   
    for (int j = k + 1; j < n; j++)
      for (int i = j; i < n; i++)
        a[i][j] = a[i][j] - a[i][k]*a[j][k];

  }
  a[n-1][n-1] = sqrt(a[n-1][n-1]);
}
int main() {
  float m[3][3] = {
    { 6,  15,  55},
    { 15,55,  225},
    { 55,  225,  979}
  };
  int n = 3;
  gauss(m, n);
  //cholesky(m,n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%.1f ", m[i][j]);
    printf("\n");
  }
  
  return 0;
}