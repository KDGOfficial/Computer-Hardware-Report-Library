#include <iostream>
#include <string>

using namespace std;

// Интерфейс для устройств (Реализация)
class Device {
public:
    virtual string GetDetails() const = 0; // Чисто виртуальный метод для получения характеристик
    virtual ~Device() = default; // Виртуальный деструктор
};

// Конкретное устройство: Видеокарта
class VideoCard : public Device {
public:
    string GetDetails() const override {
        return "Video Card: NVIDIA RTX 3080, 10GB GDDR6X, 1.71 GHz";
    }
};

// Конкретное устройство: Процессор
class Processor : public Device {
public:
    string GetDetails() const override {
        return "Processor: Intel Core i9-12900K, 16 cores, 5.2 GHz";
    }
};

// Конкретное устройство: Жесткий диск
class HardDrive : public Device {
public:
    string GetDetails() const override {
        return "Hard Drive: Samsung SSD 1TB, 3500 MB/s read, 3000 MB/s write";
    }
};

// Конкретное устройство: Оперативная память (RAM)
class RAM : public Device {
public:
    string GetDetails() const override {
        return "RAM: 32GB DDR5, 6000 MHz, CL36";
    }
};

// Абстракция: Базовый класс для отчетов
class Report {
protected:
    Device* device; // Указатель на устройство (мост между абстракцией и реализацией)
public:
    Report(Device* dev) : device(dev) {}
    virtual void GenerateReport() const = 0; // Чисто виртуальный метод для генерации отчета
    virtual ~Report() = default; // Виртуальный деструктор
};

// Конкретный отчет: Простой отчет
class SimpleReport : public Report {
public:
    SimpleReport(Device* dev) : Report(dev) {}

    void GenerateReport() const override {
        cout << "Simple Report: " << device->GetDetails() << endl;
    }
};

// Конкретный отчет: Детализированный отчет
class DetailedReport : public Report {
public:
    DetailedReport(Device* dev) : Report(dev) {}

    void GenerateReport() const override {
        cout << "Detailed Report:\n";
        cout << "Device Information: " << device->GetDetails() << "\n";
        cout << "Additional Notes: This device is fully compatible with the system.\n";
    }
};

// Тестирование библиотеки
int main() {
    // Создаем устройства
    VideoCard videoCard;
    Processor processor;
    HardDrive hardDrive;
    RAM ram;

    // Создаем отчеты
    SimpleReport simpleVideoCardReport(&videoCard);
    DetailedReport detailedProcessorReport(&processor);
    SimpleReport simpleHardDriveReport(&hardDrive);
    DetailedReport detailedHardDriveReport(&hardDrive);
    SimpleReport simpleRAMReport(&ram);
    DetailedReport detailedRAMReport(&ram);

    // Генерируем отчеты
    simpleVideoCardReport.GenerateReport();
    detailedProcessorReport.GenerateReport();
    simpleHardDriveReport.GenerateReport();
    detailedHardDriveReport.GenerateReport();
    simpleRAMReport.GenerateReport();
    detailedRAMReport.GenerateReport();

    return 0;
}
