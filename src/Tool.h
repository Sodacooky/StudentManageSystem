#pragma once

#include <io.h>

#include <string>

//测试指定文件是否存在
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

//测试指定目录是否存在
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