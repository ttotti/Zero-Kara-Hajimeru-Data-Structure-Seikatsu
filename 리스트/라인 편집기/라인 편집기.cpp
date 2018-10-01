#include "LineEditor.h"

void Usage()
{
	printf("[�޴�����] i-�Է�,d-����,r-����,p-���,l-�����б�,s-����,q-����=> ");
}

int main()
{
	LineEditor editor;

	char command;

	do
	{
		Usage();

		command = getchar();

		switch (command)
		{
		case 'd':
			editor.DeleteLine();
			break;
		case 'i':
			editor.InsertLine();
			break;
		case 'r':
			editor.ReplaceLine();
			break;
		case 'l':
			editor.LoadFile("Test.txt");
			break;
		case 's':
			editor.StoreFile("Test.txt");
			break;
		case 'p':
			editor.Display();
			break;
		case 'q':
			break;
		}
		
		while (getchar() != '\n');
		// fflush(stdin);

	} while (command != 'q');

	return 0;
}