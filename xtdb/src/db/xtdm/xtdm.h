#ifndef XTDM_H
#define XTDM_H
#include <string>
namespace xtdb {
class XtDM
{
public:
    static std::string cellViewNmToFilePath(const std::string& pCellViewNm);
};
}
#endif // XTDM_H
