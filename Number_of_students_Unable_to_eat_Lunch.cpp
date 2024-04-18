#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
 		queue<int> q;       
 		stack<int> st;

 		int n=students.size();
 		for(int i=0;i<n;i++){
 			q.push(students[i]);
 			st.push(sandwiches[i]);
 		}

 		int served=0;
 		while(!q.empty() && served<q.size()){
 			if(st.top()==q.front()){
 				st.pop();
 				q.pop();
 				served=0;
 			}
 			else{
 				q.push(q.front());
 				q.pop();
 				served++;
 			}
 		}

 		return q.size();
    }
};

int main(){
	return 0;
}