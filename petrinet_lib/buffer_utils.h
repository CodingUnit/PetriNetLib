#pragma once
#include "arm_lib/lib_incl.h"
#include "arm_lib/memory.h"

namespace petrinet_lib
{

  class bytes
  {
    int len;
  public:
    bytes() : len(0) {}
    bytes(int l) : len(l) {}

    void set_buf(const bytes &b)
    {
      memory::Mem::copy(get_buf(), b.get_buf(), b.get_count());
      len = b.len;
    }


    u8 at(int idx) const
    {
      return ((u8 *)get_buf())[idx];
    }
    
    void copy_to(void *buf) const
    {
      copy(buf, get_buf(), get_count());
    }

	void set_buf(const void *b, int l)
	{
		memory::Mem::copy(get_buf(), b, l);
		len = l;
	}

    virtual void *get_buf() const { return 0; };
    int get_count() const { return len; };
    void set_count(int l) { len = l; }

    void operator=(const bytes &b)
    {
      set_buf(b);
    }
  };

  class bytes_ptr : public bytes
  {
	  void *ptr;
  public:
	  bytes_ptr() {}
	  bytes_ptr(const void *buf, int l) { set_buf((void *)buf, l); }
	  bytes_ptr(const bytes &n) { set_buf(n); }
	  bytes_ptr(int l) : bytes(l) {}

	  void set_buf(const bytes &b)
	  {
		  ptr = b.get_buf();
		  set_count(b.get_count());
	  }


	  u8 at(int idx) const
	  {
		  return ((u8 *)get_buf())[idx];
	  }

	  void copy_to(void *buf) const
	  {
		  copy(buf, ptr, get_count());
	  }

	  void set_buf(void *b, int l)
	  {
		  ptr = b;
		  //memory::Mem::copy(get_buf(), b, l);
		  set_count(l);
	  }

	  virtual void *get_buf() const { return ptr; };

	  void operator=(const bytes &b)
	  {
		  set_buf(b);
	  }
  };

  class bytes2 : public bytes
  {
    u8 buf[2];
  public:
    //bytes2(const bytes2 &self) { init(self.buf); }
    bytes2() {}
    bytes2(u8 buf[2]) : bytes(2)
    {
      init(buf);
    }

    void init(const u8 data[2])
    {
      *(u16 *)&buf[0] = *(u16 *)&data[0];
      set_count(2);
    }

    void *get_buf() const { return (void *)buf; }

    void operator=(const bytes &b)
    {
      set_buf(b);
    }
  };

  class bytes3 : public bytes
  {
	  u8 buf[3];
  public:
	  //bytes2(const bytes2 &self) { init(self.buf); }
	  bytes3() {}
	  bytes3(u8 buf[3]) : bytes(3)
	  {
		  init(buf);
	  }

	  void init(const u8 data[3])
	  {
		  *(u16 *)&buf[0] = *(u16 *)&data[0];
		  *(u8 *)&buf[2] = data[2];
		  set_count(3);
	  }

	  void *get_buf() const { return (void *)buf; }

	  void operator=(const bytes &b)
	  {
		  set_buf(b);
	  }
  };

  class bytes4 : public bytes
  {
	  u8 buf[4];
  public:
	  //bytes2(const bytes2 &self) { init(self.buf); }
	  bytes4() {}
	  bytes4(u8 buf[4]) : bytes(4)
	  {
		  init(buf);
	  }

	  void init(const u8 data[4])
	  {
		  *(u32 *)&buf[0] = *(u32 *)&data[0];
		  set_count(4);
	  }

	  void *get_buf() const { return (void *)buf; }

	  void operator=(const bytes &b)
	  {
		  set_buf(b);
	  }
  };

  class bytesn : public bytes
  {
    u8 buf[100];
  public:
    bytesn(const bytesn &self) { set_buf(self); }
    bytesn() {}
    bytesn(void *buf, int len)
    {
      init(buf, len);
    }

    void init(const void *data, int len)
    {
      memory::Mem::copy(buf, data, len);
      set_count(len);
    }

    void *get_buf() const { return (void *)buf; }

    void operator=(const bytes &b)
    {
      set_buf(b);
    }
  };

  class bytes8 : public bytes
  {
    u8 buf[8];
  public:
    bytes8() {}
    bytes8(const bytes8 &b)
    {
      set_buf(b);
    }
    //bytes8(const bytes &buf) {init(buf);}
    bytes8(u8 buf[8])
    {
      init(buf, 8);
    }

	bytes8(void *buf, int len)
	{
    init((u8 *)buf, len);
	}
    /*void init(const bytes &data)
    {
      memory::Mem::copy(&buf[0], data.get_buf(), data.get_count());
      set_count(data.get_count());
    }*/
    
    void init(u8 data[8], int len)
    {
      *(u32 *)&buf[0] = *(u32 *)&data[0];
      *(u32 *)&buf[4] = *(u32 *)&data[4];
      set_count(len);
    }

    void *get_buf() const { return (void *)buf; }
    void operator=(const bytes &b)
    {
      set_buf(b);
    }
  };

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
