	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r4, _081E27D8 @ =0x0000C091
	ldr r1, _081E27DC @ =0x0000CD91
	adds r0, r4, #0
	bl GetFile
	str r0, [r6, #0x1c]
	ldr r1, _081E27E0 @ =0x0000A413
	adds r0, r4, #0
	bl GetFile
	str r0, [r6, #0x20]
	movs r4, #1
	str r4, [sp, #0xc]
	ldr r2, [r6, #0x1c]
	movs r5, #0
	str r5, [sp]
	str r4, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	movs r0, #3
	str r0, [sp, #0xc]
	ldr r2, [r6, #0x20]
	str r5, [sp]
	str r4, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	str r5, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _081E27E4 @ =0x000092B3
	ldr r1, _081E27E8 @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x24]
	ldr r1, _081E27EC @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E27D8: .4byte 0x0000C091
_081E27DC: .4byte 0x0000CD91
_081E27E0: .4byte 0x0000A413
_081E27E4: .4byte 0x000092B3
_081E27E8: .4byte 0x000026BB
_081E27EC: .4byte 0x03004250
