	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r1, _080BD3B8 @ =0x00001785
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BD3C0
	ldr r2, _080BD3BC @ =0x00001787
	adds r4, r6, r2
	ldrb r0, [r4]
	bl GetWeaponID
	adds r5, r0, #0
	ldrb r0, [r4]
	bl FUN_080bce64
	adds r4, r0, #0
	movs r7, #1
	b _080BD402
	.align 2, 0
_080BD3B8: .4byte 0x00001785
_080BD3BC: .4byte 0x00001787
_080BD3C0:
	cmp r0, #7
	bhi _080BD3FC
	ldr r0, _080BD3F0 @ =0x00001787
	adds r1, r6, r0
	ldr r2, _080BD3F4 @ =0x00001654
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #4
	subs r0, #0x10
	ldrb r1, [r1]
	adds r0, r0, r1
	adds r2, #8
	adds r1, r6, r2
	adds r1, r1, r0
	movs r5, #0
	ldrsb r5, [r1, r5]
	ldr r1, _080BD3F8 @ =0x08DA9E68
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r4, [r0, #0xa]
	b _080BD400
	.align 2, 0
_080BD3F0: .4byte 0x00001787
_080BD3F4: .4byte 0x00001654
_080BD3F8: .4byte 0x08DA9E68
_080BD3FC:
	movs r5, #0
	movs r4, #0
_080BD400:
	movs r7, #0
_080BD402:
	cmp r5, #0
	ble _080BD434
	cmp r4, #0
	ble _080BD434
	ldr r1, _080BD42C @ =0x00001787
	adds r0, r6, r1
	ldrb r1, [r0]
	add r0, sp, #4
	bl FUN_080b9938
	adds r0, r6, #0
	adds r0, #0x58
	ldr r2, _080BD430 @ =0x000013F8
	adds r1, r6, r2
	str r7, [sp]
	add r2, sp, #4
	adds r3, r4, #0
	bl FUN_080b9658
	b _080BD43C
	.align 2, 0
_080BD42C: .4byte 0x00001787
_080BD430: .4byte 0x000013F8
_080BD434:
	ldr r1, _080BD444 @ =0x000013F8
	adds r0, r6, r1
	bl FUN_080b9724
_080BD43C:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BD444: .4byte 0x000013F8
