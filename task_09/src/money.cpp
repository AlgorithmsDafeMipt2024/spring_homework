#include "money.hpp"

int solve(std::vector<int> &vec, int number){
   std::vector<int>table(number, 1e9);
   for(int i = 0; i < number; i++){
    for(int j = 0; j < vec.size(); ++j){
        if(vec[j] <= i){
            table[i] = std::min(table[i], 1 + table[i-j]);
        }
    }
   }
   return table[number - 1];
}