#include "pebble.h"
#include "algebra.h"
#include "geometry.h"
#include "trigonometry.h"
#include "calc.h"
#include "biology.h"
#include "physics.h"
#include "chemistry.h"
#include "conversion.h"
	
#define NUM_MATH_MENU_ITEMS 4
#define NUM_MENU_SECTIONS 4
#define NUM_SCIENCE_MENU_ITEMS 3
#define NUM_OTHER_MENU_ITEMS 1
#define NUM_ABOUT_MENU_ITEMS 2
static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections[NUM_MENU_SECTIONS];

static SimpleMenuItem math_menu_items[NUM_MATH_MENU_ITEMS];
static SimpleMenuItem science_menu_items[NUM_SCIENCE_MENU_ITEMS];
static SimpleMenuItem about_menu_items[NUM_ABOUT_MENU_ITEMS];
static SimpleMenuItem other_menu_items[NUM_OTHER_MENU_ITEMS];

//Callbacks

static void algebra_select_callback(int index, void *ctx) {
  show_algebra_menu();
}
static void geometry_select_callback(int index, void *ctx) {
  show_geometry_menu();
}
static void calc_select_callback(int index, void *ctx) {
  show_calc_menu();
}
static void trig_select_callback(int index, void *ctx) {
  show_trig_menu();
}
static void bio_select_callback(int index, void *ctx) {
  show_bio_menu();
}
static void physics_select_callback(int index, void *ctx) {
  show_physics_menu();
}
static void chemistry_select_callback(int index, void *ctx) {
  show_chemistry_menu();
}
static void conversion_select_callback(int index, void *ctx) {
  show_conversion_menu();
}



static void window_load(Window *window) {

  int num_a_items = 0;
  int num_a2_items = 0;
  int num_a3_items = 0;
  int num_a4_items = 0;

  math_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Algebra",
	.subtitle = "Formule Algebriche",
    .callback = algebra_select_callback,
  };
  math_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Geometria",
	.subtitle = "Formule Geometriche",
    .callback = geometry_select_callback,
  };
  math_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Calculo",
	.subtitle = "Calculo 1",
    .callback = calc_select_callback,
  };
  math_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Trigonometia",
	.subtitle = "Formule Trigonometriche",
    .callback = trig_select_callback,
  };
  science_menu_items[num_a2_items++] = (SimpleMenuItem){
    .title = "Fisica",
	.subtitle = "Formule Fisiche",
    .callback = physics_select_callback,
  };
  science_menu_items[num_a2_items++] = (SimpleMenuItem){
    .title = "Chimica",
	.subtitle = "Formule Chimiche",
    .callback = chemistry_select_callback,
  };
  science_menu_items[num_a2_items++] = (SimpleMenuItem){
    .title = "Biologia",
	.subtitle = "Bio-Formule",
    .callback = bio_select_callback,
  };
  other_menu_items[num_a4_items++] = (SimpleMenuItem){
    .title = "Conversioni",
	.subtitle = "Conversioni d'unità",
    .callback = conversion_select_callback,
  };
  about_menu_items[num_a3_items++] = (SimpleMenuItem){
    .title = "Contattami",
	.subtitle = "francesco.dulio@gmail.com",
  };
  about_menu_items[num_a3_items++] = (SimpleMenuItem){
    .title = "Contattalo",
	.subtitle = "Blackpaw1996@gmail.com",
  };
  menu_sections[0] = (SimpleMenuSection){
  .title ="Matematica",
  .num_items = NUM_MATH_MENU_ITEMS,
  .items = math_menu_items,
  };
  menu_sections[1] = (SimpleMenuSection){
  .title ="Scienze",
  .num_items = NUM_SCIENCE_MENU_ITEMS,
  .items = science_menu_items,
  };
  menu_sections[2] = (SimpleMenuSection){
  .title ="Altro",
  .num_items = NUM_OTHER_MENU_ITEMS,
  .items = other_menu_items,
  };

  menu_sections[3] = (SimpleMenuSection){
  .title ="About",
  .num_items = NUM_ABOUT_MENU_ITEMS,
  .items = about_menu_items,
  };
	
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, menu_sections,NUM_MENU_SECTIONS, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
}

int main(void) {
  window = window_create();


  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });

  window_stack_push(window, true /* Animated */);

  app_event_loop();

  window_destroy(window);
}
/* This app is created by Devin Simmons, anyone can feel free to use this code to make their own apps as long as you
give credit!!

Thanks for using the app! Please leave a review, and if you would like any formulas or equations added contact me at blackpaw1996@gmail.com,
or on Google Plus!

A big thanks to Grégoire Sage for helping guide me through learning how to code!

*/
