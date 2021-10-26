// Shortest remaining time, also known as shortest remaining time first (SRTF), is a scheduling method that is a preemptive version of shortest job next scheduling. In this scheduling algorithm, the process with the smallest amount of time remaining until completion is selected to execute.

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct process{
  int arrivalTime;
  int burstTime;
  int completionTime;
  int turnAroundTime; 
  int waitingTime;
  int btTime;
  int pid;
};

int main(){
  int np=0;
  struct process p;
  vector<process> v;
  vector<process> v1;
  vector<process> completed;
  double waiting_time=0.0,turnaround_time=0.0;
  cout<<"Enter the number of process : "<<endl;
  cin>>np;
  for(int i=0;i<np;i++){
    cout<<"For process : "<<i+1<<endl;
    cout<<"Enter the arrivalTime : "<<endl;
    cin>>p.arrivalTime;
     cout<<"Enter the burstTime : "<<endl;
    cin>>p.burstTime;
    p.btTime = p.burstTime;
    p.pid = i+1;
    v.push_back(p);
  }
    int time=0;
    while(np!=0){
      //filtering out the process
      //for a point of time if there are multiple processes grab them all
      copy_if(v.begin(), v.end(), std::back_inserter(v1), [time](struct process p){return p.arrivalTime == time;} );
      //if the size of the vector is zero it means there are no process to execute
      if(v1.size()!=0){
      //sorting the array based on bursttime .... if the bursttime is same sort according to the arrivaltime
       sort(v1.begin(), v1.end(), 
    [](struct process p1, struct process p2) {
      if(p1.burstTime == p2.burstTime){
        return p1.arrivalTime < p2.arrivalTime;
      }
      return p1.burstTime < p2.burstTime;}
      ); 
       cout<<"At time : "<<time<<endl;
       cout<<"Process id : "<<v1[0].pid<<"  is executing..."<<endl;
       v1[0].burstTime = v1[0].burstTime - 1;
       time++;
       if(v1[0].burstTime == 0){
          v1[0].completionTime = time;
          v1[0].turnAroundTime = v1[0].completionTime - v1[0].arrivalTime;
          v1[0].waitingTime =  v1[0].turnAroundTime -  v1[0].btTime;
          completed.push_back(v1[0]);
          turnaround_time += v1[0].turnAroundTime;
          waiting_time += v1[0].waitingTime;
          v1.erase(v1.begin());
          np--;
       }
      }else{
        cout<<"CPU is idle..."<<endl;
        time++;
      }
    }
  cout<<endl;
  cout<<"Average Waiting Time : "<<(waiting_time/v.size())<<endl;
  cout<<"Average TurnAround Time : "<<(turnaround_time/v.size())<<endl;
  cout<<"Completed Processes : "<<endl;
  for(int i=0;i<completed.size();i++){
    cout<<"For process : "<<completed[i].pid<<endl;
    cout<<"arrivalTime : "<<completed[i].arrivalTime<<endl;
    cout<<"burstTime : "<<completed[i].btTime<<endl; 
    cout<<"turnAroundTime : "<<completed[i].turnAroundTime<<endl; 
    cout<<"waitingTime : "<<completed[i].waitingTime<<endl; 
    cout<<"completionTime : "<<completed[i].completionTime<<endl; 
    cout<<"--------------------------------------------------------"<<endl;
  }
  return 0;
}