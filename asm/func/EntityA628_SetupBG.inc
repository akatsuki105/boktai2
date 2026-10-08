	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080A0E48 @ =0x0000C091
	ldr r1, _080A0E4C @ =0x00000B12
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x18]
	movs r0, #0
	str r0, [sp, #0xc]
	str r0, [sp]
	movs r5, #1
	str r5, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #2
	movs r3, #0
	bl Video_SetupBGLayout
	movs r0, #1
	movs r1, #1
	bl SetBGPrioDirect
	ldr r0, _080A0E50 @ =0x03002B80
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #1
	bne _080A0E32
	movs r1, #1
_080A0E32:
	cmp r1, #0
	beq _080A0E5C
	ldr r2, _080A0E54 @ =0x03003E78
	ldr r0, _080A0E58 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0x37
	strb r5, [r0]
	b _080A0E86
	.align 2, 0
_080A0E48: .4byte 0x0000C091
_080A0E4C: .4byte 0x00000B12
_080A0E50: .4byte 0x03002B80
_080A0E54: .4byte 0x03003E78
_080A0E58: .4byte 0xFFFFFDFF
_080A0E5C:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _080A0E74
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080A0E70 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080A0E7E
	.align 2, 0
_080A0E70: .4byte 0x03003E78
_080A0E74:
	ldr r0, _080A0E90 @ =0x03003E78
	ldr r1, _080A0E94 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080A0E7E:
	adds r1, r4, #0
	adds r1, #0x37
	movs r0, #0
	strb r0, [r1]
_080A0E86:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A0E90: .4byte 0x03003E78
_080A0E94: .4byte 0xFFFFFDFF
