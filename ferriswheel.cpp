/*    Chapter6/figure.cpp     */

/* This is the code from Chapter5/figure.cpp, modified to show
 * the figure with a red plastic surface. 
 */

#include <GL/glut.h>
#include <GL/glui.h>
#include "ferriswheel.h"
 
GLfloat TORSO_RADIUS = 2.0;
GLfloat TORSO_HEIGHT = 6.0;
GLfloat HEADX = 0.0, HEADY = 7.5;
GLfloat HEAD_RADIUS = 2.0;
GLfloat ARM_RADIUS = 0.4;
GLfloat UPPER_ARM_LENGTH = 3.0, LOWER_ARM_LENGTH = 3.0;
GLfloat LUAX = -2.0, LUAY = 5.0, LLAY = -3.0;
GLfloat RUAX = 2.0, RUAY = 5.0, RLAY = -3.0;
GLfloat LEG_RADIUS = 0.4;
GLfloat UPPER_LEG_LENGTH = 4.0, LOWER_LEG_LENGTH = 4.0;
GLfloat LULX = -2.0, LULY = 0.0, LLLY = -4.0;
GLfloat RULX = 2.0, RULY = 0.0, RLLY = -4.0;
typedef struct materialStruct {
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat shininess;
} materialStruct;

materialStruct redPlasticMaterials = {
    {0.3, 0.0, 0.0, 1.0},
    {0.9, 0.0, 0.0, 1.0},
    {0.8, 0.6, 0.6, 1.0},
    32.0};

typedef struct lightingStruct {
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
} lightingStruct;

lightingStruct whiteLighting = {
    {0.0, 0.0, 0.0, 1.0},
    {1.0, 1.0, 1.0, 1.0},
    {1.0, 1.0, 1.0, 1.0} };

lightingStruct coloredLighting = {
    {0.2, 0.0, 0.0, 1.0},
    {0.0, 1.0, 0.0, 1.0},
    {0.0, 0.0, 1.0, 1.0} };

GLfloat light0_pos[4] = {4.0, 10.0, 20.0, 0.0};

materialStruct *currentMaterials;
lightingStruct *currentLighting;


GLfloat theta[] = {65.0, 0.0, 0.0, -42.0, -12.0, -33.0, -48.0,18.0, 74.0, -14.0, 11.0};

GLUquadricObj *p, *q;  
int main_window;


void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5.0, 10.0, 40.0, 0.0, 10.0, 0.0, 0.0,  1.0, 0.0);
}


void reshape(int w, int h) {
    glViewport(0, 0, w, h);

    float aspect = w*1.0/h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, aspect, 0.5, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glutSetWindow(main_window);
    glutPostWindowRedisplay(main_window);  
}

void torso() {
    glPushMatrix();
    glRotatef(-90.0, 1.0, 0.0, 0.0); 
    gluCylinder(p, TORSO_RADIUS, TORSO_RADIUS, TORSO_HEIGHT, 8, 8);
    glPopMatrix();
}

void head(){
    gluSphere(p, HEAD_RADIUS, 8, 8);
}

void right_upper_arm(){
    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    gluCylinder(p, ARM_RADIUS, ARM_RADIUS, UPPER_ARM_LENGTH, 8, 8);
    glPopMatrix();
}

void right_lower_arm() {
    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    gluCylinder(p, ARM_RADIUS, ARM_RADIUS, LOWER_ARM_LENGTH, 8, 8);
    glPopMatrix();
}

void left_upper_arm(){
    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    gluCylinder(p, ARM_RADIUS, ARM_RADIUS, UPPER_ARM_LENGTH, 8, 8);
    glPopMatrix();
}

void left_lower_arm() {
    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    gluCylinder(p, ARM_RADIUS, ARM_RADIUS, LOWER_ARM_LENGTH, 8, 8);
    glPopMatrix();
}

void right_upper_leg(){
    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    gluCylinder(p, LEG_RADIUS, LEG_RADIUS, UPPER_LEG_LENGTH, 8, 8);
    glPopMatrix();
}

