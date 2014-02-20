#include "pebble.h"
#include "elettromagnetismo.h"
	
#define NUM_ELET_MENU_ITEMS 1

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem elet_menu_items[NUM_ELET_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {
  int num_a_items = 0;
	
  elet_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Forza di Coulomb",
	.subtitle = "F=k(|q1||q2|)/(d²)"
  };
	
  menu_sections.num_items = NUM_ELET_MENU_ITEMS;
  menu_sections.items = elet_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_elet_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}