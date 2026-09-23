	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x80
	ldrh r0, [r1]
	subs r0, #0xf
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08020CBC
	strh r5, [r1]
	movs r0, #0xa9
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _08020C98 @ =0x00000153
	bl PlaySound_082406e0
	adds r1, r4, #0
	adds r1, #0x82
	movs r0, #0x1e
	strh r0, [r1]
	movs r2, #1
	adds r0, r4, #0
	adds r0, #0x37
	strb r2, [r0]
	adds r0, #0x4d
	ldrb r0, [r0]
	subs r1, #0x49
	strb r0, [r1]
	adds r1, #1
	movs r0, #0
	strb r0, [r1]
	ldr r0, _08020C9C @ =FUN_08020d10
	str r0, [r4, #0x30]
	ldr r1, _08020CA0 @ =0xFFFF0000
	add r3, sp, #8
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
	str r5, [sp, #8]
	adds r0, r4, #0
	adds r0, #0x38
	ldrb r0, [r0]
	ands r2, r0
	cmp r2, #0
	beq _08020CA4
	movs r0, #0x80
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r0, #0x70
	movs r1, #2
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0
	adds r2, r3, #0
	movs r3, #5
	bl FUN_080dbd08
	b _08020CBC
	.align 2, 0
_08020C98: .4byte 0x00000153
_08020C9C: .4byte FUN_08020d10
_08020CA0: .4byte 0xFFFF0000
_08020CA4:
	movs r0, #0x80
	strh r0, [r3, #4]
	adds r0, r4, #0
	adds r0, #0x70
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #0
	add r2, sp, #8
	movs r3, #5
	bl FUN_080dbd08
_08020CBC:
	adds r0, r4, #0
	adds r0, #0x80
	adds r1, r4, #0
	adds r1, #0x7a
	ldrh r1, [r1]
	ldrh r0, [r0]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x72
	strh r1, [r0]
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
