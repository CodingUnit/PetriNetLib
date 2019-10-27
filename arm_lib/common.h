#pragma once
#include "lib_incl.h"
#include "common_hal.h"
//#include "stdint.h"
//#include "types.h"

namespace common {

	class parameters
	{
	public:

	};

	class callable
	{
	public:

		virtual void exec() { }
	};

	class callable_pars
	{
	public:

		virtual void exec(const parameters *) { }
	};

	class function
	{
		typedef void(function::*self_func_type)();
		typedef void(*mem_func_dummy)(void *);
		typedef void(*tfunc_parm)(void *, u32);
		typedef void(*tfunc_parm2)(u32);

		typedef union
		{
			uint32_t adr;
			voidfunc vfunc;
			mem_func_dummy dfunc;
			tfunc_parm ifunc_obj;
			tfunc_parm2 ifunc;
		} func_union;

		typedef function self;

		void *obj;
		func_union func;

		void loop()
		{

		}

	public:
		function()
		{
			init();
		}

		template <class Func>
		function(Func func)
		{
			set(func);
		}

		function(voidfunc func)
		{
			set(func);
		}

		template <class Func>
		function(void *o, Func func)
		{
			set(o, func);
		}

		function(const self &s)
		{
			assign(s);
		}
		// инициализация

		void init()
		{
			obj = NULL;
			static const self_func_type f = &function::loop;
			func.adr = *(uint32_t *)&f;
		}

		// установка члена функции
		template <class Func>
		void set(void *o, Func f)
		{
			func.adr = *(uint32_t *)&f;//micro::utils::conv_iar_member_to_func<Func, func_ptr > 
			obj = o;
		}

		template <class Func>
		void set(Func f)
		{
			func.adr = *(uint32_t *)&f;//micro::utils::conv_iar_member_to_func<Func, func_ptr > 
		}

		void set(voidfunc f)
		{
			func.vfunc = f;//micro::utils::conv_iar_member_to_func<Func, func_ptr > 
		}

		template <class Func>
		static mem_func_dummy conv_func(Func func)
		{
			return *(mem_func_dummy *)&func;
		}

		void assign(const self &s)
		{
			func = s.func;
			obj = s.obj;
		}
		// запуск функции

		void exec()
		{
			func.dfunc(obj);
		}

		void exec_int(u32 parm)
		{
			if (obj)
			{
				func.ifunc_obj(obj, parm);
			}
			else
			{
				func.ifunc(parm);
			}

		}

		template <class T>
		void exec(T parm)
		{
			typedef void(*func_parm)(void *, T);
			typedef void(*func_parm2)(T);

			if (obj)
			{
				func_parm f = *(func_parm *)&func;
				f(obj, parm);
			}
			else
			{
				func_parm2 f = *(func_parm2 *)&func.vfunc;
				f(parm);
			}
		}


		template <class T, class V>
		void exec(T parm, V parm2)
		{
			typedef void(*func_parm)(void *, T, V);
			typedef void(*func_parm2)(T, V);

			if (obj)
			{
				func_parm f = *(func_parm *)&func;
				f(obj, parm, parm2);
			}
			else
			{
				func_parm2 f = *(func_parm2 *)&func.vfunc;
				f(parm, parm2);
			}
		}


		template <class T>
		void exec_ref(const T &parm)
		{
			typedef void(*func_parm)(void *, const T &);
			func_parm f = *(func_parm *)&func;
			f(obj, parm);
		}


		template <class T>
		T exec_ret()
		{
			typedef T(*func_parm)(void *);
			func_parm f = *(func_parm *)&func;
			return f(obj);
		}

		template <class T, class T2>
		T exec_ret(T2 p)
		{
			typedef T(*func_parm)(void *, T2);
			func_parm f = *(func_parm *)&func;
			return f(obj, p);
		}

		template <class T, class T2, class T3>
		T exec_ret(T2 p2, T3 p3)
		{
			typedef T(*func_parm)(void *, T2, T3);
			func_parm f = *(func_parm *)&func;
			return f(obj, p2, p3);
		}

		template <class T, class T2, class T3, class T4>
		T exec_ret(T2 p2, T3 p3, T4 p4)
		{
			typedef T(*func_parm)(void *, T2, T3, T4);
			func_parm f = *(func_parm *)&func;
			return f(obj, p2, p3, p4);
		}

		template <class T, class T2, class T3, class T4, class T5>
		T exec_ret(T2 p2, T3 p3, T4 p4, T5 p5)
		{
			typedef T(*func_parm)(void *, T2, T3, T4, T5);
			func_parm f = *(func_parm *)&func;
			return f(obj, p2, p3, p4, p5);
		}

		void operator=(const self &s)
		{
			if (this != &s)
			{
				assign(s);
			}
		}

		void operator( )()
		{
			exec();
		}

		function_hal get_hal_func() const
		{
			return function_hal(obj, func.dfunc);
		}

		// показывает что функция не установлена
		bool is_empty() const
		{
			return obj == 0 && func.adr == 0;
		}

		// очистка

		void clear()
		{
			init();
		}
	};



}
