#include <stdio.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

static int c_add(lua_State *L)
{
    int a, b;
    a = lua_tonumber(L, 1);
    b = lua_tonumber(L, 2);
    lua_pushnumber(L, a + b);
    return 1;
}

static int c_sub(lua_State *L)
{
    int a, b;
    a = lua_tonumber(L, 1);
    b = lua_tonumber(L, 2);
    lua_pushnumber(L, a - b);
    return 1;
}

static const struct luaL_Reg reg_libs[] =
{
   {"lua_add", c_add},
   {"lua_sub", c_sub},
   {NULL, NULL}
};

int luaopen_clibs(lua_State *L)
{
    lua_newtable(L);
    luaL_setfuncs(L, reg_libs, 0);
    return 1;
}