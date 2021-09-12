void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  WiFi.setAutoReconnect(true);
  WiFi.persistent(true);

  timeClient.begin();
  timeClient.update();
}
