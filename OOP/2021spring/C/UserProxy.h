#include"User.h"
#include"EncryptStrategy.h"
#include"VerificationStrategy.h"
#include<iostream>

class UserProxy : public User {
    RealUser *ruser;
    EncryptStrategy *encStr;
    VerificationStrategy *verStr;
public:
    UserProxy(RealUser *ruser, EncryptStrategy *encStr, VerificationStrategy *verStr) : ruser(ruser), encStr(encStr), verStr(verStr) {}
    void sendMessage(std::string mes) {
        std::string _mes = encStr->encode(mes);
        ruser->sendMessage(_mes);
        _mes = verStr->verify(mes);
        std::cout << _mes << std::endl;
    }
};