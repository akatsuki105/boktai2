	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	add r3, sp, #0x14
	ldr r2, _081E9914 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081E9918
	asrs r1, r0, #0xc
	b _081E991E
	.align 2, 0
_081E9914: .4byte gSineTable
_081E9918:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081E991E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081E993A
	asrs r0, r0, #0xc
	b _081E9940
_081E993A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081E9940:
	strh r0, [r3, #4]
	ldr r0, _081E9968 @ =0x00000309
	str r0, [sp]
	ldr r0, [sp, #0x30]
	str r0, [sp, #4]
	ldr r0, [sp, #0x34]
	str r0, [sp, #8]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	adds r0, r7, #0
	movs r1, #0
	add r2, sp, #0x14
	adds r3, r4, #0
	bl Entity081e9cac_Spawn
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081E9968: .4byte 0x00000309
