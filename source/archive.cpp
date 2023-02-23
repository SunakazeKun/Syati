#include "syati.h"
#include "sample/archive.h"

namespace syati {
    JKRArchive* loadArchive(const char *pArchivePath) {
        bool isExist = MR::isFileExist(pArchivePath, false);

        if (isExist) {
            void* rawData = MR::loadToMainRAM(pArchivePath, 0, MR::getStationedHeapNapa(), 1);
            OSReport("loaded into ram\n");
            OSReport("raw data ptr: %p\n");

            FileLoader* ldr = SingletonHolder<FileLoader>::sInstance;
            JKRArchive* arch = ldr->createAndAddArchive(rawData, 0, pArchivePath);
            OSReport("added archive\n");

            return arch;
        }

        OSReport("file %s not found!!\n", pArchivePath);
        return NULL;
    }

    void* loadResourceFromArchive(const char *pArchivePath, const char *pFile) {
        FileLoader* ldr = SingletonHolder<FileLoader>::sInstance;
        JKRArchive* archive = ldr->mArchiveHolder->getArchive(pArchivePath);

        if (archive) {
            void* data = archive->getResource(pFile);

            if (data) {
                OSReport("data found! returning\n");
                return data;
            }
            else {
                OSReport("FILE %s NOT FOUND!!\n", pFile);
            }
        }
        else {
            OSReport("FILE %s NOT FOUND!!\n", pArchivePath);
        }

        return NULL;
    }
};
