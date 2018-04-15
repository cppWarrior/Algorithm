#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
#include<cmath>

using namespace std;

int v_coord[500][2];
int parent[500];
int find(int i);

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int V,S; // outpost and satelite
        scanf("%d %d",&S,&V);
        
        memset(v_coord,0,sizeof(v_coord));
        
        for(int i=0;i<V;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            v_coord[i][0] = x;
            v_coord[i][1] = y;
        }
        
        vector<pair<double,pair<int,int>>> edgeList;
        
        for(int i=0;i<V;i++){
            int first_x = v_coord[i][0];
            int first_y = v_coord[i][1];
            for(int j=i-1;j>=0;j--){
                int second_x = v_coord[j][0];
                int second_y = v_coord[j][1];
                double dis = sqrt(pow(first_x - second_x,2) + pow(first_y - second_y,2));
                //printf("%f ",dis);
                edgeList.push_back(make_pair(dis,pair<int,int>(i,j)));
            }
        }
        
        sort(edgeList.begin(),edgeList.end());
        
        memset(parent,0,sizeof(parent));
        for(int i=0;i<500;i++){
            parent[i] = i;
        }
        
        int flag = V-S; // ends at (edges - satelite number)
        for(int i=0;i<V*(V-1);i++){
            pair<double,pair<int,int>> front = edgeList[i];  
            int first_vp = find(front.second.first);
            int second_vp = find(front.second.second);
            
            if(first_vp == second_vp)
                continue;
            parent[first_vp] = second_vp;
            flag--;
            if(flag==0){
                printf("%.2f\n",front.first);
                break;
            }
        }
    }
}

int find(int i){
    return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
}
