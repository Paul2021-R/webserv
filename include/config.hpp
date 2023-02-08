#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#include "webserv.hpp"

#define SER "server"
#define LISTEN "listen"
#define BODY "body_size"
#define MAXCON "max_connect"
#define ROOT "root"
#define DEFFILE "default_file"
#define UPLOAD "upload_path"
#define ACCLOG "access_log"
#define ERRLOG "error_log"
#define SERNAME "server_name"
#define TIMEOUT "timeout"
#define AUTOINDEX "auto_index"
#define METHOD "method"
#define ERR "error"
#define CGIFILE "cgi"
#define LOCNAME "location"

enum e_server {
  Listen,
  BodySize,
  MaxConnect,
  Root,
  DefaultFile,
  UploadPath,
  AccessLog,
  ErrorLog,
  ServerName,
  Timeout,
  AutoIndex,
  Method,
  Error
};

enum e_location {
  locationname,
  cgi,
  redirection,
  root,
  defaultfile,
  autoindex,
  method,
  error
};

enum e_type { T_ROOT, T_LOCATION, T_CGI };
enum e_autoindex { on, off };

typedef struct s_loc_conf {
  std::map<e_location, std::string> configs_;
  e_type loc_type_;
  e_autoindex mode_;
} t_loc_conf;

typedef std::map<std::string, t_loc_conf*> loc_list;

typedef struct s_ser_conf {
  std::map<e_server, std::string> main_config_;
  loc_list location_;
} t_ser_conf;

class ServerConfig {
 private:
  std::vector<t_ser_conf*> server_list_;
  int64_t server_number_;

 private:
  void ParssingServer(const char* config_data);
  bool CheckKeyWord(const std::string& target, unsigned long pos,
                    const char* keyword);

 public:
  ServerConfig(const char* confpath);
  //   ~ServerConfig();
  //   ssize_t PrintServerConfig();
  //   t_ser_conf* GetServer(int64_t server_number);
  //   t_ser_conf* GetServer(const char* server_name);
  //   loc_list::iterator GetServerLocation(int64_t server_number);
  //   loc_list::iterator GetServerLocation(const char* server_name);
};

#endif
