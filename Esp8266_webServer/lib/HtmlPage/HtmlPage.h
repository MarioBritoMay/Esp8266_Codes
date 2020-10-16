#ifndef HTML_PAGE_H
#define HTML_PAGE_H

#define HTMLPage_SIZE 954
#define HTMLEND_SIZE 20

const char htmlPage[HTMLPage_SIZE] = "<!DOCTYPE html><html><head><title>ESP8266 Configure</title><style>body {text-align: center; background-color:#CEDBD8;}.container {width: 50%; margin-right: 25%; margin-left: 25%;}.label_input {width: 40%;}.input1 {width: 60%;}.input_container {width: 100%;}.input_container {width: 100%;}.button{font-weight: bolder;border-radius: 5px;color: white;width: 100px;padding: 5px 10px;font-size: 13px;background-color: #555555;}</style><meta charset='UTF-8'></head><body><form action='configuration'method='get'class='formulary'<h1>ESP8266 Configure</h1><div class='container'><div class='input_container'><label for='ssid'class='label_input'>SSID:</label><input class='input1'name='ssid'type='text'placeholder='type ssid'></div><br><div class='input_container'><label for='pass'class='label_input'>PASS:</label><input class='input1'name='pass'type='password'placeholder='type password'></div><br><input class='button'type='submit'value='SAVE'/></div></form>";
const char htmlPageEnd[HTMLEND_SIZE] = "</body></html>";

#endif
