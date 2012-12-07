//
//  Creator.h
//  small_world_app
//
//  Created by Wonyoung So on 12. 12. 6..
//
//

#pragma once

using namespace ci;
using namespace ci::app;

namespace smallworld {
    class Creator {
    public:
        Creator();
        ~Creator();
    private:
        Vec2i position;
    }
}