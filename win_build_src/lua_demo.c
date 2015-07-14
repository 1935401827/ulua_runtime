#include <stdio.h>
#include <string.h>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

//��ע���C������
int add(lua_State* L)
{
	double a = luaL_checknumber(L, 1);
	double b = luaL_checknumber(L, 2);
	
	lua_pushnumber(L, a + b);
	return 1;
}

//luaL_Reg�ṹ��ĵ�һ���ֶ�Ϊ�ַ�������ע��ʱ����֪ͨLua�ú��������֡�
//��һ���ֶ�ΪC����ָ�롣
//�ṹ�������е����һ��Ԫ�ص������ֶξ�ΪNULL��������ʾLuaע�ắ���Ѿ����������ĩβ��
static luaL_Reg mylibs[] = {
	{"add", add},
	{NULL, NULL}
};

//��C���Ψһ��ں������亯��ǩ����ͬ�������ע�ắ���������¼���˵����
//1. ���ǿ��Խ��ú����򵥵����Ϊģ��Ĺ���������
//2. �亯��������Ϊluaopen_xxx������xxx��ʾlibrary���ơ�Lua����require "xxx"��Ҫ��֮��Ӧ��
//3. ��luaL_register�ĵ����У����һ���ַ�������Ϊģ����"xxx"���ڶ�������Ϊ��ע�ắ�������顣
//4. ��Ҫǿ�����ǣ�������Ҫ�õ�"xxx"�Ĵ��룬����C����Lua�������뱣��һ�£�����Lua��Լ���������޷����á�
int luaopen_mydemolibs(lua_State* L)
{
	const char* libName = "lua_demo"; 
	luaL_register(L, libName, mylibs);
	return 1;
}

