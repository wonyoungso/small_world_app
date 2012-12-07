//
//  LinkEvent.h
//  small_world_app
//
//  Created by Wonyoung So on 12. 12. 6..
//
//

#pragma once

namespace small_world {
    class LinkEvent {
    public:
        LinkEvent();
        ~LinkEvent();
    private:
        Vec2i position;
    } 
}