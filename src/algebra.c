#include "pebble.h"
#include "algebra.h"
	
#define NUM_ALGEBRA_MENU_ITEMS 12

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem algebra_menu_items[NUM_ALGEBRA_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {
  int num_a_items = 0;

	  algebra_menu_items[num_a_items++] = (SimpleMenuItem){
   	  .title = "Soluzione eq quadratica",
	  .subtitle = "(-b±(b²-4ac)^½)/(2a)",
  };
	  algebra_menu_items[num_a_items++] = (SimpleMenuItem){
	  .title = "Formula di Grassmann",
	  .subtitle = "dim(W+V)=dim(W)+dim(V)-dim(W∩V)",
  };
	  algebra_menu_items[num_a_items++] = (SimpleMenuItem){
	  .title = "Trasposta del prodotto",
	  .subtitle = "t(AB)=tBtA",
  };
	  algebra_menu_items[num_a_items++] = (SimpleMenuItem){
	  .title = "Matrice simmetrica",
	  .subtitle = "A=tA",
  };
	  algebra_menu_items[num_a_items++] = (SimpleMenuItem){
	  .title = "Matrice antisimmetrica",
	  .subtitle = "A=-tA",
  };
	  algebra_menu_items[num_a_items++] = (SimpleMenuItem){
	  .title = "Teorema dimensioni",
	  .subtitle = "n=dim(Ker)+dim(Im)",
  };
	  algebra_menu_items[num_a_items++] = (SimpleMenuItem){
	  .title = "Molteplicità algebrica a",
	  .subtitle = "Esponente autovalore",
  };
	  algebra_menu_items[num_a_items++] = (SimpleMenuItem){
	  .title = "Molteplicità geometrica g",
	  .subtitle = "g=n-rk(A-aI)",
  };
	  algebra_menu_items[num_a_items++] = (SimpleMenuItem){
	  .title = "Rango rk",
	  .subtitle = "Dim max det≠0",
  };
	  algebra_menu_items[num_a_items++] = (SimpleMenuItem){
	  .title = "Diagonalizzabilità",
	  .subtitle = "1 ≤ g ≤ a ≤ n",
  };
	  algebra_menu_items[num_a_items++] = (SimpleMenuItem){
	  .title = "Teorema di Binet",
	  .subtitle = "det(AB)=det(A)·det(B)",
  };
	  algebra_menu_items[num_a_items++] = (SimpleMenuItem){
	  .title = "Teorema del rango",
	  .subtitle = "det(A)≠0 se rk(A)=n se ∃A^-1",
  };

  menu_sections.num_items = NUM_ALGEBRA_MENU_ITEMS;
  menu_sections.items = algebra_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_algebra_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}