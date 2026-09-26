	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r1, [r4, #0x34]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_0822dafc
	ldr r0, _080A98B0 @ =0x0203B400
	mov r8, r0
	ldr r5, _080A98B4 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r6, _080A98B8 @ =0x000003FF
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x50
	bl Mod
	adds r0, #0x18
	movs r2, #0
	strh r0, [r4, #0x18]
	ldr r0, [r5]
	adds r0, #1
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #7
	ands r0, r1
	adds r0, #8
	strh r0, [r4, #0x1a]
	strh r2, [r4, #0x1c]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r2, [r4, #0x28]
	ldr r0, _080A98BC @ =FUN_080a9808
	str r0, [r4, #0x38]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A98B0: .4byte 0x0203B400
_080A98B4: .4byte 0x030046B8
_080A98B8: .4byte 0x000003FF
_080A98BC: .4byte FUN_080a9808
