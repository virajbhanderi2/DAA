#include<stdio.h>
#include<stdlib.h>
#define V 7
#define SIZE 100


int Queue[SIZE];
int rear = -1;
int front =-1;

void enque(int val){
    if(rear == SIZE-1){
        printf("Queue Overflow/n");
        return;
    }else{
        if(front == -1){
            front = 0;
        }
        Queue[++rear]=val;
       return; 
    }
}
int  deque(){
    if(front == -1 || front>rear){
        printf("Queue Underflow\n");
    }else{
        
        return Queue[front++];
    }
}
int isEmpty(){
    if(front==-1 || front>rear){
        return 0;
    }
    return 1;
}
void bfs(int graph[V][V]){
    int visited[V]={0};

    visited[0]=1;
    enque(0);

    while(isEmpty()){
        int u=deque();
        printf("%d\n",u+1);
        for(int i=0;i<V;i++){
            if(visited[i]==0 && graph[u][i]!=0){
                visited[i]=1;
                enque(i);
            }
        }
    }
}

void main(){
    int graph[V][V]={
        {0,1,0,1,0,0,0},
        {1,0,1,1,0,0,0},
        {0,1,0,0,1,1,0},
        {1,1,0,0,1,0,1},
        {0,0,1,1,0,1,1},
        {0,0,1,0,1,0,1},
        {0,0,0,1,1,1,0}
    };
    bfs(graph);
}