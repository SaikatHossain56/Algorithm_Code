#include <iostream> 
#include <chrono> 
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
  
using namespace std; 
using namespace chrono;

int partition(vector<int> &arr, int low, int high, int pivot_choice){

    if(pivot_choice == 2){
        swap(arr[low], arr[high]);
    }
    else if(pivot_choice == 3){
        int mid = (low + high) / 2;
        swap(arr[low], arr[mid]);
    }
    else if(pivot_choice == 4){
        int random_index = low + rand() % (high - low + 1);
        swap(arr[low], arr[random_index]);
    }

    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true){
        while (i <= high && arr[i] <= pivot) i++;

        while (arr[j] > pivot) j--;

        // arr[i] > pivot && arr[j] < pivot
        if (i < j) swap(arr[i], arr[j]);

        else break;
    }

    swap(arr[low], arr[j]);

    return j;
}

void quickSort(vector<int> &arr, int low, int high,int pivot_choice){

    if(low < high){

        int pivot_index = partition(arr, low, high, pivot_choice);

        quickSort(arr, low, pivot_index - 1, pivot_choice);
        quickSort(arr, pivot_index + 1, high, pivot_choice);
    }
}

vector<int> array_generation(int n, int type){

    vector<int> arr;

    if(type == 1){
        for(int i = 1; i <= n; i++){
        arr.push_back(rand());
        }
    }
    else if(type == 2){
        for(int i = 1; i <= n; i++){
            arr.push_back(i);
        }
    }
    else{
        for(int i = n; i >= 1; i--){
            arr.push_back(i);
        }
    }

    return arr;
}

double calculate_time(vector<int> &arr, int pivot_choice){

    auto start = high_resolution_clock::now(); 
    quickSort(arr, 0, arr.size() - 1, pivot_choice);
    auto stop = high_resolution_clock::now(); 

    auto ns = duration_cast<nanoseconds>(stop - start);

    return ns.count();
}

  
int main() { 
    
    srand(time(0));
    const int m = 500;
    cout<<fixed<<setprecision(2);
    cout<<"Enter Input Format: \n 1. Random Array\n 2. Ascending Array\n 3. Descending Array"<<endl;
    int in; 
    cin>>in;
    cout<<"Array Size\tFirst Element\tLast Element\tMiddle Element\tRandom Element"<<endl;
    for(int n = 10; n <= 5000; n += 10){

    double total1 = 0;
    double total2 = 0;
    double total3 = 0;
    double total4 = 0;

    for(int i = 1; i <= m; i++){
        
    vector<int> arr = array_generation(n, in);

    vector<int> arr1 = arr;
    vector<int> arr2 = arr;
    vector<int> arr3 = arr;
    vector<int> arr4 = arr; 
    
    
    total1 += calculate_time(arr1, 1);
    total2 += calculate_time(arr2, 2);
    total3 += calculate_time(arr3, 3);
    total4 += calculate_time(arr4, 4);

    }
    
   double avg1 = total1 / m;
   double avg2 = total2 / m;
   double avg3 = total3 / m;
   double avg4 = total4 / m;

   cout<<n<<"\t"<<avg1<<"\t"<<avg2<<"\t"<<avg3<<"\t"<<avg4<<endl;
    }

    return 0; 
} 