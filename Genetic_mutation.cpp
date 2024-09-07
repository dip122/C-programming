#include<bits/stdc++.h>
using namespace std;

bool ispossible_change(string &a,string &b){

	int n = a.size();
	if(a.size() != b.size())return false;
	int count = 0;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i])count++;
	}
	return count == 1;
}

int minimum_steps(string &startGene,string &endGene,vector<string>&bank){

	int n = bank.size();
	unordered_map<string,vector<string>> adj;
	for(int i=0;i<bank.size();i++){
		if(ispossible_change(startGene,bank[i])){
			adj[startGene].push_back(bank[i]);
			adj[bank[i]].push_back(startGene);
		}
	}

	for(int i=0;i<bank.size();i++){
		for(int j=i+1;j<bank.size();j++){
			if(ispossible_change(bank[i],bank[j])){
				adj[bank[i]].push_back(bank[j]);
				adj[bank[j]].push_back(bank[i]);
			}	
		}
	}

	queue<pair<int,string>> q;
	q.push({0,startGene});
	map<string,int> vis;
	vis[startGene] = 1;
	while(q.empty() == false){
		int steps = q.front().first;
		string node = q.front().second;
		q.pop();
		if(node == endGene)return steps;
		for(auto &adjnode : adj[node]){
			if(vis.find(adjnode)==vis.end()){
				vis[adjnode] = 1;
				q.push({steps+1,adjnode});
			}
		}
	}

	return -1;
}

int main(){
	

	string startGene = "AACCGGTT";
       	string endGene = "AACCGGTA";
	vector<string> bank = {"AACCGGTA"};
	cout<<minimum_steps(startGene,endGene,bank)<<endl;


	return 0;
}
