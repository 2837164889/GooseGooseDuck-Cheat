#pragma once

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

#include "struct.hpp"

#include <iostream>
#include <fstream>

using namespace rapidjson;
using namespace std;

bool initialize_config(config_container& cont);