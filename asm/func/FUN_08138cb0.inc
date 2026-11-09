	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r0, #0xe6
	lsls r0, r0, #1
	adds r5, r6, r0
	ldr r4, [r5]
	subs r0, #0x30
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r3, r6, r1
	ldr r0, _08138DBC @ =0xFFFFFEFF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r0, #4
	movs r7, #0xb3
	lsls r7, r7, #4
	adds r2, r4, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08138DC0 @ =0x00000544
	adds r1, r6, r0
	movs r0, #0xf0
	strh r0, [r1]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #0x1e
	strh r0, [r1]
	adds r7, #0x24
	adds r4, r4, r7
	movs r0, #0x10
	strh r0, [r4]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _08138DC4 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r5, [r5]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r3, _08138DC8 @ =0x00000B4B
	adds r1, r5, r3
	ldrb r1, [r1]
	bl Div
	adds r4, r0, #0
	subs r7, #0xa
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r4, r0
	bge _08138D46
	adds r0, r7, #0
	adds r5, r5, r0
_08138D38:
	adds r0, r6, #0
	bl FUN_08137858
	adds r4, #1
	ldrb r1, [r5]
	cmp r4, r1
	blt _08138D38
_08138D46:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	movs r1, #0x21
	rsbs r1, r1, #0
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r5, #0
	strh r1, [r2]
	ldr r4, _08138DCC @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r7, _08138DD0 @ =0x0000046D
	adds r0, r6, r7
	movs r2, #1
	strb r2, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r5, [r0]
	movs r1, #5
	subs r7, #0xeb
	adds r0, r6, r7
	strb r3, [r0]
	ldr r4, _08138DD4 @ =0x00000469
	adds r0, r6, r4
	strb r3, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _08138DD8 @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	ldr r3, _08138DDC @ =0x0000046C
	adds r0, r6, r3
	strb r2, [r0]
	movs r4, #0xfe
	lsls r4, r4, #1
	adds r0, r6, r4
	ldrb r0, [r0]
	strb r0, [r6, #5]
	adds r7, #0x18
	adds r0, r6, r7
	strh r2, [r0]
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08138DBC: .4byte 0xFFFFFEFF
_08138DC0: .4byte 0x00000544
_08138DC4: .4byte 0xFFEFFFFF
_08138DC8: .4byte 0x00000B4B
_08138DCC: .4byte Enemy_ClearStateBegun
_08138DD0: .4byte 0x0000046D
_08138DD4: .4byte 0x00000469
_08138DD8: .4byte 0x00000484
_08138DDC: .4byte 0x0000046C
