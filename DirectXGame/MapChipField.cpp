#include "MapChipField.h"
#include <map>

namespace {
std::map<std::string, MapChipType> mapChipTable_ = {
    {"0", MapChipType::kBlank},
    {"1", MapChipType::kBlock}
};

}

void ResetMapChipDate() {
    //マップチップデータをリセット
	mapChipDate_.date.clear();
	mapChipDate_.date.resize(kNumBlockVirtical);
}
