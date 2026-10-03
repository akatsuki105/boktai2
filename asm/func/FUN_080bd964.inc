	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xec
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	subs r1, #3
	ands r0, r1
	str r0, [r2]
	ldr r2, _080BD9D8 @ =0x00001784
	adds r4, r5, r2
	adds r0, r4, #0
	bl FUN_080b9fe8
	ldr r0, _080BD9DC @ =0x00000EB8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	movs r1, #0x14
	bl FUN_080b9d94
	adds r0, r5, #0
	bl FindEmptyWeaponSlot
	ldr r2, _080BD9E0 @ =0x0000168C
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080bd058
	adds r0, r5, #0
	bl FUN_080bd180
	adds r0, r5, #0
	bl FUN_080bd390
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bd6d0
	ldr r1, _080BD9E4 @ =FUN_080bd9e8
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080bcdf8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BD9D8: .4byte 0x00001784
_080BD9DC: .4byte 0x00000EB8
_080BD9E0: .4byte 0x0000168C
_080BD9E4: .4byte FUN_080bd9e8
