#include "HashChainMap.h"

void main()
{
	HashChainMap hash;

	//Node("do", "�ݺ�");

	hash.addRecord(&Node("do", "�ݺ�"));
	hash.addRecord(&Node("for", "�ݺ�"));
	hash.addRecord(&Node("if", "�б�"));
	hash.addRecord(&Node("case", "�б�"));
	hash.addRecord(&Node("else", "�б�"));
	hash.addRecord(&Node("return", "��ȯ"));
	hash.addRecord(&Node("funtion", "�Լ�"));

	hash.display();

	hash.searchRecord("return");
	hash.searchRecord("class");
	hash.searchRecord("funtion");
}