#include "cinder/app/AppCocoaTouch.h"
#include "cinder/app/Renderer.h"
#include "cinder/Surface.h"
#include "cinder/gl/Texture.h"
#include "cinder/Camera.h"
#include "cinder/Vector.h"

#include "fieldkit/FieldKit.h"
#include "fieldkit/Logger.h"
#include "fieldkit/ConfigDict.h"

using namespace ci;
using namespace ci::app;
using namespace fk;
using namespace std;

class small_world_app : public AppCocoaTouch {
  public:
	virtual void	setup();
	virtual void	resize( int width, int height );
	virtual void	update();
	virtual void	draw();
	virtual void	mouseDown( ci::app::MouseEvent event );
		
	ci::Matrix44f	mCubeRotation;
	ci::gl::Texture mTex;
	ci::CameraPersp	mCam;
private:
    fk::ConfigDict config;
};

void small_world_app::setup()
{
    // load config
    try{
        config.loadXML(loadResource("config.xml"));
    } catch(std::exception &e){
        LOG_ERROR("Couldnt read configuration file");
        _exit(0);
    }
    
    config.print();

    /// end load config
    
    
	mCubeRotation.setToIdentity();

	// Create a blue-green gradient as an OpenGL texture
	Surface8u surface( 256, 256, false );
	Surface8u::Iter iter = surface.getIter();
	while( iter.line() ) {
		while( iter.pixel() ) {
			iter.r() = 0;
			iter.g() = iter.x();
			iter.b() = iter.y();
		}
	}
	
	mTex = gl::Texture( surface );
}

void small_world_app::resize( int width, int height )
{
	mCam.lookAt( Vec3f( 3, 2, -3 ), Vec3f::zero() );
	mCam.setPerspective( 60, width / (float)height, 1, 1000 );
}

void small_world_app::mouseDown( MouseEvent event )
{
	std::cout << "Mouse down @ " << event.getPos() << std::endl;
}

void small_world_app::update()
{
	mCubeRotation.rotate( Vec3f( 1, 1, 1 ), 0.03f );
}

void small_world_app::draw()
{
	gl::clear( Color( 0.2f, 0.2f, 0.3f ) );

}

CINDER_APP_COCOA_TOUCH( small_world_app, RendererGl )
