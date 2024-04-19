#include "py/dynruntime.h"


int32_t colorwheel_calc(mp_float_t pos) {
    pos = pos - ((uint32_t)(pos / 256) * 256);
    int shift1, shift2;
    if (pos < 85) {
        shift1 = 8;
        shift2 = 16;
    } else if (pos < 170) {
        pos -= 85;
        shift1 = 0;
        shift2 = 8;
    } else {
        pos -= 170;
        shift1 = 16;
        shift2 = 0;
    }
    int p = (int)(pos * 3);
    p = (p < 256) ? p : 255;
    return (p << shift1) | ((255 - p) << shift2);
}

static mp_obj_t colorwheel(mp_obj_t n) {
    mp_float_t f = mp_obj_get_float(n);
    return mp_obj_new_int(colorwheel_calc(f));
}
static MP_DEFINE_CONST_FUN_OBJ_1(colorwheel_obj, colorwheel);

mp_obj_t mpy_init(mp_obj_fun_bc_t *self, size_t n_args, size_t n_kw, mp_obj_t *args) {
    MP_DYNRUNTIME_INIT_ENTRY

    mp_store_global(MP_QSTR_colorwheel, MP_OBJ_FROM_PTR(&colorwheel_obj));

    MP_DYNRUNTIME_INIT_EXIT
}
