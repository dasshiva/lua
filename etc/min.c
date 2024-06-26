/*
* min.c
* a minimal Lua interpreter. loads stdin only.
* no standard library, only a "print" function.
*/

#include <stdio.h>
#include "lua.h"
#include <time.h>
/* a simple "print". based on the code in lbaselib.c */
static int print(lua_State *L)
{
 int n=lua_gettop(L);
 int i;
 for (i=1; i<=n; i++)
 {
  if (i>1) printf("\t");
  if (lua_isstring(L,i))
   printf("%s",lua_tostring(L,i));
  else
   printf("%s:%p",lua_typename(L,lua_type(L,i)),lua_topointer(L,i));
 }
 printf("\n");
 return 0;
}

static int tm(lua_State *L) {
	lua_pushnumber(L, time(NULL));
	return 1;
}

int main(void)
{
 lua_State *L=lua_open(0);
 lua_register(L,"print",print);
 lua_register(L,"time", tm);
 return lua_dofile(L, "hello.lua");
}
