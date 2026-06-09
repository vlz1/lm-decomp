#include "Koga/MissionMode.hpp"
#include <JSystem/JKernel/JKRFileFinder.hpp>
#include <JSystem/JKernel/JKRArchive.hpp>
#include "Koga/MapColl.hpp"
#include "Koga/EnTypesManager.hpp"
#include "Koga/EnManager.hpp"
#include "Koga/EnemyGenManager.hpp"
#include "Koga/JMPMessage.hpp"
#include "Koga/CharacterColManager.hpp"
#include "Koga/SimpleModeler.hpp"
#include "Koga/ToolData.hpp"
#include <stdio.h>

dummy_float_data()

//TODO: Remove these
extern int sCurMapNo;
extern JKRArchive* fn_80006930(const char*, s32);

namespace Koga {

    MissionMode::MissionMode()
        : GameMode()
        , mEnTypesMgr(nullptr)
        , mEnMgr(nullptr)
        , mEnGenMgr(nullptr)
        , mMapData(nullptr)
        , mJmpCount(0)
        , mMapArchive(nullptr)
        , mCharColMgr(nullptr)
        , mJmpMsgSender(nullptr)
    {
        MapColl::newMapColl();
        EnTypesManager::newManager();
        mEnTypesMgr = EnTypesManager::getManager();
        mEnMgr = new EnManager();
        mCharColMgr = new CharacterColManager();
        mJmpMsgSender = new JmpMessageSender();
        mEnGenMgr = new EnemyGenManager();
        SimpleModeler::newSimpleModeler();

        init();
    }

    MissionMode* Koga::MissionMode::create() {
        // If we are on the TitleScreen
        if (Koga::GameModeBase::getGameModeCount() == 0)
            sMissionMode = new Koga::MissionMode();
        return sMissionMode;
    }

    //Needed for data ordering
    void unk() {
        char data[10];
        sprintf(data, "/Map/map");
    }

    void MissionMode::init() {
        char mapName[128];

        sprintf(mapName, "%s%d.szp", "/Map/map", sCurMapNo);
        mMapArchive = fn_80006930(mapName, 0);

        mEnMgr->load(mMapArchive);
        s32 jmpFileCount = mMapArchive->countFile("/jmp") - 2;

        if (jmpFileCount > 0) {
            mJmpCount = jmpFileCount;
            mMapData = new ToolData[jmpFileCount];

            JKRFileFinder* jmpFile = mMapArchive->getFirstFile("/jmp");
            for (int i = 0; i < jmpFileCount; i++, jmpFile->findNextFile()) {
                //Why the space lol
                mMapData[i].attach((ToolData::JMapData*)mMapArchive->getResource('JMP ', jmpFile->mBase.mFileName));
            }
            delete jmpFile;
        }
        mJmpMsgSender->fn_800EA900(getMapSectionData("ObjInfo"));
        mJmpMsgSender->fn_800EA900(getMapSectionData("CharacterInfo"));
        mJmpMsgSender->fn_800EA900(getMapSectionData("KeyInfo"));
        mJmpMsgSender->fn_800EA900(getMapSectionData("GeneratorInfo"));
        mJmpMsgSender->fn_800EA900(getMapSectionData("EnemyInfo"));
        mJmpMsgSender->fn_800EA900(getMapSectionData("ObserverInfo"));

        mJmpMsgSender->addListener(mEnMgr);
    }

    ToolData* MissionMode::getMapSectionData(const char* name) {
        ToolData jmpToolData;
        jmpToolData.attach((ToolData::JMapData*)mMapArchive->getResource('JMP ', name));
        ToolData* mapData = &mMapData[0];
        ToolData* maxData = &mMapData[mJmpCount];

        for (int i = 0; mapData != maxData; i++, mapData = &mMapData[i]) {}

        if (mapData == maxData && mapData->getJMapData() == 0)
            return nullptr;

        return mapData;
    }
}
