	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r6, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08228718
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _08228714 @ =0x00000F14
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #1
	b _0822871A
	.align 2, 0
_08228714: .4byte 0x00000F14
_08228718:
	movs r0, #0
_0822871A:
	cmp r0, #0
	beq _08228754
	ldr r3, _08228798 @ =0x00000F15
	adds r1, r6, r3
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0822879C @ =0x00000DE4
	adds r0, r6, r1
	ldr r2, _082287A0 @ =0x00000E34
	adds r1, r6, r2
	ldr r1, [r1]
	adds r3, #0x13
	adds r2, r6, r3
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #8
	movs r3, #0
	bl FUN_08236fac
	adds r0, r6, #0
	bl FUN_08223998
	ldr r1, _082287A4 @ =0x00000DF4
	adds r0, r6, r1
	bl FUN_080136b4
	adds r0, r6, #0
	bl FUN_082239fc
_08228754:
	ldr r2, _082287A8 @ =0x00000F4C
	adds r0, r6, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _08228764
	adds r0, r6, #0
	bl _call_via_r1
_08228764:
	ldr r0, _082287AC @ =0x00000D9C
	adds r3, r6, r0
	ldr r2, _082287B0 @ =0x00000E38
	adds r1, r6, r2
	ldrh r2, [r1]
	adds r0, r2, #1
	strh r0, [r1]
	movs r1, #3
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	bne _0822880E
	ldr r2, _082287B4 @ =0x00000DEC
	adds r0, r6, r2
	ldrh r0, [r0]
	adds r2, r1, #0
	ands r2, r0
	cmp r2, #2
	bgt _082287BC
	cmp r2, #1
	bge _082287E4
	cmp r2, #0
	beq _082287C4
	ldr r0, _082287B8 @ =0x00000E3A
	adds r1, r6, r0
	b _08228804
	.align 2, 0
_08228798: .4byte 0x00000F15
_0822879C: .4byte 0x00000DE4
_082287A0: .4byte 0x00000E34
_082287A4: .4byte 0x00000DF4
_082287A8: .4byte 0x00000F4C
_082287AC: .4byte 0x00000D9C
_082287B0: .4byte 0x00000E38
_082287B4: .4byte 0x00000DEC
_082287B8: .4byte 0x00000E3A
_082287BC:
	ldr r0, _082287D8 @ =0x00000E3A
	adds r1, r6, r0
	cmp r2, #3
	bne _08228804
_082287C4:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _082287DC
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #1
	b _08228802
	.align 2, 0
_082287D8: .4byte 0x00000E3A
_082287DC:
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #0xf8
	b _08228802
_082287E4:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _082287FC
	ldr r2, _082287F8 @ =0x00000E3A
	adds r1, r6, r2
	movs r0, #0xff
	b _08228802
	.align 2, 0
_082287F8: .4byte 0x00000E3A
_082287FC:
	ldr r0, _08228844 @ =0x00000E3A
	adds r1, r6, r0
	movs r0, #8
_08228802:
	strb r0, [r1]
_08228804:
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldrh r1, [r3, #0x1e]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
_0822880E:
	ldr r2, _08228848 @ =0x00000D9C
	adds r5, r6, r2
	ldr r3, _0822884C @ =0x00000DE4
	adds r4, r6, r3
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08228850
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08228858
	.align 2, 0
_08228844: .4byte 0x00000E3A
_08228848: .4byte 0x00000D9C
_0822884C: .4byte 0x00000DE4
_08228850:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08228858:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0822887C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08228884
_0822887C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08228884:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _082288BC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08228902
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _082288C6
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _082288C0
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _082288DC
	.align 2, 0
_082288BC: .4byte 0x0000FFFF
_082288C0:
	subs r0, #1
	strh r0, [r4, #8]
	b _082288DA
_082288C6:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _082288DA
	strh r1, [r4, #8]
	movs r2, #1
	b _082288DC
_082288DA:
	movs r2, #0
_082288DC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08228904
	movs r0, #1
	strb r0, [r4, #7]
	b _08228904
_08228902:
	movs r2, #0
_08228904:
	ldr r3, _08228914 @ =0x00000F14
	adds r0, r6, r3
	strb r2, [r0]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08228914: .4byte 0x00000F14
