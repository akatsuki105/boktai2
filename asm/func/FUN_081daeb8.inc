	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081DAF30 @ =0x0000C091
	ldr r1, _081DAF34 @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	str r2, [r5, #0x18]
	movs r0, #8
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
	ldr r0, _081DAF38 @ =0x000092B3
	ldr r1, _081DAF3C @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	str r0, [r5, #0x1c]
	ldr r1, _081DAF40 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	movs r5, #3
_081DAF0A:
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
	ble _081DAF0A
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DAF30: .4byte 0x0000C091
_081DAF34: .4byte 0x0000CD91
_081DAF38: .4byte 0x000092B3
_081DAF3C: .4byte 0x000026BB
_081DAF40: .4byte 0x03004250
