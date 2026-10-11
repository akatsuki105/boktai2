	push {r4, lr}
	sub sp, #0x10
	str r1, [sp, #0xc]
	ldr r0, _0804B3E4 @ =0x0000C091
	ldr r1, _0804B3E8 @ =0x0000A413
	bl GetFile
	adds r2, r0, #0
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0804B3EC @ =0x000092B3
	ldr r1, _0804B3F0 @ =0x0000EFDA
	bl GetFile
	adds r0, #0x14
	ldr r1, _0804B3F4 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804B3E4: .4byte 0x0000C091
_0804B3E8: .4byte 0x0000A413
_0804B3EC: .4byte 0x000092B3
_0804B3F0: .4byte 0x0000EFDA
_0804B3F4: .4byte 0x03004250
