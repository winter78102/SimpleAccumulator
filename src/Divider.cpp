#include <Divider/Divider.h>

std::vector<double> Divider::FixDataModel(const std::vector<double> &Storage) {
    std::vector<double> StoreData;
    StoreData.push_back(Storage[0]);
    for (int i = 1; i < Storage.size(); ++i) {
        StoreData.push_back(1 / Storage[i]);
    }
    return StoreData;
}


Divider::Divider() {
    _Symbol = '/';
}

