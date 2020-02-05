#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;


//while (1) {
//cin>>s;
//char c = getchar();
//input.push_back(s);
//if(c == '\n') {
//break;
//}
//}


class Graph{
public:
    vector<vector<int> > g;
    int size;
    Graph(int S);
    bool is_free(int vertex);
    void remove(int vertex);
};

Graph::Graph(int S) {
    size = S;
    for(int i=0; i<=S; i++) {
        vector<int> vec(S+1, 0);
        g.push_back(vec);
    }
}

bool Graph::is_free(int vertex) {
    if(vertex > size){
        return false;
    }
    return find(g[vertex].begin(), g[vertex].end(), 1) == g[vertex].end() ;
}

void Graph::remove(int vertex) {
    if(vertex > size){
        return;
    }
    for(int i=0; i<size+1; i++) {
        g[i][vertex] = 0;
    }
}


int main() {
    int m, n;
    cin>>n>>m;
    vector<int> weight(m, 0);
    int w;
    for(int i=1; i<=n; i++){
        cin>>w;
        weight[i] = w;
    }

    Graph me(n);

    int a, b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        me.g[b][a] = 1;
    }

    vector<int> s_w(weight.begin()+1, weight.end());
    sort(s_w.begin(), s_w.end());
    s_w.erase(unique(s_w.begin(), s_w.end()), s_w.end());

    vector<int> best_line;

    for(const auto &ww : s_w) {
        for(int i=1; i<weight.size(); i++) {
            if(ww == weight[i]) {
                best_line.push_back(i);
            }
        }
    }


    while(!best_line.empty()) {
        auto i = best_line.begin();
        while (!me.is_free(*i)) {
            i++;
            if(i == best_line.end()){
                cout<<"problem";
                return -1;
            }
        }
        cout<<*i<<" ";
        me.remove(*i);
        best_line.erase(i);
    }





    return 0;
}