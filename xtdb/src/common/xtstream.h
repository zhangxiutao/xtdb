#ifndef XTSTREAM_H
#define XTSTREAM_H

#include "xttypes.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>

class XtIStream
{
private:
    FILE *mFp;
//    void readError()
//    {
//        throw ZIOError(ferror(_f),
//                     "write failed on database stream; system io error: ");
//    }
public:
    XtIStream(const char *pFileNm)
    {
        mFp = fopen(pFileNm, "r");
    };
    ~XtIStream()
    {
        fclose(mFp);
    }
    void close()
    {
        fclose(mFp);
    }
    XtIStream(FILE *pFp):mFp(pFp){};
    XtIStream& operator>>(unsigned short& pS)
    {
        if (R_ABNORMAL == fread(&pS, sizeof(pS), 1, mFp)) {
//            read_error();
        }
        return *this;
    }
    XtIStream& operator>>(short& pS)
    {
        if (R_ABNORMAL == fread(&pS, sizeof(pS), 1, mFp)) {
//            read_error();
        }
        return *this;
    }
    XtIStream& operator>>(int& pI)
    {
        if (R_ABNORMAL == fread(&pI, sizeof(pI), 1, mFp)) {
//            read_error();
        }
        return *this;
    }
    XtIStream& operator>>(uint& pI)
    {
        if (R_ABNORMAL == fread(&pI, sizeof(pI), 1, mFp)) {
//            read_error();
        }
        return *this;
    }
    XtIStream& operator>>(char*& pC)
    {
        int l;
        *this >> l;
        if (0 == l) {
            pC = nullptr;
        } else {
            pC = (char*)malloc(l);
            if (R_ABNORMAL == fread(pC, l, 1, mFp))
            {
                //read_error();
            }
        }
        return *this;
    }
    XtIStream& operator>>(char& pC)
    {
        if (R_ABNORMAL == fread(&pC, sizeof(pC), 1, mFp))
        {
            //read_error();
        }
        return *this;
    }

};

class XtOStream
{
private:
    FILE *mFp;
//    void writeError()
//    {
//        throw ZIOError(ferror(_f),
//                     "write failed on database stream; system io error: ");
//    }
public:
    XtOStream(const char* pFileNm)
    {
        mFp = fopen(pFileNm, "a");
    };
    XtOStream(FILE *pFp):mFp(pFp){};
    ~XtOStream()
    {
        fclose(mFp);
    }
    void close()
    {
        fclose(mFp);
    }
    XtOStream& operator<<(unsigned short pS)
    {
        if (R_ABNORMAL == fwrite(&pS, sizeof(pS), 1, mFp)) {
//            write_error();
        }
        return *this;
    }
    XtOStream& operator<<(short pS)
    {
        if (R_ABNORMAL == fwrite(&pS, sizeof(pS), 1, mFp)) {
//            write_error();
        }
        return *this;
    }
    XtOStream& operator<<(int pI)
    {
        if (R_ABNORMAL == fwrite(&pI, sizeof(pI), 1, mFp)) {
//            write_error();
        }
        return *this;
    }
    XtOStream& operator<<(uint pI)
    {
        if (R_ABNORMAL == fwrite(&pI, sizeof(pI), 1, mFp)) {
//            write_error();
        }
        return *this;
    }
    XtOStream& operator<<(const char* pC)
    {
        if (pC == NULL) {
          *this << 0;
        } else {
          int l = strlen(pC) + 1;
          *this << l;
          if (R_ABNORMAL == fwrite(pC, l, 1, mFp)) {
//             write_error();
          }
        }
        return *this;
    }
    XtOStream& operator<<(char& pC)
    {
        if (R_ABNORMAL == fwrite(&pC, sizeof(pC), 1, mFp))
        {
            //read_error();
        }
        return *this;
    }
};

#endif // XTSTREAM_H
