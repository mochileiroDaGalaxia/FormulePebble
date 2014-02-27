#include "pebble.h"
#include "geometry.h"
#include "coniche.h"

	
#define NUM_GEOMETRY_MENU_ITEMS 14

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem geometry_menu_items[NUM_GEOMETRY_MENU_ITEMS];

static void coni_select_callback(int index, void *ctx) {
  show_coni_menu();
}

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {
  int num_a_items = 0;

  	geometry_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Teorema di Pitagora",
	.subtitle = "A²+B²=C²"
  };
	geometry_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Coniche",
	.callback = coni_select_callback
  };
	geometry_menu_items[num_a_items++] = (SimpleMenuItem){
      .title = "Coef angolare",
      .subtitle = "M=(Y2-Y1)/(X2-X1)",
  };
	geometry_menu_items[num_a_items++] = (SimpleMenuItem){
      .title = "Punto medio",
	  .subtitle = "(X1+X2)/2,(Y1+Y2)/2",
  };
	geometry_menu_items[num_a_items++] = (SimpleMenuItem){
	  .title = "Retta P Q",
	  .subtitle = "Xi=P+t(P-Q)",
  };
	geometry_menu_items[num_a_items++] = (SimpleMenuItem){
	  .title = "Piano P Q w",
	  .subtitle = "Xi=P+t(P-Q)+s(w)",
  };
	geometry_menu_items[num_a_items++] = (SimpleMenuItem){
	  .title = "Dist punto piano",
	  .subtitle = "d(Pπ)=|ax+by+cz+d|/(a²+b²+c²)",
  };
  	geometry_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Area triangolo",
	.subtitle = "½BH"
  };
 	geometry_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Area cerchio",
	.subtitle = "πr²"
  };
	geometry_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Sfera",
	.subtitle = "(Xi-X0)²=r²",
  };
	geometry_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Centro sfera",
	.subtitle = "X0=-½a",
  };
	geometry_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Area sfera",
	.subtitle = "4/3πr^3",
  };
  	geometry_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Volume piramide",
	.subtitle = "(1/3)bh = 1/3πr²h"
  };
  	geometry_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Volume cono",
	.subtitle = "(1/3)bh = 1/3πr²h"
  };
  menu_sections.num_items = NUM_GEOMETRY_MENU_ITEMS;
  menu_sections.items = geometry_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_geometry_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}