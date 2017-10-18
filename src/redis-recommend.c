#include "redismodule.h"


int add_pref_cmd(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {
    RedisModule_ReplyWithSimpleString(ctx, "add pref");    
    return REDISMODULE_OK;
}

int del_pref_cmd(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {
    RedisModule_ReplyWithSimpleString(ctx, "del pref");   
    return REDISMODULE_OK;
}

int RedisModule_OnLoad(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

    if (RedisModule_Init(ctx, "REC", 1, REDISMODULE_APIVER_1) == REDISMODULE_ERR) {
        return REDISMODULE_ERR;
    }

    if (RedisModule_CreateCommand(ctx, "REC.ADDPREF", add_pref_cmd, "write", 1, 1, 1) == REDISMODULE_ERR) {
        return REDISMODULE_ERR;
    }

    if (RedisModule_CreateCommand(ctx, "REC.DELPREF", del_pref_cmd, "write", 1, 1, 1) == REDISMODULE_ERR) {
        return REDISMODULE_ERR;
    }

    return REDISMODULE_OK;
}
