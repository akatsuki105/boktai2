	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _081940A0 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08193FB8
	movs r0, #0
	strb r0, [r1]
_08193FB8:
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r7, #0
	movs r1, #4
	movs r2, #0xc
	bl FUN_0818fdd8
	adds r0, r7, #0
	movs r1, #3
	movs r2, #0xa
	bl FUN_08191774
	ldr r1, _081940A4 @ =0x0000046B
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081940C0
	adds r4, r7, #0
	adds r4, #8
	ldr r2, _081940A8 @ =0x00000472
	adds r0, r7, r2
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_08191a14
	ldr r0, _081940AC @ =0x000001DF
	bl PlaySound_082406e0
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r1, _081940B0 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_0818e6fc
	mov r2, sp
	ldr r1, _081940B4 @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r1, [r0, #0xc]
	ldrh r0, [r7, #8]
	subs r1, r1, r0
	movs r5, #0
	movs r6, #0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	movs r1, #2
	movs r2, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r5, [r0]
	adds r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _081940B8 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _081940BC @ =0x00000484
	adds r0, r7, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r7, r3
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r2, [r0]
	adds r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	subs r3, #2
	adds r0, r7, r3
	strb r5, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r6, [r0]
	movs r3, #0xaa
	lsls r3, r3, #2
	adds r0, r7, r3
	bl AuxShadow_Hide
	b _081940CA
	.align 2, 0
_081940A0: .4byte 0x0000046C
_081940A4: .4byte 0x0000046B
_081940A8: .4byte 0x00000472
_081940AC: .4byte 0x000001DF
_081940B0: .4byte 0xFFEFFFFF
_081940B4: .4byte 0x000004A4
_081940B8: .4byte 0x0000046A
_081940BC: .4byte 0x00000484
_081940C0:
	ldr r0, _081940D4 @ =0x00000484
	adds r1, r7, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081940CA:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081940D4: .4byte 0x00000484
