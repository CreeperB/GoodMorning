#include<bits/stdc++.h>
#include<sstream>
using namespace std;

struct node {
    string name;
    int x;
    int y;
};
string num2str(int i){
	stringstream ss;
	ss<<i;
	return ss.str();
}
int distance(node a, node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string s;
    fin >> s;
    int n;
    fin >> n;

    vector<node> Points(n);
    for (int i = 0; i < n; i++) {
        fin >> Points[i].name >> Points[i].x >> Points[i].y;
    }

    // Minimum Spanning Tree using Prim's Algorithm
    vector<bool> IsVisited(n, false);
    vector<int> minDist(n, INT_MAX);
    vector<int> parent(n, -1);

    minDist[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;

        // Find the vertex with the minimum distance that is not yet included in MST
        for (int i = 0; i < n; i++) {
            if (!IsVisited[i] && (u == -1 || minDist[i] < minDist[u])) {
                u = i;
            }
        }

        IsVisited[u] = true;

        // Update the distance of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++) {
            int dist = distance(Points[u], Points[v]);
            if (!IsVisited[v] && dist < minDist[v]) {
                minDist[v] = dist;
                parent[v] = u;
            }
        }
    }
	
    // Output the edges of the MST
    /*for (int i = 1; i < n; i++) {
        fout << Points[parent[i]].name << " " << Points[i].name << endl;
    }*/
    
	//Add steiner points
	for(int i=1;i<n;i++){
		node Node;
		Node.name="S"+num2str(i);
		Node.x=Points[parent[i]].y;//�H����I�A�i��|�X�u�P���I�X�{�h�� 
		Node.y=Points[i].x;
		Points.push_back(Node);
	}
	n=Points.size();
	
	//Show the additional points
	fout<<"NumVertices: "<<n<<endl;
	for(int i=0;i<n;i++){
		fout<<Points[i].name<<" "<<Points[i].x<<" "<<Points[i].y<<endl;
	}
	//�o�᭱�O�����A���٦b�Q 
	vector<bool> IsVisited2(n, false);
    vector<int> minDist2(n, INT_MAX);
    vector<int> parent2(n, -1);
	 minDist2[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;

        // Find the vertex with the minimum distance that is not yet included in MST
        for (int i = 0; i < n; i++) {
            if (!IsVisited2[i] && (u == -1 || minDist2[i] < minDist2[u])) {
                u = i;
            }
        }

        IsVisited2[u] = true;

        // Update the distance of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++) {
            int dist = distance(Points[u], Points[v]);
            if (!IsVisited2[v] && dist < minDist2[v]) {
                minDist2[v] = dist;
                parent2[v] = u;
            }
        }
    }
	
	 // Show the additional edges
	int Wirelength=0;
	fout<<"Numedges: "<<n-1<<endl;
    for (int i = 1; i < n; i++) {
        fout << "E"+num2str(i)<<" "<<Points[parent2[i]].name << " " << Points[i].name << endl;
        Wirelength+=distance(Points[parent2[i]],Points[i]);
    }
    fout<<"Wirelength: "<<Wirelength;
    fin.close();
    fout.close();

    return 0;
}

