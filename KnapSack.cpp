#include <bits/stdc++.h>
using namespace std;

int numItems, value, size, bpSize, listLength;
int values[100][100];



struct Item
{
    int id;
    int value;
    int size;
    char name[20];



}items [1000];


void printItem(Item current){
    cout<<"Item name: "<<current.name<<"\n";
    cout<<"Item value: "<<current.value<<"\n";
    cout<<"Item size: "<<current.size<<"\n";
    cout<<"Item id: "<<current.id<<"\n\n";


}

void printArray(int numbers[100][100]){
    for(int i = 0; i < listLength; i++){ 
        cout<<"\n";
        for(int j = 1; j <= bpSize; j++){
            cout<<numbers[i][j]<<" ";
        }
    }

}




int main(){

    cout<<"What size is your knapsack"<<"\n";
    cin>>bpSize;
    cout<<"How many items are available"<<"\n";
    cin>>listLength;

    


    for(int i = 0; i < listLength; i++){
        char temp[20];
        items[i].id = i;
        cout<<"Enter the name of item "<<i+1<<"\n";
        cin>>temp;
        strcpy(items[i].name, temp);
        cout<<"Enter the value of item "<<i+1<<"\n";
        cin>>items[i].value;
        cout<<"Enter the size of item "<<i+1<<"\n";
        cin>>items[i].size;
        
        

    }
    // for(int i = 0; i < listLength; i++){
        
    //     printItem(items[i]);
    // }
        for(int i = 0; i < listLength; i++){ //current item index
            for(int j = 1; j <= bpSize; j++){ //current size being tested
                if(items[i].size == j){ //item
                    
                    int max = items[i].value;
                    if(i > 0)
                    {
                        if(values[i-1][j] >= max){
                            max = values[i-1][j];
                        }
                    }
                    if(j > 0)
                    {
                        if(values[i][j-1] >= max){
                            max = values[i][j-1];
                        }
                    }
                    values[i][j] = max;
                    
                }
                else if (items[i].size > j){ //items dont fit in the size
                int max = 0;
                    if(i > 0)
                    {
                        if(values[i-1][j] >= max){
                            max = values[i-1][j];
                        }
                    }
                    if(j > 0)
                    {
                        if(values[i][j-1] >= max){
                            max = values[i][j-1];
                        }
                    }
                    values[i][j] = max;

                }
                else if(items[i].size < j){//items fit with room to spare
                    int max = items[i].value;
                if (i > 0) {
                    max = max + values[i - 1][j - items[i].size];
                    max = max > values[i - 1][j] ? max : values[i - 1][j];
                }
                values[i][j] = max;
                }
            }
        }
    



//top based on bpsize => all weights possible
//left iterates through items 1 by 1
    printArray(values);


    return 0;
}