	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	ldr r0, [r4, #0x60]
	ldr r1, [r4, #0x64]
	str r0, [r4, #0x34]
	str r1, [r4, #0x38]
	adds r1, r4, #0
	adds r1, #0xed
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080B28EC @ =0x0203B400
	mov r8, r0
	ldr r5, _080B28F0 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r6, _080B28F4 @ =0x000003FF
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	ldrh r1, [r4, #0x34]
	subs r1, #5
	adds r1, r1, r0
	strh r1, [r4, #0x34]
	ldr r0, [r5]
	adds r0, #1
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	ldrh r1, [r4, #0x38]
	subs r1, #5
	adds r1, r1, r0
	strh r1, [r4, #0x38]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B28EC: .4byte 0x0203B400
_080B28F0: .4byte 0x030046B8
_080B28F4: .4byte 0x000003FF
