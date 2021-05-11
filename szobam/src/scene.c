#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    scene->rotation=0.0;
    scene->x=100.0;
    scene->y=100.0;
    scene->z=-60;
    load_model(&(scene->asztal), "asztal3.obj");
    scene->asztal_texture_id = load_texture("whitewood.png");
    load_model(&(scene->szek), "szek2.obj");
    scene->szek_texture_id = load_texture("paint_szek.png");
    load_model(&(scene->kocka), "kocka.obj");
    scene->kocka_texture_id = load_texture("kocka_uv.png");
    load_model(&(scene->wardrobe), "Wardrobe.obj");
    scene->wardrobe_texture_id = load_texture("whitewood.png");
    load_model(&(scene->laptop), "laptop2.obj");
    scene->laptop_texture_id = load_texture("Laptop_2.jpg");
    load_model(&(scene->szekreny), "bookcase1.obj");
    scene->szekreny_texture_id = load_texture("whitewood.png");
    load_model(&(scene->ajto), "Door2.obj");
    scene->ajto_texture_id = load_texture("WoodTexture.jpg");
    load_model(&(scene->shelf), "shelf2.obj");
    scene->shelf_texture_id = load_texture("szekreny.jpg");
    load_model(&(scene->TV), "TV2.obj");
    load_model(&(scene->korong),"korong.obj");
    scene->korong_texture_id =load_texture("korong.png");
    load_model(&(scene->fan),"fan.obj");
    scene->fan_texture_id =load_texture("szekreny.jpg");
    load_model(&(scene->bed),"bed.obj");
    scene->bed_texture_id =load_texture("bed.png");
    load_model(&(scene->desk),"desk.obj");
    scene->asztal2_texture_id =load_texture("desk.png");
    load_model(&(scene->TV),"TV2.obj");
    scene->TV_texture_id =load_texture("tv.png");
    scene->texture_id = load_texture("szoveg.png");
   

    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;

    scene->material.shininess = 0.0;
}
void update_rotation(Scene* scene,double time)
{
    scene->rotation+=10*time;
}
GLfloat move_tv_x(Scene* scene,double move)
{
    scene->x+=move;
    return scene->x;
}
GLfloat move_tv_y(Scene* scene, double move)
{
    scene->y+=move;
    return scene->y;
}
GLfloat move_tv_z(Scene* scene,double move)
{
    scene->z=move;
    return scene->z;
}
void set_light(Scene* scene,float value)
{
    scene->material.ambient.red += value;
    scene->material.ambient.green += value;
    scene->material.ambient.blue += value;

    scene->material.diffuse.red += value;
    scene->material.diffuse.green += value;
    scene->material.diffuse.blue += value;
}
void set_lighting()
{
    float ambient_light[] = { 0.9f, 0.9f, 0.9f, 1.0f };
    float diffuse_light[] = { 0.9f, 0.9f, 0.9, 1.0f };
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position[] = { 0.0,0.0,10.0,1.0 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    float ambient_material_color[3];
    float diffuse_material_color[3];
    float specular_material_color[3];

    ambient_material_color[0] = material->ambient.red;
    ambient_material_color[1] = material->ambient.green;
    ambient_material_color[2] = material->ambient.blue;

    diffuse_material_color[0] = material->diffuse.red;
    diffuse_material_color[1] = material->diffuse.green;
    diffuse_material_color[2] = material->diffuse.blue;

    specular_material_color[0] = material->specular.red;
    specular_material_color[1] = material->specular.green;
    specular_material_color[2] = material->specular.blue;

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}
void draw_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting();
        glPushMatrix();
    glRotatef(90,0,0,1);
    glRotatef(90,1,0,0);
    glRotatef(-90,0,1,0);
    glTranslatef(40,-60,-35);
    glScalef(9,9,6);
    glBindTexture(GL_TEXTURE_2D,scene->asztal_texture_id);
    draw_model(&(scene->asztal));
        glPopMatrix();
        glPushMatrix();
    glRotatef(90,1,0,0);
    glRotatef(90,0,1,0);
    glTranslatef(80,-60,60);
    glScalef(5,5,5);
    glBindTexture(GL_TEXTURE_2D,scene->szek_texture_id);
    draw_model(&(scene->szek));
        glPopMatrix();
        glPushMatrix();
    glTranslatef(125,30,38);
    glScalef(100,100,100);
    glBindTexture(GL_TEXTURE_2D,scene->kocka_texture_id);
    draw_model(&(scene->kocka));
        glPopMatrix();
        glPushMatrix();
    glRotatef(90,1,0,0);
    glTranslatef(200,-63,-115); 
    glScalef(25,25,25);
    glBindTexture(GL_TEXTURE_2D,scene->wardrobe_texture_id);
    draw_model(&(scene->wardrobe));
        glPopMatrix();
        glPushMatrix();
    glRotatef(90,1,0,0);
    glRotatef(180,0,1,0);
    glTranslatef(-30,-23,85);
    glScalef(5,5,5);
    glBindTexture(GL_TEXTURE_2D,scene->laptop_texture_id);
    draw_model(&(scene->laptop));
        glPopMatrix();
        glPushMatrix();
    glTranslatef(150,115,-60);
    glScalef(8,8,8);
    glBindTexture(GL_TEXTURE_2D,scene->szekreny_texture_id);
    draw_model(&(scene->szekreny));
        glPopMatrix();
        glPushMatrix();
    glScalef(7,7,7);
    glRotatef(90,1,0,0);
    glTranslatef(12,-9.5,-18);
    glBindTexture(GL_TEXTURE_2D,scene->ajto_texture_id);
    draw_model(&(scene->ajto));
        glPopMatrix();
        glPushMatrix();
    glRotatef(90,1,0,0);
    glRotatef(90,0,1,0);
    glScalef(0.2,0.2,0.2);
    glTranslatef(400,50,205);
    glBindTexture(GL_TEXTURE_2D,scene->shelf_texture_id);
    draw_model(&(scene->shelf));
        glPopMatrix();
        glPushMatrix();
    glTranslatef(scene->x,scene->y,scene->z);
    glBindTexture(GL_TEXTURE_2D,scene->korong_texture_id);
    draw_model(&(scene->korong));
        glPopMatrix();
        glPushMatrix();
    glScalef(200,200,200);
    glRotatef(90,1,0,0);
    glTranslatef(0.5,0.32,0);
    glRotatef(scene->rotation,0,1,0);
    glBindTexture(GL_TEXTURE_2D,scene->fan_texture_id);
    draw_model(&(scene->fan));
        glPopMatrix();
        glPushMatrix();
    glScalef(0.5,0.5,0.5);
    glRotatef(270,0,0,1);
    glTranslatef(50,350,-75);
    glBindTexture(GL_TEXTURE_2D,scene->bed_texture_id);
    draw_model(&(scene->bed));
        glPopMatrix();
        glPushMatrix();
    glScalef(75,75,75);
    glRotatef(90,1,0,0);
    glRotatef(-90,0,1,0);
    glTranslatef(0.25,-0.65,-0.6);
    glBindTexture(GL_TEXTURE_2D,scene->asztal2_texture_id);
    draw_model(&(scene->desk));
        glPopMatrix();
        glPushMatrix();
    glScalef(15,15,15);
    glRotatef(90,0,1,0);
    glRotatef(90,0,0,1);
    glTranslatef(0,-1.65,4);
    glBindTexture(GL_TEXTURE_2D,scene->TV_texture_id);
    draw_model(&(scene->TV));
        glPopMatrix();
        
    glBindTexture(GL_TEXTURE_2D,scene->texture_id);

}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(100, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(100, 0, 0);

    glColor3f(0, 100, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 100, 0);

    glColor3f(0, 0, 100);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 100);

    glEnd();
}
