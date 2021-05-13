#ifndef CAMERA_H
#define CAMERA_H

#include "utils.h"

#include "scene.h"

#include <GL/glut.h>

/**
 * Camera, as a moving point with direction
 */
typedef struct Camera
{
    vec3 position;
    vec3 rotation;
    vec3 speed;
    vec3 rotation_speed;
} Camera;

    Scene scene;
/**
 * Is the texture preview visible?
 */
int is_preview_visible;

/**
 * Initialize the camera to the start position.
 */
void init_camera(Camera* camera);

/**
 * Update the position of the camera.
 */
void update_camera(Camera* camera, double time);

/**
 * Apply the camera settings to the view transformation.
 */
void set_view(const Camera* camera);

/**
 * Set the horizontal and vertical rotation of the view angle.
 */
void rotate_camera(Camera* camera, double horizontal, double vertical);

/**
 * Set the speed of forward and backward motion.
 */
void set_camera_speed(Camera* camera, double speed);

void show_texture_preview();
/**
 * Set the speed of left and right side steps.
 */
void set_camera_side_speed(Camera* camera, double speed);

void set_camera_vert_speed(Camera* camera, double speed);

void set_camera_horizontal_rotation_speed(Camera* camera,double rotation_speed);

void set_camera_vertical_rotation_speed(Camera* camera,double rotation_speed);

GLfloat getx(Scene* scene);
GLfloat gety(Scene* scene);
GLfloat getz(Scene* scene);

#endif /* CAMERA_H */
