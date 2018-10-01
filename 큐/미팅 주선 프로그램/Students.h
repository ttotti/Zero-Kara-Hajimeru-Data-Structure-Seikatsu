#pragma once

struct Students
{
	int _id;
	char* _gender;

	Students(int id = 0, char* gender = "0")
		:_id(id), _gender(gender) {}
};