#ifndef TEXTFILEENCODER_H
#define TEXTFILEENCODER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDir>

class TextFileEncoder
{
public:
    TextFileEncoder();

    static bool convert_text_file(const QString& sdir,const QString& tdir,const QString& sen,const QString& ten);

    static void convert_text_files(const QString& sdir, const QString& tdir, const QStringList& slfiles, const QString& encode1, const QString& encode2)
    {
//        foreach (const QString& fileName, slfiles) {
//            QString sourceFilePath = sdir + "/" + fileName;
//            QString targetFilePath = tdir + "/" + fileName;

//            QFile sourceFile(sourceFilePath);
//            QFile targetFile(targetFilePath);

//            if (sourceFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
//                if (targetFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
//                    QTextStream in(&sourceFile);
//                    QTextStream out(&targetFile);

//                    // 设置源文件的编码
//                    QTextCodec* codec1 = QTextCodec::codecForName(encode1.toUtf8());
//                    in.setCodec(codec1);

//                    // 设置目标文件的编码
//                    QTextCodec* codec2 = QTextCodec::codecForName(encode2.toUtf8());
//                    out.setCodec(codec2);

//                    // 逐行读取源文件并写入目标文件
//                    while (!in.atEnd()) {
//                        QString line = in.readLine();
//                        out << line << endl;
//                    }

//                    targetFile.close();
//                }

//                sourceFile.close();
//            }
//        }
    }
};

#endif // TEXTFILEENCODER_H
