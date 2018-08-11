#include <bits/stdc++.h>
#include "../include/Vehicle.hpp"
using namespace std;
class Planner
{

public:	
	void plan(State, State, int**);

}

void Planner::plan(State start, State end, int** obs_map)
{
	Map map(obs_map);//object of Map class
	int visited[map.MAPX][map.MAPY][map.MAP_THETA]={0};//To mark the visited states. MAXX, MAXY and MAX_THETA are to be imported from the map class
	Vehicle car;//object of vehicle class
	priority_queue<state, Heuristic::compare> pq;

	pq.push(start);
	while(true)
	{
		State current=pb.top();
		pq.pop();

		visited[current.x][current.y][current.theta]=1;
		if(Map::isReached(current))//checks if it has reached the goal
			break;
		vector <State> next=car.next_states(state);
		for(vector <State>::iterator it= next.begin(); it!=next.end();it++)
		{
			if(visited[*it.x][*it.y][*it.theta])
				continue;
			if(map.is_collision_free(it))
				pq.push(*it);

		}
	}
}
int main()
{

}