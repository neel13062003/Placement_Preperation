#include <vector>
#define ll long long
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& q) {
        vector<bool> rowFlag(n, 1), colFlag(n, 1);
        ll ans = 0;
        ll rowRemain = n, colRemain = n;
        for(int i = q.size()-1; i >= 0; --i){
            if(q[i][0] == 0 && rowFlag[q[i][1]]){ 
                ans += colRemain * q[i][2];  
                rowFlag[q[i][1]] = 0;
                rowRemain--;
            }
            if(q[i][0] == 1 && colFlag[q[i][1]]){
                ans += rowRemain * q[i][2];
                colFlag[q[i][1]] = 0;
                colRemain--;
            }
        }
        return ans;
    }
}; 

//12 + 6 + 4

// #include <vector>

// class Solution {
// public:
//     long long matrixSumQueries(int n, std::vector<std::vector<int>>& queries) {
//         std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        
//         for (const auto& query : queries) {
//             int type = query[0];
//             int index = query[1];
//             int value = query[2];
            
//             if (type == 0) {
//                 for (int j = 0; j < n; j++) {
//                     matrix[index][j] = value;
//                 }
//             } else {
//                 for (int i = 0; i < n; i++) {
//                     matrix[i][index] = value;
//                 }
//             }
//         }
        
//         long long sum = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 sum += matrix[i][j];
//             }
//         }
        
//         return sum;
//     }
// };


// #include <vector>
// #include <utility>

// #define ll long long

// class Solution {
// public:
//     long long matrixSumQueries(int n, std::vector<std::vector<int>>& q) {
//         std::vector<std::vector<std::pair<ll, ll>>> row1(n, std::vector<std::pair<ll, ll>>(n));
//         std::vector<std::vector<std::pair<ll, ll>>> col1(n, std::vector<std::pair<ll, ll>>(n));

//         std::vector<std::vector<std::pair<ll, ll>>> col2(n, std::vector<std::pair<ll, ll>>(n));

//         ll sum = 0;

//         for(int i = 0; i < q.size(); i++) {
//             int roworcol = q[i][0];
//             int which = q[i][1];
//             int val = q[i][2];

//             std::pair<ll, ll> p = {val, i};       // {val,position}

//             // Row
//             if(roworcol == 0) {
//                 for(int j = 0; j < n; j++) {
//                     row1[which][j].first = p.first;
//                     row1[which][j].second = p.second;
//                 }
//             }
//             // Col
//             else if(roworcol == 1) {
//                 for(int j = 0; j < n; j++) {
//                     col1[which][j].first = p.first;
//                     col1[which][j].second = p.second;
//                 }
//             }
//         }

//         // Transpose of col1 matrix
//         for(ll i = 0; i < n; i++) {
//             for(ll j = 0; j < n; j++) {
//                 col2[j][i] = col1[i][j];
//             }
//         }

//         for(ll i = 0; i < n; i++) {
//             for(ll j = 0; j < n; j++) {
//                 if(col2[i][j].second > row1[i][j].second) {
//                     sum += col2[i][j].first;
//                 }
//                 else if(col2[i][j].second < row1[i][j].second){
//                     sum += row1[i][j].first;
//                 }
//             }
//         }

//         return sum;

//     }
// };



// #include <vector>
// #include <utility>

// #define ll long long

// class Solution {
// public:
//     long long matrixSumQueries(int n, vector<vector<int>>& q) {
//         vector<vector<pair<ll, ll>>> row1(n, vector<pair<ll, ll>>(n));
//         vector<vector<pair<ll, ll>>> col1(n, vector<pair<ll, ll>>(n));
        
//         vector<vector<pair<ll, ll>>> col2(n, vector<pair<ll, ll>>(n));
        
//         ll sum = 0;
        
//         for(int i = 0; i < q.size(); i++) {
//             int roworcol = q[i][0];
//             int which = q[i][1];
//             int val = q[i][2];
            
//             pair<ll, ll> p = {val, i};       // {val,position}
            
//             // Row
//             if(roworcol == 0) {
//                 vector<pair<ll, ll>> row(n);
//                 for(int j = 0; j < n; j++) {
//                     row[j].first = p.first;
//                     row[j].second = p.second;
//                 }
//                 row1[which] = row;
//             }
//             // Col
//             else if(roworcol == 1) {
//                 vector<pair<ll, ll>> col(n);
//                 for(int j = 0; j < n; j++) {
//                     col[j].first = p.first;
//                     col[j].second = p.second;
//                 }
//                 col1[which] = col;
//             }
//         }
        
//         // Transpose of col1 matrix
//         for(ll i = 0; i < n; i++) {
//             for(ll j = 0; j < n; j++) {
//                 col2[j][i] = col1[i][j];
//             }
//         }
         
//         for(ll i = 0; i < n; i++) {
//             for(ll j = 0; j < n; j++) {
//                 if(col2[i][j].second > row1[i][j].second) {
//                     sum += col2[i][j].first;
//                 }
//                 else if(col2[i][j].second < row1[i][j].second) {
//                     sum += row1[i][j].first;
//                 }
//             }
//         }
        
//         return sum;
        
//     }
// };



// #define ll long long
// class Solution {
// public:
//     long long matrixSumQueries(int n, vector<vector<int>>& q) {
//         //Brute Force Approach = O(n^2) * O(queries.length);
       
//         vector<pair<ll,ll>>row(n);
//         vector<pair<ll,ll>>col(n);
        
//         vector<vector<pair<ll,ll>>>row1(n,vector<pair<ll,ll>>(n));
//         vector<vector<pair<ll,ll>>>col1(n,vector<pair<ll,ll>>(n));
        
        
//         for(int i=0;i<q.size();i++){
//             // int roworcol= q[0];
//             // int which = q[1];
//             // int val = q[2];
            
//             pair<ll,ll> p = {q[2],i};       // {val,position}
            
//             //Row
//             if(q[0] == 0){
//                 for(int j=0;j<n;j++){
//                     row[i].first=p.first;
//                     row[i].second=p.second;
//                 }    
//             }
//             //Col
//             else if(q[0] == 1){
//                 for(int j=0;j<n;j++){
//                     col[i].first=p.first;
//                     col[i].second=p.second;
//                 } 
//             }
//             row1.push_back(row);
//             col1.push_back(col);

//             row.clear();
//             col.clear();
//         }
        
//         vector<vector<pair<ll,ll>>>col2(n,vector<pair<ll,ll>>(n));
//         //Transpose of col1 metrix
//         for(ll i=0;i<n;i++){
//             for(ll j=0;j<i;j++){
//                 col2[j][i] = col[j][i];
//             }
//         }
         
//        ll sum=0;
//         for(ll i=0;i<n;i++){
//             for(ll j=0;j<n;j++){
//                 if(col2[i][j].first > row1[i][j].first) sum+= col2[i][j].first;
//                 else sum += row1[i][j].first;
//             }
//         }
        
//         return sum;
//     }
// };