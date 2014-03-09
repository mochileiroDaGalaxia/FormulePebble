#include "pebble.h"
#include "trigonometry.h"

	
#define NUM_TRIG_MENU_ITEMS 14

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem trig_menu_items[NUM_TRIG_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {

  int num_a_items = 0;

  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Identità 1",
	.subtitle = "sin²(u)+cos²(u) = 1",
  };

  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Identità 2",
	.subtitle = "1+tan²(u)= = sec²(u)",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Identità 3",
	.subtitle = "1+cot²(u) = sec²(u)",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Identità quoziente 1",
	.subtitle = "tan(u)=(sin(u)/cos(u))",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Identità quoziente 2",
	.subtitle = "cot(u)= (cos(u)/sin(u))",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Identità reciproca 1",
	.subtitle = "sin(u) = (1/csc(u))",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Identità reciproca 2",
	.subtitle = "cos(u) = (1/sec(u))",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Identità reciproca 3",
	.subtitle = "tan(u) = (1/cot(u))",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Identità reciproca 4",
	.subtitle = "csc(u) = (1/sin(u))",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Identità reciproca 5",
	.subtitle = "sec(u) = (1/cos(u))",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Identità reciproca 2",
	.subtitle = "cot(u) = (1/tan(u))",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Formula duplicazione 1",
	.subtitle = "sin(2u)=2sin(u)cos(u)",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Formula duplicazione 2",
	.subtitle = "cos(2u)=cos²(u)-sin²(u)",
  };
  trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Formula duplicazione 3",
	.subtitle = "tan(2u)=2tan(u)/(1-tan²(u))",
  };


  menu_sections.num_items = NUM_TRIG_MENU_ITEMS;
  menu_sections.items = trig_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_trig_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}