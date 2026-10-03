	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, _080BB23C @ =0x000012ED
	adds r0, r6, r1
	movs r5, #0
	strb r5, [r0]
	adds r0, r6, #0
	bl FUN_080baa40
	ldr r2, _080BB240 @ =0x000012F2
	adds r1, r6, r2
	strh r0, [r1]
	ldr r0, _080BB244 @ =0x03003ED0
	ldr r4, [r0, #0x2c]
	ldr r1, _080BB248 @ =0x000012D8
	adds r0, r6, r1
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
	adds r4, #0xe4
	ldr r2, _080BB24C @ =0x0000F050
	adds r0, r2, #0
	strh r0, [r4]
	adds r4, #2
	ldr r1, _080BB250 @ =0x0000F051
	adds r0, r1, #0
	strh r0, [r4]
	adds r4, #2
	adds r2, #2
	adds r0, r2, #0
	strh r0, [r4]
	adds r4, #2
	adds r1, #0xf
	adds r0, r1, #0
	strh r0, [r4]
	adds r4, #2
	adds r2, #0xf
	adds r0, r2, #0
	strh r0, [r4]
	adds r4, #2
	adds r1, #2
	adds r0, r1, #0
	strh r0, [r4]
	adds r4, #2
	subs r2, #0x51
	adds r0, r2, #0
	strh r0, [r4]
	adds r4, #2
	strh r0, [r4]
	adds r4, #2
	strh r0, [r4]
	adds r4, #2
	strh r0, [r4]
	strh r0, [r4, #2]
	ldr r0, _080BB254 @ =0x0000151A
	adds r4, r6, r0
	ldrb r0, [r4]
	bl FUN_080b94cc
	ldrb r0, [r4]
	bl FUN_080b9400
	ldr r1, _080BB258 @ =0x00001408
	adds r4, r6, r1
	movs r0, #0x14
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #4
	movs r3, #0
	bl FUN_080b9ff8
	ldr r2, _080BB25C @ =0x00000D98
	adds r1, r6, r2
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r6, #0
	bl FUN_080ba410
	adds r0, r6, #0
	bl FUN_080ba57c
	adds r0, r6, #0
	bl FUN_080ba2d8
	ldr r0, _080BB260 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x5c
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _080BB264
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r6, #0
	bl FUN_080ba0f0
	b _080BB274
	.align 2, 0
_080BB23C: .4byte 0x000012ED
_080BB240: .4byte 0x000012F2
_080BB244: .4byte 0x03003ED0
_080BB248: .4byte 0x000012D8
_080BB24C: .4byte 0x0000F050
_080BB250: .4byte 0x0000F051
_080BB254: .4byte 0x0000151A
_080BB258: .4byte 0x00001408
_080BB25C: .4byte 0x00000D98
_080BB260: .4byte 0x030046A0
_080BB264:
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl GetInventoryArmor
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_080ba0f0
_080BB274:
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ba85c
	ldr r1, _080BB290 @ =FUN_080baae8
	adds r0, r6, #0
	movs r2, #1
	bl FUN_080ba054
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BB290: .4byte FUN_080baae8
