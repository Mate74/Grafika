#ifndef SCENE_H
#define SCENE_H

//#include "camera.h"
#include "utils.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Model asztal;
    Model szek;
    Model kocka;
    Model wardrobe;
    Model ajto;
    Model shelf;
    Model laptop;
    Model szekreny;
    Model TV;
    Model korong;
    Model fan;
    Model bed;
    Model desk;
    Material material;
    GLuint asztal_texture_id;
    GLuint szek_texture_id;
    GLuint wardrobe_texture_id;
    GLuint laptop_texture_id;
    GLuint szekreny_texture_id;
    GLuint kocka_texture_id;
    GLuint ajto_texture_id;
    GLuint shelf_texture_id;
    GLuint korong_texture_id;
    GLuint fan_texture_id;
    GLuint bed_texture_id;
    GLuint asztal2_texture_id;
    GLuint TV_texture_id;
    GLuint texture_id;
    GLfloat x;
    GLfloat y;
    GLfloat z;
    float rotation;
} Scene;
/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

void update_rotation(Scene* scene,double time);

void set_light(Scene* scene,float value);


GLfloat move_tv_x(Scene* scene,double move);

GLfloat move_tv_y(Scene* scene, double move);

GLfloat move_tv_z(Scene* scene, double move);

#endif /* SCENE_H */
