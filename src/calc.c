#include "pebble.h"
#include "calc.h"

	
#define NUM_CALC_MENU_ITEMS 7

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem calc_menu_items[NUM_CALC_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {

  int num_a_items = 0;

  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Regra do produto",
	.subtitle = "uv' + vu'"
  };
  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Regra do quociente",
	.subtitle = "(vu' - uv')/v²"
  };  
  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Regra da cadeia",
	.subtitle = "f(g(x)) => f'(g(x))·g'(x)"
  };
  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(x^n)",
  .subtitle = "f'(x) = nx^(n-1)"
  };
  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(ln(x))",
	.subtitle = "f'(ln x)= (1/x)"
  };
  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(e^x)",
	.subtitle = "f'(e^x)= e^x·(du/dx)"
  };
  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(a^x)",
  .subtitle = "(a^x)·ln(a)"
  };
  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(ln|x|)",
  .subtitle = "1/x"
  };

  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(log x na base a)",
  .subtitle = "1/(x·ln(a))"
  };

  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(sen(x))",
  .subtitle = "cos(x)"
  };


  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(cos(x))",
  .subtitle = "-sen(x)"
  };


  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(tg(x))",
  .subtitle = "sec²(x)"
  };


  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(cossec(x))",
  .subtitle = "-cossec(x)·cotg(x)"
  };


  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(sec(x))",
  .subtitle = "sec(x)·tg(x)"
  };


  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(cotg(x))",
  .subtitle = "-cossec²(x)"
  };


  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(arcsen(x))",
  .subtitle = "1/((1-x²)^1/2)"
  };


  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(arccos(x))",
  .subtitle = "-1/((1-x²)^1/2)"
  };


  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(arctg(x))",
  .subtitle = "1/(1+x²)"
  };


  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(arccossec(x))",
  .subtitle = "-1/(x·(x²-1)^1/2)"
  };


  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(arcsec(x))",
  .subtitle = "1/(x·(x²-1)^1/2)"
  };

  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(arccotg(x))",
  .subtitle = "-1/(1+x²)"
  };

  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(senh(x))",
  .subtitle = "cosh(x)"
  };

  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(cosh(x))",
  .subtitle = "senh(x)"
  };

  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(tgh(x))",
  .subtitle = "sech²(x)"
  };

  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(cossech(x))",
  .subtitle = "-cossech(x)·cotgh(x)"
  };

  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(sech(x))",
  .subtitle = "-sech(x)·tgh(x)"
  };

  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(cotgh(x))",
  .subtitle = "-cossech²(x)"
  };

  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(arcsenh(x))",
  .subtitle = "1/((1+x²)^1/2)"
  };


  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(arccosh(x))",
  .subtitle = "1/((x²-1)^1/2)"
  };


  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(arctgh(x))",
  .subtitle = "1/(1-x²)"
  };


  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(arccossech(x))",
  .subtitle = "-1/(|x|·(x²+1)^1/2)"
  };


  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(arcsech(x))",
  .subtitle = "-1/(x·(1-x²)^1/2)"
  };

  calc_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "D(arccotgh(x))",
  .subtitle = "1/(1-x²)"
  };

  menu_sections.num_items = NUM_CALC_MENU_ITEMS;
  menu_sections.items = calc_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_calc_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}