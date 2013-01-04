#include "itiotbvectorimageviewerfactory.h"

#include "../widgets/vector/itiotbvectorimageviewer.h"

#include "../widgets/panel/itiotbimageviewerpanel.h"
#include "../widgets/panel/itiotbimageviewerpanelsetuptab.h"

#include "../commands/commandcontrastenhancementgaussian.h"
#include "../commands/commandcontrastenhancementlinear0255.h"
#include "../commands/commandcontrastenhancementlinearxperc.h"
#include "../commands/commandcontrastenhancementsquareroot.h"

using namespace itiviewer;

ItiOtbVectorImageViewerFactory::ItiOtbVectorImageViewerFactory(QObject *parent)
    : ItiOtbImageViewerFactory(parent)
{
}

//!
void ItiOtbVectorImageViewerFactory::createViewer(ItiOtbImageViewerPanel *panel){
    m_pItiOtbImageViewer = new ItiOtbVectorImageViewer();

    ItiOtbImageViewerPanelSetupTab *sTab = panel->setupTab();

    if(sTab){
        Command *cmdGaussian        = createCommandContrastEnhancementGaussian(sTab);
        if(cmdGaussian)
            panel->setCommand(ItiOtbImageViewerPanel::SLOT_CE_GAUSSIAN,cmdGaussian);

        Command *cmdLinear0_255     = createCommandContrastEnhancementLinear0_255(sTab);
        if(cmdLinear0_255)
            panel->setCommand(ItiOtbImageViewerPanel::SLOT_CE_LINEAR_0_255,cmdLinear0_255);

        Command *cmdLinearXPerc     = createCommandContrastEnhancementLinearXPerc(sTab);
        if(cmdLinearXPerc)
            panel->setCommand(ItiOtbImageViewerPanel::SLOT_CE_LINEARXPERC,cmdLinearXPerc);

        Command *cmdSquareRoot      = createCommandContrastEnhancementSquareRoot(sTab);
        if(cmdSquareRoot)
            panel->setCommand(ItiOtbImageViewerPanel::SLOT_CE_SQUAREROOT,cmdSquareRoot);
    }
}


Command* ItiOtbVectorImageViewerFactory::createCommandContrastEnhancementGaussian(ItiOtbImageViewerPanelSetupTab *sTab){
    ItiOtbVectorImageViewer *vv  = qobject_cast<ItiOtbVectorImageViewer*>(m_pItiOtbImageViewer);

    if(!vv)
        return 0;

    CommandContrastEnhancementGaussian *cg = new CommandContrastEnhancementGaussian(vv,this);

    connect(sTab, SIGNAL(deviationChanged(double)),cg, SLOT(updateDeviation(double)));

    return cg;
}


Command* ItiOtbVectorImageViewerFactory::createCommandContrastEnhancementLinear0_255(ItiOtbImageViewerPanelSetupTab *sTab){
    ItiOtbVectorImageViewer *vv  = qobject_cast<ItiOtbVectorImageViewer*>(m_pItiOtbImageViewer);

    if(!vv)
        return 0;

    CommandContrastEnhancementLinear0255 *cl1 = new CommandContrastEnhancementLinear0255(vv,this);

    return cl1;
}


Command* ItiOtbVectorImageViewerFactory::createCommandContrastEnhancementLinearXPerc(ItiOtbImageViewerPanelSetupTab *sTab){
    ItiOtbVectorImageViewer *vv  = qobject_cast<ItiOtbVectorImageViewer*>(m_pItiOtbImageViewer);

    if(!vv)
        return 0;

    CommandContrastEnhancementLinearXPerc *cl2 = new CommandContrastEnhancementLinearXPerc(vv,this);

    connect(sTab,SIGNAL(lowerQuantileChanged(double)),cl2,SLOT(updateLowerQuantile(double)));
    connect(sTab,SIGNAL(upperQuantileChanged(double)),cl2,SLOT(updateUpperQuantile(double)));

    return cl2;
}


Command* ItiOtbVectorImageViewerFactory::createCommandContrastEnhancementSquareRoot(ItiOtbImageViewerPanelSetupTab *sTab){
    ItiOtbVectorImageViewer *vv  = qobject_cast<ItiOtbVectorImageViewer*>(m_pItiOtbImageViewer);

    if(!vv)
        return 0;

    CommandContrastEnhancementSquareRoot *cs = new CommandContrastEnhancementSquareRoot(vv,this);

    connect(sTab,SIGNAL(lowerQuantileChanged(double)),cs,SLOT(updateLowerQuantile(double)));
    connect(sTab,SIGNAL(upperQuantileChanged(double)),cs,SLOT(updateUpperQuantile(double)));

    return cs;
}


ItiOtbVectorImageViewerFactory::~ItiOtbVectorImageViewerFactory(){

}
