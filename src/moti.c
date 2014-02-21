#include "pebble.h"
#include "moti.h"
	
#define NUM_MOTI_MENU_ITEMS 7

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem moti_menu_items[NUM_MOTI_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {
  int num_a_items = 0;

	moti_menu_items[num_a_items++] = (SimpleMenuItem){
		.title = "Rettilineo uniforme",
		.subtitle = "x=x0+vt",
  };
	moti_menu_items[num_a_items++] = (SimpleMenuItem){
		.title = "Uniformemente accelerato",
		.subtitle = "x=x0+vt+½at²",
  };
	moti_menu_items[num_a_items++] = (SimpleMenuItem){
		.title = "Rettilineo smorzato",
		.subtitle = "x=v0/k[1-e^(-kt)]",
  };
	moti_menu_items[num_a_items++] = (SimpleMenuItem){
		.title = "Caduta libera",
		.subtitle = "x=h-vt-½gt²",
  };
	moti_menu_items[num_a_items++] = (SimpleMenuItem){
		.title = "Moto armonico semplice",
		.subtitle = "x=A·sin(wx+phi)",
  };
	moti_menu_items[num_a_items++] = (SimpleMenuItem){
		.title = "Moto parabolico",
		.subtitle = "y=x·tg(A)-gx^2/[2v^2·cos(A)]",
  };
	moti_menu_items[num_a_items++] = (SimpleMenuItem){
		.title = "Gittata",
		.subtitle = "2v^2·cos(A)sin(A)/g",
  };

  menu_sections.num_items = NUM_MOTI_MENU_ITEMS;
  menu_sections.items = moti_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_moti_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}