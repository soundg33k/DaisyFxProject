#include "daisy_petal.h"
#include "terrarium.h"
 
 daisy::DaisyPetal hardware;
 daisy::Led led1, led2;

void audioCallback(daisy::AudioHandle::InputBuffer in, daisy::AudioHandle::OutputBuffer out, size_t sampleCount)
 {
    // Do a passthrough 
    for(size_t i = 0; i < sampleCount; i += 2)
    {
        (*out)[i] = (*in)[i];
        (*out)[i+1] = (*in)[i+1];
    }
 }

// This function can be removed. 
// This is simply to test the pedal hardware
// To test, put all of the knobs at the minimum values and the switches in the up position.
// Led1 will turn on when a knob passes the half position.
// Led2 will turn on when a switch is set in the down position or a footswitch is pressed.
void testTerrariumHardware()
{
    static bool bKnob1 = false;
    static bool bKnob2 = false;
    static bool bKnob3 = false;
    static bool bKnob4 = false;
    static bool bKnob5 = false;
    static bool bKnob6 = false;

    static bool bSw1 = false;
    static bool bSw2 = false;
    static bool bSw3 = false;
    static bool bSw4 = false;

    static bool bFtSw1 = false;
    static bool bFtSw2 = false;

    bool bKnob1Current = hardware.knob[terrarium::Terrarium::KNOB_1].GetRawFloat() > 0.5f;
    bool bKnob2Current = hardware.knob[terrarium::Terrarium::KNOB_2].GetRawFloat() > 0.5f;
    bool bKnob3Current = hardware.knob[terrarium::Terrarium::KNOB_3].GetRawFloat() > 0.5f;
    bool bKnob4Current = hardware.knob[terrarium::Terrarium::KNOB_4].GetRawFloat() > 0.5f;
    bool bKnob5Current = hardware.knob[terrarium::Terrarium::KNOB_5].GetRawFloat() > 0.5f;
    bool bKnob6Current = hardware.knob[terrarium::Terrarium::KNOB_6].GetRawFloat() > 0.5f;

    bool bSwitch1Current = hardware.switches[terrarium::Terrarium::SWITCH_1].RawState();
    bool bSwitch2Current = hardware.switches[terrarium::Terrarium::SWITCH_2].RawState();
    bool bSwitch3Current = hardware.switches[terrarium::Terrarium::SWITCH_3].RawState();
    bool bSwitch4Current = hardware.switches[terrarium::Terrarium::SWITCH_4].RawState();

    bool bFtSw1Current = !hardware.switches[terrarium::Terrarium::FOOTSWITCH_1].RawState();
    bool bFtSw2Current = !hardware.switches[terrarium::Terrarium::FOOTSWITCH_2].RawState();

    hardware.ProcessAllControls();

    if (bKnob1Current != bKnob1)
    {
        led1.Set(bKnob1 ? 0.f : 1.f);
        led1.Update();
        bKnob1 = bKnob1Current;
    }
    else if (bKnob2Current != bKnob2)
    {
        led1.Set(bKnob2 ? 0.f : 1.f);
        led1.Update();
        bKnob2 = bKnob2Current;
    }
    else if (bKnob3Current != bKnob3)
    {
        led1.Set(bKnob3 ? 0.f : 1.f);
        led1.Update();
        bKnob3 = bKnob3Current;
    }
    else if (bKnob4Current != bKnob4)
    {
        led1.Set(bKnob4 ? 0.f : 1.f);
        led1.Update();
        bKnob4 = bKnob4Current;
    }
    else if (bKnob5Current != bKnob5)
    {
        led1.Set(bKnob5 ? 0.f : 1.f);
        led1.Update();
        bKnob5 = bKnob5Current;
    }
    else if (bKnob6Current != bKnob6)
    {
        led1.Set(bKnob6 ? 0.f : 1.f);
        led1.Update();
        bKnob6 = bKnob6Current;
    }

    if (bSwitch1Current != bSw1)
    {
        led2.Set(bSwitch1Current ? 0.f : 1.f);
        led2.Update();
        bSw1 = bSwitch1Current;
    }
    else if (bSwitch2Current != bSw2)
    {
        led2.Set(bSwitch2Current ? 0.f : 1.f);
        led2.Update();
        bSw2 = bSwitch2Current;
    }
    else if (bSwitch3Current != bSw3)
    {
        led2.Set(bSwitch3Current ? 0.f : 1.f);
        led2.Update();
        bSw3 = bSwitch3Current;
    }
    else if (bSwitch4Current != bSw4)
    {
        led2.Set(bSwitch4Current ? 0.f : 1.f);
        led2.Update();
        bSw4 = bSwitch4Current;
    }

    if (bFtSw1Current != bFtSw1)
    {
        led2.Set(bFtSw1Current ? 0.f : 1.f);
        led2.Update();
        bFtSw1 = bFtSw1Current;
    }
    else if (bFtSw2Current != bFtSw2)
    {
        led2.Set(bFtSw2Current ? 0.f : 1.f);
        led2.Update();
        bFtSw2 = bFtSw2Current;
    }
}

int main()
{
    hardware.Init();

    led1.Init(hardware.seed.GetPin(terrarium::Terrarium::LED_1),false);
    led2.Init(hardware.seed.GetPin(terrarium::Terrarium::LED_2),false);

    hardware.SetAudioBlockSize(12);

    hardware.StartAdc();
    hardware.StartAudio(audioCallback);

    while (true)
    {
        testTerrariumHardware();
        hardware.DelayMs(100);
    }
}