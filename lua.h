#ifndef CLIONSQLITE_LUA_H
#define CLIONSQLITE_LUA_H

#include <stdlib.h>
#include <lua5.1/lua.h>
#include <lua5.1/lauxlib.h>
#include <lua5.1/lualib.h>

void do_lua_test();
int map_create(lua_State *lua);
int map_slice(lua_State *lua);

#endif //CLIONSQLITE_LUA_H
