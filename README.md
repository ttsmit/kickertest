# RTT Chipper/Kicker Tester

Small ardruino programm to test the RoboTeam Twente kicker and chipper. 

## Installation

Upload the programm to an ardruino with [PlatformIO](https://platformio.org/). 

```bash
pio run --target upload
```

## Usage
Connect the pins below to the micor controller (micro_cont) on the bottom board. 

| Ard. pin | micro_cont |
| -------- | ---------- |
| d2       | done       |
| d3       | kick       |
| d4       | chip       |
| d5       | charge     |

The build-in led will blink for half a second, indicating that the capacitor is being charged. Thereafter, it will blink shortly indicating that the kicker is addressed. 

