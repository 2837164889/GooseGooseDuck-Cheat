//https://github.com/Tencent/rapidjson/blob/master/example/simpledom/simpledom.cpp

#include "config.hpp"

bool initialize_config(config_container& cont) {

    FILE* fp = nullptr;

    if (0 == fopen_s(&fp, "data.json", "r")) {

        char readBuffer[65536];
        FileReadStream is(fp, readBuffer, sizeof(readBuffer));

        Document d;
        d.ParseStream(is);

        fclose(fp);

        StringBuffer buffer;
        Writer<StringBuffer> writer(buffer);
        d.Accept(writer);

        cont.canDrawESP = d["cheat"]["canDrawESP"].GetBool();
        cont.drawBox = d["cheat"]["drawBox"].GetBool();
        cont.drawLine = d["cheat"]["drawLine"].GetBool();
        cont.showPlayerInfo = d["cheat"]["showPlayerInfo"].GetBool();

        return true;

    }
    else return false;

}

bool save_config() {

}

bool reload_config() {

}