	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r4, [r0]
	movs r1, #2
	ldr r2, _08178A54 @ =0x00001008
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08178A58
	movs r0, #1
	b _08178A5A
	.align 2, 0
_08178A54: .4byte 0x00001008
_08178A58:
	movs r0, #0
_08178A5A:
	cmp r0, #0
	beq _08178AA4
	movs r2, #4
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r3, r5
	movs r1, #0
	strb r1, [r0]
	adds r5, #1
	adds r0, r3, r5
	strb r1, [r0]
	adds r5, #1
	adds r0, r3, r5
	strb r2, [r0]
	ldr r2, _08178AB8 @ =0x00000484
	adds r0, r3, r2
	str r1, [r0]
	adds r5, #2
	adds r1, r3, r5
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r1, _08178ABC @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _08178AC0 @ =0x00000544
	adds r1, r3, r2
	movs r0, #0xb4
	strh r0, [r1]
	movs r5, #0xde
	lsls r5, r5, #1
	adds r1, r3, r5
	movs r0, #2
	strh r0, [r1]
_08178AA4:
	ldr r1, _08178AC4 @ =0x00001008
	adds r0, r4, r1
	movs r1, #3
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08178AB8: .4byte 0x00000484
_08178ABC: .4byte 0xFFEFFFFF
_08178AC0: .4byte 0x00000544
_08178AC4: .4byte 0x00001008
