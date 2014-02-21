#include "pebble.h"
#include "physics.h"
#include "electricity.h"
#include "kinematic.h"
#include "termodinamica.h"
#include "quantistica.h"
#include "elettromagnetismo.h"
#include "fluidodinamica.h"
	
#define NUM_PHYSICS_MENU_ITEMS 6

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem physics_menu_items[NUM_PHYSICS_MENU_ITEMS];

static void elec_select_callback(int index, void *ctx) {
  show_elec_menu();
}
static void cin_select_callback(int index, void *ctx) {
  show_cin_menu();
}
static void fluid_select_callback(int index, void *ctx) {
  show_fluid_menu();
}
static void termo_select_callback(int index, void *ctx) {
  show_termo_menu();
}
static void elet_select_callback(int index, void *ctx) {
  show_elet_menu();
}
static void quant_select_callback(int index, void *ctx) {
  show_quant_menu();
}

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {

  int num_a_items = 0;

  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Meccanica",
	.callback = cin_select_callback
  };
  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Fluidodinamica",
	.callback = fluid_select_callback
  };
  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Termodinamica",
	.callback = termo_select_callback
  };
  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Circuiti",
	.callback = elec_select_callback
  };
  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Elettromagnetismo",
	.callback = elet_select_callback
  };
  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Quantistica",
	.callback = quant_select_callback
  };

  menu_sections.num_items = NUM_PHYSICS_MENU_ITEMS;
  menu_sections.items = physics_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);
	
  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_physics_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}