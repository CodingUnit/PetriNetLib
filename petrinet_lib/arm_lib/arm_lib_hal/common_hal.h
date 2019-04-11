#pragma once
#include "lib_incl.h"

namespace common {

			class function_hal
			{
				typedef void( function_hal::*self_func_type )( );
				typedef void (*mem_func_dummy)(void *);

				typedef union
				{
					uint32_t adr;
					voidfunc vfunc;
					mem_func_dummy dfunc;
					void *ptr;
				} func_union;

				typedef function_hal self;

				void *obj;
				func_union func;

				void loop()
				{

				}

			public:
				function_hal()
				{
					init();
				}

				//template <class Func>
				function_hal( mem_func_dummy func )
				{
					set(func);
				}

				function_hal( voidfunc func )
				{
					set(func);
				}

				//template <class Func>
				function_hal( void *o, mem_func_dummy func )
				{
					set( o, func );
				}

				function_hal( const self &s )
				{
					assign( s );
				}
				// инициализация

				void init( )
				{
					obj = 0;
					static const self_func_type f = &function_hal::loop;
					func.ptr = *(void **)&f;
				}
				
				// установка члена функции
				//template <class Func>
				void set( void *o, mem_func_dummy f )
				{                                        
					func.ptr = (void *)f;//micro::utils::conv_iar_member_to_func<Func, func_ptr > 
					obj = o;
				}

				//template <class Func>
				void set( mem_func_dummy f )
				{                                        
					func.adr = (uint32_t)f;//micro::utils::conv_iar_member_to_func<Func, func_ptr > 
				}

				void set(voidfunc f )
				{
					func.vfunc = f;//micro::utils::conv_iar_member_to_func<Func, func_ptr > 
				}

				void assign( const self &s )
				{
					func = s.func;
					obj = s.obj;
				}
				// запуск функции

				void exec( )
				{
					func.dfunc(obj);
				}

				//template <class T>
				void exec(int parm)
				{
					typedef void (*func_parm)(void *, int);
					typedef void (*func_parm2)(int);
					
					if (obj)
					{
						//func_parm f = ;
						((func_parm)func.ptr)(obj, parm);
					} else 
					{
						//func_parm2 f = *(func_parm2 *)&func.vfunc;
						((func_parm2)func.ptr)(parm);
					}
				}

				//template <class T, class V>
				void exec(int parm, int parm2)
				{
					typedef void (*func_parm)(void *, int, int);
					typedef void (*func_parm2)(int, int);
					//func_parm f = *(func_parm *)&func;
					
					if (obj)
					{
					 ((func_parm)func.ptr)(obj, parm, parm2);
					} else 
					{
						//func_parm2 f = *(func_parm2 *)&func.vfunc;
						((func_parm2)func.ptr)(parm, parm2);
					}
				}

				//template <class T>
				void exec_ref(void *parm)
				{
					typedef void (*func_parm)(void *, void *);
					 //f = *(func_parm *)&func;
					((func_parm)func.ptr)(obj, parm);
				}

				//template <class T>
				int exec_ret()
				{
					typedef int (*func_parm)(void *);
					 //f = *(func_parm *)&func;
					return ((func_parm)func.ptr)(obj);
				}

				void operator=( const self &s )
				{
					if ( this != &s )
					{
						assign( s );
					}
				}

				void operator( )( )
				{
					exec( );
				}

				// показывает что функция не установлена

				bool is_empty( ) const
				{
					static const self_func_type f = &function_hal::loop;
					return obj == 0 && func.ptr == *(void **)&f;
				}

				// очистка

				void clear( )
				{
					init( );
				}
			};

			}