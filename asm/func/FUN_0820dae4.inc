	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r5, r0, #0
	str r1, [sp, #0x10]
	ldr r0, _0820DB80 @ =0x0000C091
	ldr r1, _0820DB84 @ =0x00004F8F
	bl GetFile
	adds r2, r0, #0
	str r2, [r5, #0x18]
	movs r4, #0
	str r4, [sp]
	movs r6, #1
	str r6, [sp, #4]
	add r0, sp, #0x10
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	movs r0, #2
	movs r1, #0
	bl SetBGPrioDirect
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0820DB88 @ =0x000092B3
	ldr r1, _0820DB8C @ =0x0000A41A
	bl GetFile
	adds r1, r0, #0
	adds r0, #0x14
	str r0, [r5, #0x1c]
	movs r2, #0xda
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, _0820DB90 @ =0x030043F0
	movs r2, #0x30
	bl CpuSet
	ldr r0, _0820DB94 @ =0x03003F60
	movs r1, #0x10
	strh r1, [r0, #0x18]
	strh r4, [r0, #0x20]
	strh r4, [r0, #0x22]
	movs r0, #3
	movs r1, #3
	bl SetBGPrioDirect
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r2, _0820DB98 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #9
	str r0, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #3
	movs r1, #4
	movs r2, #6
	movs r3, #8
	bl FUN_0822bdb8
	movs r0, #0
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0820DB80: .4byte 0x0000C091
_0820DB84: .4byte 0x00004F8F
_0820DB88: .4byte 0x000092B3
_0820DB8C: .4byte 0x0000A41A
_0820DB90: .4byte 0x030043F0
_0820DB94: .4byte 0x03003F60
_0820DB98: .4byte 0x03003E78
