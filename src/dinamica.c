#include "pebble.h"
#include "dinamica.h"
	
#define NUM_DINAMICA_MENU_ITEMS 4

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem dinamica_menu_items[NUM_DINAMICA_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {
  int num_a_items = 0;
	
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Energia cinetica",
	.subtitle = "K=½mv²"
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Energia potenziale",
	.subtitle = "V=mgh"
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Lavoro",
	.subtitle = "W=F·d·cos(a)"
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Potenziale molla",
	.subtitle = "V=½kx²"
  };
	
  menu_sections.num_items = NUM_DINAMICA_MENU_ITEMS;
  menu_sections.items = dinamica_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_dinamica_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}