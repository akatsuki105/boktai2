	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _080AEE60 @ =0x00001348
	adds r4, r6, r0
	ldr r1, _080AEE64 @ =0x0000134A
	adds r5, r6, r1
	ldrh r1, [r4]
	ldrh r2, [r5]
	cmp r1, r2
	bhs _080AEE6C
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	bne _080AEE4A
	movs r1, #0x9b
	lsls r1, r1, #5
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_0805b1a0
_080AEE4A:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r5, [r5]
	cmp r0, r5
	bhs _080AEE5C
	b _080AEFC0
_080AEE5C:
	ldr r2, _080AEE68 @ =0x0000134C
	b _080AEFBA
	.align 2, 0
_080AEE60: .4byte 0x00001348
_080AEE64: .4byte 0x0000134A
_080AEE68: .4byte 0x0000134C
_080AEE6C:
	ldr r1, _080AEEC8 @ =0x0000134C
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080AEE78
	b _080AEFA6
_080AEE78:
	ldr r0, _080AEECC @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _080AEED0 @ =0x000003FF
	ands r1, r2
	str r1, [r0]
	lsls r1, r1, #1
	ldr r2, _080AEED4 @ =0x0203B400
	adds r1, r1, r2
	ldrb r4, [r1]
	ldr r1, _080AEED8 @ =0x085B0A08
	mov sl, r1
	add r5, sp, #8
	adds r7, r0, #0
	movs r2, #2
	mov sb, r2
	movs r0, #0xff
	mov r8, r0
_080AEE9C:
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r1, _080AEED8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	mov r2, r8
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	cmp r0, #0
	blt _080AEEDC
	asrs r1, r0, #0xc
	b _080AEEE2
	.align 2, 0
_080AEEC8: .4byte 0x0000134C
_080AEECC: .4byte 0x030046B8
_080AEED0: .4byte 0x000003FF
_080AEED4: .4byte 0x0203B400
_080AEED8: .4byte 0x085B0A08
_080AEEDC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AEEE2:
	ldrh r0, [r5]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080AEF34 @ =0xFFFF0000
	ldr r3, [sp, #8]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #8]
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080AEF38 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _080AEF3C @ =0x0203B400
	adds r0, r0, r2
	ldrh r2, [r0]
	asrs r1, r3, #0x10
	adds r1, #0x80
	movs r0, #0x1f
	ands r2, r0
	adds r1, r1, r2
	lsls r1, r1, #0x10
	ldr r0, _080AEF40 @ =0x0000FFFF
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #8]
	adds r0, r4, #0
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _080AEF44
	asrs r0, r0, #0xc
	b _080AEF4A
	.align 2, 0
_080AEF34: .4byte 0xFFFF0000
_080AEF38: .4byte 0x000003FF
_080AEF3C: .4byte 0x0203B400
_080AEF40: .4byte 0x0000FFFF
_080AEF44:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AEF4A:
	ldrh r1, [r5, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080AEFD0 @ =0xFFFF0000
	ldr r0, [r5, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	movs r1, #0x9b
	lsls r1, r1, #5
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r1, _080AEFD4 @ =0x03002BE0
	ldr r2, [r1]
	adds r2, #0x2c
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xc8
	str r1, [sp, #4]
	add r1, sp, #8
	adds r3, r4, #0
	bl FUN_0805b0b0
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080AEFD8 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _080AEFDC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, r0, r4
	adds r4, r0, #0
	adds r4, #0x4e
	mov r0, r8
	ands r4, r0
	subs r1, #0x10
	add sb, r1
	mov r2, sb
	cmp r2, #0
	blt _080AEFA6
	b _080AEE9C
_080AEFA6:
	ldr r0, _080AEFE0 @ =0x0000134C
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3c
	bls _080AEFC0
	ldr r2, _080AEFE4 @ =0x00001348
_080AEFBA:
	adds r1, r6, r2
	movs r0, #0
	strh r0, [r1]
_080AEFC0:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AEFD0: .4byte 0xFFFF0000
_080AEFD4: .4byte 0x03002BE0
_080AEFD8: .4byte 0x000003FF
_080AEFDC: .4byte 0x0203B400
_080AEFE0: .4byte 0x0000134C
_080AEFE4: .4byte 0x00001348
