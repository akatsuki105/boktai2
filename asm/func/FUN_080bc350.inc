	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _080BC3E4 @ =0x000012ED
	adds r1, r4, r0
	movs r5, #0
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FindEmptyArmorSlot
	ldr r2, _080BC3E8 @ =0x000012F2
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _080BC3EC @ =0x000012D8
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #2
	bl Video_SetBGLayer
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r2, _080BC3F0 @ =0x0000151A
	adds r5, r4, r2
	ldrb r0, [r5]
	bl FUN_080b94cc
	ldrb r0, [r5]
	bl FUN_080b9400
	ldr r0, _080BC3F4 @ =0x00001408
	adds r5, r4, r0
	movs r0, #0x14
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #4
	movs r3, #0
	bl MenuCursor_Init
	ldr r2, _080BC3F8 @ =0x00000D98
	adds r1, r4, r2
	adds r0, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080bb388
	adds r0, r4, #0
	bl FUN_080bb5bc
	adds r0, r4, #0
	bl FUN_080bb294
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080bb8f4
	ldr r1, _080BC3FC @ =FUN_080bbc60
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080ba054
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BC3E4: .4byte 0x000012ED
_080BC3E8: .4byte 0x000012F2
_080BC3EC: .4byte 0x000012D8
_080BC3F0: .4byte 0x0000151A
_080BC3F4: .4byte 0x00001408
_080BC3F8: .4byte 0x00000D98
_080BC3FC: .4byte FUN_080bbc60
