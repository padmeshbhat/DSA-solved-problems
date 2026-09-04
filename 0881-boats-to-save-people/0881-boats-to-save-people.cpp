class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int st=0;
        int end=n-1;
        int cnt=0;
        sort(people.begin(),people.end());
        while(st<=end){
            if(people[st]+people[end]<=limit){
               
               st++;
               end--;
            }
            else{
               
                end--;
            }
            cnt++;
        }
        return cnt;
    }
};