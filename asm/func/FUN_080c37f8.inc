	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	ldr r0, _080C3818 @ =0x03003584
	ldr r0, [r0]
	ldr r4, _080C381C @ =0x00002BA0
	adds r3, r0, r4
	cmp r1, #0x1f
	ble _080C3828
	ldr r0, _080C3820 @ =0x0000259C
	adds r1, r2, r0
	ldr r2, _080C3824 @ =0x04000008
	adds r0, r3, #0
	bl CpuSet
	b _080C3862
	.align 2, 0
_080C3818: .4byte 0x03003584
_080C381C: .4byte 0x00002BA0
_080C3820: .4byte 0x0000259C
_080C3824: .4byte 0x04000008
_080C3828:
	adds r5, r1, #0
	movs r7, #0x1f
	ldr r0, _080C3868 @ =0x0000259C
	adds r4, r2, r0
	movs r6, #0xf
_080C3832:
	ldrh r0, [r3]
	movs r2, #0x1f
	ands r2, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x15
	ands r1, r7
	lsrs r0, r0, #0x1a
	ands r0, r7
	muls r2, r5, r2
	asrs r2, r2, #5
	muls r1, r5, r1
	asrs r1, r1, #5
	muls r0, r5, r0
	asrs r0, r0, #5
	lsls r0, r0, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r2
	strh r0, [r4]
	adds r3, #2
	adds r4, #2
	subs r6, #1
	cmp r6, #0
	bge _080C3832
_080C3862:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3868: .4byte 0x0000259C
