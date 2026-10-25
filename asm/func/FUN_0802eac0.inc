	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r6, #0
	ldr r0, _0802EB30 @ =0x00000899
	adds r1, r6, r0
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802EBA0
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802EB38
	ldr r1, _0802EB34 @ =0x00000824
	adds r0, r6, r1
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _0802EB48
	movs r3, #0
	b _0802EB48
	.align 2, 0
_0802EB30: .4byte 0x00000899
_0802EB34: .4byte 0x00000824
_0802EB38:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _0802EB48
	movs r3, #5
_0802EB48:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	bl Boss_PlayAnimDir8
	ldr r1, _0802EB94 @ =0x00000844
	adds r2, r5, r1
	ldr r3, _0802EB98 @ =0x00000868
	adds r0, r5, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r5, #0
	bl FUN_08028604
	ldr r0, _0802EB9C @ =0x0000084C
	adds r1, r5, r0
	adds r0, r5, #0
	movs r2, #0x20
	bl FUN_0802853c
	movs r1, #0xbf
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl FUN_08029a1c
	b _0802EBE8
	.align 2, 0
_0802EB94: .4byte 0x00000844
_0802EB98: .4byte 0x00000868
_0802EB9C: .4byte 0x0000084C
_0802EBA0:
	adds r0, r6, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802EBC0
	ldr r2, _0802EBBC @ =0x00000824
	adds r0, r6, r2
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _0802EBD0
	movs r3, #0
	b _0802EBD0
	.align 2, 0
_0802EBBC: .4byte 0x00000824
_0802EBC0:
	movs r3, #0x82
	lsls r3, r3, #4
	adds r0, r6, r3
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _0802EBD0
	movs r3, #5
_0802EBD0:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	bl Boss_PlayAnimDir8
_0802EBE8:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r3, #0xb3
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, _0802EC6C @ =0x00000167
	adds r0, r5, r1
	strb r2, [r0]
	movs r1, #4
	adds r4, r6, #0
	adds r4, #0x98
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802ECD8
	ldr r3, _0802EC70 @ =0x00000FD4
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802EC36
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_0802EC36:
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _0802EC4C
	adds r0, r2, #2
	strh r0, [r3]
_0802EC4C:
	ldr r2, _0802EC74 @ =gSineTable
	lsls r0, r7, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0802EC78
	asrs r1, r0, #0xc
	b _0802EC7E
	.align 2, 0
_0802EC6C: .4byte 0x00000167
_0802EC70: .4byte 0x00000FD4
_0802EC74: .4byte gSineTable
_0802EC78:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802EC7E:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0802EC94
	movs r0, #0
	strh r0, [r1]
_0802EC94:
	ldr r1, _0802ECC8 @ =0x000008E4
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #3
	bls _0802ECA8
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08028838
_0802ECA8:
	movs r2, #0x84
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r3, _0802ECCC @ =0x00000842
	adds r1, r5, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _0802ECD0
	adds r0, r5, #0
	bl FUN_08028648
	adds r0, r5, #0
	bl FUN_080286d8
	b _0802ECD8
	.align 2, 0
_0802ECC8: .4byte 0x000008E4
_0802ECCC: .4byte 0x00000842
_0802ECD0:
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0802ECD8:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
