#include <string>

class CompanyA {
public:
    void sendCleartext(const std::string& msg){}
    void sendEncrypted(const std::string& msg){}
};

class CompanyB {
public:
    void sendCleartext(const std::string& msg){}
    void sendEncrypted(const std::string& msg){}
};

template<typename Company>
class MsgSender {
public:
    void sendClear(const std::string& msg)
    {
        Company c;
        c.sendCleartext(msg);
    }

    void sendSecret(const std::string& msg){
        Company c;
        c.sendEncrypted(msg);
    }
};

template<typename Kcompany>
class LoggingMsgSender: public MsgSender<Kcompany> {
public:
    using MsgSender<Kcompany>::sendClear;
    void sendClearMsg(const std::string& msg)
    {
        //write "before sending" info to the log;
        sendClear(msg); // <-------- won't compile!
        //write "after sending" info to the log;
    }
};

int main(int argc, char const *argv[]) {
  MsgSender<CompanyA> cal;
  cal.sendClear("rr");
  //LoggingMsgSender<CompanyA> cal;
  //cal.sendClearMsg("rr");
  return 0;
}
