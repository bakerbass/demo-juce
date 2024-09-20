/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DemoPluginAudioProcessorEditor::DemoPluginAudioProcessorEditor (DemoPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
    // set up the slider
    addAndMakeVisible(newSlider);
    newSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    newSlider.setRange(-1.f, 1.f);
    newSlider.setValue(1.f);
    // grab the parameter from audio processor
    auto ParameterTree = audioProcessor.getParameters();
    newSliderParameter   = (juce::AudioParameterFloat*) ParameterTree.getUnchecked(0);
    // Update parameter with slider val
    newSlider.onValueChange = [this]
    {
        *newSliderParameter = newSlider.getValue();
    };
}

DemoPluginAudioProcessorEditor::~DemoPluginAudioProcessorEditor()
{
}

//==============================================================================
void DemoPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
//
//    g.setColour (juce::Colours::white);
//    g.setFont (15.0f);
//    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void DemoPluginAudioProcessorEditor::resized()
{
    newSlider.setBounds(getLocalBounds().reduced(50));
}
