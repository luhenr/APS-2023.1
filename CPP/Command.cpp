#include <iostream>
using namespace std;

class Command
{
public:
    virtual void execute() = 0;
};

class Light
{
public:
    void turnOn()
    {
        cout << "A luz esta ligada!" << endl;
    }
};

class LightOnCommand : public Command
{
public:
    LightOnCommand(Light &light) : m_light(light) {}
    void execute() override
    {
        m_light.turnOn();
    }

private:
    Light &m_light;
};

class RemoteControl
{
public:
    void setCommand(Command *command)
    {
        m_command = command;
    }
    void pressButton()
    {
        m_command->execute();
    }

private:
    Command *m_command;
};

int main()
{
    Light light;

    LightOnCommand lightOnCommand(light);
    RemoteControl remoteControl;
    remoteControl.setCommand(&lightOnCommand);
    remoteControl.pressButton();

    return 0;
}