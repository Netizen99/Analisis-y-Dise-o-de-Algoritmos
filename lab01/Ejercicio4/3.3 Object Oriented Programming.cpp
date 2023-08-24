#include <iostream>
using namespace std;

class CVector
{
private:
    int* m_pVect;  // Pointer to the buffer
    int m_nCount;  // Control how many elements are actually used
    int m_nMax;    // Control how many are allocated as maximum
    int m_nDelta;  // To control the growing
    void Init(int delta);   // Init our private variables, etc
    void Resize();          // Resize the vector when an overflow occurs
public:
    CVector(int delta = 10);  // Constructor
    void Insert(int elem);    // Insert a new element
};

CVector::CVector(int delta) {
    Init(delta);
}

void CVector::Init(int delta) {
    m_pVect = new int[delta];
    m_nCount = 0;
    m_nMax = delta;
    m_nDelta = delta;
}

void CVector::Resize() {
    int* newVect = new int[m_nMax + m_nDelta];
    for (int i = 0; i < m_nCount; ++i) {
        newVect[i] = m_pVect[i];
    }
    delete[] m_pVect;
    m_pVect = newVect;
    m_nMax += m_nDelta;
}

void CVector::Insert(int elem) {
    if (m_nCount == m_nMax)
        Resize();
    m_pVect[m_nCount++] = elem;
}

int main() {
    CVector myVector; 
    
    for (int i = 0; i < 100; ++i) {
        myVector.Insert(i);  
        cout<<" "<<i;
    }
    
    
    return 0;
}