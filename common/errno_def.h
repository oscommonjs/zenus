#ifndef ERRNO_H_
#define ERRNO_H_

//gameserver and dbserver

const int ERR_COMMUNICATE      = -100000;
const int ERR_PROTOC_PARSE     = -100001;
const int ERR_PROGRAME         = -100002;

//for account
const int ERR_ACCOUNT_EXIST    = -100002;
const int ERR_ACCOUNT_ILLEGAL  = -100003;
const int ERR_PASSWORD_ILLEGAL = -100004;

#endif