void right_lower_leg() {
    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    gluCylinder(p, LEG_RADIUS, LEG_RADIUS, LOWER_LEG_LENGTH, 8, 8);
    glPopMatrix();
}

void left_upper_leg(){
    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    gluCylinder(p, LEG_RADIUS, LEG_RADIUS, UPPER_LEG_LENGTH, 8, 8);
    glPopMatrix();
}

void left_lower_leg() {
    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    gluCylinder(p, LEG_RADIUS, LEG_RADIUS, LOWER_LEG_LENGTH, 8, 8);
    glPopMatrix();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    /* torso */
    glRotatef(theta[0], 0.0, 1.0, 0.0);
    torso();
 
    /* head */
    glPushMatrix();
    glTranslatef(0.0, HEADX, 0.0);
    glRotatef(theta[1], 1.0, 0.0, 0.0);
    glRotatef(theta[2], 0.0, 1.0, 0.0);
    glTranslatef(0.0, HEADY, 0.0);
    head();
    glPopMatrix();
  
    /* right arm */
    glPushMatrix();
    glTranslatef(LUAX, LUAY, 0.0);
    glRotatef(theta[3], 1.0, 0.0, 0.0);
    right_upper_arm();
    glTranslatef(0.0, LLAY, 0.0);
    glRotatef(theta[4], 1.0, 0.0, 0.0);
    right_lower_arm();
    glPopMatrix();

    /* left arm */
    glPushMatrix();
    glTranslatef(RUAX, RUAY, 0.0);
    glRotatef(theta[5], 1.0, 0.0, 0.0);
    left_upper_arm();
    glTranslatef(0.0, RLAY, 0.0);
    glRotatef(theta[6], 1.0, 0.0, 0.0);
    left_lower_arm();
    glPopMatrix();

    /* right leg */
    glPushMatrix();
    glTranslatef(LULX, LULY, 0.0);
    glRotatef(theta[7], 1.0, 0.0, 0.0);
    right_upper_leg();
    glTranslatef(0.0, LLLY, 0.0);
    glRotatef(theta[8], 1.0, 0.0, 0.0);
    right_lower_leg();
    glPopMatrix();

    /* left leg */
    glPushMatrix();
    glTranslatef(RULX, RULY, 0.0);
    glRotatef(theta[9], 1.0, 0.0, 0.0);
    left_upper_leg();
    glTranslatef(0.0, RLLY, 0.0);
    glRotatef(theta[10], 1.0, 0.0, 0.0);
    left_lower_leg();
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers(); 
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(650, 650);
    glutInitWindowPosition(50, 50);
    main_window = glutCreateWindow("Robot");

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    currentMaterials = &redPlasticMaterials;
    glMaterialfv(GL_FRONT, GL_AMBIENT, currentMaterials->ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, currentMaterials->diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, currentMaterials->specular);
    glMaterialf(GL_FRONT, GL_SHININESS, currentMaterials->shininess);
    currentLighting = &whiteLighting;
    glLightfv(GL_LIGHT0, GL_AMBIENT, currentLighting->ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, currentLighting->diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, currentLighting->specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);

    p = gluNewQuadric();
    q = gluNewQuadric();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    init();

    GLUI *control_panel = GLUI_Master.create_glui( "Controls",0, 50, 700 );

    new GLUI_Button(control_panel, "Quit", 0, (GLUI_Update_CB)exit);

    new GLUI_Column(control_panel, true);

    GLUI_Spinner *bend0=new GLUI_Spinner(control_panel, "BODY Angle", GLUI_SPINNER_FLOAT, &(theta[0]), 0,(GLUI_Update_CB) NULL);
    bend0->set_float_limits(-180.0, 180.0, GLUI_LIMIT_CLAMP);

    GLUI_Rollout *head_rollout = new GLUI_Rollout(control_panel, "HEAD Angles", false );
    GLUI_Spinner *bend1=new GLUI_Spinner(head_rollout, "Head Angle 1", GLUI_SPINNER_FLOAT, &(theta[1]), 0,(GLUI_Update_CB) NULL);
    bend1->set_float_limits(-10.0, 10.0, GLUI_LIMIT_CLAMP);
    GLUI_Spinner *bend2=new GLUI_Spinner(head_rollout, "Head Angle 2", GLUI_SPINNER_FLOAT, &(theta[2]), 0,(GLUI_Update_CB) NULL);
    bend2->set_float_limits(-180.0, 180.0, GLUI_LIMIT_CLAMP);

    new GLUI_Column(control_panel, true);

    GLUI_Rollout *right_arm_rollout = new GLUI_Rollout(control_panel, "Right Arm Angles", false );
    GLUI_Spinner *bend3=new GLUI_Spinner(right_arm_rollout, "Upper Arm Angle", GLUI_SPINNER_FLOAT, &(theta[3]), 0, (GLUI_Update_CB)NULL);
    bend3->set_float_limits(-180.0, 90.0, GLUI_LIMIT_CLAMP);
    GLUI_Spinner *bend4=new GLUI_Spinner(right_arm_rollout, "Lower Arm Angle", GLUI_SPINNER_FLOAT, &(theta[4]), 0, (GLUI_Update_CB)NULL);
    bend4->set_float_limits(-90.0, 0.0, GLUI_LIMIT_CLAMP);

    GLUI_Rollout *left_arm_rollout = new GLUI_Rollout(control_panel, "Left Arm Angles", false );
    GLUI_Spinner *bend5=new GLUI_Spinner(left_arm_rollout, "Upper Arm Angle", GLUI_SPINNER_FLOAT, &(theta[5]), 0, (GLUI_Update_CB)NULL);
    bend5->set_float_limits(-180.0, 90.0, GLUI_LIMIT_CLAMP);
    GLUI_Spinner *bend6=new GLUI_Spinner(left_arm_rollout, "Lower Arm Angle", GLUI_SPINNER_FLOAT, &(theta[6]), 0, (GLUI_Update_CB)NULL);
    bend6->set_float_limits(-90.0, 0.0, GLUI_LIMIT_CLAMP);

    new GLUI_Column(control_panel, true);

    GLUI_Rollout *right_leg_rollout = new GLUI_Rollout(control_panel, "Right Leg Angles", false );
    GLUI_Spinner *bend7= new GLUI_Spinner(right_leg_rollout, "Upper Leg Angle", GLUI_SPINNER_FLOAT, &(theta[7]), 0, (GLUI_Update_CB)NULL);
    bend7->set_float_limits(-140.0, 70.0, GLUI_LIMIT_CLAMP);
    GLUI_Spinner *bend8= new GLUI_Spinner(right_leg_rollout, "Lower Leg Angle", GLUI_SPINNER_FLOAT, &(theta[8]), 0, (GLUI_Update_CB)NULL);
    bend8->set_float_limits(0.0, 1600.0, GLUI_LIMIT_CLAMP);

    GLUI_Rollout *left_leg_rollout = new GLUI_Rollout(control_panel, "Left Leg Angles", false );
    GLUI_Spinner *bend9=new GLUI_Spinner(left_leg_rollout, "Upper Leg Angle", GLUI_SPINNER_FLOAT, &(theta[9]), 0, (GLUI_Update_CB)NULL);
    bend9->set_float_limits(-140.0, 70.0, GLUI_LIMIT_CLAMP);
    GLUI_Spinner *bend10=new GLUI_Spinner(left_leg_rollout, "Lower Leg Angle", GLUI_SPINNER_FLOAT, &(theta[10]), 0, (GLUI_Update_CB)NULL);
    bend10->set_float_limits(0.0, 160.0, GLUI_LIMIT_CLAMP);

    control_panel->set_main_gfx_window(main_window); 

    glutMainLoop();
}
