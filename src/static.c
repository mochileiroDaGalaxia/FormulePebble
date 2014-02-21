#include "pebble.h"
#include "static.h"
	
#define NUM_STATIC_MENU_ITEMS 4

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem static_menu_items[NUM_STATIC_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {
  int num_a_items = 0;

  static_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Eq Cinematica",
	.subtitle = "V1²=V0²+2a(∆x)"
  };
  static_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Eq Cinematica",
	.subtitle = "d=Vi·t+½at²"
  };
  static_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Eq Cinematica",
	.subtitle = "Vf=Vi+at"
  };
  static_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Eq Cinematica",
	.subtitle = "d=(Vi+Vf/2)t"
  };
  
  menu_sections.num_items = NUM_STATIC_MENU_ITEMS;
  menu_sections.items = static_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_static_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}