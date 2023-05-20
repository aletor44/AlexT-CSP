// Alexander Torjyan 28
// CSP Period 1


import requests
import tkinter as tk
from tkinter import messagebox

API_KEY = "YOUR_API_KEY"  # Replace with your OpenWeatherMap API key
API_URL = "http://api.openweathermap.org/data/2.5/weather?q={}&appid={}"

def get_weather(city):
    try:
        response = requests.get(API_URL.format(city, API_KEY))
        data = response.json()
        if data["cod"] != "404":
            weather_info = {
                "City": data["name"],
                "Temperature (Celsius)": data["main"]["temp"] - 273.15,
                "Humidity (%)": data["main"]["humidity"],
                "Description": data["weather"][0]["description"],
            }
            return weather_info
        else:
            return None
    except requests.exceptions.RequestException:
        return None

def show_weather():
    city = entry.get()
    weather_data = get_weather(city)
    if weather_data:
        message = "Weather in {}: \n".format(weather_data["City"])
        for key, value in weather_data.items():
            message += "{}: {}\n".format(key, value)
        messagebox.showinfo("Weather Information", message)
    else:
        messagebox.showerror("Error", "Failed to retrieve weather information.")

# GUI setup
window = tk.Tk()
window.title("Weather App")

label = tk.Label(window, text="Enter a city:")
label.pack()

entry = tk.Entry(window)
entry.pack()

button = tk.Button(window, text="Get Weather", command=show_weather)
button.pack()

window.mainloop()
