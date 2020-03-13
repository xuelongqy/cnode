;;-------------------------------------------------------------------------------------------------------
;; Copyright (C) Microsoft Corporation and contributors. All rights reserved.
;; Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
;;-------------------------------------------------------------------------------------------------------

(module
  (import "dummy" "memory" (memory 1))

    (func (export "i16x8_anytrue") (result i32)
        (i64x2.any_true (m128.load offset=0 align=4 (i32.const 0)))
    )

    (func (export "i16x8_alltrue") (result i32)
        (i64x2.all_true (m128.load offset=0 align=4 (i32.const 0)))
    )

    (func (export "func_i64x2_extractlane_0") (local $v1 m128)
        (set_local $v1 (m128.load offset=0 align=4 (i32.const 0)))
        (i64.store offset=0 (i32.const 8) (i64x2.extract_lane lane=0 (get_local $v1)))
    )

    (func (export "func_i64x2_extractlane_1") (local $v1 m128)
        (set_local $v1 (m128.load offset=0 align=4 (i32.const 0)))
        (i64.store offset=0 (i32.const 0) (i64x2.extract_lane lane=1 (get_local $v1)))
    )

    (func (export "func_i64x2_replacelane_0") (local $v1 m128) (local $val i64)
        (set_local $v1 (m128.load offset=0 align=4 (i32.const 0)))
        (set_local $val (i64.load offset=16 align=4 (i32.const 0)))
        (m128.store offset=0 (i32.const 0) (i64x2.replace_lane lane=0 (get_local $v1) (get_local $val)))
    )

    (func (export "func_i64x2_replacelane_1") (local $v1 m128) (local $val i64)
        (set_local $v1 (m128.load offset=0 align=4 (i32.const 0)))
        (set_local $val (i64.load offset=16 align=4 (i32.const 0)))
        (m128.store offset=0 (i32.const 0) (i64x2.replace_lane lane=1 (get_local $v1) (get_local $val)))
    )

    (func (export "func_i64x2_splat") (local $v1 i64) (local $v2 m128)
        (set_local $v1 (i64.load offset=0 align=4 (i32.const 0)))
        (set_local $v2 (i64x2.splat (get_local $v1)))
        (m128.store offset=0 (i32.const 0) (get_local $v2))
    )

    (func (export "func_i64x2_add") (local $v1 m128) (local $v2 m128)
        (set_local $v1 (m128.load offset=0 align=4 (i32.const 0)))
        (set_local $v2 (m128.load offset=0 align=4 (i32.const 16)))
        (m128.store offset=0 (i32.const 0) (i64x2.add (get_local $v1) (get_local $v2)))
    )

    (func (export "func_i64x2_sub") (local $v1 m128) (local $v2 m128)
        (set_local $v1 (m128.load offset=0 align=4 (i32.const 0)))
        (set_local $v2 (m128.load offset=0 align=4 (i32.const 16)))
        (m128.store offset=0 (i32.const 0) (i64x2.sub (get_local $v1) (get_local $v2)))
    )

    (func (export "func_i64x2_neg") (local $v1 m128)
        (set_local $v1 (m128.load offset=0 align=4 (i32.const 0)))
        (m128.store offset=0 (i32.const 0) (i64x2.neg (get_local $v1)))
    )

    (func (export "func_i64x2_anytrue") (local $v1 m128)
        (set_local $v1 (m128.load offset=0 align=4 (i32.const 0)))
        (i32.store offset=0 (i32.const 0) (i64x2.any_true (get_local $v1)))
    )

    (func (export "func_i64x2_alltrue") (local $v1 m128)
        (set_local $v1 (m128.load offset=0 align=4 (i32.const 0)))
        (i32.store offset=0 (i32.const 0) (i64x2.all_true (get_local $v1)))
    )

    (func (export "func_i64x2_shl") (param $shamt i32) (local $v1 m128)
        (set_local $v1 (m128.load offset=0 align=4 (i32.const 0)))
        (m128.store offset=0 (i32.const 0) (i64x2.shl (get_local $v1) (get_local $shamt)))
    )

    (func (export "func_i64x2_shr_s") (param $shamt i32) (local $v1 m128)
        (set_local $v1 (m128.load offset=0 align=4 (i32.const 0)))
        (m128.store offset=0 (i32.const 0) (i64x2.shr_s (get_local $v1) (get_local $shamt)))
    )

    (func (export "func_i64x2_shr_u") (param $shamt i32) (local $v1 m128)
        (set_local $v1 (m128.load offset=0 align=4 (i32.const 0)))
        (m128.store offset=0 (i32.const 0) (i64x2.shr_u (get_local $v1) (get_local $shamt)))
    )
)
