#ifndef HISTOGRAMGENERATOR_H
#define HISTOGRAMGENERATOR_H

#include <QObject>

#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif

#include "itkImageToHistogramGenerator.h"
#include "itkImage.h"
#include "itkRGBPixel.h"

#include "itkImageFileReader.h"

#include "otbImageFileWriter.h"
#include "otbVectorRescaleIntensityImageFilter.h"
#include "../viewer/vector_globaldefs.h"

#include <QHash>

const unsigned int                            _Dimension = 2;

class HistogramGenerator : public QObject
{
    Q_OBJECT
public:

    typedef unsigned char                                   PixelComponentType;


    typedef itk::RGBPixel< PixelComponentType >             RGBPixelType;


    typedef itk::Image< RGBPixelType, _Dimension >          RGBImageType;


    typedef itk::Statistics::ImageToHistogramGenerator<
                                RGBImageType >              HistogramGeneratorType;


    typedef HistogramGeneratorType::SizeType                SizeType;


    typedef itk::ImageFileReader< RGBImageType >  ReaderType;


    typedef HistogramGeneratorType::HistogramType  HistogramType;


    explicit HistogramGenerator(QObject *parent = 0);


    ~HistogramGenerator();


    /*!
     * \brief generateHistogram
     * \param path
     */
    void generateHistogram(const QString &path);

    /*!
     * \brief generateHistogram
     *  Oh, there is one thing Greek people say in such an occassion..
     *  Yet another path knows the good fellow..
     *  So dummy implementation, the problem was that the histogram filter was not been able to be
     *  implemented in the gnorasi..
     * \param image
     */
    void generateHistogram(VectorImageType *image);


    double* redChannelFrequency() const { return m_pRedChannelFrequency; }
    double* greenChannelFrequency() const { return m_pGreenChannelFrequency; }
    double* blueChannelFrequency() const { return m_pBlueChannelFrequency; }

    double* redChannelAmplitude() const { return m_pRedChannelAmplitude; }
    double* greenChannelAmplitude() const { return m_pGreenChannelAmplitude; }
    double* blueChannelAmplitude() const { return m_pBlueChannelAmplitude; }

    QHash<int,double> redChannelData() const { return m_redChannelData; }
    QHash<int,double> greenChannelData() const { return m_greenChannelData; }
    QHash<int,double> blueChannelData() const { return m_blueChannelData; }


    //OTB specific stuff***************************************************
    //Default 32 bit image writer
//    typedef double                   DoublePixelType;
//    typedef otb::VectorImage<DoublePixelType, 2> VectorImageType;
    typedef VectorImageType* 		     ImagePointer;
    typedef otb::ImageFileWriter<VectorImageType> WriterType;
    WriterType::Pointer writer;

    //16 bit image writer
    typedef unsigned short             IntegerPixelType;
    typedef otb::VectorImage<IntegerPixelType, 2> IntegerImageType;
    typedef otb::ImageFileWriter<IntegerImageType> IntegerWriterType;
    IntegerWriterType::Pointer int_writer;
    typedef otb::VectorRescaleIntensityImageFilter<
      VectorImageType,
      IntegerImageType>    IntegerRescalerFilterType;
    IntegerRescalerFilterType::Pointer  intrescaler;

    //float image writer
    typedef float             FloatPixelType;
    typedef otb::VectorImage<FloatPixelType, 2> FloatImageType;
    typedef otb::ImageFileWriter<FloatImageType> FloatWriterType;
    FloatWriterType::Pointer float_writer;
    typedef otb::VectorRescaleIntensityImageFilter<
      VectorImageType,
      FloatImageType>    FloatRescalerFilterType;
    FloatRescalerFilterType::Pointer  floatrescaler;

    //8bit image writer
    //TODO: set default???
    typedef unsigned char             BytePixelType;
    typedef otb::VectorImage<BytePixelType, 2> ByteImageType;
    typedef otb::ImageFileWriter<ByteImageType> ByteWriterType;
        ByteWriterType::Pointer byte_writer;
    typedef otb::VectorRescaleIntensityImageFilter<
      VectorImageType,
      ByteImageType>    ByteRescalerFilterType;
    ByteRescalerFilterType::Pointer  byterescaler;

    
signals:
    
public slots:

private:
    HistogramGeneratorType::Pointer histogramGenerator;

    ReaderType::Pointer reader;

    const HistogramType * histogram;

    /*!
     * \brief parseRedChannel
     */
    void parseRedChannel();

    /*!
     * \brief parseGreenChannel
     */
    void parseGreenChannel();

    /*!
     * \brief parseBlueChannel
     */
    void parseBlueChannel();


    QString constructNewName();


    void clearImageRepo();

    double *m_pRedChannelFrequency;
    double *m_pGreenChannelFrequency;
    double *m_pBlueChannelFrequency;

    double *m_pRedChannelAmplitude;
    double *m_pGreenChannelAmplitude;
    double *m_pBlueChannelAmplitude;

    QHash<int, double> m_redChannelData;
    QHash<int, double> m_greenChannelData;
    QHash<int, double> m_blueChannelData;

    QDir m_dir;

};

#endif // HISTOGRAMGENERATOR_H
