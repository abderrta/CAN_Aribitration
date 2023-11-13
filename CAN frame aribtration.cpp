/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//this code is dedecate to the arbitration operation in CAN protocol


#include <iostream>
using namespace std;


int a = 0;
	
class CAN  {
   
   public:
   
   int frameCAN[76];

   
   
   public:
   
   void setelement(){
       cout<<"give me your frameCAN"<<endl;
       

       for (int i=1;i<14 ;i++){
           
           cin>>frameCAN[i];
           
       }
   }
   
   void displayID(){
       for (int i=1;i<14 ;i++){
           cout<<frameCAN[i] <<" " ;
       }
       cout<<endl ;
   }
   
   friend void RTRarbitration(CAN  node1,CAN  node2);

   friend void IDarbitration(CAN  node1,CAN  node2);
   
   friend void arbitrationIDE(CAN  node1,CAN  node2);
};

void arbitrationIDE(CAN  node1,CAN  node2){
    
    if(node1.frameCAN[13] ==0 && node2.frameCAN[13]==1 ){
        cout<<"the node1 one is standars and win the arbitration"<<endl;
    }
    if(node1.frameCAN[13] ==1 && node2.frameCAN[13]==0){
        cout<<"the node2 one is standars and win the arbitration"<<endl;
    }
    if ((node1.frameCAN[13]==0 && node2.frameCAN[13]==0) || (node1.frameCAN[13]==1 && node2.frameCAN[13]==1)){
        RTRarbitration(node1,node2);
        
    }
    
    
}

void RTRarbitration(CAN  node1,CAN  node2){
    if (node1.frameCAN[12] ==0 && node2.frameCAN[12]==1 ){
        cout<<"the node1 one has the arbitration"<<endl;
    }
    if (node1.frameCAN[12] ==1 && node2.frameCAN[12]==0 ){
        cout<<"the node2 one has the arbitration"<<endl;
    }
    if ((node1.frameCAN[12] ==0 && node2.frameCAN[12]==0 ) || (node1.frameCAN[12] ==1 && node2.frameCAN[12]==1 )){
        IDarbitration(node1,node2);
    }
}

void IDarbitration(CAN  node1,CAN  node2){
    int compter=0;
    
    for (int i=1;i<12 ;i++){
        
        if ((node1.frameCAN[i]==0 && node2.frameCAN[i]==0) || (node1.frameCAN[i]==1 && node2.frameCAN[i]==1)){
            compter++;
            if (compter==12){
                cout<<"the node1 & node2 has some arbitration"<<endl;
                
            }
        }   
        if (node1.frameCAN[i]==0 && node2.frameCAN[i]==1){
            cout<<"the node1 one has the arbitration"<<endl;
            
            break;
        }
        
        if (node2.frameCAN[i]==0 && node1.frameCAN[i]==1){
            cout<<"the node2 one has the arbitration"<<endl;
            
            break;
        }

    }
    
}


int main()
{
    CAN  node1;
    CAN  node2;
    node1.setelement();
    node2.setelement();
    node1.displayID();
    node2.displayID();
    arbitrationIDE(node1,node2);

    return 0;
}
