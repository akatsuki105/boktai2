	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081D9FF0 @ =0x0000C091
	ldr r1, _081D9FF4 @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	str r2, [r5, #0x18]
	movs r0, #5
	str r0, [sp, #0xc]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _081D9FF8 @ =0x000092B3
	ldr r1, _081D9FFC @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	str r0, [r5, #0x1c]
	ldr r1, _081DA000 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	ldr r0, _081DA004 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DA008
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, #1
	bne _081DA008
	movs r0, #1
	b _081DA00A
	.align 2, 0
_081D9FF0: .4byte 0x0000C091
_081D9FF4: .4byte 0x0000CD91
_081D9FF8: .4byte 0x000092B3
_081D9FFC: .4byte 0x000026BB
_081DA000: .4byte 0x03004250
_081DA004: .4byte 0x03002C68
_081DA008:
	movs r0, #0
_081DA00A:
	cmp r0, #0
	bne _081DA02E
	movs r4, #0
	movs r5, #3
_081DA012:
	adds r0, r4, #0
	adds r0, #0x19
	adds r1, r4, #0
	adds r1, #0x16
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DA012
_081DA02E:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
