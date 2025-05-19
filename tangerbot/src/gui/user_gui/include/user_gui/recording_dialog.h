#ifndef RECORDING_DIALOG_H
#define RECORDING_DIALOG_H

#include <QDialog>
#include <QAudioInput>
#include <QFile>
#include <QLabel>

class RecordingDialog : public QDialog {
public:
    explicit RecordingDialog(QWidget *parent = nullptr);
    ~RecordingDialog();

private slots:
    void write_wav_header();
    void update_wav_header();
    void stop_recording();
    void cancel_recording();
    void checkMicrophones();

private:
    QLabel *label;
    QPushButton *btn_stop;
    QPushButton *btn_cancel;

    QAudioInput *audio_input;
    QAudioFormat format;
    QFile *audio_file;
    QFile *output_file;
};

#endif // RECORDING_DIALOG_H