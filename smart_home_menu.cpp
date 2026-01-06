#include <iostream>
#include <string>
using namespace std;

/* Base Class */
class Device {
protected:
    string name;
    bool status;

public:
    Device(string n) {
        name = n;
        status = false;
    }

    virtual void turnOn() {
        status = true;
        cout << name << " is ON" << endl;
    }

    virtual void turnOff() {
        status = false;
        cout << name << " is OFF" << endl;
    }

    virtual void showStatus() {
        cout << name << " status: " << (status ? "ON" : "OFF") << endl;
    }
};

/* Light */
class Light : public Device {
private:
    int brightness;

public:
    Light(string n) : Device(n) {
        brightness = 50;
    }

    void setBrightness(int b) {
        brightness = b;
        cout << name << " brightness set to " << brightness << "%" << endl;
    }
};

/* Fan */
class Fan : public Device {
private:
    int speed;

public:
    Fan(string n) : Device(n) {
        speed = 1;
    }

    void setSpeed(int s) {
        speed = s;
        cout << name << " speed set to " << speed << endl;
    }
};

/* Thermostat */
class Thermostat : public Device {
private:
    int temperature;

public:
    Thermostat(string n) : Device(n) {
        temperature = 22;
    }

    void setTemperature(int t) {
        temperature = t;
        cout << name << " temperature set to " << temperature << "°C" << endl;
    }
};

/* Smart Home Controller */
class SmartHome {
private:
    Device* devices[3];

public:
    SmartHome(Device* d1, Device* d2, Device* d3) {
        devices[0] = d1;
        devices[1] = d2;
        devices[2] = d3;
    }

    void showAllDevices() {
        cout << "\nDevice Status:\n";
        for (int i = 0; i < 3; i++) {
            devices[i]->showStatus();
        }
    }
};

int main() {
    Light light("Living Room Light");
    Fan fan("Ceiling Fan");
    Thermostat thermostat("Thermostat");

    SmartHome home(&light, &fan, &thermostat);

    int choice;

    do {
        cout << "\n--- Smart Home Menu ---\n";
        cout << "1. Turn ON Light\n";
        cout << "2. Turn OFF Light\n";
        cout << "3. Set Light Brightness\n";
        cout << "4. Turn ON Fan\n";
        cout << "5. Turn OFF Fan\n";
        cout << "6. Set Fan Speed\n";
        cout << "7. Turn ON Thermostat\n";
        cout << "8. Turn OFF Thermostat\n";
        cout << "9. Set Temperature\n";
        cout << "10. Show All Device Status\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                light.turnOn();
                break;
            case 2:
                light.turnOff();
                break;
            case 3: {
                int b;
                cout << "Enter brightness (0–100): ";
                cin >> b;
                light.setBrightness(b);
                break;
            }
            case 4:
                fan.turnOn();
                break;
            case 5:
                fan.turnOff();
                break;
            case 6: {
                int s;
                cout << "Enter fan speed: ";
                cin >> s;
                fan.setSpeed(s);
                break;
            }
            case 7:
                thermostat.turnOn();
                break;
            case 8:
                thermostat.turnOff();
                break;
            case 9: {
                int t;
                cout << "Enter temperature: ";
                cin >> t;
                thermostat.setTemperature(t);
                break;
            }
            case 10:
                home.showAllDevices();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}
