import requests

API_KEY = "cab6a73c97c27c77bcaf4e4c2c713171"
CIDADE = "Sao Bernardo do Campo"
URL = f"http://api.openweathermap.org/data/2.5/weather?q={CIDADE}&appid={API_KEY}&units=metric&lang=pt_br"

try:
    response = requests.get(URL)
    dados = response.json()

    if response.status_code == 200:
        temp = dados['main']['temp']
        clima = dados['weather'][0]['main']
        desc = dados['weather'][0]['description']

        print(f"Cidade: {CIDADE} | Temp: {temp}C | Condição: {desc}")

        if clima in ['Rain', 'Drizzle', 'Thunderstorm']:
            print("STATUS: CHUVA DETECTADA -> SUSPENDER IRRIGAÇÃO")
        else:
            print("STATUS: SEM CHUVA -> SISTEMA LIBERADO")
    else:
        print("Erro: Verifique se a chave API já foi ativada pelo OpenWeather.")

except Exception as e:
    print(f"Erro de conexão: {e}")
