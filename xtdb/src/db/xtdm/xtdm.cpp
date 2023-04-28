#include "xtdm.h"
#include <filesystem>
namespace xtdb {
std::string XtDM::cellViewNmToFilePath(const std::string& pCellViewNm)
{
    size_t slashIndex = pCellViewNm.find('/');
    std::string cellNm = pCellViewNm.substr(0, slashIndex);
    std::string viewNm = pCellViewNm.substr(slashIndex + 1, std::string::npos);
    std::filesystem::path cellViewPath = ".";
    return (cellViewPath / cellNm / viewNm).string();
}
}
