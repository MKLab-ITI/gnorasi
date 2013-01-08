#include "itiotbimageviewerpanel.h"

#include "itiotbimageviewerpaneldatatab.h"
#include "itiotbimageviewerpanelsetuptab.h"
#include "itiotbimageviewerpanelhistogramtab.h"
#include "itiotbimageviewerpanelpixeldescriptiontab.h"

#include "../../commands/command.h"

#include <QVBoxLayout>


using namespace itiviewer;

ItiOtbImageViewerPanel::ItiOtbImageViewerPanel(QWidget *parent) :
    QWidget(parent)
{
    initialize();
}

//!
void ItiOtbImageViewerPanel::initialize(){

    //! the setu tab
    m_pSetupTab = new ItiOtbImageViewerPanelSetupTab(this);

    //! the tab widget
    m_pTabWidget = new QTabWidget(this);

    //! add widgets to the tab
    m_pTabWidget->addTab(m_pSetupTab,m_pSetupTab->windowTitle());

    //! setup connections
    connect(m_pSetupTab,SIGNAL(colorCompositionApplyButtonClicked()),this,SLOT(applyColorComposition()));
    connect(m_pSetupTab,SIGNAL(contrastEnhancementApplyButtonClicked()),this,SLOT(applyConstrastEnhancement()));
    //! connections to establish updating command parameters
    connect(m_pSetupTab,SIGNAL(contrastEnhancementChanged(int,double,double)),this,SIGNAL(contrastEnhancementChanged(int,double,double)));
    connect(m_pSetupTab,SIGNAL(greyScaleColorCompositionChannelChanged(int)),SIGNAL(greyScaleColorCompositionChannelChanged(int)));
    connect(m_pSetupTab,SIGNAL(rgbColorCompositionChannelsChanged(int,int,int)),SIGNAL(rgbColorCompositionChannelsChanged(int,int,int)));
    connect(m_pSetupTab,SIGNAL(applyContrastEnhancementGaussian()),this,SLOT(applyContrastEnhancementGaussian()));
    connect(m_pSetupTab,SIGNAL(applyContrastEnhancementLinear0255()),this,SLOT(applyContrastEnhancementLinear0_255()));
    connect(m_pSetupTab,SIGNAL(applyContrastEnhancementLinearXPerc()),this,SLOT(applyContrastEnhancementLinearXPerc()));
    connect(m_pSetupTab,SIGNAL(applyContrastEnhancementSquareRoot()),this,SLOT(applyContrastEnhancementSquareRoot()));

    //! setup layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_pTabWidget);
    setLayout(layout);
}

//!
void ItiOtbImageViewerPanel::applyColorComposition(){
    Command *pCommand = m_commandHash[(int)SLOT_CC];
    if(pCommand)
        pCommand->execute();
}

//!
void ItiOtbImageViewerPanel::applyConstrastEnhancement(){
    Command *pCommand = m_commandHash[(int)SLOT_CE];
    if(pCommand)
        pCommand->execute();
}

//!
void ItiOtbImageViewerPanel::setCommand(SLOT_KEY cmdk, Command *pC){
    m_commandHash[(int)cmdk] = pC;
}

void ItiOtbImageViewerPanel::applyContrastEnhancementGaussian(){
    Command *pCommand = m_commandHash[(int)SLOT_CE_GAUSSIAN];
    if(pCommand)
        pCommand->execute();
}

void ItiOtbImageViewerPanel::applyContrastEnhancementLinear0_255(){
    Command *pCommand = m_commandHash[(int)SLOT_CE_LINEAR_0_255];
    if(pCommand)
        pCommand->execute();
}

void ItiOtbImageViewerPanel::applyContrastEnhancementLinearXPerc(){
    Command *pCommand = m_commandHash[(int)SLOT_CE_LINEARXPERC];
    if(pCommand)
        pCommand->execute();
}

void ItiOtbImageViewerPanel::applyContrastEnhancementSquareRoot(){
    Command *pCommand = m_commandHash[(int)SLOT_CE_SQUAREROOT];
    if(pCommand)
        pCommand->execute();
}

//!
void ItiOtbImageViewerPanel::setupChannels(){
    m_pSetupTab->setupChannels();
}