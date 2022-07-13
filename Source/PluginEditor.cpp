/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
HelloJuceAudioProcessorEditor::HelloJuceAudioProcessorEditor (HelloJuceAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 300);
    
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    gainSlider.setRange(-60.0f, 0.0f, 0.01f);
    gainSlider.setValue(-20.0f);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
}

HelloJuceAudioProcessorEditor::~HelloJuceAudioProcessorEditor()
{
}

//==============================================================================
void HelloJuceAudioProcessorEditor::paint (juce::Graphics& g)
{
    
    g.fillAll(juce::Colours::black);
    
    // g.setColour (juce::Colours::white);
    // g.setFont (15.0f);
    // g.drawFittedText ("Hello Juce!", getLocalBounds(), juce::Justification::centred, 1);
}

void HelloJuceAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 75, 100, 150);
}

void HelloJuceAudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
    if (slider == &gainSlider)
    {        
        audioProcessor.gain = gainSlider.getValue();
    }
}
