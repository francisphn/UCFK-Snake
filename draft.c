int max_score_chooser(void)
{
    int max_score = 10;

    tinygl_clear();
    tiny_text_init();
    tinygl_text_mode_set(TINYGL_TEXT_MODE_STEP);
    tinygl_text("10");

    while(1)
    {
        pacer_wait();
        tinygl_update();
        navswitch_update();

        if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
            if (level == 3) {
                level = 1;
            } else {
                level++;
            }
        
            if (level == 1) {
                tinygl_text("L1");
            } else if (level == 2) {
                tinygl_text("L2");
            } else if (level == 3) {
                tinygl_text("L3");
            }

        } else if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {

            if (level == 1) {
                level = 3;
            } else {
                level--;
            }
        
            if (level == 1) {
                tinygl_text("L1");
            } else if (level == 2) {
                tinygl_text("L2");
            } else if (level == 3) {
                tinygl_text("L3");
            }
        } else if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
            tinygl_clear();
            return level;
        }
    }
    return 0;
}