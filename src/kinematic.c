#include "pebble.h"
#include "kinematic.h"
#include "static.h"
#include "dinamica.h"
	
#define NUM_CIN_MENU_ITEMS 6

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem cin_menu_items[NUM_CIN_MENU_ITEMS];

static void static_select_callback(int index, void *ctx) {
  show_static_menu();
}
static void dinamica_select_callback(int index, void *ctx) {
  show_dinamica_menu();
}

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {
  int num_a_items = 0;

  cin_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Statica",
	.callback = static_select_callback,
  };
  cin_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Dinamica",
	.callback = dinamica_select_callback,
  };
  cin_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Eq Cinematica",
	.subtitle = "V1²=V0²+2a(∆x)"
  };
  cin_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Eq Cinematica",
	.subtitle = "d=Vi·t+½at²"
  };
  cin_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Eq Cinematica",
	.subtitle = "Vf=Vi+at"
  };
  cin_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Eq Cinematica",
	.subtitle = "d=(Vi+Vf/2)t"
  };

  menu_sections.num_items = NUM_CIN_MENU_ITEMS;
  menu_sections.items = cin_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_cin_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}