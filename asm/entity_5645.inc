	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0805308c
FUN_0805308c: @ 0x0805308C
	ldr r1, _08053094 @ =0x03000120
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08053094: .4byte 0x03000120

	thumb_func_start FUN_08053098
FUN_08053098: @ 0x08053098
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r5, r3, #0
	cmp r1, #8
	bls _080530A6
	b _0805321A
_080530A6:
	lsls r0, r1, #2
	ldr r1, _080530B0 @ =_080530B4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080530B0: .4byte _080530B4
_080530B4: @ jump table
	.4byte _080530D8 @ case 0
	.4byte _0805311E @ case 1
	.4byte _08053104 @ case 2
	.4byte _08053146 @ case 3
	.4byte _08053170 @ case 4
	.4byte _08053196 @ case 5
	.4byte _080531BC @ case 6
	.4byte _080531D8 @ case 7
	.4byte _080531F4 @ case 8
_080530D8:
	movs r2, #0
	str r2, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #1
	bl FUN_080da9c4
	str r0, [r4, #0x24]
	ldr r0, _08053100 @ =0x000001B1
	bl PlaySound_082406e0
	b _0805321A
	.align 2, 0
_08053100: .4byte 0x000001B1
_08053104:
	movs r2, #0
	str r2, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #0
	b _08053136
_0805311E:
	movs r2, #0
	str r2, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #3
_08053136:
	bl FUN_080da9c4
	str r0, [r4, #0x24]
	movs r0, #0xf6
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0805321A
_08053146:
	movs r2, #0
	str r2, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #2
	bl FUN_080da9c4
	str r0, [r4, #0x24]
	ldr r0, _0805316C @ =0x000001ED
	bl PlaySound_082406e0
	b _0805321A
	.align 2, 0
_0805316C: .4byte 0x000001ED
_08053170:
	movs r0, #1
	str r0, [r4, #0x28]
	movs r3, #0
	strh r2, [r4, #0x2c]
	strh r5, [r4, #0x2e]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	adds r2, r4, #0
	adds r2, #0x2c
	str r2, [sp]
	movs r5, #0x2e
	ldrsh r2, [r4, r5]
	str r2, [sp, #4]
	str r3, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #1
	b _08053214
_08053196:
	movs r0, #3
	str r0, [r4, #0x28]
	movs r3, #0
	strh r2, [r4, #0x2c]
	strh r5, [r4, #0x2e]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	adds r2, r4, #0
	adds r2, #0x2c
	str r2, [sp]
	movs r5, #0x2e
	ldrsh r2, [r4, r5]
	str r2, [sp, #4]
	str r3, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #3
	b _08053214
_080531BC:
	movs r0, #5
	str r0, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #5
	movs r3, #0
	b _08053214
_080531D8:
	movs r0, #4
	str r0, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #4
	movs r3, #0
	b _08053214
_080531F4:
	ldr r3, [r4, #0x24]
	cmp r3, #0
	beq _0805321A
	adds r1, r4, #0
	adds r1, #0x30
	ldr r2, [r4, #0x28]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #0x64
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r3, #0x7f
_08053214:
	bl FUN_080da9c4
	str r0, [r4, #0x24]
_0805321A:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08053224
FUN_08053224: @ 0x08053224
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r5, r4, #0
	adds r5, #0x7c
	ldr r0, [r4, #0x7c]
	cmp r0, #1
	bne _0805324C
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bls _08053246
	adds r1, r0, #0
	movs r0, #3
	subs r2, r0, r1
	b _08053262
_08053246:
	ldrb r2, [r4, #0x10]
	movs r3, #0
	b _08053264
_0805324C:
	ldrb r1, [r4, #0x10]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r2, #0
	cmp r0, #1
	bhi _0805325C
	adds r2, r3, #0
_0805325C:
	movs r3, #0
	cmp r1, #1
	bls _08053264
_08053262:
	movs r3, #1
_08053264:
	str r6, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	ldr r0, [sp, #0x24]
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08055b5c
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08053280
FUN_08053280: @ 0x08053280
	push {r4, r5, lr}
	sub sp, #0xc
	adds r3, r0, #0
	adds r5, r1, #0
	adds r1, r2, #0
	adds r4, r3, #0
	adds r4, #0x7c
	ldr r0, [r3, #0x7c]
	cmp r0, #1
	bne _0805329E
	ldrb r2, [r3, #0x10]
	movs r3, #0
	cmp r2, #1
	bls _080532AA
	b _080532A8
_0805329E:
	movs r2, #0
	ldrb r0, [r3, #0x10]
	movs r3, #0
	cmp r0, #1
	bls _080532AA
_080532A8:
	movs r3, #1
_080532AA:
	str r1, [sp]
	ldr r0, [sp, #0x18]
	str r0, [sp, #4]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08055b5c
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080532c4
FUN_080532c4: @ 0x080532C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r5, r3, #0
	ldr r0, [r4, #0x7c]
	cmp r0, #1
	bne _080532EC
	ldrb r0, [r4, #0x11]
	cmp r0, #4
	bls _080532E6
	adds r1, r0, #0
	movs r0, #8
	subs r2, r0, r1
	movs r3, #1
	b _08053308
_080532E6:
	ldrb r2, [r4, #0x11]
	movs r3, #0
	b _08053308
_080532EC:
	ldrb r0, [r4, #0x11]
	cmp r0, #4
	bls _080532FC
	adds r1, r0, #0
	movs r0, #8
	subs r2, r0, r1
	movs r3, #1
	b _08053302
_080532FC:
	ldrb r2, [r4, #0x11]
	movs r3, #0
	adds r1, r2, #0
_08053302:
	adds r0, r1, #0
	muls r0, r5, r0
	strb r0, [r4, #0x11]
_08053308:
	adds r0, r4, #0
	adds r0, #0x7c
	str r6, [sp]
	ldr r1, [sp, #0x20]
	str r1, [sp, #4]
	ldr r1, [sp, #0x24]
	str r1, [sp, #8]
	adds r1, r7, #0
	bl FUN_08055b5c
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08053324
FUN_08053324: @ 0x08053324
	push {r4, lr}
	sub sp, #0xc
	ldr r3, [sp, #0x14]
	ldr r4, [sp, #0x18]
	adds r0, #0x7c
	str r2, [sp]
	str r3, [sp, #4]
	str r4, [sp, #8]
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08053344
FUN_08053344: @ 0x08053344
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r3, #0
	ldr r7, [sp, #0x1c]
	str r2, [r4, #0x20]
	cmp r2, #3
	bgt _0805337E
	ldr r0, [r4]
	cmp r0, #0
	bne _08053368
	adds r0, r6, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _08053368
	adds r2, #0xa
_08053368:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	ldrh r2, [r0, #2]
	movs r3, #1
	ldrsb r3, [r0, r3]
	b _0805338C
_0805337E:
	subs r0, r2, #4
	ldr r1, _080533A4 @ =0x085AB924
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	ldrh r2, [r0, #2]
	ldrb r3, [r0, #1]
_0805338C:
	cmp r1, #1
	bne _080533A8
	str r7, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r2, #0
	adds r2, r5, #0
	bl FUN_08053280
	b _080533E4
	.align 2, 0
_080533A4: .4byte 0x085AB924
_080533A8:
	cmp r1, #2
	bne _080533BE
	str r7, [sp]
	ldr r1, [sp, #0x20]
	str r1, [sp, #4]
	adds r0, r4, #0
	adds r1, r2, #0
	adds r2, r5, #0
	bl FUN_08053224
	b _080533E4
_080533BE:
	cmp r1, #3
	bne _080533D4
	str r7, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r2, #0
	adds r2, r5, #0
	bl FUN_080532c4
	b _080533E4
_080533D4:
	str r7, [sp]
	ldr r1, [sp, #0x20]
	str r1, [sp, #4]
	adds r0, r4, #0
	adds r1, r2, #0
	adds r2, r5, #0
	bl FUN_08053324
_080533E4:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080533ec
FUN_080533ec: @ 0x080533EC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	adds r1, r3, #0
	ldr r5, [sp, #0x24]
	ldr r3, [sp, #0x28]
	adds r4, r7, #0
	adds r4, #0x7c
	cmp r2, #2
	bne _0805342E
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08055e34
	adds r5, r0, #0
	adds r0, r7, #0
	adds r0, #0xa8
	ldr r1, [r7]
	cmp r1, #2
	bne _08053422
	movs r1, #0x27
	bl MainSprite_SetPlttID
	b _0805344E
_08053422:
	cmp r1, #1
	bne _0805344E
	movs r1, #0x26
	bl MainSprite_SetPlttID
	b _0805344E
_0805342E:
	str r3, [sp]
	adds r0, r4, #0
	ldr r2, [sp, #0x20]
	adds r3, r5, #0
	bl FUN_08055dac
	adds r5, r0, #0
	adds r1, r7, #0
	adds r1, #0x88
	ldr r0, [r7]
	cmp r0, #2
	bne _0805344E
	adds r0, r1, #0
	movs r1, #0x27
	bl Video_SetAuxSpritePltt
_0805344E:
	cmp r5, #0
	bge _08053458
	movs r0, #1
	rsbs r0, r0, #0
	b _080534CC
_08053458:
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08055f5c
	movs r0, #0xc0
	movs r1, #0
	strb r0, [r7, #0xf]
	movs r0, #1
	strb r0, [r7, #0x11]
	movs r0, #3
	mov r8, r0
	movs r0, #0
	strb r0, [r7, #0x10]
	str r1, [sp]
	str r1, [sp, #4]
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #3
	movs r3, #1
	bl FUN_08053344
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r4, r7, r1
	movs r2, #0x84
	lsls r2, r2, #1
	adds r5, r7, r2
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl ParticleShadow_Init
	adds r0, r4, #0
	bl ParticleShadow_Show
	movs r0, #0x88
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r2, _080534D8 @ =0x000017EC
	adds r1, r6, r2
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822a470
	movs r1, #7
	strh r1, [r4, #0x10]
	ldr r2, _080534DC @ =0x00000117
	adds r1, r7, r2
	mov r2, r8
	strb r2, [r1]
	movs r1, #0x96
	lsls r1, r1, #1
	adds r3, r7, r1
	ldr r1, [r5]
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r3]
	str r2, [r3, #4]
_080534CC:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080534D8: .4byte 0x000017EC
_080534DC: .4byte 0x00000117

	thumb_func_start FUN_080534e0
FUN_080534e0: @ 0x080534E0
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x28]
	adds r0, r0, r1
	str r0, [r2, #0x28]
	cmp r0, #0
	bge _080534F4
	movs r0, #0
	str r0, [r2, #0x28]
	b _080534FE
_080534F4:
	movs r1, #0xfa
	lsls r1, r1, #2
	cmp r0, r1
	ble _080534FE
	str r1, [r2, #0x28]
_080534FE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08053504
FUN_08053504: @ 0x08053504
	push {lr}
	adds r0, #0x44
	ldrh r0, [r0]
	cmp r0, #1
	beq _08053518
	cmp r0, #1
	ble _08053522
	cmp r0, #2
	beq _0805351C
	b _08053522
_08053518:
	movs r0, #0x80
	b _08053524
_0805351C:
	movs r0, #0xa0
	lsls r0, r0, #1
	b _08053524
_08053522:
	movs r0, #0x40
_08053524:
	pop {r1}
	bx r1

	thumb_func_start FUN_08053528
FUN_08053528: @ 0x08053528
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r3, #0
	beq _08053540
	adds r3, r4, #0
	adds r3, #0x33
	movs r1, #0
	movs r0, #1
	strb r0, [r3]
	str r1, [r4, #0x34]
	str r5, [r4, #0x38]
_08053540:
	adds r0, r5, #0
	muls r0, r2, r0
	cmp r0, #0
	blt _0805354C
	asrs r1, r0, #6
	b _08053552
_0805354C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r1, r0, #0
_08053552:
	ldr r0, [r4, #0x3c]
	adds r0, r0, r1
	str r0, [r4, #0x3c]
	ldr r1, _08053564 @ =0x0000270F
	cmp r0, r1
	ble _08053568
	str r1, [r4, #0x3c]
	b _08053570
	.align 2, 0
_08053564: .4byte 0x0000270F
_08053568:
	cmp r0, #0
	bge _08053570
	movs r0, #0
	str r0, [r4, #0x3c]
_08053570:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08053578
FUN_08053578: @ 0x08053578
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x50]
	adds r0, #1
	str r0, [r1, #0x50]
	ldr r2, _08053598 @ =0x000003E7
	cmp r0, r2
	bls _0805358A
	str r2, [r1, #0x3c]
_0805358A:
	ldr r2, [r1, #0x50]
	ldr r0, [r1, #0x54]
	cmp r2, r0
	bls _08053594
	str r2, [r1, #0x54]
_08053594:
	pop {r0}
	bx r0
	.align 2, 0
_08053598: .4byte 0x000003E7

	thumb_func_start FUN_0805359c
FUN_0805359c: @ 0x0805359C
	movs r1, #0
	str r1, [r0, #0x50]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080535a4
FUN_080535a4: @ 0x080535A4
	str r1, [r0, #0x74]
	bx lr

	thumb_func_start FUN_080535a8
FUN_080535a8: @ 0x080535A8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, #0
	ldr r4, [sp, #0x18]
	movs r6, #0
	strb r6, [r7, #1]
	ldr r0, [r0, #0x2c]
	asrs r1, r0, #2
	adds r2, r2, r1
	strb r2, [r7, #2]
	strb r3, [r7, #3]
	asrs r0, r0, #1
	adds r0, #0x13
	strh r0, [r7, #4]
	strh r6, [r7, #6]
	str r4, [r7, #8]
	str r6, [r7, #0xc]
	movs r0, #0x20
	str r0, [r7, #0x10]
	adds r5, r7, #0
	adds r5, #0x1c
	ldr r0, _08053628 @ =0x085AB954
	lsls r4, r4, #1
	adds r4, r4, r0
	ldrh r1, [r4]
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r1, _0805362C @ =0x085AB740
	ldrb r0, [r7, #3]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x54
	strh r1, [r0]
	adds r1, r7, #0
	adds r1, #0x56
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08053630 @ =0x000008FC
	strh r0, [r1]
	str r6, [r7, #0x74]
	movs r0, #1
	strb r0, [r7]
	mov r1, r8
	ldr r0, [r1, #0x4c]
	adds r0, #1
	str r0, [r1, #0x4c]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053628: .4byte 0x085AB954
_0805362C: .4byte 0x085AB740
_08053630: .4byte 0x000008FC

	thumb_func_start FUN_08053634
FUN_08053634: @ 0x08053634
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x38
	bl FUN_0822a4e0
	movs r0, #0
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805364c
FUN_0805364c: @ 0x0805364C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x38
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _080536B0
	ldr r2, _080536A4 @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #8]
	ldrh r1, [r5, #4]
	lsrs r1, r1, #1
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r1, _080536A8 @ =0x00001004
	adds r2, r5, #0
	adds r2, #0x54
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0xfa
	str r0, [sp, #4]
	movs r0, #0
	add r3, sp, #8
	bl FUN_080607ec
	adds r0, r6, #0
	bl FUN_0805359c
	adds r0, r6, #0
	movs r1, #0x64
	bl FUN_080534e0
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08053634
	ldr r0, _080536AC @ =0x00000195
	bl PlaySound_082406e0
	b _080537D4
	.align 2, 0
_080536A4: .4byte 0xFFFF0000
_080536A8: .4byte 0x00001004
_080536AC: .4byte 0x00000195
_080536B0:
	movs r3, #1
	ldrh r1, [r5, #6]
	movs r0, #1
	orrs r0, r1
	strh r0, [r5, #6]
	ldrh r0, [r5, #4]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	strh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	ldr r1, _08053700 @ =0x0F9F0000
	cmp r0, r1
	ble _08053704
	adds r0, r6, #0
	bl FUN_08053578
	ldr r0, [r6, #0x2c]
	movs r1, #0x10
	rsbs r1, r1, #0
	subs r1, r1, r0
	adds r0, r6, #0
	bl FUN_080534e0
	movs r4, #2
	ldrsb r4, [r5, r4]
	adds r0, r6, #0
	bl FUN_08053504
	adds r2, r0, #0
	adds r0, r6, #0
	adds r1, r4, #0
	movs r3, #0
	bl FUN_08053528
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08053634
	b _080537D4
	.align 2, 0
_08053700: .4byte 0x0F9F0000
_08053704:
	adds r4, r5, #0
	adds r4, #0x64
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x64]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08053732
	ldr r0, [r5, #0x38]
	movs r1, #4
	orrs r0, r1
	b _0805373A
_08053732:
	ldr r0, [r5, #0x38]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0805373A:
	str r0, [r5, #0x38]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0805375E
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _08053766
_0805375E:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08053766:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0805379C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080537D4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080537A0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08053796
	ldrb r0, [r4, #5]
_08053796:
	subs r0, #1
	strh r0, [r4, #8]
	b _080537B0
	.align 2, 0
_0805379C: .4byte 0x0000FFFF
_080537A0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080537B0
	strh r1, [r4, #8]
_080537B0:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080537D4
	movs r0, #1
	strb r0, [r4, #7]
_080537D4:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080537dc
FUN_080537dc: @ 0x080537DC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x38
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _080537FC
	adds r0, r6, #0
	bl FUN_0805359c
	adds r0, r6, #0
	movs r1, #0x64
	bl FUN_080534e0
	b _08053840
_080537FC:
	ldrh r1, [r5, #6]
	movs r0, #1
	orrs r0, r1
	strh r0, [r5, #6]
	ldrh r0, [r5, #4]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	strh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	ldr r0, _0805384C @ =0x00000F9F
	cmp r1, r0
	ble _08053850
	adds r0, r6, #0
	bl FUN_08053578
	ldr r0, [r6, #0x2c]
	movs r1, #0x10
	rsbs r1, r1, #0
	subs r1, r1, r0
	adds r0, r6, #0
	bl FUN_080534e0
	movs r4, #2
	ldrsb r4, [r5, r4]
	adds r0, r6, #0
	bl FUN_08053504
	adds r2, r0, #0
	adds r0, r6, #0
	adds r1, r4, #0
	movs r3, #0
	bl FUN_08053528
_08053840:
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08053634
	b _08053950
	.align 2, 0
_0805384C: .4byte 0x00000F9F
_08053850:
	ldr r0, _08053864 @ =0x00000BB8
	cmp r1, r0
	bgt _08053878
	ldr r0, [r5, #0xc]
	movs r1, #3
	ands r0, r1
	cmp r0, #1
	bhi _08053868
	ldrb r0, [r5, #0x14]
	b _0805386A
	.align 2, 0
_08053864: .4byte 0x00000BB8
_08053868:
	ldrb r0, [r5, #0x15]
_0805386A:
	strb r0, [r5, #3]
	ldr r0, _080538A8 @ =0x085AB740
	ldrb r1, [r5, #3]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	strh r0, [r7, #0x1c]
_08053878:
	adds r4, r5, #0
	adds r4, #0x64
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x64]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080538AC
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080538B4
	.align 2, 0
_080538A8: .4byte 0x085AB740
_080538AC:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080538B4:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080538D8
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080538E0
_080538D8:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080538E0:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08053918 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08053950
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805391C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08053910
	ldrb r0, [r4, #5]
_08053910:
	subs r0, #1
	strh r0, [r4, #8]
	b _0805392C
	.align 2, 0
_08053918: .4byte 0x0000FFFF
_0805391C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0805392C
	strh r1, [r4, #8]
_0805392C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08053950
	movs r0, #1
	strb r0, [r4, #7]
_08053950:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08053958
FUN_08053958: @ 0x08053958
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x38
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _0805397A
	adds r0, r6, #0
	bl FUN_0805359c
	adds r0, r6, #0
	movs r1, #0x64
	bl FUN_080534e0
	b _080539E6
_0805397A:
	ldrh r0, [r5, #6]
	movs r1, #1
	orrs r1, r0
	strh r1, [r5, #6]
	ldr r0, [r5, #0xc]
	cmp r0, #0x40
	bne _080539A6
	adds r0, r5, #0
	adds r0, #0x64
	ldr r2, _080539F0 @ =0x000017E4
	adds r1, r6, r2
	ldr r1, [r1]
	movs r2, #1
	str r2, [sp]
	movs r2, #2
	movs r3, #1
	bl FUN_08236fac
	movs r0, #0xf2
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080539A6:
	ldr r0, [r5, #0xc]
	cmp r0, #0x3f
	bls _080539F8
	ldrh r0, [r5, #4]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	strh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	ldr r1, _080539F4 @ =0x0F9F0000
	cmp r0, r1
	ble _08053A38
	adds r0, r6, #0
	bl FUN_08053578
	ldr r0, [r6, #0x2c]
	movs r1, #0x10
	rsbs r1, r1, #0
	subs r1, r1, r0
	adds r0, r6, #0
	bl FUN_080534e0
	movs r4, #2
	ldrsb r4, [r5, r4]
	adds r0, r6, #0
	bl FUN_08053504
	adds r2, r0, #0
	adds r0, r6, #0
	adds r1, r4, #0
	movs r3, #0
	bl FUN_08053528
_080539E6:
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08053634
	b _08053B10
	.align 2, 0
_080539F0: .4byte 0x000017E4
_080539F4: .4byte 0x0F9F0000
_080539F8:
	ldrh r0, [r5, #4]
	lsrs r0, r0, #1
	ldrh r2, [r7, #0x20]
	adds r0, r0, r2
	strh r0, [r7, #0x20]
	ldr r2, _08053A20 @ =0x085B0A08
	ldr r0, [r5, #0xc]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _08053A24
	asrs r2, r0, #0xc
	b _08053A2A
	.align 2, 0
_08053A20: .4byte 0x085B0A08
_08053A24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08053A2A:
	ldr r0, _08053A68 @ =0x085AB740
	ldrb r1, [r5, #3]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
_08053A38:
	adds r4, r5, #0
	adds r4, #0x64
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x64]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08053A6C
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _08053A74
	.align 2, 0
_08053A68: .4byte 0x085AB740
_08053A6C:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08053A74:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08053A98
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _08053AA0
_08053A98:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08053AA0:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08053AD8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08053B10
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08053ADC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08053AD0
	ldrb r0, [r4, #5]
_08053AD0:
	subs r0, #1
	strh r0, [r4, #8]
	b _08053AEC
	.align 2, 0
_08053AD8: .4byte 0x0000FFFF
_08053ADC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08053AEC
	strh r1, [r4, #8]
_08053AEC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08053B10
	movs r0, #1
	strb r0, [r4, #7]
_08053B10:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08053b18
FUN_08053b18: @ 0x08053B18
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08053B50 @ =0x000008DC
	adds r4, r5, r0
	movs r6, #0x1f
_08053B22:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08053B40
	movs r0, #0
	strh r0, [r4, #6]
	ldr r2, [r4, #0x74]
	cmp r2, #0
	beq _08053B3A
	adds r0, r5, #0
	adds r1, r4, #0
	bl _call_via_r2
_08053B3A:
	ldr r0, [r4, #0xc]
	adds r0, #1
	str r0, [r4, #0xc]
_08053B40:
	subs r6, #1
	adds r4, #0x78
	cmp r6, #0
	bge _08053B22
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08053B50: .4byte 0x000008DC

	thumb_func_start FUN_08053b54
FUN_08053b54: @ 0x08053B54
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08053B7C @ =0x000008DC
	adds r4, r5, r0
	movs r6, #0x1f
_08053B5E:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08053B6C
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08053634
_08053B6C:
	subs r6, #1
	adds r4, #0x78
	cmp r6, #0
	bge _08053B5E
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08053B7C: .4byte 0x000008DC

	thumb_func_start FUN_08053b80
FUN_08053b80: @ 0x08053B80
	push {lr}
	ldr r2, _08053B94 @ =0x000008DC
	adds r1, r0, r2
	movs r2, #0
_08053B88:
	ldrb r0, [r1]
	cmp r0, #0
	bne _08053B98
	adds r0, r1, #0
	b _08053BA2
	.align 2, 0
_08053B94: .4byte 0x000008DC
_08053B98:
	adds r2, #1
	adds r1, #0x78
	cmp r2, #0x1f
	ble _08053B88
	movs r0, #0
_08053BA2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08053ba8
FUN_08053ba8: @ 0x08053BA8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	bl FUN_08053b80
	adds r6, r0, #0
	cmp r6, #0
	beq _08053C02
	ldr r2, _08053C0C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08053C10 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08053C14 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r3, r0, #0
	ldr r2, _08053C18 @ =0x00001E0C
	adds r0, r5, r2
	ldr r2, [r0]
	movs r4, #0
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_080535a8
	adds r0, r6, #0
	adds r0, #0x64
	ldr r2, _08053C1C @ =0x000017DC
	adds r1, r5, r2
	ldr r1, [r1]
	str r4, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	ldr r1, _08053C20 @ =FUN_0805364c
	adds r0, r6, #0
	bl FUN_080535a4
_08053C02:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08053C0C: .4byte 0x030046B8
_08053C10: .4byte 0x000003FF
_08053C14: .4byte 0x0203B400
_08053C18: .4byte 0x00001E0C
_08053C1C: .4byte 0x000017DC
_08053C20: .4byte FUN_0805364c

	thumb_func_start FUN_08053c24
FUN_08053c24: @ 0x08053C24
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	bl FUN_08053b80
	adds r5, r0, #0
	cmp r5, #0
	beq _08053C9A
	ldr r2, _08053CA4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08053CA8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08053CAC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r3, r0, #0
	ldr r2, _08053CB0 @ =0x00001E10
	adds r0, r6, r2
	ldr r2, [r0]
	movs r4, #1
	str r4, [sp]
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_080535a8
	adds r0, r5, #0
	adds r0, #0x1c
	ldr r1, _08053CB4 @ =0x00000269
	bl Video_SetAuxSpritePltt
	adds r0, r5, #0
	adds r0, #0x64
	movs r2, #0xbf
	lsls r2, r2, #5
	adds r1, r6, r2
	ldr r1, [r1]
	str r4, [sp]
	movs r2, #0
	movs r3, #1
	bl FUN_08236fac
	ldrb r0, [r5, #3]
	strb r0, [r5, #0x14]
	ldrb r0, [r5, #3]
	adds r0, #2
	movs r1, #3
	bl Mod
	strb r0, [r5, #0x15]
	ldr r1, _08053CB8 @ =FUN_080537dc
	adds r0, r5, #0
	bl FUN_080535a4
_08053C9A:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08053CA4: .4byte 0x030046B8
_08053CA8: .4byte 0x000003FF
_08053CAC: .4byte 0x0203B400
_08053CB0: .4byte 0x00001E10
_08053CB4: .4byte 0x00000269
_08053CB8: .4byte FUN_080537dc

	thumb_func_start FUN_08053cbc
FUN_08053cbc: @ 0x08053CBC
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	bl FUN_08053b80
	adds r4, r0, #0
	cmp r4, #0
	beq _08053D22
	ldr r2, _08053D2C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08053D30 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08053D34 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r3, r0, #0
	ldr r2, _08053D38 @ =0x00001E14
	adds r0, r5, r2
	ldr r2, [r0]
	movs r0, #2
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080535a8
	adds r1, r4, #0
	adds r1, #0x56
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x64
	ldr r2, _08053D3C @ =0x000017E4
	adds r1, r5, r2
	ldr r1, [r1]
	movs r2, #1
	str r2, [sp]
	movs r2, #0
	movs r3, #3
	bl FUN_08236fac
	ldr r1, _08053D40 @ =FUN_08053958
	adds r0, r4, #0
	bl FUN_080535a4
_08053D22:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08053D2C: .4byte 0x030046B8
_08053D30: .4byte 0x000003FF
_08053D34: .4byte 0x0203B400
_08053D38: .4byte 0x00001E14
_08053D3C: .4byte 0x000017E4
_08053D40: .4byte FUN_08053958

	thumb_func_start FUN_08053d44
FUN_08053d44: @ 0x08053D44
	push {r4, r5, r6, r7, lr}
	adds r3, r1, #0
	mov ip, r2
	adds r1, #0x78
	movs r4, #0
	ldrsh r2, [r1, r4]
	ldr r1, [r3, #0x14]
	subs r6, r2, r1
	adds r5, r2, r1
	ldr r7, _08053D98 @ =0x000008DC
	adds r1, r0, r7
	movs r2, #0
	movs r4, #1
_08053D5E:
	ldrh r0, [r1, #6]
	ands r0, r4
	cmp r0, #0
	beq _08053D9C
	ldrb r0, [r1, #3]
	ldrb r7, [r3, #8]
	cmp r0, r7
	bne _08053D9C
	adds r0, r1, #0
	adds r0, #0x58
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, r6
	blt _08053D9C
	cmp r0, r5
	bgt _08053D9C
	mov r0, ip
	cmp r0, #0
	bne _08053D86
	strb r4, [r1, #1]
_08053D86:
	ldr r0, [r1, #8]
	cmp r0, #1
	beq _08053D94
	cmp r0, #1
	blo _08053D94
	cmp r0, #2
	bne _08053D9C
_08053D94:
	movs r0, #1
	b _08053DA6
	.align 2, 0
_08053D98: .4byte 0x000008DC
_08053D9C:
	adds r2, #1
	adds r1, #0x78
	cmp r2, #0x1f
	ble _08053D5E
	movs r0, #0
_08053DA6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08053dac
FUN_08053dac: @ 0x08053DAC
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	beq _08053DBA
	movs r0, #0
	strb r0, [r2, #0xe]
_08053DBA:
	ldrb r0, [r2, #0xa]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2, #0xa]
	ldr r0, [r2, #0x1c]
	adds r0, #1
	str r0, [r2, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start FUN_08053dcc
FUN_08053dcc: @ 0x08053DCC
	push {r4, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08053DEC
	movs r0, #0
	strb r0, [r4, #0xe]
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r2, #0
	movs r2, #0
	movs r3, #1
	bl FUN_08053344
_08053DEC:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08053dfc
FUN_08053dfc: @ 0x08053DFC
	push {r4, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08053E1C
	movs r0, #0
	strb r0, [r4, #0xe]
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r2, #0
	movs r2, #1
	movs r3, #1
	bl FUN_08053344
_08053E1C:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08053e2c
FUN_08053e2c: @ 0x08053E2C
	push {r4, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08053E56
	movs r1, #0
	strb r1, [r4, #0xe]
	ldr r0, [r4, #0x20]
	cmp r0, #3
	beq _08053E56
	str r1, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r2, #0
	adds r1, r4, #0
	movs r2, #3
	movs r3, #1
	bl FUN_08053344
_08053E56:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08053e64
FUN_08053e64: @ 0x08053E64
	push {r4, r5, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08053E8E
	movs r1, #0
	strb r1, [r4, #0xe]
	ldr r0, [r4, #0x20]
	cmp r0, #3
	beq _08053E8E
	str r1, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r2, #0
	adds r1, r4, #0
	movs r2, #3
	movs r3, #1
	bl FUN_08053344
_08053E8E:
	ldr r0, [r4, #0x1c]
	cmp r0, #0xf
	bhi _08053ECA
	ldr r2, _08053EB0 @ =0x085B0A08
	lsls r0, r0, #3
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xa4
	muls r0, r1, r0
	cmp r0, #0
	blt _08053EB4
	asrs r0, r0, #0xc
	b _08053EBA
	.align 2, 0
_08053EB0: .4byte 0x085B0A08
_08053EB4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08053EBA:
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r0, r3
	adds r0, r4, #0
	adds r0, #0x76
	strh r1, [r0]
	adds r3, r0, #0
	b _08053ED8
_08053ECA:
	adds r1, r4, #0
	adds r1, #0x76
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r2, _08053EF4 @ =0x085B0A08
	adds r3, r1, #0
_08053ED8:
	ldr r0, [r4, #0x1c]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _08053EF8
	asrs r0, r0, #0xc
	b _08053EFE
	.align 2, 0
_08053EF4: .4byte 0x085B0A08
_08053EF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08053EFE:
	ldr r1, _08053F34 @ =0x00000DAC
	adds r5, r1, #0
	subs r0, r5, r0
	adds r2, r4, #0
	adds r2, #0x78
	strh r0, [r2]
	ldr r0, [r4, #0x1c]
	subs r0, #0xe
	cmp r0, #5
	bhi _08053F1A
	ldrb r1, [r4, #0xa]
	movs r0, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
_08053F1A:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x1f
	bls _08053F38
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r3]
	strh r5, [r2]
	movs r0, #3
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	movs r0, #0
	b _08053F3A
	.align 2, 0
_08053F34: .4byte 0x00000DAC
_08053F38:
	adds r0, #1
_08053F3A:
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08053f44
FUN_08053f44: @ 0x08053F44
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08053F72
	movs r1, #0
	strb r1, [r4, #0xe]
	ldr r0, [r4, #0x20]
	cmp r0, #3
	beq _08053F6E
	str r1, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r2, #0
	adds r1, r4, #0
	movs r2, #3
	movs r3, #1
	bl FUN_08053344
_08053F6E:
	ldrb r0, [r4, #9]
	strb r0, [r4, #8]
_08053F72:
	adds r5, r4, #0
	adds r5, #0x74
	movs r0, #0
	ldrsh r2, [r5, r0]
	ldr r1, _08053FA4 @ =0x085AB740
	ldrb r0, [r4, #8]
	lsls r0, r0, #1
	adds r3, r0, r1
	movs r1, #0
	ldrsh r0, [r3, r1]
	subs r2, r2, r0
	cmp r2, #0
	bge _08053F8E
	rsbs r2, r2, #0
_08053F8E:
	cmp r2, #0xc
	bgt _08053FA8
	ldrh r0, [r3]
	movs r1, #0
	strh r0, [r5]
	movs r0, #3
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	str r1, [r4, #0x1c]
	b _08053FC8
	.align 2, 0
_08053FA4: .4byte 0x085AB740
_08053FA8:
	ldrh r2, [r5]
	movs r6, #0
	ldrsh r1, [r5, r6]
	movs r6, #0
	ldrsh r0, [r3, r6]
	cmp r1, r0
	bge _08053FBC
	adds r0, r2, #0
	adds r0, #0xc
	b _08053FC0
_08053FBC:
	adds r0, r2, #0
	subs r0, #0xc
_08053FC0:
	strh r0, [r5]
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
_08053FC8:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08053fd0
FUN_08053fd0: @ 0x08053FD0
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08054002
	movs r1, #0
	strb r1, [r4, #0xe]
	adds r2, r5, #0
	adds r2, #0x32
	movs r0, #1
	strb r0, [r2]
	str r1, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #4
	movs r3, #2
	bl FUN_08053344
	ldr r0, _08054030 @ =0x00000322
	bl PlaySound_082406e0
_08054002:
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_08055d20
	cmp r0, #0
	beq _08054046
	ldr r1, [r5, #0x24]
	ldr r0, _08054034 @ =0x000003E7
	cmp r1, r0
	ble _08054038
	movs r0, #7
	movs r1, #0
	strb r0, [r4, #0xd]
	movs r2, #1
	strb r2, [r4, #0xe]
	str r1, [r4, #0x1c]
	adds r0, r5, #0
	adds r0, #0x30
	strb r1, [r0]
	adds r0, #0x16
	strh r2, [r0]
	b _0805404C
	.align 2, 0
_08054030: .4byte 0x00000322
_08054034: .4byte 0x000003E7
_08054038:
	movs r0, #3
	movs r1, #0
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	str r1, [r4, #0x1c]
	b _0805404C
_08054046:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
_0805404C:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08054054
FUN_08054054: @ 0x08054054
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080540A2
	movs r4, #0
	strb r4, [r5, #0xe]
	str r4, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r2, #0xf
	movs r3, #2
	bl FUN_08053344
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #0xa
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r0, #0x14
	str r0, [sp, #0x14]
	movs r0, #0x10
	str r0, [sp, #0x18]
	movs r0, #7
	movs r1, #0x1a
	movs r3, #0
	bl FUN_080149dc
_080540A2:
	ldr r0, [r6, #0x28]
	adds r0, #0x18
	str r0, [r6, #0x28]
	str r0, [r6, #0x24]
	adds r0, r5, #0
	adds r0, #0x7c
	bl FUN_08055d20
	cmp r0, #0
	beq _080540C4
	movs r0, #3
	movs r1, #0
	strb r0, [r5, #0xd]
	movs r0, #1
	strb r0, [r5, #0xe]
	str r1, [r5, #0x1c]
	b _080540CA
_080540C4:
	ldr r0, [r5, #0x1c]
	adds r0, #1
	str r0, [r5, #0x1c]
_080540CA:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080540d4
FUN_080540d4: @ 0x080540D4
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080540F6
	movs r0, #0
	strb r0, [r4, #0xe]
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #5
	movs r3, #2
	bl FUN_08053344
_080540F6:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x1e
	bne _08054102
	ldr r0, _0805412C @ =0x00000321
	bl PlaySound_082406e0
_08054102:
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_08055d20
	cmp r0, #0
	beq _0805411E
	ldr r0, [r5, #0x1c]
	cmp r0, #0
	beq _0805411E
	movs r1, #0
	bl Script_ExecById
	movs r0, #0
	str r0, [r5, #0x1c]
_0805411E:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805412C: .4byte 0x00000321

	thumb_func_start FUN_08054130
FUN_08054130: @ 0x08054130
	push {r4, lr}
	sub sp, #8
	adds r3, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08054160
	movs r1, #0
	strb r1, [r4, #0xe]
	adds r0, r3, #0
	adds r0, #0x32
	ldrb r0, [r0]
	movs r2, #6
	cmp r0, #0
	beq _08054150
	movs r2, #7
_08054150:
	str r1, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r3, #0
	adds r1, r4, #0
	movs r3, #2
	bl FUN_08053344
_08054160:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08054170
FUN_08054170: @ 0x08054170
	push {r4, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080541B8
	movs r1, #0
	strb r1, [r4, #0xe]
	adds r0, r2, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _080541A0
	str r1, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r2, #0
	adds r1, r4, #0
	movs r2, #8
	movs r3, #2
	bl FUN_08053344
	b _080541B2
_080541A0:
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r2, #0
	adds r1, r4, #0
	movs r2, #9
	movs r3, #2
	bl FUN_08053344
_080541B2:
	ldr r0, _080541C8 @ =0x0000031F
	bl PlaySound_082406e0
_080541B8:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080541C8: .4byte 0x0000031F

	thumb_func_start FUN_080541cc
FUN_080541cc: @ 0x080541CC
	push {r4, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080541EE
	movs r0, #0
	strb r0, [r4, #0xe]
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r2, #0
	movs r2, #0xa
	movs r3, #2
	bl FUN_08053344
_080541EE:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080541fc
FUN_080541fc: @ 0x080541FC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805421E
	movs r0, #0
	strb r0, [r4, #0xe]
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #2
	bl FUN_08053344
_0805421E:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x20
	bne _08054282
	movs r5, #0
	ldr r0, [r4]
	subs r0, #2
	cmp r0, #4
	bhi _0805426E
	lsls r0, r0, #2
	ldr r1, _08054238 @ =_0805423C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08054238: .4byte _0805423C
_0805423C: @ jump table
	.4byte _08054250 @ case 0
	.4byte _08054260 @ case 1
	.4byte _08054264 @ case 2
	.4byte _08054268 @ case 3
	.4byte _0805426C @ case 4
_08054250:
	movs r5, #0xb
	ldr r0, _0805425C @ =0x000002E6
	bl PlaySound_082406e0
	b _0805426E
	.align 2, 0
_0805425C: .4byte 0x000002E6
_08054260:
	movs r5, #0xc
	b _0805426E
_08054264:
	movs r5, #0xd
	b _0805426E
_08054268:
	movs r5, #0xe
	b _0805426E
_0805426C:
	movs r5, #0
_0805426E:
	movs r0, #0
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #2
	bl FUN_08053344
_08054282:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08054290
FUN_08054290: @ 0x08054290
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #0xc]
	cmp r0, #0
	beq _080542A6
	movs r1, #0
	strb r1, [r2, #0xc]
	strb r1, [r2, #0xd]
	movs r0, #1
	strb r0, [r2, #0xe]
	str r1, [r2, #0x1c]
_080542A6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080542ac
FUN_080542ac: @ 0x080542AC
	push {r4, r5, lr}
	adds r3, r1, #0
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r5, #1
	str r5, [r0]
	ldrb r0, [r3, #0xc]
	cmp r0, #0
	beq _080542E2
	movs r2, #0
	strb r2, [r3, #0xc]
	adds r1, r3, #0
	adds r1, #0x78
	movs r0, #0xfa
	lsls r0, r0, #4
	strh r0, [r1]
	movs r0, #2
	strb r0, [r3, #0xd]
	strb r5, [r3, #0xe]
	str r2, [r3, #0x1c]
	movs r0, #0xc0
	strb r0, [r3, #0xf]
	movs r0, #1
	strb r0, [r3, #0x11]
	movs r0, #0
	strb r0, [r3, #0x10]
_080542E2:
	adds r2, r3, #0
	adds r2, #0x78
	ldrh r1, [r2]
	movs r4, #0
	ldrsh r0, [r2, r4]
	ldr r4, _0805430C @ =0x00000DAC
	cmp r0, r4
	bgt _08054310
	movs r1, #0
	strh r4, [r2]
	movs r0, #2
	strb r0, [r3, #0xb]
	strb r5, [r3, #0xc]
	str r1, [r3, #0x18]
	adds r0, r3, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08053098
	b _08054314
	.align 2, 0
_0805430C: .4byte 0x00000DAC
_08054310:
	subs r0, r1, #4
	strh r0, [r2]
_08054314:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805431c
FUN_0805431c: @ 0x0805431C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #1
	str r2, [r0]
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	beq _0805434A
	movs r1, #0
	strb r1, [r4, #0xc]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	str r1, [r4, #0x1c]
	movs r0, #0xc0
	strb r0, [r4, #0xf]
	movs r0, #1
	strb r0, [r4, #0x11]
	movs r0, #0
	strb r0, [r4, #0x10]
_0805434A:
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _080543CA
	movs r2, #0
	ldr r0, [r5, #0x50]
	cmp r0, #0x1d
	bhi _08054368
	ldr r0, [r5, #0x18]
	movs r1, #0x3f
	ands r0, r1
	cmp r0, #0
	bne _08054374
	b _08054378
_08054368:
	ldr r0, [r5, #0x18]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _08054374
	movs r2, #1
_08054374:
	cmp r2, #0
	beq _080543CA
_08054378:
	ldr r2, _080543A4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080543A8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080543AC @ =0x0203B400
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r0, [r5, #0x4c]
	cmp r0, #0x63
	bls _080543B8
	cmp r1, #0x65
	ble _080543BC
	cmp r1, #0xa9
	bgt _080543B0
	adds r0, r5, #0
	bl FUN_08053cbc
	b _080543CA
	.align 2, 0
_080543A4: .4byte 0x030046B8
_080543A8: .4byte 0x000003FF
_080543AC: .4byte 0x0203B400
_080543B0:
	adds r0, r5, #0
	bl FUN_08053c24
	b _080543CA
_080543B8:
	cmp r1, #0x7f
	bgt _080543C4
_080543BC:
	adds r0, r5, #0
	bl FUN_08053ba8
	b _080543CA
_080543C4:
	adds r0, r5, #0
	bl FUN_08053c24
_080543CA:
	ldrb r0, [r4, #0xd]
	cmp r0, #3
	bne _0805443E
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_08053d44
	adds r3, r0, #0
	cmp r3, #0
	beq _080543EE
	movs r0, #6
	movs r1, #0
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	str r1, [r4, #0x1c]
	b _0805443E
_080543EE:
	ldr r0, _08054400 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r5, #1
	movs r2, #1
	ands r2, r1
	cmp r2, #0
	beq _08054404
	movs r0, #4
	b _08054438
	.align 2, 0
_08054400: .4byte 0x030044E0
_08054404:
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _08054424
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _0805441A
	subs r0, #1
	strb r0, [r4, #9]
_0805441A:
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	str r2, [r4, #0x1c]
	b _0805443E
_08054424:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805443E
	ldrb r0, [r4, #8]
	cmp r0, #1
	bhi _08054436
	adds r0, #1
	strb r0, [r4, #9]
_08054436:
	movs r0, #5
_08054438:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	str r3, [r4, #0x1c]
_0805443E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08054444
FUN_08054444: @ 0x08054444
	push {r4, lr}
	adds r2, r1, #0
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r4, #1
	str r4, [r0]
	ldrb r0, [r2, #0xc]
	cmp r0, #0
	beq _08054468
	movs r0, #0
	strb r0, [r2, #0xc]
	movs r0, #0xc0
	strb r0, [r2, #0xf]
	movs r0, #1
	strb r0, [r2, #0x11]
	movs r0, #0
	strb r0, [r2, #0x10]
_08054468:
	ldrb r0, [r2, #0xd]
	cmp r0, #3
	bne _0805448A
	ldrb r3, [r2, #8]
	cmp r3, #1
	beq _08054480
	movs r1, #0
	strb r4, [r2, #9]
	movs r0, #5
	strb r0, [r2, #0xd]
	strb r4, [r2, #0xe]
	b _08054488
_08054480:
	movs r0, #2
	movs r1, #0
	strb r0, [r2, #0xd]
	strb r3, [r2, #0xe]
_08054488:
	str r1, [r2, #0x1c]
_0805448A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08054490
FUN_08054490: @ 0x08054490
	push {lr}
	adds r2, r1, #0
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r3, #1
	str r3, [r0]
	ldrb r0, [r2, #0xc]
	cmp r0, #0
	beq _080544B0
	movs r1, #0
	strb r1, [r2, #0xc]
	movs r0, #8
	strb r0, [r2, #0xd]
	strb r3, [r2, #0xe]
	str r1, [r2, #0x1c]
_080544B0:
	pop {r0}
	bx r0

	thumb_func_start FUN_080544b4
FUN_080544b4: @ 0x080544B4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	ldrb r0, [r3, #0xc]
	cmp r0, #0
	beq _080544DE
	movs r2, #0
	strb r2, [r3, #0xc]
	adds r1, #0x78
	ldr r0, _0805450C @ =0x000008FC
	strh r0, [r1]
	movs r0, #1
	strb r0, [r3, #0xd]
	strb r0, [r3, #0xe]
	str r2, [r3, #0x1c]
	movs r0, #0x40
	strb r0, [r3, #0xf]
	movs r0, #5
	strb r0, [r3, #0x11]
	movs r0, #2
	strb r0, [r3, #0x10]
_080544DE:
	adds r4, r3, #0
	adds r4, #0x78
	movs r0, #0
	ldrsh r2, [r4, r0]
	ldr r1, [r5, #0x24]
	ldr r0, _08054510 @ =0x00000CE4
	subs r1, r0, r1
	cmp r2, r1
	blt _08054514
	movs r0, #0
	strh r1, [r4]
	movs r1, #6
	strb r1, [r3, #0xb]
	movs r1, #1
	strb r1, [r3, #0xc]
	str r0, [r3, #0x18]
	adds r0, r3, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08053098
	b _0805451A
	.align 2, 0
_0805450C: .4byte 0x000008FC
_08054510: .4byte 0x00000CE4
_08054514:
	ldrh r0, [r4]
	adds r0, #6
	strh r0, [r4]
_0805451A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08054520
FUN_08054520: @ 0x08054520
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	beq _0805454C
	movs r1, #0
	strb r1, [r4, #0xc]
	movs r0, #3
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	str r1, [r4, #0x1c]
	movs r0, #0xc0
	strb r0, [r4, #0xf]
	movs r1, #1
	strb r1, [r4, #0x11]
	movs r0, #0
	strb r0, [r4, #0x10]
	adds r0, r5, #0
	adds r0, #0x30
	strb r1, [r0]
_0805454C:
	ldrb r0, [r4, #0xd]
	adds r6, r4, #0
	adds r6, #0x78
	cmp r0, #3
	bne _080545AE
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #2
	ldrb r0, [r0, #0xa]
	ands r0, r1
	cmp r0, #0
	beq _080545AE
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	ldrb r1, [r4, #8]
	cmp r0, r1
	bne _080545AE
	adds r2, #0x70
	adds r0, r5, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0
	ldrsh r0, [r6, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _08054588
	rsbs r1, r1, #0
_08054588:
	cmp r1, #0x7f
	bgt _080545AE
	ldr r1, _080545C0 @ =0x00001E18
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0x40
	movs r3, #1
	bl FUN_08053528
	movs r0, #6
	movs r1, #0
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	str r1, [r4, #0x1c]
	ldr r0, _080545C4 @ =0x0000028B
	bl PlaySound_082406e0
_080545AE:
	ldr r3, [r5, #0x28]
	ldr r1, [r5, #0x24]
	subs r2, r3, r1
	cmp r2, #3
	ble _080545C8
	adds r0, r1, #4
	str r0, [r5, #0x24]
	b _080545D8
	.align 2, 0
_080545C0: .4byte 0x00001E18
_080545C4: .4byte 0x0000028B
_080545C8:
	movs r0, #4
	rsbs r0, r0, #0
	cmp r2, r0
	bgt _080545D6
	subs r0, r1, #4
	str r0, [r5, #0x24]
	b _080545D8
_080545D6:
	str r3, [r5, #0x24]
_080545D8:
	ldr r0, [r5, #0x24]
	ldr r2, _080545F8 @ =0x00000CE4
	adds r1, r2, #0
	subs r1, r1, r0
	strh r1, [r6]
	ldr r1, _080545FC @ =0x000003E7
	cmp r0, r1
	ble _08054600
	movs r0, #7
	strb r0, [r4, #0xb]
	movs r0, #1
	strb r0, [r4, #0xc]
	movs r0, #0
	str r0, [r4, #0x18]
	b _08054668
	.align 2, 0
_080545F8: .4byte 0x00000CE4
_080545FC: .4byte 0x000003E7
_08054600:
	ldrb r0, [r4, #0xd]
	cmp r0, #3
	bne _08054668
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_08053d44
	cmp r0, #0
	beq _08054668
	ldrb r0, [r4, #8]
	cmp r0, #1
	beq _0805462A
	cmp r0, #1
	bgt _08054624
	cmp r0, #0
	beq _08054658
	b _0805465C
_08054624:
	cmp r0, #2
	beq _08054658
	b _0805465C
_0805462A:
	ldr r2, _08054648 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805464C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08054650 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _08054654
	movs r0, #0
	b _0805465A
	.align 2, 0
_08054648: .4byte 0x030046B8
_0805464C: .4byte 0x000003FF
_08054650: .4byte 0x0203B400
_08054654:
	movs r0, #2
	b _0805465A
_08054658:
	movs r0, #1
_0805465A:
	strb r0, [r4, #9]
_0805465C:
	movs r0, #5
	movs r1, #0
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	str r1, [r4, #0x1c]
_08054668:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08054670
FUN_08054670: @ 0x08054670
	push {lr}
	ldrb r0, [r1, #0xc]
	cmp r0, #0
	beq _0805467C
	movs r0, #0
	strb r0, [r1, #0xc]
_0805467C:
	adds r1, #0x78
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bgt _0805468C
	movs r0, #0
	b _08054690
_0805468C:
	adds r0, r2, #0
	subs r0, #0xc
_08054690:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08054698
FUN_08054698: @ 0x08054698
	push {r4, lr}
	adds r3, r1, #0
	ldrb r0, [r3, #0xc]
	cmp r0, #0
	beq _080546C0
	movs r2, #0
	strb r2, [r3, #0xc]
	adds r1, #0x78
	ldr r0, _080546EC @ =0x000008FC
	strh r0, [r1]
	movs r0, #1
	strb r0, [r3, #0xd]
	strb r0, [r3, #0xe]
	str r2, [r3, #0x1c]
	movs r0, #0x40
	strb r0, [r3, #0xf]
	movs r0, #5
	strb r0, [r3, #0x11]
	movs r0, #2
	strb r0, [r3, #0x10]
_080546C0:
	adds r2, r3, #0
	adds r2, #0x78
	ldrh r4, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _080546F0 @ =0x00000A8B
	cmp r1, r0
	ble _080546F4
	movs r1, #0
	adds r0, #1
	strh r0, [r2]
	movs r0, #9
	strb r0, [r3, #0xb]
	movs r0, #1
	strb r0, [r3, #0xc]
	str r1, [r3, #0x18]
	adds r0, r3, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08053098
	b _080546F8
	.align 2, 0
_080546EC: .4byte 0x000008FC
_080546F0: .4byte 0x00000A8B
_080546F4:
	adds r0, r4, #4
	strh r0, [r2]
_080546F8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08054700
FUN_08054700: @ 0x08054700
	push {r4, lr}
	adds r2, r1, #0
	ldrb r0, [r2, #0xc]
	cmp r0, #0
	beq _08054718
	movs r0, #0
	strb r0, [r2, #0xc]
	movs r1, #3
	strb r1, [r2, #0xd]
	movs r1, #1
	strb r1, [r2, #0xe]
	str r0, [r2, #0x1c]
_08054718:
	adds r3, r2, #0
	adds r3, #0x78
	ldrh r4, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _0805473C @ =0x00000D47
	cmp r1, r0
	ble _08054740
	movs r1, #0
	adds r0, #1
	strh r0, [r3]
	movs r0, #0xa
	strb r0, [r2, #0xb]
	movs r0, #1
	strb r0, [r2, #0xc]
	str r1, [r2, #0x18]
	b _08054746
	.align 2, 0
_0805473C: .4byte 0x00000D47
_08054740:
	adds r0, r4, #0
	adds r0, #8
	strh r0, [r3]
_08054746:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805474c
FUN_0805474c: @ 0x0805474C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r1, #0xc]
	cmp r0, #0
	beq _0805479C
	movs r2, #0
	strb r2, [r1, #0xc]
	movs r0, #8
	strb r0, [r1, #0xd]
	movs r5, #1
	strb r5, [r1, #0xe]
	str r2, [r1, #0x1c]
	movs r0, #0x40
	strb r0, [r1, #0xf]
	movs r0, #5
	strb r0, [r1, #0x11]
	movs r3, #1
	movs r0, #2
	strb r0, [r1, #0x10]
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #4
	strb r1, [r0, #0xb]
	strb r3, [r0, #0xc]
	str r2, [r0, #0x18]
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	bne _0805479C
	ldr r1, _080547A4 @ =0x00001E1C
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	movs r2, #0x40
	movs r3, #1
	bl FUN_08053528
	str r5, [r4, #0x48]
_0805479C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080547A4: .4byte 0x00001E1C

	thumb_func_start FUN_080547a8
FUN_080547a8: @ 0x080547A8
	push {lr}
	mov ip, r1
	ldrb r0, [r1, #0xc]
	cmp r0, #0
	beq _080547E6
	movs r2, #0
	strb r2, [r1, #0xc]
	ldr r0, _080547EC @ =0x085AB740
	ldrh r0, [r0, #2]
	subs r0, #0xe0
	adds r1, #0x74
	movs r3, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	ldr r0, _080547F0 @ =0x00000DCC
	strh r0, [r1]
	movs r0, #9
	mov r1, ip
	strb r0, [r1, #0xd]
	movs r0, #1
	strb r0, [r1, #0xe]
	str r2, [r1, #0x1c]
	strb r3, [r1, #0xf]
	movs r0, #3
	strb r0, [r1, #0x11]
	movs r0, #1
	strb r0, [r1, #0x10]
_080547E6:
	pop {r0}
	bx r0
	.align 2, 0
_080547EC: .4byte 0x085AB740
_080547F0: .4byte 0x00000DCC

	thumb_func_start FUN_080547f4
FUN_080547f4: @ 0x080547F4
	push {lr}
	adds r3, r1, #0
	ldrb r0, [r3, #0xc]
	cmp r0, #0
	beq _0805483C
	movs r2, #0
	strb r2, [r3, #0xc]
	ldr r0, _08054840 @ =0x085AB740
	ldrh r0, [r0, #2]
	adds r0, #0x20
	adds r1, #0x74
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08054844 @ =0x00000DCC
	strh r0, [r1]
	movs r0, #9
	strb r0, [r3, #0xd]
	movs r0, #1
	strb r0, [r3, #0xe]
	str r2, [r3, #0x1c]
	movs r0, #0xc0
	strb r0, [r3, #0xf]
	movs r0, #1
	strb r0, [r3, #0x11]
	movs r0, #0
	strb r0, [r3, #0x10]
	adds r0, r3, #0
	movs r1, #4
	movs r2, #0xb4
	movs r3, #0xb4
	bl FUN_08053098
_0805483C:
	pop {r0}
	bx r0
	.align 2, 0
_08054840: .4byte 0x085AB740
_08054844: .4byte 0x00000DCC

	thumb_func_start FUN_08054848
FUN_08054848: @ 0x08054848
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x1c
	mov sl, r0
	adds r4, r1, #0
	adds r1, r3, #0
	str r2, [r4]
	ldr r0, _0805491C @ =0x085AB748
	lsls r5, r2, #3
	subs r5, r5, r2
	lsls r5, r5, #3
	adds r5, r5, r0
	ldr r0, [r5]
	str r0, [r4, #4]
	movs r0, #0
	movs r2, #1
	mov r8, r2
	mov r2, r8
	strb r2, [r4, #8]
	strb r0, [r4, #0xa]
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	str r0, [r4, #0x1c]
	ldr r0, _08054920 @ =0x085AB740
	ldr r6, _08054924 @ =0xFFFF0000
	ldrh r0, [r0, #2]
	movs r2, #0x80
	lsls r2, r2, #0x11
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r6
	ldr r2, _08054928 @ =0x00001770
	orrs r0, r2
	str r0, [sp, #0x10]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	str r2, [r4, #0x74]
	str r3, [r4, #0x78]
	movs r0, #0x30
	adds r0, r0, r4
	mov sb, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrb r3, [r4, #0xf]
	movs r0, #7
	str r0, [sp]
	str r4, [sp, #4]
	mov r0, sb
	add r2, sp, #0xc
	bl FUN_0823b400
	ldr r0, [sp, #0x14]
	ands r0, r6
	str r0, [sp, #0x14]
	ldr r1, _0805492C @ =0x085AB912
	ldr r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r6
	str r0, [r1, #4]
	mov r0, sb
	bl FUN_0823b47c
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r4, r1
	str r5, [r0]
	ldr r0, [r4, #4]
	ldr r1, [r5, #4]
	bl FUN_08040d94
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	str r0, [r1]
	ldr r2, [r5, #8]
	ldr r3, [r4, #4]
	ldr r0, [r5, #0xc]
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	add r1, sp, #0xc
	str r1, [sp, #8]
	mov r0, sl
	adds r1, r4, #0
	bl FUN_080533ec
	movs r0, #0x40
	str r0, [r4, #0x14]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805491C: .4byte 0x085AB748
_08054920: .4byte 0x085AB740
_08054924: .4byte 0xFFFF0000
_08054928: .4byte 0x00001770
_0805492C: .4byte 0x085AB912

	thumb_func_start FUN_08054930
FUN_08054930: @ 0x08054930
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_0822a4e0
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r4, r1
	bl ParticleShadow_Remove
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_08055d7c
	adds r0, r4, #0
	adds r0, #0x30
	bl FUN_0823b284
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08054960
FUN_08054960: @ 0x08054960
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r6, #0
	adds r7, #0x7c
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	movs r2, #0x84
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r2, [r0]
	ldr r0, [r6, #0x74]
	ldr r1, [r6, #0x78]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl FUN_08055c04
	ldr r1, _080549DC @ =0x085AB95C
	ldrb r0, [r6, #0xb]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	bl _call_via_r2
	movs r0, #0
	strb r0, [r6, #0xa]
	ldrb r0, [r6, #0xd]
	lsls r0, r0, #2
	adds r4, #0x10
	adds r4, r4, r0
	ldr r2, [r4]
	adds r0, r5, #0
	adds r1, r6, #0
	bl _call_via_r2
	movs r4, #1
	ldrb r0, [r6, #0xa]
	ands r0, r4
	cmp r0, #0
	beq _080549E0
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08055ef8
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	orrs r1, r4
	str r1, [r0]
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r0, r6, r2
	bl ParticleShadow_Hide
	b _08054AB4
	.align 2, 0
_080549DC: .4byte 0x085AB95C
_080549E0:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08055f1c
	movs r0, #0x88
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r6, r1
	bl ParticleShadow_Show
	movs r0, #0x96
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r1, #0x84
	lsls r1, r1, #1
	adds r3, r6, r1
	ldr r0, [r3]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	subs r0, #0x10
	strh r0, [r2]
	movs r2, #0x98
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	subs r0, #0x10
	strh r0, [r1]
	ldr r5, [r3]
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08054A50
	cmp r1, #0
	blt _08054A50
	ldr r0, _08054A54 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08054A50
	ldr r0, _08054A58 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08054A5C
_08054A50:
	movs r4, #0
	b _08054A6A
	.align 2, 0
_08054A54: .4byte 0x030046A8
_08054A58: .4byte 0x030046AC
_08054A5C:
	ldr r0, _08054A7C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08054A6A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08054A80
	adds r0, #4
	b _08054A8C
	.align 2, 0
_08054A7C: .4byte 0x030046A4
_08054A80:
	ldr r0, _08054AA0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08054A8C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08054AA4
	cmp r2, #2
	beq _08054AA8
	b _08054AAC
	.align 2, 0
_08054AA0: .4byte 0x030046A4
_08054AA4:
	ldrb r0, [r5, #4]
	b _08054AAA
_08054AA8:
	ldrb r0, [r5]
_08054AAA:
	subs r1, r1, r0
_08054AAC:
	movs r2, #0x97
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
_08054AB4:
	adds r0, r6, #0
	adds r0, #0x30
	bl FUN_0823b4b8
	ldr r0, [r6, #0x74]
	ldr r1, [r6, #0x78]
	str r0, [r6, #0x38]
	str r1, [r6, #0x3c]
	ldrh r1, [r6, #0x2c]
	movs r2, #0x2c
	ldrsh r0, [r6, r2]
	cmp r0, #0
	ble _08054ADE
	subs r0, r1, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bgt _08054ADE
	movs r0, #3
	strh r0, [r6, #0x2c]
_08054ADE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08054ae4
FUN_08054ae4: @ 0x08054AE4
	push {r4, lr}
	movs r2, #0xa4
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r3, #0
	strb r3, [r1, #0xb]
	movs r4, #1
	strb r4, [r1, #0xc]
	str r3, [r1, #0x18]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r0, r2
	strb r3, [r1, #0xb]
	strb r4, [r1, #0xc]
	str r3, [r1, #0x18]
	ldr r2, _08054B3C @ =0x000005D4
	adds r1, r0, r2
	strb r3, [r1, #0xb]
	strb r4, [r1, #0xc]
	str r3, [r1, #0x18]
	movs r2, #0x8a
	lsls r2, r2, #3
	adds r1, r0, r2
	movs r2, #0xb
	strb r2, [r1, #0xb]
	strb r4, [r1, #0xc]
	str r3, [r1, #0x18]
	movs r2, #0xeb
	lsls r2, r2, #3
	adds r1, r0, r2
	movs r2, #0xc
	strb r2, [r1, #0xb]
	strb r4, [r1, #0xc]
	str r3, [r1, #0x18]
	str r4, [r0, #0x58]
	ldr r0, _08054B40 @ =0x0300445C
	str r3, [r0]
	ldr r1, _08054B44 @ =0x03004464
	ldr r2, _08054B48 @ =0x00001084
	adds r0, r2, #0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054B3C: .4byte 0x000005D4
_08054B40: .4byte 0x0300445C
_08054B44: .4byte 0x03004464
_08054B48: .4byte 0x00001084

	thumb_func_start FUN_08054b4c
FUN_08054b4c: @ 0x08054B4C
	push {r4, lr}
	adds r1, r0, #0
	movs r4, #1
	ldr r3, _08054B6C @ =0x000019D0
	adds r2, r1, r3
	movs r3, #3
_08054B58:
	ldr r1, [r2]
	orrs r1, r4
	str r1, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _08054B58
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08054B6C: .4byte 0x000019D0

	thumb_func_start FUN_08054b70
FUN_08054b70: @ 0x08054B70
	push {r4, lr}
	sub sp, #0x14
	adds r2, r0, #0
	ldr r4, [r2, #0x3c]
	ldr r1, [r2, #0x40]
	subs r3, r4, r1
	cmp r3, #4
	ble _08054B86
	adds r0, r1, #4
	str r0, [r2, #0x40]
	b _08054B96
_08054B86:
	movs r0, #4
	rsbs r0, r0, #0
	cmp r3, r0
	bge _08054B94
	subs r0, r1, #4
	str r0, [r2, #0x40]
	b _08054B96
_08054B94:
	str r4, [r2, #0x40]
_08054B96:
	ldr r1, _08054BC4 @ =0x00001848
	adds r0, r2, r1
	ldr r3, _08054BC8 @ =0x00001828
	adds r1, r2, r3
	ldr r2, [r2, #0x40]
	movs r3, #0x1e
	str r3, [sp]
	movs r3, #0x20
	str r3, [sp, #4]
	movs r3, #0x98
	str r3, [sp, #8]
	movs r3, #8
	str r3, [sp, #0xc]
	movs r3, #0
	str r3, [sp, #0x10]
	movs r3, #4
	bl FUN_082376a4
	add sp, #0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054BC4: .4byte 0x00001848
_08054BC8: .4byte 0x00001828

	thumb_func_start FUN_08054bcc
FUN_08054bcc: @ 0x08054BCC
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x33
	ldrb r0, [r5]
	cmp r0, #0
	beq _08054C62
	ldr r0, [r4, #0x34]
	adds r2, r0, #1
	str r2, [r4, #0x34]
	cmp r2, #0x3b
	ble _08054BF4
	adds r0, r4, #0
	bl FUN_08054b4c
	movs r0, #0
	str r0, [r4, #0x34]
	strb r0, [r5]
	b _08054C5C
_08054BF4:
	cmp r2, #9
	ble _08054C22
	cmp r2, #0x31
	ble _08054C0A
	movs r0, #3
	ands r2, r0
	movs r0, #1
	cmp r2, #1
	bgt _08054C1C
	movs r0, #0
	b _08054C1C
_08054C0A:
	cmp r2, #0x1d
	ble _08054C1A
	movs r1, #3
	ands r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	b _08054C1C
_08054C1A:
	movs r0, #1
_08054C1C:
	movs r5, #0
	movs r6, #0x88
	b _08054C2C
_08054C22:
	movs r0, #0xa
	subs r0, r0, r2
	lsls r5, r0, #3
	movs r6, #0x88
	movs r0, #1
_08054C2C:
	cmp r0, #0
	beq _08054C5C
	ldr r1, _08054C54 @ =0x000019C8
	adds r0, r4, r1
	ldr r2, _08054C58 @ =0x00001828
	adds r1, r4, r2
	ldr r2, [r4, #0x38]
	movs r3, #0x1e
	str r3, [sp]
	str r5, [sp, #4]
	subs r3, r6, #2
	str r3, [sp, #8]
	movs r3, #8
	str r3, [sp, #0xc]
	movs r3, #0
	str r3, [sp, #0x10]
	movs r3, #4
	bl FUN_082376a4
	b _08054C62
	.align 2, 0
_08054C54: .4byte 0x000019C8
_08054C58: .4byte 0x00001828
_08054C5C:
	adds r0, r4, #0
	bl FUN_08054b4c
_08054C62:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08054c6c
FUN_08054c6c: @ 0x08054C6C
	push {lr}
	sub sp, #0x14
	ldr r1, _08054C9C @ =0x00001B48
	adds r3, r0, r1
	ldr r2, _08054CA0 @ =0x00001828
	adds r1, r0, r2
	ldr r2, [r0, #0x50]
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x20
	str r0, [sp, #4]
	movs r0, #0x90
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	adds r0, r3, #0
	movs r3, #3
	bl FUN_082376a4
	add sp, #0x14
	pop {r0}
	bx r0
	.align 2, 0
_08054C9C: .4byte 0x00001B48
_08054CA0: .4byte 0x00001828

	thumb_func_start FUN_08054ca4
FUN_08054ca4: @ 0x08054CA4
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x5c]
	cmp r0, #0
	beq _08054D1C
	movs r4, #1
	ldr r0, _08054D24 @ =0x00001850
	adds r1, r3, r0
	movs r2, #3
_08054CB6:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _08054CB6
	movs r4, #1
	ldr r0, _08054D28 @ =0x000019D0
	adds r1, r3, r0
	movs r2, #3
_08054CCC:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _08054CCC
	movs r4, #1
	ldr r0, _08054D2C @ =0x00001B50
	adds r1, r3, r0
	movs r2, #2
_08054CE2:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _08054CE2
	movs r4, #1
	ldr r0, _08054D30 @ =0x00001C84
	adds r1, r3, r0
	movs r2, #5
_08054CF8:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _08054CF8
	movs r4, #1
	ldr r0, _08054D34 @ =0x00001DA8
	adds r1, r3, r0
	movs r2, #1
_08054D0E:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _08054D0E
_08054D1C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054D24: .4byte 0x00001850
_08054D28: .4byte 0x000019D0
_08054D2C: .4byte 0x00001B50
_08054D30: .4byte 0x00001C84
_08054D34: .4byte 0x00001DA8

	thumb_func_start Entity5645_Update
Entity5645_Update: @ 0x08054D38
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08054D8C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08054D90 @ =0x00000942
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [r6, #0x2c]
	adds r0, r6, #0
	bl FUN_08053b18
	movs r0, #0xa4
	lsls r0, r0, #1
	adds r5, r6, r0
	movs r4, #4
_08054D58:
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08054960
	subs r4, #1
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r5, r5, r1
	cmp r4, #0
	bge _08054D58
	adds r0, r6, #0
	adds r0, #0x60
	bl FUN_0823b8ac
	ldr r0, [r6, #0x50]
	cmp r0, #0x63
	bls _08054D94
	adds r0, r6, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r4, r0, #0
	cmp r1, #2
	beq _08054DBE
	movs r0, #2
	b _08054DA6
	.align 2, 0
_08054D8C: .4byte 0x030046A0
_08054D90: .4byte 0x00000942
_08054D94:
	cmp r0, #0x1d
	bls _08054DB4
	adds r0, r6, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r4, r0, #0
	cmp r1, #1
	beq _08054DBE
	movs r0, #1
_08054DA6:
	strh r0, [r4]
	ldr r0, _08054DB0 @ =0x0000028B
	bl PlaySound_082406e0
	b _08054DBE
	.align 2, 0
_08054DB0: .4byte 0x0000028B
_08054DB4:
	adds r1, r6, #0
	adds r1, #0x44
	movs r0, #0
	strh r0, [r1]
	adds r4, r1, #0
_08054DBE:
	ldrh r0, [r4]
	cmp r0, #0
	beq _08054E08
	cmp r0, #1
	bne _08054DD4
	ldr r0, _08054DD0 @ =0x00001CB0
	adds r1, r6, r0
	movs r0, #4
	b _08054DDE
	.align 2, 0
_08054DD0: .4byte 0x00001CB0
_08054DD4:
	cmp r0, #2
	bne _08054DE0
	ldr r0, _08054E00 @ =0x00001CB0
	adds r1, r6, r0
	movs r0, #5
_08054DDE:
	strh r0, [r1, #0x10]
_08054DE0:
	adds r5, r6, #0
	adds r5, #0x31
	movs r2, #2
	rsbs r2, r2, #0
	ldr r0, _08054E04 @ =0x00001C84
	adds r1, r6, r0
	movs r4, #5
_08054DEE:
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r1, #0x2c
	subs r4, #1
	cmp r4, #0
	bge _08054DEE
	b _08054E22
	.align 2, 0
_08054E00: .4byte 0x00001CB0
_08054E04: .4byte 0x00001C84
_08054E08:
	adds r5, r6, #0
	adds r5, #0x31
	movs r2, #1
	ldr r0, _08054E50 @ =0x00001C84
	adds r1, r6, r0
	movs r4, #5
_08054E14:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x2c
	subs r4, #1
	cmp r4, #0
	bge _08054E14
_08054E22:
	adds r0, r6, #0
	bl FUN_08054b70
	adds r0, r6, #0
	bl FUN_08054bcc
	adds r0, r6, #0
	bl FUN_08054c6c
	ldr r0, [r6, #0x58]
	cmp r0, #1
	bne _08054E58
	ldr r1, _08054E54 @ =0x0300445C
	ldr r0, [r1]
	adds r0, #4
	str r0, [r1]
	cmp r0, #0x3f
	ble _08054E6E
	movs r0, #0x40
	str r0, [r1]
	movs r0, #0
	b _08054E6C
	.align 2, 0
_08054E50: .4byte 0x00001C84
_08054E54: .4byte 0x0300445C
_08054E58:
	cmp r0, #2
	bne _08054E6E
	ldr r1, _08054EB0 @ =0x0300445C
	ldr r0, [r1]
	subs r0, #4
	str r0, [r1]
	cmp r0, #0
	bgt _08054E6E
	movs r0, #0
	str r0, [r1]
_08054E6C:
	str r0, [r6, #0x58]
_08054E6E:
	ldrb r0, [r5]
	cmp r0, #0
	beq _08054E84
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08054E84
	adds r0, r6, #0
	bl FUN_08054ae4
_08054E84:
	adds r0, r6, #0
	bl FUN_08054ca4
	ldr r2, _08054EB4 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0xec
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r6, #0x3c]
	strh r1, [r0]
	ldr r0, [r2]
	ldr r1, _08054EB8 @ =0x000003B2
	adds r0, r0, r1
	ldr r1, [r6, #0x54]
	strh r1, [r0]
	ldr r0, [r6, #0x18]
	adds r0, #1
	str r0, [r6, #0x18]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08054EB0: .4byte 0x0300445C
_08054EB4: .4byte 0x030046A0
_08054EB8: .4byte 0x000003B2

	thumb_func_start Entity5645_Destroy
Entity5645_Destroy: @ 0x08054EBC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0xa4
	lsls r0, r0, #1
	adds r5, r6, r0
	movs r4, #4
_08054EC8:
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08054930
	subs r4, #1
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #0
	bge _08054EC8
	ldr r0, _08054F74 @ =0x00001848
	adds r5, r6, r0
	movs r4, #3
_08054EE2:
	adds r0, r5, #0
	bl FUN_0822f1c0
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _08054EE2
	ldr r0, _08054F78 @ =0x000019C8
	adds r5, r6, r0
	movs r4, #3
_08054EF6:
	adds r0, r5, #0
	bl FUN_0822f1c0
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _08054EF6
	ldr r0, _08054F7C @ =0x00001B48
	adds r5, r6, r0
	movs r4, #2
_08054F0A:
	adds r0, r5, #0
	bl FUN_0822f1c0
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _08054F0A
	ldr r0, _08054F80 @ =0x00001C84
	adds r5, r6, r0
	movs r4, #5
_08054F1E:
	adds r0, r5, #0
	bl FUN_0822a4e0
	adds r5, #0x2c
	subs r4, #1
	cmp r4, #0
	bge _08054F1E
	ldr r0, _08054F84 @ =0x00001DA8
	adds r5, r6, r0
	movs r4, #1
_08054F32:
	adds r0, r5, #0
	bl FUN_0822a4e0
	adds r5, #0x2c
	subs r4, #1
	cmp r4, #0
	bge _08054F32
	movs r4, #0
	adds r0, r6, #0
	bl FUN_08053b54
	movs r0, #0
	movs r1, #0
	bl SetBGPrioDirect
	movs r0, #1
	movs r1, #1
	bl SetBGPrioDirect
	movs r0, #2
	movs r1, #2
	bl SetBGPrioDirect
	movs r0, #3
	movs r1, #3
	bl SetBGPrioDirect
	ldr r0, _08054F88 @ =0x03000120
	str r4, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08054F74: .4byte 0x00001848
_08054F78: .4byte 0x000019C8
_08054F7C: .4byte 0x00001B48
_08054F80: .4byte 0x00001C84
_08054F84: .4byte 0x00001DA8
_08054F88: .4byte 0x03000120

	thumb_func_start Entity5645_Init
Entity5645_Init: @ 0x08054F8C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	mov r8, r0
	ldr r0, _08054FF4 @ =0x03000120
	mov r1, r8
	str r1, [r0]
	ldr r5, _08054FF8 @ =0x030046B8
	bl GetMinute
	adds r4, r0, #0
	bl GetSecond
	ldr r1, _08054FFC @ =0x03002CF0
	lsls r2, r4, #4
	subs r2, r2, r4
	lsls r2, r2, #2
	ldr r1, [r1]
	adds r1, r1, r2
	adds r1, r1, r0
	ldr r0, _08055000 @ =0x000003FF
	ands r1, r0
	str r1, [r5]
	movs r0, #0
	movs r1, #3
	bl SetBGPrioDirect
	movs r0, #1
	movs r1, #3
	bl SetBGPrioDirect
	movs r0, #2
	movs r1, #3
	bl SetBGPrioDirect
	movs r0, #3
	movs r1, #3
	bl SetBGPrioDirect
	ldr r0, _08055004 @ =0x0000CB05
	ldr r1, _08055008 @ =0x0000B343
	bl GetFile
	mov ip, r0
	cmp r0, #0
	bne _0805500C
_08054FEE:
	movs r0, #1
	rsbs r0, r0, #0
	b _080553EA
	.align 2, 0
_08054FF4: .4byte 0x03000120
_08054FF8: .4byte 0x030046B8
_08054FFC: .4byte 0x03002CF0
_08055000: .4byte 0x000003FF
_08055004: .4byte 0x0000CB05
_08055008: .4byte 0x0000B343
_0805500C:
	ldr r2, _080550F4 @ =0x00001828
	add r2, r8
	mov sb, r2
	mov r1, ip
	ldm r1!, {r0, r3, r4}
	stm r2!, {r0, r3, r4}
	ldm r1!, {r0, r3, r4}
	stm r2!, {r0, r3, r4}
	ldm r1!, {r3, r4}
	stm r2!, {r3, r4}
	mov r0, sb
	mov r1, ip
	bl OpenMainSpriteFile
	ldr r4, _080550F8 @ =0x0000922E
	ldr r1, _080550FC @ =0x0000871C
	adds r0, r4, #0
	bl GetFile
	ldr r1, _08055100 @ =0x000017DC
	add r1, r8
	str r0, [r1]
	ldr r1, _08055104 @ =0x00005BB7
	adds r0, r4, #0
	bl GetFile
	movs r1, #0xbf
	lsls r1, r1, #5
	add r1, r8
	str r0, [r1]
	ldr r1, _08055108 @ =0x000062C7
	adds r0, r4, #0
	bl GetFile
	ldr r1, _0805510C @ =0x000017E4
	add r1, r8
	str r0, [r1]
	ldr r1, _08055110 @ =0x00006830
	adds r0, r4, #0
	bl GetFile
	ldr r1, _08055114 @ =0x000017E8
	add r1, r8
	str r0, [r1]
	movs r5, #0
	ldr r0, _08055118 @ =0x085AB748
	mov sl, r0
	movs r1, #0x68
	add r1, r8
	mov sb, r1
	mov r2, sl
	str r2, [sp, #0x34]
	movs r3, #0
	str r3, [sp, #0x2c]
_08055078:
	mov r0, sl
	adds r0, #8
	ldr r4, [sp, #0x2c]
	adds r0, r4, r0
	ldr r0, [r0]
	cmp r0, #2
	bne _080550B0
	ldr r0, [sp, #0x34]
	ldrh r1, [r0]
	ldr r0, _0805511C @ =0x0000CB05
	bl GetFile
	mov ip, r0
	cmp r0, #0
	beq _08054FEE
	lsls r1, r5, #5
	add r1, r8
	adds r1, #0x68
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	mov r0, sb
	mov r1, ip
	bl OpenMainSpriteFile
_080550B0:
	movs r4, #0x20
	add sb, r4
	ldr r0, [sp, #0x34]
	adds r0, #0x38
	str r0, [sp, #0x34]
	ldr r1, [sp, #0x2c]
	adds r1, #0x38
	str r1, [sp, #0x2c]
	adds r5, #1
	cmp r5, #6
	ble _08055078
	movs r0, #0x63
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _08055120
	bl Script_GetValue
	mov r4, r8
	adds r4, #0x60
	strh r0, [r4]
	bl Script_GetValue
	mov r1, r8
	adds r1, #0x62
	strh r0, [r1]
	bl Script_GetValue
	mov r1, r8
	adds r1, #0x64
	strh r0, [r1]
	adds r0, r4, #0
	b _08055132
	.align 2, 0
_080550F4: .4byte 0x00001828
_080550F8: .4byte 0x0000922E
_080550FC: .4byte 0x0000871C
_08055100: .4byte 0x000017DC
_08055104: .4byte 0x00005BB7
_08055108: .4byte 0x000062C7
_0805510C: .4byte 0x000017E4
_08055110: .4byte 0x00006830
_08055114: .4byte 0x000017E8
_08055118: .4byte 0x085AB748
_0805511C: .4byte 0x0000CB05
_08055120:
	mov r1, r8
	adds r1, #0x60
	strh r2, [r1]
	mov r0, r8
	adds r0, #0x62
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, r1, #0
_08055132:
	bl FUN_0823b8ac
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	mov r2, r8
	str r0, [r2, #0x1c]
	movs r0, #0x43
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08055164
	mov r3, r8
	adds r3, #0x46
	str r3, [sp, #0x28]
	add r4, sp, #0x10
	movs r5, #4
_08055156:
	bl Script_GetValue
	stm r4!, {r0}
	subs r5, #1
	cmp r5, #0
	bge _08055156
	b _0805517C
_08055164:
	str r0, [sp, #0x10]
	movs r0, #7
	str r0, [sp, #0x14]
	movs r0, #2
	str r0, [sp, #0x18]
	movs r0, #5
	str r0, [sp, #0x1c]
	movs r0, #1
	str r0, [sp, #0x20]
	mov r4, r8
	adds r4, #0x46
	str r4, [sp, #0x28]
_0805517C:
	ldr r0, _080552D0 @ =0x000017EC
	add r0, r8
	ldr r1, _080552D4 @ =0x00001C1B
	bl Video_GetAuxSprite
	ldr r1, _080552D8 @ =0x000017F2
	add r1, r8
	ldr r0, _080552DC @ =0x00007584
	strh r0, [r1]
	ldr r1, _080552E0 @ =0x000017F8
	add r1, r8
	ldr r0, _080552E4 @ =0x00001808
	add r0, r8
	str r0, [r1]
	ldr r1, _080552E8 @ =0x00005294
	movs r5, #0xf
	ldr r0, _080552EC @ =0x00001826
	add r0, r8
_080551A0:
	strh r1, [r0]
	subs r0, #2
	subs r5, #1
	cmp r5, #0
	bge _080551A0
	movs r4, #0xa4
	lsls r4, r4, #1
	add r4, r8
	ldr r0, _080552F0 @ =0x085AB908
	mov sb, r0
	add r1, sp, #0x10
	mov sl, r1
	movs r5, #4
_080551BA:
	mov r3, sl
	adds r3, #4
	mov sl, r3
	subs r3, #4
	ldm r3!, {r2}
	mov r0, sb
	ldrh r3, [r0]
	mov r0, r8
	adds r1, r4, #0
	bl FUN_08054848
	movs r1, #2
	add sb, r1
	subs r5, #1
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r4, r4, r2
	cmp r5, #0
	bge _080551BA
	movs r5, #5
	movs r0, #0xa4
	lsls r0, r0, #1
	add r0, r8
	movs r1, #1
	movs r2, #0
	strb r1, [r0, #0xb]
	strb r1, [r0, #0xc]
	str r2, [r0, #0x18]
	movs r0, #0xb3
	lsls r0, r0, #2
	add r0, r8
	strb r5, [r0, #0xb]
	strb r1, [r0, #0xc]
	str r2, [r0, #0x18]
	movs r0, #3
	mov r3, r8
	str r0, [r3, #0x20]
	movs r0, #0xc8
	str r0, [r3, #0x24]
	str r0, [r3, #0x28]
	str r2, [r3, #0x3c]
	ldr r4, _080552F4 @ =0x00001828
	add r4, r8
	str r4, [sp, #0x24]
	movs r4, #0
	ldr r0, _080552F8 @ =0x000019C8
	add r0, r8
	mov sl, r0
	ldr r1, _080552FC @ =0x00001848
	add r1, r8
	mov sb, r1
	movs r5, #3
_08055222:
	str r4, [sp]
	str r4, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sb
	ldr r1, [sp, #0x24]
	movs r2, #0x1e
	movs r3, #0x10
	bl MainSprite_Add
	str r4, [sp]
	str r4, [sp, #4]
	movs r3, #0x3c
	str r3, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sl
	ldr r1, [sp, #0x24]
	movs r2, #0x1e
	movs r3, #0x11
	bl MainSprite_Add
	movs r0, #0x60
	add sl, r0
	add sb, r0
	subs r5, #1
	cmp r5, #0
	bge _08055222
	movs r0, #0
	mov r1, r8
	str r0, [r1, #0x4c]
	str r0, [r1, #0x50]
	str r0, [r1, #0x54]
	mov sb, r0
	ldr r4, _08055300 @ =0x00001B48
	add r4, r8
	movs r5, #2
_0805526C:
	mov r2, sb
	str r2, [sp]
	str r2, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, _080552F4 @ =0x00001828
	add r1, r8
	movs r2, #0x1e
	movs r3, #0x11
	bl MainSprite_Add
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0805526C
	ldr r2, _08055304 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r6
	movs r1, #0x42
	orrs r0, r1
	ldr r1, _08055308 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x98
	lsls r1, r1, #0x10
	adds r6, r0, #0
	orrs r6, r1
	ands r7, r2
	ldr r0, _0805530C @ =0x00001C68
	add r0, r8
	ldr r1, _08055310 @ =0x0000A8E7
	bl Video_GetAuxSprite
	movs r5, #0
	movs r3, #0
	ldr r4, _08055314 @ =0x00001C84
	add r4, r8
_080552B8:
	adds r0, r4, #0
	ldr r1, _0805530C @ =0x00001C68
	add r1, r8
	movs r2, #0x11
	str r3, [sp, #0x30]
	bl FUN_0822a470
	ldr r3, [sp, #0x30]
	cmp r5, #1
	bgt _08055318
	adds r0, r5, #3
	b _0805531A
	.align 2, 0
_080552D0: .4byte 0x000017EC
_080552D4: .4byte 0x00001C1B
_080552D8: .4byte 0x000017F2
_080552DC: .4byte 0x00007584
_080552E0: .4byte 0x000017F8
_080552E4: .4byte 0x00001808
_080552E8: .4byte 0x00005294
_080552EC: .4byte 0x00001826
_080552F0: .4byte 0x085AB908
_080552F4: .4byte 0x00001828
_080552F8: .4byte 0x000019C8
_080552FC: .4byte 0x00001848
_08055300: .4byte 0x00001B48
_08055304: .4byte 0xFFFF0000
_08055308: .4byte 0x0000FFFF
_0805530C: .4byte 0x00001C68
_08055310: .4byte 0x0000A8E7
_08055314: .4byte 0x00001C84
_08055318:
	adds r0, r5, #5
_0805531A:
	strh r0, [r4, #0x10]
	movs r0, #0xe5
	lsls r0, r0, #5
	add r0, r8
	adds r0, r0, r3
	str r6, [r0]
	str r7, [r0, #4]
	movs r0, #0
	strb r0, [r4, #7]
	adds r0, r6, #0
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080553FC @ =0xFFFF0000
	adds r1, r2, #0
	ands r1, r6
	orrs r1, r0
	adds r6, r1, #0
	adds r3, #0x2c
	adds r4, #0x2c
	adds r5, #1
	cmp r5, #5
	ble _080552B8
	movs r6, #0x90
	lsls r6, r6, #0x10
	ands r7, r2
	ldr r0, _08055400 @ =0x00001D8C
	add r0, r8
	ldr r1, _08055404 @ =0x0000A5BD
	bl Video_GetAuxSprite
	movs r5, #0
	ldr r3, _08055408 @ =0x00001DA8
	movs r4, #0
	mov sb, r4
_08055360:
	movs r0, #0x2c
	adds r4, r5, #0
	muls r4, r0, r4
	adds r0, r4, r3
	add r0, r8
	ldr r1, _08055400 @ =0x00001D8C
	add r1, r8
	movs r2, #0x10
	str r3, [sp, #0x30]
	bl FUN_0822a470
	mov r1, r8
	adds r0, r4, r1
	ldr r3, [sp, #0x30]
	adds r0, r0, r3
	strh r5, [r0, #0x10]
	add r4, r8
	ldr r2, _0805540C @ =0x00001DC4
	adds r0, r4, r2
	str r6, [r0]
	str r7, [r0, #4]
	ldr r0, _08055410 @ =0x00001DAF
	adds r4, r4, r0
	mov r1, sb
	strb r1, [r4]
	adds r2, r6, #0
	asrs r1, r2, #0x10
	adds r1, #8
	lsls r1, r1, #0x10
	ldr r0, _08055414 @ =0x0000FFFF
	ands r2, r0
	adds r6, r2, #0
	orrs r6, r1
	adds r5, #1
	cmp r5, #1
	ble _08055360
	ldr r1, _08055418 @ =0x00001E0C
	add r1, r8
	movs r0, #2
	str r0, [r1]
	ldr r1, _0805541C @ =0x00001E10
	add r1, r8
	movs r0, #4
	str r0, [r1]
	ldr r1, _08055420 @ =0x00001E14
	add r1, r8
	movs r0, #6
	str r0, [r1]
	ldr r1, _08055424 @ =0x00001E18
	add r1, r8
	movs r0, #0x32
	str r0, [r1]
	ldr r1, _08055428 @ =0x00001E1C
	add r1, r8
	movs r0, #0xfa
	lsls r0, r0, #1
	str r0, [r1]
	movs r1, #0
	ldr r2, [sp, #0x28]
	strh r1, [r2]
	mov r3, r8
	str r1, [r3, #0x5c]
	ldr r0, _0805542C @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0xeb
	lsls r4, r4, #2
	adds r0, r0, r4
	strh r1, [r0]
	movs r0, #0
_080553EA:
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080553FC: .4byte 0xFFFF0000
_08055400: .4byte 0x00001D8C
_08055404: .4byte 0x0000A5BD
_08055408: .4byte 0x00001DA8
_0805540C: .4byte 0x00001DC4
_08055410: .4byte 0x00001DAF
_08055414: .4byte 0x0000FFFF
_08055418: .4byte 0x00001E0C
_0805541C: .4byte 0x00001E10
_08055420: .4byte 0x00001E14
_08055424: .4byte 0x00001E18
_08055428: .4byte 0x00001E1C
_0805542C: .4byte 0x030046A0

	thumb_func_start Entity5645_Create
Entity5645_Create: @ 0x08055430
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _08055470 @ =0x03000120
	ldr r0, [r0]
	cmp r0, #0
	bne _0805547E
	movs r1, #0xf1
	lsls r1, r1, #5
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805547C
	ldr r1, _08055474 @ =Entity5645_Update
	ldr r2, _08055478 @ =Entity5645_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity5645_Init
	cmp r0, #0
	bge _0805547C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805547E
	.align 2, 0
_08055470: .4byte 0x03000120
_08055474: .4byte Entity5645_Update
_08055478: .4byte Entity5645_Destroy
_0805547C:
	adds r0, r4, #0
_0805547E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08055484
FUN_08055484: @ 0x08055484
	push {r4, lr}
	ldr r0, _080554D0 @ =0x03000120
	ldr r4, [r0]
	cmp r4, #0
	beq _080554C8
	adds r0, r4, #0
	adds r0, #0x46
	ldrh r3, [r0]
	cmp r3, #0
	bne _080554C8
	movs r0, #0xa4
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #3
	strb r0, [r1, #0xb]
	movs r2, #1
	strb r2, [r1, #0xc]
	str r3, [r1, #0x18]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #7
	strb r1, [r0, #0xb]
	strb r2, [r0, #0xc]
	str r3, [r0, #0x18]
	ldr r1, _080554D4 @ =0x000005D4
	adds r0, r4, r1
	movs r1, #8
	strb r1, [r0, #0xb]
	strb r2, [r0, #0xc]
	str r3, [r0, #0x18]
	adds r0, r4, #0
	adds r0, #0x30
	strb r3, [r0]
_080554C8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080554D0: .4byte 0x03000120
_080554D4: .4byte 0x000005D4

	thumb_func_start FUN_080554d8
FUN_080554d8: @ 0x080554D8
	push {r4, r5, lr}
	ldr r0, _0805552C @ =0x03000120
	ldr r2, [r0]
	cmp r2, #0
	beq _0805554C
	movs r3, #1
	str r3, [r2, #0x5c]
	adds r0, r2, #0
	adds r0, #0x46
	ldrh r4, [r0]
	cmp r4, #0
	bne _0805554C
	movs r0, #2
	str r0, [r2, #0x58]
	ldr r1, _08055530 @ =0x0300445C
	movs r0, #0x40
	str r0, [r1]
	ldr r1, _08055534 @ =0x03004464
	ldr r5, _08055538 @ =0x00001084
	adds r0, r5, #0
	strh r0, [r1]
	adds r1, r2, #0
	adds r1, #0x31
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _0805553C @ =0x030046A0
	ldr r0, [r1]
	movs r5, #0xeb
	lsls r5, r5, #2
	adds r0, r0, r5
	strh r3, [r0]
	adds r0, r2, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	bne _08055544
	ldr r0, [r1]
	ldr r1, _08055540 @ =0x000003AE
	adds r0, r0, r1
	strh r3, [r0]
	b _0805554C
	.align 2, 0
_0805552C: .4byte 0x03000120
_08055530: .4byte 0x0300445C
_08055534: .4byte 0x03004464
_08055538: .4byte 0x00001084
_0805553C: .4byte 0x030046A0
_08055540: .4byte 0x000003AE
_08055544:
	ldr r0, [r1]
	ldr r5, _08055554 @ =0x000003AE
	adds r0, r0, r5
	strh r4, [r0]
_0805554C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08055554: .4byte 0x000003AE
