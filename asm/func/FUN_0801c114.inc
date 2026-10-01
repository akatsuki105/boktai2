	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _0801C174 @ =0x0000C091
	ldr r1, _0801C178 @ =0x00009F57
	bl GetFile
	adds r2, r0, #0
	str r2, [r5, #0x48]
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
	ldr r0, _0801C17C @ =0x000092B3
	ldr r1, _0801C180 @ =0x0000A41A
	bl GetFile
	adds r1, r0, #0
	adds r0, #0x14
	str r0, [r5, #0x4c]
	movs r2, #0xda
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, _0801C184 @ =0x030043F0
	movs r2, #0x30
	bl CpuSet
	movs r0, #0
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801C174: .4byte 0x0000C091
_0801C178: .4byte 0x00009F57
_0801C17C: .4byte 0x000092B3
_0801C180: .4byte 0x0000A41A
_0801C184: .4byte 0x030043F0
