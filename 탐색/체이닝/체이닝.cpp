#include "HashChainMap.h"

void main()
{
	HashChainMap hash;

	//Node("do", "반복");

	hash.addRecord(&Node("do", "반복"));
	hash.addRecord(&Node("for", "반복"));
	hash.addRecord(&Node("if", "분기"));
	hash.addRecord(&Node("case", "분기"));
	hash.addRecord(&Node("else", "분기"));
	hash.addRecord(&Node("return", "반환"));
	hash.addRecord(&Node("funtion", "함수"));

	hash.display();

	hash.searchRecord("return");
	hash.searchRecord("class");
	hash.searchRecord("funtion");
}