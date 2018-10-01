#pragma once

#include <cstdio>


void error(const char* message)
{
	printf("%s\n", message);
}

// ����Ʈ�� ���ð� ť�� ���� �����ڷ��� ������ ���ܰ� �ĴܻӸ� �ƴ϶� �߰��� �ִ� ��ҵ鿡 ���� �����̳� ���������� ����Ѵ�
// ���� ����Ʈ�� �迭�� �����ϸ� ��ȿ������ ����ũ��� �߰� ���� �Ǵ� �߰� ���� �� ���� �ڷ��� �̵��� �ʿ��ϴ�
// �̸� �ذ��ϱ� ���� ���Ḯ��Ʈ�� ����Ͽ� ����Ʈ�� ������ �� �ִ�

#define MAX_LIST_SIZE 100

class ArrayList
{
private:
	int data[MAX_LIST_SIZE]; // ������ �׸��� ������ ��
	int length;				 // ���� ����Ʈ ���� �׸���� ����
							 // length �� �׻� �����Ͱ� ����ִ°��� ��ġ�Ѵ� 

public:
	// ������ ==> length �� �ʱ�ȭ
	ArrayList(void) { length = 0; }

	// ���� �� ��ȭ ���� �˻�
	// length �� 0 �̸� ����Ʈ�� �����Ͱ� ����
	// length �� �ִ� �迭 ���� ������ ���� ����
	bool isEmpty() { return length == 0; }
	bool isFull() { return length == MAX_LIST_SIZE; }

	// ���� ���� : ����Ʈ�� pos��°�� �׸� e �߰�
	void insert(int pos, int e)
	{
		// ����Ʈ�� ������ ������� �˻��ϰ�
		// �Լ��� ������ ����� ���� �Էµ� pos ��ġ�� ��ȿ������ �˻��ϴ� �ڵ带 �߰��Ͽ���
		// ��ȿ�� pos�� ������ 0���� length�����̴� ����Ʈ�� �� ������ �ڷḦ �߰��� �� �־�� �Ѵ�
		if (!isFull() && pos >= 0 && pos <= length)
		{
			// ���� �����͸� �� ĭ�� �а�
			for (int i = length; i > pos; i--)
			{
				data[i] = data[i - 1];
			}
			// pos�� e�� �����ϰ�
			data[pos] = e;
			// ����Ʈ �׸��� ���� ����
			length++;
		}
		else error("��ȭ���� ���� �Ǵ� ���� ��ġ ����");
	}

	// ���� ���� : pos��°�� �׸��� ����Ʈ���� ����
	void remove(int pos)
	{
		// ����Ʈ�� ����ִ��� Ȯ���ϰ�
		// �����ϰ��� �ϴ� ��ġ�� ��ȿ�� ��ġ������ �˻��ϴ� �ڵ带 �߰��ߴ�
		// ��ȿ�� pos�� ������ 0���� length-1 ���� �̴�
		if (!isEmpty() && pos >= 0 && pos < length)
		{
			// ���� �����͸� ������ ����
			for (int i = pos + 1; i < length; i++)
			{
				data[i - 1] = data[i];
			}
			// ���� ����
			length--;
		}
		else error("������� ���� �Ǵ� ���� ��ġ ����");
	}

	// pos��° �׸��� ��ȯ
	int getEntry(int pos) { return data[pos]; }

	// item �׸��� �ִ��� �˻�
	bool find(int item)
	{
		// �迭�ȿ� �����͸� ó������ ������ ������ŭ �����Ѵ�
		for (int i = 0; i < length; i++)
		{
			if (data[i] == item)
				return true;
		}

		return false;
	}

	// pos��ġ�� ��� ����
	void replace(int pos, int e)
	{
		data[pos] = e;
	}

	// ����Ʈ�� ���� ��ȯ
	int size() { return length; }

	// ����Ʈ�� �׸��� ���
	void display()
	{
		printf("[�迭�� ������ ����Ʈ ��ü �׸� �� = %2d] : ", size());
		for (int i = 0; i < length; i++)
		{
			printf("[%2d]", data[i]);
		}
		printf("\n");
	}

	// ��� ��� ����
	void clear() { length = 0; }
};