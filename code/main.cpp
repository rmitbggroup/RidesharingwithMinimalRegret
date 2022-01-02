#include "main.h"

//simulation parameters
int MAX_PASSENGERS = 4; //capacity
int MAX_TAXIS = 2000;
double SERVICE_CONST = 1.5; //flexible factor
double PICKUP_CONST = 600;
int logicalTime = 68400;//
int logicalTimeLimit = 70200;//
double speed = 10;
string data_dir = "/research/remote/petabyte/users/s3852647/data/newyork";
double limit = 1;
double alpha = 0.9;
int batch = 1;


//statistics
//int count_dist;
//int count_taxi;
//int count_share;
size_t count_edge;
int count_node;

//data structures
queue<request_t> requests;
vector<taxi_t> taxis;
vector<vertex*> vertices;
ShortestPath* shortestPath;

int main(int argc, char** argv)
{
	range = 100;
	hasher = range / 2;

	grid_dist.resize(range);
	for (auto& v1 : grid_dist) {
		v1.resize(range);
		for (auto& v2 : v1) {
			v2.resize(range);
			for (auto& v3 : v2) {
				v3.resize(range);
			}
		}
	}
	extern vector<vector<set<int>>> grid_border;
	grid_border.resize(range);
	for (auto& v : grid_border) {
		v.resize(range);
	}
	for (int i = 0; i < 2; ++i) {
		vis_grid[i].resize(range);
		for (auto& v1 : vis_grid[i]) {
			v1.resize(range);
		}
	}
	grid.resize(range);
	for (auto& v : grid) {
		v.resize(range);
	}

	PICKUP_CONST *= speed;
	cout << "----------------------------" << endl;
	cout << "MAX_PASSENGERS = " << MAX_PASSENGERS << endl;
	cout << "MAX_TAXIS = " << MAX_TAXIS << endl;
	cout << "SERVICE_CONST = " << SERVICE_CONST << endl;
	cout << "PICKUP_CONST = " << PICKUP_CONST << endl;
	cout << "LogicalTimeLimit = " << logicalTimeLimit << endl;

	shortest_path_init(vertices, data_dir);
	cout << "memory=" << double(grid_dist.capacity() * grid_dist.capacity() * grid_dist.capacity() * grid_dist.capacity() * sizeof(double)+ grid.capacity() * grid_dist.capacity() * sizeof(grid_t)+ grid_border.capacity() * grid_border.capacity() * sizeof(int))/1024/1024 << endl;
	read_request(requests);
	taxis = set_taxi(MAX_TAXIS);
    best_first(requests, taxis);
	//search_and_replace(requests, taxis);

	return 0;
}