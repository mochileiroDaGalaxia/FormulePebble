#include "pebble.h"
#include "coniche.h"
	
#define NUM_CONI_MENU_ITEMS 6

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem coni_menu_items[NUM_CONI_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {
  int num_a_items = 0;
	
	coni_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Coniche",
	.subtitle = "ax²+2bxy+cy²+2dx+2ey+f=0"
  };
	coni_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Eccentricità",
	.subtitle = "e=d(FP)/d(dP)"
  };
	coni_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Parabola e=1",
	.subtitle = "y=ax²+bx+c"
  };
	coni_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Iperbole e e>1",
	.subtitle = "x²/a²-y²/b²=1"
  };
	coni_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Ellisse 0<e<1",
	.subtitle = "x²/a²+y²/b²=1"
  };
	coni_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Cerchio e=0",
	.subtitle = "(x-x0)²+(y-y0)²=r²"
  };
	
  menu_sections.num_items = NUM_CONI_MENU_ITEMS;
  menu_sections.items = coni_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_coni_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}