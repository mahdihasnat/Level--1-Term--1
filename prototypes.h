


// road.h
char * int_to_string(int a,char *s);
void print_road_right();
void print_road_background(double left,double bottom);
void road_run();
void print_life_meter(double left,double bottom,int life);


// car.h
void print_car(int left,int bottom ,int type);
void print_car_pic(double left,double bottom,int type);
void print_car_demo(double left,double bottom,int type);
int car_col_cmp(game_data &a,int i);
void power_col();

// menu.h
void pre_game_over(game_data &a);
void print_game_over();
void menu_input_mouse(int button, int state, int mx, int my);
void menu_input_key(unsigned char key);
void menu_input_sp_key(unsigned char key);
void mode_input_mouse(int button, int state, int mx, int my);
void mode_input_key(unsigned char key);
void mode_input_sp_key(unsigned char key);






// playing.h
void get_user_string(char key);
void resume_game();
void pause_game();
void playing_input_key(unsigned char key);
void print_pause_menu();
void play_start();
void playing_input_mouse(int button, int state, int mx, int my);
void playing_input_key(unsigned char key);
void pause_game();
void resume_game();
void playing_input_sp_key(unsigned char key);
void reset_game(game_data &a);
void power_col(game_data &a);

//settings.h
void print_settings(void);

void settings_input_mouse(int button, int state, int mx, int my);
void settings_input_key(unsigned char key);
void settings_input_sp_key(unsigned char key);


// about.h
void print_about(void);

// help.h
void print_help(void);
void help_input_sp_key(unsigned char key);
void help_input_key(unsigned char key);
void help_input_mouse(int button, int state, int mx, int my);
void help_change();


// sounds.h
void start_music();
void stop_music();
void sync_music();

//highscore.h
void print_high_score();
void update_high_score(struct game_data );
void get_high_score();
void high_score_input_mouse(int button, int state, int mx, int my);
void high_score_input_key(unsigned char key);
void high_score_input_sp_key(unsigned char key);
void erase_high_score();

// updating data
void update_game();
void save_file();
void save_game();
void load_game_data();
void load_a_game();
void delate_game(int idx);


//load_game
void print_load_menu(void);
void print_load_menu(void);
void load_input_mouse(int button, int state, int mx, int my);
void load_input_key(unsigned char key);
void load_input_sp_key(unsigned char key);
void delete_input_mouse(int button, int state, int mx, int my);
void delete_input_key(unsigned char key);

//aligner.h

double align_string(double left,double dx,char *p);
