#include "Ey3OpenGLRenderer.h"
#include "Ey3SimpleGeometry.h"
#include "Ey3Camera.h"

using namespace Ey3;

OpenGLRenderer::OpenGLRenderer(int w, int h)
: Renderer(w,h)
{
	_type = Renderer::OPENGL;
}

//TODO

void OpenGLRenderer::clearBackBuffer()
{
	glEnable(GL_SCISSOR_TEST);
    glScissor(0,0,width,height);
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
}

void OpenGLRenderer::clearBackBuffer(int xPos, int yPos, int iwidth, int iheight)
{
	glEnable(GL_SCISSOR_TEST);
    glScissor(xPos,yPos,iwidth,iheight);
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
}

void OpenGLRenderer::clearZBuffer()
{
	glEnable(GL_SCISSOR_TEST);
    glScissor(0,0,width,height);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glClear(GL_DEPTH_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
}

void OpenGLRenderer::clearZBuffer(int xPos, int yPos, int iwidth, int iheight)
{
	glEnable(GL_SCISSOR_TEST);
    glScissor(xPos,yPos,iwidth,iheight);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glClear(GL_DEPTH_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
}

void OpenGLRenderer::clearStencilBuffer()
{
	glEnable(GL_SCISSOR_TEST);
    glScissor(0,0,width,height);
    glStencilMask(~0);
    glClear(GL_STENCIL_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
}

void OpenGLRenderer::clearStencilBuffer(int xPos, int yPos, int iwidth, int iheight)
{
	glEnable(GL_SCISSOR_TEST);
    glScissor(xPos,yPos,iwidth,iheight);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glStencilMask(~0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
}

void OpenGLRenderer::clearBuffers()
{
	glEnable(GL_SCISSOR_TEST);
    glScissor(0,0,width,height);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glStencilMask(~0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
}

void OpenGLRenderer::clearBuffers(int xPos, int yPos, int iwidth, int iheight)
{
	glEnable(GL_SCISSOR_TEST);
    glScissor(xPos,yPos,iwidth,iheight);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glStencilMask(~0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
}


void OpenGLRenderer::drawSimple(SimpleGeometry* simple)
{
	glBegin(GL_TRIANGLE_STRIP);

	//char buf[100];

	for(int i = 0; i < simple->getVertexCount(); i++)
	{
		glColor3f(simple->getColors()[i].r,
					simple->getColors()[i].g,
					simple->getColors()[i].b);
		glNormal3f(simple->getNormals()[i].x,
					simple->getNormals()[i].y,
					simple->getNormals()[i].z);
		glVertex3f(simple->getVertices()[i].x,
					simple->getVertices()[i].y,
					simple->getVertices()[i].z);
	}

	glEnd();
	/*glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, simple->getVertices()); 
    glNormalPointer(GL_FLOAT, 0, simple->getNormals()); 
    glColorPointer(3, GL_FLOAT, 0, simple->getColors()); 
    
    glDrawElements(GL_TRIANGLES, simple->getIndexCount(), GL_UNSIGNED_SHORT, 
        simple->getIndices());

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
	*/
	//Grid Lines

	glBegin (GL_LINES);
		glColor3f(1.0f,0.0f,0.0f); //X - red
		glVertex3f(-100.0f,0.0f,0.0f);
		glVertex3f(100.0f,0.0f,0.0f);
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,100.0f,0.0f); //Y - blue
		glVertex3f(0.0f,-100.0f,0.0f);
		glColor3f(0.0f,1.0f,0.0f); //Z - green
		glVertex3f(0.0f,0.0f,100.0f);
		glVertex3f(0.0f,0.0f,-100.0f);
    glEnd();

    /*if (gDisplayLeafBounds)
    {
        glPolygonMode(GL_FRONT, GL_LINE);

        IvSetWorldIdentity();
        IvSetColor( 1.0f, 0.5f, 0.0f );
        IvDrawCapsule(mWorldCapsule.GetSegment(), mWorldCapsule.GetRadius());
        glPolygonMode(GL_FRONT, GL_FILL);
    }
       
    if (gDisplayHierarchyBounds)
    {
        glPolygonMode(GL_FRONT, GL_LINE);
        IvMatrix44 ident;
        ident.Identity();
        ident(0,3) = mWorldSphere.GetCenter().x;
        ident(1,3) = mWorldSphere.GetCenter().y;
        ident(2,3) = mWorldSphere.GetCenter().z;

        IvSetWorldMatrix(ident);
        IvSetColor( 1.0f, 1.0f, 0.0f );
        IvDrawSphere(mWorldSphere.GetRadius());

        glPolygonMode(GL_FRONT, GL_FILL);
    }*/
}

void OpenGLRenderer::onFrustumChange()
{
	if (camera)
    {
        float fL, fR, fB, fT, fN, fF;
        camera->getFrustum(fL,fR,fB,fT,fN,fF);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glFrustum(fL,fR,fB,fT,fN,fF);
    }
}

void OpenGLRenderer::onViewPortChange()
{
	float fL, fR, fT, fB;
    if (camera)
    {
        // 3D applications use cameras
        camera->getViewPort(fL,fR,fT,fB);

		GLint iX = (GLint)(fL*width);
		GLint iY = (GLint)(fB*height);
		GLsizei iW = (GLsizei)((fR - fL)*width);
		GLsizei iH = (GLsizei)((fT - fB)*height);
		glViewport(iX,iY,iW,iH);
	}
}

void OpenGLRenderer::onFrameChange()
{
	Vector3 kLoc  = camera->getWorldLocation();
    Vector3 kUVec = camera->getWorldUVector();
    Vector3 kDVec = camera->getWorldDVector();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    Vector3 kLookAt = kLoc + kDVec;
    gluLookAt(kLoc.x,kLoc.y,kLoc.z,kLookAt.x,kLookAt.y,kLookAt.z,
        kUVec.x,kUVec.y,kUVec.z);

}

void OpenGLRenderer::setWorldTransformation()
{

}

void OpenGLRenderer::restoreWorldTransformation()
{

}

void OpenGLRenderer::setScreenTransformation()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glLoadIdentity();
	
	glMatrixMode(GL_PROJECTION);    
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,0.0,-1.0);
}

void OpenGLRenderer::restoreScreenTransformation()
{
	glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void OpenGLRenderer::setBackgroundColor(Ey3::ColorRGB &c)
{
	Renderer::setBackgroundColor(c);
	glClearColor(c.r,c.g,c.b,1.0f);
}

OpenGLRenderer::~OpenGLRenderer()
{

}

void OpenGLRenderer::initialize()
{
    glEnableClientState(GL_VERTEX_ARRAY);

    glDisableClientState(GL_COLOR_ARRAY);
	glColor4f(ColorRGBA::WHITE.r,ColorRGBA::WHITE.b,ColorRGBA::WHITE.g,ColorRGBA::WHITE.a);

    // normals disabled
    glDisableClientState(GL_NORMAL_ARRAY);
	
    // Get number of supported texture units.  Initially disable them.
    GLint iMaxTextures;
    glGetIntegerv(GL_MAX_TEXTURE_UNITS_ARB,&iMaxTextures);
    maxTextures = (int)iMaxTextures;
    for (int i = 0; i < maxTextures; i++)
    {
        glClientActiveTextureARB(GL_TEXTURE0_ARB+i);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY); 
        glActiveTextureARB(GL_TEXTURE0_ARB+i);
        glDisable(GL_TEXTURE_2D);
    }
	
    // set up light model
    maxLights = 8;  // OpenGL limits the number of lights to eight
	//glLightModelf(GL_LIGHT_MODEL_AMBIENT,ColorRGBA::BLACK.r,ColorRGBA::BLACK.b,ColorRGBA::BLACK.g,ColorRGBA::BLACK.a);
    glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SEPARATE_SPECULAR_COLOR);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_FALSE);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_FALSE);
    glDisable(GL_LIGHTING);
	
     // get stencil buffer size
     GLint iBits = 0;
     glGetIntegerv((GLenum)GL_STENCIL_BITS,&iBits);
     maxStencilIndices = ( iBits > 0 ? (1 << iBits) : 0 );
	
    // disable drawing of lines as sequences of dashes (want solid lines)
    glDisable(GL_LINE_STIPPLE);

}

