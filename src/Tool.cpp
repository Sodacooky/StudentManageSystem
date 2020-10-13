#include "Tool.h"

bool IsFileExist(const std::string& filename)
{
	_finddata_t fileInfo;

	auto handle = _findfirst(filename.c_str(), &fileInfo);
	if (handle == -1)
	{
		_findclose(handle);
		return false;
	}
	else
	{
		if (fileInfo.attrib != _A_SUBDIR)
		{
			_findclose(handle);
			return true;
		}
		//否则是目录
		_findclose(handle);
		return false;
	}
}

bool IsPathExist(const std::string& filename)
{
	_finddata_t fileInfo;

	auto handle = _findfirst(filename.c_str(), &fileInfo);
	if (handle == -1)
	{
		_findclose(handle);
		return false;
	}
	else
	{
		if (fileInfo.attrib == _A_SUBDIR)
		{
			_findclose(handle);
			return true;
		}
		else
		{
			_findclose(handle);
			return false;
		}
	}
}

unsigned int StringToUInt(const std::string& str)
{
	//乘几个10
	int tenMultipler = 1;

	unsigned int ret = 0;

	for (auto iter = str.end() - 1; ; iter--, tenMultipler *= 10)
	{
		if (*iter < '0' || *iter>'9')
		{
			//不是数字则跳过
			continue;
		}
		else
		{
			//这位数
			int elm = *iter - '0'; //如果是字符0，减去字符0就是0
			//乘上若干个10然后加上
			ret += (elm * tenMultipler);
		}

		if (iter == str.begin())
		{
			break;
		}
	}

	return ret;
}