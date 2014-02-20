#include "pebble.h"
#include "conversion.h"
	
#define NUM_CONVERSION_MENU_ITEMS 6

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem conversion_menu_items[NUM_CONVERSION_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {
  int num_a_items = 0;

  conversion_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Farenheit in C",
	.subtitle = "C = 5/9*(F-32)",
  };
  conversion_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Celcius in K",
	.subtitle = "K = C+273",
  };
  conversion_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Celcius in F",
	.subtitle = "F = 9/5*(C+32)",
  };
  conversion_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Miglia in Kilometri",
	.subtitle = "Km = mi/0.62137",
  };
  conversion_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Grammi in Once",
	.subtitle = "oz = 0.035274 g",
  };
  conversion_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Km/h in m/s",
	.subtitle = "1 km/h = 0.278 m/s",
  };


  menu_sections.num_items = NUM_CONVERSION_MENU_ITEMS;
  menu_sections.items = conversion_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_conversion_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}