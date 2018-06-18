#include "lua.h"

void do_lua_test() {
    lua_State *lua = lua_open();
    luaL_openlibs(lua);

    static const struct luaL_reg map_lib[] = {
            {"create", map_create},
            {"slice",  map_slice},
            {NULL, NULL}};

    luaL_openlib(lua, "Map", map_lib, 0);

    luaL_dostring(lua, "map = Map.create(256, 256)");
    luaL_dostring(lua, "s = Map.slice(map, 256, 0, 0, 5, 5)");
    luaL_dostring(lua, "for i=0,4 do print(table.concat(s,' ',5*i, 5*i+4)) end");
}

int map_create(lua_State *lua) {
    lua_Integer w = luaL_checkinteger(lua, 1);
    lua_Integer h = luaL_checkinteger(lua, 2);

    unsigned char *map = malloc((size_t) (w * h));

    int n;
    for (n = 0; n != w * h; n++) {
        map[n] = (unsigned char) (n % 10);
    }

    lua_pushlightuserdata(lua, map);
    return 1;
}

int map_slice(lua_State *lua) {
    unsigned char *map = lua_touserdata(lua, 1);
    lua_Integer map_width = luaL_checkinteger(lua, 2);
    lua_Integer x = luaL_checkinteger(lua, 3);
    lua_Integer y = luaL_checkinteger(lua, 4);
    lua_Integer w = luaL_checkinteger(lua, 5);
    lua_Integer h = luaL_checkinteger(lua, 6);

    lua_newtable(lua);

    int cx, cy;
    for (cy = 0; cy != h; cy++)
        for (cx = 0; cx != w; cx++) {
            lua_pushnumber(lua, cx + w * cy);
            lua_pushnumber(lua, map[x + cx + (y + cy) * map_width]);
            lua_settable(lua, -3);
        }

    return 1;
}
