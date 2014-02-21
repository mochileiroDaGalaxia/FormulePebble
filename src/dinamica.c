#include "pebble.h"
#include "dinamica.h"
#include "moti.h"
	
#define NUM_DINAMICA_MENU_ITEMS 17

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem dinamica_menu_items[NUM_DINAMICA_MENU_ITEMS];

static void moti_select_callback(int index, void *ctx) {
  show_moti_menu();
}

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {
  int num_a_items = 0;

  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Newton 2",
	.subtitle = "F=ma",
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Newton 3",
	.subtitle = "F1=F2",
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Equilibrio",
	.subtitle = "F1+F2+...=0",
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Equilibrio",
	.subtitle = "M1+M2+...=0",
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Quantità di moto",
	.subtitle = "p=mv",
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Impulso",
	.subtitle = "J=∆p",
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Lavoro",
	.subtitle = "W=F·d·cos(a)"
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Potenza",
	.subtitle = "P=W/t=F·v",
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Energia cinetica",
	.subtitle = "K=½mv²"
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Energia potenziale",
	.subtitle = "V=mgh"
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Momento angolare",
	.subtitle = "L=r x p",
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Momento di F",
	.subtitle = "M=r x F",
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Teorema momento angolare",
	.subtitle = "M=dL/dt",
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Periodo",
	.subtitle = "T=2π/w"
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Frequenza",
	.subtitle = "v=1/T"
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Potenziale molla",
	.subtitle = "V=½kx²"
  };
  dinamica_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Moti",
	.callback = moti_select_callback,
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