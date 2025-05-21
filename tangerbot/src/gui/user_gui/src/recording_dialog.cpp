#include "user_gui/recording_dialog.h"

#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QAudioDeviceInfo>
#include <QDebug>

RecordingDialog::RecordingDialog(QWidget *parent) : QDialog(parent), audio_input(nullptr), audio_file(nullptr)
{
    if (QFile::exists("output.wav")) {
        QFile::remove("output.wav");
    }

    setWindowTitle("Voice Recording");
    setModal(true);

    label = new QLabel("Speak!", this);
    label->setAlignment(Qt::AlignCenter);

    btn_stop = new QPushButton("⏹ Stop", this);
    btn_cancel = new QPushButton("Cancel", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(btn_stop);
    layout->addWidget(btn_cancel);

    connect(btn_stop, &QPushButton::clicked, this, &RecordingDialog::stop_recording);
    checkMicrophones();
    format.setSampleRate(44100);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);

    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if (!info.isFormatSupported(format)) {
        format = info.nearestFormat(format);
    }

    foreach (const QAudioDeviceInfo &deviceInfo, QAudioDeviceInfo::availableDevices(QAudio::AudioInput)) {
        qDebug() << "Found device:" << deviceInfo.deviceName();
        if (deviceInfo.deviceName().contains("ALC233")) {
            info = deviceInfo;
            break;
        }
    }

    audio_file = new QFile("output.wav", this);
    if (!audio_file->open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Error", "file open failed");
        reject();
        return;
    }

    write_wav_header();

    audio_input = new QAudioInput(format, this);
    audio_input->start(audio_file);
}

void RecordingDialog::write_wav_header() {
    QByteArray header;
    QDataStream out(&header, QIODevice::WriteOnly);
    out.setByteOrder(QDataStream::LittleEndian);
    out.writeRawData("RIFF", 4);
    out << quint32(0); // placeholder for file size
    out.writeRawData("WAVE", 4);
    out.writeRawData("fmt ", 4);
    out << quint32(16); // size of fmt chunk
    out << quint16(1);  // PCM
    out << quint16(format.channelCount());
    out << quint32(format.sampleRate());
    out << quint32(format.sampleRate() * format.channelCount() * format.sampleSize() / 8); // byte rate
    out << quint16(format.channelCount() * format.sampleSize() / 8); // block align
    out << quint16(format.sampleSize());
    out.writeRawData("data", 4);
    out << quint32(0); // placeholder for data size

    audio_file->write(header);
}

void RecordingDialog::update_wav_header() {
    quint32 file_size = audio_file->size();
    quint32 data_size = file_size - 44;
    audio_file->seek(4);
    QDataStream out(audio_file);
    out.setByteOrder(QDataStream::LittleEndian);
    out << quint32(file_size - 8); // file size - 8
    audio_file->seek(40);
    out << quint32(data_size); // data chunk size
}

void RecordingDialog::stop_recording()
{
    if (audio_input) {
        audio_input->stop();
        update_wav_header();
        audio_file->close();
        label->setText("Finish recording!");

        if (!audio_file->open(QIODevice::ReadOnly)) {
            qWarning() << "Cannot open file for reading";
            return;
        }
        QByteArray audio_data = audio_file->readAll();
        audio_file->close();
        // auto msg = tangerbot_msgs::msg::AudioData();
        // msg.filename = "output.wav";
        // msg.data = std::vector<uint8_t>(audioData.begin(), audioData.end());
        // publisher_->publish(msg);
    }
}

RecordingDialog::~RecordingDialog()
{
    delete audio_input;
    delete audio_file;
}


void RecordingDialog::checkMicrophones() {
    QList<QAudioDeviceInfo> devices = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);

    if (devices.isEmpty()) {
        qDebug() << "🎤 No audio input devices found!";
    } else {
        qDebug() << "🎙️ Available audio input devices:";
        for (const QAudioDeviceInfo &device : devices) {
            qDebug() << " -" << device.deviceName();
        }
    }
}