// public
void saten_load_resources(saten_scene_info scene, bool threaded)
{
    saten_load_on_thread = threaded;
    saten_now_loading = scene;
    if (threaded) {
        //TODO
    } else {
        // Set uid to check which resources to load (in case file has resources
        // for various scenes
        // something_global = scene.uid;
        // Uses path to a mrb script calling functions to load resources
        FILE *f = NULL;
        saten_fopen(&f, saten_darr_scene[scene.id].loadscriptfp, "r");
        mrb_load_file_cxt(saten_mrb, f, saten_mrbc);
        fclose(f);
        saten_scene_load_done(scene);
    }
}

// private
mrb_value saten_mrb_load_img(mrb_state *mrb, mrb_value self)
{
    char *string;
    mrb_int mrb_id; int id;
    mrb_bool mrb_opt; bool opt;
    mrb_get_args(saten_mrb, "z|i?", &string, &mrb_id, &mrb_opt);
    id = (int)mrb_id;
    opt = (bool)mrb_opt;
    int i;

    if (!opt || id == saten_now_loading.uid) {
        saten_resmngr *res;
        if (saten_load_on_thread)
            res = &saten_vres;
        else
            res = &(saten_darr_scene[saten_now_loading.id].res);
        // load file if no scene given or if we want to load files for id
        /*
        saten_asset.sprite_n++;
        saten_asset.sprite = saten_realloc(saten_asset.sprite,
                (saten_asset.sprite_n) * sizeof(saten_sprite*));
        saten_asset.sprite[saten_asset.sprite_n-1] = saten_sprite_load(string);
        */
        res->sprite_n++;
        i = res->sprite_n;
        res->sprite = saten_realloc(res->sprite, i * sizeof(saten_sprite*));
        res->sprite[i-1] = saten_sprite_load(string);
        //saten_darr_scene[saten_now_loading.id].asset_num_sprite++;
    }

    return mrb_nil_value();
}

// private
mrb_value saten_mrb_load_sfx(mrb_state *mrb, mrb_value self)
{
    char *string;
    mrb_int mrb_id; int id;
    mrb_bool mrb_opt; bool opt;
    mrb_get_args(saten_mrb, "z|i?", &string, &mrb_id, &mrb_opt);
    id = (int)mrb_id;
    opt = (bool)mrb_opt;
    int i;

    if (!opt || id == saten_now_loading.uid) {
        saten_resmngr *res;
        if (saten_load_on_thread)
            res = &saten_vres;
        else
            res = &(saten_darr_scene[saten_now_loading.id].res);
        // load file if no scene given or if we want to load files for id
        /*
        saten_asset.sfx_n++;
        saten_asset.sfx = saten_realloc(saten_asset.sfx,
                (saten_asset.sfx_n) * sizeof(Mix_Chunk*));
        saten_asset.sfx[saten_asset.sfx_n-1] = Mix_LoadWAV(string);
        */
        res->sfx_n++;
        i = res->sfx_n;
        res->sfx = saten_realloc(res->sfx, i * sizeof(Mix_Chunk*));
        res->sfx[i-1] = Mix_LoadWAV(string);
        //saten_darr_scene[saten_now_loading.id].asset_num_sfx++;
    }

    return mrb_nil_value();
}

// private
mrb_value saten_mrb_load_bgm(mrb_state *mrb, mrb_value self)
{
    char *string;
    mrb_int mrb_id; int id;
    mrb_bool mrb_opt; bool opt;
    mrb_get_args(saten_mrb, "z|i?", &string, &mrb_id, &mrb_opt);
    id = (int)mrb_id;
    opt = (bool)mrb_opt;
    int i;

    if (!opt || id == saten_now_loading.uid) {
        saten_resmngr *res;
        if (saten_load_on_thread)
            res = &saten_vres;
        else
            res = &(saten_darr_scene[saten_now_loading.id].res);
        // load file if no scene given or if we want to load files for id
        /*
        saten_asset.bgm_n++;
        saten_asset.bgm = saten_realloc(saten_asset.bgm,
                (saten_asset.bgm_n) * sizeof(Mix_Music*));
        saten_asset.bgm[saten_asset.bgm_n-1] = Mix_LoadMUS(string);
        */
        res->bgm_n++;
        i = res->bgm_n;
        res->bgm = saten_realloc(res->bgm, i * sizeof(Mix_Music*));
        res->bgm[i-1] = Mix_LoadMUS(string);
        //saten_darr_scene[saten_now_loading.id].asset_num_bgm++;
    }

    return mrb_nil_value();
}

// private
mrb_value saten_mrb_load_text(mrb_state *mrb, mrb_value self)
{
    char *string;
    mrb_int mrb_id; int id;
    mrb_bool mrb_opt; bool opt;
    mrb_get_args(saten_mrb, "z|i?", &string, &mrb_id, &mrb_opt);
    id = (int)mrb_id;
    opt = (bool)mrb_opt;
    int i;

    if (!opt || id == saten_now_loading.uid) {
        saten_resmngr *res;
        if (saten_load_on_thread)
            res = &saten_vres;
        else
            res = &(saten_darr_scene[saten_now_loading.id].res);
        /*
        saten_asset.text_n++;
        saten_asset.text = saten_realloc(saten_asset.text,
                (saten_asset.text_n) * sizeof(saten_text*));
        saten_asset.text[saten_asset.text_n-1] = saten_text_create(1.0, string,
                0, 0);
        */
        res->text_n++;
        i = res->text_n;
        res->text = saten_realloc(res->text, i * sizeof(saten_text*));
        res->text[i-1] = saten_text_create(1.0, string, 0, 0);
        //saten_darr_scene[saten_now_loading.id].asset_num_text++;
    }

    return mrb_nil_value();
}
