local clibs = require("clibs")
c =clibs.lua_add(10, 20)      --调用c中注册的函数lua_add
d =clibs.lua_sub(99, 33)
print("c= ", c)
print("d= ", d)