#include <iostream>
using namespace std;

class Person_Detection
{

    string person_hall1;
    string person_hall2;

public:
    string detect_person1()
    {
        return person_hall1;
    }

    string detect_person2()
    {
        return person_hall2;
    }
    Person_Detection(string person1, string person2)
    {
        person_hall1 = person1;
        person_hall2 = person2;
    }
    Person_Detection() {}
};

class Fan_control
{

    string fan_hall1;
    string fan_hall2;

public:
    void fan_on_off(string x, string y)
    {

        if (x == "present" && y == "present")
        {
            fan_hall1 = "on";
            fan_hall2 = "on";
        }
        else if (x == "absent" && y == "absent")
        {
            fan_hall1 = "off";
            fan_hall2 = "off";
        }
        else if (x == "present" && y == "absent")
        {
            fan_hall1 = "on";
            fan_hall2 = "off";
        }
        else if (x == "absent" && y == "present")
        {
            fan_hall1 = "off";
            fan_hall2 = "on";
        }
    }

    string get_fan_hall1()
    {
        return fan_hall1;
    }
    string get_fan_hall2()
    {
        return fan_hall2;
    }
    // Fan_control(string x, string y) {
    //     fan_hall1 = x;
    //     fan_hall2 = y;
    // }

    Fan_control() {}
};

class Light_Control
{
    string hall1_light_intensity;
    string hall2_light_intensity;

    string Light1;
    string Light2;

public:
    void light_on_off(string x, string y)
    {
        if (x == "present" && y == "present")
        {
            hall1_light_intensity = "low";
            hall2_light_intensity = "low";
            Light1 = "on";
            Light2 = "on";
        }
        else if (x == "absent" && y == "absent")
        {
            hall1_light_intensity = "lights off";
            hall2_light_intensity = "lights off";
            Light1 = "off";
            Light2 = "off";
        }
        else if (x == "present" && y == "absent")
        {
            hall1_light_intensity = "low";
            hall2_light_intensity = "lights off";
            Light1 = "on";
            Light2 = "off";
        }
        else if (x == "absent" && y == "present")
        {
            hall1_light_intensity = "lights off";
            hall2_light_intensity = "low";
            Light1 = "off";
            Light2 = "on";
        }
    }

    string get_light_Intensity_hall1()
    {
        return hall1_light_intensity;
    }
    string get_light_Intensity_hall2()
    {
        return hall2_light_intensity;
    }

    string get_light1()
    {
        return Light1;
    }

    string get_light2()
    {
        return Light2;
    }
    
    Light_Control() {}
};

class Smart_Home : public Fan_control, public Light_Control, public Person_Detection
{
public:
    Smart_Home(string person1, string person2) : Person_Detection(person1, person2){};

    void Hall1_display()
    {
        cout << "Hall1" << endl;
        cout << "Person:            " << detect_person1() << endl;
        cout << "Fan:               " << get_fan_hall1() << endl;
        cout << "Light Intensity:   " << get_light_Intensity_hall1() << endl;
        cout << "Light:             " << get_light1() << endl;
    }

    void Hall2_display()
    {
        cout << "Hall2" << endl;
        cout << "Person:            " << detect_person2() << endl;
        cout << "Fan:               " << get_fan_hall2() << endl;
        cout << "Light Intensity:   " << get_light_Intensity_hall2() << endl;
        cout << "Light:             " << get_light2() << endl;
    }
};

int main()

{
    int a = 1;
    while (a == 1)
    {
        string status1;
        string status2;

        cout << "Availability of person in Hall1: ";
        cin >> status1;

        cout << "Availability of person in Hall2: ";
        cin >> status2;

        Smart_Home Hall1(status1, status2);
        Hall1.light_on_off(status1, status2);
        Hall1.fan_on_off(status1, status2);

        Hall1.Hall1_display();
        Hall1.Hall2_display();

        cout << "To continue -  Press 1: ";
        cin >> a;
    }

    return 0;
}