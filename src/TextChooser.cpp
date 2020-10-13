#include "TextChooser.h"

//显示所有
static void Display(std::vector<std::string>& content, int now_index);

//等待键盘输入，返回一个delta index（正负1）
//返回0为无效输入
//返回2为回车
static int HandleInput();

static int HandleInput()
{
	//msvc要求getch写成_getch
	auto input = _getch();

	if (input == 224)
	{
		//第一个输入为224则为拓展键
		//接受第二个字节的输入（方向键
		input = _getch();
		switch (input)//第二次调用getch()
		{
		case 72:
			return -1;
			break;
		case 80:
			return 1;
			break;
		default:
			return 0;
			break;
		}
	}
	else if (input == '\r')
	{
		//windows下的回车键为\r\n两个字节
		return 2;
	}

	return 0;
}

static void Display(std::vector<std::string>& content, int now_index)
{
	for (int index = 0; index != content.size(); index++)
	{
		if (now_index == index)
		{
			std::cout << "■" << content[index];
		}
		else
		{
			std::cout << "  " << content[index];
		}
		std::cout << std::endl;
	}
}

int TextChooserEnter(std::vector<std::string>& content, const std::string& strTips)
{
	int now_index = 0;

	while (true)
	{
		system("cls");//清屏

		std::cout << strTips << std::endl;
		Display(content, now_index);
		auto delta_index = HandleInput();

		if (delta_index == 1)
		{
			if (now_index == content.size() - 1)
			{
				now_index = 0;
			}
			else
			{
				now_index++;
			}
		}
		else if (delta_index == -1)
		{
			if (now_index == 0)
			{
				now_index = content.size() - 1;
			}
			else
			{
				now_index--;
			}
		}
		else if (delta_index == 2)
		{
			return now_index;
		}
	}

	//bkn
	return 0;
}
