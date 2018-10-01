#pragma once

// �ʺ� �켱 Ž���� ť�� ����Ͽ��� �ϹǷ� ���� �켱 Ž������ �ڵ尡 �ణ �����ϴ�
// ���⼭�� ���� ť�� ��������� ����� ť�� ����ص� ����
// ���� ����� �̿��� ����� ����� �ٸ� ���� ���� ���� ����Ʈ�� ��� ������ ���� �ε����� �����̱� �����̴�

// �ʺ� �켱 Ž���� �׷����� 
// ���� ����Ʈ�� ǥ���Ǿ� ������ ��ü ���� �ð��� O(n + e) �̸�,
// ���� ��ķ� ǥ���Ǿ� �ִ� ���� O(n^2) �ð��� �ɸ���
// �ʺ� �켱 Ž���� ���� �켱 Ž���� ���� ��� �׷����� ����� ��� ���� ����Ʈ�� ����ϴ� ���� ȿ�����̴�

#include "AdjListGraph.h"
#include "CircularQueue.h"

class SrchALGraph :public AdjListGraph
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

	// u��° ������ ���� ����Ʈ�� ��� �����Ϳ������� NULL�� �ƴ� ������ ��� ���� ���鿡 ���� �˻���
	bool isLinked(int u, int v)
	{
		for (Node* p = adj[u]; p != NULL; p = p->getLink())
		{
			// �� ����� ���� ��ȣ�� v�̸� u��° ������ v��° ������ ������, ���� true ��ȯ
			if (p->getId() == v)
				return true;
		}

		// ���� ����Ʈ�� ������ȣ v�� ������ u�� v�� �������� ����, ���� false ��ȯ
		return false;
	}

	// ���� ����Ʈ�� ǥ���� �׷����� ���� �ʺ�켱Ž�� ����
	void BFS(int v)
	{
		// ���� ������ �湮��
		visited[v] = true;
		// ������ �̸� ���
		printf("%c ", getVertex(v));

		// ť ��ü ����
		CircularQueue que;

		// ���� ������ ť�� ����
		que.enqueue(v);

		// ť �ȿ� �����Ͱ� ���� ������
		while (!que.isEmpty())
		{
			// ť�� ���� ����
			int v = que.dequeue();

			// ���� ������ ��� ���� �����鿡 ���ؼ�
			for (Node* w = adj[v]; w != NULL; w = w->getLink())
			{
				// ���� ����� ���� ID
				int id = w->getId();
				// �̹湮 ���� Ž��
				if (!visited[id])
				{
					// �湮 ǥ��
					visited[id] = true;

					printf("%c ", getVertex(id));
					// �湮�� ������ ť�� ����
					que.enqueue(id);
				}
			}
		}
	}
};