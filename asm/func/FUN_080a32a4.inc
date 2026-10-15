	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x50]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r4, #0x50]
	adds r2, r4, #0
	adds r2, #0x6e
	movs r0, #0
	ldrsh r1, [r2, r0]
	adds r0, r4, #0
	adds r0, #0x9a
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, #0x16
	cmp r1, r0
	bge _080A32CE
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
_080A32CE:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A32E6
	subs r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A3336
_080A32E6:
	ldr r0, _080A3314 @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807d118
	bl FUN_080a6edc
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A331C
	ldr r1, _080A3318 @ =FUN_080a3340
	adds r0, r4, #0
	bl FUN_080a2a14
	b _080A3324
	.align 2, 0
_080A3314: .4byte 0x03002BE0
_080A3318: .4byte FUN_080a3340
_080A331C:
	ldr r1, _080A333C @ =FUN_080a2e20
	adds r0, r4, #0
	bl FUN_080a2a14
_080A3324:
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _080A3336
	movs r1, #0
	bl VM_ExecByID
_080A3336:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A333C: .4byte FUN_080a2e20
