// Pat1003 Emergency.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;
const static int infinity = 9999999;

int map[600][600];
bool colle[600];
int same[600];
int team[600];
int cityteam[600];
unsigned int dist[600];
int num_city = 0, num_road = 0;

int find(){
	int w = 0; int c = infinity;
	for (int i = 0; i < num_city; i++)
	{
		if (dist[i]<c && colle[i] == false)
		{
			c = dist[i];
			w = i;
		}
	}
	
	if (c != infinity)
		return w;
	else return -404;
}
int dijkstra(int st){
	int cur = st, nex = 0;
	for (int i = 0; i < num_city; i++)
		if (map[cur][i] > 0)
			dist[i] = map[cur][i];
	dist[st] = 0;
	colle[st] = true;
	while (1)
	{
		cur = find();
		if (cur == -404)break;
		colle[cur] = true;
		for (nex = 0; nex < num_city; nex++){					//出现新的最短路径
			if (colle[nex]) continue;
			if (map[cur][nex] + dist[cur] < dist[nex] ){		
				dist[nex] = dist[cur] + map[cur][nex];
				same[nex] = same[cur];
				cityteam[nex] = cityteam[cur] + team[nex];
			}
			else if (map[cur][nex] + dist[cur] == dist[nex]) {	//出现新的相同长度路径
				same[nex] += same[cur];
				if (cityteam[cur] + team[nex] > cityteam[nex])
					cityteam[nex] = cityteam[cur] + team[nex];
				}
		}	
	}
	return 0;
}


int main()
{
	fstream data;
	data.open("data.txt");
	int st = 0, en = 0;
	data >> num_city >> num_road >> st >> en;
	for (int i = 0; i < num_city; i++) {
		dist[i] = infinity;
		same[i] = 1;										//到任意点的路径至少唯一（无孤立点）
		for (int j = 0; j < num_city; j++)
			map[i][j] = infinity;
	}
	for (int i = 0; i < num_city; i++) {
		data >> team[i];
		cityteam[i] = team[i];
	}
	int c1 = 0, c2 = 0;
	for (int i = 0; i < num_road; i++)
	{
		data >> c1 >> c2;
		data >> map[c1][c2];
		map[c2][c1] = map[c1][c2];
	}
	if (st != en) {											//考虑起始点和终点相同的情形
		dijkstra(st);
		cout << same[en] << " "
			<< cityteam[en] + team[st] << endl;				//统计队伍的时候起始点未计算
	}
	else cout << 1 << " " << team[st] << endl;
	return 0;
}