//Driver Info

const char* OpenGLRenderer::getVendor()
{
    return (const char*)glGetString(GL_VENDOR);
}

const char* OpenGLRenderer::getRenderer ()
{
    return (const char*)glGetString(GL_RENDERER);
}

const char* OpenGLRenderer::getVersion ()
{
    return (const char*)glGetString(GL_VERSION);
}

const char* OpenGLRenderer::getGluVersion ()
{
    return (const char*)glGetString((GLenum)GLU_VERSION);
}

const char* OpenGLRenderer::getExtensions ()
{
    return (const char*)glGetString(GL_EXTENSIONS);
}

bool OpenGLRenderer::isMinimumVersion (int iMajor, int iMinor, int iRelease)
{
    int iVMajor = 0, iVMinor = 0, iVRelease = 0;
    sscanf(getVersion(),"%d.%d.%d",&iVMajor,&iVMinor,&iVRelease);

    if ( iVMajor < iMajor )
        return false;

    if ( iVMajor > iMajor )
        return true;

    if ( iVMinor < iMinor )
        return false;

    if ( iVMinor > iMinor )
        return true;

    if ( iVRelease < iRelease )
        return false;

    return true;
}

void OpenGLRenderer::establishCapabilities ()
{
    bool b1p2 = isMinimumVersion(1,2,0);
    bool b1p3 = isMinimumVersion(1,3,0);
    bool b1p4 = isMinimumVersion(1,4,0);
    (void)b1p4;  // avoid compiler warning in release mode

    int iMaxTextureUnits;
    int iBits = 0;
    bool bCapSpecularAfterTexture;
    bool bCapMultitexture;
    bool bCapTextureClampToBorder;
    bool bCapTextureApplyAdd;
    bool bCapTextureApplyCombine;
    bool bCapTextureApplyCombineDot3;
    //bool bCapDot3BumpMapping;
    bool bCapPlanarShadow;
    bool bCapPlanarReflection;
    bool bCapPixShaderVersion;
    bool bCapVertShaderVersion;

    //bool bVBO = ExtensionSupported("GL_ARB_vertex_buffer_object");

    // specular highlights drawn untinted after the texture color
    bCapSpecularAfterTexture = b1p2
        || extensionSupported("GL_EXT_separate_specular_color");

    // initialize the number of supported texture units
    if ( b1p3 || extensionSupported("GL_ARB_multitexture") )
    {
        // This code may look strange, but Apple OpenGL 1.2 defines GLint
        // as "long" whereas Windows and Linux define it as "int".
       // glGetIntegerv(GL_MAX_TEXTURE_UNITS_ARB,&iMaxTextureUnits);
        bCapMultitexture = true;
    }
    else
    {
        iMaxTextureUnits = 1;
        bCapMultitexture = false;
    }

    // texture clamping to border
    bCapTextureClampToBorder = b1p3
        || extensionSupported("GL_ARB_texture_border_clamp");

    // texture apply add mode
    bCapTextureApplyAdd = b1p3
        || extensionSupported("GL_ARB_texture_env_add");

    // texture apply combine mode
    bCapTextureApplyCombine = b1p3
        || extensionSupported("GL_ARB_texture_env_combine");
    if ( bCapTextureApplyCombine )
    {
        bCapTextureApplyCombineDot3 = b1p3
            || extensionSupported("GL_ARB_texture_env_dot3");
    }

    // Dot3 bump mapping (combine, combine dot3, and multitexturing)
//    bCapDot3BumpMapping =
//        bCapTextureApplyCombine &&
//        bCapTextureApplyCombineDot3 &&
//        iMaxTextureUnits > 1;

    // query if stencil buffer was really created
    glGetIntegerv((GLenum)GL_STENCIL_BITS,&iBits);

    // projected planar shadow (uses stencil buffer)
    bCapPlanarShadow = ( iBits > 0 );

    // planar reflection (uses stencil buffer and blend color)
    bCapPlanarReflection = ( iBits > 0 &&
        extensionSupported("GL_EXT_blend_color") );

    // vertex/pixel shaders
    bCapPixShaderVersion = extensionSupported("GL_ARB_fragment_program");
    bCapVertShaderVersion = extensionSupported("GL_ARB_vertex_program");

	if(bCapVertShaderVersion)
		LOG("OpenGL: GL_ARB_vertex_program extension supported");
	if(bCapPixShaderVersion)
		LOG("OpenGL: GL_ARB_fragment_program extension supported");
}

bool OpenGLRenderer::extensionSupported (const char* acExt)
{
    // make sure a proper string has been passed
    if ( !acExt || acExt[0] == 0 )
        return false;

    // Without the typecast on strstr, CodeWarrior 9.x generates an error
    // because its C library appears to define the return value of strstr
    // as 'const char*'.  Other compilers appear to define the return value
    // as 'char*'.
    char* acBegin = (char*)strstr(getExtensions(),acExt);
    if ( acBegin )
    {
        // The extension was found, but make sure it is not a proper substring
        // of another extension.  TO DO:  Should cEnd be compared to tabs or
        // other white space characters?
        char cEnd = *(acBegin + strlen(acExt));
        return cEnd == ' ' || cEnd == 0;
    }

    return false;
}
