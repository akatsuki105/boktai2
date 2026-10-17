	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _08012CD4 @ =0x0000C091
	ldr r1, _08012CD8 @ =0x000033B2
	bl GetFile
	adds r2, r0, #0
	movs r1, #0x8b
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _08012CDC @ =0x000092B3
	ldr r1, _08012CE0 @ =0x0000E9C3
	bl GetFile
	ldr r1, _08012CE4 @ =0x0000045C
	adds r5, r5, r1
	adds r0, #0x14
	str r0, [r5]
	ldr r1, _08012CE8 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08012CD4: .4byte 0x0000C091
_08012CD8: .4byte 0x000033B2
_08012CDC: .4byte 0x000092B3
_08012CE0: .4byte 0x0000E9C3
_08012CE4: .4byte 0x0000045C
_08012CE8: .4byte 0x03004250
