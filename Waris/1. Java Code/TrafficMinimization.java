public class TrafficMinimization{
    public int performServerplacement (int[] client_array, int k_servers) {
        int len = client_array.length;
        int[][][] result = getMatrixForOneServer(client_array, k_servers,
        new int[len][len][k_servers+1], len);
        // if servers are greater than one then function
        // getMatrixForRestOfServers is called to further server placement
        if(k_servers>1)
            result = getMatrixForRestOfServers(client_array, k_servers, result,len);
        return result[0][len-1][k_servers];
    }
    //to calculate values when server is equal to 1
    public int[][][] getMatrixForOneServer(int[] client_array, int k_servers,int[][][] result, int len){
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
                    result[i][j][1] += client_array[m]*Math.abs(m - server_position);
                }
            }
        }
        return result;
    }
    // to calculate values when server are more than 1
        public int[][][] getMatrixForRestOfServers(int[] client_array, int k_servers,int[][][] result, int len){
            for(int j = 1; j < len; j++) {
                for(int server_no = 2; server_no <= k_servers && server_no < j+1;
                server_no++) {
                result[0][j][server_no] = Integer.MAX_VALUE;
                    for(int p = server_no-2; p < j; p++) {
                        result[0][j][server_no] = Math.min(result[0][j][server_no],
                        result[0][p][server_no-1] + result[p+1][j][1]);
                    }
                }
            }
            return result;
        }
    }
