
// ���� ����� �̿��� �׷��� Ŭ����
#pragma once
#include <cstdio>

// ǥ�� ������ �ִ� ������ ����
#define MAX_VTXS 256

class AdjMatGraph
{
	// �׷��� Ŭ������ ����� ����� ������ �ʵ带 protected�� ����
	// ������ �����, ������ �̸� ������ ����
protected:
	// ������ ����
	int size;
	// ������ �̸�
	char vertices[MAX_VTXS];
	// ���� ���
	int adj[MAX_VTXS][MAX_VTXS];

public:
	// ������, reset() �Լ��� ȣ���� ������ �ʵ带 �ʱ�ȭ ��
	AdjMatGraph() { reset(); }

	// ������ ������ ���� ����(���� �Ǵ� ��ȯ) �Լ�
	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }

	// ������ ������ 0�̸� ����, MAX_VTXS �̻��̸� ��ȭ ����
	bool isEmpty() { return size = 0; }
	bool isFull() { return size >= MAX_VTXS; }

	// �׷��� �ʱ�ȭ -> ���� ������ �׷���
	// Ŭ���� �ʱ�ȭ �Լ�, ������ ������ ���� ����Ʈ�� �ʱ�ȭ ��
	void reset()
	{
		size = 0;
		for (int i = 0; i < MAX_VTXS; i++)
		{
			for (int j = 0; j < MAX_VTXS; j++)
			{
				setEdge(i, j, 0);
			}
		}
	}

	// ���� ���� ����
	void inserVertex(char name)
	{
		// ��ȭ ���°� �ƴϸ� ���ο� ������ �׷����� �߰���, ������ �̸��� �Ű������� ���޹޾� ������
		if (!isFull())
			vertices[size++] = name;
		else
			printf("Error : �׷��� ���� ���� �ʰ�\n");
	}

	// ���� ���� ���� : ������ �׷����� �����, (����, ����ġ �׷��������� ����)
	// ������ �׷����� ���� ���� �Լ�, ����(u, v)�� �Բ� (v, u)�� ������, ���� ����� �ش� ����� ���� 1�� ��
	void insertEdge(int u, int v)
	{
		setEdge(u, v, 1);
		setEdge(v, u, 1); // ���� �׷��������� �� �κ��� ������(<u, v>�� ����)
	}

	// �׷��� ������ ����� (ȭ���̳� ���Ͽ� ���)
	// �׷��� ��� �Լ�, �׷����� ȭ��� �ƴ϶� ���Ϸε� ����� �� �ֵ��� �Ű������� FILE* �� ����
	// ����Ʈ �Ű������� stdout�� �����Ͽ� �Ű������� ���� ȣ��� ��� ȭ�鿡 ����ϵ��� ��
	void display(FILE* fp = stdout)
	{
		// ��� ������ ���� ������ ������ ����ϰ�
		fprintf(fp, "%d\n", size);

		// �� ������ �̸��� �ٸ� �������� ���� ���θ� �����, ������ �ִ� ���� 1�� ������ 0�� �����
		for (int i = 0; i < size; i++)
		{
			fprintf(fp, "%c  ", getVertex(i));

			for (int j = 0; j < size; j++)
				fprintf(fp, " %3d", getEdge(i, j));

			fprintf(fp, "\n");
		}
	}

	// ���� �Է� �Լ�
	// ���� filename �� �о� �׷��� ��ü�� �ʱ�ȭ�ϴ� �Լ�
	void load(const char* filename)
	{
		// ������ ���� �����͸� ���� (�б� ���)
		FILE* fp = fopen(filename, "r");

		// ������ ������
		if (fp != NULL)
		{
			int n, val;
			// ������ ������ ���� �о����, ���� graph.txt ������ ������ ��
			fscanf(fp, "%d", &n);

			// ������ �̸��� �о� ������ ������
			// ���Ͽ��� ���� �ϳ��� ���ڿ��� �а� ���ڿ��� ù ��° ���ڸ� ������ �̸����� ������ �Ϳ� ������ ��
			// ���ڿ��� �ƴ϶� ���ڷ� ���� ��� '\n'�� ���� ���� ��Ȳ�� �߻��� �� ����
			for (int i = 0; i < n; i++)
			{
				char str[80];
				// ������ �̸�
				fscanf(fp, "%s", str);
				// ���� ����
				inserVertex(str[0]);

				// �ϳ��� ������ ���� �ٸ� �������� ���� ���踦 �о� �鿩 ������ ������ ������ ������
				for (int j = 0; j < n; j++)
				{
					int val;
					// ���� ����
					fscanf(fp, "%d", &val);
					// ������ ������
					if (val != 0)
						// ���� ����
						insertEdge(i, j);
				}
			}

			// ó���� �������� ������ ����
			fclose(fp);
		}
	}

	// ���� ���� �Լ�, ���� �׷����� filename ���Ͽ� ������
	void store(const char* filename)
	{
		// ������ ���� �����͸� ���� (���� ���)
		FILE* fp = fopen(filename, "w");

		// ������ ������
		if (fp != NULL)
		{
			// display() �Լ� ȣ��, �Ű������� ���� ������ fp�� ������
			display(fp);
			// ó���� �������� ������ ����
			fclose(fp);
		}
	}
};