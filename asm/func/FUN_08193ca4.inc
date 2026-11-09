	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08193CBC @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08193CC0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08193CC2
	.align 2, 0
_08193CBC: .4byte 0x0000046C
_08193CC0:
	movs r0, #0
_08193CC2:
	cmp r0, #0
	beq _08193CFA
	ldr r4, _08193D9C @ =FUN_0818a904
	movs r3, #0x22
	ldr r2, _08193DA0 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _08193DA4 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08193DA8 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #8
	strh r0, [r1]
_08193CFA:
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r6, #0
	ldrsh r1, [r0, r6]
	adds r3, r1, #0
	cmp r1, #0
	bge _08193D0C
	rsbs r3, r1, #0
_08193D0C:
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r2, r0, #0
	cmp r0, #0
	bge _08193D1E
	rsbs r2, r0, #0
_08193D1E:
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #4
	movs r2, #0xc
	bl FUN_0818fdd8
	movs r1, #0xd7
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x28
	bl FUN_0818f938
	ldr r6, _08193DA4 @ =0x0000046B
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08193DB4
	adds r0, r5, #0
	bl FUN_0818e6fc
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r3, #1
	ldr r2, _08193DA0 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r3, [r0]
	adds r0, r5, r6
	strb r2, [r0]
	ldr r4, _08193DA8 @ =0x00000553
	adds r0, r5, r4
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08193DAC @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _08193DB0 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	b _08193DBE
	.align 2, 0
_08193D9C: .4byte FUN_0818a904
_08193DA0: .4byte 0x0000046D
_08193DA4: .4byte 0x0000046B
_08193DA8: .4byte 0x00000553
_08193DAC: .4byte 0x0000046A
_08193DB0: .4byte 0x00000484
_08193DB4:
	ldr r0, _08193DC4 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08193DBE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08193DC4: .4byte 0x00000484
