#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

class TrafficMinimization{
public:
    int performServerplacement (int client_array[], int size, int k_servers) {
        int len = size;
        int*** a = new int**[len];
        for (int i = 0; i < len; i++) {
        // Allocate memory blocks for
        // rows of each 2D array
            a[i] = new int*[len];
            for (int j = 0; j < len; j++) {
                // Allocate memory blocks for
                // columns of each 2D array
                a[i][j] = new int[k_servers];
                for(int k=0; k< k_servers; k++){
                    a[i][j][k] = 0;
                }
            }
        }
        a = getMatrixForOneServer(client_array, k_servers, a, len);
        // if servers are greater than one then function
        // getMatrixForRestOfServers is called to further server placement
        if(k_servers>1)
            a = getMatrixForRestOfServers(client_array, k_servers, a ,len);
        return a[0][len-1][k_servers];
    }
    
    
    
    int *** getMatrixForOneServer(int client_array[], int k_servers,int ***result, int len){
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < len; j++) {
                int total = 0;
                for(int p = j; p >= i; p--) {
                    total += client_array[p];
                }
                double inter_value = client_array[j];
                int server_position = j;
                while(inter_value <= (total/2.0)) {
                    server_position--;
                    inter_value += client_array[server_position];
                }
                result[i][j][1] = 0;
                for(int m = i; m <= j; m++) {
                    result[i][j][1] += client_array[m] * abs(m - server_position);
                }
            }
        }
        return result;
    }


    int *** getMatrixForRestOfServers(int client_array[], int k_servers,int *** result, int len){
        for(int j = 1; j < len; j++) {
            for(int server_no = 2; server_no <= k_servers && server_no < j+1; server_no++) {
                result[0][j][server_no] = INT_MAX;
                    for(int p = server_no-2; p < j; p++) {
                        result[0][j][server_no] = min(result[0][j][server_no], result[0][p][server_no-1] + result[p+1][j][1]);
                    }
                }
            }
        return result;
    }

};
