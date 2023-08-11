#include "textfileencoder.h"
#include <QStringConverter>
#include <QByteArray>
#include <QTextStream>

TextFileEncoder::TextFileEncoder()
{

}

/**
 * @brief convert text file endcode from sen to ten.
 *        sdir and tdir must are diectory with file name.
 *        it is best to have a file suffix.
 * @param sdir source directory
 * @param tdir target directory
 * @param sen source encode
 * @param ten targer encode
 * @return is convert successful
 */
bool convert_text_file(const QString& sdir, const QString& tdir, const QString& sen, const QString& ten)
{
    //QString sourceFilePath = sdir;
    //QString targetFilePath = tdir;

    //QFile sourceFile(sourceFilePath);
    //QFile targetFile(targetFilePath);

    //if (sourceFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    //    if (targetFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
    //        QTextStream in(&sourceFile);
    //        QTextStream out(&targetFile);

    //        // 创建编码转换器
    //        QStringConverter converter(ten.toUtf8(), sen.toUtf8());

    //        // 逐行读取源文件并写入目标文件
    //        while (!in.atEnd()) {
    //            QString line = in.readLine();

    //            // 使用编码转换器转换文本编码
    //            QByteArray convertedData = converter.fromUnicode(line);
    //            QString convertedLine = QString::fromUtf8(convertedData);

    //            out << convertedLine << endl;
    //        }

    //        targetFile.close();
    //    }

    //    sourceFile.close();
    //    return true;
    //}

    return false;
}

//bool TextFileEncoder::convert_text_file(const QString &sdir, const QString &tdir, const QString &sen, const QString &ten)
//{
//    QString sourceFilePath = sdir;
//    QString targetFilePath = tdir;

//    QFile sourceFile(sourceFilePath);
//    QFile targetFile(targetFilePath);

//    if (sourceFile.open(QIODevice::ReadOnly | QIODevice::Text) &&
//            targetFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
//            QTextStream in(&sourceFile);
//            QTextStream out(&targetFile);

//            // 设置源文件的编码
//#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
//            //qt 5
//            QTextCodec* codec1 = QTextCodec::codecForName(sen.toUtf8());
//            in.setCodec(codec1);
//#else
//            // qt 6
//            auto iba=sen.toLatin1();
//            auto ichar=iba.data();
//            in.setEncoding(QStringConverter::encodingForName(ichar));
//#endif
//            // 设置目标文件的编码
//#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
//            //qt 5
//            QTextCodec* codec2 = QTextCodec::codecForName(ten.toUtf8());
//            out.setCodec(codec2);
//#else
//            // qt 6
//            auto oba=ten.toLatin1();
//            auto ochar=oba.data();
//            out.setEncoding(QStringConverter::encodingForName(ochar));
//#endif

//            // 逐行读取源文件并写入目标文件
//            while (!in.atEnd()) {
//                QString line = in.readLine();
//                out << line << std::endl;
//            }

//            targetFile.close();
//            sourceFile.close();
//            return true;
//    }
//    return false;
//}
