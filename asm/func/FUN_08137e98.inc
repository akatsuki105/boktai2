	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	movs r1, #2
	movs r3, #0xb3
	lsls r3, r3, #4
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08137EB8
	movs r0, #1
	b _08137EBA
_08137EB8:
	movs r0, #0
_08137EBA:
	movs r1, #0xb3
	lsls r1, r1, #4
	adds r5, r2, r1
	cmp r0, #0
	beq _08137F10
	movs r3, #4
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r1, #0
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r3, [r0]
	adds r2, #0x1a
	adds r0, r4, r2
	str r1, [r0]
	ldr r0, _08137F20 @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _08137F24 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _08137F28 @ =0x00000544
	adds r1, r4, r2
	movs r0, #0xb4
	strh r0, [r1]
	movs r0, #0xde
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #2
	strh r0, [r1]
	ldrh r0, [r5]
	orrs r3, r0
	strh r3, [r5]
_08137F10:
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08137F20: .4byte 0x0000046C
_08137F24: .4byte 0xFFEFFFFF
_08137F28: .4byte 0x00000544
