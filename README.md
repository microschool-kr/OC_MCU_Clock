# 시계만들기 

[실시간 시계](https://ko.wikipedia.org/wiki/%EC%8B%A4%EC%8B%9C%EA%B0%84_%EC%8B%9C%EA%B3%84)의 개념을 활용해서 아두이노로 시계를 만들어볼 것이다.


![img](https://nerdytechy.com/wp-content/uploads/2021/02/arduino-rtc-5-1024x677.png)

[![YouTube Channel Views](https://img.shields.io/youtube/channel/views/UCz5BOU9J9pB_O0B8-rDjCWQ?label=YouTube&style=social)](https://youtu.be/E6wkvTG2Ofs?si=k_IFc8MM8aGpZE7J)

## 하드웨어 

- 아두이노 우노  
- SSD1306 OLED
- DS3231 RTC module
- CR2032 코인베터리
- M-M 점퍼선 8개 
- USB 2.0 케이블 Type A/B


**주의: 점퍼선 연결시 케이블을 제거하고 진행합니다.**

### 선 작업 
#### 회로도
![img](/ppt/img/RTC_Arduino_fritzing.png)
#### 핀 정보
| [Arduino UNO GPIO](https://docs.arduino.cc/resources/pinouts/A000066-full-pinout.pdf) | DS3231 |
|-----------|------|
|   D19     | SCL  |
|   D18     | SDA  |
|   5V      | VCC  |
|   GND     | GND  |

| [Arduino UNO GPIO](https://docs.arduino.cc/resources/pinouts/A000066-full-pinout.pdf) | SSD1306 |
|-----------|------|
|   D19     | SCL  |
|   D18     | SDA  |
|   5V      | VCC  |
|   GND     | GND  |

### 구입처 

The stl files for an enclosure are on thingiverse [here](https://www.thingiverse.com/thing:6125748) (Thanks Ryan!).

## 순서도
[![](https://mermaid.ink/img/pako:eNptUj9PwkAU_yqXNxdCS8H2BhIDDiYaE3UyXRp6QhO4YmkTkZA4EEPEgQEjGiAMGBdNUMC4-IW44zt40BIVuKG9e78_92vfq0LWsQhgKJMLn9AsydhmzjWLBkVilUzXs7N2yaQe2nUt36bOJnB8mt4sHh3sZQwa1INnqI-kUkKA0b6SRvObKW8O1uGF9C-OVj5rDvNOnfdfEW92Z6M64oN7Np6I1zXvPwd8wRLcUIUXR8QfWiGFtbrr0t737Gu0uqzgOCUk80mDvTRYc4jYqMPG061BlsaB1Wz0vkjMn9r8421riv-phev8sbP9D7B2m98O5-07Nmjw3mQZPQz82WWD8CMJtQwKEhSJWzRtS3SyugAM8PKkSAzAYluwc17eAIPWBNH0PeekQrOAPdcnEvgly_RWbQd8bhbKokos23Pcw2A2liMigWjsmeP8csQZcBUuAcu6HtU0VdUUNSkruqJrElQAR2RZjcoJRY8lkrqaVNX4Tk2Cq6WHHI3H5ZhYWjKhJgRa-wEsOP1j?type=png)](https://mermaid.live/edit#pako:eNptUj9PwkAU_yqXNxdCS8H2BhIDDiYaE3UyXRp6QhO4YmkTkZA4EEPEgQEjGiAMGBdNUMC4-IW44zt40BIVuKG9e78_92vfq0LWsQhgKJMLn9AsydhmzjWLBkVilUzXs7N2yaQe2nUt36bOJnB8mt4sHh3sZQwa1INnqI-kUkKA0b6SRvObKW8O1uGF9C-OVj5rDvNOnfdfEW92Z6M64oN7Np6I1zXvPwd8wRLcUIUXR8QfWiGFtbrr0t737Gu0uqzgOCUk80mDvTRYc4jYqMPG061BlsaB1Wz0vkjMn9r8421riv-phev8sbP9D7B2m98O5-07Nmjw3mQZPQz82WWD8CMJtQwKEhSJWzRtS3SyugAM8PKkSAzAYluwc17eAIPWBNH0PeekQrOAPdcnEvgly_RWbQd8bhbKokos23Pcw2A2liMigWjsmeP8csQZcBUuAcu6HtU0VdUUNSkruqJrElQAR2RZjcoJRY8lkrqaVNX4Tk2Cq6WHHI3H5ZhYWjKhJgRa-wEsOP1j)


## 라이브러리  
- [RTCLib](https://github.com/adafruit/RTClib?tab=readme-ov-file)  
    : Adafruit사에서 만든 아두이노의 기본 RTC 기능에 대한 라이브러리입니다. DS1307, DS3231 및 PCF8523 지원됩니다.   
- [Adafruit-SSD1306](https://github.com/adafruit/Adafruit_SSD1306)  
    : Adafruit사에서 만든 SSD1306을 위한 라이브러리. 로고가 안보이도록 하려면 몇가지 [수정](https://www.youtube.com/watch?v=0xcp01De9so)이 필요하다.
### uRTCLib의 주요 기능 
1. rtc.set()
2. rtc.refresh() 

### Adafuit_SSD1306의 주요 기능  
1. display.display()
2. display.cleardisplay()

## 응용하기  
1. D-day 기능 만들기: 굉장히 오래 전부터 지금까지에 대한 시간
2. Alarm 기능 만들기: 10초 후에 뭔가 발생하는 것 만들기 




