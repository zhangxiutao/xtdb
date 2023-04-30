#ifndef XTDM_H
#define XTDM_H
#include <filesystem>
namespace xtdb {
class XtDM
{
public:
    static std::filesystem::path cellViewNmToFilePath(const std::string& pCellViewNm);
};
}
#endif // XTDM_H
