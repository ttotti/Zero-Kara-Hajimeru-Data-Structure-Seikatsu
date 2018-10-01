#include <cstdlib>
#include <cstring>
#include <cstdio>

// �̿� ���� �� ������ ������ ���� C�� C++�� ���� �ð� ���̺귯������ �� ���� �Լ��� �����ȴ�
// ���� qsort() �� �̸����� �����Ǵµ�, �� �Լ��� ��� ����ϴ��� �����ϰ� Ȱ���� �� �ִٸ� �ſ� ������ ���̴�

// �Լ��� ����
/*
	void qsort
	{
		void* base,   // �迭�� ���� �ּ�
		size_t num,   // �迭 ����� ����
		size_t width, // �迭 ��� �ϳ��� ũ��(����Ʈ ����)
		int (*compare)(const void *, const void *) // �� �Լ�, �����͸� ���Ͽ� �� ���� ��Ҹ� ���Ͽ� �� ����� ������ ��ȯ�Ѵ�, ����ڰ� �����Ͽ��� ��
	}
*/

// �Լ��� ����
// �� �Լ��� �� ��Ұ� width ����Ʈ�� num ���� ��Ҹ� ������ �迭�� ���Ͽ� �� ������ �����Ѵ�
// �Է� �迭�� ���ĵ� ������ ���� ��������,
// compare()�� �迭 ��� 2���� ���� ���ϴ� ����� ���� �Լ��� qsort �Լ��� ��ҵ��� ���� ������ ������ ���� ȣ���Ͽ� ����Ѵ�
/*
	compare((void *)elem1,(void *)elem2);

	��ȯ��
	< 0  - elem1�� elem2 ���� ������
	0    - elem1�� elem2 �� ������
	> 0  - elem1�� elem2 ���� ũ��
*/

// ������ �� ���� ���̺귯�� �Լ��� ����ϴ� ���� ���δ�
// �迭�� ��Ұ� double ���̹Ƿ� �̿� ���� compare() �Լ��� ������
// ���� Ŭ���� ��ü�� �迭�� �����Ϸ��� compare() ���� �����ϰ��� �ϴ� �ʵ带 ���Ͽ� ������ ���� ��ȯ�ϸ� �ȴ�
int compare(const void* arg1, const void* arg2)
{
	if (*(double*)arg1 > *(double*)arg2)
		return 1;
	else if (*(double*)arg1 < *(double*)arg2)
		return -1;
	else
		return 0;
}

void main()
{
	double list[5] = { 2.1, 0.9, 1.6, 3.8, 1.2 };

	qsort((void*)list, 5, sizeof(double), compare);

	for (int i = 0; i < 5; i++)
		printf("%f ", list[i]);
}