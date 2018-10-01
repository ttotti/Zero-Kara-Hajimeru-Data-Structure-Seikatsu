#pragma once

// ���� �켱 Ž���� ���� �������� �� �̻� �湮���� ���� ���� ������ ������ ���� �������� ������ �������� �ǵ��ư���
// �� ����� ���� �ֱٿ� ������ ������� �ǵ��ư��� �ϹǷ� ������ ����Ͽ� ������ �� ������
// ���þ��� ��ȯ �˰����� ���·� �����ϰ� ��Ÿ�� �� �ִ�

#include "AdjMatGraph.h"

class SrchAMGraph :public AdjMatGraph
{
private:
	// ������ �湮 ����
	bool visited[MAX_VTXS];

public:
	// ��� ������ �湮���� �ʾҴٰ� ����
	void resetVisited()
	{
		for (int i = 0; i < size; i++)
		{
			visited[i] = false;
		}
	}

	// u ��° ������ v ��° ������ ����Ǿ� �ִ����� �˻���
	bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

	// ���� �켱 Ž�� �Լ�
	void DFS(int v)
	{
		// ���� ������ �湮��
		// ���� ���� ���� v�� �湮�ߴٰ� ǥ����
		visited[v] = true;
		// ������ �̸� ���
		printf("%c ", getVertex(v));

		// ��� �����鿡 ����
		for (int w = 0; w < size; w++)
		{
			// ���� ������ ����Ǿ� �ְ� ���� ���� ���� �����̸�
			if (isLinked(v, w) && visited[w] == false)
				// ���� + �湮X => ��ȯȣ��� �湮
				// ��ȯ ȣ��� �ٽ� Ž����
				DFS(w);
		}
	}
};