//
// Created by liang on 2019/10/20.
//

#ifndef DATASTRUCTURE_HASHTABLE_H
#define DATASTRUCTURE_HASHTABLE_H



#define MAXTABLESIZE 100000   // ���������ٵ����ɢ�б���
typedef int Index;
typedef int ElementType;
typedef Index Position;
typedef enum{   // �ֱ��Ӧ���кϷ�Ԫ�ء��ա�����ɾ��Ԫ��
  Legitimate,Empty,Deleted
} EntryType;  // ���嵥Ԫ״̬����

typedef struct HashEntry Cell;
struct HashEntry{   //  ��ϣ���ֵ��Ԫ
  ElementType Data;  // ���Ԫ��
  EntryType Info;  // ��Ԫ״̬
};

typedef struct HashTbl *HashTable;
struct HashTbl{  // ��ϣ��ṹ��
  int TableSize;   // ��ϣ���С
  Cell *Cells;   // ��ϣ���ֵ��Ԫ����
};

using namespace std;

int NextPrime(int N);  // ��������
HashTable CreateTable( int TableSize); // ������ϣ��
Index Hash(int Key,int TableSize);   // ��ϣ����

// ��������
int NextPrime(int N){
  int p = (N%2)?N+2:N+1;  // �Ӵ��� N ���¸�������ʼ
  int i;

  while(p <= MAXTABLESIZE){
    for(i = (int)sqrt(p);i>2;i--)
      if(!(p%i))  // p ��������
        break;
    if(i==2)
      break;
    p += 2;  // ������̽�¸�����
  }
  return p;
}

// ������ϣ��
HashTable CreateTable( int TableSize){
  HashTable H;
  int i;
  H = (HashTable)malloc(sizeof(struct HashTbl));
  // ��֤��ϣ����󳤶�������
  H->TableSize = NextPrime(TableSize);
  // ��ʼ����Ԫ����
  H->Cells = (Cell *)malloc(sizeof(Cell)*H->TableSize);
  // ��ʼ����Ԫ����״̬
  for(int i=0;i<H->TableSize;i++)
    H->Cells[i].Info = Empty;
  return H;
}

// ƽ��̽�����
// d(i) +1*1 -1*1 +2*2 -2*2 +3*3 -3*3
// cnum   1    2    3    4    5    6
Position Find(HashTable H,ElementType Key){
  Position CurrentPos,NewPos;
  int CNum = 0 ;   // ��¼��ͻ����
  CurrentPos = NewPos = Hash(Key,H->TableSize);
  // �����ǰ��Ԫ״̬��Ϊ�գ�����ֵ���ȣ���һֱ��
  while(H->Cells[NewPos].Info != Empty && H->Cells[NewPos].Data != Key){
    if(++CNum % 2 ){ // ��ͻ�����η���
      NewPos = CurrentPos + (CNum+1)/2*(CNum+1)/2;
      // ���Խ�磬һֱ��ֱ���ٴν���߽�
      while(H->TableSize <= NewPos){
        NewPos -= H->TableSize;
      }
    }else{  // ��ͻż���η���
      NewPos = CurrentPos - CNum/2*CNum/2;
      // ���Խ�磬һֱ��ֱ���ٴν���߽�
      while(NewPos < 0){
        NewPos += H->TableSize;
      }
    }
  }
  return NewPos;
}

// ����
bool Insert( HashTable H,ElementType Key,int i){
  Position Pos = i;
  Pos = Find(H,Key);
  // �����Ԫ��״̬����"���ںϷ�Ԫ��"
  if( H->Cells[Pos].Info != Legitimate){
    H->Cells[Pos].Info = Legitimate;
    H->Cells[Pos].Data = Key;
  }
  return true;
}

// ������������ϣ����
Index Hash(int Key,int TableSize){
  return Key % TableSize;
}


void output(HashTable H){
  for(int i=0;i<H->TableSize;i++)
    cout<<i<<" "<<H->Cells[i].Data<<endl;
}


#endif //DATASTRUCTURE_HASHTABLE_H
