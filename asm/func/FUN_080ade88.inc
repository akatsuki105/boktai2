	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _080ADF1C @ =0x0000C091
	ldr r2, _080ADF20 @ =0x085AD048
	ldr r3, _080ADF24 @ =0x00001336
	adds r1, r6, r3
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r1, [r1]
	bl GetFile
	adds r2, r0, #0
	ldr r0, _080ADF28 @ =0x000004D4
	adds r5, r6, r0
	str r2, [r5]
	movs r4, #0
	str r4, [sp, #0xc]
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r1, sp, #0xc
	str r1, [sp, #8]
	movs r0, #3
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	ldr r1, [r5]
	movs r0, #1
	movs r2, #0
	bl Video_SetBGLayer
	ldr r2, _080ADF2C @ =0x03003E78
	ldr r0, _080ADF30 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	movs r1, #0
	bl SetBGPrioDirect
	ldr r1, _080ADF34 @ =0x04000050
	ldr r2, _080ADF38 @ =0x00003C42
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	movs r3, #0x81
	lsls r3, r3, #4
	adds r0, r3, #0
	strh r0, [r1]
	ldr r0, _080ADF3C @ =0x04000054
	strh r4, [r0]
	ldr r0, _080ADF40 @ =0x000092B3
	ldr r1, _080ADF44 @ =0x0000F308
	bl GetFile
	movs r1, #0x9b
	lsls r1, r1, #3
	adds r6, r6, r1
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r6]
	ldr r1, _080ADF48 @ =0x030043D0
	ldr r2, _080ADF4C @ =0x04000008
	bl CpuSet
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ADF1C: .4byte 0x0000C091
_080ADF20: .4byte 0x085AD048
_080ADF24: .4byte 0x00001336
_080ADF28: .4byte 0x000004D4
_080ADF2C: .4byte 0x03003E78
_080ADF30: .4byte 0xFFFFFDFF
_080ADF34: .4byte 0x04000050
_080ADF38: .4byte 0x00003C42
_080ADF3C: .4byte 0x04000054
_080ADF40: .4byte 0x000092B3
_080ADF44: .4byte 0x0000F308
_080ADF48: .4byte 0x030043D0
_080ADF4C: .4byte 0x04000008
