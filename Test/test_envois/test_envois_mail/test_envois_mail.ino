//Classe Emailsender avec argument



//Constructeur avec les argument passé 
void setup() {
 EMailSender(const char* email_login, const char* email_password, const char* email_from, const char* smtp_server, uint16_t smtp_port)
 {
  EMailSender emailSend("smtp.hugo38.test1@gmail.com", "toToeap1!");
 }

void loop() {
EMailSender::EMailMessage message;
message.subject = "Robot detection";
message.message = "Detection CO !!";
EMailSender::Response resp = emailSend.send("hugo38.rodrigues@gmail.com", message);
}
