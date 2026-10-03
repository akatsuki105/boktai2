	push {lr}
	adds r3, r0, #0
	ldr r0, _080AE468 @ =0x000004EC
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r2, r0, #1
	strh r2, [r1]
	ldr r0, _080AE46C @ =0x0000FFFF
	adds r1, r0, #0
	adds r0, r2, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080AE462
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x11
	movs r0, #3
	ands r1, r0
	movs r2, #0x9c
	lsls r2, r2, #3
	adds r0, r3, r2
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	ldr r1, _080AE470 @ =0x030043B0
	ldr r2, _080AE474 @ =0x04000008
	bl CpuSet
_080AE462:
	pop {r0}
	bx r0
	.align 2, 0
_080AE468: .4byte 0x000004EC
_080AE46C: .4byte 0x0000FFFF
_080AE470: .4byte 0x030043B0
_080AE474: .4byte 0x04000008
