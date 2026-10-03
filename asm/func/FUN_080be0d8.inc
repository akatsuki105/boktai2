	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _080BE134 @ =0x00001784
	adds r5, r4, r0
	movs r0, #0x14
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #4
	movs r3, #0
	bl FUN_080b9ff8
	ldr r2, _080BE138 @ =0x00000EB8
	adds r1, r4, r2
	adds r0, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FindEmptyWeaponSlot
	ldr r2, _080BE13C @ =0x0000168C
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080bd180
	adds r0, r4, #0
	bl FUN_080bd390
	adds r0, r4, #0
	bl FUN_080bd058
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080bd6d0
	ldr r1, _080BE140 @ =FUN_080bd9e8
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080bcdf8
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BE134: .4byte 0x00001784
_080BE138: .4byte 0x00000EB8
_080BE13C: .4byte 0x0000168C
_080BE140: .4byte FUN_080bd9e8
