	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	ldr r1, _080CEB58 @ =0x00000A74
	adds r5, r7, r1
	movs r2, #0
	mov r8, r2
	strb r0, [r5]
	ldrb r0, [r4, #1]
	adds r1, #1
	adds r6, r7, r1
	strb r0, [r6]
	ldrb r1, [r4, #4]
	ldr r2, _080CEB5C @ =0x00000A78
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r1, [r4, #8]
	adds r2, #0x1e
	adds r0, r7, r2
	strh r1, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_080ceaa4
	ldr r2, _080CEB60 @ =0x00000A7A
	adds r1, r7, r2
	strh r0, [r1]
	ldr r1, _080CEB64 @ =0x00000A7C
	adds r0, r7, r1
	mov r2, r8
	strh r2, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_080ce5a0
	ldrb r0, [r5]
	cmp r0, #0x3d
	bne _080CEB70
	ldr r0, _080CEB68 @ =0x00000A98
	adds r1, r7, r0
	ldr r0, _080CEB6C @ =FUN_080d3b14
	str r0, [r1]
	b _080CEB80
	.align 2, 0
_080CEB58: .4byte 0x00000A74
_080CEB5C: .4byte 0x00000A78
_080CEB60: .4byte 0x00000A7A
_080CEB64: .4byte 0x00000A7C
_080CEB68: .4byte 0x00000A98
_080CEB6C: .4byte FUN_080d3b14
_080CEB70:
	ldr r1, _080CEB90 @ =0x00000A98
	adds r2, r7, r1
	ldr r1, _080CEB94 @ =0x085AD14C
	ldrb r0, [r6]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
_080CEB80:
	adds r0, r7, #0
	bl FUN_080ce868
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CEB90: .4byte 0x00000A98
_080CEB94: .4byte 0x085AD14C
