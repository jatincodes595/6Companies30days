// function should print the required range
typedef pair<int,pair<int,int>> ppi;
#include<queue>
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          // create min heap
          // pq --> {val,{row,col}}
      priority_queue <ppi,vector<ppi>,greater<ppi>> pq;
      int m=0;
      for(int i=0;i<k;i++)
      {
          pq.push({arr[i][0],{i,0}});
          m=max(m,arr[i][0]);
      }
      
      // just initialse thr range and left and right values
      // {max-min,{max,min}}
      ppi minRange={m-pq.top().first,{m,pq.top().first}};
      
      while(pq.size()==k)
      {
          ppi curr=pq.top();
          pq.pop();
          
          int curRow=curr.second.first;
          int curCol=curr.second.second;
         
          if(curCol+1 < n)
          {
              //push the ele
              pq.push({arr[curRow][curCol+1],{curRow,curCol+1}});
             
              //update m
              m=max(m,arr[curRow][curCol+1]);
              
              //update minrange
              if(m-pq.top().first<minRange.first)
              minRange={m-pq.top().first,{m,pq.top().first}};
               
          }
      }
     
      return {minRange.second.second,minRange.second.first};
    }
};