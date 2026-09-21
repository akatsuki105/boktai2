	push {r4, r5, lr}
	sub sp, #0x10
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp, #0xc]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	ldr r0, _0823D4A0 @ =0x0000C091
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r1, r4, #0
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
	cmp r5, #0
	beq _0823D498
	ldr r0, _0823D4A4 @ =0x000092B3
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, _0823D4A8 @ =0x030043F0
	movs r2, #0x30
	bl CpuSet
_0823D498:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823D4A0: .4byte 0x0000C091
_0823D4A4: .4byte 0x000092B3
_0823D4A8: .4byte 0x030043F0
