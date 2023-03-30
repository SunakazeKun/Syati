#pragma once

#ifdef __cplusplus
extern "C" {
#endif

    void* LMSi_Malloc(size_t size);
    int LMSi_MemCmp(const char *memA, const char *memB, size_t length);

    // void LMS_SetMemFuncs


    // ----------------------------------------------------------------------------------------------------------------


    struct LMS_MessageBlock {
        const char* dataPtr; // _0
        char name[4];        // _4
        size_t dataSize;     // _8
        short _C;            // _C
    };

    struct LMS_MessageBinary {
        const char* src;          // _0
        long fileSize;            // _4
        char encoding;            // _8
        short blocksCount;        // _A
        LMS_MessageBlock* blocks; // _C
    };

    void LMSi_AnalyzeMessageBinary(LMS_MessageBinary *binary, const char *magic);
    void LMSi_AnalyzeMessageHeader(LMS_MessageBinary *binary, const char *magic);
    void LMSi_AnalyzeMessageBlocks(LMS_MessageBinary *binary);

    int LMSi_SearchBlockByName(const LMS_MessageBinary *binary, const char *name);
    int LMSi_GetHashTableIndexFromLabel(const char *label, size_t buckets);


    // ----------------------------------------------------------------------------------------------------------------


    struct LMS_Message {
        LMS_MessageBinary binary; // _0
        int labelsBlock;          // _10
        int textsBlock;           // _14
        int attrsBlock;           // _18
    };

    const LMS_Message* LMS_InitMessage(const char *data);

    int LMS_GetTextIndexByLabel(const LMS_Message *message, const char *label);
    const void* LMS_GetText(const LMS_Message *message, int index);
    const void* LMS_GetTextByLabel(const LMS_Message *message, const char *label);
    const char* LMS_GetAttribute(const LMS_Message *message, int index);


    // ----------------------------------------------------------------------------------------------------------------


    struct LMS_Flowchart {
        LMS_MessageBinary binary; // _0
        int flowsBlock;           // _10
        int labelsBlock;          // _14
        int refsBlock;            // _18
    };

    struct LMS_Node {
        unsigned short type; // _0
        unsigned short arg0; // _2
        unsigned short arg1; // _4
        unsigned short arg2; // _6
        unsigned short arg3; // _8
        unsigned short arg4; // _A
    };

    struct LMS_Branch {
        unsigned short trueIndex;  // _0
        unsigned short falseIndex; // _2
    };

    const LMS_Flowchart* LMS_InitFlowchart(const char *data);

    int LMS_GetNodeNum(const LMS_Flowchart *flowchart);
    int LMS_GetEntryNodeIndex(const LMS_Flowchart *flowchart, const char *label);
    const LMS_Node* LMS_GetNodeDataPtr(const LMS_Flowchart *flowchart, int index);
    int LMS_GetFlowNodeIndex(const LMS_Flowchart *flowchart, const LMS_Node *node);
    const LMS_Branch* LMS_GetNodeBranchPtr(const LMS_Flowchart *flowchart, int index);


#ifdef __cplusplus
}
#endif
