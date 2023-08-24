#include <iostream>
using namespace std;

int *gpVect = NULL;  
int gnCount = 0;
int gnMax = 0;

struct Vector {
    int* m_pVect;  // Pointer to the buffer
    int m_nCount;  // Control how many elements are actually used
    int m_nMax;    // Control how many are allocated as maximum
    int m_nDelta;  // To control the growing
};

void Resize(Vector *pThis) {
    pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));  // The Max has to be increased by delta
    pThis->m_nMax += pThis->m_nDelta;
}

void Insert(Vector *pThis, int elem) {
    if (pThis->m_nCount == pThis->m_nMax)    // Verify the overflow
        Resize(pThis);
    pThis->m_pVect[pThis->m_nCount++] = elem;
}

int main() {
  Vector *vc = new Vector;
  vc->m_pVect = gpVect;
  vc->m_nCount = gnCount;
  vc->m_nMax = gnMax;
  vc->m_nDelta = 10;
  for(int j=0; j < 100; j++)
  {
  	Insert(vc, j);
  	cout<<vc->m_pVect[j] <<" ";
  }
}