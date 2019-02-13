#pragma once
namespace petrinet_lib
{


	bool equals(void *buf1, void *buf2, int count)
	{
		int *ptr1 = (int *)buf1;
		int *ptr2 = (int *)buf2;
		for (int i = 0; i < count; )
		{
			if (count - i >= 4)
			{
				if (*ptr1++ != *ptr2++)
				{
					return false;
				}
				i += 4;
			}
			else
			{
				char *bptr1 = (char *)ptr1;
				char *bptr2 = (char *)ptr2;
				if (*bptr1++ != *bptr2++)
				{
					return false;
				}
				i++;
			}
		}
		return true;
	}
}