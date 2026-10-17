	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _081DBA40 @ =0x0000C091
	ldr r1, _081DBA44 @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x18]
	movs r0, #7
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	ldr r0, _081DBA48 @ =0x000092B3
	ldr r1, _081DBA4C @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	str r0, [r4, #0x1c]
	ldr r1, _081DBA50 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DBA40: .4byte 0x0000C091
_081DBA44: .4byte 0x0000CD91
_081DBA48: .4byte 0x000092B3
_081DBA4C: .4byte 0x000026BB
_081DBA50: .4byte 0x03004250
