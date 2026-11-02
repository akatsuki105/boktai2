	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r4, _081DFF04 @ =0x0000C091
	ldr r1, _081DFF08 @ =0x0000CD91
	adds r0, r4, #0
	bl GetFile
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r5, r7, r1
	str r0, [r5]
	ldr r1, _081DFF0C @ =0x0000A413
	adds r0, r4, #0
	bl GetFile
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r6, r7, r2
	str r0, [r6]
	movs r0, #0xa
	str r0, [sp, #0xc]
	ldr r2, [r5]
	movs r4, #0
	str r4, [sp]
	movs r5, #1
	str r5, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	movs r0, #0xc
	str r0, [sp, #0xc]
	ldr r2, [r6]
	str r4, [sp]
	str r5, [sp, #4]
	add r1, sp, #0xc
	str r1, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _081DFF10 @ =0x000092B3
	ldr r1, _081DFF14 @ =0x000026BB
	bl GetFile
	movs r2, #0xf3
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r0, #0x14
	str r0, [r1]
	ldr r1, _081DFF18 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DFF04: .4byte 0x0000C091
_081DFF08: .4byte 0x0000CD91
_081DFF0C: .4byte 0x0000A413
_081DFF10: .4byte 0x000092B3
_081DFF14: .4byte 0x000026BB
_081DFF18: .4byte 0x03004250
