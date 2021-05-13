#include "camera.h"

#include <GL/glut.h>

#include <math.h>

GLfloat getx(Scene* scene)
{
    GLfloat x;
    x=scene->x;
    return x;
}
GLfloat gety(Scene* scene)
{
    GLfloat y;
    y=scene->y+10;
    return y;
}
GLfloat getz(Scene* scene)
{
    GLfloat z;
    z=scene->z+10;
    return z;
}

void init_camera(Camera* camera)
{

    camera->position.x = getx(&scene);
    camera->position.y = gety(&scene);
    camera->position.z = getz(&scene);
    camera->rotation.x = -40.0;
    camera->rotation.y =-100.0;
    camera->rotation.z = -100.0;
    camera->speed.x = 0.0;
    camera->speed.y = 0.0;
    camera->speed.z = 0.0;
    camera->rotation_speed.x = 0.0;
    camera->rotation_speed.y = 0.0;
    camera->rotation_speed.z = 0.0;

    is_preview_visible = FALSE;
}
void update_camera(Camera* camera, double time)
{
    double angle;
    double side_angle;

    camera->rotation.z +=camera->rotation_speed.z * time;
    camera->rotation.x +=camera->rotation_speed.x * time;

    angle = degree_to_radian(camera->rotation.z);
    side_angle = degree_to_radian(camera->rotation.z + 90.0);

    camera->position.x =getx(&scene);
    camera->position.y =gety(&scene);
    camera->position.z +=camera->speed.z * time;
}


void set_view(const Camera* camera)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-(camera->rotation.x + 90), 1.0, 0, 0);
    glRotatef(-(camera->rotation.z - 90), 0, 0, 1.0);
    glTranslatef(-camera->position.x, -camera->position.y, -camera->position.z);
}

void rotate_camera(Camera* camera, double horizontal, double vertical)
{
    camera->rotation.z += horizontal;
    camera->rotation.x += vertical;

    if (camera->rotation.z < 0) {
        camera->rotation.z += 360.0;
    }

    if (camera->rotation.z > 360.0) {
        camera->rotation.z -= 360.0;
    }

    if (camera->rotation.x < 0) {
        camera->rotation.x += 360.0;
    }

    if (camera->rotation.x > 360.0) {
        camera->rotation.x -= 360.0;
    }
}

void set_camera_speed(Camera* camera, double speed)
{
    camera->speed.y = speed;
}

void set_camera_side_speed(Camera* camera, double speed)
{
    camera->speed.x = speed;
}
void set_camera_vert_speed(Camera* camera, double speed)
{
    camera->speed.z = speed;
}
void set_camera_horizontal_rotation_speed(Camera* camera,double rotation_speed)
{
    camera->rotation_speed.z=rotation_speed;
}
void set_camera_vertical_rotation_speed(Camera* camera,double rotation_speed)
{
    camera->rotation_speed.x=rotation_speed;
}
void show_texture_preview()
{
    
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-1.5, 1, -2);
    glTexCoord2f(1, 0);
    glVertex3f(1.5, 1, -2);
    glTexCoord2f(1, 1);
    glVertex3f(1.5, -1, -2);
    glTexCoord2f(0, 1);
    glVertex3f(-1.5, -1, -2);
    glEnd();

    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}

