#pragma once

namespace petrinet_lib
{

	class token_iter
	{
	public:
		virtual int elem_size() const = 0;
		virtual void reset() = 0;
		virtual void *current() const = 0;
		virtual bool move_next() = 0;
	};

	class token_iter_utils
	{
	public:

		
	};


}
