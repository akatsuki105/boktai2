	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	mov ip, r1
	ldr r0, _080CCC4C @ =0x000006AC
	adds r4, r5, r0
	cmp r3, #0
	bne _080CCC50
	movs r3, #0xa0
	movs r7, #0xe1
	lsls r7, r7, #1
	b _080CCC60
	.align 2, 0
_080CCC4C: .4byte 0x000006AC
_080CCC50:
	cmp r3, #1
	bne _080CCC5C
	movs r3, #0x8c
	movs r7, #0xa9
	lsls r7, r7, #1
	b _080CCC60
_080CCC5C:
	movs r3, #0x78
	movs r7, #0xe0
_080CCC60:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r6, r0, #5
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldrh r0, [r4, #0x1e]
	adds r0, r0, r3
	strh r0, [r4, #0x1e]
	ldr r2, _080CCC9C @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	cmp r0, #0
	blt _080CCCA0
	asrs r1, r0, #0xc
	b _080CCCA6
	.align 2, 0
_080CCC9C: .4byte gSineTable
_080CCCA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCCA6:
	ldrh r0, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _080CCCBE
	asrs r1, r0, #0xc
	b _080CCCC4
_080CCCBE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCCC4:
	ldrh r0, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CCCE8
	asrs r1, r0, #0xc
	b _080CCCEE
_080CCCE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCCEE:
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r0, r5, r3
	strh r1, [r0]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CCD0C
	asrs r2, r0, #0xc
	b _080CCD12
_080CCD0C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080CCD12:
	ldr r3, _080CCD50 @ =0x0000070C
	adds r0, r5, r3
	strh r2, [r0]
	add r2, sp, #8
	mov r0, ip
	add r1, sp, #4
	bl FUN_080ccaa0
	ldr r1, _080CCD54 @ =0x000006F4
	adds r0, r5, r1
	ldr r2, _080CCD58 @ =0x00000704
	adds r1, r5, r2
	ldr r1, [r1]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r2, [sp, #8]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #1
	bl AuxAnim_SetAnim
	adds r0, r5, #0
	bl FUN_080ccae0
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CCD50: .4byte 0x0000070C
_080CCD54: .4byte 0x000006F4
_080CCD58: .4byte 0x00000704
